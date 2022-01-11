2 DEFINT X,Y
3 VARLIST
5 FOR I=1 TO 3
6 PRINT "loop with NEXT I"I
7 NEXT I,J
8 FOR I=1 TO 3
9 PRINT "loop with NEXT"I
10 NEXT
11 A=9999999999
12 PRINT "this should print 1E+10:"A
13 ' quote comment
14 ! bang comment
15 PRINT"this line has a trailing bang comment"!comment
16 PRINT"this line has a trailing quote comment"'comment
17 PRINT"this line has a trailing REM comment":REM comment
18 PRINT "input with a,b,c":INPUT A,B,C
20 DIM A(2,2)
30 A(1,1)=1:A(1,2)=2:A(2,1)=3:A(2,2)=4
40 PRINTA(1,1),A(1,2),A(2,1),A(2,2)
50 DEF FNA(X)=X
51 varlist
52 print "Calling function with const, should return 20: "FNA(20)
53 X=10
54 print "Calling function with var, should return 10: "FNA(X)
60 PRINT:PRINT:PRINT:PRINT"three blank lines above"
90 PRINT"HELLO WORLD"
100 PRINT "HELLO WORLD"
110 A$="HELLO WORLD"
120 PRINT A$, "len="len(a$)
130 PRINT "left 5 = "LEFT$(A$,5)
140 PRINT "right 5= "right$(A$,5)
150 PRINT "mid 5  = "mid$(A$,5)
160 PRINT "mid 4,5= "mid$(A$,4,5)
200 REM HELLO
230 B=10
240 PRINT "B",B,"B(1,1)",B(1,1)
250 print "hello"B
300 LET A=2
400 PRINT "A=2, A*10=";A*10
440 input "a prompt with comma",A
450 print a
470 input "a prompt with semi";B
480 print b
490 print "a is"a
500 ON A GOTO 600,700,800
600 PRINT "A WAS 1":END
700 PRINT "A WAS 2":END
800 PRINT "A WAS 3":END
850 goto 90
900 END
