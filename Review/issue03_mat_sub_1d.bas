1 REM Issue #3: matrix_sub() 1D case uses + instead of -
2 REM Expected: C(1)=7, C(2)=7, C(3)=7
3 REM Bug: C(1)=13, C(2)=15, C(3)=17 (addition instead of subtraction)
10 DIM A(3),B(3),C(3)
20 A(1)=10:A(2)=11:A(3)=12
30 B(1)=3:B(2)=4:B(3)=5
40 MAT C=A-B
50 PRINT "C(1) expect 7: ";C(1)
60 PRINT "C(2) expect 7: ";C(2)
70 PRINT "C(3) expect 7: ";C(3)
99 END
