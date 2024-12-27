/* strng (header) for RetroBASIC
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

#ifndef str_h
#define str_h

#include "stdhdr.h"

/**
 * @file strng.h
 * @author Maury Markowitz
 * @date 8 August 2022
 * @brief Various utilities for strings based on GLib's gstring.
 *
 * The types and functions in this library are intended to closely mirror the API of the
 * GLib GString library. gnbasic was written using GLib to avoid recreating the wheel for
 * common functionality. Unfortunately, using GLib on anything other than bog-standard
 * Unix is annoying.
 *
 * It also includes a replacement for strndup, which is POSIX and not available in windows.
 *
 */

// this should be more than large enough for programs of the era,
// but some like Atari will use large strings for data storage
#define MAX_STRING_LEN 256

/**
 * callocs a new string and copies the optional @p string into it.
 *
 * @param string The string to to copy from, or NULL.
 */
char* str_new(char *string);

/**
 * mallocs a new string and copies in the contents of @p string, up to @p no_of_chars.
 * Replaces strndup, as this is only available in POSIX and thus doesn't exist
 * on Windows.
 *
 * @param string The string to copy.
 * @param no_of_chars Number of characters to copy.
 * @return The copied string.
 */
char* str_copy(const char *string, size_t no_of_chars);

/**
 * @brief Escapes out C bits like \n.
 *
 * @param string The string to clean.
 * @return The cleaned string.
 */
char* str_escape(const char *string);

/**
 * Converts a string to lower-case.
 *
 * @param string The string to convert.
 * @return The converted string.
 */
char* str_tolower(char *string);

/**
 * Converts a string to upper-case.
 *
 * @param string The string to convert.
 * @return The converted string.
 */
char* str_toupper(char *string);

/**
 * Deletes characters from a string starting at @p starting_pos and running for @p no_of_chars.
 *
 * @param string The string to delete from.
 * @param starting_pos Starting location to delete from.
 * @param no_of_chars Number of characters to delete.
 * @return The resulting string.
 *
 * @note If starting_pos > strlen(string) nothing is deleted.
 */
char* str_erase(char *string, size_t starting_pos, size_t no_of_chars);

/**
 * Deletes @p no_of_chars characters at the end a string.
 *
 * @param string The string to delete from.
 * @param no_of_chars How many to delete.
 * @return The resulting string.
 *
 * @note If @p starting_pos > strlen(string) nothing is deleted.
 */
char* str_truncate(char *string, size_t no_of_chars);

/**
 * Deletes @p no_of_chars characters at the front of a string.
 *
 * @param string The string to delete from.
 * @param no_of_chars How many to delete.
 * @return The resulting string.
 *
 * @note If @p no_of_chars > strlen(string) nothing is deleted.
 */
char* str_fruncate(char *string, size_t no_of_chars);

/**
 * Appends @p new_string to the end of @p orig_string and returns resulting @p orig_string.
 *
 * @param orig_string The string to append onto.
 * @param new_string The string to append.
 * @return The resulting string.
 */
char* str_append(char *orig_string, char *new_string);

/**
 * Deletes any leading or trailing whitespace from @p orig_string.
 *
 * @param orig_string The string to trim.
 * @return The resulting string.
 */
char* str_trim(char *orig_string);

/**
 * Deletes leading or trailing double-quotes from @p orig_string.
 *
 * @param orig_string The string to trim.
 * @return The resulting string.
 */
char* str_unquote(char *orig_string);

#endif /* string_h */
