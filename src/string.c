/* string (implementation) for RetroBASIC
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

#include "string.h"

char* str_new(char *string)
{
  char *newstr = malloc((MAXSTRING + 1) * sizeof(char));
  
  if (newstr == NULL) {
    fprintf(stderr, "Malloc in str_new failed.");
    exit(EXIT_FAILURE);
  }

  if(strlen(string) > 0)
    strcpy(newstr, string);
  else
    newstr[0] = '\0';

  return newstr;
}

char* str_erase(char *string, size_t starting_pos, size_t no_of_chars)
{
  size_t len = strlen(string);
  
  size_t sp = starting_pos;
  if(sp >= len) sp = len;
  
  size_t ep = starting_pos + no_of_chars - 1;
  if(ep >= len) ep = len;
  
  size_t no = ep - sp + 1;

  memmove(string, string + sp, no); // doesn't copy the null!
  string[no] = '\0';

  return string;
}

char* str_truncate(char *string, size_t no_of_chars)
{
  size_t len = strlen(string);
  
  size_t no = no_of_chars;
  if(no > len) no = 0;
  
  string[len - no] = '\0'; // cheater's method, no -1 in thie case

  return string;
}

char* str_fruncate(char *string, size_t no_of_chars)
{
  size_t len = strlen(string);
  
  size_t no = no_of_chars;
  if(no > len) no = 0;

  memmove(string, string + no, len - no);
  string[len - no] = '\0';
  
  return string;
}

char* str_append(char *orig_string, char *new_chars)
{
  // this exists only to match the API from GLib, which is used to return a string into str_new
  return strcat(orig_string, new_chars);
}
