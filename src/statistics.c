/* Statistics for RetroBASIC
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

#include "statistics.h"

#include "parse.h"

#if _WIN32
#define _USE_MATH_DEFINES
#include "winsupport.h"
#else
#include <sys/time.h> // for run timers
#endif

/* declarations of the externs from the header */
int variables_total = 0;
int variables_default = 0;
int variables_int = 0;
int variables_float = 0;
int variables_double = 0;
int variables_string = 0;
int numeric_constants_total = 0;
int numeric_constants_float = 0;
int numeric_constants_zero = 0;
int numeric_constants_one = 0;
int numeric_constants_minus_one = 0;
int numeric_constants_one_digit = 0;
int numeric_constants_two_digit = 0;
int numeric_constants_three_digit = 0;
int numeric_constants_four_digit = 0;
int numeric_constants_five_digit = 0;
int numeric_constants_one_byte = 0;
int numeric_constants_two_byte = 0;
int numeric_constants_four_byte = 0;
int numeric_constants_big = 0;

int string_constants_total = 0;
int string_constants_zero = 0;
int string_constants_one_byte = 0;
int string_constants_big = 0;
int string_constants_max = 0;
int linenum_constants_total = 0;
int linenum_forwards = 0;
int linenum_backwards = 0;
int linenum_same_line = 0;
int linenum_goto_totals = 0;
int linenum_then_goto_totals = 0;
int linenum_gosub_totals = 0;
int linenum_on_totals = 0;
int for_loops_total = 0;
int for_loops_step_1 = 0;
int for_loops_all_constant = 0;
int increments = 0;
int decrements = 0;
int compare_equals_zero = 0;
int compare_equals_one = 0;
int compare_equals_other = 0;
int compare_not_equals_zero = 0;
int compare_not_equals_one = 0;
int compare_not_equals_other = 0;
int assign_zero = 0;
int assign_one = 0;
int assign_other = 0;

/* methods used while list walking */
static void is_string(void *key, void *value, void *user_data)
{
  variable_storage_t *data = (variable_storage_t *)value;
  int *tot = (int *)user_data;
  if (data->type == STRING) *tot += 1;
}
static void is_single(void *key, void *value, void *user_data)
{
  variable_storage_t *data = (variable_storage_t *)value;
  int *tot = (int* )user_data;
  if (data->type == SINGLE) *tot += 1;
}
static void is_double(void *key, void *value, void *user_data)
{
  variable_storage_t *data = (variable_storage_t *)value;
  int *tot = (int *)user_data;
  if (data->type == DOUBLE) *tot += 1;
}
static void is_integer(void *key, void *value, void *user_data)
{
  variable_storage_t *data = (variable_storage_t *)value;
  int *tot = (int *)user_data;
  if (data->type == INTEGER) *tot += 1;
}

/**
 * Prints out the statistics to the console if the global print_stats
 * is turned on, and to a file if write_stats is turned on.
 *
 */
void print_statistics(void)
{
  int lines_total = 0, line_min = MAX_LINE_NUMBER + 1, line_max = -1;
  double linenum_1_digit = 0.0, linenum_2_digit = 0.0, linenum_3_digit = 0.0, linenum_4_digit = 0.0, linenum_5_digit = 0.0;
  double linenum_tot_digits = 0.0;
  double linenum_ave_digits = 0;
  
  // start with line number stats
  // just look for any entry in the arra with a non-empty statement list
  for(int i = 0; i < MAX_LINE_NUMBER; i++) {
    if (interpreter_state.lines[i] != NULL) {
      lines_total++;
      if (i < line_min) line_min = i;
      if (i > line_max) line_max = i;
      
      if (i >= 0 && i <= 9) { linenum_1_digit++; linenum_tot_digits = linenum_tot_digits + 1; }
      else if (i >= 10 && i <= 99) { linenum_2_digit++; linenum_tot_digits = linenum_tot_digits + 2; }
      else if (i >= 100 && i <= 999) { linenum_3_digit++; linenum_tot_digits = linenum_tot_digits + 3; }
      else if (i >= 1000 && i <= 9999) { linenum_4_digit++; linenum_tot_digits = linenum_tot_digits + 4; }
      else if (i >= 10000 && i <= 99999) { linenum_5_digit++; linenum_tot_digits = linenum_tot_digits + 5; }
    }
  }
  
  // exit if there's no program
  if (lines_total == 0) {
    printf("\nNO PROGRAM TO EXAMINE\n\n");
    return;
  }
  
  // average number of digits in a line number
  linenum_ave_digits = (
                        (linenum_1_digit * 1) + (linenum_2_digit * 2) + (linenum_3_digit * 3) + (linenum_4_digit * 4) + (linenum_5_digit * 5)
                        ) / lines_total;

  
  // since the statements are run together as one long list, it's
  // easy to print out the total number, but not so easy to print
  // out the number per line. so this code checks each node to see
  // if the ->next is the first item on the next line
  int stmts_max = 0, diff = 0, next_num;
  list_t *next_line;
  list_t *start = interpreter_state.lines[interpreter_state.first_line];
  
  for (int i = interpreter_state.first_line; i < MAX_LINE_NUMBER - 1; i++) {
    // get the next line's statements, and continue if its empty
    list_t *this_line = interpreter_state.lines[i];
    if (interpreter_state.lines[i] == NULL)
      continue;
    
    // now find the next non-empty line
    next_num = i + 1; // note to me: no, you can't i++ here!
    while ((next_num < MAX_LINE_NUMBER) && (interpreter_state.lines[next_num] == NULL))
      next_num++;
    
    // if we ran off the end of the list, exit
    if (next_num > MAX_LINE_NUMBER - 1)
      break;
    
    // otherwise we found the next line
    next_line = interpreter_state.lines[next_num];
    
    // now count the number of statements between them
    diff = lst_index_of_node(start, next_line) - lst_index_of_node(start, this_line);
    if (diff > stmts_max)
      stmts_max = diff;
  }
  
  // variables
  int num_total = lst_length(interpreter_state.variable_values);
  
  int num_int = 0, num_sng = 0, num_dbl = 0, num_str = 0;
  lst_foreach(interpreter_state.variable_values, is_integer, &num_int);
  lst_foreach(interpreter_state.variable_values, is_single, &num_int);
  lst_foreach(interpreter_state.variable_values, is_double, &num_int);
  lst_foreach(interpreter_state.variable_values, is_string, &num_str);
  
  // output to screen if selected
  if (print_stats) {
    printf("\nRUN TIME: %g\n", (double)(end_time.tv_usec - start_time.tv_usec) / 1000000 + (double)(end_time.tv_sec - start_time.tv_sec));
    printf("CPU TIME: %g\n", ((double) (end_ticks - start_ticks)) / CLOCKS_PER_SEC);
    
    printf("\nLINE NUMBERS\n\n");
    printf("  total: %i\n", lines_total);
    printf("  first: %i\n", line_min);
    printf("   last: %i\n", line_max);
    printf(" digits: %2.2f\n", linenum_ave_digits);

    printf("\nSTATEMENTS\n\n");
    printf("  total: %i\n", lst_length(interpreter_state.lines[line_min]));
    printf("average: %2.2f\n", (double)lst_length(interpreter_state.lines[line_min])/(double)lines_total);
    printf("    max: %i\n", stmts_max);
    
    printf("\nVARIABLES\n\n");
    printf("  total: %i\n",num_total);
    printf(" string: %i\n",num_str);
    printf(" (nums): %i\n",num_total-num_str-num_int-num_sng-num_dbl);
    printf("   ints: %i\n",num_int);
    printf("singles: %i\n",num_sng);
    printf("doubles: %i\n",num_dbl);
    
    printf("\nNUMERIC CONSTANTS\n\n");
    printf("  total: %i\n",numeric_constants_total);
    printf("non-int: %i\n",numeric_constants_float);
    printf("    int: %i\n",numeric_constants_total - numeric_constants_float);
    printf("  zeros: %i\n",numeric_constants_zero);
    printf("   ones: %i\n",numeric_constants_one);
    printf("  -ones: %i\n",numeric_constants_minus_one);
    printf("1 digit: %i\n",numeric_constants_one_digit);
    printf("2 digit: %i\n",numeric_constants_two_digit);
    printf("3 digit: %i\n",numeric_constants_three_digit);
    printf("4 digit: %i\n",numeric_constants_four_digit);
    printf("5 digit: %i\n",numeric_constants_five_digit);
    printf(" bigger: %i\n",numeric_constants_big);
    printf(" 1 byte: %i\n",numeric_constants_one_byte);
    printf(" 2 byte: %i\n",numeric_constants_two_byte);
    printf(" 4 byte: %i\n",numeric_constants_four_byte);
    
    printf("\nSTRING CONSTANTS\n\n");
    printf("  total: %i\n",string_constants_total);
    printf("0 chars: %i\n",string_constants_zero);
    printf(" 1 char: %i\n",string_constants_one_byte);
    printf("biggest: %i\n",string_constants_max);
    
    printf("\nBRANCHES\n\n");
    printf("  total: %i\n",linenum_constants_total);
    printf(" gosubs: %i\n",linenum_gosub_totals);
    printf("  gotos: %i\n",linenum_goto_totals);
    printf("  thens: %i\n",linenum_then_goto_totals);
    printf("forward: %i\n",linenum_forwards);
    printf("bckward: %i\n",linenum_backwards);
    printf("same ln: %i\n",linenum_same_line);
    printf("    ons: %i\n",linenum_on_totals);

    printf("\nOTHER BITS\n\n");
    printf(" asgn 0: %i\n",assign_zero);
    printf(" asgn 1: %i\n",assign_one);
    printf(" asgn x: %i\n",assign_other);
    printf("   FORs: %i\n",for_loops_total);
    printf(" step 1: %i\n",for_loops_step_1);
    printf("   incs: %i\n",increments);
    printf("   decs: %i\n",decrements);
    
    printf("\nLOGICAL\n\n");
    printf("    = 0: %i\n",compare_equals_zero);
    printf("   != 0: %i\n",compare_not_equals_zero);
    printf("    = 1: %i\n",compare_equals_one);
    printf("   != 1: %i\n",compare_not_equals_one);
    printf("    = x: %i\n",compare_equals_other);
    printf("   != x: %i\n",compare_not_equals_other);
  }
  /* and/or the file if selected */
  if (write_stats) {
    //check that the file name is reasonable, and then try to open it
    FILE* fp = fopen(stats_file, "w+");
    if (!fp)
      return;
    
    double tu = (double)(end_time.tv_usec - start_time.tv_usec);
    double ts = (double)(end_time.tv_sec - start_time.tv_sec);
    fprintf(fp, "RUN TIME,%g\n", tu / 1000000 + ts);
    fprintf(fp, "CPU TIME,%g\n", ((double) (end_ticks - start_ticks)) / CLOCKS_PER_SEC);
    
    fprintf(fp, "LINE NUMBERS,total,%i\n", lines_total);
    fprintf(fp, "LINE NUMBERS,first,%i\n", line_min);
    fprintf(fp, "LINE NUMBERS,last,%i\n", line_max);
    fprintf(fp, "LINE NUMBERS,average digits,%2.2f\n", linenum_ave_digits);

    fprintf(fp, "STATEMENTS,total,%i\n", lst_length(interpreter_state.lines[line_min]));
    fprintf(fp, "STATEMENTS,average,%g\n", (double)lst_length(interpreter_state.lines[line_min])/(double)lines_total);
    fprintf(fp, "STATEMENTS,max/ln,%i\n", stmts_max);
    
    fprintf(fp, "VARIABLES,total,%i\n",num_total);
    fprintf(fp, "VARIABLES,string,%i\n",num_str);
    fprintf(fp, "VARIABLES,default,%i\n",num_total-num_str-num_int-num_sng-num_dbl);
    fprintf(fp, "VARIABLES,ints,%i\n",num_int);
    fprintf(fp, "VARIABLES,singles,%i\n",num_sng);
    fprintf(fp, "VARIABLES,doubles,%i\n",num_dbl);
    
    fprintf(fp, "NUMERIC CONSTANTS,total,%i\n",numeric_constants_total);
    fprintf(fp, "NUMERIC CONSTANTS,non-int,%i\n",numeric_constants_float);
    fprintf(fp, "NUMERIC CONSTANTS,int,%i\n",numeric_constants_total - numeric_constants_float);
    fprintf(fp, "NUMERIC CONSTANTS,zeros,%i\n",numeric_constants_zero);
    fprintf(fp, "NUMERIC CONSTANTS,ones,%i\n",numeric_constants_one);
    fprintf(fp, "NUMERIC CONSTANTS,-ones,%i\n",numeric_constants_minus_one);
    fprintf(fp, "NUMERIC CONSTANTS,1 digit,%i\n",numeric_constants_one_digit);
    fprintf(fp, "NUMERIC CONSTANTS,2 digit,%i\n",numeric_constants_two_digit);
    fprintf(fp, "NUMERIC CONSTANTS,3 digit,%i\n",numeric_constants_three_digit);
    fprintf(fp, "NUMERIC CONSTANTS,4 digit,%i\n",numeric_constants_four_digit);
    fprintf(fp, "NUMERIC CONSTANTS,5 digit,%i\n",numeric_constants_five_digit);
    fprintf(fp, "NUMERIC CONSTANTS,bigger,%i\n",numeric_constants_big);
    fprintf(fp, "NUMERIC CONSTANTS,1 byte,%i\n",numeric_constants_one_byte);
    fprintf(fp, "NUMERIC CONSTANTS,2 byte,%i\n",numeric_constants_two_byte);
    fprintf(fp, "NUMERIC CONSTANTS,4 byte,%i\n",numeric_constants_four_byte);
    
    fprintf(fp, "STRING CONSTANTS,total,%i\n",string_constants_total);
    fprintf(fp, "STRING CONSTANTS,0 chars,%i\n",string_constants_zero);
    fprintf(fp, "STRING CONSTANTS,1 char,%i\n",string_constants_one_byte);
    fprintf(fp, "STRING CONSTANTS,biggest,%i\n",string_constants_max);
    
    fprintf(fp, "BRANCHES,total,%i\n",linenum_constants_total);
    fprintf(fp, "BRANCHES,gosubs,%i\n",linenum_gosub_totals);
    fprintf(fp, "BRANCHES,gotos,%i\n",linenum_goto_totals);
    fprintf(fp, "BRANCHES,thens,%i\n",linenum_then_goto_totals);
    fprintf(fp, "BRANCHES,forward,%i\n",linenum_forwards);
    fprintf(fp, "BRANCHES,backward,%i\n",linenum_backwards);
    fprintf(fp, "BRANCHES,same line,%i\n",linenum_same_line);
    fprintf(fp, "BRANCHES,ons,%i\n",linenum_on_totals);

    fprintf(fp, "OTHER,assign 0,%i\n",assign_zero);
    fprintf(fp, "OTHER,assign 1,%i\n",assign_one);
    fprintf(fp, "OTHER,assign other,%i\n",assign_other);
    fprintf(fp, "OTHER,FORs,%i\n",for_loops_total);
    fprintf(fp, "OTHER,FORs step 1,%i\n",for_loops_step_1);
    fprintf(fp, "OTHER,incs,%i\n",increments);
    fprintf(fp, "OTHER,decs,%i\n",decrements);
    fprintf(fp, "OTHER,logical=0,%i\n",compare_equals_zero);
    fprintf(fp, "OTHER,logical!=0,%i\n",compare_not_equals_zero);
    fprintf(fp, "OTHER,logical=1,%i\n",compare_equals_one);
    fprintf(fp, "OTHER,logical!=1,%i\n",compare_not_equals_one);
    fprintf(fp, "OTHER,logical=x,%i\n",compare_equals_other);
    fprintf(fp, "OTHER,logical!=x,%i\n",compare_not_equals_other);
    
    fclose(fp);
  }
}

