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

#ifndef __ERRORS_H__
#define __ERRORS_H__

/**
 * @file errors.h
 * @author Maury Markowitz
 * @date 1 April 2024
 * @brief Definitions of standard BASIC error numbers and messages
 *
 * The numbers are mostly taken from Commodore BASIC B, and will provide
 * some level of compatibility. A number of these are not used by RetroBASIC,
 * like STRING TO LONG, which simply can't occur. The numbers for these are
 * defined for completeness, but the corresponding message text is not
 * defined and there is no entry in the mapping array.
 */

#define ern_NO_ERROR          0      // no error

#define ern_TOO_MANY_FILES    1      // attempt to OPEN a file with too many already OPEN
#define ern_FILE_OPEN         2      // attempt to OPEN a file that's already OPEN
#define ern_FILE_NOT_OPEN     3      // attempt to use a file that's not OPEN
#define ern_FILE_NOT_FOUND    4      // attempt to OPEN a non-existent file
#define ern_DEV_NOT_FOUND     5      // attempt to OPEN a non-existent device - used for paths
#define ern_FILE_NOT_INPUT    6      // attempt to INPUT/GET from a file opened for writing
#define ern_FILE_NOT_OUTPUT   7      // attempt to PRINT/PUT to a file opened for reading
#define ern_FILENAME_MISSING  8      // attempt to OPEN a file with no filename
#define ern_BAD_DEVICE_NUM    9      // attempt to OPEN a device that is invalid
#define ern_ARE_YOU_SURE      10     // causes "are you sure" message before writing, unused in RetroBASIC
#define ern_FILE_EXISTS       11     // originally ern_BAD_DISK, repurposed as exiting file

#define ern_READY             12     // no error but paused in ready state
#define ern_IN                13     // not an error, this points to the string " IN ". unused in RetroBASIC
#define ern_BREAK             14     // the user has pressed the BREAK key
#define ern_INPUT_EXTRA       15     // too many items in the input line, extras ignored
#define ern_INPUT_REDO        16     // input character data for a numeric variable
#define ern_LAST_NUMBER       17     // not an error, returns last number parsed. unused in RetroBASIC
#define ern_MORE              18     // not an error, this points to the string "MORE". unused in RetroBASIC
#define ern_POWER_ON_MSG      19     // not an error, prints a startup message. unused in RetroBASIC
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
#define ern_FILE_DATA         34     // attempt to read a number from a file but get a non-number. unused in RetroBASIC, returns 32 instead
#define ern_FORMULA_TOO_LONG  35     // unused in RetroBASIC
// no definition for 36 can be found
#define ern_DEF_UNKNOWN       37     // call to user-defined function that doesn't exist
#define ern_LOAD_ERROR        38     // program failed to load from cassette. unused in RetroBASIC
#define ern_VERIFY_ERROR      39     // program failed to verify on saving to cassette. unused in RetroBASIC
#define ern_OUT_OF_STACK      40     // unused in RetroBASIC
#define ern_CANT_CONTINUE     41     // RetroBASIC does not support CONTinue
#define ern_POP_NO_STACK      42     // a POP/EXIT/DISPOSE was called with nothing on the stack
#define ern_OUT_OF_TEXT       43     // loading a file larger than 64. unused in RetroBASIC
#define ern_RES_NO_TRAP       44     // a RESUME was encountered with no corresponding TRAP

#define ers_TOO_MANY_FILES    "TOO MANY FILES"
#define ers_FILE_OPEN         "FILE OPEN"
#define ers_FILE_NOT_OPEN     "FILE NOT OPEN"
#define ers_FILE_NOT_FOUND    "FILE NOT FOUND"
#define ers_DEV_NOT_FOUND     "DEVICE NOT PRESENT"
#define ers_FILE_NOT_INPUT    "NOT INPUT FILE"
#define ers_FILE_NOT_OUTPUT   "NOT OUTPUT FILE"
#define ers_FILENAME_MISSING  "MISSING FILENAME"
#define ers_BAD_DEVICE_NUM    "ILLEGAL DEVICE NUMBER"
#define ers_FILE_EXISTS       "FILE EXISTS"
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
#define ers_POP_NO_STACK      "POP WITHOUT STACK"
#define ers_RES_NO_TRAP       "RESUME WITHOUT TRAP"

/**
 * Maps error numbers to messages.
 *
 */
extern char *error_messages[];

/**
 * Handles runtime errors.
 *
 * If trap_line is set to 0, there is no error handling turned on,
 * in which case it simply reports the error and exits. If trap_line
 * is +ve, it does not report the error and instead moves to the trap.
 *
 * If there is no trap and the error is going to be reported, it will
 * always report the error string and the line where it occurred. If
 * @p message is not empty, it will be printed in parens at the end.
 *
 * @param errnum error number, see errors.h for a list
 * @param message optional message string for extra information
 */
void handle_error(const int errnum, const char *message);

/**
 * Handles runtime warnings.
 *
 * Similar to handle_error, but does not trigger a trap, and does not
 * exit the program. Examples include REDO FROM START.
*
 * @param errnum error number, see errors.h for a list
 * @param message optional message string for extra information
 */
void handle_warning(const int errnum, const char *message);

#endif /* errors_h */
