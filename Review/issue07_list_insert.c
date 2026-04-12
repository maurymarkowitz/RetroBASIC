/*
 * Issue #7: lst_insert_at_index() corrupts list linkage
 *
 * The last line of the insertion sets new_node->prev = new_node (self-ref)
 * instead of tmp_node->prev = new_node. This breaks the backward link.
 *
 * Build: gcc -I../src -o issue07_list_insert issue07_list_insert.c ../src/list.c ../src/strng.c -lm
 *
 * Expected: PASS - all forward and backward links are correct
 * Bug: FAIL - backward traversal from insertion point is broken
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdhdr.h"
#include "list.h"

int main(void)
{
    /* Build a list: A -> C */
    list_t *list = NULL;
    list = lst_append(list, "A");
    list = lst_append(list, "C");

    /* Insert B at index 1 (between A and C) -> should be A -> B -> C */
    list = lst_insert_at_index(list, "B", 1);

    int failed = 0;

    /* Check forward traversal */
    list_t *node = lst_first_node(list);
    if (node == NULL || strcmp((char*)node->data, "A") != 0) {
        printf("FAIL: first node is not A\n");
        failed = 1;
    }

    node = node->next;
    if (node == NULL || strcmp((char*)node->data, "B") != 0) {
        printf("FAIL: second node is not B\n");
        failed = 1;
    }

    node = node->next;
    if (node == NULL || strcmp((char*)node->data, "C") != 0) {
        printf("FAIL: third node is not C\n");
        failed = 1;
    }

    /* Check backward traversal from C */
    node = lst_last_node(list);
    if (node == NULL || strcmp((char*)node->data, "C") != 0) {
        printf("FAIL: last node is not C\n");
        failed = 1;
    }

    node = node->prev;
    if (node == NULL || strcmp((char*)node->data, "B") != 0) {
        printf("FAIL: C->prev is not B (backward link broken)\n");
        failed = 1;
    }

    /* Check that B->prev points to A, not to B itself */
    if (node->prev == node) {
        printf("FAIL: B->prev points to itself (self-referencing node)\n");
        failed = 1;
    }

    node = node->prev;
    if (node == NULL || strcmp((char*)node->data, "A") != 0) {
        printf("FAIL: B->prev is not A\n");
        failed = 1;
    }

    if (!failed)
        printf("PASS: all forward and backward links correct after insert_at_index\n");

    lst_free(list);
    return failed ? 1 : 0;
}
