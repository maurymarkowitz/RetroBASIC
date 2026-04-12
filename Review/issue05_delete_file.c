/*
 * Issue #5: delete_file() has inverted existence check
 *
 * access(file, F_OK) == 0 means the file EXISTS, but the code treats it
 * as "not found" and errors out. So deleting an existing file always fails.
 *
 * Build: gcc -o issue05_delete_file issue05_delete_file.c
 *
 * Expected: PASS
 * Bug: FAIL - errors when file exists, attempts remove() when it doesn't
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Replicate the buggy logic from io.c line 369 */
static int delete_file_under_test(const char *file)
{
    /* BUG: == 0 means file EXISTS, but code says "doesn't exist" */
    if (access(file, F_OK) == 0) {
        fprintf(stderr, "  [bug triggered] 'file doesn't exist' error fired when file DOES exist\n");
        return 0; /* simulates handle_error + return false */
    }

    if (remove(file) != 0) {
        fprintf(stderr, "  [bug triggered] remove() called on non-existent file\n");
        return 0;
    }

    return 1;
}

int main(void)
{
    const char *testfile = "issue05_test.tmp";
    int result;

    /* Create a file to delete */
    FILE *fp = fopen(testfile, "w");
    if (fp == NULL) {
        printf("FAIL: could not create test file\n");
        return 1;
    }
    fprintf(fp, "test\n");
    fclose(fp);

    /* Verify it exists */
    if (access(testfile, F_OK) != 0) {
        printf("FAIL: test file was not created\n");
        return 1;
    }

    /* Try to delete it using the buggy function */
    if (delete_file_under_test(testfile)) {
        printf("PASS: delete_file successfully deleted existing file\n");
        result = 0;
    } else {
        printf("FAIL: delete_file could not delete an existing file (inverted check)\n");
        result = 1;
    }

    /* Clean up just in case */
    unlink(testfile);

    return result;
}
