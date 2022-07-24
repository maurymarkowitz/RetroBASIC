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

#ifndef data_h
#define data_h

#include "stdhdr.h"
#include <stdlib.h>

// this should be more than large enough for programs of the era,
// but some like Atari will use large strings for data storage
#define MAXSTRING 256

/**
 * @file data.h
 * @author Maury Markowitz
 * @date 17 July 2022
 * @brief Various utilities for string and list handling
 *
 */

/**
 * @brief mallocs a new string and copies the optional @p string into it.
 *
 * @param string The string to to copy from, or NULL.
 */
char* str_new(char *string);

/**
 * @brief Deletes characters from a string starting at @p starting_pos and running for @p no_of_chars.
 *
 * @param string The string to delete from.
 * @param starting_pos Starting location to delete from.
 * @param no_of_chars Number of characters to delete.
 *
 * @note If starting_pos > strlen(string) nothing is deleted.
 */
char* str_erase(char *string, size_t starting_pos, size_t no_of_chars);

/**
 * @brief Deletes @p no_of_chars characters at the end a string.
 *
 * @param string The string to delete from.
 * @param no_of_chars How many to delete.
 *
 * @note If starting_pos > strlen(string) nothing is deleted.
 */
char* str_truncate(char *string, size_t no_of_chars);

/**
 * @brief Deletes @p no_of_chars characters at the front of a string.
 *
 * @param string The string to delete from.
 * @param no_of_chars How many to delete.
 *
 * @note If starting_pos > strlen(string) nothing is deleted.
 */
char* str_fruncate(char *string, size_t no_of_chars);

/**
 * @brief Appends @p new_chars to the end of @p orig_string and returns resulting @p orig_string.
 *
 * @param orig_string The string to append onto.
 * @param new_chars The characters to append.
 */
char* str_append(char *orig_string, char *new_chars);

#endif /* data_h */
