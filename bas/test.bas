1 REMARK
5 DEF FNA(X)=1
6 PRINT:PRINT:PRINT:PRINT
9 PRINT"HELLO WORLD"
10 PRINT "HELLO WORLD"
11 A$="HELLO WORLD"
12 PRINT A$, "len="len(a$)
13 PRINT "left 5 = "LEFT$(A$,5)
14 PRINT "right 5= "right$(A$,5)
15 PRINT "mid 5  = "mid$(A$,5)
16 PRINT "mid 4,5= "mid$(A$,4,5)
20 REM HELLO
23 B=10
24 PRINT "B",B,"B(1,1)",B(1,1)
25 print "hello"B
30 LET A=2
40 PRINT "A*10=";A*10
44 input "a prompt with comma",A
45 print a
47 input "a prompt with semi";B
48 print b
49 print "a is"a
50 ON A GOTO 60,70,80
60 PRINT "A WAS 1":END
70 PRINT "A WAS 2":END
80 PRINT "A WAS 3":END
85 goto 90
90 END
