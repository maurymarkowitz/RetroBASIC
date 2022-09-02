#
# makefile for RetroBASIC
#
#
# various setup
LEX = flex
LFLAGS = -lfl
YAC = bison
YFLAGS =-dtv
CC = gcc -g
CFLAGS = -DYYDEBUG=1
CLIBS = -ly -ll

rm=/bin/rm -f
mv=/bin/mv -f

# our program name
TARGET = retrobasic

# the final program has three inputs, the lex/yacc and the interpreter source
$(TARGET): $(wildcard src/*.c) parse.tab.c lex.yy.c
	$(CC) -Isrc $^ -o $(TARGET) -lm
 
# if the lex or .tab.h file is changed, run lex again
lex.yy.c: src/scan.l parse.tab.h
	$(LEX) $(LEXFLAGS) $<

# If the yacc file is changed, run yacc again.
parse.tab.c parse.tab.h: src/parse.y
	$(YAC) $(YFLAGS) $<

clean:
	$(rm) $(TARGET) $(TARGET).o
	$(rm) *.tab.h *.tab.c *.lex.c

all: retrobasic
