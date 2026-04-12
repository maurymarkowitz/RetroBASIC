1 REM Issue #18: Inverted strcmp logic in RANDOMIZE TIMER
2 REM RANDOMIZE TIMER should seed the RNG with time - no error
3 REM Bug: strcmp returns 0 on match (falsy), so when string IS "TIMER"
4 REM the if-branch is false and the error fires instead
5 REM Expected: prints a random number without error
6 REM Bug: TYPE MISMATCH error
10 RANDOMIZE TIMER
20 PRINT "RND after RANDOMIZE TIMER: ";RND(1)
30 PRINT "PASS: no error"
99 END
