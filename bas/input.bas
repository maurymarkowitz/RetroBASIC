5 REM various tests of INPUT statements
5 REM
10 PRINT "input single number with no prompt"
20 INPUT A
30 REM PRINT "input single number with a prompt"
40 REM INPUT "the prompt";A
50 PRINT "input three numbers with a single prompt"
60 INPUT "single prompt",A,B,C
65 PRINT A,B,C
70 PRINT "input three numbers with three prompts"
80 INPUT "A prompt",A,"B prompt",B,"C prompt",C
85 PRINT A,B,C
90 PRINT "input a number and a string"
100 INPUT "number",A,"string",A$
110 PRINT A,A$
120 PRINT "LINPUT test, enter weird things";
130 LINPUT B$
140 PRINT B$
