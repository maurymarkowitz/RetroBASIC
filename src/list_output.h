/* list_output (header) for RetroBASIC
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

#ifndef __LIST_OUTPUT_H__
#define __LIST_OUTPUT_H__

#include "retrobasic.h"

/**
 * Generate a canonical LIST of the current tokenized program.
 *
 * @param start_line The first line number to include.
 * @param end_line The last line number to include.
 * @return A heap-allocated string containing the LIST output. Caller must free it.
 */
char *list_output_program(int start_line, int end_line);

#endif /* __LIST_OUTPUT_H__ */
