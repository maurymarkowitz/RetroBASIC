/* Data (header) for RetroBASIC
   Copyright (C) 2020 Maury Markowitz
      
   Based on gnbasic
   Copyright (C) 1998 James Bowman
    
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

#include "data.h"

/* STRINGS */

// TODO: make this global, it's also in retrobasic.h right now
#define MAXSTRING 255

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

void str_delete(char *string, size_t starting_pos, size_t no_of_chars)
{
  if((starting_pos + no_of_chars - 1 ) <= strlen(string)) {
    strcpy(&string[starting_pos-1], &string[starting_pos + no_of_chars - 1]);
  }
}

void str_truncate(char *string, size_t no_of_chars)
{
  size_t len = strlen(string);
  if (no_of_chars <= len) {
    string[len - no_of_chars] = '\0'; // cheater's method
  }
}

void str_fruncate(char *string, size_t no_of_chars)
{
  size_t len = strlen(string);
  if (no_of_chars <= len) {
    memmove(string, string + no_of_chars, len);
  }
}

char* str_append(char *orig_string, char *new_chars)
{
  // this exists only to match the API from GLib, which returns the string
  strcat(orig_string, new_chars);
  return orig_string;
}

/* STRINGS */
