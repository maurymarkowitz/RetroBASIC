1 REM lots of little tests
2 REM
5 REM print some random numbers
6 REM
7 PRINT"Some rnds with RANDOMIZE 1"
8 RANDOMIZE 1:FOR I=1 TO 10:PRINT RND(0):NEXT I
9 REM
10 REM calling DEFINT and then listing vars
11 REM
20 DEFINT X,Y
25 PRINT "printing var list"
30 VARLIST
33 REM
34 REM hex, oct, bin constants
35 REM
36 PRINT "hex &FF, should print 255: ";&FF
37 PRINT "hex 0hFF, should print 255: ";0hFF
38 PRINT "oct 0o77, should print 63: ";0o77
39 PRINT "bin 0b10101010, should print 170: ";0b10101010
40 GOSUB te
44 REM
45 REM simple loop
46 REM
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
120 PRINT "printing A=9999999999, this should print 1E+10: "A
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
1200 PRINT A$, "len="len(A$)
1300 PRINT "left 5, should produce HELLO: "LEFT$(A$,5)
1400 PRINT "right 5, should produce WORLD: "right$(A$,5)
1500 PRINT "mid 5, should produce O WORLD: "mid$(A$,5)
1600 PRINT "mid 4,5, should produce LO WO: "mid$(A$,4,5)
1610 PRINT "mid 20,5, should produce nothing: "mid$(A$,20,5)
1620 PRINT "right 100, should produce HELLO WORLD: "right$(A$,100)
1630 PRINT "left 100, should produce HELLO WORLD: "left$(A$,100)
1640 PRINT "mid 100,100 should produce nothing: "mid$(A$,100,100)
1640 PRINT "mid 5,100 should produce O WORLD: "mid$(A$,5,100)
1650 PRINT "seg 4,5, should produce LO: "seg$(A$,4,5)
1660 PRINT "substr 4,5, should produce LO WO: "substr$(A$,4,5)
1660 PRINT "substring 4,5, should produce LO WO: "substring$(A$,4,5)
1700 REM
1710 REM do some string manipulation using ANSI slices
1720 REM
1730 PRINT "string slicing on HELLO WORLD"
1740 PRINT A$, "len="len(A$)
1750 PRINT "(1:5), should produce HELLO: "A$(1:5)
1760 PRINT "(4:5), should produce LO: "A$(4:5)
1770 REM
1771 REM assign string into a slice
1772 REM
1780 A$="HELLO WORLD"
1790 A$(1:4)="GOOD"
1791 PRINT "assigned into a slice, should produce GOODO WORLD: "A$
1800 REM
1801 REM concats
1802 REM
1810 PRINT "concat with plus, should produce HELLO WORLD: ";"HELLO" + " " + "WORLD"
1820 PRINT "concat with amp, should produce HELLO WORLD: ";"HELLO" & " " & "WORLD"
1830 PRINT "multi-concat, should produce 1 2 3 4: ";"1" & " " & "2" & " " & "3" & " " & "4"
1840 REM
1841 REM test upper and lower conversions
1842 REM
1850 PRINT"HelLO to upper, should produce HELLO: ";UCASE$("HelLO")
1860 PRINT"WORld to lower, should produce world: ";LCASE$("WORld")
1870 REM
1871 REM try CHANGING strings to nums and back
1872 REM
1880 DIM B(50)
1881 PRINT "changing hello to ASCII, should produce 5 104 101 108 108 111: ";
1882 B$="hello"
1883 CONVERT B$ TO B
1884 FOR J=0 TO B(0):PRINT B(J),:NEXT J:PRINT
1885 REM the line above only works on strings because CHANGE puts the length in (0)
1890 PRINT "changing from ASCII back to string, should produce hello: ";
1891 CHANGE B TO B$
1892 PRINT B$
1900 REM
1901 REM some new string commands
1002 REM
1910 PRINT "using SPACE$, should print three spaces and HELLO: ";SPACE$(3);"HELLO"
1920 PRINT "using STRING$, should print HELLO three times: ";STRING$("HELLO",3)
1930 PRINT "using STRING$ with ASCII value, should print three X's: ";STRING$(88,3)
2000 REM
2001 REM bin/oct/hex conversions
2002 REM
2010 PRINT "Convert hex FFFE to number, should print 65534: ";HEX("FFFE")
2020 PRINT "Convert oct 7654 to number, should print 4012: ";OCT("7654")
2030 PRINT "Convert bin 101010 to number, should print 42: ";BIN("101010")
2040 PRINT "Convert 5432 to hex, should print 1538: ";HEX$(5432)
2050 PRINT "Convert 4321 to oct, should print 10341: ";OCT$(4321)
2060 PRINT "Convert 55 to bin, should print 110111: ";BIN$(55)
2294 REM
2295 REM make sure B and B() are different
2296 REM
2300 B=10
2400 PRINT "B, should be 10: ",B,"B(1), should be 104: ",B(1)
2500 REM
2501 REM test J vs. J(0) vs. J(1) on non-DIMed variables
2502 REM
2510 L=5:L(1)=10
2515 PRINT "L should be 5 "J
2520 PRINT "L(1) should be 10 "L(1)
2525 PRINT "L(0) should be 0 "L(0)
2530 DIM K(5)
2535 PRINT "K(5) should be 0 "K(5)
2540 PRINT "K(6) should cause error: "K(6)
2600 REM
2610 REM test that a small DIMmed array correctly errors on index > 10
2620 REM
2630 L(3)=3
2640 DIM L(5)
2650 PRINT "L(3) should be 3: "L(3)
2670 PRINT "L(6) should cause error: "L(6)
3000 REM
3010 REM time functions
3020 REM
3030 PRINT "jiffies so far: ";TIME
3040 PRINT "time so far: ";TIME$
3050 PRINT "resetting time to 001000, 10 minutes, 36000 jiffies"
3060 TIME$="001000"
3070 PRINT "time now: ";TIME$
3994 REM
3995 REM various prints and inputs with different separators
3996 REM
3998 LET A=2
4000 PRINT "A=2, A*10=";A*10
4400 input "an input prompt with comma, enter a number (1 to 3)",A
4700 input "an input prompt with semi, enter a number";B
4900 print "a is "A" b is "B
4901 REM
4902 REM use the value of A for a GOTO..OF
4903 REM
4910 GOSUB A OF 4920,4930,4940
4915 GOTO 4960
4920 PRINT"A was 1":RETURN
4930 PRINT"A was 2":RETURN
4940 PRINT"A was 3":RETURN
4950 REM
4955 REM input with three variables
4956 REM
4960 PRINT "input with a,b,c":INPUT A,B,C
4965 PRINT "inputs were: " A,B,C
4994 REM
4995 REM using the values just input, do ON GOTO
4996 REM
4997 PRINT "using ON with value A="A
5000 ON A GOTO 5010,5020,5030
5010 PRINT "A WAS 1":GOTO 5100
5020 PRINT "A WAS 2":GOTO 5100
5030 PRINT "A WAS 3":GOTO 5100
5097 REM
5098 REM TEST UBOUND AND LBOUND
5099 REM
5100 H=5:V=4
5110 DIM X(H,V)
5120 PRINT "X is 5 by 4, UBOUND should print 5: "UBOUND(X)
5130 PRINT "X is 5 by 4, UBOUND 2 should print 4: "UBOUND(X,2)
5200 REM
5201 REM test pausing
5202 REM
5210 PRINT "jiffies so far: ";TIME
5220 PRINT "pausing for 5 seconds"
5230 PAUSE 300
5240 PRINT "after pause: ";TIME
8000 STOP
8100 REM
8101 REM test label'ed gosub
8102 REM
8110 LABEL te
8120 PRINT "successfully GOSUBed to label which had line number: "te
8130 RETURN
9000 END
