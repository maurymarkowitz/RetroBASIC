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
 * inserting and deleting items from the list, counting the number of items (length),
 * and so forth.
 *
 * The list consists of a linked series of "nodes", which are also the basic struct of
 * the list itself. Lists and the nodes are synonymous. A minimal valid list consists
 * of a single node. The empty list is NULL, not a single empty node.
 *
 * The list normally contains data via a void* pointer which the user has to allocate
 * as appropriate. They may also be used to store integers by casting them to void*.
 *
 * When traversing the list, the functions below will always check to see if the passed
 * node is at the start (or end) of the list and rewind to the front (or forward to the
 * end) as needed. This means all of these functions can be called by passing in any
 * valid node. In practice, however, code calling these functions would generally keep
 * a handle to the start of the list. This is eased by accepting the returned value from
 * the functions, which is normally the start of the resulting list. For instance, if
 * you call lst_remove_key and the item to be removed is at the front of the list,
 * the function will return the second item, as it is now the front after removal.
 *
 * The types and functions in this library are intended to closely mirror the API of the
 * GLib library. gnbasic was written using GLib to avoid recreating the wheel for common
 * functionality. However, installing GLib on anything other than generic *nix platforms
 * turned out to be more annoying that writing the code to perform these relatively
 * simple tasks. Over time, the API began to diverge to make certain calls more obvious.
 * A good example is lst_first_node, formerly lst_first, as it is not clear in the API
 * that this returned a node, as opposed to the data, and it was possible to cast the
 * returned value to a void* without warning.
 *
 * gnbasic also used GTree to store sorted lists, notably for variable values. This is
 * instead implemented here as a list through the addition of the (optional) char* "key"
 * field and using lst_insert_sorted. The resulting list can then be used in a hash-like
 * fashion to find named items, or simply as a sorted list, ignoring the keys. More
 * complex keys and/or sorting based on the data itself is not currently supported.
 *
 */

#ifndef lst_h
#define lst_h

#include "stdint.h"
#include "stdhdr.h"

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
 * Returns the previous node.
 *
 * @param list a node in the list to traverse.
 * @return the previous node.
*/
#define lst_previous(list)      ((list) ? (((list_t *)(list))->prev) : NULL)

/** Returns the next node.
 *
 * @param list a node in the list to traverse.
 * @return the next node.
*/
#define lst_next(list)          ((list) ? (((list_t *)(list))->next) : NULL)

/** Stores an (int) in the data field in place of a pointer.
 *
 * @param value the int value to store in a node.
 */
#define INT_TO_POINTER(value)     ((void*)(intptr_t)(value))

/** Retrieves an (int) from the data field.
 *
 * @param data the data field of a node.
 */
#define POINTER_TO_INT(data)   ((int)(intptr_t)(data))

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
 * from either list will cause the other to contain invalid pointers. It is up
 * to the user to manage the malloc/free of the underlying data.
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
 * Returns the first node.
 *
 * @param list the list to search
 * @return the first item in the list or NULL if it was empty
 */
list_t* lst_first_node(list_t *list);

/**
 * Returns the last node.
 *
 * @param list the list to search
 * @return the last item in the list or NULL if it was empty
 */
list_t* lst_last_node(list_t *list);

/**
 * Returns the list node for a given @p data item (pointer).
 *
 * @param list the list to search
 * @param data the pointer to the data to find
 * @return the node for the item, or NULL if it was empty or not found
 */
list_t* lst_node_with_data(list_t *list, void* data);

/**
 * Returns the node at a given @p index.
 *
 * @param list the list to search
 * @param index the number of the item to return
 * @return the node at the given index, or NULL if it was empty or past the end
 */
list_t* lst_node_at(list_t *list, int index);

/**
 * Returns the data for the node at a given @p index.
 *
 * @param list the list to search
 * @param index the number of the item to return
 * @return the node at the given index, or NULL if it was empty or past the end
 */
void* lst_data_at(list_t *list, int index);

/**
 * Returns the node with the given @p key.
 *
 * @param list the list to search
 * @param key the number of the item to return
 * @return the node with a given key, or NULL if it was empty or not found
 */
list_t* lst_node_with_key(list_t *list, const char *key);

/**
 * Returns the data for the node with the given @p key.
 *
 * @param list the list to search
 * @param key the number of the item to return
 * @return the node with a given key, or NULL if it was empty or not found
 */
void* lst_data_with_key(list_t *list, const char *key);

/**
 * @brief Returns the index of @p node in @p list.
 *
 * @param list The list to search.
 * @param node The list node to search for.
 * @return The index of the item or NULL if it is not found.
 */
int lst_index_of_node(list_t *list, list_t *node);

/**
 * @brief Returns the index of the node holding @p data in @p list.
 *
 * @param list The list to search.
 * @param data The item to search for.
 * @return The index of the item or NULL if it is not found.
 */
int lst_index_of_data(list_t *list, void *data);

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
 * @p index zero means "front of list" while any negative value inserts
 * at the end. An empty list will always be inserted at the start regardless
 * of the value.
 *
 * @param list the list to insert into
 * @param data pointer to the object to store in the list or NULL if it failed
 * @param index the location to insert at
 * @return pointer to @p data if it was inserted, NULL otherwise
 */
list_t* lst_insert_at_index(list_t *list, void *data, int index);

/**
 * Inserts a value at the correct sorted location given a string key.
 *
 * @param list the list to insert into
 * @param key a string to use to position the object in the list
 * @param data pointer to the object to store in the list or NULL if it failed
 * @return pointer to @p data if it was inserted, NULL otherwise
 */
list_t* lst_insert_with_key_sorted(list_t *list, void *data, char *key);

/**
 * @brief Removes @p data from @p list and returns resulting @p list.
 *
 * @param list The list to remove from.
 * @param data A pointer to user data to be removed.
 * @return A pointer to user data.
 */
list_t* lst_remove_node_with_data(list_t *list, void *data);

/**
 * Removes and frees the node at the given index. The user data is returned and *not* freed.
 *
 * @param list the list to insert into
 * @param index the location to insert at
 * @return the resulting list
 */
void* lst_remove_node_at_index(list_t *list, int index);

/**
 * Removes and frees the node with the given key. The user data is returned and *not* freed.
 *
 * @param list the list to insert into
 * @param key the key to search for
 * @return the resulting list
 */
void* lst_remove_node_with_key(list_t *list, char *key);

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
