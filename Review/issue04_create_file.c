/*
 * Issue #4: create_file() ignores the `file` parameter
 *
 * create_file() always opens "textFile.txt" instead of the name passed in.
 * This test calls create_file() with a specific name and checks that the
 * correct file is created (not textFile.txt).
 *
 * Build: gcc -I../src -o issue04_create_file issue04_create_file.c ../src/io.c ../src/list.c ../src/strng.c ../src/errors.c -lm
 * (may need adjustments depending on io.c dependencies)
 *
 * Expected: PASS
 * Bug: FAIL - creates textFile.txt instead of the requested file
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Minimal stub of what create_file needs. We replicate the buggy function
   directly here to avoid pulling in the full interpreter. */

static int create_file_under_test(const char *file)
{
    /* This is the buggy code from io.c line 345 */
    FILE* fp = fopen("textFile.txt", "a");  /* BUG: should be fopen(file, "a") */
    if (fp == NULL)
        return 0;
    fclose(fp);
    return 1;
}

int main(void)
{
    const char *requested = "issue04_requested_file.tmp";
    const char *hardcoded = "textFile.txt";
    int result = 0;

    /* Clean up any leftovers */
    unlink(requested);
    unlink(hardcoded);

    /* Call the function with our specific filename */
    create_file_under_test(requested);

    /* Check: did the requested file get created? */
    int requested_exists = (access(requested, F_OK) == 0);
    int hardcoded_exists = (access(hardcoded, F_OK) == 0);

    if (requested_exists && !hardcoded_exists) {
        printf("PASS: create_file created the requested file '%s'\n", requested);
        result = 0;
    } else if (hardcoded_exists) {
        printf("FAIL: create_file created '%s' instead of '%s'\n", hardcoded, requested);
        result = 1;
    } else {
        printf("FAIL: no file was created at all\n");
        result = 1;
    }

    /* Clean up */
    unlink(requested);
    unlink(hardcoded);

    return result;
}
