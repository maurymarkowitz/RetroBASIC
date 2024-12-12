/* strng (implementation) for RetroBASIC
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

#include "strng.h"

/* makes a new string and copies in chars */
char* str_new(char *string)
{
  char *newstr = malloc((MAXSTRING + 1) * sizeof(char));
  
  if (newstr == NULL) {
    fprintf(stderr, "Malloc in str_new failed.");
    exit(EXIT_FAILURE);
  }

  if (strlen(string) > 0)
    strcpy(newstr, string);
  else
    newstr[0] = '\0';

  return newstr;
}

/* copies one string to another, replaces strndup */
char* str_copy(const char *string, size_t no_of_chars)
{
  size_t len = 0;
  while (len < no_of_chars && string[len])
    len++;

  char *new_str = malloc(len + 1);
  if (new_str) {
    memcpy(new_str, string, len);
    new_str[len] = 0;
  }

  return new_str;
}

/* escapes C-string sequences like \n */
char* str_escape(const char *string)
{
  const char *p;
  char *dest;
  char *q;

  if (!string)
    return NULL;

  p = (char *)string;
  /* Each source byte needs maximally four destination chars (\777) */
  q = dest = malloc(strlen(string) * 4 + 1);

  while (*p) {
    switch (*p)
    {
      case '\b':
        *q++ = '\\';
        *q++ = 'b';
        break;
      case '\f':
        *q++ = '\\';
        *q++ = 'f';
        break;
      case '\n':
        *q++ = '\\';
        *q++ = 'n';
        break;
      case '\r':
        *q++ = '\\';
        *q++ = 'r';
        break;
      case '\t':
        *q++ = '\\';
        *q++ = 't';
        break;
      case '\v':
        *q++ = '\\';
        *q++ = 'v';
        break;
      case '\\':
        *q++ = '\\';
        *q++ = '\\';
        break;
      case '"':
        *q++ = '\\';
        *q++ = '"';
        break;
      default:
        *q++ = *p;
        break;
    }
    p++;
  }
  *q = 0;
  return dest;
}

/* convert a string to lower case */
char* str_tolower(char *string)
{
  for(char *p=string; *p; p++)
    *p = tolower(*p);
  return string;
}

/* convert a string to upper case */
char* str_toupper(char* string)
{
  for(char *p=string; *p; p++)
    *p = toupper(*p);
  return string;
}

/* removes a number of characters from a string starting at a given position */
char* str_erase(char *string, size_t starting_pos, size_t no_of_chars)
{
  size_t len = strlen(string);
  
  size_t sp = starting_pos;
  if (sp >= len) sp = len;
  
  size_t ep = starting_pos + no_of_chars - 1;
  if (ep >= len) ep = len;
  
  size_t no = ep - sp + 1;

  memmove(string, string + sp, no); // doesn't copy the null!
  string[no] = '\0';

  return string;
}

/* remove a number of characters from the end of a string */
char* str_truncate(char *string, size_t no_of_chars)
{
  size_t len = strlen(string);
  
  size_t no = no_of_chars;
  if (no > len) no = 0;
  
  string[len - no] = '\0'; // cheater's method, no -1 in thie case

  return string;
}

/* remove a number of characters from the front of a string */
char* str_fruncate(char *string, size_t no_of_chars)
{
  size_t len = strlen(string);
  
  size_t no = no_of_chars;
  if (no > len) no = 0;

  memmove(string, string + no, len - no);
  string[len - no] = '\0';
  
  return string;
}

/* append one string to another */
char* str_append(char *orig_string, char *new_chars)
{
  // this exists only to match the API from GLib, which is used to return a string into str_new
  return strcat(orig_string, new_chars);
}

/* remove leading and trailing whitespace */
char* str_trim(char *orig_string)
{
  size_t len = strlen(orig_string);
  size_t p = 0, q = len - 1;

  while (isspace(orig_string[p]))
    p++;
  
  while (isspace(orig_string[q]))
    q--;
  
  size_t after_len = q + 1 - p;

  memmove(orig_string, orig_string + p, after_len);
  orig_string[after_len] = '\0';
  
  return orig_string;
}

/* remove leading and trailing quotes */
char* str_unquote(char *orig_string)
{
  size_t len = strlen(orig_string);
  size_t p = 0, q = len - 1;

  if (orig_string[p] == '"')
    p++;
  
  if (orig_string[q] == '"')
    q--;
  
  size_t after_len = q + 1 - p;

  memmove(orig_string, orig_string + p, after_len);
  orig_string[after_len] = '\0';
  
  return orig_string;
}
