1 REM lots of little tests
2 REM
5 REM print some random numbers
6 REM
7 PRINT"Some rnds with RANDOMIZE 0"
8 RANDOMIZE 1:FOR I=1 TO 10:PRINT RND(0):NEXT I
9 REM
10 REM calling DEFINT and then listing vars
11 REM
20 DEFINT X,Y
30 VARLIST
34 REM
35 REM simple loop
36 REM
50 FOR I=1 TO 3
60 PRINT "loop with NEXT I"I
70 NEXT I
74 REM
75 REM simple loop with no variable in NEXT
76 REM
80 FOR I=1 TO 3
90 PRINT "loop with NEXT (no I)"I
100 NEXT
104 REM
105 REM print a long number that should display as E format
106 REM
110 A=9999999999
120 PRINT "this should print 1E+10:"A
124 REM
125 REM some variations on the comment formats
126 REM
130 ' quote comment
140 ! bang comment
144 REM
145 REM trying remarks at the end of the lines
146 REM
150 PRINT"this line has a trailing bang comment"!comment
160 PRINT"this line has a trailing quote comment"'comment
170 PRINT"this line has a trailing REM comment":REM comment
184 REM
185 REM making a 2x2 array and then printing it out
186 REM
200 DIM A(2,2)
300 A(1,1)=1:A(1,2)=2:A(2,1)=3:A(2,2)=4
400 PRINT"Array 1 to 4: "A(1,1),A(1,2),A(2,1),A(2,2)
494 REM
495 REM make a simple function that returns itself
496 REM
500 DEF FNA(X)=X
520 print "Calling function A with const 20, should return 20: "FNA(20)
525 print "Setting variable X to 10"
530 X=10
540 print "Calling function A with var X=10, should return 10: "FNA(X)
550 print "After calling function, X is"X
594 REM
595 REM make a function with some actual math
596 REM
600 DEF FNB(X)=X+5
620 print "Calling function B with 20 const, should return 25: "FNB(20)
630 print "Value of X after B is "X
694 REM
695 REM not sure why this is here
696 REM
700 PRINT:PRINT:PRINT:PRINT"three blank lines above"
1094 REM
1095 REM do some string manipulation using string functions
1096 REM
1099 PRINT "string manipulation on HELLO WORLD"
1100 A$="HELLO WORLD"
1200 PRINT A$, "len="len(a$)
1300 PRINT "left 5, should produce HELLO: "LEFT$(A$,5)
1400 PRINT "right 5, should produce WORLD: "right$(A$,5)
1500 PRINT "mid 5, should produce O WORLD: "mid$(A$,5)
1600 PRINT "mid 4,5, should produce LO WO: "mid$(A$,4,5)
1610 PRINT "mid 20,5, should produce nothing: "mid$(A$,20,5)
1620 PRINT "right 100, should produce HELLO WORLD: "right$(A$,100)
1630 PRINT "left 100, should produce HELLO WORLD: "left$(A$,100)
1640 PRINT "mid 100,100 should produce nothing: "mid$(A$,100,100)
1640 PRINT "mid 5,100 should produce O WORLD: "mid$(A$,5,100)
1700 REM
1710 REM do some string manipulation using ANSI slices
1720 REM
1730 PRINT "string slicing on HELLO WORLD"
1740 PRINT A$, "len="len(a$)
1750 PRINT "(1:5), should produce HELLO: "A$(1:5)
1760 PRINT "(4:5), should produce LO: "A$(4:5)
1800 REM
1810 REM concats
1820 REM
1830 PRINT "concat with plus, should produce HELLO WORLD: ";"HELLO" + " " + "WORLD"
1840 PRINT "concat with amp, should produce HELLO WORLD: ";"HELLO" & " " & "WORLD"
1850 PRINT "multi-concat, should produce 1 2 3 4: ";"1" & " " & "2" & " " & "3" & " " & "4"
1900 REM
1910 REM time and date
1920 REM
1930 !PRINT "the unix time is "TIME
1940 !PRINT "the BASIC time string is "TIME$
1950 !PRINT "the date value is "DATE
1960 !PRINT "the date string is "DATE$
2294 REM
2295 REM make sure B and B() are different
2296 REM
2300 B=10
2400 PRINT "B",B,"B(1,1)",B(1,1)
2500 print "hello"B
2994 REM
2995 REM various prints and inputs with different separators
2996 REM
3000 LET A=2
4000 PRINT "A=2, A*10=";A*10
4400 input "a prompt with comma",A
4500 print a
4700 input "a prompt with semi";B
4800 print b
4900 print "a is "a" b is "b
4950 REM
4955 REM input with three variables
4956 REM
4960 PRINT "input with a,b,c":INPUT A,B,C
4965 PRINT "inputs were: " A,B,C
4994 REM
4995 REM using the values just input, do ON GOTO
4996 REM
4997 PRINT "using ON with value A="A
5000 ON A GOTO 6000,7000,8000
6000 PRINT "A WAS 1":END
7000 PRINT "A WAS 2":END
8000 PRINT "A WAS 3":END
9000 END
