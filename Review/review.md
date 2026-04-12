# RetroBASIC Code Review

## Prompt (this is the only human-authored section of the document)

I fired up Claude and set the the underlying model to be Opus
from the default of Sonnet. I set the effort level to "high".Then I gave Claude code the following prompt.  I gave it no other information.

> please review the source code for the BASIC language interpreter here in
>   /Users/jeff/go/src/github.com/maurymarkowitz/RetroBASIC. This is is an "old
>   school" C program, so we are particularly concerned about pointer and memory issues.
>   Be sure to review every source file, and when you have completed your review write the review to review.md.
  
Here is Claude's review:

## Summary

RetroBASIC is a well-structured BASIC interpreter with a clean lex/yacc frontend and a recursive tree-walking evaluator. The codebase is organized logically and the code is generally readable with good commenting. However, the review uncovered approximately 20 issues across the severity spectrum, including several **critical correctness bugs** (double-printing of numbers, swapped loop indices in matrix fill, wrong operator in matrix subtraction, hardcoded filename in file creation, inverted logic in file deletion), **pointer/memory concerns** (NULL dereference paths, missing bounds checks, buffer overflows), and a number of warning-level reliability issues. **Request changes** — the critical bugs below will produce wrong output or corrupt data in normal usage.

---

## Critical Issues

### 1. `retrobasic.c` ~line 2255-2257: Numbers printed twice in `print_value()`

```c
char* a = number_to_string(v.number);
interpreter_state.cursor_column += fprintf(out, "%s", a);
        interpreter_state.cursor_column += fprintf(out, "%s ", a); // note the trailing space
```

Both `fprintf` calls execute, printing every number twice. The first line (without trailing space) appears to be an earlier version that was not removed. **Delete line 2256** (the one without the trailing space).

### 2. `matrix.c` line 254-255: Swapped row/column loop indices in `matrix_fill_str()`

```c
for (int r = 1; r <= cols; r++) {
    for (int c = 1; c <= rows; c++) {
```

The outer loop iterates `r` up to `cols` and the inner loop iterates `c` up to `rows`. This is backwards — `r` should iterate up to `rows` and `c` up to `cols`. The slot calculation on line 256 (`r * (cols + 1) + c`) assumes the standard row-major layout, so with the loops swapped, out-of-bounds writes will occur whenever `rows != cols`.

**Fix:** swap `cols`/`rows` in the loop bounds to `r <= rows` and `c <= cols`.

### 3. `matrix.c` line 498: Addition instead of subtraction in `matrix_sub()` 1D case

```c
destination_store->array[c].number = one_store->array[c].number + two_store->array[c].number;
```

This is inside `matrix_sub()` but uses `+` instead of `-`. The 2D case on line 507 correctly uses `-`. **Change `+` to `-`.**

### 4. `io.c` line 345: `create_file()` ignores the `file` parameter

```c
FILE* fp = fopen("textFile.txt" ,"a");
```

The `file` parameter passed to `create_file()` is never used. This always creates `textFile.txt` regardless of what the BASIC program requests. **Replace `"textFile.txt"` with `file`.**

### 5. `io.c` line 369: `delete_file()` has inverted existence check

```c
if (access(file, F_OK) == 0) {
    handle_error(ern_FILE_NOT_FOUND, "Attempt to delete file failed because the file doesn't exist");
    return false;
}
```

`access(file, F_OK) == 0` means the file **exists**. The error message says "file doesn't exist" but fires when the file is found. The check should be `!= 0`:

```c
if (access(file, F_OK) != 0) {
```

### 6. `retrobasic.c` line 1251: Wrong field assigned in numeric variable fallback

```c
else {
    if (p)
        result.number = p->number;
    else
        result.string = 0;  // should be result.number = 0
}
```

In the `else` branch (numeric type), the fallback assigns to `result.string` instead of `result.number`. This corrupts the value_t union — a numeric result gets its string pointer zeroed instead of its number set to zero. **Change to `result.number = 0;`.**

### 7. `list.c` line 334: `lst_insert_at_index()` corrupts list linkage

```c
new_node->prev = tmp_node->prev;
new_node->prev->next = new_node;
new_node->next = tmp_node;
new_node->prev = new_node;   // BUG: should be tmp_node->prev = new_node
```

The last line sets `new_node->prev` to point to itself, overwriting the correct value just set two lines earlier, and fails to update `tmp_node->prev`. This creates a self-referencing node and a broken backward link. **Change to `tmp_node->prev = new_node;`.**

### 8. `retrobasic.c` line 725: Pointer cast to int for string DIM bounds checking

```c
int dim_len = POINTER_TO_INT(storage->value->string);
```

`storage->value->string` is a `char*`. `POINTER_TO_INT` casts the pointer address itself to an integer, not the string length. This will produce garbage values for the bounds check. This should likely be `(int)strlen(storage->value->string)`.

### 9. `retrobasic.c` line 5127: `bit[2]` buffer not null-terminated before `atoi()`

In the TIME_STR handler:
```c
char bit[2];
memcpy(bit, &hms.string[0], 2);
h = atoi(bit);
```

`bit` is 2 bytes but `atoi()` requires a null-terminated string. Since `bit` has no null terminator, `atoi()` will read past the buffer. **Change `bit[2]` to `bit[3]` and add `bit[2] = '\0';` after each `memcpy`.**

---

## Warning Issues

### 10. `strng.c` line 33: `str_new()` dereferences potentially NULL parameter

```c
char* str_new(char *string)
{
    char *newstr = malloc((MAX_STRING_LEN + 1) * sizeof(char));
    ...
    if (strlen(string) > 0)
```

The doc says `string` can be NULL, but `strlen(NULL)` is undefined behavior. Add a NULL check before calling `strlen`.

### 11. `strng.c` `str_erase()`: Implementation doesn't match documentation

The documentation says "deletes characters from a string starting at `starting_pos` and running for `no_of_chars`." The implementation actually *keeps* characters from `starting_pos` for `no_of_chars` and discards the rest — it's doing extraction, not erasure. Either the doc or the implementation needs to be corrected depending on how callers use it.

### 12. `strng.c` `str_append()`: Unbounded `strcat()`

```c
return strcat(orig_string, new_chars);
```

No bounds checking. If `orig_string` was allocated with `str_new()` (MAX_STRING_LEN + 1 bytes), appending can overflow. Consider checking that `strlen(orig_string) + strlen(new_chars) <= MAX_STRING_LEN`.

### 13. `list.c` lines 403-407: `lst_copy()` appends node structs as data

```c
new_list->data = list->data;           // head gets first item's data

while (list->next != NULL) {
    new_node = _lst_alloc();
    new_node->data = list->data;       // first iteration: same data as head
    new_node->key = list->key;
    lst_append(new_list, new_node);    // appends the node struct itself as data!
    list = list->next;
}
```

Two problems: (a) The first loop iteration copies the same element as the head, producing a duplicate. The `list = list->next` should happen before the copy, not after. (b) `lst_append(new_list, new_node)` passes the `list_t*` node as the data pointer, when it should be appending `new_node->data`. The function should either directly set up `->next`/`->prev` pointers, or call `lst_append(new_list, list->data)` and handle keys separately.

### 14. `retrobasic.c` lines 993-995: `number_to_bin_string()` undefined behavior and only covers 6 bits

```c
unsigned u = *(unsigned *)&i;
for (int bit = 32; bit > 0; bit >>= 1)
    strcat(str, ((u & bit) == bit) ? "1" : "0");
```

- Type punning via pointer cast is undefined behavior in C. Use `memcpy` or a union.
- The loop starts at 32 and shifts right, visiting bits 32, 16, 8, 4, 2, 1 — only 6 bits. For a 32-bit integer, `bit` should start at `(1u << 31)` and shift right, or the loop should be rewritten entirely.
- Uses `strcat` on a static buffer in a loop — O(n^2) and fragile.

### 15. `io.c` `open_file()`: Missing bounds check on channel number

The function uses `channel` to index into `file_handle_map[256]` and `file_name_map[256]` without verifying `0 <= channel < 256`. A BASIC program passing a large or negative channel number would cause an out-of-bounds array access.

### 16. `retrobasic.c` ~line 639: Known memory leak in string slicing

The code allocates memory for string slice results in `variable_value()` that is never freed. A comment acknowledges this. In programs that heavily use string slicing (e.g., `MID$`, `LEFT$`), this will leak continuously. Consider a small arena or free-list for slice temporaries.

### 17. `statistics.c` lines 180-181: `is_single` and `is_double` accumulate into wrong counter

```c
lst_foreach(interpreter_state.variable_values, is_single, &num_int);
lst_foreach(interpreter_state.variable_values, is_double, &num_int);
```

Both callbacks increment `num_int` instead of `num_sng` and `num_dbl` respectively. Fix:
```c
lst_foreach(interpreter_state.variable_values, is_single, &num_sng);
lst_foreach(interpreter_state.variable_values, is_double, &num_dbl);
```

### 18. `retrobasic.c` line 4878: Inverted `strcmp` logic in RANDOMIZE TIMER

```c
if (strcmp(str_toupper(seed_value.string), "TIMER")) {
    srand((unsigned int)time(NULL));
} else {
    handle_error(ern_TYPE_MISMATCH, ...);
}
```

`strcmp` returns 0 (falsy) on match. So when the string IS "TIMER", the `if` branch is false and the error fires. When it's NOT "TIMER", the `if` branch is true and it seeds with time. The condition should be `strcmp(...) == 0` or `!strcmp(...)`.

### 19. `retrobasic.c` POP handler (~line 4692): Passes list node instead of data to remove

```c
stack_node = lst_last_node(interpreter_state.runtime_stack);
if (stack_node != NULL) {
    lst_remove_node_with_data(interpreter_state.runtime_stack, stack_node);
}
```

`lst_remove_node_with_data` expects a `void *data` pointer to match against `node->data`, but here it receives `stack_node` (a `list_t*`). It should be `stack_node->data`. As-is, POP will fail to find and remove the entry.

### 20. `retrobasic.c` line 4842: PUT_FILE evaluates `generic_parameter` twice

```c
// First evaluation to get channel:
int channel = floor(evaluate_expression(statement->parms.generic.generic_parameter).number);
fp = handle_for_channel(channel);
...
// Second evaluation to get value:
value_t v = evaluate_expression(statement->parms.generic.generic_parameter);
```

For `PUT_FILE`, both the channel and value are read from `generic_parameter`. The channel is consumed first, then the same expression is evaluated again for the value. This means the value is always the channel number, not a separate data expression. If PUT_FILE is supposed to output a value distinct from the channel, a different parameter field is needed.

### 21. `retrobasic.c` line 5073: STOP prints message.string without type check

```c
value_t message = evaluate_expression(statement->parms.generic.generic_parameter);
printf("STOP: %s\n", message.string);
```

If the parameter evaluates to a NUMBER, `message.string` is uninitialized/garbage, which will crash or print garbage. Add a type check.

---

## Nits

- **`strng.c` line 159**: Comment says "no -1 in thie case" — typo "thie" → "this".
- **`format.c`**: Contains many `fprintf(stderr, "DEBUG: ...")` statements throughout. These should be removed or wrapped in `#ifdef DEBUG` before any release.
- **`retrobasic.c`**: Mixed indentation (tabs vs spaces) throughout `perform_statement()`, particularly visible in the NEXT handler (lines 4520-4533) and PRINT handler. Consider normalizing.
- **`retrobasic.c` line 4939**: `evaluate_expression` called twice for the same RESTORE parameter — once for the type check and once for the value. Cache the first result.
- **`strng.c` `str_escape()`**: The malloc size `strlen(string) * 4 + 1` accounts for octal escapes like `\777` but the switch only emits 2-character escapes. `* 2 + 1` would suffice and waste less memory, though this is harmless.
- **`main.c`**: Uses `abort()` in a default switch case for option parsing. `exit(EXIT_FAILURE)` would be more graceful.
- **`list.c` `lst_copy()`**: Also doesn't copy the last element (the `while` loop exits when `list->next == NULL`, skipping the tail).

---

## Questions

1. **`str_erase()` semantics**: Is the intent to *delete* characters from the middle of a string (shifting the remainder left), or to *extract* a substring? The current implementation extracts, but the name and documentation describe deletion. Callers should be checked to determine which is correct.

2. **`retrobasic.c` line 725 (`POINTER_TO_INT` on string)**: Is this meant to be checking a DIMmed length stored somewhere other than the string pointer? Some BASIC implementations store the DIM length in metadata. If so, where is this metadata stored, and how should it be accessed?

3. **PUT_FILE double evaluation (issue #20)**: Is `generic_parameter` supposed to hold both the channel and the value? If PUT_FILE needs a separate value expression, which struct field should it use (e.g., `generic_parameter2`)?

4. **Memory ownership model**: Several functions (e.g., `str_new`, `str_escape`, `str_copy`) allocate and return new memory, while others (e.g., `str_tolower`, `str_erase`, `str_trim`) modify in-place. The ownership convention is not always clear to callers — for example, `evaluate_expression` sometimes returns stack-allocated strings and sometimes heap-allocated ones. Is there a planned strategy for string lifetime management, or is the acknowledged leak in string slicing considered acceptable for the target use case (short-lived BASIC programs)?
