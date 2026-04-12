# Plan: Test Suite for Code Review Issues

Tests in the `Review/` directory, named to match review issue numbers. Each test is designed to fail until the corresponding bug is fixed.

## Tests writable in BASIC

| Issue | File | What it tests |
|-------|------|---------------|
| **#1** | `issue01_print_double.bas` | `PRINT 42` — output should contain `42` exactly once, not twice. Currently prints `4242`. |
| **#2** | `issue02_mat_fill_str_nonsquare.bas` | `MAT S$=("X")` on a non-square (2x3) string matrix — should fill all 6 cells. Currently swaps row/col bounds causing out-of-bounds or wrong fill. |
| **#3** | `issue03_mat_sub_1d.bas` | `MAT C=A-B` on 1D arrays — result should be differences. Currently adds instead. |
| **#6** | `issue06_numeric_var_fallback.bas` | Access an unset numeric variable — should return 0. Currently corrupts the value_t union. |
| **#9** | `issue09_time_str_set.bas` | `TIME$="120000"` then read back — should parse correctly. Currently buffer overrun with `atoi` on non-null-terminated `bit[2]`. |
| **#14** | `issue14_bin_conversion.bas` | `BIN$(255)` — should produce `11111111` (8 bits). Currently only produces 6 bits. |
| **#17** | `issue17_stats_counters.bas` | Run with `-p` flag — single/double counts should be reported (not all lumped into integer count). |
| **#18** | `issue18_randomize_timer.bas` | `RANDOMIZE TIMER` — should seed the RNG without error. Currently fires type-mismatch error. |
| **#21** | `issue21_stop_numeric.bas` | `STOP 42` (numeric arg) — should not crash. Currently dereferences garbage string pointer. |

## Tests requiring C (internal APIs not directly exercisable from BASIC)

| Issue | File | What it tests |
|-------|------|---------------|
| **#4** | `issue04_create_file.c` | Calls `create_file()` with a specific name, checks the correct file is created (not `textFile.txt`). |
| **#5** | `issue05_delete_file.c` | Calls `delete_file()` on an existing file, checks it succeeds. Currently fails due to inverted existence check. |
| **#7** | `issue07_list_insert.c` | Calls `lst_insert_at_index()` and verifies list linkage integrity. |
| **#8** | `issue08_pointer_to_int.c` | Demonstrates that `POINTER_TO_INT(string)` produces garbage vs `strlen()`. |
| **#13** | `issue13_list_copy.c` | Calls `lst_copy()` and verifies all elements are copied correctly. |
| **#19** | `issue19_pop.c` | Pushes to runtime stack, calls POP, verifies the entry is actually removed. |

## Issues skipped (not feasible to test in isolation)

- **#10** (`str_new(NULL)`) — would crash the process; verifying UB is not meaningful in a test.
- **#11** (`str_erase` semantics) — ambiguous per the review; needs clarification first.
- **#12** (`str_append` overflow) — would require a 256+ char string; hard to trigger from BASIC.
- **#15** (channel bounds) — negative channel from BASIC may not parse.
- **#16** (memory leak) — not testable as a pass/fail.
- **#20** (`PUT_FILE` double eval) — architecture issue, not a simple test.

## Test validation approach

Each BASIC test will `PRINT` a known-good expected value and the actual computed value on the same line, making it easy to diff expected vs actual output. A wrapper comment at the top explains what the expected output is and what the bug produces.

The C tests compile standalone against the RetroBASIC source files they need, print PASS/FAIL, and return 0 on pass, 1 on fail.
