RetroBASIC Reference Manual
===========================

**Copyright © 2023 Maury Markowitz**

Version 1.8.8

[![GPL license](http://img.shields.io/badge/license-GPL-brightgreen.svg)](https://opensource.org/licenses/gpl-license)

<!-- TOC start (generated with https://github.com/derlin/bitdowntoc) -->

- [About this manual](#about-this-manual)
   * [Abbreviations](#abbreviations)
   * [Formatting and notation](#formatting-and-notation)
- [Introduction](#introduction)
   * [What is RetroBASIC?](#what-is-retrobasic)
   * [What RetroBASIC is not](#what-retrobasic-is-not)
- [Some underlying concepts](#some-underlying-concepts)
   * [Syntax example](#syntax-example)
- [Data in BASIC programs](#data-in-basic-programs)
   * [Numbers](#numbers)
   * [Strings](#strings)
   * [Variables](#variables)
   * [Arrays](#arrays)
- [Commands](#commands)
   * [`BYE`](#bye)
   * [`CLR` and `CLEAR`](#clr-and-clear)
   * [`CLS`](#cls)
   * [`END`](#end)
   * [`NEW`, `ERASE` and `SCRATCH`](#new-erase-and-scratch)
   * [`RUN` [*aexp*]](#run-aexp)
   * [`STOP` [*sexp*]](#stop-sexp)
   * [Unsupported](#unsupported)
- [Program statements](#program-statements)
   * [[`REM`|`'`|`!`] [*scon*]](#rem-scon)
   * [[`LET`] *var*=*expr*](#let-varexpr)
   * [`DIM` *var*(*nexp*[, *nexp*...])[,*var*(*nexp*[, *nexp*...])...]](#dim-varnexp-nexpvarnexp-nexp)
   * [`GOTO` and `GO TO`](#goto-and-go-to)
   * [`GOSUB` and `RETURN`](#gosub-and-return)
   * [`IF` *lexp* `THEN` {(line)|(statmnt)[:(statmnt):...]}](#if-lexp-then-linestatmntstatmnt)
   * [`ON` *aexpr* {`GOTO`|`GOSUB`} [*lineno*|*aexpr*]{,[*lineno*|*aexpr*],...}](#on-aexpr-gotogosub-linenoaexprlinenoaexpr)
   * [`FOR` *avar*=(aexpr1) `TO` *aexpr2* [`STEP` *aexpr3*] {:|}<CR>} [*statmnt*,{:|}<CR>}...] and `NEXT` [*avar*,[*avar*,...]]](#for-avaraexpr1-to-aexpr2-step-aexpr3-statmnt-and-next-avaravar)
   * [`POP`](#pop)
   * [`EXIT`](#exit)
   * [`PAUSE` *aexp*](#pause-aexp)
   * [`LABEL` *nvar*](#label-nvar)
   * [`CALL`, `SYSTEM` and `SYS`](#call-system-and-sys)
- [Input/Output Statements](#inputoutput-statements)
   * [`PRINT` [*exp*{|[;|,]},...]]](#print-exp)
   * [`INPUT` [*sexp*{[;|,]}]*var*[,*var*...]](#input-sexpvarvar)
   * [`DATA` *con*[,*con*...], `READ` *var*[,*var*] and `RESTORE` [{*lineno*!*aexp*}]](#data-concon-read-varvar-and-restore-linenoaexp)
- [Other statements](#other-statements)
   * [`RANDOMIZE` [*aexp*]](#randomize-aexp)
   * [`CHANGE` {*avar*|*svar*} TO {*svar*|*avar*}, `CONVERT` {*avar*|*svar*} TO {*svar*|*avar*}](#change-avarsvar-to-svaravar-convert-avarsvar-to-svaravar)
- [Operators](#operators)
   * [Mathematical operators (arithmetic)](#mathematical-operators-arithmetic)
   * [Logical operators](#logical-operators)
   * [String operators](#string-operators)
- [Mathematical functions](#mathematical-functions)
   * [`ABS`(*aexp*)](#absaexp)
   * [`CLOG`(*aexp*)](#clogaexp)
   * [`EXP`(*aexp*)](#expaexp)
   * [`FIX`(*aexp*)](#fixaexp)
   * [`FRAC`(*aexp*)](#fracaexp)
   * [`INT`(*aexp*)](#intaexp)
   * [`LOG`(*aexp*)](#logaexp)
   * [`PI`[(*dexp*)]](#pidexp)
   * [`ROUND`(*aexp*[,*aexp])](#roundaexpaexp)
   * [`RND`(*aexp*)](#rndaexp)
   * [`SGN`(*aexp*)](#sgnaexp)
   * [`SQR`(*aexp*)](#sqraexp)
   * [`UBOUND`(*avar*{,*aexp*}) and `LBOUND`(*avar*{,*aexp*})](#uboundavaraexp-and-lboundavaraexp)
- [Numeric string functions](#numeric-string-functions)
   * [`BIN`(*sexp*) and `BIN$`(*aexp*)](#binsexp-and-binaexp)
   * [`OCT`(*sexp*) and `OCT$`(*aexp*)](#octsexp-and-octaexp)
   * [`HEX`(*sexp*) and `HEX$`(*aexp*)](#hexsexp-and-hexaexp)
- [Trigonometric functions](#trigonometric-functions)
   * [`ACS`(*aexp*)](#acsaexp)
   * [`ASN`(*aexp*)](#asnaexp)
   * [`ATN`(*aexp*)](#atnaexp)
   * [`CSH`(*aexp*) and `COSH`(*aexp*)](#cshaexp-and-coshaexp)
   * [`COS`(*aexp*)](#cosaexp)
   * [`CSH`(*aexp*) and `COSH`(*aexp*)](#cshaexp-and-coshaexp-1)
   * [`SIN`(*aexp*)](#sinaexp)
   * [`SNH`(*aexp*) and `SINH`(*aexp*)](#snhaexp-and-sinhaexp)
   * [`TAN`(*aexp*)](#tanaexp)
   * [``TNH`(*aexp*) and TANH`(*aexp*)](#tnhaexp-and-tanhaexp)
- [String functions](#string-functions)
   * [`ASC`(*sexp*)](#ascsexp)
   * [`CHR$`(*aexp*)](#chraexp)
   * [`INKEY$`(*dexp*)](#inkeydexp)
   * [`LEN`(*sexp*)](#lensexp)
   * [`STR$`(*aexp*)](#straexp)
   * [`VAL`(*sexp*)](#valsexp)
   * [`UCASE$`(*sexp*) and `LCASE$`(*sexp*)](#ucasesexp-and-lcasesexp)
- [System functions](#system-functions)
   * [`FRE`(*dexp*)](#fredexp)
   * [`POS`(*aexp*)](#posaexp)
   * [`PEEK`(*aexp*)](#peekaexp)
   * [`USR`(*aexp*)](#usraexp)
   * [`LIN`(*aexp*)](#linaexp)
   * [`SPC`(*aexp*), SPA(*aexp*) and SPACE$(*aexp*)](#spcaexp-spaaexp-and-spaceaexp)
   * [`STRING$`([*sexp*|*aexp*],*aexp*)](#stringsexpaexpaexp)
   * [`TAB`(*aexp*)](#tabaexp)
   * [`TIME`{(*dexp*)} and `TIME=`*aexp*](#timedexp-and-timeaexp)
   * [`TIME$`(*dexp*) and `CLK$`](#timedexp-and-clk)

<!-- TOC end -->

<!-- TOC --><a name="about-this-manual"></a>
## About this manual

This manual is primarily a listing of the operators, commands and statements in the RetroBASIC interpreter. It also details some of the internal structures and differences between dialects of BASIC. It is written in Markdown in order to make it readable on most platforms.

<!-- TOC --><a name="abbreviations"></a>
### Abbreviations

The following abbreviations will be used in this manual:

- *ncon* - any numeric constant
- *icon* - an integer constant
- *dcon* - a double constant
- *scon* - a string constant
- *con* - any constant
- *nvar* - a numeric variable
- *svar* - a string variable
- *avar* - an array variable (matrix)
- *var* - any of the variable types above
- *aop* - arithmetic operator
- *sop* - string operator
- *lop* - logical operator
- *aexp* - arithmetic expression
- *sexp* - string expression
- *lexp* - logical expression
- *exp* - any of the expression types above
- *dexp* - dummy expression, seen in some functions
- *statmnt* - any complete statement
- *lineno* - a line number

<!-- TOC --><a name="formatting-and-notation"></a>
### Formatting and notation

This manual will use the following typographic conventions:

- monospaced `CAPITAL LETTERS` will be used to indicate keywords and commands
- *italicized* lower case words indicate an abbreviation from the list above
- [square brackets] indicate optional items separated by commas
- {curly braces} indicate "one of" options separated with the vertical bar
- <angle brackets> indicate special characters like a carriage return
- the ellipsis... indicates "and more of same", normally in option lists

For example:

`PRINT` [*exp*{|[;|,]},...]]

This indicates that the PRINT statement consists of the statement keyword followed by zero or more optional expressions separated by nothing, a semicolon, or a comma. The *exp* indicates that any expression type may be used. Note that the line number is not indicated at the front, nor are the <CR> or <Enter> at the end, as these are assumed to be in the source code.

<!-- TOC --><a name="introduction"></a>
## Introduction

<!-- TOC --><a name="what-is-retrobasic"></a>
### What is RetroBASIC?

RetroBASIC is a multi-lingual version of the BASIC programming language intended to run classic BASIC programs written from the 1960s into the 1980s. It includes most features from three main families of BASIC:

- Dartmouth BASIC Version 4
- HP Timeshared BASIC
- DEC BASIC-PLUS and its better-known offshoot: Microsoft BASIC

While most BASIC dialects take their basic syntax and keywords from the original Dartmouth BASIC, they began to diverge in the late 1960s into these three general families. The goal of RetroBASIC is to run any program written for these dialects and their many offshoots.

So, for instance, RetroBASIC can run the version of Super Star Trek found in *BASIC Computer Games*, a Microsoft BASIC variation that is likely one of the most widely-ported games in history. But it can also run the (non-Super) Star Trek found in the earlier *101 BASIC Games*, written for DEC BASIC. It can also run most programs from *What to do After You Hit Return*, which are written in HP's dialect. Practically any major program should run properly without conversion.

Programs must be provided in plain text, better known as "source code". RetroBASIC cannot read binary files from other platforms, which was the normal way to store BASIC programs on home computers. There are a variety of programs available that will read these tokenized files and output text, which can then be run in RetroBASIC.

<!-- TOC --><a name="what-retrobasic-is-not"></a>
### What RetroBASIC is not

The goal of RetroBASIC is to allow you to run popular BASIC programs written during the language's Golden Age. As such, it is also marked by a number of deliberate limitations:

- the language is intended to *run* programs, not *edit* them, and it thus lacks an interactive editor
- you cannot `LIST` a program
- it does not include any platform-specific instructions like sound or graphics, as these are not portable
- if does not (currently) have file handling features, as these vary considerably across platforms

<!-- TOC --><a name="some-underlying-concepts"></a>
## Some underlying concepts

Like most computer languages, BASIC has a number of **keywords** that are reserved by the language. In BASIC the list of keywords is normally fixed, meaning that users cannot add new keywords or modify the actions of existing ones. This contrasts with programming languages like ALGOL which were based around the idea of creating new keywords in code. As new keywords cannot be created in most BASIC dialects, BASIC tends to have many more reserved keywords than other languages.

Any program consists of a series of instructions. In BASIC, these are known as **statements**. A statement consists of a keyword and then zero or more **expressions**. Only certain keywords can appear at the front of a statement, others only as part of an expression. To confuse matters, the subset of keywords that can appear at the front are often referred to as "statements" as well, while other dialects refer to these special keywords simply as "keywords". In most dialects, a subset of the statement keywords can only be used in certain circumstances and are known as **commands**. Commands *are* statements, and both are used *in* statements.

To avoid confusion, this manual will use the term **statement keywords** for this subset of reserved words and to clearly separate the concept of a statement from a keyword.

The purpose of an **expression** is to provide data for the statements. There are many different types of expressions and much of a program's complexity is found within them. The primary types of expressions are classified by type:

- **number** - such as 10 or -1.75. Also known as **numeric constants**.
- **string** - a series of characters surrounded by quote marks, like "Hello, World!". Also known as **string constants**.
- **variable** - a symbolic name associated with a memory location which can store the value of a number or a string for future recall.
- **array** - a type of variable that stores multiple values at once. Depending on the number of dimensions, they are also known as **vector** (one-dimensional array) or **matrix** (two-dimensional array).
- **operator** - symbol characters, typically from mathematics, that take one or two expressions and produce a number or string.
- **function** - operators using names instead of symbols. Some dialects, including RetroBASIC, allow you to define new functions.

In most dialects, variables can contain either a number value or a string value but cannot change from one to another. This split was introduced in Dartmouth BASIC, which required the user to add a dollar sign suffix to variables that wanted to hold a string value. These are known as **string variables**, and non-string variables are sometimes, but not always, referred to as **numeric variables**.

BASIC programs are generally organized over multiple **lines**, each of which contains one or more statements. A line always starts with a **line number**, which acts as a label so other parts of the program can refer to it, as well as a way for various editing tools to allow the user to indicate which lines they wish to edit. After the line number, there is a statement keyword and then any expressions that keyword may use, forming a complete statement. Lines may have more than one statement separated by colons or backslashes, depending on the dialect. Execution normally starts with the first statement on the first line, and then continues statement by statement until it reaches the end of the program. Some statements can change this normally linear progression; these are known as **branches**.

BASIC was written in an era when editing was carried out on typewriters and had a fixed-width line, often 132 characters, but sometimes 80 or 72, or rarely, even less. To address the need to allow larger statements to be typed in, most dialects have the concept of a **logical line** versus a **physical line**. A physical line is simply a single line or text as produced by the device the user is typing on, while a logical line can span multiple physical lines up to some pre-set limit. The idea of a logical line allows the code to operate properly while moving between machines with different physical line lengths.

<!-- TOC --><a name="syntax-example"></a>
### Syntax example

Here is a simple example of a BASIC program that illustrates the overall form that RetroBASIC expects:

    10 LET A=10
    20 B$="Hello"
    30 C=A+5:PRINT C
    40 PRINT B$+", World!"
    50 IF C>10 THEN PRINT "C is > 10"
    60 END

Line 10 of this program uses the `LET` statement keyword to assign the numeric value to the numeric variable `A`, using the operator `=` to separate the variable name from the expression that provides a value. In this case, the associated numeric expression is the numeric constant 10. The assignment statement is almost always the most common statement in a BASIC program, and for this reason, most versions of BASIC allow the `LET` to be optional. This produces an exception to the rule that statements start with a statement keyword; they can actually start with a statement keyword *or* a variable name.

Line 20 of this program is also an assignment statement, in this case leaving off the optional `LET`. Notice the dollar-sign on the variable name that indicates that the language should expect a string expression on the other side of the `=` operator, not a number. The expression used in this statement is a string constant.

Line 30 is an example of a multi-statement line, with two statements separated by a colon. The first statement is an assignment using the addition operator with the value stored in `A` and the numeric constant 5 as the inputs. This will have the effect of assigning the resulting value (15) to the variable `C`. The second statement on this line is a print statement, another very common statement in most programs. This will evaluate the expression, in this case returning the numerical value 15, and then print that value to the user's console.

Line 40 shows an example of *overloading*, where a keyword may mean different things depending on the context. The expression in the print statement has the `+` operator but is being given string expressions instead of numeric. In this case the `+` does not represent numeric addition but string concatenation, which places the right-hand string at the end of the left-hand string and returns a new, longer string. The result of this print statement is "Hello, World!" being printed to the console.

Line 50 is an example of a logical comparison, which is indicated by the `IF` statement keyword. This is followed by a **logical expression**, in this case using the larger-than operator, which calculates the results of expressions on both sides of the operator, compares them, and then, depending on the outcome of the comparison, optionally performs the statement following the `THEN`. As `C` will hold the value 15 at this point, and 15 is larger-than 10, the statement after `THEN` *will* be performed and produce the string "C is > 10" on the console.

Line 60 is the `END` statement, which takes no expression and stops execution of the program. `END` is optional in most dialects.

<!-- TOC --><a name="data-in-basic-programs"></a>
## Data in BASIC programs

The ultimate goal of any program is to manipulate data. Data comes in many forms in the real world, but in BASIC there are only two forms: numbers and text. Most BASIC dialects have similar concepts of what numbers can be represented as and how to manipulate them. BASICs vary much more widely in the way they store and process textual data, or *strings*. RetroBASIC attempts to support as many varieties of both numbers and strings as possible.

Another key concept in most programming languages is the difference between a *constant* and a *variable*. Constants are data entered directly into the code, for instance, the number `100` or the string `"hello"`. Variables are names that are given to the location where data is stored. As the name implies, the value of a variable can be changed. The types, capabilities and syntax of constants and variables are fairly constant across dialects, although there are a few optional features found in later versions. RetroBASIC attempts to support as many of these as possible.

<!-- TOC --><a name="numbers"></a>
### Numbers

Most BASIC interpreters of the RetroBASIC era use the equivalent of a *single* type, or *float*, to store numbers. Unless otherwise indicated, any variable will default to this type. Thus, the name `I` would be a variable with the name "I" that holds a numeric value, initially zero. The internal format used to store the value was chosen to balance the need to save memory while maximizing precision. Microcomputers generally used 32-bit or 40-bit numeric formats, as larger formats would use up too much of the extremely limited memory available in these machines.

Some dialects had a second internal number format, *integer*. Most notable among these are later versions of Microsoft BASIC, so this feature is widely available (though rarely used) in most versions from the home computer era. The MS version used 16-bit values for integers, potentially saving considerable amounts of memory in programs with large numbers of numeric constants. To indicate that a variable should store the value in integer format, the percent sign, `%`, was added to the end of the variable name. So, `I` would store a value in the default format, normally a 40-bit floating point, while `I%` would treat the value as a 16-bit integer.

A few dialects also added a *double* format as well, once again led by Microsoft's later versions like that found in Microsoft Atari BASIC. These were indicated by adding the hash symbol, `#`, to the end of the variable name. In dialects that had doubles, it was common for the default internal format of the single to be smaller and then have the programmer use doubles if more precision was required. For instance, on the Atari version of MS BASIC, a single was 32 bits instead of the more typical 40, while the double was 64 bits. On most of these dialects, a single-precision value could be explicitly indicated by adding the `!` suffix to the variable name, although this was the default format for variables, it is almost never found in real-world programs.

As memory is no longer an issue, RetroBASIC uses the IEEE double format to store all numbers. This has no effect on the programs; the extra precision is hidden within the system. The only difference is that when a calculation is stored in a variable, if that variable is declared as an integer, the `INT` operator is applied to the result. In some dialects, like BBC BASIC, an entirely separate math library is used for this purpose, which offers higher performance. In MS versions, the existing floating point code is used and then discards the fractional leftover, which allowed them to implement these functions without adding new code to the already memory-limited machines. RetroBASIC takes this later approach, as performance and memory footprint are no longer issues.

BASIC inputs and outputs numbers in decimal format, using the same formatting rules as C's "g" format. This means that large numbers and small fractions are output in exponent format, regardless of how they are input. For instance, if the program asks the user to type in a number and they type fifteen ones, when output that value will be rendered as 1.11111E14. For those dialects that supported doubles, numeric constants could be set to doubles by changing the E to a D.

RetroBASIC has the additional feature that numeric constants can be entered in hexadecimal, octal or binary format. Hexadecimal values are indicated by placing the string "0x", "0h" or "&" in front of the value, for instance, &1F3A will be converted internally to the value 7994. Octal is indicated by "0o", like "0o3725", and binary with "0b", like "0b10110011". These values can be used in any numeric expression in place of a decimal constant. Like any numeric value, they are converted to doubles internally.

<!-- TOC --><a name="strings"></a>
### Strings

Strings hold zero or more characters to form sentence-like values, stored using ASCII, or more commonly, a platform-specific 8-bit variation of ASCII like PETASCII or ATASCII. The maximum size of a string varies on different platforms. Those that originated on systems with printer terminals are often limited to 72 or 132 characters, the length of one line on the paper, while those from the video terminal and home computer era are normally 128 or 256 characters, which is easy to store in an 8-bit value. Some dialects allow strings to be limited only by system memory.

 RetroBASIC strings are always variable-length can be any size up to the underlying operating system's limit, typically a 32-bit or 64-bit value. This is much more than most dialects of BASIC, which were normally limited to 8-bit or 16-bit lengths. So while it is possible that bad code would produce strings that are too long for the machine it was originally written on, causing an error, it will likely work fine in RetroBASIC. In the case that a string ends up longer than the original DIMension in those dialects that require it, like HP, an error will be printed to the console.
 
String constants are normally delimited with double-quotes, like "Hello, World!", although some dialects use single-quotes, 'Hello, World!', or allow either format. Dialects vary widely in the way that they include quotes inside string literals; the modern solution of placing two double-quotes beside each other inside a string is a later invention. Another curiosity, also seen in the FOCAL language, is that the closing quote can be left off if it is the last character on the line, although this is rarely seen in actual programs.

The major difference between dialects of BASIC is the way that strings and substrings are manipulated. These vary significantly between the three "families" noted in the introduction. Code that manipulates strings using one of these styles will not run on other variations and will require some level of porting effort to do so.

Dartmouth v4 introduced the `CHANGE` command in V4 as a method of manipulating strings. This converts a string of characters into a numeric array containing the length of the string in the zero slot and the ASCII values of each character in the rest of the slots in the array. The values were then manipulated numerically, and then `CHANGE`d back into a string. The system was not easy to use for many simple tasks, like concatenation, which required loops and copying values from one array to another. It does have some advantages in certain operations, like converting upper to lower case or back, where the ASCII number is what is being checked.

HP BASIC is the third major family. This included the `CHANGE` command from Dartmouth, but renamed it `CONVERT`. While one might argue this is a better name for this feature, changing it seems to offer little advantage compared to the need to port programs that would otherwise run without change. HP is more notable for its addition of a new method of manipulating strings. This introduces the concept of the *slice*, a pair of numbers that represents a series of continuous characters within the original string. Slices are efficient as they are represented by a pointer to the starting location and a length, it does not copy characters or their ASCII values in memory.

Today, the best-known method of manipulating strings is the version found in MS-derived dialects. This uses the `+` operator for concatenation and the functions `MID$`, `LEFT$` and `RIGHT$` to return substrings. This style of manipulation was originally introduced by Tymshare on their SUPER BASIC, which was then copied by DEC to produce BASIC-PLUS, which was then copied by MS to produce Microsoft BASIC. It is arguably the least efficient method of performing string manipulations and often leads to MS systems running out of memory after performing even a relatively few string operations.

When microcomputers were first emerging in the mid-1970s, the programmers on these platforms invariably introduced BASIC (maybe several flavors of) for these machines, and they almost always copied either the MS or HP model for strings, depending on which platform they were most familiar with. Few microcomputer users came from the mainframe world, and the Dartmouth concept was forgotten. Versions based on the DEC/MS or HP models were well represented until about 1978, when the first all-in-one machines like the Commodore PET began to take over the market. These platforms almost always licensed MS's code, which quickly became the *de facto* standard. HP-style strings lived on, primarily on platforms where memory was limited or markets where MS was not so established. Atari and Sinclair are examples of later dialects where slicing was the primary style.

One of the major goals of RetroBASIC was to support programs from any of the older dialects, and for this reason, it supports all of these styles. It includes the entire set of string functions from MS, slicing from HP, and both `CHANGE` and `CONVERT`.

<!-- TOC --><a name="variables"></a>
### Variables

Variables are named references to a location in computer memory holding data. They are a key part of any programming language. In most BASIC dialects, the name can be one or two characters from the sets of A to Z or 0 to 1. This is the case for Microsoft-derived BASICs, and is the standard followed by RetroBASIC. Some allow only one character, and some allow one character and a digit, not two letters. As RetroBASIC allows any two characters, including lower case, all such variations will run fine. Some dialects allow variable names to be any length, like Atari BASIC, but this is not currently supported in RetroBASIC.

The 1968 version of Dartmouth BASIC introduced string variables for the first time. To indicate it held a string, the dollar-sign, \$, was added to the end of the name. Because the \$ is part of the name and most dialects only allow for two characters in the name, it is common to have the limitation that string variables can have single character names. There is also a subtlety to note here; as the \$ is part of the variable name, A and A$ are two different variables, and both can be used independently in a program.

Further confusion was added by the use of the `DEF` statement keywords, which allow one or more variables to be given a type without using the suffix characters. For instance, one can `DEFSTR A` to indicate that A is a string variable without needing the \$. In this case, A and A$ will still be different variables, both holding strings.

#### Notes:

Most BASIC interpreters store the values of the variables in a table with fixed-width fields. The first two locations in these fields hold the variable's name. When the program refers to the variable in code, the interpreter searches through the table from top to bottom until it finds a field with that name. If it does not find a match, it creates a new entry at the bottom of the table.

This means that every time a variable is encountered, the interpreter has to perform a linear search. As the number of variables in a program grows, this search takes an increasing amount of time and becomes a performance issue in larger programs. For this reason, large programs often have a line near the top of the code that is something like:

    10 I=0;J=0;K=0;A=0;X=0;Y=0

The purpose of this line is to force these six variables to be at the top of the table and thus be found more rapidly, improving the performance of the program. Typically, the list is ordered, so the most commonly used variable ends up first in the list.

Not all dialects work this way. Compilers, like Dartmouth, hold links directly to each variable's storage in memory and thus do not have to search the table at runtime. A number of interpreters use the same strategy, Atari BASIC being a notable example. In these versions, it is as if every variable is at the top of a one-entry list, and while the pre-flighting example above will still run, it offers no additional performance advantage.

<!-- TOC --><a name="arrays"></a>
### Arrays

Most BASIC dialects include the concept of an **array**. An array is a group of related values all referred to by a single variable name. Arrays need to be defined before use (see exception below) using the `DIM`ension statement. Later in the program, the separate values can be referred to using numbers in parentheses placed after the variable name. These numbers are known as **indexes**. For example:

    10 DIM A(10)
    20 A(1)=5
    30 A(2)=10

This program sets aside ten locations in memory, or *slots*, that can hold numeric values. It then assigns the values 5 and 10 to the first two slots. The rest have not been set, and those slots will contain zeros.

The exact handling of arrays depends on the dialect. Some allow a single dimension, while most allow two, and a small number allow three or more. In those dialects that allow two or more dimensions, single-dimension arrays, like the example above, are sometimes referred to as *vectors*, while those with two are sometimes known as *matrixes*.

RetroBASIC allows any number of dimensions and should properly run code from any of these dialects.

Dialects also vary based on what they consider to be the first entry in the array. Early versions of Dartmouth had slot 1 as the first entry in the array, but this was soon realized to be a mistake as it made it difficult to represent common polynomials, which often have a zeroth entry. Later versions of Dartmouth thus added an additional slot zero to every array. Thus, the `DIM` statement above produces an array with 11 entries in it, not 10. Debate over whether to use 0 or 1 for the first slot ran into the 1980s, but this was largely moot as MS variations did include 0 and this was the *de facto* standard, so it is safe to assume 0 is available.

As there is no indication of whether a particular program expects 0 or 1 as the first index, RetroBASIC always sets up a 0 slot just in case. This has (almost) no effect on programs; if they use index 0, it works; if not, it works. The only effect is on the `LBOUND` function, which returns the first index. This normally returns 0, but can be told to return 1 by setting the command-line switch `--array_base=1` if required or using the `OPTION BASE 1` statement. As the original Dartmouth did not include the `LBOUND` function, it is unlikely this feature will have any effect one way or another in any real program.

There is another oddity to consider. Dartmouth sets aside a 0..10 block of memory for every numeric variable, even if it is not `DIM`med. In the example program above, A is defined to have 10 slots, and then it assigns values to the first two slots. This program will also work if line 10 is left out, because A will always have 10 slots. This is a *very* odd feature and is rarely implemented in non-MS dialects, so programs relying on this feature will not run on those machines. RetroBASIC does implement this "feature" in case there are programs that use it. To date, none have been found.

Finally, there is the additional oddity that the parens are part of the variable name. That is, the variable `A` is a different variable than the one in `A(0)`. One can assign values to either, and they will be held separately in memory, at least in MS-derived dialects.

To summarize, consider this program following the MS conventions:

    10 A(0)=5
    20 A(1)=10
    30 PRINT A(0);A(1);A

The output of this program is ` 5  10  0`.

<!-- TOC --><a name="commands"></a>
## Commands

Dartmouth BASIC consisted of two separate programs, the BASIC compiler and runtime, and a shell program that edited the source code and performed a small number of commands that were deliberately intended to look like BASIC statements. So in Dartmouth, some of the statement-looking lines could be used in your program, while other statement-looking lines could only be used in the shell. This led to the separate concepts of **commands** and **statements**, a separation that many later dialects maintained.

Commands were generally intended to work on the program as a whole, loading or saving the source code, running it, debugging it, etc. Examples include `LOAD` to read source code into memory, `RUN` to execute the program, `LIST` to print the current program to the console, and so forth. Some later dialects allowed these commands to be put into programs as well; for instance, Atari BASIC could `LIST` itself. This blurred the line between statements and commands.

RetroBASIC is intended to be used with known-good BASIC source code, which can be edited in any text editor. It is then loaded and run as part of starting up the program. Thus, there is no need for `LOAD`, `SAVE` or `LIST` as these are accomplished in the editor, and this also eliminates many of the editing statements like `RENUM` and similar. Nor is there a need for `RUN` or `CONT`, as the former occurs automatically and the latter is not needed as one cannot stop the program while it is running. It does, however, include a small number of statement keywords that are normally considered commands in most dialects and are found widely enough in source code to be useful:

<!-- TOC --><a name="bye"></a>
### `BYE`

`BYE` originates with Dartmouth BASIC where it exits the BASIC program and returns the user to the interactive shell. Its effect in other dialects was varied; in Atari BASIC for instance, it exits to Memo Pad. In RetroBASIC, `BYE` simply exits the program in the same fashion as `END`.

<!-- TOC --><a name="clr-and-clear"></a>
### `CLR` and `CLEAR`

Clears the stored values of all variables and resets the dimensions of all arrays. `CLEAR` is an alternative spelling seen in a few dialects, but in others this may clear the screen, perform a `NEW`, or offer various parameters to clear certain items and leave others.

<!-- TOC --><a name="cls"></a>
### `CLS`

Clears the screen. On modern machines with scrollback buffers in the console, the scrolled text will likely still be there.

<!-- TOC --><a name="end"></a>
### `END`

`END` stops the execution of the program and exits RetroBASIC, returning you to the console shell. `END` is optional in most dialects, but adding an `END` was considered good form. `END` does not have to be at the end of the source code, it was often found higher in the code with subroutines below it, preventing them from running unless explicitly called.
    
<!-- TOC --><a name="new-erase-and-scratch"></a>
### `NEW`, `ERASE` and `SCRATCH`

`NEW` clears any existing program and data from memory and prepares to accept a new program to be entered. In RetroBASIC, it simply exits to the shell. `ERASE` and `SCRATCH` are alternative spellings found in some dialects.
    
<!-- TOC --><a name="run-aexp"></a>
### `RUN` [*aexp*]
    
`RUN` begins processing the in-memory program, if one exists. The optional *aexp* starts execution at a particular line. In RetroBASIC this occurs automatically, and `RUN` does nothing.

<!-- TOC --><a name="stop-sexp"></a>
### `STOP` [*sexp*]
    
`STOP` is similar to `END` in that the program stops executing and the user is returned to the shell. It is intended to stop execution in the middle of the program and keep the data intact so the user can `CONT`inue running after it stops. It is mostly used for debugging purposes.

RetroBASIC adds a feature from Wang BASIC, which allows it to output an optional string. This is useful for saying things like "Stopping for debugging". If no expression is included, it instead prints the default message "STOPped at line:" along with the line number.

<!-- TOC --><a name="unsupported"></a>
### Unsupported
    
`LIST` and `CONT` are not (currently) supported.

<!-- TOC --><a name="program-statements"></a>
## Program statements

This section explains the statements associated with loops, conditional and unconditional branches, subroutines and their retrieval, and similar basic functionality. It also explains the means of accessing data and the optional command used for defining variables. The following list is not in order; it is meant to group statements with similar functionality.

<!-- TOC --><a name="rem-scon"></a>
### [`REM`|`'`|`!`] [*scon*]

`REM` is short for "remark", which is used to insert comment text into the program code. Any text on the line after the `REM` is ignored, and execution immediately moves to the next line. RetroBASIC supports the alternative versions, `'` and `!`. The former is widely used in MS-derived BASICs, while the latter, taken from Fortran, is found in some mainframe dialects.

#### Examples:

    10 REM This program will print Hello! to the user's console
    20 PRINT "Hello";:REM "World" will not appear:PRINT "World"
    30 PRINT "!"

<!-- TOC --><a name="let-varexpr"></a>
### [`LET`] *var*=*expr*

The most common statement found in most programs is the assignment statement, with the keyword `LET`. This calculates the value of the expression (expr) and then assigns the result to *var*. The *type* of variable must match the type of expression; numeric expressions cannot be assigned to string variables and vice versa, and attempts to do so will raise a runtime error.

The keyword `LET` was made optional in later versions of Dartmouth BASIC, and most dialects followed this. Some code written for Dartmouth users after `LET` became optional continued to use it, in order to maintain backward compatibility. This keyword is otherwise rarely used in most dialects.

#### Examples:

    10 LET A=10+10^2
    20 B$="Hello, World!"

Line 10 calculates the value of `10+10^2`, 110, and then copies that value into the numeric variable `A`. Line 20 copies the string constant "Hello, World!" into the string variable `B$`.

<!-- TOC --><a name="dim-varnexp-nexpvarnexp-nexp"></a>
### `DIM` *var*(*nexp*[, *nexp*...])[,*var*(*nexp*[, *nexp*...])...]

Short for "dimension", `DIM` is used to set up arrays. At least one variable name and associated numeric expression has to be supplied. A variable with one numeric expression produces a one-dimensional array, sometimes referred to as a *vector*, while two-dimensional arrays are sometimes known as a *matrix*. A single `DIM` statement can set up multiple arrays in a single statement.

Each dimension of an array has a lower bound of zero and an upper bound set to the supplied *nexp*. That means there are more entries in the array than would appear at first glance. For instance, `DIM A(10)` creates an array with 11 entries, while `DIM M(6,3)` creates one with 28 entries.

In those dialects descending from HP, string arrays are actually arrays of single characters. In Atari BASIC, for instance, `DIM A$(100)` is not making an array of 101 strings but a single string with up to 100 characters.

#### Examples:

    10 DIM A(100),B(10,10),C$(5)

This dimension statement sets up two arrays: a vector from 0..100, a matrix 0..10,0..10, and a string vector 0..5.

<!-- TOC --><a name="goto-and-go-to"></a>
### `GOTO` and `GO TO`

BASIC progresses through a program by performing statements one at a time, moving to the next statement when one is completed. In this respect, a program can be thought of as a single, long list of statements. This normally linear flow is interrupted by **branches**, statements that deliberately send the execution to another point in the program. In BASIC, branches move to a **target**, which is indicated by a line number.

The simplest form of branch in BASIC is the `GOTO`, or as it was in early versions of Dartmouth BASIC, `GO TO`. `GOTO` always moves to the line number following the statement keyword and is thus also known as an **unconditional branch**. In most dialects, the expression following the keyword must be a number constant, but some allow any valid numeric expression, examples being Tiny BASIC and Atari BASIC. RetroBASIC supports both forms of the keywords and allows the use of any expression as long as it produces a valid line number.

#### Examples:

    100 PRINT 100
    110 GOTO 200
    120 PRINT 120
    200 END
    
This program will print "100" to the user's console, as the second print statement, on line 120, will be skipped over by the branch on line 110.

#### See also:

* `LABEL`

<!-- TOC --><a name="gosub-and-return"></a>
### `GOSUB` and `RETURN`

`GOSUB` statements are unconditional branches like a `GOTO`, but differ in that they record the position in the code where they were called. They do this by writing down the location of the `GOSUB` in a special area in memory known as the "runtime stack", or simply "the stack". They then branch to the target and continue as normal until they encounter a `RETURN` statement. At that time, they removed the entry on the stack they added earlier and used the location they found to continue at the statement after the original `GOSUB`.

The name "GOSUB" is a contraction of "go to subroutine". Subroutines are small sub-programs that perform a task and then complete it. For instance, one might write a subroutine to calculate the value of pi and then call that code repeatedly with different input values from different locations in the code. This allows the calculation to be isolated in the code for clarity, often placed near the bottom of the program, and then called from different parts of the rest of the program.

As the lines of code making up subroutines are normal statements, programs might accidentally run them when they reach the end of the main program code. If this occurs, the `RETURN` at the end of the subroutines will be called without a `GOSUB` and an error will occur. To prevent this, programs generally place their `END` statement immediately before the subroutines, or alternately, place the `END` at a high line number like 9999 and then `GOTO 9999` at the end of the main code.

#### Examples:

    100 GOSUB 500:PRINT 100
    110 END
    500 PRINT 200
    510 RETURN

This program will print "200" and then "100".

#### Notes:

Many dialects of BASIC will search for a branch target, starting at the top of the program and then looking through the entire source code for the matching line. Normally, subroutines are placed at the end of the program to separate them, often using large line numbers to make this more obvious. However, this also maximizes the amount of time it takes to find the subroutine at runtime and slows performance. For this reason, programs looking to improve performance would sometimes place their subroutine code at the top of the program and then have a `GOTO` to jump past it when the program started. This led to the code being difficult to read.
    
#### See also:

* `LABEL`
* `POP`
* `EXIT`

<!-- TOC --><a name="if-lexp-then-linestatmntstatmnt"></a>
### `IF` *lexp* `THEN` {(line)|(statmnt)[:(statmnt):...]}

`IF` calculates the value of the logical expression *lexp*, producing zero if it is not true and a non-zero value, typically -1, if it is true. Like an assignment, the *type* of expression, numeric or string, must be the same on either side of the logical operator; otherwise, a runtime error will be raised.

In early versions of Dartmouth BASIC, the only thing that could follow the `THEN` was a line number. This was used to perform a **conditional branch**, similar to a `GOTO` but only branching if the logical expression was true. This made the logic of such programs difficult to follow as they tended to perform many such logical comparisons and branches and thus jump around a lot. This is one of the reasons BASIC was dismissed by programmers like Dijkstra as causing "brain damage" and the common complaint that it produces "spaghetti code".

This limitation was removed from later versions of Dartmouth, changed to allow one or more statements of any sort to follow the `THEN`. In the common case where only one statement needs to be performed, placing it after the `THEN`, instead of branching to or around it, can lead to dramatically more readable code. If there is more than one statement after the `THEN`, these are performed all-or-nothing; if the logical expression is true, all of the following statements *on the same line* are performed; if it fails, *none* of them are performed and the program moves to the first statement on the next line. A few memory-limited dialects, notably Sinclair BASIC, lacked the ability to place any statement after `THEN`, and thus followed the original Dartmouth syntax.

This change also leads to the curious syntax that one can still perform the action of `THEN GOTO` a line without a `GOTO`, as the original `THEN` (line) style was retained for compatibility reasons. A more obvious syntax is to use the `THEN GOTO` (line), but this is never seen in real programs. Some dialects also allow the alternative syntax of a `GOTO` or `GOSUB` without the then, `IF X=0 GOTO 100`. RetroBASIC supports all of these options.

#### Examples:

    IF X=100 THEN 150
    
This statement tests whether the value in the numeric variable X is equal to 100. If it is, execution branches to line 150.
    
    IF A$="BASIC" THEN 200
    
Similar to the example above, but comparing strings instead of numeric values.

    IF X=100 THEN X=0
    
Unlike the previous examples, this version performs a statement instead of a branch. In older dialects lacking this capability, the code would normally be written in this fashion:

    100 IF X<>100 THEN 300
    200 X=0

This ultimately performs the same statements but can be much more difficult to understand, as the logical operator is the opposite of what the code is trying to accomplish, and line 300 may be farther down the program and thus hard to find visually.

    IF AA=145 AND BB=1 THEN PRINT AA,BB
    
This example uses a more complex logical expression that combines several types of logical operators. Due to the order of operations, the two equalities will be tested first, and then the values `AND`ed together, producing a single logical value.

`IF` statements are often used in loops. For instance:

    10 A=9
    20 A=A+1
    30 PRINT A
    40 IF A<20 THEN 20
    
This causes the program to repeatedly add 1 to the current value of A, print the new value, and then start again at line 20. This loop will continue until the value in A reaches 20, which will occur after 10 loops.

#### See also:

* `LABEL`

<!-- TOC --><a name="on-aexpr-gotogosub-linenoaexprlinenoaexpr"></a>
### `ON` *aexpr* {`GOTO`|`GOSUB`} [*lineno*|*aexpr*]{,[*lineno*|*aexpr*],...}

The `ON` statement, also known as the **computed branch**, combines a series of `IF`...`THEN` (line) statements into a single instruction. The value of *aexpr* is calculated to produce a value that is expected to be from 1 up to the number of line numbers in the list following the `GOTO` or `GOSUB`. If there is an entry in the list for that ordinal value, like a 5th entry if aexpr returns 5, then the `GOTO` or `GOSUB` is performed to that line. `ON` is often used to respond to user input that selects among a number of options. As is the case for `GOTO` and `GOSUB`, RetroBASIC allows any valid *aexpr* in place of constants for line numbers.

#### Examples:

    300 A=2
    310 ON A GOTO 400,500,600
    400 STOP
    500 BYE
    600 END

This program will perform a `STOP`, `BYE` or `END` depending on the value in the numeric variable `A`. Line 10 assigns the value 2 to A, so the program will perform `BYE`.

<!-- TOC --><a name="for-avaraexpr1-to-aexpr2-step-aexpr3-statmnt-and-next-avaravar"></a>
### `FOR` *avar*=(aexpr1) `TO` *aexpr2* [`STEP` *aexpr3*] {:|}<CR>} [*statmnt*,{:|}<CR>}...] and `NEXT` [*avar*,[*avar*,...]]

Another of the common statements found in BASIC is the FOR/NEXT loop. When this is encountered at runtime, the system calculates the value *aexpr2* and caches it on the stack. If the optional `STEP `is used, it also calculates and caches the value of *aexpr3*, if `STEP `is not used, it defaults to the value 1. It then sets the value of *avar* to the calculated value of *aexpr1*.
    
Execution then continues by performing any following statements, continuing until it encounters the `NEXT`. At that point it adds the value of *aexpr3* to *avar* and compares it to *aexpr2*; if the result in *avar* is less or equal than *aexpr2*, it returns to the first statement after the `FOR`, if it is larger than *aexpr2*, it continues with the statement after the `NEXT,` thereby terminating the loop.

Some dialects allow the variable name to be left off the `NEXT`, although this is sometimes considered bad form. Others, like later versions of Microsoft BASIC, allow multiple comma-separated variable names, so a single NEXT can close multiple loops. RetroBASIC supports all of these forms.
    
#### Examples:

This code will produce ten lines of output, containing the numbers 1 through 10:

    10 FOR X = 1 TO 10
    20 PRINT X
    30 NEXT X
    
This example is similar to the one above but demonstrates multiple statements in the FOR/NEXT "block", as well as leaving off the variable name from the NEXT:

    10 FOR Y=10 TO 20 STEP 2
    20 A=A+Y
    30 PRINT A
    40 NEXT

#### Notes:

In home computer interpreters, FOR/NEXT loops are much faster than loops constructed using `IF`/`THEN`. This is because the values of *aexpr1* and *aexpr2* are calculated only once when the loop is first encountered, instead of every time through the loop. Additionally, the starting position is saved in the same manner as a `GOSUB`, meaning the loop does not have to search for the top of the list of statements in the common case that the loop is not yet complete, which allows it to move back to the correct statement rapidly. A few dialects, notably Atari and Sinclair, do not cache the memory location of the first statement in the block but the line number instead. These dialects run much slower, as they have to search through the entire program to find the top of the loop over and over again.

Dartmouth and most other compilers, as well as the later ANSI Full BASIC, do not run the body of the loop if the index value is beyond the upper limit when it enters the loop. For instance:

    10 FOR X = 1 TO 0
    20 PRINT X
    30 NEXT X

On most dialects, the output will be a single line, "0". On Dartmouth derived versions, there is no output, and execution resumes at the statement after the NEXT X.

#### See also:

* `POP`
* `EXIT`

<!-- TOC --><a name="pop"></a>
### `POP`

FOR..NEXT loops and `GOSUB`s store information in memory in an area called the runtime stack. This information is removed from memory when the loop completes or a `RETURN` is encountered. Under certain circumstances, this information can be left behind. If this occurs, the next loop or subroutine may not operate properly.

The most common cause of this problem is branching out of a loop or subroutine without calling the appropriate statement to complete it. For instance:

    10 GOSUB 1000
    20 PRINT A
    20 PRINT B
    40 END
    1000 A=5
    1010 GOSUB 2000
    1020 RETURN
    2000 B=6
    2010 IF A=5 THEN 1020
    2020 RETURN

In this example, the first `GOSUB` on line 10 puts an item on the stack saying the program should return to the next statement, in this case, line 20. When it enters the subroutine at line 1000, it sets the value of A and then calls another subroutine at line 2000 and puts the new return location on the stack, line 1020. However, the second subroutine exits before calling `RETURN`, leaving behind the entry that says it should return to 1020. When the `RETURN` on 1020 is called, it returns to line 1020, not 20, and removes that entry. It then continues, falling into the second subroutine again, eventually reaching line 2020 and then returning to line 20. Depending on the order of operations and the sequence of calls, the result will be that the code does not follow the expected flow, or you may get an error about "NEXT without FOR" or "RETURN without GOSUB".

`POP` is intended to correct these situations by removing the last entry on the stack when the program knows it needs to break out of the normal flow. In the example above, the expected behavior is being upset on line 2010. This can be addressed by modifying that line to read:

    2010 IF A=5 THEN POP:GOTO 1020

The `POP` will remove the last entry on the stack, the dangling subroutine call, and then GOTO to code on 1020 and return to the correct location.

#### See also:

* `EXIT`

<!-- TOC --><a name="exit"></a>
### `EXIT`

`EXIT` works in a fashion similar to `POP`, removing entries from the runtime stack when normal program flow is being interrupted. The difference is that `EXIT` examines the stack and continues removing items until it finds the correct entry, whereas `POP` always removes the top entry. For instance:

    10 GOSUB 1000
    20 END
    1000 FOR I=1 TO 10
    1010 IF I=5 THEN GOTO 1030
    1020 NEXT I
    1030 RETURN

In this example, there are two entries on the stack during the execution of the subroutine, one for the subroutine call, and another for the FOR..NEXT loop. When I=5, the loop will exit early, leaving the incomplete loop entry on the stack. In most dialects, the `RETURN` will clear out any entries above the subroutine and therefore clear out the incomplete loop. This is not universal; however, other versions may attempt to return using the topmost entry, the loop, and fail out.

#### See also:

* `POP`

<!-- TOC --><a name="pause-aexp"></a>
### `PAUSE` *aexp*
    
`PAUSE` stops execution of the program for *aexp* 60ths of a second, or *jiffies*.

#### Availability:

1.8.4

<!-- TOC --><a name="label-nvar"></a>
### `LABEL` *nvar*

`LABEL` is an assignment statement, like `LET`, that sets the value of the *nvar* to the current line number. This is intended to be used with branches that may wish to use a variable instead of a numeric constant. If a traditional assignment is used and the target then moves or its line number is changed, the variable will no longer point to the right line of code. Using `LABEL` to set these values ensures the variable always contains the correct value, even if the program is edited.

A number of dialects included a `LABEL`-like feature, but there was no standard syntax for this concept. For example, Atom BASIC had labels that worked in this fashion but were implemented by typing a single letter after the line number on the line to be labeled. Atari BASIC allowed branches to expressions but lacked a `LABEL` concept and was thus subject to errors if the program was edited.

`LABEL` should be considered a RetroBASIC-only feature.

#### Examples:

    10 LABLE T
    20 PRINT "Hello, World!"
    30 GOTO T

#### Availability:

1.8.3

<!-- TOC --><a name="call-system-and-sys"></a>
### `CALL`, `SYSTEM` and `SYS`

`CALL` and `SYSTEM` are two of the common ways that BASIC interpreters allowed machine language code to be called from a BASIC program. This was often used to access operating system routines and sound and graphics commands. `SYS` is a common abbreviation. All three are supported in RetroBASIC, but they perform no action. 

#### See also:

* `USR`

<!-- TOC --><a name="inputoutput-statements"></a>
## Input/Output Statements

This section describes the input/output statements that are used to access and display data.

<!-- TOC --><a name="print-exp"></a>
### `PRINT` [*exp*{|[;|,]},...]]

`PRINT` is used to produce output on the user's console. It is one of the most common statements found in most BASIC programs. The statement is designed to be very flexible, able to output values from any type of expression. In the case of string expressions, the output is sent unchanged to the console. For numeric values, it is formatted to ensure very large or small numbers do not fill the screen.

`PRINT` can accept any number of subsequent expressions, including zero. These expressions are separated with one of the three "print separators", the comma, the semicolon, or if the preceding expression is a string constant, nothing. `PRINT` normally outputs a newline when it completes, so it is not uncommon to see a "bare" `PRINT` statement with no expression as a way to print a newline. The newline is not output if the line ends with a separator, the semicolon or comma. In that case, any following `PRINT` will start on the same line.

A curiosity of the BASIC language is that the question-mark may be used as an alias for the `PRINT` statement. This was intended to allow users to type in "questions" at the command line, for instance, `? 5+5`, meaning "what is 5 plus 5". The interpreter would internally expand the question-mark to `PRINT`, perform the expression, and print the result, in this case 10. As the question-mark is expanded on entry, using it in a program will expand result in `PRINT` appearing in its place when `LIST`ed.

There are a number of oddities and gotchas in common dialects, many of which are not mentioned in most references.

#### Examples:

    PRINT "Hello, World!"

The classic Hello, World! example in BASIC. The interpreter will evaluate the expression, in this case a string constant, and on determining it is a string constant, it is printed as-is. As it is the last statement and there is no separator following, a newline is also printed.

    ? 2+3+4

In this example, the expression is numeric. The value will be calculated, formatted, and output. A newline will be printed as well. This will produce:

     9

It is not easily visible in this example, but there is an additional leading space in front of the value 9. This is part of the formatting rules for numeric values; it leaves room to print a minus sign for negative values. This way, if a series of numbers is printed that may be negative or positive, they will properly line up vertically on the console.

    100 PRINT "The value of X is ";X
    
This statement uses the semicolon to print two separate expressions: the first is a string constant, which is output as normal, and the second a numeric variable whose value is calculated, formatted, and output. In this case the value of X is not set, so the output will be:

    The value of X is  0

In this case the extra space in front of numeric values is more obvious. In the case that one of the values on either side of the semicolon is a string constant, the semicolon can be left off. This code will produce the same output as the example above:

    100 PRINT "The value of X is "X

Semicolons were introduced to BASIC after the original separator, the comma:

    100 PRINT "COMMAS", "ARE", "FOR"
    110 PRINT "COLUMN", "SPACING"

The output from this code will be something like:

    COMMAS   ARE       FOR
    COLUMN   SPACING

The number of spaces between the words is calculated to create a layout where separate lines of text will line up vertically. In contrast, the same code using semicolons as well will result in a more compact layout:

    100 PRINT "COMMAS"; "ARE"; "FOR"
    110 PRINT "COLUMN"; "SPACING"

produces:

    COMMASAREFOR
    COUMNSPACING
    
The column widths for commas vary across platforms, but the most common setting is 10 spaces, which is used by MS BASIC. RetroBASIC defaults to 10, but this can be changed with the `--tabs` command line switch.

#### See also:

* `POS`

<!-- TOC --><a name="input-sexpvarvar"></a>
### `INPUT` [*sexp*{[;|,]}]*var*[,*var*...]

`INPUT` is the primary statement for asking the user for data from the keyboard. When it is encountered in a program, execution stops, and a question-mark prompt, `?`, is displayed on the console to indicate the computer is waiting for input. If the optional *sexp* is included, that text will be printed in front of the question-mark as an additional prompt. The user then enters their response and indicates they are done by pressing the <return> key. The value that they typed in is then processed and assigned to corresponding *var*.

`INPUT` can accept multiple inputs in a single statement, using a comma-separated list of variables. If the variable is numeric, the user may enter the value on its own and press <return>, or they can enter multiple values on a single line by separating the values with commas. If the variable is a string, it only ends at the <return>, and commas input by the user are included in the string. This means it is not possible to enter multiple string values on a single line. In either case, if the user types in fewer values than there are variables in the statement, another question-mark prompt will be displayed, and the process will repeat until a value has been received for each *var*.

Some dialects allow prompt strings in front of every input *var*, and RetroBASIC supports this option.

#### Examples:

    10 PRINT "Enter five numbers to be summed..."
    20 FOR I=1 TO 5
    30 INPUT "Number",V
    40 T=T+V
    50 NEXT I
    60 PRINT "The total is "T
    70 END

When run, this example will produce the following:

    Enter five numbers to be summed...
    Number?

The user responds by typing a number and pressing <return>. This returns to the top of the `FOR` loop and repeats, so the complete interaction would be something like:

    Enter five numbers to be summed...
    Number? 5
    Number? 3
    Number? 1
    Number? 1
    Number? 7
    The total is 17

Using multiple variables in a single `INPUT` has a similar effect. For instance:

    10 PRINT "Enter three numbers to be summed..."
    20 INPUT "Type three numbers separated by commas "A,B,C
    30 PRINT "The total is "A+B+C

The difference here is the way that the user's input is interpreted. The user can type three values on one line, separated by commas, as noted in the prompt. They can also type a single value and press <return>, which will cause the `INPUT` to display the question mark and continue until all values are provided. In this example, the user types one value per line:

    Enter three numbers to be summed...
    Type three numbers separated by commas 3
    ? 2
    ? 1
    The total is 6

RetroBASIC allows multiple prompt strings in a single statement:

    10 PRINT "Enter three numbers to be summed..."
    20 INPUT "What is value 1 "A,"What is value 2 "B,"What is value 3 "C
    30 PRINT "The total is "A+B+C
    
#### Notes:

Although the question-mark prompt is almost universal, Tiny BASIC uses the colon, `:` in its place. Other dialects allow the question-mark to be suppressed, but there is no standard for this feature.

<!-- TOC --><a name="data-concon-read-varvar-and-restore-linenoaexp"></a>
### `DATA` *con*[,*con*...], `READ` *var*[,*var*] and `RESTORE` [{*lineno*!*aexp*}]

Early versions of Dartmouth BASIC lacked the ability to work with data files, which made it difficult to store data for use in a program. While one could implement this using many assignment statements, this made the code difficult to understand. To solve this problem, the `DATA` statement was introduced. `DATA` is followed by a comma-separated list of constants, either strings or numbers. There can be any number of `DATA` statements in a program and any number of values per statement, up to the maximum line length on that platform.

When the program first encounters a `READ` statement, it searches through the program for the first `DATA` statement and sets a pointer to the first value in it. The value at the pointer is then read into the associated *var*. One or more variables can be read in a single `READ`, with the variables separated by commas like an `INPUT` statement. As each variable is read, the pointer is moved forward one location in the list of values. This process continues across statements and lines until it reaches the last value in the last `DATA` statement in the program, at which point any further `READ`s will cause an error.

`RESTORE` is used to reset the pointer to the start of the list or to the first data element on a particular line indicated by an optional line number or numeric expression. Some dialects, notably Wang BASIC, interpreted the optional number not as a line number but an ordinal, such that `RESTORE 10` would set the pointer to the 10th element in the `DATA`. As there is no way to tell which is which, RetroBASIC always interprets the value as a line number, which is far more common.

#### Examples:

    10 FOR N=1 TO 2
    20 READ A
    30 RESTORE
    40 READ B
    50 M=A+B
    60 PRINT "Total is ";M
    70 NEXT N
    80 END
    90 DATA 30,15
    
This program will print two totals at the console. The first time through A and B will both be 30, due to the `RESTORE`, so the total will be 60. On the second pass, the pointer will start at the second value, 15, and the `RESTORE` moves it back, so in this case, A will be 15 and B will be 30, and the total will be 45.

<!-- TOC --><a name="other-statements"></a>
## Other statements

<!-- TOC --><a name="randomize-aexp"></a>
### `RANDOMIZE` [*aexp*]

On older dialects of BASIC, random numbers returned by the `RND` function are based on an internal mathematical function that produces a new value based on the last one. When a program is first `RUN`, the first number in the sequence is normally zero, and thus every time the program is run, it will produce the same series of values. For a program that is using `RND`, this is generally the opposite of what is desired.

To address this problem, most such dialects also include the `RANDOMIZE` statement. When used alone, with no *aexp*, this uses a platform-specific solution to generate a new starting number, the *seed*, so it is not zero. Thus, every time the program is run, it will produce a different series of numbers with `RND`, which is what is desired.

Although `RANDOMIZE` is generally used to produce random seeds, it is also extremely useful during testing and debugging, where the opposite is desired. In this case, using the optional *aexp* will cause the same series of numbers to be returned every time, which makes it much easier to track down problems without the behavior of the program changing every time. In these cases, `RANDOMIZE 0` is very common.

Later dialects, those developed for home computers, often lack the `RANDOMIZE` statement. Instead, they generate random numbers by applying a simple formula to some internal hardware value, normally a timer on the video circuitry. This makes the system very simple to implement, it runs quickly, and there is no need to `RANDOMIZE` as even the shortest delays when `RUN`ning the program will be sufficient to produce complete random values.

#### Notes:

GW-BASIC has the additional oddity that if the *aexp* is left out, it will pause and ask the user for a seed value similar to an `INPUT` statement. To get the same behavior as other dialects, where it uses the clock as a seed, one uses the `RANDOMIZE TIMER` variation, which is not (currently) supported in RetroBASIC.

Because `RANDOMIZE` is so useful for debugging and many programs do not include the statement, RetroBASIC also allows the seed to be set on the command line using the `--random` switch. This allows you to set the seed without modifying the original program.

#### See:

* `RND`

<!-- TOC --><a name="change-avarsvar-to-svaravar-convert-avarsvar-to-svaravar"></a>
### `CHANGE` {*avar*|*svar*} TO {*svar*|*avar*}, `CONVERT` {*avar*|*svar*} TO {*svar*|*avar*}

The primary difference between the three main families of BASIC is the way they manipulate strings. In Dartmouth versions, this is accomplished with the `CHANGE` command, which takes a string and converts it a series of ASCII values in a numeric array, or takes an array and converts it to a string. The length of the string is stored in the array's zero slot. `CONVERT` is the identical operation found in HP dialects.

#### Examples:

    10 DIM X$(10)
    20 X$="SYSTEM"
    30 CHANGE X$ to X
    40 PRINT"The ASCII codes for `SYSTEM` are:"
    50 FOR I=1 TO X(0)
    60 PRINT X(I);",";
    70 NEXT I
    80 END

<!-- TOC --><a name="operators"></a>
## Operators

<!-- TOC --><a name="mathematical-operators-arithmetic"></a>
### Mathematical operators (arithmetic)

RetroBASIC supports the standard set of arithmetic operators: `+` for addition, `-` for subtraction, `*` for multiplication, `/` for division, and `^` for exponentiation. It also supports the alternative `**` for exponentiation, which is seen in some older dialects. The `MOD` operator returns the remainder of the integer division, so that `A = 7.5 MOD 2.5` becomes 7 MOD 2, producing 1.

<!-- TOC --><a name="logical-operators"></a>
### Logical operators

RetroBASIC supports the standard set of logical operators: `=`, `>`, `<`, `<=`, `>=` and `<>` for not-equals. It also supports the HP-style `#` which is the equivalent to `<>`, as well as the seldom-seen `=>` and `=<` variations. It also supports logical `NOT`, `AND`, `OR` and `XOR`.

<!-- TOC --><a name="string-operators"></a>
### String operators

RetroBASIC supports only two string operators, `+` and `&`, both of which perform the same operation, string concatenation. A new string is constructed that consists of the string on the right placed on the right end of the string on the left.

String logical operators are the same as the mathematical ones: `=`, `>`, `<`, `<=`, `>=`, `<>` `#`, `=>` and `=<`.

<!-- TOC --><a name="mathematical-functions"></a>
## Mathematical functions

<!-- TOC --><a name="absaexp"></a>
### `ABS`(*aexp*)

Returns the absolute value of a number without regard to whether it is positive or negative. The returned value is always positive.

<!-- TOC --><a name="clogaexp"></a>
### `CLOG`(*aexp*)

Returns the logarithm to the base 10 of the variable or expression in parentheses. CLOG(0) gives an error, and CLOG(1)equals 0.

<!-- TOC --><a name="expaexp"></a>
### `EXP`(*aexp*)

Returns the value of *e* (approximately 2.71828283), raised to the power specified by the expression in parentheses. For instance, `EXP(3)`, returns is 20.0855365.

<!-- TOC --><a name="fixaexp"></a>
### `FIX`(*aexp*)

Removes any fractional part from the value of *aexp* and returns the resulting integer value. This is similar to C's `trunc` function, and is *not* equivalent to `INT`, which always rounds down. `FIX(-3.445)` will return -3, `INT(-3.445)` returns -4.

#### See also:

* `FRAC`
* `INT`

<!-- TOC --><a name="fracaexp"></a>
### `FRAC`(*aexp*)

Returns the fractional part of the value of *aexp*. `FRAC(-3.445)` returns 0.445.

#### See also:

* `FIX`
* `INT`

<!-- TOC --><a name="intaexp"></a>
### `INT`(*aexp*)

Returns the greatest integer less than or equal to the value of the expression. This is true whether the expression evaluates to a positive or negative number. Thus, `INT(3.445)` returns 3, while `INT(-3.445)` returns -4. This function is similar to the `floor` function found in most dialects.

A few dialects, notably earlier versions of Dartmouth and some later dialects like Benton Harbor BASIC, truncate the fractional part instead of performing a floor. On those versions, `INT(-3.445)` returns -3. One particularly common piece of code found in many BASIC programs is something like `INT(X+0.5)`, which is used to round a value. In these dialects, the rounding will be incorrect for negative numbers; for instance, `INT(-3.445+0.5)` will evaluate the interior to -2.945 and then truncate that to -2. In contrast, in most dialects, that will produce -3, which is the proper answer in this case.

RetroBASIC currently implements `INT` only as a `floor`, and users should be aware of this when using programs from these (rare) dialects.

#### See also:

* `FIX`
* `FRAC`

<!-- TOC --><a name="logaexp"></a>
### `LOG`(*aexp*)

Returns the natural logarithm of the number or expression. `LOG(0)` gives an error, and `LOG(1)` equals 0.

<!-- TOC --><a name="pidexp"></a>
### `PI`[(*dexp*)]

Returns the value of pi, 3.1415... The (*dexp*) is optional; `A=PI` and `A=PI()` are both accepted.

<!-- TOC --><a name="roundaexpaexp"></a>
### `ROUND`(*aexp*[,*aexp])

Rounds the number to the nearest integer or decimal place. If only one *aexp* is provided, that number is rounded to the *zeroth decimal*, that is, a whole number. So `ROUND(1.234)` will return 1. If two *aexp*s are provided, the first is rounded to the second decimal place. So `ROUND(1.2345,3)` will return 1.235.

<!-- TOC --><a name="rndaexp"></a>
### `RND`(*aexp*)

Returns a random positive number between 0 and 0.999... The variable or expression in parentheses following RND is a dummy and has no effect on the numbers returned. Some dialects require an expression in the parentheses; some do not. RetroBASIC works with both.

`RND` is very common in BASIC programs, especially in games. In most cases, the program actually desires an integer value, and code to the effect of `INT(RND(0)*X+0.5)` that produces an integer between 0 and X is very common. It is so common that many programs use a user-defined function to make references to this sequence of operations shorter; an example is Super Star Trek which defines a function called `FNR` near the top of the program and then calls it from many locations.

Because this series of operations takes some time to complete, a number of dialects offer a simple way to generate integer values directly. Unfortunately, there is no standard solution for this operation. Some use a separate function like `RAND` for this, while others modify `RND` instead. Among those that use `RND`, one common solution is that 0 and 1 return a floating point value as above, whereas other positive values produce a value from 1 to the provided number.

#### See:

* `RANDOMIZE`

<!-- TOC --><a name="sgnaexp"></a>
### `SGN`(*aexp*)

Returns a — 1 if *aexp* evaluates to a negative number, a 0 if *aexp* evaluates to 0, or a 1 if *aexp* evaluates to a positive number.

<!-- TOC --><a name="sqraexp"></a>
### `SQR`(*aexp*)

Returns the square root of the *aexp* which must be positive. If *aexp* is negative, an error will be raised.

<!-- TOC --><a name="uboundavaraexp-and-lboundavaraexp"></a>
### `UBOUND`(*avar*{,*aexp*}) and `LBOUND`(*avar*{,*aexp*})

Returns the upper and lower bounds of the array in *avar*, respectively. In RetroBASIC, the lower bound is always zero, and the upper bound is the value in the associated `DIM` statement. If the variable was not `DIM`ensioned, `UBOUND` will return 10. For multi-dimensional arrays, the optional *aexp* indicates which dimension to count, starting at one. If *aexp* is not included and the array is multi-dimensional, they return the values for the first dimension.

#### Examples:

    10 DIM A(25,10)
    20 PRINT "The length of dimension 1 is "UBOUND(A)
    30 PRINT "The length of dimension 2 is "UBOUND(A,2)

Produces:

        The length of dimension 1 is 25
        The length of dimension 2 is 10

<!-- TOC --><a name="numeric-string-functions"></a>
## Numeric string functions

BASIC interpreters display and input numbers in decimal format. In many programs, especially on home computers, it is more convenient to store values in other formats, like hexadecimal or binary. RetroBASIC includes a number of functions to convert to and from these formats.

RetroBASIC also allows binary, octal, and hexadecimal values to be typed in directly as constants, using the 0b, 0o and 0h prefixes, respectively, as well as & for hexadecimal. For instance, 0b10101010 represents the decimal value 170 entered as a binary constant. These are particularly useful when entering bit-oriented values like masks for fonts and sprites.

<!-- TOC --><a name="binsexp-and-binaexp"></a>
### `BIN`(*sexp*) and `BIN$`(*aexp*)

`BIN` converts a string containing binary digits, 1's and 0's, into the corresponding decimal value. `BIN$` converts a decimal number to a binary string.

#### Examples:

    10 PRINT "Convert bin 101010 to number, should print 42: ";BIN("101010")
    20 PRINT "Convert 55 to bin, should print 110111: ";BIN$(55)
    
<!-- TOC --><a name="octsexp-and-octaexp"></a>
### `OCT`(*sexp*) and `OCT$`(*aexp*)

`OCT` converts a string containing octal digits, 0 through 7, into the corresponding decimal value. `OCT` converts a decimal number to an octal string.

#### Examples:

    10 PRINT "Convert oct 7654 to number, should print 4012: ";OCT("7654")
    20 PRINT "Convert 4321 to oct, should print 10341: ";OCT$(4321)

<!-- TOC --><a name="hexsexp-and-hexaexp"></a>
### `HEX`(*sexp*) and `HEX$`(*aexp*)

`HEX` converts a string containing octal digits, 0 through F, into the corresponding decimal value. `HEX` converts a decimal number to an hexadecimal string.

#### Examples:

    10 PRINT "Convert hex FFFE to number, should print 65534: ";HEX("FFFE")
    20 PRINT "Convert 5432 to hex, should print 1538: ";HEX$(5432)

<!-- TOC --><a name="trigonometric-functions"></a>
## Trigonometric functions

Trigonometric functions in BASIC are normally carried out using radians. A few dialects have a feature to switch to degrees, but this is not currently supported in RetroBASIC.

<!-- TOC --><a name="acsaexp"></a>
### `ACS`(*aexp*)

Returns the arccosine of the variable or expression in parentheses.

<!-- TOC --><a name="asnaexp"></a>
### `ASN`(*aexp*)

Returns the arcsine of the variable or expression in parentheses.

<!-- TOC --><a name="atnaexp"></a>
### `ATN`(*aexp*)

Returns the arctangent of the variable or expression in parentheses.

<!-- TOC --><a name="cshaexp-and-coshaexp"></a>
### `CSH`(*aexp*) and `COSH`(*aexp*)

Returns the hyperbolic cosine of the expression in parentheses.

<!-- TOC --><a name="cosaexp"></a>
### `COS`(*aexp*)

Returns the cosine of the expression in parentheses.

<!-- TOC --><a name="cshaexp-and-coshaexp-1"></a>
### `CSH`(*aexp*) and `COSH`(*aexp*)

Returns the hyperbolic cosine of the expression in parentheses.

<!-- TOC --><a name="sinaexp"></a>
### `SIN`(*aexp*)

Returns the sine of the expression in parentheses.

<!-- TOC --><a name="snhaexp-and-sinhaexp"></a>
### `SNH`(*aexp*) and `SINH`(*aexp*)

Returns the hyperbolic sine of the expression in parentheses.

<!-- TOC --><a name="tanaexp"></a>
### `TAN`(*aexp*)

Returns the tangent of the expression in parentheses.

<!-- TOC --><a name="tnhaexp-and-tanhaexp"></a>
### ``TNH`(*aexp*) and TANH`(*aexp*)

Returns the hyperbolic tangent of the expression in parentheses.

<!-- TOC --><a name="string-functions"></a>
## String functions

<!-- TOC --><a name="ascsexp"></a>
### `ASC`(*sexp*)

This function returns the ASCII code number for the first character of the string expression *sexp*. For instance, `ASC("Hello")` returns 72, the decimal ASCII value for "H".

<!-- TOC --><a name="chraexp"></a>
### `CHR$`(*aexp*)

Returns the character as a single-character string, represented by the ASCII code number in parentheses. `CHR$(72)` returns "H".

<!-- TOC --><a name="inkeydexp"></a>
### `INKEY$`(*dexp*)

This function returns the ASCII value of the key currently pressed on the keyboard. If no key is pressed when it is called, it returns 0. In either case, it immediately continues without waiting for user input, unlike `INPUT` or `GET`. `INKEY$` was a later addition to BASIC and mostly found in interactive programs and games. The parameter is a dummy and can be left out, along with the parens.

<!-- TOC --><a name="lensexp"></a>
### `LEN`(*sexp*)

This function returns the length in bytes of the designated *sexp*. `LEN("Hello")` returns 5. String variables have a length of zero until characters have been stored in them.

<!-- TOC --><a name="straexp"></a>
### `STR$`(*aexp*)

This function returns a string that represents the ASCII representation of the number in *aexp*. For instance, if the *aexp* evaluates to 25, this function returns the string "25".

<!-- TOC --><a name="valsexp"></a>
### `VAL`(*sexp*)

This function returns a number of the same value as the number stored as a string, performing the opposite operation of the `STR$` function. For instance, if *sexp* evaluates to "25", this function will return the numerical value 25.


<!-- TOC --><a name="ucasesexp-and-lcasesexp"></a>
### `UCASE$`(*sexp*) and `LCASE$`(*sexp*)

`UCASE$` and `LCASE$` convert a string to upper case or lower case, respectively, and return the new string. The original string in *sexp* is unchanged.

#### Examples:

    PRINT UCASE$("hello world"),LCASE$("Hello World")

Produces:

    HELLO WORLD         hello world

<!-- TOC --><a name="system-functions"></a>
## System functions

<!-- TOC --><a name="fredexp"></a>
### `FRE`(*dexp*)

This function returns the number of bytes of user RAM left. Its primary use is to check the amount of memory left before performing operations that require a large amount of memory.

<!-- TOC --><a name="posaexp"></a>
### `POS`(*aexp*)

When POS is called with zero or one dummy parameter, it returns the current position of the cursor. This can be called after `PRINT` and `INPUT` statements to provide more control over output. When called with more parameters, it acts as an alias for `INSTR`, and is covered in the string functions section.

<!-- TOC --><a name="peekaexp"></a>
### `PEEK`(*aexp*)

Returns the contents of a specified memory address location *aexp*. The address specified must be an integer or an arithmetic expression that evaluates to an integer between 0 and 65535 and represents the memory address in decimal notation (not hexadecimal). The number returned will also be a decimal integer with a range from 0 to 255.

In RetroBASIC, `PEEK` always returns zero.

<!-- TOC --><a name="usraexp"></a>
### `USR`(*aexp*)

`USR` is the other common method that BASIC interpreters used to call machine language code, the other being `CALL` and `SYSTEM`. The difference between `CALL` and `USR` is that `USR` expects a return value to be left in a particular location in memory, and the function returns that value.

In RetroBASIC, `USR` always returns zero.

<!-- TOC --><a name="linaexp"></a>
### `LIN`(*aexp*)

`LIN` produces *aexp* newlines in the output. The exact nature of `LIN` varies across platforms. On HP systems it is a standalone statement, whereas others treat it as a pseudo-function like `TAB`. RetroBASIC treats it as a true function that returns a string, means it has to be placed in `PRINT` statements to produce output.

#### Examples:

    PRINT LIN(3);"Hello"

Produces:




    Hello


<!-- TOC --><a name="spcaexp-spaaexp-and-spaceaexp"></a>
### `SPC`(*aexp*), SPA(*aexp*) and SPACE$(*aexp*)

`SPC` returns a string containing the number of space characters in *aexp*. `SPA` is the alternate spelling for the same function found in HP, while `SPACE$` is found in other dialects.

#### Examples:

    PRINT SPC(10);"Hello"

Produces:

              Hello

<!-- TOC --><a name="stringsexpaexpaexp"></a>
### `STRING$`([*sexp*|*aexp*],*aexp*)

`STRING$` makes a new string containing *aexp* copies of the first parameter. The first parameter can be any string if it is provided as *sexp*, or it can be a single ASCII value if it is an *aexp*. `STRING$` can be used to provide the same functionality as `SPC` if *sexp* contains a single space or *aexp*.

#### Examples:

    PRINT STRING$("Hello", 3)

Produces:

    HelloHelloHello

<!-- TOC --><a name="tabaexp"></a>
### `TAB`(*aexp*)

`TAB` is a pseudo-function, normally used only in `PRINT` statements. In most dialects, it does not return a value; instead, it advances the cursor to the column given by *aexp*. This is used to line up output in tabular format. In RetroBASIC, `TAB` *does* return a string, one containing enough spaces to advance from the current `POS` to the indicated column.

<!-- TOC --><a name="timedexp-and-timeaexp"></a>
### `TIME`{(*dexp*)} and `TIME=`*aexp*

Returns the real-time clock's time value in jiffies, 1/60ths of a second. `TIME` is a pseudo-variable that allows the clock to be set by assigning a value to it. This allows, for instance, portions of a program to be timed by setting `TIME=0` and then `PRINT TIME` later in the code, as `TIME` will now hold the elapsed time. As `TIME` is treated as a variable, only the first two letters of the name are actually read, meaning `PRINT TIME` and `PRINT TI` are identical code internally.

#### Examples:

    10 PRINT "This code will time a loop to 10000"
    20 TI=0
    30 FOR I=1 TO 10000
    40 NEXT I
    50 PRINT "Elapsed time is "TI

<!-- TOC --><a name="timedexp-and-clk"></a>
### `TIME$`(*dexp*) and `CLK$`

Returns the real-time clock's time value formatted for printing. In RetroBASIC this is in numeric hours-minutes-seconds format. `CLK$` is the alternative spelling found on Univac systems.

#### Examples:

    PRINT TIME$()

Produces:

    102456
