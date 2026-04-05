100 REM Test PRINT USING with HP IMAGE format
110 REM Simple numeric formatting
120 A = 465.465
130 PRINT USING "3D.4D"; A
140 REM Expected: 465.4650

150 REM Test with sign
160 B = -1234
170 PRINT USING "S4D"; B
180 REM Expected: -1234

190 REM Test string output
200 C$ = "HELLO"
210 PRINT USING "6A"; C$
220 REM Expected: HELLO

230 END
