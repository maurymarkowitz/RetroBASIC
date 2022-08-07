/* list (header) for RetroBASIC
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

/**
 * @file List.h
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

#ifndef List_h
#define List_h

#include <stdlib.h>

/**
 * private type used within the List
 *
 */
//typedef struct _node {
//  void *val;
//  struct _node *next;
//} _node;

/**
 * List structure
 */
typedef struct List {
  //int length;
  void *data;
  struct List *next;
  struct List *prev;
} List;

/**
 * Creates an empty List. head is set to NULL and length to 0. Returns NULL if the allocation failed.
 */
List *lst_init(void);

/**
 * Private method to create a new node with the given user data.
 */
struct List* _lst_create_node(void *data, struct _node *next);


/**
 * Returns the next node.
 */
struct List* lst_next(List *list);

/**
 * Returns the previous node.
 */
struct List* lst_prev(List *list);

/**
 * Returns the node at the given index.
 */
struct List* lst_item_at(List *list, int index);

/**
 * Appends a value to the end of the List.
 *
 * @param list the list to append onto
 * @param value pointer to the object to store in the list
 */
void lst_append(List *list, void *data);

/**
 * Prepends a value at the front of the List.
 *
 * @param list the list to prepend onto
 * @param data pointer to the object to store in the list
 */
void lst_prepend(List *list, void *data);

/**
 * Inserts a value at a given index location in a List.
 *
 * @param List the list to insert into
 * @param index the location to insert at
 * @param data pointer to the object to store in the list
 */
void lst_insert_at(List *list, int index, void *data);

/**
 * Removes and frees the node at the given index. The user data is returned and not freed.
 */
void* lst_remove_at(List *List, int index);

/**
 * Removes all nodes from a list. It is up to the user to free the items within.
 */
void* lst_remove_all(List *List, int index);

/**
 * Removes and frees the first node in the List, returning the associated data.
 */
void* lst_pop(List *List);

/**
 * Adds the value to the front of the list (alias for prepend).
 */
void lst_push(List *List, void *value);

/**
 * Safe free of the List. Also frees the _nodes, but not the values.
 */
void lst_free(List *List);

#endif /* list_h */
