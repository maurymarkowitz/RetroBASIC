/*
 * Issue #8: POINTER_TO_INT cast on string gives pointer address, not length
 *
 * retrobasic.c line 725 does:
 *   int dim_len = POINTER_TO_INT(storage->value->string);
 *
 * POINTER_TO_INT casts the char* address to int, producing garbage.
 * It should use strlen() instead.
 *
 * Build: gcc -I../src -o issue08_pointer_to_int issue08_pointer_to_int.c -lm
 *
 * Expected: PASS
 * Bug: FAIL - POINTER_TO_INT returns pointer address, not string length
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* Reproduce the macro from list.h */
#define POINTER_TO_INT(data) ((int)(intptr_t)(data))

int main(void)
{
    /* Simulate a string that is 10 characters long */
    char *test_string = "HELLOWORLD";  /* length 10 */
    int expected_len = 10;

    /* The buggy approach: cast pointer to int */
    int buggy_len = POINTER_TO_INT(test_string);

    /* The correct approach: use strlen */
    int correct_len = (int)strlen(test_string);

    printf("String: \"%s\"\n", test_string);
    printf("Expected length: %d\n", expected_len);
    printf("POINTER_TO_INT value: %d\n", buggy_len);
    printf("strlen value: %d\n", correct_len);

    if (buggy_len == expected_len) {
        printf("PASS: POINTER_TO_INT returned the correct length (coincidence on this platform)\n");
        return 0;
    } else {
        printf("FAIL: POINTER_TO_INT returned %d instead of %d (pointer address, not length)\n",
               buggy_len, expected_len);
        return 1;
    }
}
