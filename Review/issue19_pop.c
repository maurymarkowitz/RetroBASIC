/*
 * Issue #19: POP passes list node instead of node->data to lst_remove_node_with_data
 *
 * The code does:
 *   stack_node = lst_last_node(runtime_stack);
 *   lst_remove_node_with_data(runtime_stack, stack_node);
 *
 * But lst_remove_node_with_data searches for a node whose ->data matches
 * the argument. Since stack_node is a list_t*, not user data, it won't
 * match any node's ->data, so nothing gets removed.
 *
 * Should be: lst_remove_node_with_data(runtime_stack, stack_node->data);
 *
 * Build: gcc -I../src -o issue19_pop issue19_pop.c ../src/list.c ../src/strng.c -lm
 *
 * Expected: PASS - last item is removed
 * Bug: FAIL - list length unchanged after "POP"
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdhdr.h"
#include "list.h"

int main(void)
{
    /* Simulate a runtime stack with 3 entries */
    list_t *stack = NULL;
    stack = lst_append(stack, "GOSUB_100");
    stack = lst_append(stack, "GOSUB_200");
    stack = lst_append(stack, "FOR_I");

    int before = lst_length(stack);
    printf("Stack length before POP: %d\n", before);

    /* Reproduce the buggy POP logic from retrobasic.c ~line 4691 */
    list_t *stack_node = lst_last_node(stack);
    if (stack_node != NULL) {
        /* BUG: passes stack_node (a list_t*) instead of stack_node->data */
        stack = lst_remove_node_with_data(stack, stack_node);
    }

    int after = lst_length(stack);
    printf("Stack length after POP: %d\n", after);

    int failed = 0;
    if (after != before - 1) {
        printf("FAIL: POP did not remove entry (length %d -> %d, expected %d)\n",
               before, after, before - 1);
        failed = 1;
    } else {
        printf("PASS: POP correctly removed last entry\n");
    }

    lst_free(stack);
    return failed ? 1 : 0;
}
