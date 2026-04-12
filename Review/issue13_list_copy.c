/*
 * Issue #13: lst_copy() has two bugs:
 *   (a) First loop iteration copies same element as head (duplicate)
 *   (b) lst_append passes node struct as data instead of node->data
 *   Also skips the last element (while exits when list->next == NULL)
 *
 * Build: gcc -I../src -o issue13_list_copy issue13_list_copy.c ../src/list.c ../src/strng.c -lm
 *
 * Expected: PASS - copy contains A, B, C in order
 * Bug: FAIL - copy has wrong elements and/or wrong count
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdhdr.h"
#include "list.h"

int main(void)
{
    /* Build original list: A -> B -> C */
    list_t *orig = NULL;
    orig = lst_append(orig, "A");
    orig = lst_append(orig, "B");
    orig = lst_append(orig, "C");

    int orig_len = lst_length(orig);
    printf("Original list length: %d\n", orig_len);

    /* Copy it */
    list_t *copy = lst_copy(orig);
    int copy_len = lst_length(copy);
    printf("Copied list length: %d\n", copy_len);

    int failed = 0;

    /* Check length matches */
    if (copy_len != orig_len) {
        printf("FAIL: copy length %d != original length %d\n", copy_len, orig_len);
        failed = 1;
    }

    /* Check each element's data pointer matches the original */
    list_t *o = lst_first_node(orig);
    list_t *c = lst_first_node(copy);
    int index = 0;

    while (o != NULL) {
        if (c == NULL) {
            printf("FAIL: copy ended early at index %d\n", index);
            failed = 1;
            break;
        }

        /* Data pointers should be the same (shallow copy) */
        if (c->data != o->data) {
            printf("FAIL: at index %d, copy data=%p ('%s') != original data=%p ('%s')\n",
                   index,
                   c->data, c->data ? (char*)c->data : "NULL",
                   o->data, o->data ? (char*)o->data : "NULL");
            failed = 1;
        } else {
            printf("  index %d: '%s' OK\n", index, (char*)c->data);
        }

        o = o->next;
        c = c->next;
        index++;
    }

    if (c != NULL) {
        printf("FAIL: copy has extra elements beyond original\n");
        failed = 1;
    }

    if (!failed)
        printf("PASS: lst_copy produced correct shallow copy\n");

    lst_free(orig);
    lst_free(copy);
    return failed ? 1 : 0;
}
