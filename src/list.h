/* list (header) for RetroBASIC
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

/**
 * @file list.h
 * @author Maury Markowitz
 * @date 17 July 2022
 * @brief A simple linked-List implementation and various work methods
 *
 * The types and functions in this library are intended to closely mirror the API of the
 * GLib library. gnbasic was written using GLib to avoid having to implement common
 * functionality and recreating the wheel. However, installing GLib on anything other
 * than generic *nix platforms turned out to be more annoying that simply writing
 * the code to perform these relatively simple tasks.
 */

#ifndef list_h
#define list_h

#include <stdlib.h>

/**
 * List structure
 */
typedef struct _list {
  void *data;
  void *key;
  struct _list *next;
  struct _list *prev;
} list_t;

// maybe macro these?
//#define lst_previous(list)      ((list) ? (((list_t *)(list))->prev) : NULL)
//#define lst_next(list)          ((list) ? (((list_t *)(list))->next) : NULL)

/**
 * Creates an empty List. Returns NULL if the allocation failed.
 */
list_t *lst_alloc(void);

/**
 * Removes all nodes from a list. It is up to the user to free the items within.
 */
void lst_free(list_t *List);

/**
 * Removes all nodes from a list and the user data within. Needs to be used
 * with caution, if the lists have been copied, reversed or concated, bad
 * things will happen.
 */
void lst_free_everything(list_t *list);

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
list_t* lst_copy(list_t *list);

/**
 * Concatenates two lists.
 *
 * @param first_list the list to insert into
 * @param second_list the list to add to the end of the first
 * @return resulting longer @p first_list
 */
list_t* lst_concat(list_t *first_list, list_t *second_list);

/**
 * @brief Returns the number of items in @p list.
 *
 * @param list The list to count.
 * @return The length of the list.
 */
int lst_length(list_t *list);

/**
 * Returns the next node.
 *
 * @param list the list to search
 */
list_t* lst_next(list_t *list);

/**
 * Returns the previous node.
 *
 * @param list the list to search
 */
list_t* lst_previous(list_t *list);

/**
 * Returns the first node.
 *
 * @param list the list to search
 * @return the first item in the list or NULL if it was empty
 */
list_t* lst_first(list_t *list);

/**
 * Returns the last node.
 *
 * @param list the list to search
 * @return the last item in the list or NULL if it was empty
 */
list_t* lst_last(list_t *list);

/**
 * Returns the list node for a given data item (pointer).
 *
 * @param list the list to search
 * @param data the pointer to the data to find
 * @return the node for the item, or NULL if it was empty or not found
 */
list_t* lst_item(list_t *list, void* data);

/**
 * Returns the data at a given index.
 *
 * @param list the list to search
 * @param index the number of the item to return
 * @return the node at the given index, or NULL if it was empty or past the end
 */
list_t* lst_item_at(list_t *list, int index);

/**
 * @brief Returns the index of @p data in @p list.
 *
 * @param list The list to search.
 * @param data The item to search for.
 * @return The index of the item or NULL if it is not found.
 */
int lst_position(list_t *list, void *data);

/**
 * Appends a value to the end of the List.
 *
 * @param list the list to append onto
 * @param data pointer to the object to store in the list
 * @return @p data if it was inserted, NULL otherwise
 */
list_t* lst_append(list_t *list, void *data);

/**
 * Prepends a value at the front of the List.
 *
 * @param list the list to prepend onto
 * @param data pointer to the object to store in the list
 * @return @p data if it was inserted, NULL otherwise
 */
list_t* lst_prepend(list_t *list, void *data);

/**
 * Inserts a value at a given index location in a List.
 *
 * @param list the list to insert into
 * @param index the location to insert at
 * @param data pointer to the object to store in the list or NULL if it failed
 * @return pointer to @p data if it was inserted, NULL otherwise
 */
list_t* lst_insert_after(list_t *list, int index, void *data);

/**
 * @brief Removes @p data from @p list and returns resulting @p list.
 *
 * @param list The list to remove from.
 * @param data A pointer to user data to be removed.
 */
void* lst_remove(list_t *list, void *data);

/**
 * Removes and frees the node at the given index. The user data is returned and *not* freed.
 *
 * @param List the list to insert into
 * @param index the location to insert at
 * @return pointer to @p data if it was removed, NULL otherwise
 */
void* lst_remove_at(list_t *List, int index);

/**
 * Adds the value to the front of the list (alias for prepend).
 *
 * @param list the list to insert into
 * @param data the data to push
 * @return pointer to @p data if it was pushed, NULL otherwise
*/
list_t* lst_push(list_t *list, void *data);

/**
 * Removes and frees the first node in the List, returning the associated data.
 */
void* lst_pop(list_t *list);

#endif /* list_h */
