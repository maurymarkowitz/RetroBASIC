10 DIM A(5,5)
20 A(3,3)=10
30 PRINT"tight-printing 5x5 matrix containing one non-zero entry in 3,3"
40 MAT PRINT A;
50 PRINT"wide-printing 5x5 containing one non-zero entry in 3,3"
60 MAT PRINT A
100 DIM B(3,3)
110 PRINT"input a 3x3"
120 MAT INPUT B
130 PRINT"printing input"
140 MAT PRINT B
200 DIM C(2,5)
210 PRINT"reading 2x5"
220 MAT READ C
230 PRINT"printing 2x5"
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
1000 DATA 1,2,3,4,5,6,7,8,9,10
9999 END
