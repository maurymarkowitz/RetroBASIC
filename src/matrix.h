/* matrix (header) for RetroBASIC
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

/**
 * @file matrix.h
 * @author Maury Markowitz
 * @date 11 May 2024
 *
 * @title Dartmouth-style matrix functions
 * @brief Basic matrix math and various work methods for MAT statements
 *
 * This code includes a number of work methods for common matrix math like
 * multiplication or transposing. The key difference between these methods and
 * the many stock ones found on the 'net is that these work on 1..n as opposed
 * to a normal C array which is 0..n-1. This matches the way Dartmouth BASIC
 * organizes its arrays. Items are allowed in the 0 indexes, but are ignored
 * in this code, which, like Dartmouth, can result in odd output when not
 * expected if the matrix changes dimensions as a side-effect of the calc.
 *
 * These are not general purpose routines and are not expected to be used with
 * other programs, unlike list or strng. This code needs to know about
 * statement_t which requires it to import retrobasic.h, and will report errors
 * and cause execution to stop if one is encountered.
 *
 */

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include "retrobasic.h"

/**
 * Used for REDIM and similar instructions that have to resize an array
 * or matrix to a specified size. Most of the matrix functions will
 * call this even if the size is the same before and after.
 *
 * @param destination_ref The array to resize.
 * @param x the X dimension, must be > 0.
 * @param y the Y dimension. Optional, if not being used, set to -1 for clarity.
 * @return true if the resize worked, false otherwise.
 */
bool redim_matrix_to_size(variable_reference_t *destination_ref, int x, int y);

/**
 * Fills the destination matrix with a given double value.
 * Used for ZER and CON and numeric expression assignments.
 *
 * @param statement the statement containing the fill operation.
 * @param fill_value the numeric value to fill it with. This
 * function checks to make sure the array is numeric and will
 * report an error if it is not.
*/
void matrix_fill_num(statement_t *statement, double fill_value);

/**
 * Fills the destination matrix with a given string value.
 * Used for string expression assignments. This function checks
 * to make sure the array is a string and will report an error
 * if it is not.
 *
 * @param statement the statement containing the fill operation.
 * @param fill_value the string value to fill it with.
*/
void matrix_fill_str(statement_t *statement, char *fill_value);

/**
 * Makes the destination matrix into an identity matrix. The matrix has
 * to be numeric, and square.
 *
 * @param statement the statement containing the fill operation.
*/
void matrix_identity(statement_t *statement);

/**
 * Copies the values in the source matrix to the destination matrix.
 *
 * @param size the actual dimensions of the source array.
 * @param destination the destination matrix the values will be copied into.
 * @param source the source matrix.
*/
void matrix_copy(statement_t *statement);

/**
 * Adds the values in one array to the values already in another.
 *
 * @param size the actual dimensions of the resulting array.
 * @param matrix the destination matrix.
 * @param addend the source matrix the addition values will be taken from.
*/
void matrix_add(statement_t *statement);

/**
 * Subtracts the values in one array from the values already in another.
 *
 * @param size the actual dimensions of the resulting array.
 * @param matrix the destination matrix.
 * @param subtrahend the source matrix the subtraction values will be taken from.
*/
void matrix_sub(statement_t *statement);

/**
 * Multiplies the values in one array by the values in another.
 *
 * @param size the actual dimensions of the resulting array.
 * @param matrix the destination matrix.
 * @param multiplier the source matrix the multiplier values will be taken from.
*/
void matrix_mul(statement_t *statement);

/**
 * Multiplies the values in a matrix by a double value.
 *
 * @param size the actual dimensions of the resulting array.
 * @param matrix the destination matrix.
*/
void matrix_mul_const(statement_t *statement);

/**
 * Transposes a matrix.
 *
 * @param size the actual dimensions of the resulting array.
 * @param matrix the destination matrix.
*/
void matrix_transpose(statement_t *statement);

/**
 * Inverts a matrix.
 *
 * Unlike the other functions in this library, inverting an array is almost always then used to
 * modify the original array, so when this function is used the original will generally need
 * to be left in the original form.
 *
 * Additionally, this function can fail, so it returns an integer value.
 *
 * @param statement the statement containing the matrix to invert.
 * @return determinant, used to indicate if the operation was successful.
*/
double matrix_invert(statement_t *statement);
    
#endif /* matrix_h */
