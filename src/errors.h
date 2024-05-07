/* Errors (header) for RetroBASIC
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

#ifndef errors_h
#define errors_h

/**
 * @file errors.h
 * @author Maury Markowitz
 * @date 1 April 2024
 * @brief Definitions of standard BASIC error numbers and messages
 *
 * The numbers are mostly taken from Commodore BASIC and will provide
 * some level of compatibility. A number of errors have not been included.
 * Among these are things like TEXT TOO LONG, which occurs when a Commodore
 * machine attempts to open a source code file longer than 64k. Others,
 * like STRING TO LONG, are included but should never occur.
 */

#define ern_NO_ERROR          0      // no error

#define ern_TOO_MANY_FILES    1      // attempt to OPEN a file with many already OPEN
#define ern_FILE_OPEN         2      // attempt to OPEN a file that's already OPEN
#define ern_FILE_NOT_OPEN     3      // attempt to use a file that's not OPEN
#define ern_FILE_NOT_FOUND    4      // attempt to OPEN a non-existent file
#define ern_DEV_NOT_FOUND     5      // attempt to OPEN a non-existent device - unused in RetroBASIC
#define ern_FILE_NOT_INPUT    6      // attempt to INPUT/GET from a file opened for writing
#define ern_FILE_NOT_OUTPUT   7      // attempt to PRINT/PUT to a file opened for reading
#define ern_FILENAME_MISSING  8      // attempt to OPEN a file with no filename
#define ern_BAD_DEVICE_NUM    9      // attempt to OPEN a device that is invalid

#define ern_READY             12     // no error but paused in ready state
#define ern_BREAK             14     // the user has pressed the BREAK key
#define ern_INPUT_EXTRA       15     // too many items in the input line, extras ignored
#define ern_INPUT_REDO        16     // input character data for a numeric variable
#define ern_NEXT_NO_FOR       20     // NEXT without a FOR on the stack
#define ern_SYNTAX_ERROR      21     // any syntax error
#define ern_RET_NO_GOSUB      22     // RETURN without a GOSUB on the stack
#define ern_OUT_OF_DATA       23     // READ with no remaining data
#define ern_ILLEGAL_VALUE     24     // any parameter out-of-range, like a MID with a start parameter outside the string
#define ern_OVERFLOW          25     // result of calculation is out-of-range - unused in RetroBASIC
#define ern_OUT_OF_MEMORY     26     // unused in RetroBASIC
#define ern_NO_SUCH_LINE      27     // branch to a non-existing line, aka UNDEFINED STATEMENT
#define ern_BAD_SUBSCRIPT     28     // array access outside DIMed range
#define ern_REDIM_ARRAY       29     // DIM being called on an already DIMed variable
#define ern_DIV_BY_ZERO       30     // any division by zero, including integer division
#define ern_DIRECT_MODE       31     // INPUT/GET cannot be used in direct mode - unused in RetroBASIC
#define ern_TYPE_MISMATCH     32     // number provided to string operation or vice versa
#define ern_STRING_TO_LONG    33     // unused in RetroBASIC
#define ern_FORMULA_TOO_LONG  35     // unused in RetroBASIC
#define ern_DEF_UNKNOWN       37     // call to user-defined function that doesn't exist
#define ern_OUT_OF_STACK      40     // unused in RetroBASIC
#define ern_CANT_CONTINUE     41     // RetroBASIC does not support CONTinue
#define ern_RES_NO_TRAP       42     // a RESUME was encountered with no corresponding TRAP

#define ers_TOO_MANY_FILES    "TOO MANY FILES"
#define ers_FILE_OPEN         "FILE OPEN"
#define ers_FILE_NOT_OPEN     "FILE NOT OPEN"
#define ers_FILE_NOT_FOUND    "FILE NOT FOUND"
#define ers_DEV_NOT_FOUND     "DEVICE NOT PRESENT"
#define ers_FILE_NOT_INPUT    "NOT INPUT FILE"
#define ers_FILE_NOT_OUTPUT   "NOT OUTPUT FILE"
#define ers_FILENAME_MISSING  "MISSING FILENAME"
#define ers_BAD_DEVICE_NUM    "ILLEGAL DEVICE NUMBER"
#define ers_READY             "READY"
#define ers_BREAK             "BREAK"
#define ers_INPUT_EXTRA       "EXTRA IGNORED"
#define ers_INPUT_REDO        "REDO FROM START"
#define ers_NEXT_NO_FOR       "NEXT WITHOUT FOR"
#define ers_SYNTAX_ERROR      "SYNTAX"
#define ers_RET_NO_GOSUB      "RETURN WITHOUT GOSUB"
#define ers_OUT_OF_DATA       "OUT OF DATA"
#define ers_ILLEGAL_VALUE     "ILLEGAL QUANTITY"
#define ers_OVERFLOW          "OVERFLOW"
#define ers_OUT_OF_MEMORY     "OUT OF MEMORY"
#define ers_NO_SUCH_LINE      "UNDEFINED STATEMENT"
#define ers_BAD_SUBSCRIPT     "BAD SUBSCRIPT"
#define ers_REDIM_ARRAY       "REDIM'D ARRAY"
#define ers_DIV_BY_ZERO       "DIVISION BY ZERO"
#define ers_DIRECT_MODE       "ILLEGAL DIRECT"
#define ers_TYPE_MISMATCH     "TYPE MISMATCH"
#define ers_STRING_TO_LONG    "STRING TOO LONG"
#define ers_FORMULA_TOO_LONG  "FORMULA TOO COMPLEX"
#define ers_DEF_UNKNOWN       "UNDEFINED FUNCTION"
#define ers_OUT_OF_STACK      "OUT OF STACK"
#define ers_CANT_CONTINUE     "UNABLE TO RESUME"
#define ers_RES_NO_TRAP       "RESUME WITHOUT TRAP"

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
  [ern_RES_NO_TRAP] = ers_RES_NO_TRAP
};

#endif /* errors_h */
