/* Statistics (header) for RetroBASIC
 Copyright (C) 2020 Maury Markowitz
 
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

#ifndef __STATISTICS_H__
#define __STATISTICS_H__

#include "stdhdr.h"
#include "retrobasic.h"

/* additional externs used for the static analyzer, used in parse.y */
extern clock_t start_ticks, end_ticks;  // start and end ticks, for calculating CPU time
extern struct timeval start_time, end_time;     // start and end clock, for total run time

extern int variables_total;
extern int variables_default;
extern int variables_int;
extern int variables_float;
extern int variables_double;
extern int variables_string;
extern int numeric_constants_total;
extern int numeric_constants_float;
extern int numeric_constants_zero;
extern int numeric_constants_one;
extern int numeric_constants_minus_one;
extern int numeric_constants_one_digit;
extern int numeric_constants_two_digit;
extern int numeric_constants_three_digit;
extern int numeric_constants_four_digit;
extern int numeric_constants_five_digit;
extern int numeric_constants_big;
extern int numeric_constants_one_byte;
extern int numeric_constants_two_byte;
extern int numeric_constants_four_byte;
extern int string_constants_total;
extern int string_constants_zero;
extern int string_constants_one_byte;
extern int string_constants_two_byte;
extern int string_constants_four_byte;
extern int string_constants_eight_byte;
extern int string_constants_sixteen_byte;
extern int string_constants_big;
extern int string_constants_max;
extern int linenum_constants_total;
extern int linenum_forwards;
extern int linenum_backwards;
extern int linenum_same_line;
extern int linenum_goto_totals;
extern int linenum_then_goto_totals;
extern int linenum_gosub_totals;
extern int linenum_on_totals;
extern int for_loops_total;
extern int for_loops_step_1;
extern int increments;
extern int decrements;
extern int compare_equals_zero;
extern int compare_equals_one;
extern int compare_equals_other;
extern int compare_not_equals_zero;
extern int compare_not_equals_one;
extern int compare_not_equals_other;
extern int assign_zero;
extern int assign_one;
extern int assign_other;

/* only one function here */
void print_statistics(void);

#endif /* statistics_h */
