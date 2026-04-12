1 REM Issue #17: is_single and is_double accumulate into num_int instead of num_sng/num_dbl
2 REM Run with: retrobasic -p issue17_stats_counters.bas
3 REM Expected: statistics should show non-zero single/double counts
4 REM Bug: single and double counts are zero, integer count is inflated
5 REM
6 REM Declare variables of different types to populate the counters
10 DEFINT I
20 DEFSNG S
30 DEFDBL D
40 I=1
50 S=1.5
60 D=3.14159265358979
70 PRINT "Check -p output: int=1, sng=1, dbl=1"
99 END
