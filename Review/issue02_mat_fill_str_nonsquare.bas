1 REM Issue #2: Swapped row/column loop indices in matrix_fill_str()
2 REM Fill a non-square 2x3 string matrix with "X"
3 REM Expected: all 6 cells contain "X"
4 REM Bug: r iterates to cols, c iterates to rows, so S$(1,3) and S$(2,3) are empty
5 REM
10 DIM S$(2,3)
20 MAT S$=("X")
30 E=0
40 FOR R=1 TO 2
50 FOR C=1 TO 3
60 IF S$(R,C)<>"X" THEN PRINT "FAIL: S$(";R;",";C;") is '";S$(R,C);"' not 'X'":E=E+1
70 NEXT C
80 NEXT R
90 IF E=0 THEN PRINT "PASS: all 6 cells filled"
95 IF E>0 THEN PRINT "FAIL:";E;" cells were not filled"
99 END
