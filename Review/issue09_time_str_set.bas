1 REM Issue #9: bit[2] buffer not null-terminated before atoi()
2 REM Set TIME$ to "120000" (12:00:00) then read it back
3 REM Expected: TIME$ reads back as "120000"
4 REM Bug: atoi() reads past 2-byte buffer, producing wrong h/m/s values
10 TIME$="120000"
20 PRINT "TIME$ expect 120000: ";TIME$
99 END
