1 REM Issue #14: number_to_bin_string() only covers 6 bits
2 REM BIN$(255) should produce 11111111 (8 ones)
3 REM Bug: loop visits bits 32,16,8,4,2,1 - only 6 bits total
4 REM Also uses type punning via pointer cast (undefined behavior)
10 PRINT "BIN$(255) expect 11111111: ";BIN$(255)
20 PRINT "BIN$(1) expect 1: ";BIN$(1)
30 PRINT "BIN$(128) expect 10000000: ";BIN$(128)
99 END
