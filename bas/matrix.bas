5 A=5:REM make sure A is not the same as A()
10 DIM A(5,5)
15 PRINT A
20 A(3,3)=10
30 PRINT"tight-printing 5x5 matrix containing one non-zero entry in 3,3"
40 MAT PRINT A;
50 PRINT"wide-printing 5x5 containing one non-zero entry in 3,3"
60 MAT PRINT A
70 PRINT"printing a 1-D array"
80 DIM Z(3)
90 MAT PRINT Z
95 PRINT"printing a (0,3) array"
96 DIM Y(0,3)
97 MAT PRINT Y
100 DIM B(3,3)
110 PRINT"input a 3x3"
120 MAT INPUT B
130 PRINT"printing input"
140 MAT PRINT B
200 DIM C(2,5)
210 PRINT"READing and PRINTing 2x5"
220 MAT READ C
240 MAT PRINT C
300 PRINT"IDNing 3x3"
310 MAT B=IDN
320 MAT PRINT B
400 print"ZERing 3x3"
410 MAT B=ZER
420 MAT PRINT B
500 PRINT"CONing 3x3"
510 MAT B=CON
520 MAT PRINT B
600 PRINT"CONing a (1x)6"
610 DIM E(6)
620 MAT E=CON
630 MAT PRINT E
700 PRINT "DIM(6,6), IDN(3,3)"
710 DIM D(6,6)
720 MAT D=IDN(3,3)
730 MAT PRINT D
800 PRINT "Copy that to E"
810 DIM F(10,10)
820 MAT F=D
830 MAT PRINT F
1000 DATA 1,2,3,4,5,6,7,8,9,10
9999 END
