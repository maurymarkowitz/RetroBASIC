//
//  errors.c
//  retrobasic
//
//  Created by Maury Markowitz on 2024-11-17.
//  Copyright © 2024 Maury Markowitz. All rights reserved.
//

#include "errors.h"

char *error_messages[] = {
  [ern_FILE_OPEN] = ers_FILE_OPEN,
  [ern_FILE_NOT_OPEN] = ers_FILE_NOT_OPEN,
  [ern_FILE_NOT_FOUND] = ers_FILE_NOT_FOUND,
  [ern_DEV_NOT_FOUND] = ers_DEV_NOT_FOUND,
  [ern_FILE_NOT_INPUT] = ers_FILE_NOT_INPUT,
  [ern_FILE_NOT_OUTPUT] = ers_FILE_NOT_OUTPUT,
  [ern_FILENAME_MISSING] = ers_FILENAME_MISSING,
  [ern_READY] = ers_READY,
  [ern_BREAK] = ers_BREAK,
  [ern_INPUT_EXTRA] = ers_INPUT_EXTRA,
  [ern_INPUT_REDO] = ers_INPUT_REDO,
  [ern_NEXT_NO_FOR] = ers_NEXT_NO_FOR,
  [ern_SYNTAX_ERROR] = ers_SYNTAX_ERROR,
  [ern_RET_NO_GOSUB] = ers_RET_NO_GOSUB,
  [ern_OUT_OF_DATA] = ers_OUT_OF_DATA,
  [ern_ILLEGAL_VALUE] = ers_ILLEGAL_VALUE,
  [ern_OVERFLOW] = ers_OVERFLOW,
  [ern_OUT_OF_MEMORY] = ers_OUT_OF_MEMORY,
  [ern_NO_SUCH_LINE] = ers_NO_SUCH_LINE,
  [ern_BAD_SUBSCRIPT] = ers_BAD_SUBSCRIPT,
  [ern_REDIM_ARRAY] = ers_REDIM_ARRAY,
  [ern_DIV_BY_ZERO] = ers_DIV_BY_ZERO,
  [ern_DIRECT_MODE] = ers_DIRECT_MODE,
  [ern_TYPE_MISMATCH] = ers_TYPE_MISMATCH,
  [ern_STRING_TO_LONG] = ers_STRING_TO_LONG,
  [ern_FORMULA_TOO_LONG] = ers_FORMULA_TOO_LONG,
  [ern_DEF_UNKNOWN] = ers_DEF_UNKNOWN,
  [ern_OUT_OF_STACK] = ers_OUT_OF_STACK,
  [ern_CANT_CONTINUE] = ers_CANT_CONTINUE,
  [ern_POP_NO_STACK] = ers_POP_NO_STACK,
  [ern_RES_NO_TRAP] = ers_RES_NO_TRAP
};
