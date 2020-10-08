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
${TARGET}: ${TARGET} ${TARGET}.tab.c lex.yy.c
	${CC} ${TARGET}.c ${TARGET}.tab.c lex.yy.c -o $TARGET

# if the lex or .tab.h file is changed, run lex again
lex.yy.c: ${TARGET}.l ${TARGET}.tab.h
	${LEX} ${LEXFLAGS} ${TARGET}.l

# If the yacc file is changed, run yacc again.
${TARGET}.tab.c: ${TARGET}.y
	${YAC} ${YFLAGS} ${TARGET}.y

clean:
	$(rm) ${TARGET} ${TARGET}.o
	$(rm) *.tab.h *.tab.c *.lex.c

all: retrobasic
