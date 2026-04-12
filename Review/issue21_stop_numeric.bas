1 REM Issue #21: STOP prints message.string without type check
2 REM STOP with a numeric argument should not crash
3 REM Bug: if parameter is NUMBER, message.string is uninitialized/garbage
4 REM Expected: prints something like "STOP: 42" or "STOPped at line: 10"
5 REM Bug: crash or garbage output from dereferencing bad pointer
10 STOP 42
99 END
