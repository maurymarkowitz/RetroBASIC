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
int string_constants_one_byte = 0;
int string_constants_two_byte = 0;
int string_constants_four_byte = 0;
int string_constants_eight_byte = 0;
int string_constants_sixteen_byte = 0;
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

static gboolean is_string(gpointer key, gpointer value, gpointer user_data)
{
  variable_storage_t *data = (variable_storage_t *)value;
  int *tot = (int*)user_data;
  if(data->type == STRING) *tot += 1;
  return FALSE;
}
static gboolean is_single(gpointer key, gpointer value, gpointer user_data)
{
  variable_storage_t *data = (variable_storage_t *)value;
  int *tot = (int*)user_data;
  if(data->type == SINGLE) *tot += 1;
  return FALSE;
}
static gboolean is_double(gpointer key, gpointer value, gpointer user_data)
{
  variable_storage_t *data = (variable_storage_t *)value;
  int *tot = (int*)user_data;
  if(data->type == DOUBLE) *tot += 1;
  return FALSE;
}
static gboolean is_integer(gpointer key, gpointer value, gpointer user_data)
{
  variable_storage_t *data = (variable_storage_t *)value;
  int *tot = (int*)user_data;
  if(data->type == INTEGER) *tot += 1;
  return FALSE;
}

/* prints out various statistics from the static code,
 or if the write_stats flag is on, writes them to a file */
void print_statistics()
{
  int lines_total, line_min, line_max;
  
  // start with line number stats
  lines_total = 0;
  line_max = MAXLINE + 1;
  line_min = -1;
  // just look for any entry with a list
  for(int i = 0; i < MAXLINE; i++) {
    if (interpreter_state.lines[i] != NULL) {
      lines_total++;
      if (i < line_max) line_max = i;
      if (i > line_min) line_min = i;
    }
  }
  
  // exit if there's no program
  if (lines_total == 0) {
    printf("\nNO PROGRAM TO EXAMINE\n\n");
    return;
  }
  
  // since the statements are run together as one long list, it's
  // easy to print out the total number, but not so easy to print
  // out the number per line. so this code checks each node to see
  // if the ->next is the first item on the next line
  int stmts_max = 0, diff = 0, next_num;
  list_t *this, *next;
  list_t *start = interpreter_state.lines[interpreter_state.first_line];
  
  for(int i = interpreter_state.first_line; i < MAXLINE - 1; i++) {
    // try again if this line is empty
    if(interpreter_state.lines[i] == NULL) continue;
    
    // otherwise get the statements on this line
    this = interpreter_state.lines[i];
    
    // and find the next non-empty line
    next_num = i + 1; // note to me: no, you can't i++ here!
    while ((next_num < MAXLINE) && (interpreter_state.lines[next_num] == NULL))
      next_num++;
    
    // if we ran off the end of the list, exit
    if(next_num == MAXLINE - 1) break;
    
    // otherwise we found the next line
    next = interpreter_state.lines[next_num];
    
    // now count the number of statements between them
    diff = lst_position(start, next) - lst_position(start, this);
    if(diff > stmts_max) stmts_max = diff;
  }
  
  // variables
  int num_total = g_tree_nnodes(interpreter_state.variable_values);
  int num_int = 0, num_sng = 0, num_dbl = 0, num_str = 0;
  g_tree_foreach(interpreter_state.variable_values, is_integer, &num_int);
  g_tree_foreach(interpreter_state.variable_values, is_single, &num_sng);
  g_tree_foreach(interpreter_state.variable_values, is_double, &num_dbl);
  g_tree_foreach(interpreter_state.variable_values, is_single, &num_sng);
  g_tree_foreach(interpreter_state.variable_values, is_string, &num_str);
  
  // output to screen if selected
  if (print_stats == TRUE) {
    printf("\nRUN TIME: %g\n", (double)(end_time.tv_usec - start_time.tv_usec) / 1000000 + (double)(end_time.tv_sec - start_time.tv_sec));
    printf("CPU TIME: %g\n", ((double) (end_ticks - start_ticks)) / CLOCKS_PER_SEC);
    
    printf("\nLINE NUMBERS\n\n");
    printf("  total: %i\n", lines_total);
    printf("  first: %i\n", line_max);
    printf("   last: %i\n", line_min);
    
    printf("\nSTATEMENTS\n\n");
    printf("  total: %i\n", lst_length(interpreter_state.lines[line_max]));
    printf("average: %2.2f\n", (double)lst_length(interpreter_state.lines[line_max])/(double)lines_total);
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
    printf(" 1 char: %i\n",string_constants_one_byte);
    printf("2 chars: %i\n",string_constants_two_byte);
    printf("4 chars: %i\n",string_constants_four_byte);
    printf("8 chars: %i\n",string_constants_eight_byte);
    printf("16 char: %i\n",string_constants_sixteen_byte);
    printf(" bigger: %i\n",string_constants_big);
    printf("biggest: %i\n",string_constants_max);
    
    printf("\nBRANCHES\n\n");
    printf("  total: %i\n",linenum_constants_total);
    printf(" gosubs: %i\n",linenum_gosub_totals);
    printf("  gotos: %i\n",linenum_goto_totals);
    printf("  thens: %i\n",linenum_then_goto_totals);
    printf("    ons: %i\n",linenum_on_totals);
    printf("forward: %i\n",linenum_forwards);
    printf("bckward: %i\n",linenum_backwards);
    printf("same ln: %i\n",linenum_same_line);
    
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
  if (write_stats == TRUE) {
    //check that the file name is reasonable, and then try to open it
    FILE* fp = fopen(stats_file, "w+");
    if(!fp) return;
    
    double tu = (double)(end_time.tv_usec - start_time.tv_usec);
    double ts = (double)(end_time.tv_sec - start_time.tv_sec);
    fprintf(fp, "RUN TIME: %g\n", tu / 1000000 + ts);
    fprintf(fp, "CPU TIME,%g\n", ((double) (end_ticks - start_ticks)) / CLOCKS_PER_SEC);
    
    fprintf(fp, "LINE NUMBERS,total,%i\n", lines_total);
    fprintf(fp, "LINE NUMBERS,first,%i\n", line_max);
    fprintf(fp, "LINE NUMBERS,last,%i\n", line_min);
    
    fprintf(fp, "STATEMENTS,total,%i\n", lst_length(interpreter_state.lines[line_max]));
    fprintf(fp, "STATEMENTS,average,%g\n", (double)lst_length(interpreter_state.lines[line_max])/(double)lines_total);
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
    fprintf(fp, "STRING CONSTANTS,1 char,%i\n",string_constants_one_byte);
    fprintf(fp, "STRING CONSTANTS,2 chars,%i\n",string_constants_two_byte);
    fprintf(fp, "STRING CONSTANTS,4 chars,%i\n",string_constants_four_byte);
    fprintf(fp, "STRING CONSTANTS,8 chars,%i\n",string_constants_eight_byte);
    fprintf(fp, "STRING CONSTANTS,16 chars,%i\n",string_constants_sixteen_byte);
    fprintf(fp, "STRING CONSTANTS,bigger,%i\n",string_constants_big);
    fprintf(fp, "STRING CONSTANTS,biggest,%i\n",string_constants_max);
    
    fprintf(fp, "BRANCHES,total,%i\n",linenum_constants_total);
    fprintf(fp, "BRANCHES,gosubs,%i\n",linenum_gosub_totals);
    fprintf(fp, "BRANCHES,gotos,%i\n",linenum_goto_totals);
    fprintf(fp, "BRANCHES,thens,%i\n",linenum_then_goto_totals);
    fprintf(fp, "BRANCHES,ons,%i\n",linenum_on_totals);
    fprintf(fp, "BRANCHES,forward,%i\n",linenum_forwards);
    fprintf(fp, "BRANCHES,backward,%i\n",linenum_backwards);
    fprintf(fp, "BRANCHES,same line,%i\n",linenum_same_line);
    
    fprintf(fp, "OTHER,ASSIGN 0: %i\n",assign_zero);
    fprintf(fp, "OTHER,ASSIGN 1: %i\n",assign_one);
    fprintf(fp, "OTHER,ASSIGN OTHER: %i\n",assign_other);
    fprintf(fp, "OTHER,FORs step 1: %i\n",for_loops_step_1);
    fprintf(fp, "OTHER,FORs: %i\n",for_loops_total);
    fprintf(fp, "OTHER,FORs step 1: %i\n",for_loops_step_1);
    fprintf(fp, "OTHER,incs: %i\n",increments);
    fprintf(fp, "OTHER,decs: %i\n",decrements);
    fprintf(fp, "OTHER,logical=0: %i\n",compare_equals_zero);
    fprintf(fp, "OTHER,logical!=0: %i\n",compare_not_equals_zero);
    fprintf(fp, "OTHER,logical=1: %i\n",compare_equals_one);
    fprintf(fp, "OTHER,logical!=1: %i\n",compare_not_equals_one);
    fprintf(fp, "OTHER,logical=x: %i\n",compare_equals_other);
    fprintf(fp, "OTHER,logical!=x: %i\n",compare_not_equals_other);
    
    fclose(fp);
  }
}

