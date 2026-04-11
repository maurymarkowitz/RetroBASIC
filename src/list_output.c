/* list_output (implementation) for RetroBASIC
   Copyright (C) 2026 Maury Markowitz

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
along with RetroBASIC; see the file COPYING.  */

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "retrobasic.h"
#include "parse.h"
#include "list_output.h"

typedef struct {
  char *data;
  size_t length;
  size_t capacity;
} string_builder_t;

static void sb_init(string_builder_t *sb)
{
  sb->capacity = 128;
  sb->length = 0;
  sb->data = malloc(sb->capacity);
  if (sb->data == NULL) {
    fprintf(stderr, "Malloc failed in list_output\n");
    exit(EXIT_FAILURE);
  }
  sb->data[0] = '\0';
}

static void sb_reserve(string_builder_t *sb, size_t extra)
{
  if (sb->length + extra + 1 > sb->capacity) {
    size_t need = sb->length + extra + 1;
    size_t new_capacity = sb->capacity * 2;
    while (new_capacity < need)
      new_capacity *= 2;
    sb->data = realloc(sb->data, new_capacity);
    if (sb->data == NULL) {
      fprintf(stderr, "Realloc failed in list_output\n");
      exit(EXIT_FAILURE);
    }
    sb->capacity = new_capacity;
  }
}

static void sb_append(string_builder_t *sb, const char *text)
{
  if (text == NULL)
    return;

  size_t added = strlen(text);
  sb_reserve(sb, added);
  memcpy(sb->data + sb->length, text, added);
  sb->length += added;
  sb->data[sb->length] = '\0';
}

static void sb_append_char(string_builder_t *sb, char c)
{
  sb_reserve(sb, 1);
  sb->data[sb->length++] = c;
  sb->data[sb->length] = '\0';
}

static void sb_append_fmt(string_builder_t *sb, const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  va_list ap_copy;
  va_copy(ap_copy, ap);
  int needed = vsnprintf(NULL, 0, fmt, ap_copy);
  va_end(ap_copy);
  if (needed < 0) {
    va_end(ap);
    return;
  }

  sb_reserve(sb, (size_t)needed);
  vsnprintf(sb->data + sb->length, sb->capacity - sb->length, fmt, ap);
  sb->length += (size_t)needed;
  sb->data[sb->length] = '\0';
  va_end(ap);
}

static void sb_free(string_builder_t *sb)
{
  free(sb->data);
  sb->data = NULL;
  sb->capacity = 0;
  sb->length = 0;
}

static int expression_precedence(const expression_t *expression)
{
  if (expression == NULL)
    return 0;
  if (expression->type != op)
    return 0;

  int opcode = expression->parms.op.opcode;
  switch (opcode) {
    case NOT:
    case '-':
      return 1;
    case '^':
      return 2;
    case '*':
    case '/':
    case MOD:
    case DIV:
    case MAX:
    case MIN:
      return 3;
    case '+':
    case '&':
      return 4;
    case '=':
    case '<':
    case '>':
    case CMP_LE:
    case CMP_GE:
    case CMP_NE:
    case HASH:
      return 5;
    case AND:
      return 6;
    case OR:
      return 7;
    default:
      return 0;
  }
}

static bool expression_is_infix(const expression_t *expression)
{
  if (expression == NULL || expression->type != op)
    return false;

  switch (expression->parms.op.opcode) {
    case '+':
    case '-':
    case '*':
    case '/':
    case MOD:
    case DIV:
    case MAX:
    case MIN:
    case AND:
    case OR:
    case EQV:
    case IMP:
    case '=':
    case '<':
    case '>':
    case CMP_LE:
    case CMP_GE:
    case CMP_NE:
    case HASH:
      return true;
    default:
      return false;
  }
}

static const char *operator_token_name(int opcode)
{
  switch (opcode) {
    case '+': return "+";
    case '-': return "-";
    case '*': return "*";
    case '/': return "/";
    case '^': return "^";
    case MOD: return "MOD";
    case DIV: return "DIV";
    case MAX: return "MAX";
    case MIN: return "MIN";
    case AND: return "AND";
    case OR: return "OR";
    case EQV: return "EQV";
    case IMP: return "IMP";
    case '=': return "=";
    case '<': return "<";
    case '>': return ">";
    case CMP_LE: return "<=";
    case CMP_GE: return ">=";
    case CMP_NE: return "<>";
    case HASH: return "#";
    default: return NULL;
  }
}

static const char *function_token_name(int opcode)
{
  switch (opcode) {
    case ABS: return "ABS";
    case SGN: return "SGN";
    case CLOG: return "CLOG";
    case EXP: return "EXP";
    case LOG: return "LOG";
    case SQR: return "SQR";
    case PI: return "PI";
    case RND: return "RND";
    case INT: return "INT";
    case FIX: return "FIX";
    case FRAC: return "FRAC";
    case ROUND: return "ROUND";
    case CINT: return "CINT";
    case CSNG: return "CSNG";
    case CDBL: return "CDBL";
    case COS: return "COS";
    case SIN: return "SIN";
    case ATN: return "ATN";
    case ACS: return "ACS";
    case ASN: return "ASN";
    case TAN: return "TAN";
    case COSH: return "COSH";
    case SINH: return "SINH";
    case TANH: return "TANH";
    case ASC: return "ASC";
    case VAL: return "VAL";
    case LEN: return "LEN";
    case SEG: return "SEG";
    case SUBSTR: return "SUBSTR";
    case INSTR: return "INSTR";
    case ADR: return "ADR";
    case FRE: return "FRE";
    case SPC: return "SPC";
    case TAB: return "TAB";
    case POS: return "POS";
    case USR: return "USR";
    case LIN: return "LIN";
    case UBOUND: return "UBOUND";
    case LBOUND: return "LBOUND";
    case LEFT: return "LEFT$";
    case RIGHT: return "RIGHT$";
    case MID: return "MID$";
    case STR: return "STR$";
    case CHR: return "CHR$";
    case UCASE: return "UCASE$";
    case LCASE: return "LCASE$";
    case TIME_STR: return "TIME$";
    case BINSTR: return "BIN$";
    case HEXSTR: return "HEX$";
    case OCTSTR: return "OCT$";
    case STRNG: return "STRING$";
    case INKEY: return "INKEY$";
    default:
      return operator_token_name(opcode);
  }
}

static char *format_number(double d)
{
  char temp[64];
  if (floor(d) == d) {
    sprintf(temp, "%.0f", d);
  } else {
    sprintf(temp, "%g", d);
  }
  return strdup(temp);
}

static char *format_string_literal(const char *text)
{
  if (text == NULL)
    return strdup("\"\"");

  char *escaped = str_escape(text);
  size_t length = strlen(escaped) + 3;
  char *result = malloc(length);
  if (result == NULL) {
    fprintf(stderr, "Malloc failed in format_string_literal\n");
    exit(EXIT_FAILURE);
  }
  sprintf(result, "\"%s\"", escaped);
  free(escaped);
  return result;
}

static void append_expression(string_builder_t *sb, expression_t *expression, int parent_precedence);

static void append_variable_reference(string_builder_t *sb, variable_reference_t *variable)
{
  if (variable == NULL)
    return;

  sb_append(sb, variable->name);

  if (variable->subscripts != NULL) {
    sb_append_char(sb, '(');
    bool first = true;
    for (list_t *item = lst_first_node(variable->subscripts); item != NULL; item = lst_next(item)) {
      if (!first)
        sb_append(sb, ",");
      append_expression(sb, item->data, 0);
      first = false;
    }
    sb_append_char(sb, ')');
  }

  if (variable->slicing != NULL) {
    if (string_slicing) {
      sb_append_char(sb, '(');
    } else {
      sb_append_char(sb, '[');
    }

    list_t *first = lst_first_node(variable->slicing);
    list_t *second = NULL;
    if (first)
      second = lst_next(first);

    if (first)
      append_expression(sb, first->data, 0);

    if (second) {
      if (string_slicing) {
        sb_append(sb, " TO ");
      } else {
        sb_append_char(sb, ':');
      }
      append_expression(sb, second->data, 0);
    }

    if (string_slicing) {
      sb_append_char(sb, ')');
    } else {
      sb_append_char(sb, ']');
    }
  }
}

static void append_expression(string_builder_t *sb, expression_t *expression, int parent_precedence)
{
  if (expression == NULL)
    return;

  if (expression->type == number) {
    char *number_text = format_number(expression->parms.number);
    sb_append(sb, number_text);
    free(number_text);
    return;
  }

  if (expression->type == string) {
    char *quoted = format_string_literal(expression->parms.string);
    sb_append(sb, quoted);
    free(quoted);
    return;
  }

  if (expression->type == variable) {
    append_variable_reference(sb, expression->parms.variable);
    return;
  }

  if (expression->type == fn) {
    variable_reference_t *func = expression->parms.variable;
    if (func == NULL)
      return;
    sb_append(sb, func->name);
    sb_append_char(sb, '(');
    bool first = true;
    for (list_t *item = lst_first_node(func->subscripts); item != NULL; item = lst_next(item)) {
      if (!first)
        sb_append(sb, ",");
      append_expression(sb, item->data, 0);
      first = false;
    }
    sb_append_char(sb, ')');
    return;
  }

  if (expression->type == op) {
    int precedence = expression_precedence(expression);
    bool needs_paren = precedence > parent_precedence && parent_precedence > 0;
    if (needs_paren)
      sb_append_char(sb, '(');

    int opcode = expression->parms.op.opcode;

    if (opcode == '^' && expression->parms.op.arity == 2) {
      append_expression(sb, expression->parms.op.p[0], precedence);
      sb_append(sb, "^");
      append_expression(sb, expression->parms.op.p[1], precedence);
    } else if (expression_is_infix(expression)) {
      append_expression(sb, expression->parms.op.p[0], precedence);
      sb_append(sb, operator_token_name(opcode));
      append_expression(sb, expression->parms.op.p[1], precedence);
    } else if (opcode == NOT) {
      sb_append(sb, "NOT ");
      append_expression(sb, expression->parms.op.p[0], precedence);
    } else if (opcode == '-') {
      sb_append_char(sb, '-');
      append_expression(sb, expression->parms.op.p[0], precedence);
    } else {
      const char *name = function_token_name(opcode);
      if (name == NULL)
        name = "UNKNOWN";
      sb_append(sb, name);
      sb_append_char(sb, '(');
      for (int i = 0; i < expression->parms.op.arity; i++) {
        if (i > 0)
          sb_append(sb, ",");
        append_expression(sb, expression->parms.op.p[i], 0);
      }
      sb_append_char(sb, ')');
    }

    if (needs_paren)
      sb_append_char(sb, ')');
    return;
  }
}

static void append_varlist(string_builder_t *sb, list_t *list)
{
  bool first = true;
  for (list_t *item = lst_first_node(list); item != NULL; item = lst_next(item)) {
    if (!first)
      sb_append(sb, ",");
    append_variable_reference(sb, item->data);
    first = false;
  }
}

static void append_exprlist(string_builder_t *sb, list_t *list)
{
  bool first = true;
  for (list_t *item = lst_first_node(list); item != NULL; item = lst_next(item)) {
    if (!first)
      sb_append(sb, ",");
    append_expression(sb, item->data, 0);
    first = false;
  }
}

static void append_printlist(string_builder_t *sb, list_t *list)
{
  bool first = true;
  for (list_t *item = lst_first_node(list); item != NULL; item = lst_next(item)) {
    printitem_t *print_item = item->data;
    if (!first)
      ;
    if (print_item == NULL)
      continue;

    if (print_item->expression) {
      append_expression(sb, print_item->expression, 0);
    }
    if (print_item->separator == ',') {
      sb_append(sb, ",");
    } else if (print_item->separator == ';') {
      sb_append_char(sb, ';');
    }
    first = false;
  }
}

static char *statement_to_string(statement_t *statement)
{
  if (statement == NULL)
    return strdup("");

  string_builder_t sb;
  sb_init(&sb);

  switch (statement->type) {
    case REM:
    case QUOTEREM:
    case BANGREM:
      sb_append(&sb, "REM ");
      if (statement->parms.rem)
        sb_append(&sb, statement->parms.rem);
      break;
    case BYE:
      sb_append(&sb, "BYE");
      break;
    case CLEAR:
      sb_append(&sb, "CLEAR");
      break;
    case CLS:
      sb_append(&sb, "CLS");
      break;
    case CMD:
      sb_append(&sb, "CMD");
      break;
    case DATA:
      sb_append(&sb, "DATA ");
      append_exprlist(&sb, statement->parms.data);
      break;
    case DEF:
      sb_append(&sb, "DEF ");
      append_variable_reference(&sb, statement->parms.def.signature);
      sb_append(&sb, "=");
      append_expression(&sb, statement->parms.def.formula, 0);
      break;
    case DEFSTR:
      switch (statement->parms.deftype.type) {
        case DOUBLE: sb_append(&sb, "DEFDBL "); break;
        case INTEGER: sb_append(&sb, "DEFINT "); break;
        case SINGLE: sb_append(&sb, "DEFSNG "); break;
        case STRING: sb_append(&sb, "DEFSTR "); break;
        default: sb_append(&sb, "DEFSTR "); break;
      }
      append_varlist(&sb, statement->parms.deftype.vars);
      break;
    case DIM:
      sb_append(&sb, "DIM ");
      append_varlist(&sb, statement->parms.dim);
      break;
    case REDIM:
      sb_append(&sb, "REDIM ");
      if (statement->parms.redim.preserve)
        sb_append(&sb, "PRESERVE ");
      append_varlist(&sb, statement->parms.redim.varlist);
      break;
    case END:
      sb_append(&sb, "END");
      break;
    case EXIT:
      sb_append(&sb, "EXIT");
      break;
    case FOR:
      sb_append(&sb, "FOR ");
      append_variable_reference(&sb, statement->parms._for.variable);
      sb_append(&sb, "=");
      append_expression(&sb, statement->parms._for.begin, 0);
      sb_append(&sb, " TO ");
      append_expression(&sb, statement->parms._for.end, 0);
      if (statement->parms._for.step) {
        sb_append(&sb, " STEP ");
        append_expression(&sb, statement->parms._for.step, 0);
      }
      break;
    case GOSUB:
      sb_append(&sb, "GOSUB ");
      if (statement->parms.gosub)
        append_expression(&sb, statement->parms.gosub, 0);
      break;
    case GOTO:
      sb_append(&sb, "GOTO ");
      if (statement->parms._goto)
        append_expression(&sb, statement->parms._goto, 0);
      break;
    case INPUT:
      sb_append(&sb, "INPUT ");
      append_printlist(&sb, statement->parms.input);
      break;
    case INPUT_FILE:
      sb_append(&sb, "INPUT #");
      append_expression(&sb, statement->parms.generic.generic_parameter, 0);
      sb_append(&sb, ",");
      append_printlist(&sb, statement->parms.input);
      break;
    case INPUT_LINE:
      sb_append(&sb, "INPUT LINE ");
      if (statement->parms.generic.generic_parameter) {
        sb_append(&sb, "#");
        append_expression(&sb, statement->parms.generic.generic_parameter, 0);
        sb_append(&sb, ",");
      }
      append_printlist(&sb, statement->parms.input);
      break;
    case IF:
      sb_append(&sb, "IF ");
      append_expression(&sb, statement->parms._if.condition, 0);
      sb_append(&sb, " THEN ");
      if (statement->parms._if.then_expression) {
        bool first = true;
        for (list_t *item = lst_first_node(statement->parms._if.then_expression); item != NULL; item = lst_next(item)) {
          if (!first)
            sb_append(&sb, ": ");
          char *child = statement_to_string(item->data);
          sb_append(&sb, child);
          free(child);
          first = false;
        }
      } else {
        sb_append_fmt(&sb, "%d", statement->parms._if.then_linenumber);
      }
      break;
    case LABEL:
      sb_append(&sb, "LABEL ");
      append_variable_reference(&sb, statement->parms.label.variable);
      break;
    case LET:
      if (statement->let_explicit)
        sb_append(&sb, "LET ");
      append_variable_reference(&sb, statement->parms.let.variable);
      sb_append(&sb, "=");
      append_expression(&sb, statement->parms.let.expression, 0);
      break;
    case NEXT:
      sb_append(&sb, "NEXT");
      if (statement->parms.next) {
        sb_append(&sb, " ");
        append_varlist(&sb, statement->parms.next);
      }
      break;
    case NEW:
      sb_append(&sb, "NEW");
      break;
    case ON:
      sb_append(&sb, "ON ");
      if (statement->parms.on.expression)
        append_expression(&sb, statement->parms.on.expression, 0);
      sb_append(&sb, statement->parms.on.type == GOSUB ? " GOSUB " : statement->parms.on.type == GOTO ? " GOTO " : " GOTO ");
      append_exprlist(&sb, statement->parms.on.numbers);
      break;
    case OPEN:
      sb_append(&sb, "OPEN ");
      if (statement->parms.generic.generic_parameter) {
        append_expression(&sb, statement->parms.generic.generic_parameter, 0);
        sb_append(&sb, ",");
      }
      append_expression(&sb, statement->parms.generic.generic_parameter2, 0);
      sb_append(&sb, ",");
      append_expression(&sb, statement->parms.generic.generic_parameter3, 0);
      break;
    case OPTION:
      sb_append(&sb, "OPTION BASE ");
      append_expression(&sb, statement->parms.generic.generic_parameter, 0);
      break;
    case PAUSE:
      sb_append(&sb, "PAUSE");
      if (statement->parms.generic.generic_parameter) {
        sb_append(&sb, " ");
        append_expression(&sb, statement->parms.generic.generic_parameter, 0);
      }
      break;
    case POKE:
      sb_append(&sb, "POKE ");
      append_expression(&sb, statement->parms.generic.generic_parameter, 0);
      sb_append(&sb, ",");
      append_expression(&sb, statement->parms.generic.generic_parameter2, 0);
      break;
    case POP:
      sb_append(&sb, "POP");
      break;
    case PRINT:
    {
      bool has_format = statement->parms.print.format != NULL;
      bool has_items = statement->parms.print.item_list != NULL;
      sb_append(&sb, "PRINT");
      if (has_format || has_items) {
        sb_append_char(&sb, ' ');
        if (has_format) {
          sb_append(&sb, "USING ");
          append_expression(&sb, statement->parms.print.format, 0);
          if (has_items)
            sb_append(&sb, "; ");
        }
        append_printlist(&sb, statement->parms.print.item_list);
      }
    }
      break;
    case PRINT_FILE:
    {
      bool has_format = statement->parms.print.format != NULL;
      bool has_items = statement->parms.print.item_list != NULL;
      sb_append(&sb, "PRINT #");
      append_expression(&sb, statement->parms.print.channel, 0);
      if (has_format || has_items) {
        if (has_format) {
          sb_append(&sb, " USING ");
          append_expression(&sb, statement->parms.print.format, 0);
          if (has_items)
            sb_append(&sb, "; ");
        } else if (has_items) {
          sb_append(&sb, ", ");
        }
        append_printlist(&sb, statement->parms.print.item_list);
      }
    }
      break;
    case PUT:
      sb_append(&sb, "PUT ");
      append_expression(&sb, statement->parms.generic.generic_parameter, 0);
      break;
    case PUT_FILE:
      sb_append(&sb, "PUT #");
      append_expression(&sb, statement->parms.generic.generic_parameter, 0);
      sb_append(&sb, ", ");
      append_expression(&sb, statement->parms.generic.generic_parameter2, 0);
      break;
    case RAISE:
      sb_append(&sb, "RAISE ");
      append_expression(&sb, statement->parms.generic.generic_parameter, 0);
      break;
    case RANDOMIZE:
      sb_append(&sb, "RANDOMIZE");
      if (statement->parms.generic.generic_parameter) {
        sb_append(&sb, " ");
        append_expression(&sb, statement->parms.generic.generic_parameter, 0);
      }
      break;
    case READ:
      sb_append(&sb, "READ ");
      append_varlist(&sb, statement->parms.read);
      break;
    case RESTORE:
      sb_append(&sb, "RESTORE");
      if (statement->parms.generic.generic_parameter) {
        sb_append(&sb, " ");
        append_expression(&sb, statement->parms.generic.generic_parameter, 0);
      }
      break;
    case RESUME:
      sb_append(&sb, "RESUME");
      if (statement->parms.generic.generic_parameter) {
        sb_append(&sb, " ");
        append_expression(&sb, statement->parms.generic.generic_parameter, 0);
      }
      break;
    case RETURN:
      sb_append(&sb, "RETURN");
      if (statement->parms.generic.generic_parameter) {
        sb_append(&sb, " ");
        append_expression(&sb, statement->parms.generic.generic_parameter, 0);
      }
      break;
    case STOP:
      sb_append(&sb, "STOP");
      if (statement->parms.generic.generic_parameter) {
        sb_append(&sb, " ");
        append_expression(&sb, statement->parms.generic.generic_parameter, 0);
      }
      break;
    case STRNG:
      sb_append(&sb, "STRING$ ");
      append_expression(&sb, statement->parms.generic.generic_parameter, 0);
      break;
    case SYS:
      sb_append(&sb, "SYS ");
      append_expression(&sb, statement->parms.generic.generic_parameter, 0);
      break;
    case TAB:
      sb_append(&sb, "TAB ");
      append_expression(&sb, statement->parms.generic.generic_parameter, 0);
      break;
    case TIME_STR:
      sb_append(&sb, "TIME$");
      if (statement->parms.generic.generic_parameter) {
        sb_append(&sb, "=");
        append_expression(&sb, statement->parms.generic.generic_parameter, 0);
      }
      break;
    case TRAP:
      sb_append(&sb, "TRAP");
      if (statement->parms.generic.generic_parameter) {
        sb_append(&sb, " ");
        append_expression(&sb, statement->parms.generic.generic_parameter, 0);
      }
      break;
    case VARLIST:
      sb_append(&sb, "VARLIST");
      break;
    case WAIT:
      sb_append(&sb, "WAIT");
      if (statement->parms.generic.generic_parameter) {
        sb_append(&sb, " ");
        append_expression(&sb, statement->parms.generic.generic_parameter, 0);
      }
      break;
    case MAT:
      sb_append(&sb, "MAT ");
      append_variable_reference(&sb, statement->parms.mat.variable);
      sb_append(&sb, "=");
      if (statement->parms.mat.variable2) {
        append_variable_reference(&sb, statement->parms.mat.variable2);
      } else if (statement->parms.mat.expression) {
        sb_append_char(&sb, '(');
        append_expression(&sb, statement->parms.mat.expression, 0);
        sb_append_char(&sb, ')');
      }
      break;
    case MATADD:
      sb_append(&sb, "MAT ");
      append_variable_reference(&sb, statement->parms.mat.variable);
      sb_append(&sb, "=");
      append_variable_reference(&sb, statement->parms.mat.variable2);
      sb_append(&sb, " + ");
      append_variable_reference(&sb, statement->parms.mat.variable3);
      break;
    case MATSUB:
      sb_append(&sb, "MAT ");
      append_variable_reference(&sb, statement->parms.mat.variable);
      sb_append(&sb, "=");
      append_variable_reference(&sb, statement->parms.mat.variable2);
      sb_append(&sb, " - ");
      append_variable_reference(&sb, statement->parms.mat.variable3);
      break;
    case MATSCA:
      sb_append(&sb, "MAT ");
      append_variable_reference(&sb, statement->parms.mat.variable);
      sb_append(&sb, " = (");
      append_expression(&sb, statement->parms.mat.expression, 0);
      sb_append(&sb, ") * ");
      append_variable_reference(&sb, statement->parms.mat.variable3);
      break;
    case MATMUL:
      sb_append(&sb, "MAT ");
      append_variable_reference(&sb, statement->parms.mat.variable);
      sb_append(&sb, "=");
      append_variable_reference(&sb, statement->parms.mat.variable2);
      sb_append(&sb, " * ");
      append_variable_reference(&sb, statement->parms.mat.variable3);
      break;
    case MATPRINT:
      sb_append(&sb, "MAT PRINT ");
      append_printlist(&sb, statement->parms.print.item_list);
      break;
    case MATINPUT:
      sb_append(&sb, "MAT INPUT ");
      append_printlist(&sb, statement->parms.input);
      break;
    case MATREAD:
      sb_append(&sb, "MAT READ ");
      append_varlist(&sb, statement->parms.read);
      break;
    case MATCON:
      sb_append(&sb, "MAT ");
      append_variable_reference(&sb, statement->parms.mat.variable);
      sb_append(&sb, " = MATCON");
      if (statement->parms.mat.variable->subscripts) {
        sb_append_char(&sb, '(');
        append_exprlist(&sb, statement->parms.mat.variable->subscripts);
        sb_append(&sb, ")");
      }
      break;
    case MATZER:
      sb_append(&sb, "MAT ");
      append_variable_reference(&sb, statement->parms.mat.variable);
      sb_append(&sb, " = MATZER");
      if (statement->parms.mat.variable->subscripts) {
        sb_append_char(&sb, '(');
        append_exprlist(&sb, statement->parms.mat.variable->subscripts);
        sb_append(&sb, ")");
      }
      break;
    case MATNUL:
      sb_append(&sb, "MAT ");
      append_variable_reference(&sb, statement->parms.mat.variable);
      sb_append(&sb, " = MATNUL");
      if (statement->parms.mat.variable->subscripts) {
        sb_append_char(&sb, '(');
        append_exprlist(&sb, statement->parms.mat.variable->subscripts);
        sb_append(&sb, ")");
      }
      break;
    case MATIDN:
      sb_append(&sb, "MAT ");
      append_variable_reference(&sb, statement->parms.mat.variable);
      sb_append(&sb, " = MATIDN");
      if (statement->parms.mat.variable->subscripts) {
        sb_append_char(&sb, '(');
        append_exprlist(&sb, statement->parms.mat.variable->subscripts);
        sb_append(&sb, ")");
      }
      break;
    case MATTRN:
      sb_append(&sb, "MAT ");
      append_variable_reference(&sb, statement->parms.mat.variable);
      sb_append(&sb, " = MATTRN(");
      append_variable_reference(&sb, statement->parms.mat.variable2);
      sb_append(&sb, ")");
      break;
    case MATINV:
      sb_append(&sb, "MAT ");
      append_variable_reference(&sb, statement->parms.mat.variable);
      sb_append(&sb, " = MATINV(");
      append_variable_reference(&sb, statement->parms.mat.variable2);
      sb_append(&sb, ")");
      if (statement->parms.mat.variable3) {
        sb_append(&sb, ", ");
        append_variable_reference(&sb, statement->parms.mat.variable3);
      }
      break;
    case MATDET:
      sb_append(&sb, "MAT ");
      append_variable_reference(&sb, statement->parms.mat.variable);
      sb_append(&sb, " = MATDET");
      break;
    case LIST:
      sb_append(&sb, "LIST");
      if (statement->parms.generic.generic_parameter) {
        sb_append(&sb, " ");
        append_expression(&sb, statement->parms.generic.generic_parameter, 0);
        if (statement->parms.generic.generic_parameter2) {
          sb_append(&sb, " - ");
          append_expression(&sb, statement->parms.generic.generic_parameter2, 0);
        }
      }
      break;
    case LIST_FILE:
      sb_append(&sb, "LIST #");
      append_expression(&sb, statement->parms.generic.generic_parameter, 0);
      if (statement->parms.generic.generic_parameter2) {
        sb_append(&sb, " ");
        append_expression(&sb, statement->parms.generic.generic_parameter2, 0);
        if (statement->parms.generic.generic_parameter3) {
          sb_append(&sb, " - ");
          append_expression(&sb, statement->parms.generic.generic_parameter3, 0);
        }
      }
      break;
    case SAVE:
      sb_append(&sb, "SAVE ");
      append_expression(&sb, statement->parms.generic.generic_parameter, 0);
      break;
    case LOAD:
      sb_append(&sb, "LOAD ");
      append_expression(&sb, statement->parms.generic.generic_parameter, 0);
      break;
    default:
      sb_append(&sb, "UNKNOWN");
      break;
  }

  return sb.data;
}

char *list_output_program(int start_line, int end_line)
{
  if (start_line < 0)
    start_line = 0;
  if (end_line < 0)
    end_line = MAX_LINE_NUMBER - 1;
  if (start_line >= MAX_LINE_NUMBER)
    return strdup("");
  if (end_line >= MAX_LINE_NUMBER)
    end_line = MAX_LINE_NUMBER - 1;
  if (end_line < start_line)
    return strdup("");

  string_builder_t output;
  sb_init(&output);

  for (int line = start_line; line <= end_line; line++) {
    list_t *line_statements = interpreter_state.lines[line];
    if (line_statements == NULL)
      continue;

    bool first_statement = true;
    list_t *next_line_head = NULL;
    for (int next = line + 1; next < MAX_LINE_NUMBER; next++) {
      if (interpreter_state.lines[next] != NULL) {
        next_line_head = interpreter_state.lines[next];
        break;
      }
    }

    string_builder_t sb;
    sb_init(&sb);
    sb_append_fmt(&sb, "%d ", line);

    for (list_t *stmt_node = line_statements; stmt_node != NULL && stmt_node != next_line_head; stmt_node = lst_next(stmt_node)) {
      statement_t *statement = stmt_node->data;
      if (statement == NULL)
        continue;

      if (!first_statement)
        sb_append(&sb, ":");

      char *statement_text = statement_to_string(statement);
      sb_append(&sb, statement_text);
      free(statement_text);
      first_statement = false;
    }

    if (!first_statement) {
      sb_append(&output, sb.data);
      sb_append_char(&output, '\n');
    }

    sb_free(&sb);
  }

  char *result = strdup(output.data);
  sb_free(&output);
  return result;
}
