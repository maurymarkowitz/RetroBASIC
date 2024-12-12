/* matrix (implementation) for RetroBASIC
 Copyright (C) 2024 Maury Markowitz
 
 This file is part of RetroBASIC.
 
 RetroBASIC is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2, or (at your option)
 any later version.
 
 RetroBASIC is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with RetroBASIC; see the file COPYING.  If not, write to
 the Free Software Foundation, 59 Temple Place - Suite 330,
 Boston, MA 02111-1307, USA.  */

#include "matrix.h"

#include "parse.h"
#include "errors.h"

/**
 * Used for REDIM and similar instructions that have to resize an array
 * or matrix to a specified size. MAT MUL and TRN use this as well.
 *
 * @param destination_ref The array to resize.
 * @param x the X dimension, must be > 0.
 * @param y the Y dimension. Optional, if not being used, set to -1 for clarity.
 * @return true if the resize worked, false otherwise.
 */
bool redim_matrix_to_size(variable_reference_t *destination_ref, int x, int y)
{
  // basic check - note this IS legal in a DIM command, A(0,3) is valid, but it is
  // not valid in a matrix resize, where it's always starting at 1
  if (x <= 0) {
    handle_error(ern_BAD_SUBSCRIPT, "Attempt to resize array to zero or negative bounds");
    return false;
  }
  
  // get the storage entry for the destination
  variable_storage_t *destination_store = lst_data_with_key(interpreter_state.variable_values, destination_ref->name);
  list_t *destination_act_dimensions = lst_first_node(destination_store->actual_dimensions);

  // if the actual_dimensions is null, that means this is the first time this variable is being
  // seen in the code. This can only occur in a matrix re-size, otherwise the variable would have
  // been seen with subscripts and set up correctly. If this is not set up, we set it up with
  // the default 10 slots
  if (!destination_act_dimensions) {
    destination_store->actual_dimensions = lst_append(destination_act_dimensions, INT_TO_POINTER(10));
    destination_act_dimensions = destination_store->actual_dimensions;
  }
    
  // calculate the total size available in the destination
  int destination_slots = 1;
  while (destination_act_dimensions != NULL) {
    destination_slots = destination_slots * (POINTER_TO_INT(destination_act_dimensions->data) + 1); // remember, zero is 1
    destination_act_dimensions = lst_next(destination_act_dimensions);
  }
  
  // calculate the new size
  int slots = x + 1;
  if (y > 0) slots *= (y + 1);
  
  // and make sure it's big enough
  if (slots > destination_slots) {
    handle_error(ern_BAD_SUBSCRIPT, "Attempt to resize array to too large a size");
    return false;
  }
  
  // and set the sizes
  destination_act_dimensions = lst_first_node(destination_store->actual_dimensions);
  destination_act_dimensions->data = INT_TO_POINTER(x);
  if (y > 0) {
    destination_act_dimensions = lst_next(destination_act_dimensions);
    if (destination_act_dimensions == NULL)
      destination_store->actual_dimensions = lst_append(destination_act_dimensions, INT_TO_POINTER(y));
    else
      destination_act_dimensions->data = INT_TO_POINTER(y);
  }
  
  // all done
  return true;
}

void matrix_fill_num(statement_t *statement, double fill_value)
{
  list_t *use_dimensions;
  int num_dimensions;

  // get the destination reference from the LHS and find the storage
  variable_reference_t *destination_ref = statement->parms.mat.variable;
  variable_storage_t *destination_store = lst_data_with_key(interpreter_state.variable_values, destination_ref->name);
  int destination_type = variable_type(destination_ref);

  // has to be a number
  if (destination_type == STRING) {
    handle_error(ern_TYPE_MISMATCH, "MAT fill number with string result variable");
    return;
  }
  
  // see if there are specified dimensions, use them if there are
  if (statement->parms.mat.variable->subscripts != NULL) {
    // these will be expressions that need to be calculated
    use_dimensions = statement->parms.mat.variable->subscripts;
  }
  // ...otherwise use the ones in the original array
  else {
    use_dimensions = destination_store->actual_dimensions;
  }
    
  // needs to be 1 or 2 dimensions
  num_dimensions = lst_length(use_dimensions);
  if (num_dimensions == 0) {
    handle_error(ern_TYPE_MISMATCH, "MAT fill with scalar input variable");
  }
  else if (num_dimensions > 2) {
    handle_error(ern_BAD_SUBSCRIPT, "MAT fill with too many dimensions");
  }
  
  // if the dimensions are being passed in as a parameter, we need
  // to evaluate them to get the values, otherwise just use the
  // original dimensions from the array
  value_t v;
  int rows, cols;
  if (statement->parms.mat.variable->subscripts != NULL) {
    if (num_dimensions == 1) {
      v = evaluate_expression(use_dimensions->data);
      rows = v.number;
      cols = -1;
    }
    else {
      v = evaluate_expression(use_dimensions->data);
      rows = v.number;
      v = evaluate_expression(use_dimensions->next->data);
      cols = v.number;
    }
  }
  else {
    if (num_dimensions == 1) {
      rows = POINTER_TO_INT(use_dimensions->data);
      cols = -1;
    }
    else {
      rows = POINTER_TO_INT(use_dimensions->data);
      cols = POINTER_TO_INT(use_dimensions->next->data);
    }
  }
  
  // resize and make sure that worked
  if (!redim_matrix_to_size(destination_ref, rows, cols))
    return; // no message, it's already been printed during the resize
  
  // is it a vector?
  if (num_dimensions == 1) {
    for (int slot = 1; slot <= rows; slot++)
      destination_store->array[slot].number = fill_value;
  }
  // ... or a matrix?
  else {
    for (int r = 1; r <= rows; r++) {
      for (int c = 1; c <= cols; c++) {
        int slot = r * (cols + 1) + c;
        destination_store->array[slot].number = fill_value;
      }
    }
  }
}

void matrix_fill_str(statement_t *statement, char *fill_value)
{
  list_t *use_dimensions;
  int num_dimensions;

  // get the destination reference from the LHS and find the storage
  variable_reference_t *destination_ref = statement->parms.mat.variable;
  variable_storage_t *destination_store = lst_data_with_key(interpreter_state.variable_values, destination_ref->name);
  int destination_type = variable_type(destination_ref);

  // has to be a number
  if (destination_type != STRING) {
    handle_error(ern_TYPE_MISMATCH, "MAT string fill with number result variable");
    return;
  }
  
  // see if there are specified dimensions, use them if there are
  if (statement->parms.mat.variable->subscripts != NULL) {
    // these will be expressions that need to be calculated
    use_dimensions = statement->parms.mat.variable->subscripts;
  }
  // ...otherwise use the ones in the original array
  else {
    use_dimensions = destination_store->actual_dimensions;
  }
    
  // needs to be 1 or 2 dimensions
  num_dimensions = lst_length(use_dimensions);
  if (num_dimensions == 0) {
    handle_error(ern_TYPE_MISMATCH, "MAT fill with scalar result variable");
  }
  else if (num_dimensions > 2) {
    handle_error(ern_BAD_SUBSCRIPT, "MAT fill with too many dimensions");
  }
  
  // if the dimensions are being passed in as a parameter, we need
  // to evaluate them to get the values, otherwise just use the
  // original dimensions from the array
  value_t v;
  int rows, cols;
  if (statement->parms.mat.variable->subscripts != NULL) {
    if (num_dimensions == 1) {
      v = evaluate_expression(use_dimensions->data);
      rows = v.number;
      cols = -1;
    }
    else {
      v = evaluate_expression(use_dimensions->data);
      rows = v.number;
      v = evaluate_expression(use_dimensions->next->data);
      cols = v.number;
    }
  }
  else {
    if (num_dimensions == 1) {
      rows = POINTER_TO_INT(use_dimensions->data);
      cols = -1;
    }
    else {
      rows = POINTER_TO_INT(use_dimensions->data);
      cols = POINTER_TO_INT(use_dimensions->next->data);
    }
  }
  
  // resize and make sure that worked
  if (!redim_matrix_to_size(destination_ref, rows, cols))
    return; // no message, it's already been printed during the resize
  
  // is it a vector?
  if (num_dimensions == 1) {
    for (int slot = 1; slot <= rows; slot++) {
      // out with the old...
      if (destination_store->array[slot].string != NULL)
        free(destination_store->array[slot].string);
      
      // and in with the new
      destination_store->array[slot].string = str_new(fill_value);
    }
  }
  // ... or a matrix?
  else {
    for (int r = 1; r <= cols; r++) {
      for (int c = 1; c <= rows; c++) {
        int slot = r * (cols + 1) + c;
        if (destination_store->array[slot].string != NULL)
            free(destination_store->array[slot].string);
        destination_store->array[slot].string = str_new(fill_value);
      }
    }
  }
}

void matrix_identity(statement_t *statement)
{
  int num_dimensions;
  list_t *use_dimensions;
  
  // get the destination reference from the LHS and find the storage
  variable_reference_t *destination_ref = statement->parms.mat.variable;
  variable_storage_t *destination_store = lst_data_with_key(interpreter_state.variable_values, destination_ref->name);
  int destination_type = variable_type(destination_ref);

  // has to be a number
  if (destination_type == STRING) {
    handle_error(ern_TYPE_MISMATCH, "MAT IDN with string result variable");
    return;
  }

  // see if there are specified dimensions, use them if there are
  if (statement->parms.mat.variable->subscripts != NULL) {
    // these will be expressions that need to be calculated
    use_dimensions = statement->parms.mat.variable->subscripts;
  }
  // ...otherwise use the ones in the original array
  else {
    use_dimensions = destination_store->actual_dimensions;
  }
    
  // needs to be 1 or 2 dimensions
  num_dimensions = lst_length(use_dimensions);
  if (num_dimensions != 2) {
    handle_error(ern_BAD_SUBSCRIPT, "MAT IDN with non-2D array");
  }

  // eval the dimensions
  int rows, cols;
  if (statement->parms.mat.variable->subscripts != NULL) {
    value_t v = evaluate_expression(use_dimensions->data);
    rows = v.number;
    v = evaluate_expression(use_dimensions->next->data);
    cols = v.number;
  }
  else {
    rows = POINTER_TO_INT(use_dimensions->data);
    cols = POINTER_TO_INT(use_dimensions->next->data);
  }
  
  // redim
  if (!redim_matrix_to_size(destination_ref, rows, cols))
    return;

  // should be good now...
  for (int r = 1; r <= rows; r++)
    for (int c = 1; c <= cols; c++) {
      int slot = r * (cols + 1) + c;
      if (r == c)
        destination_store->array[slot].number = 1.0;
      else
        destination_store->array[slot].number = 0.0;
    }
}

void matrix_add(statement_t *statement)
{
  // find the destination array storage
  variable_reference_t *destination_ref = statement->parms.mat.variable;
  variable_storage_t *destination_store = lst_data_with_key(interpreter_state.variable_values, destination_ref->name);
  int destination_array_type = variable_type(destination_ref);

  // has to be a number
  if (destination_array_type == STRING) {
    handle_error(ern_TYPE_MISMATCH, "MAT ADD with string result variable");
    return;
  }
  
  // need two other variables, both numeric arrays
  variable_reference_t *one_item = statement->parms.mat.variable2;
  variable_storage_t *one_store = lst_data_with_key(interpreter_state.variable_values, one_item->name);
  int one_array_type = variable_type(one_item);
  variable_reference_t *two_item = statement->parms.mat.variable3;
  variable_storage_t *two_store = lst_data_with_key(interpreter_state.variable_values, two_item->name);
  int two_array_type = variable_type(two_item);
  if (one_array_type == STRING || two_array_type == STRING) {
    handle_error(ern_TYPE_MISMATCH, "MAT ADD with string variable inputs");
    return;
  }

  // the two inputs have to have the same dimensions
  int one_dims = lst_length(one_store->actual_dimensions);
  int two_dims = lst_length(two_store->actual_dimensions);
  if (one_dims != two_dims) {
    handle_error(ern_TYPE_MISMATCH, "MAT ADD with different sized inputs");
    return;
  }
  // can't be scalars or 3D
  if (one_dims == 0) {
    handle_error(ern_TYPE_MISMATCH, "MAT ADD with scalar variable");
    return;
  }
  if (one_dims > 2) {
    handle_error(ern_TYPE_MISMATCH, "MAT ADD with too many dimensions");
    return;
  }

  // and the actual dimensions have to be the same as well
  list_t *one_dimensions = lst_first_node(one_store->actual_dimensions);
  list_t *two_dimensions = lst_first_node(two_store->actual_dimensions);
  for (int i = 0; i < one_dims; i++) {
    if (POINTER_TO_INT(one_dimensions->data) != POINTER_TO_INT(two_dimensions->data)) {
      handle_error(ern_TYPE_MISMATCH, "MAT ADD with different sized inputs");
      return;
    }
    one_dimensions = one_dimensions->next;
    two_dimensions = two_dimensions->next;
  }
  
  // eval the dimensions from any that were specified in the statement,
  // or by using one of the source arrays
  int rows, cols = 0;
  if (statement->parms.mat.variable->subscripts != NULL) {
    value_t v = evaluate_expression(statement->parms.mat.variable->subscripts->data);
    rows = v.number;
    if (statement->parms.mat.variable->subscripts->next != NULL) {
      v = evaluate_expression(statement->parms.mat.variable->subscripts->next->data);
      cols = v.number;
    }
  }
  else {
    rows = POINTER_TO_INT(lst_first_node(one_store->actual_dimensions)->data);
    cols = POINTER_TO_INT(lst_first_node(one_store->actual_dimensions)->next->data);
  }

  // get the resulting number of dimensions
  int dims = lst_length(destination_store->actual_dimensions);
  if (dims == 1) {
    cols = rows; // because it was put in rows above
    
    if (!redim_matrix_to_size(destination_ref, cols, -1))
      return;

    for (int c = 1; c <= cols; c++)
      destination_store->array[c].number = one_store->array[c].number + two_store->array[c].number;
  }
  else if (dims == 2) {
    if (!redim_matrix_to_size(destination_ref, rows, cols))
      return;

    for (int r = 1; r <= rows; r++) {
      for (int c = 1; c <= cols; c++) {
        int slot = r * (cols + 1) + c;
        destination_store->array[slot].number = one_store->array[slot].number + two_store->array[slot].number;
      }
    }
  }
}

void matrix_sub(statement_t *statement)
{
  // find the destination array storage
  variable_reference_t *destination_ref = statement->parms.mat.variable;
  variable_storage_t *destination_store = lst_data_with_key(interpreter_state.variable_values, destination_ref->name);
  int destination_array_type = variable_type(destination_ref);

  // has to be a number
  if (destination_array_type == STRING) {
    handle_error(ern_TYPE_MISMATCH, "MAT SUB with string result variable");
    return;
  }
  
  // need two other variables, both numeric arrays
  variable_reference_t *one_item = statement->parms.mat.variable2;
  variable_storage_t *one_store = lst_data_with_key(interpreter_state.variable_values, one_item->name);
  int one_array_type = variable_type(one_item);
  variable_reference_t *two_item = statement->parms.mat.variable3;
  variable_storage_t *two_store = lst_data_with_key(interpreter_state.variable_values, two_item->name);
  int two_array_type = variable_type(two_item);
  if (one_array_type == STRING || two_array_type == STRING) {
    handle_error(ern_TYPE_MISMATCH, "MAT SUB with string variable inputs");
    return;
  }

  // the two inputs have to have the same dimensions
  int one_dims = lst_length(one_store->actual_dimensions);
  int two_dims = lst_length(two_store->actual_dimensions);
  if (one_dims != two_dims) {
    handle_error(ern_TYPE_MISMATCH, "MAT SUB with different sized inputs");
    return;
  }
  // can't be scalars or 3D
  if (one_dims == 0) {
    handle_error(ern_TYPE_MISMATCH, "MAT SUB with scalar variable");
    return;
  }
  if (one_dims > 2) {
    handle_error(ern_TYPE_MISMATCH, "MAT SUB with too many dimensions");
    return;
  }

  // and the actual dimensions have to be the same as well
  list_t *one_dimensions = lst_first_node(one_store->actual_dimensions);
  list_t *two_dimensions = lst_first_node(two_store->actual_dimensions);
  for (int i = 0; i < one_dims; i++) {
    if (POINTER_TO_INT(one_dimensions->data) != POINTER_TO_INT(two_dimensions->data)) {
      handle_error(ern_TYPE_MISMATCH, "MAT SUB with different sized inputs");
      return;
    }
    one_dimensions = one_dimensions->next;
    two_dimensions = two_dimensions->next;
  }
  
  // eval the dimensions from any that were specified in the statement,
  // or by using one of the source arrays
  int rows, cols = 0;
  if (statement->parms.mat.variable->subscripts != NULL) {
    value_t v = evaluate_expression(statement->parms.mat.variable->subscripts->data);
    rows = v.number;
    if (statement->parms.mat.variable->subscripts->next != NULL) {
      v = evaluate_expression(statement->parms.mat.variable->subscripts->next->data);
      cols = v.number;
    }
  }
  else {
    rows = POINTER_TO_INT(lst_first_node(one_store->actual_dimensions)->data);
    cols = POINTER_TO_INT(lst_first_node(one_store->actual_dimensions)->next->data);
  }

  // get the resulting number of dimensions
  int dims = lst_length(destination_store->actual_dimensions);
  if (dims == 1) {
    cols = rows;
    
    if (!redim_matrix_to_size(destination_ref, cols, -1))
      return;

    for (int c = 1; c <= cols; c++)
      destination_store->array[c].number = one_store->array[c].number + two_store->array[c].number;
  }
  else if (dims == 2) {
    if (!redim_matrix_to_size(destination_ref, rows, cols))
      return;

    for (int r = 1; r <= rows; r++) {
      for (int c = 1; c <= cols; c++) {
        int slot = r * (cols + 1) + c;
        destination_store->array[slot].number = one_store->array[slot].number - two_store->array[slot].number;
      }
    }
  }
}

void matrix_mul(statement_t *statement)
{
  // find the array storage
  variable_reference_t *destination_item = statement->parms.mat.variable;
  variable_storage_t *destination_store = lst_data_with_key(interpreter_state.variable_values, destination_item->name);
  int ret_array_type = variable_type(destination_item);
  
  // has to be a number
  if (ret_array_type == STRING) {
    handle_error(ern_TYPE_MISMATCH, "MAT MUL with string variable result");
    return;
  }
  
  // need two other variables, both numeric arrays
  variable_reference_t *one_item = statement->parms.mat.variable2;
  variable_storage_t *one_store = lst_data_with_key(interpreter_state.variable_values, one_item->name);
  int one_array_type = variable_type(one_item);
  variable_reference_t *two_item = statement->parms.mat.variable3;
  variable_storage_t *two_store = lst_data_with_key(interpreter_state.variable_values, two_item->name);
  int two_array_type = variable_type(two_item);
  if (one_array_type == STRING || two_array_type == STRING) {
    handle_error(ern_TYPE_MISMATCH, "MAT MUL with string variable inputs");
    return;
  }
  
  // the two inputs have to have the same dimension, we can't do array x matrix
  int one_dims = lst_length(one_store->actual_dimensions);
  int two_dims = lst_length(two_store->actual_dimensions);
  if (one_dims != two_dims) {
    handle_error(ern_TYPE_MISMATCH, "MAT MUL with different dimension inputs");
    return;
  }
  // and they can't be scalar or 3D
  if (one_dims == 0) {
    handle_error(ern_TYPE_MISMATCH, "MAT MUL with scalar inputs");
    return;
  }
  if (one_dims > 2) {
    handle_error(ern_TYPE_MISMATCH, "MAT MUL with too many dimensions");
    return;
  }
  
  // and there at limits on the dimensions themselves...
  int len = 0;
  int ret_rows = 0, ret_cols = 0, inner = 0;
  int one_cols = 0, two_cols = 0;
  list_t *one_dimensions = lst_first_node(one_store->actual_dimensions);
  list_t *two_dimensions = lst_first_node(two_store->actual_dimensions);
  if (one_dims == 1) {
    // for vectors, they have to be the same length
    int one = POINTER_TO_INT(one_dimensions->data);
    int two = POINTER_TO_INT(two_dimensions->data);
    if (one != two) {
      handle_error(ern_TYPE_MISMATCH, "MAT MUL with different sized vectors");
      return;
    }
    // if that worked...
    len = one;
  }
  else if (one_dims == 2) {
    // for matrixes, the "inner dimension" has to be the same, that is,
    // the number of columns in the first input has to be the same as the
    // number of rows in the second, so it's the second dimension in the
    // first and first dimension in the second
    int one = POINTER_TO_INT(one_dimensions->next->data);
    int two = POINTER_TO_INT(two_dimensions->data);
    if (one != two) {
      handle_error(ern_TYPE_MISMATCH, "MAT MUL with non-conformable matrixes");
      return;
    }
    // and we are good
    inner = one;
    ret_rows = POINTER_TO_INT(one_dimensions->data);
    ret_cols = POINTER_TO_INT(two_dimensions->next->data);
    one_cols = one;
    two_cols = ret_cols;
  }
  
  // unlike addition and subtraction, the cases here are a little more complex
  // so we have to further separate them out
  if (one_dims == 1) {
    // resize if needed
    if (!redim_matrix_to_size(destination_item, len, -1))
      return;
    
    for (int i = 1; i <= len; i++)
      destination_store->array[i].number = one_store->array[i].number * two_store->array[i].number;
  } // dim=1
  else if (one_dims == 2) {
    // resize if needed
    if (!redim_matrix_to_size(destination_item, ret_rows, ret_cols))
      return;
    
    // for this case we need local storage in case it's A=A*B
    double *temp = calloc((ret_rows + 1) * (ret_cols + 1), sizeof(double));
    for (int r = 1; r <= ret_rows; r++)
      for (int c = 1; c <= ret_cols; c++)
        for (int k = 1; k <= inner; k++) {
          int ret_index = r * (ret_cols + 1) + c;
          int one_index = r * (one_cols + 1) + k;
          int two_index = k * (two_cols + 1) + c;
          temp[ret_index] = temp[ret_index] + (one_store->array[one_index].number * two_store->array[two_index].number);
        }
    // copy back
    for (int r = 1; r <= ret_rows; r++)
      for (int c = 1; c <= ret_cols; c++) {
        int index = r * (ret_cols + 1) + c;
        destination_store->array[index].number = temp[index];
      }
    // ... and free temp
    free(temp);
  } // dim=2
}

void matrix_mul_const(statement_t *statement)
{
  // find the array storage
  variable_reference_t *destination_item = statement->parms.mat.variable;
  variable_storage_t *destination_store = lst_data_with_key(interpreter_state.variable_values, destination_item->name);
  int destination_array_type = variable_type(destination_item);

  // has to be a number
  if (destination_array_type == STRING) {
    handle_error(ern_TYPE_MISMATCH, "MAT MUL with string variable result");
    return;
  }
  
  // the THIRD item has to be a vector or array
  variable_reference_t *other_item = statement->parms.mat.variable3;
  variable_storage_t *other_store = lst_data_with_key(interpreter_state.variable_values, other_item->name);
  int other_array_type = variable_type(other_item);
  if (other_array_type == STRING) {
    handle_error(ern_TYPE_MISMATCH, "MAT MUL with string variable parameter");
    return;
  }
  
  // get the resulting number of dimensions
  int dims = lst_length(destination_store->actual_dimensions);
  list_t *ret_dimensions = lst_first_node(destination_store->actual_dimensions);
  
  // calculate the expression
  value_t mul = evaluate_expression(statement->parms.mat.expression);

  if (dims == 0) {
    handle_error(ern_TYPE_MISMATCH, "MAT MUL with scalar variable");
  }
  else if (dims == 1) {
    int cols = POINTER_TO_INT(ret_dimensions->data);
    
    if (!redim_matrix_to_size(destination_item, cols, -1))
      return;

    for (int c = 1; c <= cols; c++)
      destination_store->array[c].number = other_store->array[c].number * mul.number;
  } // dim=1
  else if (dims == 2) {
    int rows = POINTER_TO_INT(ret_dimensions->data);
    int cols = POINTER_TO_INT(ret_dimensions->next->data);

    if (!redim_matrix_to_size(destination_item, rows, cols))
      return;

    for (int r = 1; r <= rows; r++)
      for (int c = 1; c <= cols; c++) {
        int slot = r * (cols + 1) + c; // cols=3 means 4 columns
        destination_store->array[slot].number = other_store->array[slot].number * mul.number;
      }
  } // dim=2
  else {
    handle_error(ern_TYPE_MISMATCH, "MAT MUL with too many dimensions");
  } // dims
}

void matrix_transpose(statement_t *statement)
{
  // find the storage
  variable_reference_t *ret_item = statement->parms.mat.variable;
  variable_storage_t *ret_store = lst_data_with_key(interpreter_state.variable_values, ret_item->name);
  int ret_array_type = variable_type(ret_item);
  
  // call this to make sure the array is set up properly, even with the default 10 slots
  insert_variable(ret_item);
  
  // get the parameter
  variable_reference_t *one_item = statement->parms.mat.variable2;
  variable_storage_t *one_store = lst_data_with_key(interpreter_state.variable_values, one_item->name);
  
  // check that it's an array
  // NOTE: should we add vector->matrix? probably not
  int dims = lst_length(one_store->actual_dimensions);
  if (dims != 2) {
    handle_error(ern_BAD_SUBSCRIPT, "MAT TRN with non-2D array");
    return;
  }

  // the two arrays have to be the same type
  int one_array_type = variable_type(one_item);
  if (ret_array_type == STRING && one_array_type != STRING) {
    handle_error(ern_TYPE_MISMATCH, "MAT TRN with string output and numeric input");
    return;
  }
  if (ret_array_type != STRING && one_array_type == STRING) {
    handle_error(ern_TYPE_MISMATCH, "MAT TRN with numeric output and string input");
    return;
  }
  
  // get the original dimensions
  list_t *one_dimensions = lst_first_node(one_store->actual_dimensions);
  int old_rows = POINTER_TO_INT(one_dimensions->data);
  int old_cols = POINTER_TO_INT(one_dimensions->next->data);
  
  // make a temp array large enough to hold the results
  // NOTE: have to use temp here in case MAT A=TRN(A)
  int new_rows = old_cols;
  int new_cols = old_rows;
  int size = (new_rows + 1) * (new_cols + 1);
  double *tempnum = calloc(size, sizeof(double));
  char **tempstr = calloc(size, sizeof(char *));
  
  // copy and transpose into temp
  for (int r = 1; r <= old_rows; r++) {
    for (int c = 1; c <= old_cols; c++) {
      int old_index = r * (old_cols + 1) + c; // add 1 to skip the zero column
      int new_index = c * (new_cols + 1)  + r;
      if (ret_array_type == STRING)
        tempstr[new_index] = one_store->array[old_index].string;
      else
        tempnum[new_index] = one_store->array[old_index].number;
    }
  }

  // resize the result matrix
  if (!redim_matrix_to_size(ret_item, new_rows, new_cols)) {
    free(tempnum);
    free(tempstr);
    return;
  }

  // copy back from temp
  for (int r = 1; r <= new_rows; r++) {
    for (int c = 1; c <= new_cols; c++) {
      int slot = r * (new_cols + 1) + c;
      if (ret_array_type == STRING)
        ret_store->array[slot].string = tempstr[slot];
      else
        ret_store->array[slot].number = tempnum[slot];
    }
  }
  
  // and free temp - don't free the strings in tempstr, we're using them
  free(tempnum);
  free(tempstr);
}

double matrix_invert(statement_t *statement)
{
  double det = 1.0;
  double temp;
  
  // find the array storage
  variable_reference_t *ret_item = statement->parms.mat.variable;
  variable_storage_t *ret_store = lst_data_with_key(interpreter_state.variable_values, ret_item->name);
  int ret_array_type = variable_type(ret_item);
  
  // has to be a number
  if (ret_array_type == STRING) {
    handle_error(ern_TYPE_MISMATCH, "MAT INV with string variable result");
    return 0.0;
  }
  
  // get the number of dimensions from the source
  variable_reference_t *src_item = statement->parms.mat.variable2;
  variable_storage_t *src_store = lst_data_with_key(interpreter_state.variable_values, src_item->name);
  int src_array_type = variable_type(src_item);
  
  // has to be a number
  if (src_array_type == STRING) {
    handle_error(ern_TYPE_MISMATCH, "MAT INV with string variable input");
    return 0.0;
  }
  
  // ... and two dimensional
  int src_dims = lst_length(src_store->actual_dimensions);
  if (src_dims == 0) {
    handle_error(ern_TYPE_MISMATCH, "MAT INV with scalar input");
    return 0.0;
  }
  else if (src_dims == 1) {
    handle_error(ern_TYPE_MISMATCH, "MAT INV with vector input");
    return 0.0;
  }
  else if (src_dims > 2) {
    handle_error(ern_TYPE_MISMATCH, "MAT INV with too many dimensions");
    return 0.0;
  }
  
  // ... and square
  list_t *src_dimensions = lst_first_node(src_store->actual_dimensions);
  int rows = POINTER_TO_INT(src_dimensions->data);
  int cols = POINTER_TO_INT(src_dimensions->next->data);
  if (rows != cols) {
    handle_error(ern_TYPE_MISMATCH, "MAT INV with non-square input");
    return 0.0;
  }
  
  // copy the original data to a zero-based matrix for sanity
  double *matrix = calloc(rows * rows, sizeof(double));
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < rows; c++) {
      int old_slot = (r + 1) * (cols + 1) + c + 1;
      int new_slot = r * rows + c;
      matrix[new_slot] = src_store->array[old_slot].number;
    }
  }
  
  // make the inverse
  double *inverse = calloc(rows * rows, sizeof(double));

  // create a the augmented matrix: [A | I]
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rows; j++) {
      if (i == j) {
        *(inverse + i * rows + j) = 1.0;
      } else {
        *(inverse + i * rows + j) = 0.0;
      }
    }
  }
  
  // gaussian elimination....
  for (int i = 0; i < rows; i++) {
    // Find the pivot row (the largest value in the column)
    int max_row = i;
    for (int k = i + 1; k < rows; k++) {
      if (*(matrix + k * rows + i) > *(matrix + max_row * rows + i)) {
        max_row = k;
      }
    }
    
    // swap rows if necessary
    if (max_row != i) {
      for (int j = 0; j < rows; j++) {
        temp = *(matrix + i * rows + j);
        *(matrix + i * rows + j) = *(matrix + max_row * rows + j);
        *(matrix + max_row * rows + j) = temp;
        
        temp = *(inverse + i * rows + j);
        *(inverse + i * rows + j) = *(inverse + max_row * rows + j);
        *(inverse + max_row * rows + j) = temp;
      }
      det = -det; // if the rows are swapped, it changes the sign
    }
    
    // scale the pivot row to make the pivot element equal to 1
    temp = *(matrix + i * rows + i);
    if (temp == 0) {
      free(matrix);
      free(inverse);
      return 0.0;  // Matrix is singular, no inverse exists
    }
    
    det *= temp;
    for (int j = 0; j < rows; j++) {
      *(matrix + i * rows + j) /= temp;
      *(inverse + i * rows + j) /= temp;
    }
    
    // eliminate the column below the pivot
    for (int j = i + 1; j < rows; j++) {
      temp = *(matrix + j * rows + i);
      for (int k = 0; k < rows; k++) {
        *(matrix + j * rows + k) -= *(matrix + i * rows + k) * temp;
        *(inverse + j * rows + k) -= *(inverse + i * rows + k) * temp;
      }
    }
  }
  
  // back-substitute to eliminate above the pivots
  for (int i = rows - 1; i >= 0; i--) {
    for (int j = i - 1; j >= 0; j--) {
      temp = *(matrix + j * rows + i);
      for (int k = 0; k < rows; k++) {
        *(matrix + j * rows + k) -= *(matrix + i * rows + k) * temp;
        *(inverse + j * rows + k) -= *(inverse + i * rows + k) * temp;
      }
    }
  }

  // resize the result if required
  redim_matrix_to_size(ret_item, rows, rows);
  
  // copy the result into the output matrix
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < rows; c++) {
      int old_slot = (r + 1) * (rows + 1) + c + 1;
      int new_slot = r * rows + c;
      ret_store->array[old_slot].number = inverse[new_slot];
    }
  }
  
  // all done
  free(matrix);
  free(inverse);

  return det;
}
