1 REM Issue #6: Numeric variable fallback assigns to result.string instead of result.number
2 REM Access an uninitialized numeric variable - should return 0
3 REM Bug: result.string=0 instead of result.number=0, corrupting the value_t union
4 REM Expected: Q is 0, and Q+1 is 1
5 REM Bug: Q may be garbage or cause incorrect arithmetic
10 PRINT "Q expect 0: ";Q
20 PRINT "Q+1 expect 1: ";Q+1
30 LET R=Q+5
40 PRINT "R expect 5: ";R
99 END
