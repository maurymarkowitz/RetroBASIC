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
 *
 * @title Doubly-linked lists
 * @brief A simple linked-list implementation and various work methods
 *
 * This code implements a doubly-linked list and various common functionality like
 * inserting and deleting items from the list, calculating the number of items (length),
 * and so forth. The empty list is NULL, with nothing allocated.
 *
 * The list normally contains data via a void* pointer which the user has to allocate
 * as appropriate. They may also be used to store integers by casting them to void*.
 * Lists and the nodes within them are synonomous, the methods below will always rewind
 * to the start or forward to the end as needed, so they can be called with any existing
 * node, you do not have to keep the first or last item. However, the API also generally
 * returns the front of the list after any modifications, making it easy to track the
 * front of the list as it changes with new items insterted or existing ones removed.
 *
 * The types and functions in this library are intended to closely mirror the API of the
 * GLib library. gnbasic was written using GLib to avoid recreating the wheel for common
 * functionality. However, installing GLib on anything other than generic *nix platforms
 * turned out to be more annoying that writing the code to perform these relatively
 * simple tasks.
 *
 * gnbasic also used GTree to store sorted lists, notably for variable values. This is
 * instead implemented here as a list through the addition of the (optional) char* "key"
 * field and using lst_insert_sorted. The resulting list can then be used in a hash-like
 * fashion to find named items, or simply as a sorted list, ignoring the keys. More
 * complex keys and/or sorting based on the data itself is not currently supported.
 *
 */

#ifndef list_h
#define list_h

#include <stdlib.h>

/**
 * List structure
 */
typedef struct _list {
  void *data;
  char *key;
  struct _list *next;
  struct _list *prev;
} list_t;

/**
 * Macros for next and previous.
 */
//#define lst_previous(list)      ((list) ? (((list_t *)(list))->prev) : NULL)
//#define lst_next(list)          ((list) ? (((list_t *)(list))->next) : NULL)

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
 * Returns the list node for a given @p data item (pointer).
 *
 * @param list the list to search
 * @param data the pointer to the data to find
 * @return the node for the item, or NULL if it was empty or not found
 */
list_t* lst_item(list_t *list, void* data);

/**
 * Returns the node at a given @p index.
 *
 * @param list the list to search
 * @param index the number of the item to return
 * @return the node at the given index, or NULL if it was empty or past the end
 */
list_t* lst_item_at(list_t *list, int index);

/**
 * Returns the node with the given @p key.
 *
 * @param list the list to search
 * @param key the number of the item to return
 * @return the node with a given key, or NULL if it was empty or not found
 */
list_t* lst_item_with_key(list_t *list, char *key);

/**
 * @brief Returns the index of @p data in @p list.
 *
 * @param list The list to search.
 * @param data The item to search for.
 * @return The index of the item or NULL if it is not found.
 */
int lst_position_of(list_t *list, void *data);

/**
 * Calls a user function on each value in the list.
 *
 * @param list the list to use
 * @param function a function pointer to call
 * @param result a pointer to any data the function might return
 * @return the original list
 */
list_t* lst_foreach(list_t *list, void (*function)(void *key, void *data, void *user_data), void *user_data);

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
 * @p position zero means "front of list" while any negative value inserts
 * at the end. An empty list will always be inserted at the start regardless
 * of the value.
 *
 * @param list the list to insert into
 * @param data pointer to the object to store in the list or NULL if it failed
 * @param position the location to insert at
 * @return pointer to @p data if it was inserted, NULL otherwise
 */
list_t* lst_insert_at(list_t *list, void *data, int position);

/**
 * Inserts a value at the correct sorted location given a string key.
 *
 * @param list the list to insert into
 * @param key a string to use to position the object in the list
 * @param data pointer to the object to store in the list or NULL if it failed
 * @return pointer to @p data if it was inserted, NULL otherwise
 */
list_t* lst_insert_sorted(list_t *list, void *data, char *key);

/**
 * @brief Removes @p data from @p list and returns resulting @p list.
 *
 * @param list The list to remove from.
 * @param data A pointer to user data to be removed.
 * @return A pointer to user data.
 */
list_t* lst_remove(list_t *list, void *data);

/**
 * Removes and frees the node at the given index. The user data is returned and *not* freed.
 *
 * @param list the list to insert into
 * @param position the location to insert at
 * @return the resulting list
 */
void* lst_remove_at(list_t *list, int position);

/**
 * Removes and frees the node with the given key. The user data is returned and *not* freed.
 *
 * @param list the list to insert into
 * @param position the location to insert at
 * @return the resulting list
 */
void* lst_remove_key(list_t *list, char *key);

/**
 * Adds the value to the front of the list (alias for prepend).
 *
 * @param list the list to insert into
 * @param data the data to push
 * @return pointer to @p data if it was pushed, NULL otherwise
*/
list_t* lst_push(list_t *list, void *data);

/**
 * Removes and frees the first node in the list, returning the associated data.
 */
void* lst_pop(list_t *list);

#endif /* list_h */
