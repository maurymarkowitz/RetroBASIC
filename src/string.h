/* string (header) for RetroBASIC
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

#ifndef string_h
#define string_h

#include "stdhdr.h"
#include <stdlib.h>

// this should be more than large enough for programs of the era,
// but some like Atari will use large strings for data storage
#define MAXSTRING 256

/**
 * @file string.h
 * @author Maury Markowitz
 * @date 17 July 2022
 * @brief Various utilities for string handling
 *
 * The types and functions in this library are intended to closely mirror the API of the
 * GLib library. gnbasic was written using GLib to avoid having to implement common
 * functionality and recreating the wheel. However, installing GLib on anything other
 * than generic *nix platforms turned out to be more annoying that simply writing
 * the code to perform these relatively simple tasks.
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
 * @return The resulting string.
 *
 * @note If starting_pos > strlen(string) nothing is deleted.
 */
char* str_erase(char *string, size_t starting_pos, size_t no_of_chars);

/**
 * @brief Deletes @p no_of_chars characters at the end a string.
 *
 * @param string The string to delete from.
 * @param no_of_chars How many to delete.
 * @return The resulting string.
 *
 * @note If starting_pos > strlen(string) nothing is deleted.
 */
char* str_truncate(char *string, size_t no_of_chars);

/**
 * @brief Deletes @p no_of_chars characters at the front of a string.
 *
 * @param string The string to delete from.
 * @param no_of_chars How many to delete.
 * @return The resulting string.
 *
 * @note If starting_pos > strlen(string) nothing is deleted.
 */
char* str_fruncate(char *string, size_t no_of_chars);

/**
 * @brief Appends @p new_chars to the end of @p orig_string and returns resulting @p orig_string.
 *
 * @param orig_string The string to append onto.
 * @param new_chars The characters to append.
 * @return The resulting string.
 */
char* str_append(char *orig_string, char *new_chars);

/**
 * Simple double-linked list consisting of a series of "nodes".
 *
 */
struct list_t {
  void *data;
  struct list *prev;
  struct list *next;
};
typedef struct list_t list;

/**
 * @brief Prepends @p data to the front of @p list and returns resulting @p list.
 *
 * @param list The list to add onto.
 * @param data A pointer to a user-malloced data to be inserted.
 */
list* lst_prepend(list *list, void *data);

/**
 * @brief Appends @p data to the end of @p list and returns resulting @p list.
 *
 * @param list The list to add onto.
 * @param data A pointer to a user-malloced data to be inserted.
 */
list* lst_append(list *list, void *data);

/**
 * @brief Removes @p data from @p list and returns resulting @p list.
 *
 * @param list The list to remove from.
 * @param data A pointer to user data to be removed.
 */
list* lst_remove(list *list, void *data);

/**
 * @brief Copies items in @p list to a new list.
 *
 * @param list The list to copy.
 * @return The resulting new list.
 *
 * lst_copy makes a shallow copy of the original list, creating new nodes
 * but not duplicating the original user data. This means that freeing objects
 * from either list will cause the other to contain invalid pointers. It is up to the
 * user to manage the malloc/free of the underlying data.
 */
list* lst_copy(list *list);

/**
 * @brief Adds the items in @p other_list to the end of @p list.
 *
 * @param list The list to copy.
 * @param other_list The list to copy items from.
 * @return The resulting lengthened @p list.
 *
 */
list* lst_concat(list *list, struct list *other_list);

/**
 * @brief Returns the number of items in @p list.
 *
 * @param list The list to count.
 * @return The length of the list.
 */
int lst_length(list *list);

/**
 * @brief Returns a pointer to the next item in @p list.
 *
 * @param list The list to traverse.
 * @return Pointer to the next node.
 */
list* lst_next(list *list);

/**
 * @brief Returns a pointer to the previous item in @p list.
 *
 * @param list The list to traverse.
 */
list* lst_previous(list *list);

/**
 * @brief Returns a pointer to the first item in @p list.
 *
 * @param list The list to search.
 */
list* lst_first(list *list);

/**
 * @brief Returns a pointer to the last item in @p list.
 *
 * @param list The list to search.
 * @return The last node in the list.
 */
list* lst_last(list *list);

/**
 * @brief Returns a pointer to the nth item in @p list.
 *
 * @param list The list to search.
 * @param index The index number of the item to return.
 * @return The selected item.
 */
void* lst_nth_item(list *list, int index);

/**
 * @brief Returns the index of @p data in @p list.
 *
 * @param list The list to search.
 * @param data The item to search for.
 * @return The index of the item or NULL if it is not found.
 */
int lst_position(list *list, void *data);

#endif /* string_h */
