%{
/* Lexical analyser for RetroBASIC
   Copyright (C) 2020 Maury Markowitz

   Based on gnbasic
   Copyright (C) 1998 James Bowman
 
This file is part of RetroBASIC.

RetroBASIC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

RetroBASIC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with RetroBASIC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

#include "retrobasic.h"
#include "strng.h"
#include "parse.h"

%}

%option noyywrap
%option caseless

%%

 /* end of file */
"\032"  {
          yyterminate();
        }
<<EOF>> {
          yyterminate();
        }

 /* statements */
 /* REM statements are odd because they consist of a token and a line of text, but
    the rest of the line is part of the statement. If you want to keep the REM part as
    a separate token, this is the simplest solution. See:
    https://stackoverflow.com/questions/59117309/rest-of-line-in-bison/59122569#59122569
  */
REM.*   { yylval.s = str_new(str_copy(yytext + 3, yyleng - 3)); return REM; }
'.*     { yylval.s = str_new(str_copy(yytext + 1, yyleng - 1)); return QUOTEREM; } // short form in MS
!.*     { yylval.s = str_new(str_copy(yytext + 1, yyleng - 1)); return BANGREM; }  // later MS allow bang as well
BYE     { return BYE; }
CLEAR   { return CLEAR; }
DEF     { return DEF; }
DATA    { return DATA; }
DIM     { return DIM; }
END     { return END; }
FOR     { return FOR; }
GOSUB		{ return GOSUB; }
GOTO		{ return GOTO; }
IF      { return IF; }
INPUT   { return INPUT; }
LET	    { return LET; }
NEXT	  { return NEXT; }
NEW			{ return NEW; }
OF      { return OF; }
ON      { return ON; }
POKE    { return POKE; }
PRINT   { return PRINT; }
READ		{ return READ; }
RESTORE	{ return RESTORE; }
RETURN	{ return RETURN; }
RUN			{ return RUN; }
STEP		{ return STEP; }
STOP    { return STOP; }
THEN		{ return THEN; }
TO			{ return TO; }

 /* extended statements found in some versions*/
CALL        { return CALL; }    // used to call system functions in TI-99 and some other BASICs
CLS         { return CLS; }     // clear screen, do not confuse with CLR or CLEAR
CMD         { return CMD; }     // redirects output of PRINT to another device
GET         { return GET; }
PUT         { return PUT; }
INPUT#      { return INPUT_FILE; }
PRINT#      { return PRINT_FILE; }
OPTION      { return OPTION; }
BASE        { return BASE; }
RANDOMIZE   { return RANDOMIZE; }
SYS         { return SYS; }     // same as CALL
USING       { return USING; }
VARLIST     { return VARLIST; }
POP         { return POP; }
EXIT        { return EXIT; }    // same as POP

 /* math functions */
ABS			  { return _ABS; } /* has to have the _ because GLib has an ABS */
ATN			  { return ATN; }
COS			  { return COS; }
CLOG		  { return CLOG; }
EXP       { return EXP; }
FIX       { return FIX; }
INT			  { return INT; }
LOG			  { return LOG; }
POS			  { return POS; }
SIN			  { return SIN; }
SGN			  { return SGN; }
SQR			  { return SQR; }
RND			  { return RND; }
VAL			  { return VAL; }

 /* string-related functions */
ASC       { return ASC; }
CHR\$     { return CHR; }
LEFT\$		{ return LEFT; }
RIGHT\$		{ return RIGHT; }
MID\$     { return MID; }
LEN       { return LEN; }
STR       { return STR; }

 /* system functions */
TAB			  { return TAB; }
SPC			  { return SPC; }
PEEK      { return PEEK; }
FRE       { return FRE; }
USR       { return USR; }
LIN       { return LIN; }

 /* various operators and punctuation */
[:,;()\^=+\-*/\<\>\&]     { return yytext[0]; }

 /* alternate form for power */
"**"      { return '^'; } // FIXME: we should have a separate token for this?

 /* binary operators */
AND       { return AND; }
OR        { return OR; }
NOT       { return NOT; }
XOR       { return XOR; }

 /* comparison operators */
\<=       { return CMP_LE; }
=\<       { return CMP_LE; }
\>=       { return CMP_GE; }
=\>       { return CMP_GE; }
\<\>      { return CMP_NE; }
\>\<      { return CMP_NE; }
#         { return CMP_HASH; } // use a separate token here to preserve it in LIST

 /* defs added in Extended BASIC */
 /* FIXME: these are actually easy to do, simply run them as DIMs so they get entered into the btree */
DEFSTR    { return DEFSTR; }
DEFINT    { return DEFINT; }
DEFSNG    { return DEFSNG; }
DEFDBL    { return DEFDBL; }

 /* other string commands and functiuons */
CHANGE    { return CHANGE; }
CONVERT   { return CONVERT; }
UCASE\$   { return UCASE; }
LCASE\$   { return LCASE; }

 /* numeric constants and line numbers */
[0-9]*[0-9.][0-9]*([Ee][-+]?[0-9]+)? {
              yylval.d = strtod(yytext, NULL);
              return NUMBER;
            }

 /* user defined functions */
"FN"[A-Za-z@][A-Za-z0-9_]?[\$%\!#]? {
              yylval.s = str_new(yytext);
              return FUNCTION_NAME;
            }

 /* variable references */
 /* currently set to allow only one or two chars plus an optional type indicator
    replace the ? with a * for multi-char variables */
[A-Za-z@][A-Za-z0-9_]?[\$%\!#]? {
              yylval.s = str_new(yytext);
              return VARIABLE_NAME;
            }

 /* string constants */
\"[^"]*\"   {
              yytext[strlen(yytext) - 1] = '\0';
              yylval.s = str_new(yytext + 1);
              return STRING;
            }

 /* preserve line ends */
[\n]        { return '\n'; }

 /* eat other whitespace */
[ \t\r\l]   {  }

%%
