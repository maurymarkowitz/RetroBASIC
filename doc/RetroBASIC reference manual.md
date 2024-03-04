RetroBASIC Reference Manual
===========================

**Copyright © 2023 Maury Markowitz**

Version 1.9.1

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
   * [`FOR` *avar*=*aexpr1* `TO` *aexpr2* [`STEP` *aexpr3*] {:|}<CR>} [*statmnt*,{:|}<CR>}...] and `NEXT` [*avar*,[*avar*,...]]](#for-avaraexpr1-to-aexpr2-step-aexpr3-statmnt-and-next-avaravar)
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
   * [`ROUND`(*aexp*[,*aexp*])](#roundaexpaexp)
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
   * [`TNH`(*aexp*) and `TANH`(*aexp*)](#tnhaexp-and-tanhaexp)
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
   * [`LIN`(*aexp*)](#linaexp)
   * [`SPC`(*aexp*), `SPA`(*aexp*) and `SPACE$`(*aexp*)](#spcaexp-spaaexp-and-spaceaexp)
   * [`STRING$`(*aexp*,[*sexp*|*aexp*])(#stringsexpaexpaexp)
   * [`TAB`(*aexp*)](#tabaexp)
   * [`TIME`{(*dexp*)} and `TIME=`*aexp*](#timedexp-and-timeaexp)
   * [`TIME$`(*dexp*) and `CLK$`](#timedexp-and-clk)
   * [`TIME$`(*dexp*) and `CLK$`](#timedexp-and-clk)
   * [`USR`(*aexp*)](#usraexp)

<!-- TOC --><a name="about-this-manual"></a>
## About this manual

This manual is primarily a listing of the operators, commands and statements in the RetroBASIC interpreter. It also details some of the internal structures and differences between dialects of BASIC. It is written in Markdown to make it readable on most platforms.

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

- monospaced `CAPITAL LETTERS` will be used to indicate keywords
- *italicized* lowercase words indicate an abbreviation from the list above
- [square brackets] indicate optional items separated by commas
- {curly braces} indicate "one of" options separated by the vertical bar
- \<angle brackets\> indicate special characters like a carriage return
- the ellipsis... indicates "and more of same", normally in option lists

For example:

`PRINT` [*exp*{|[;|,]},...]]

This indicates that the PRINT statement consists of the statement keyword `PRINT` followed by zero or more optional expressions separated by nothing, a semicolon, or a comma. The *exp* indicates that any expression type may be used, numeric or string.

Note that the line number is not indicated at the front, nor are the <CR> or <Enter> at the end, as these are assumed to be in the source code.

<!-- TOC --><a name="introduction"></a>
## Introduction

<!-- TOC --><a name="what-is-retrobasic"></a>
### What is RetroBASIC?

RetroBASIC is a multi-lingual version of the BASIC programming language intended to run classic BASIC programs written from the 1960s into the 1980s. It includes most features from three main families of BASIC:

- Dartmouth BASIC Version 4
- HP Timeshared BASIC
- DEC BASIC-PLUS and its better-known offshoot, Microsoft BASIC

While most BASIC dialects take their basic syntax and keywords from the original Dartmouth BASIC, they began to diverge in the late 1960s into these three general families. The goal of RetroBASIC is to run any program written for these dialects and their many offshoots.

So, for instance, RetroBASIC can run the version of Super Star Trek found in *BASIC Computer Games*, written in Microsoft BASIC and likely one of the most widely-ported games in history. But it can also run the (non-Super) Star Trek found in the earlier *101 BASIC Games*, written for DEC BASIC. It can also run most programs from *What to do After You Hit Return*, which are written in HP's dialect. Practically any major program should run properly without conversion.

Programs must be provided in plain text, better known as "source code". RetroBASIC cannot read binary files from other platforms, which was the normal way to store BASIC programs on home computers. There are a variety of programs available that will read these binary files and output text, which can then be run in RetroBASIC.

<!-- TOC --><a name="what-retrobasic-is-not"></a>
### What RetroBASIC is not

The goal of RetroBASIC is to allow you to run popular BASIC programs written during the language's Golden Age. As such, it is also marked by a number of deliberate limitations:

- the language is intended to *run* programs, not *edit* them, and it thus lacks an interactive editor
- you cannot `LIST` a program, `LOAD` or `SAVE` it
- it does not include any platform-specific instructions like sound or graphics, as these are not portable
- it does not (currently) have file handling features, as these vary considerably across platforms

<!-- TOC --><a name="some-underlying-concepts"></a>
## Some underlying concepts

Programming languages, in general, use English language words and common mathematical symbols to describe a number of instructions that will be carried out in order to produce a desired result. This textual description is known as the *source code*. These instructions have to be converted into an internal format that the computer understands, as opposed to the english-like source code which is designed to be understood by the programmer. RetroBASIC performs this conversion. The result of the conversion is the *machine code* or *p-code* depending on how the system works. This internal language can then be *executed*, or in BASIC lingo, *run*.

Like most computer languages, BASIC has a number of **keywords** that are reserved by the language. In BASIC, the list of keywords is normally fixed, meaning that users cannot add new keywords or modify the actions of existing ones. This contrasts with programming languages like ALGOL which were based around the idea of creating new keywords in code. As new keywords cannot be created in most BASIC dialects, BASIC tends to have many more reserved keywords than other languages in order to ensure the functionality you need is present.

In BASIC, the series of instructions that makes up the program are known as **statements**. A statement consists of a keyword and then zero or more **expressions**. Only certain keywords can appear at the front of a statement, others only as part of an expression. To confuse matters, the subset of keywords that can appear at the front are often referred to as "statements" as well, while other dialects refer to these special keywords simply as "keywords". To avoid confusion, this manual will use the term **statement keywords** for this subset of reserved words and to clearly separate the concept of a statement from a keyword.

In most dialects, a subset of the statement keywords can only be used in certain circumstances and are known as **commands**. Commands *are* statements, and both commands and statement keywords can be used *in* statements.

The purpose of an **expression** is to provide data to be acted on by the statements. There are many different types of expressions and much of a program's complexity is found within them. The primary types of expressions are classified by type:

- **number** - such as 10 or -1.75. Also known as **numeric constants**.
- **string** - a series of characters surrounded by double-quote marks, like "Hello, World!". Also known as **string constants**.
- **variable** - a symbolic name which can store the value of a number or a string for future recall.
- **array** - a type of variable that stores multiple values at once.
- **operator** - symbol characters, typically from mathematics, that take one or two expressions and produce a number or string.
- **function** - operators using names instead of symbols.

In most dialects, variables can contain either a number value or a string value but cannot change from one to another. This split was introduced in Dartmouth BASIC, which required the user to add a dollar sign suffix to variables that wanted to hold a string value. These are known as **string variables**, and non-string variables are sometimes, but not always, referred to as **numeric variables**. A few dialects allow any variable to store any value, and these generally lack the dollar sign. This is not supported in RetroBASIC, because most dialects consider assigning one to the other to be an error, and RetroBASIC needs to report these.

BASIC programs are generally organized over multiple **lines**, each of which contains one or more statements. A line starts with a **line number**, which acts as a label so other parts of the program can refer to it, as well as a way for various editing tools to allow the user to indicate which lines they wish to edit. After the line number, there is a statement keyword and then any expressions that keyword may use, forming a complete statement. Lines may have more than one statement separated by colons or backslashes, depending on the dialect. Execution normally starts with the first statement on the lowest-numbered line, and then continues statement by statement until it reaches the end of the program. Some statements can change this normally linear progression; these are known as **branches**.

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

Line 10 of this program uses the `LET` statement keyword to assign a value to the numeric variable `A`, using the operator `=` to separate the variable name from the expression that provides a value. In this case, the associated **numeric expression** is the numeric constant 10. The assignment statement is almost always the most common statement in a BASIC program, and for this reason, most versions of BASIC allow the `LET` keyword to be left out. This produces an exception to the rule that statements start with a statement keyword; they can actually start with a statement keyword *or* a variable name.

Line 20 of this program is also an assignment statement, leaving off the optional `LET`. Notice the dollar sign on the variable name that indicates that the language should expect a string expression on the other side of the `=` operator, not a number. The expression used in this statement is the string constant "Hello".

Line 30 is an example of a multi-statement line, with two statements separated by a colon. The first statement is an assignment using the addition operator with the value stored in `A` and the numeric constant 5 as the inputs. This will have the effect of assigning the resulting value 15 to the variable `C`. The second statement on this line is a print statement, another very common statement in most programs. This will evaluate the expression, returning the numerical value 15, and then print that value to the user's console.

Line 40 shows an example of *overloading*, where a keyword may mean different things depending on the context. The expression in the print statement has the `+` operator but is being given **string expressions** instead of numeric. In this case, the `+` does not represent numeric addition but string concatenation, which places the right-hand string at the end of the left-hand string and returns a new, longer string. The result of this print statement is "Hello, World!" being printed to the console.

Line 50 is an example of a logical comparison, which is indicated by the `IF` statement keyword. This is followed by a **logical expression** using the larger-than operator, which calculates the results of expressions on both sides of the operator, compares them, and then, depending on the outcome of the comparison, optionally performs the statement following the `THEN`. As `C` will hold the value 15 at this point, and 15 is larger than 10, the statement after `THEN` *will* be performed and produce the string "C is > 10" on the console.

Line 60 is the `END` statement, which takes no expression and stops the execution of the program. `END` is optional in most dialects.

<!-- TOC --><a name="data-in-basic-programs"></a>
## Data in BASIC programs

The ultimate goal of any program is to manipulate data. In BASIC there are two forms of data: numbers and text, the latter more widely known as *strings*. Most BASIC dialects have similar concepts of what numbers can be represented as and how to manipulate them. BASICs vary much more widely in the way they store and process strings. RetroBASIC attempts to support as many varieties of both numbers and strings as possible.

Another key concept in most programming languages is the difference between a *constant* and a *variable*. Constants are data entered directly into the code, for instance, the number `100` or the string `"hello"`. Variables are names that are given to the location in memory where data is stored. As the terminology implies, the value of a variable can be changed, whereas constants cannot.

The types, capabilities and syntax of constants and variables are fairly constant across dialects, although there are a few optional features found in later versions. RetroBASIC attempts to support as many of these variations as possible.

<!-- TOC --><a name="numbers"></a>
### Numbers

Most BASIC interpreters of the RetroBASIC era store numbers using the equivalent of a *single* type, also known as a *float*. Unless otherwise indicated, any variable will default to this type. Thus, the name `I` found in a program would refer to a variable with the name "I" that holds a numeric value, initially zero. The internal format used to store the value was chosen to balance the need to save memory while maximizing precision. Microcomputers generally used 32-bit or 40-bit numeric formats, as larger formats would use up too much of the extremely limited memory available in these machines. Mainframe and minicomputer dialects generally used that platform's "natural" format, whatever that might be.

Some dialects had a second number format, *integer*. Most notable among these are later versions of Microsoft BASIC, so this feature is widely available in home computer dialects, though rarely used. MS used 16-bit values for integers, potentially saving considerable amounts of memory in programs with large numbers of numeric constants. To indicate that a variable should store the value in integer format, the percent sign, `%`, was added to the end of the variable name. So, `I` would store a value in the default format, normally a 40-bit floating point, while `I%` would store the value as a 16-bit integer.

A few dialects also added a *double* format as well, once again led by later Microsoft releases. These were indicated by adding the hash symbol, `#`, to the end of the variable name. In dialects that had doubles, it was common for the default internal format of the single to be smaller than normal and then have the programmer use doubles if more precision was required. For instance, on the Atari Microsoft BASIC, a single was 32 bits instead of the more typical 40, while a double was 64 bits. On most of these dialects, a single-precision value could be explicitly indicated by adding the bang, `!`, to the end of a variable name. As single was the default format for variables, the bang is almost never found in real-world programs.

As memory is no longer an issue, RetroBASIC uses the 64-bit IEEE double format to store all numbers. This does not affect the programs; the extra precision is hidden within the system. The only difference is that when a calculation is stored in a variable, if that variable is declared as an integer, the `INT` operator is applied to the result. In MS versions, the existing floating point code is used and then discards the fractional leftover, which allows them to implement these functions without adding new code to the already memory-limited machines. In some dialects, like BBC BASIC, an entirely separate math library is used for this purpose, which offers higher performance. RetroBASIC carries out all calculations using doubles, as performance and memory footprint are no longer issues.

BASIC inputs and outputs numbers in decimal format, using the same formatting rules as C's "g" format. This means that large numbers and small fractions are output in exponent format, regardless of how they are input. For instance, if the program asks the user to type in a number and they type fifteen ones, when output that value will be rendered something like `1.11111E14`. For those dialects that supported doubles, numeric constants could be set to doubles by changing the E to a D.

RetroBASIC has the additional feature that numeric constants can be entered in hexadecimal, octal or binary format. Hexadecimal values are indicated by placing the prefix `0x`, `0h` or `&` in front of the value, for instance, `&1F3A` will be converted internally to the value 7994. Octal is indicated by `0o`, like `0o3725`, and binary with `0b`, like `0b10110011`. These values can be used in any numeric expression in place of a decimal constant. Like any numeric value, they are converted to doubles internally.

Because the input and output are in decimal, but the internal format is in binary, there are numbers that one can type into the source code cannot be exactly represented internally. This is similar to the lack of a way to exactly represent 1/3 in decimal, which we represent as 0.333... . This number can be exactly represented in base-12, for instance. Generally, different number formats will always have some numbers that cannot be exactly represented.

As a result of the differences between binary and decimal, BASIC programs are subject to "round-off error" that can produce odd results, especially when dealing with fractional values. It is generally suggested that you do not rely on a variable containing a specific value when testing it; instead of `IF X=5`, you should `IF X>=5` in case the value of X rounded up to 5.000111... during a previous calculation. RetroBASIC's double format is not immune to round-off error, although it may be reduced in frequency by the higher-accuracy numbers being used internally.

To avoid round-off errors, some dialects used a different format known as binary code decimal, or BCD, which stores decimal numbers directly. This means that any number one can represent in the source code can be exactly represented in memory. This does not eliminate round-off, one can still perform `A=1/3`, but the cases where this occurs are more obvious to the user. The downside to BCD is that the numbers take up slightly more memory and are generally slower to perform math with. This was a small price in some settings, and those machines intended for business roles like the Wang 2200, used BCD (as do most handheld calculators). Although not unheard of in general-purpose dialects, only Atari BASIC and TI-99 BASIC used this format in widespread use. It was also used in the later MSX dialect. The added precision of the IEEE format used in RetroBASIC makes the use of BCD largely superfluous for its intended uses, most of the cases where round-off would occur in earlier dialects will not result in round-off in RetroBASIC.

<!-- TOC --><a name="strings"></a>
### Strings

Strings hold zero or more characters to form sentence-like values. They are stored in memory as a series of numbers using ASCII encoding, or more commonly, a platform-specific variation of ASCII like PETASCII or ATASCII. The maximum size of a string varies on different platforms. Those that originated on systems with printer terminals are often limited to 72 or 132 characters, the length of one line on paper, while those from the video terminal and home computer era are normally 128 or 256 characters, which is easy to store in an 8-bit value. Some dialects allow strings to be limited only by system memory.

RetroBASIC strings are always variable-length can be any size up to the underlying operating system's limit, typically a 32-bit or 64-bit value. This is much more than any known early dialect of BASIC. So while it is possible that bad code would produce strings that are too long for the machine it was originally written on, causing an error, that same code will likely work fine in RetroBASIC.
 
String constants are normally delimited with double quotes, like `"Hello, World!"`, although some dialects use single-quotes, `'Hello, World!'`, or allow either format. Dialects vary widely in the way that they include quotes inside string constants; the modern solution of placing two double quotes beside each other inside a string, like `"Hello, ""World""!"`, is a later invention. Another curiosity, also seen in the FOCAL language, is that the closing quote can be left off if it is the last character on the line, although this is *rarely* seen in BASIC programs.

The major difference between dialects of BASIC is the way that strings and substrings are manipulated. These vary significantly between the three "families" noted in the introduction. Code that manipulates strings using one of these styles will not run on other variations and will require some level of porting effort to do so.

Dartmouth v4 introduced the `CHANGE` command in V4. This converts a string of characters into a numeric array containing the length of the string in the zero slot and the ASCII values of each character in the rest of the slots in the array. The values were then manipulated numerically, and then `CHANGE`d back into a string. The system was not easy to use for many simple tasks, like concatenation, which required loops and copying values from one array to another. It does have some advantages in certain operations, like converting upper to lower case or back, where the ASCII number is what is being used.

HP BASIC introduced a second system. They included the `CHANGE` command from Dartmouth, but renamed it `CONVERT`. While one might argue this is a better name for this feature, changing it seems to offer little advantage compared to the need to port programs that would otherwise run without change. HP is more notable for its addition of a new method of manipulating strings. This introduces the concept of the *slice*, a pair of numbers that represents a series of continuous characters within the original string. Slices are efficient as they are represented by a pointer to the starting location and a length, it does not copy characters or their ASCII values in memory.

Today, the best-known method of manipulating strings is the version found in MS-derived dialects. This uses the `+` operator for concatenation and the functions `MID$`, `LEFT$` and `RIGHT$` to return substrings. This style of manipulation was originally introduced by Tymshare on their SUPER BASIC, which was then copied by DEC to produce BASIC-PLUS, which was then copied by MS to produce Microsoft BASIC. It is arguably the least efficient method of performing string manipulations and often leads to MS systems running out of memory after performing even a relatively few string operations.
 
When microcomputers were first emerging in the mid-1970s, the programmers on these platforms invariably introduced BASIC (maybe several flavors of) for these machines, and they almost always copied either the MS or HP model for strings, depending on which platform they were most familiar with. Few microcomputer users came from the mainframe world, and the Dartmouth concept was forgotten. Versions based on the DEC/MS or HP models were well represented until about 1978, when the first all-in-one machines like the Commodore PET began to take over the market. These platforms almost always licensed MS's code, which quickly became the *de facto* standard. HP-style strings lived on, primarily on platforms where memory was limited or markets where MS was not so established. Atari and Sinclair are examples of later dialects where slicing was the primary style.

One of the major goals of RetroBASIC was to support programs from any of the older dialects, and for this reason, it supports all of these styles. It includes the entire set of string functions from MS, slicing from HP, and both `CHANGE` and `CONVERT`.

<!-- TOC --><a name="variables"></a>
### Variables

Variables are named references to a location in computer memory holding data. They are a key part of any programming language. In most BASIC dialects, the name can be one or two characters, the first being A to Z and the optional second character A to Z or 0 to 9. This is the case for Microsoft-derived BASICs, and is the standard followed by RetroBASIC. Some dialects allow only one character, and some allow one character and a digit, not two letters. As RetroBASIC allows any two characters, including lowercase, all such variations will run fine. Some dialects allow variable names to be any length, like Atari BASIC, but this is not currently supported in RetroBASIC.

The 1968 version of Dartmouth BASIC introduced string variables. To indicate it held a string, the dollar sign, \$, was added to the end of the name. Because the \$ is part of the name and most dialects only allow for two characters in the name, it is common to have the limitation that string variables can have single-character names. There is also a subtlety to note here; as the \$ is part of the variable name, A and A\$ are two different variables, and both can be used independently in a program. Most subsequent versions of BASIC followed this rule. Tymshare SUPER BASIC was an exception, allowing strings or numbers to be assigned to any variable and not using the \$.

Further confusion was added by the later addition of the `DEF` statements, which allow one or more variables to be given a type without using the suffix characters. For instance, one can `DEFSTR A` to indicate that A is a string variable without needing the \$. A and A\$ will still be different variables, but both will hold strings.

#### Notes:

Most BASIC interpreters store the values of the variables in a table with fixed-width fields. The first two locations in these fields hold the variable's name. When the program refers to the variable in code, the interpreter searches through the table from top to bottom until it finds a field with that name. If it does not find a match, it creates a new entry at the bottom of the table.

This means that every time a variable is encountered, the interpreter has to perform a linear search. As the number of variables in a program grows, this search takes an increasing amount of time and becomes a performance issue in larger programs. For this reason, large programs often have a line near the top of the code that looks something like:

    10 I=0;J=0;K=0;A=0;X=0;Y=0

The purpose of this line is to force these six variables to be at the top of the table and thus be found more rapidly, improving the performance of the program. Typically, the list is ordered, so the most commonly used variable ends up first in the list.

Not all dialects work this way. Compilers, like Dartmouth, hold links directly to each variable's storage in memory and thus do not have to search the table at runtime. A number of interpreters use the same strategy, Atari BASIC being a notable example. In these versions, from a performance standpoint it is as if every variable is at the top of a one-entry list, and while the pre-flighting example above will still run, it offers no additional performance advantage.

<!-- TOC --><a name="arrays"></a>
### Arrays

Most BASIC dialects include the concept of an **array**. An array is a group of related values all referred to by a single variable name. Each value is assigned a **slot** in the array. Arrays need to be defined before use (see exception below) using the `DIM`ension statement. Later in the program, the separate values can be referred to using numbers in parentheses placed after the variable name. These numbers are known as **indexes**. For example:

    10 DIM A(10)
    20 A(1)=5
    30 A(2)=10

This program sets aside eleven locations in memory that can hold numeric values. It then assigns the values 5 and 10 to the first two slots. The rest have not been set, and those slots will contain zeros.

The exact handling of arrays depends on the dialect. Some allow a single dimension, while most allow two, and a small number allow three or more. In those dialects that allow two or more dimensions, single-dimension arrays, like the example above, are sometimes referred to as *vectors*, while those with two are sometimes known as *matrixes*.

RetroBASIC allows any number of dimensions and should properly run code from any of these dialects.

Dialects also vary based on what they consider to be the first entry in the array. Early versions of Dartmouth had slot 1 as the first entry in the array, but this was soon realized to be a mistake as it made it difficult to represent common polynomials, which often have a zeroth entry. Later versions of Dartmouth added a zero to every array to correct for this. Thus, the `DIM` statement above produces an array with 11 entries in it, not 10. Debate over whether to use 0 or 1 for the first slot ran into the 1980s, but this was largely moot as MS variations did include 0 and this was the *de facto* standard, so it is safe to assume 0 is available.

As there is no indication of whether a particular program expects 0 or 1 as the first index, RetroBASIC always sets up a 0 slot just in case. This has (almost) no effect on programs; if they use index 0, it works; if not, it works. The only effect is on the `LBOUND` function, which returns the first index. This normally returns 0, but can be told to return 1 by setting the command-line switch `--array_base=1` if required or using the `OPTION BASE 1` statement within a program. As most dialects did not include the `LBOUND` function, it is unlikely this feature will have any effect one way or another in any real program.

There is another oddity to consider. Dartmouth sets aside a 0...10 block of memory for every numeric variable, even if it is not `DIM`med. In the example program above, A is defined to have 10 slots, and then it assigns values to the first two slots. This program will also work if line 10 is left out, because A will always have 10 slots. This is a *very* odd feature and is rarely implemented in non-MS dialects, so programs relying on this feature will not run on those machines. RetroBASIC does implement this "feature" in case there are programs that use it. To date, none have been found.

Finally, there is the additional oddity that the parens are part of the variable name. That is, the variable `A` is a different variable than the one in `A(0)`. One can assign values to either, and they will be held separately in memory, at least in MS-derived dialects.

To summarize, consider this program following the MS conventions:

    10 A(0)=5
    20 A(1)=10
    30 PRINT A(0);A(1);A

The output of this program is ` 5  10  0`.

<!-- TOC --><a name="commands"></a>
## Commands

Dartmouth BASIC consisted of two separate programs, the BASIC compiler and runtime, and a shell program that edited the source code and performed a small number of commands. The shell commands were deliberately intended to look like BASIC statements. So in Dartmouth, some of the statement-looking lines could be used in your program, while other statement-looking lines could only be used in the shell. This led to the separate concepts of **commands** and **statements**, a separation that many later dialects maintained.

Commands were generally intended to work on the program as a whole, loading or saving the source code, running it, debugging it, etc. Examples include `LOAD` to read source code into memory, `RUN` to execute the program, `LIST` to print the current program to the console, and so forth. Some later dialects allowed these commands to be put into programs as well; for instance, Atari BASIC could `LIST` itself. This blurred the line between statements and commands.

RetroBASIC is intended to be used with known-good BASIC source code, which can be edited in any text editor. It is then loaded and run as part of starting up the program. Thus, there is no need for `LOAD`, `SAVE` or `LIST` as these are accomplished in the editor, and this also eliminates many of the editing statements like `RENUM` and similar. Nor is there a need for `RUN` or `CONT`, as the former occurs automatically and the latter is not needed as one cannot stop the program while it is running. It does, however, include a small number of statement keywords that are normally considered commands in most dialects and are found widely enough in source code to be useful:

<!-- TOC --><a name="bye"></a>
### `BYE`

`BYE` originates with Dartmouth BASIC where it exits the shell and logs the user off of the system. It matched the `HELO` command which performed a login, but `HELO` was not properly part of BASIC itself. Its effect in other dialects was varied; in Atari BASIC for instance, it exits to Memo Pad, while on PCs it would return to DOS. In RetroBASIC, `BYE` simply exits the program in the same fashion as `END`, returning you to the command shell.

#### Variations:

Later IBM PC dialects used `SYSTEM` instead of `BYE`, exiting to the DOS shell.

Some systems allow `GOODBYE` in place of or in addition to `BYE`.

<!-- TOC --><a name="clr-and-clear"></a>
### `CLEAR` and `CLR`

Clears the stored values of all variables and resets the dimensions of all arrays, resets the `DATA` pointer, and clears the runtime stack, thereby resetting all `GOSUB`s and `FOR...NEXT` loops. These same actions are performed when `RUN` is invoked, but `CLEAR` can be called within a program without restarting execution at the top. `CLR` is a common abbreviation, seen primarily in AppleSoft, Commodore and Atari BASIC. This was changed from earlier Microsoft dialects, like BASIC-80, which used `CLEAR`.

Some dialects allow a parameter to be passed to define how much memory to reserve for string storage. Examples included BASIC-80 and TRS-80 Level II. This is not supported in RetroBASIC, which has (effectively) unlimited memory.

#### Variations:

Wang BASIC offers a number of variations on `CLEAR`. Using `CLEAR` by itself performs a `NEW`, erasing the program completely. `CLEAR P` removes all the lines of the program but leaves the variables intact. Line numbers can follow the P, in which case only the range of lines between (and including) those numbers will be removed. This usage matches what most dialects called `DELETE`. `CLEAR V` clears variables, performing the same action as `CLEAR` in other dialects, and `CLEAR N` does the same but only for those variables not previously declared "common". These variations are used to allow one program to call another at runtime, a feature that most dialects that support this implement using the `CHAIN` command.

The TRS-80 allows a single numeric expression as a parameter. If present, it sets aside that amount of memory for storing strings.

Amstrad CPC BASIC offers the `ERASE` variation which is a `CLEAR` that is applied to a list of variables instead of all of them.

BBC BASIC also offers `OLD`, which recovers an accidentally `NEW`ed program. This was required because pressing the system reset key erased the program. On most other dialects that had an `OLD`, like Dartmouth, it was the equivalent of `LOAD`.

<!-- TOC --><a name="cls"></a>
### `CLS`

Clears the screen. On modern machines with scrollback buffers in the console, the scrolled text will likely still be there, as is the case with RetroBASIC running in most console programs.

<!-- TOC --><a name="end"></a>
### `END`

`END` stops the execution of the program and exits RetroBASIC, returning you to the console shell. `END` is optional in most dialects, but adding an `END` was considered good form. `END` does not have to be at the end of the source code, it was often found higher in the code with subroutines below it, preventing them from running unless explicitly called.
    
<!-- TOC --><a name="new-erase-and-scratch"></a>
### `NEW`, `ERASE` and `SCRATCH`

`NEW` clears any existing program and data from memory and prepares to accept a new program to be entered. In RetroBASIC, it simply exits to the shell. `ERASE` and `SCRATCH` are alternative spellings found in some dialects.

#### Variations:

Wang BASIC uses `CLEAR` for this purpose. See notes in that entry.

Sinclair BASIC on the ZX80 allowed a numeric parameter which reserved that amount of memory for BASIC. This allows the program to set aside a portion of memory for storing machine language routines.

Early versions of Microsoft BASIC, like BASIC-80, used `ERASE` to reset a single array variable. This allowed it to be re-`DIM`med, which was otherwise illegal. This was not widely supported in later versions of MS code, and was eventually replaced with the `REDIM` statement.

On the DEC-10 system, `SCRATCH` was used to erase data from a previously `OPEN`ed file, typically to prepare it for writing. On others, like Micropolis BASIC, `SCRATCH` was used to delete files from the disk.
    
<!-- TOC --><a name="run-aexp"></a>
### `RUN` [*aexp*]
    
`RUN` begins processing the in-memory program, if one exists. The optional *aexp* starts execution at a particular line. One can also `GOTO` *aexp* to start execution at a line, the difference is that `RUN` clears the values of all variables and arrays before starting, `GOTO` does not. In RetroBASIC, RUNning occurs automatically, and the `RUN` command does nothing. 

#### Variations:

Many later BASICs allowed either a number or string for the optional expression. If the expression is a string, it is assumed to be a file name and the named program will be loaded and run. In some cases, like Apple Business BASIC, the string does not have to be enclosed in quotes. Some of these dialects also allowed a line number to follow the file name, separated by a comma.

<!-- TOC --><a name="stop-sexp"></a>
### `STOP` [*sexp*]

`STOP` is similar to `END` in that the program stops executing and the user is returned to the shell. It is intended to stop execution in the middle of the program and keep the data intact so the user can `CONT`inue running after it stops. It is mostly used for debugging purposes.

RetroBASIC adds a feature from Wang BASIC, which allows it to output an optional string. This is useful for saying things like "Stopping for debugging, you should PRINT A". If no expression is included, RetroBASIC instead prints the default message "STOPped at line:" along with the line number.

#### Variations:

Harris BASIC-V added the `BREAK` statement, which allowed one to place `STOP` markers in the code in a single statement. For instance, `BREAK 10-50,100` would perform a stop (break) at any line from 10 to 50, or line 100. This is useful as it allows you to easily control debugging without having to edit the entire program, a single statement at the top does the same duty as multiple `STOP` statements spread all over the code. RetroBASIC does not currently support `BREAK`.

<!-- TOC --><a name="unsupported"></a>
### Unsupported

`LIST` and `CONT` are not (currently) supported.

<!-- TOC --><a name="program-statements"></a>
## Program statements

This section explains the statements associated with loops, conditional and unconditional branches, subroutines, and similar functionality. It also explains the means of accessing data and the optional commands used for defining variables. The following list is not in order; it is meant to group statements with similar functionality.

<!-- TOC --><a name="rem-scon"></a>
### {`REM`|`'`|`!`} [*scon*]

`REM`, short for "remark", is used to insert comment text into the program code. Any text on the line after the `REM` is ignored, and execution immediately moves to the next line. RetroBASIC supports the alternative versions, `'` and `!`. The former is widely used in MS-derived BASICs, while the latter, taken from Fortran, is found in some mainframe dialects including later versions of Dartmouth.

#### Examples:

    10 REM This program will print Hello! to the user's console
    20 PRINT "Hello";:REM "World" will not be printed:PRINT "World"
    30 PRINT "!"

<!-- TOC --><a name="let-varexpr"></a>
### [`LET`] *var*=*expr*

The most common statement found in most programs is the assignment statement, with the keyword `LET`. This calculates the value of the expression *expr* and then assigns the result to *var*. The *type* of variable must match the type of expression; numeric expressions cannot be assigned to string variables and vice versa, and attempts to do so will raise a runtime error.

The keyword `LET` was made optional in later versions of Dartmouth BASIC, and most dialects followed this rule. Even after it became optional, a lot of the code written for Dartmouth continued to use the `LET` in order to retain backward-compatibility. This keyword is otherwise rarely used in most dialects.

#### Examples:

    10 LET A=10+10^2
    20 B$="Hello, World!"

Line 10 calculates the value of `10+10^2`, 110, and then copies that value into the numeric variable `A`. Line 20 copies the string constant "Hello, World!" into the string variable `B$`.

<!-- TOC --><a name="dim-varnexp-nexpvarnexp-nexp"></a>
### `DIM` *var*(*nexp*[, *nexp*...])[,*var*(*nexp*[, *nexp*...])...],[*var*(*nexp*[, *nexp*...])[,*var*(*nexp*[, *nexp*...])...]...]

Short for "dimension", `DIM` is used to set up arrays. At least one variable name and associated numeric expression has to be supplied. A variable with one numeric expression produces a one-dimensional array, sometimes referred to as a *vector*, while two-dimensional arrays are sometimes known as a *matrix*. In RetroBASIC, like most dialects, a single `DIM` statement can set up multiple arrays.

Each dimension of an array has a lower bound of zero and an upper bound set to the supplied *nexp*. That means there are more entries in the array than would appear at first glance. For instance, `DIM A(10)` creates an array with 11 entries, while `DIM M(6,3)` creates one with 28 entries.

In those dialects descending from HP, string arrays are actually arrays of single characters. In Atari BASIC, for instance, `DIM A$(100)` is not making an array of 101 strings but a single string with up to 100 characters. In most such dialects, there is no way to make an array of strings, which can make some programs difficult to construct.

#### Examples:

    10 DIM A(100),B(10,10),C$(5)

This dimension statement sets up two arrays: a vector from 0...100, a matrix 0...10,0...10, and a string vector 0...5.

#### Variations:

Some dialects, like Sinclair and TRS-80, allow only a single variable per `DIM`.

Enterprise IS-BASIC allows the `TO` keyword to define the upper and lower limits of the array. For instance, `DIM A(10 TO 20)` defines an array with 11 entries, from 10 to 20 instead of 0 to 10.

<!-- TOC --><a name="goto-and-go-to"></a>
### `GOTO` *aexp* and `GO TO` *aexp*

BASIC progresses through a program by performing statements one at a time, moving to the next statement when one is completed. In this respect, a program can be thought of as a single, long list of statements. This normally linear flow is interrupted by **branches**, statements that deliberately send the execution to another point in the program. In BASIC, branches move to a **target**, which is indicated by a line number.

The simplest form of branch in BASIC is the `GOTO`, or as it was in early versions of Dartmouth BASIC, `GO TO`. `GOTO` always moves to the line number following the statement keyword and is thus also known as an **unconditional branch**. In most dialects, the expression following the keyword must be a number constant, but some allow any valid numeric expression, examples being Tiny BASIC and Atari BASIC.

RetroBASIC supports both forms of the keyword and allows the use of any expression in *aexp* as long as it produces a valid line number. If the line number does not exist, RetroBASIC normally returns an error and stops execution. Some dialects do not cause an error in this case, and instead move to the next valid line. RetroBASIC supports this behavior by turning on the `--goto-next` command line switch.

#### Examples:

    100 PRINT "Hello"
    110 GOTO 200
    120 PRINT " World!"
    200 END
    
This program will print "Hello" to the user's console, as the second print statement, on line 120, will be skipped over by the branch on line 110.

#### See also:

* `LABEL`

<!-- TOC --><a name="gosub-and-return"></a>
### `GOSUB` and `RETURN` [{*lineno*|*aexp*}]

`GOSUB` statements are unconditional branches like a `GOTO`, but differ in that they record the position in the code where they were called. They do this by writing down the location of the `GOSUB` in a special area in memory known as the **runtime stack**, or simply the **stack**. They then branch to the target and continue as normal until they encounter a `RETURN` statement. At that time, they removed the entry on the stack they added earlier, and used the location they found to continue at the statement after the original `GOSUB`.

The name "GOSUB" is a contraction of "go to subroutine". Subroutines are small sub-programs that perform a task and then return. For instance, one might write a subroutine to calculate the value of pi and then call that code repeatedly with different input values from different locations in the code. This allows the calculation code to be isolated, often placed near the bottom of the program to separate it visually, and then called from different parts of the rest of the program.

As the lines of code making up subroutines are normal statements, programs might accidentally run them when they reach the end of the main program code. If this occurs, the `RETURN` at the end of the subroutines will be called without a `GOSUB` and an error will occur. To prevent this, programs generally place their `END` statement immediately before the subroutines, or alternately, place the `END` at a high line number like 9999 and then `GOTO 9999` at the end of the main code.

RetroBASIC also supports the seldom-used option introduced in MSX BASIC that allows a line number to follow the `RETURN` statement. This is exactly equivalent to calling `POP` or `EXIT` followed by a `GOTO.

#### Examples:

    100 GOSUB 500:PRINT 100
    110 END
    500 PRINT 200
    510 RETURN

This program will print "200" and then "100".

#### Variations:

Later versions of MS BASIC, notably MSX and BASIC-A, allow a line number expression in the `RETURN`. This is not (currently) supported in RetroBASIC.

#### Notes:

Many dialects of BASIC will search for a branch target, starting at the top of the program and then looking through the entire source code for the matching line. Normally, subroutines are placed at the end of the program to separate them, often using large line numbers to make this more obvious. However, this also maximizes the amount of time it takes to find the subroutine at runtime and slows performance. For this reason, programs looking to improve performance would sometimes place their subroutine code at the top of the program and then have a `GOTO` to jump past it when the program started. This led to the code being difficult to read.

#### See also:

* `LABEL`
* `POP`
* `EXIT`

#### Availability:

The ability to RETURN to a line number was added in 2.0.0.

<!-- TOC --><a name="if-lexp-then-linestatmntstatmnt"></a>
### `IF` *lexp* `THEN` {*lineno*|*statmnt*[:*statmnt*:...]}

`IF` calculates the value of the logical expression *lexp*, producing zero if it is not true and a non-zero value, typically -1, if it is true. Like an assignment, the *type* of expression, numeric or string, must be the same on either side of the logical operator; otherwise, a runtime error will be raised.

In early versions of Dartmouth BASIC, the only thing that could follow the `THEN` was a line number. This was used to perform a **conditional branch**, similar to a `GOTO` but only branching if the logical expression was true. This made the logic of such programs difficult to follow as they tended to perform many such logical comparisons and branches and thus jump around a lot. This is one of the reasons BASIC was dismissed by programmers like Dijkstra as causing "brain damage" and the common complaint that BASIC always produces "spaghetti code".

This limitation was removed from later versions of Dartmouth, which allow one or more statements of any sort to follow the `THEN`. In the common case where only one statement needs to be performed, placing it after the `THEN`, instead of branching to or around it, can lead to dramatically more readable code. If there is more than one statement after the `THEN`, these are performed all-or-nothing; if the logical expression is true, all of the following statements *on the same line* are performed; if it fails, *none* of them are performed and the program moves to the first statement on the next line. A few memory-limited dialects, notably Sinclair BASIC, lacked the ability to place any statement after `THEN`, and thus followed the original Dartmouth syntax.

This change also leads to the curious syntax that one can still perform the action of `THEN GOTO` to branch to a line without a `GOTO`. This allows the original `THEN` *lineno* style to be used, which was retained for compatibility reasons. A more obvious syntax is to use the `THEN GOTO` *lineno*, but this is never seen in real programs. Some dialects also allow the alternative syntax of a `GOTO` or `GOSUB` without the `THEN`, for instance, `IF X=0 GOTO 100`. RetroBASIC supports all of these options.

Later versions of BASIC generally support an optional `ELSE` clause, which is performed if the *lexp* returns false. RetroBASIC does not (currently) support this feature.

#### Examples:

    IF X=100 THEN 150
    
This statement tests whether the value in the numeric variable X is equal to 100. If it is, execution branches to line 150.
    
    IF A$="BASIC" THEN 200
    
Similar to the example above, but comparing strings instead of numeric values.

    IF X=100 THEN X=0
    
Unlike the previous examples, this version performs a statement instead of a branch. In older dialects lacking this capability, the code would normally be written in this fashion:

    100 IF X<>100 THEN 300
    200 X=0
    300 REM do other things

This ultimately performs the same actions, but can be much more difficult to understand as the logical operator is the opposite of what the code is trying to accomplish, and line 300 may be farther down the program and thus hard to find visually.

    10 IF AA=145 AND BB=1 THEN PRINT AA,BB
    
This example uses a more complex logical expression that combines several types of logical operators. Due to the order of operations, the two equalities will be tested first, and then the values `AND`ed together, producing a single logical value.

In most dialects, *lexp* can be any expression that returns a zero or non-zero value. The logical operators like `>=` return these values. But there is generally no need for an expression if you simply want to test a variable:

    10 IF X THEN PRINT X

This code will print the value of X if it is not zero.

`IF` statements are often used in loops. For instance:

    10 A=9
    20 A=A+1
    30 PRINT A
    40 IF A<20 THEN 20
    
This causes the program to repeatedly add 1 to the current value of A, print the new value, and then start again at line 20. This loop will continue until the value in A reaches 20, which will occur after 10 loops. In most dialects, loops constructed in this fashion will run much slower than the corresponding `FOR` loop.

#### See also:

* `LABEL`

<!-- TOC --><a name="on-aexpr-gotogosub-linenoaexprlinenoaexpr"></a>
### `ON` *aexpr* {`GOTO`|`GOSUB`} [*lineno*|*aexpr*]{,[*lineno*|*aexpr*],...}

The `ON` statement, also known as the **computed branch**, combines a series of `IF...THEN` *lineno* statements into a single instruction. The value of *aexpr* is calculated to produce a value that is expected to be from 1 up to the number of line numbers in the list following the `GOTO` or `GOSUB`. If there is an entry in the list for that ordinal value, like a 5th entry if *aexpr* returns 5, then the `GOTO` or `GOSUB` is performed with that line as the target. `ON` is often used to respond to user input that selects among a number of options. As is the case for `GOTO` and `GOSUB`, RetroBASIC allows any valid *aexpr* in place of constants for line numbers in the list of targets.

#### Examples:

    300 A=2
    310 ON A GOTO 400,500,600
    400 PRINT "A IS 1"
    500 PRINT "A IS 2"
    600 PRINT "A IS 3"
    700 END

This program will print a `A IS 1`, `2` or `3` depending on the value in the numeric variable `A`. Line 10 assigns the value 2 to A, so the program will perform  `A IS 2`.

#### Variations:

Some dialects use the alternate syntax `GOTO` *aexpr* `ON` and `GOSUB` *aexpr* `ON`, reversing the normal format. RetroBASIC supports this format as well.

<!-- TOC --><a name="for-avaraexpr1-to-aexpr2-step-aexpr3-statmnt-and-next-avaravar"></a>
### `FOR` *avar*=*aexpr1* `TO` *aexpr2* [`STEP` *aexpr3*] {:|}<CR>} [*statmnt*,{:|}<CR>}...] and `NEXT` [*avar*,[*avar*,...]]

Another of the common statements found in BASIC is the FOR/NEXT loop. This is intended to perform a sequence of actions a set number of times. The statements are those between the `FOR` and its corresponding `NEXT`, which is known as the *body* of the loop. The same behavior can be accomplished using IF statements, but FOR/NEXT loops are optimized to make them run much faster.

When a `FOR` is encountered at runtime, the system calculates the values of all of the provided *aexpr*s. `STEP` is optional, and if it is missing, *aexpr3* is set to 1. *avar* is then set to the value of *aexpr1*. It then continues execution at the next statement, continuing as normal until it reaches the `NEXT`. At that point, it adds the value in *aexpr3* to *avar*. If the result in *avar* is now equal to or larger than *aexpr2*, execution continues with the statement after the `NEXT`. If the value is smaller, execution returns to the statement after the `FOR`, continuing the loop.

In most cases, FOR/NEXT loops are used where a pre-determined number of executions is desired. However, it is possible to change the normal behavior, either by assigning a value into *avar* to cause it to exit at the `NEXT`, or alternately, branching out of the body using a `GOTO` or `IF`. Branching out may cause errors later in execution, and some dialects offer solutions for this, like `POP`.

Many dialects allow the variable name to be left off the `NEXT`, although this is sometimes considered bad form. Others, like later versions of Microsoft BASIC, allow multiple comma-separated variable names, so a single `NEXT` can close multiple loops. RetroBASIC supports all of these forms.
    
#### Examples:

This code will produce five lines of output, containing the numbers 1 through 5:

    10 FOR X = 1 TO 5
    20 PRINT X
    30 NEXT X

This program will produce:

     1
     2
     3
     4
     5

The same output can be generated using branching:

    10 X=X+1
    20 PRINT X
    30 IF X<5 THEN 10

Using FOR/NEXT for this sort of task makes the code run faster and more clearly indicates the intentions of the programmer.

This example is similar to the one above but demonstrates multiple statements in the FOR/NEXT body, as well as leaving off the variable name from the `NEXT`:

    10 FOR Y=10 TO 20 STEP 2
    20 A=A+Y
    30 PRINT A
    40 NEXT

Loops can be *nested* inside another loop:

    10 FOR X=1 TO 3
    20 PRINT "OUTER LOOP"
    30 Z=0
    40 Z=Z+2
    50 FOR Y=1 to 5 STEP Z
    60 PRINT "     INNER LOOP"
    70 NEXT Y
    80 NEXT X

This program will produce:

    OUTER LOOP
         INNER LOOP
         INNER LOOP
         INNER LOOP
    OUTER LOOP
         INNER LOOP
         INNER LOOP
         INNER LOOP
    OUTER LOOP
         INNER LOOP
         INNER LOOP
         INNER LOOP

#### Notes:

In home computer interpreters, `FOR/NEXT` loops are much faster than loops constructed using `IF/THEN`. This is because the values of the *aexpr*s are calculated only once when the loop is first encountered, and then cached on the runtime stack for future reference. Using an `IF`, the system has to re-evaluate the expressions every time through the loop. Additionally, the starting position of the loop is saved in the same manner as a `GOSUB`, meaning the loop does not have to search through the list of statements to find the top of the loop. If the loop is not yet complete, which is typically the majority of times, it can move back to the correct statement immediately. Even in compiled versions, which calculate the statement locations for all branches and thus makes branching much faster, skipping the repeated calculations of the *aexpr*s can still result in noticeable performance improvements.

Some dialects from the early microcomputer era do not have FOR/NEXT loops, the most prominent example being Tiny BASIC. Code for these interpreters will use `IF/THEN` for looping, and would normally run very slow as a result. A few dialects, notably Atari and Sinclair, do not cache the memory location of the first statement in the block, but the line number instead. These dialects run much slower, as they have to search through the entire program to find the top of the loop over and over again. This led to various platform-specific tricks intended to improve performance. All of these run essentially instantaneously in RetroBASIC.

Dartmouth and most other compilers, as well as the later ANSI Full BASIC, do not run the body of the loop if the index value is beyond the upper limit when it enters the loop. For instance:

    10 FOR X = 1 TO 0
    20 PRINT X
    30 NEXT X

On most interpreted dialects, the output will be a single line, "1". On Dartmouth derived versions, there is no output and execution resumes at the statement after the NEXT X. This style of execution is not currently supported in RetroBASIC.

#### See also:

* `POP`
* `EXIT`

<!-- TOC --><a name="pop"></a>
### `POP`

`FOR/NEXT` loops and `GOSUB`s store information in memory in an area called the runtime stack. This information is removed from memory when the loop completes or a `RETURN` is encountered. Under certain circumstances, this information can be left behind. If this occurs, the next loop or subroutine may not operate properly.

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

In this example, the first `GOSUB` on line 10 puts an item on the stack saying the program should return to the next statement, line 20. When it enters the subroutine at line 1000, it sets the value of A and then calls another subroutine at line 2000 and puts the new return location on the stack, line 1020. However, the second subroutine exits before calling `RETURN`, leaving behind the entry that says it should return to 1020. When the `RETURN` on 1020 is called, it returns to line 1020, not 20, and removes that entry. It then continues, falling into the second subroutine again, eventually reaching line 2020 and then returning to line 20. Depending on the order of operations and the sequence of calls, the result will be that the code does not follow the expected flow, or you may get an error about "NEXT without FOR" or "RETURN without GOSUB".

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

In this example, there are two entries on the stack during the execution of the subroutine, one for the subroutine call, and another for the FOR...NEXT loop. When I=5, the loop will exit early, leaving the incomplete loop entry on the stack. In most dialects, the `RETURN` will clear out any entries above the subroutine and therefore clear out the incomplete loop. This is not universal; however, other versions may attempt to return using the topmost entry, the loop, and fail out.

#### See also:

* `POP`

<!-- TOC --><a name="pause-aexp"></a>
### `PAUSE` *aexp*
    
`PAUSE` stops execution of the program for *aexp* *jiffies*. In RetroBASIC, a jiffy is a 60th of a second.

#### Notes:

The definition of a jiffy varies widely across platforms. See details in `TIME`.

#### See also:

* `TIME`

#### Availability:

`PAUSE` was added in 1.8.4.

<!-- TOC --><a name="label-nvar"></a>
### `LABEL` *nvar*

`LABEL` is an assignment statement, like `LET`, that sets the value of the *nvar* to the current line number. This is intended to be used with branches that may wish to use a variable instead of a numeric constant. If a traditional variable assignment is used to store a line number and the target code moves or its line number is changed, the variable will no longer point to the right line of code. Using `LABEL` to set these values ensures the variable always contains the correct value, even if the program is edited.

A number of dialects included a `LABEL`-like feature, but there was no standard syntax for this concept. For example, Acorn Atom BASIC had labels that were implemented by typing a single lower-case letter after the line number on the line to be labeled. Atari and Tiny BASIC allowed branches to expressions, but lacked a `LABEL` concept and was thus subject to errors if the program was edited.

`LABEL` should be considered a RetroBASIC-only feature, useful for converting code from those platforms that support a similar feature. For instance, an Atom program that has a `s` label on a line can be converted to RetroBASIC by adding the statement `LABEL s` to the start of the line.

#### Examples:

    10 LABLE T
    20 PRINT "Hello, World!"
    30 GOTO T

#### Availability:

`LABEL` was added in 1.8.3.

<!-- TOC --><a name="call-system-and-sys"></a>
### `CALL` *aexp*[,*aexp*...], `SYSTEM` and `SYS`

`CALL` and `SYSTEM` are two of the common ways that BASIC interpreters supported machine language code being called from a BASIC program. This was often used to access operating system routines and sound and graphics commands. The required *aexp* represents a memory address where execution should begin. The machine language code is expected to call that platform's equivalent of a `RETURN` at the end of the code. When these `CALL`s are encountered in RetroBASIC, they perform no action.

In some dialects, `CALL` is also used to run user-written subroutines in BASIC. The difference between `CALL` and `GOSUB` is that the `CALL`ed routine is referenced by name, not a line number. This is paired with another statement keyword that indicates the start of the named routine, like `SUB` or `FUNCTION`. This variation of `CALL` is not (currently) supported in RetroBASIC.

#### Variations:

Most platforms used `CALL`, the notable exception being Commodore BASIC which used `SYS`, which they took from BASIC-PLUS on the DEC-10. Sperry Univac System/9 also used `SYS`. The Dragon-32 used `EXEC`.

The Color Genie required the address to be passed in hex format. All number constants in RetroBASIC can be entered in hex format, so this will work properly if the 0h or 0x prefix is placed on the constant.

Some dialects allowed parameters to be passed in after the address. Amstrad CPC allowed a single parameter, BBC BASIC allowed a list.

Later IBM PC dialects used `SYSTEM` as an alias for `BYE`, exiting to the DOS shell.

#### See also:

* `USR`

### `OPTION BASE` [0|1]

`OPTION BASE` was introduced in Dartmouth BASIC version 4. It allows you to select whether arrays start at index 0, or 1. Earlier versions used base 1, and when base 0 was introduced later that meant that all arrays ended up with additional unused elements. For those programs that used a base index of 1, which is many of them, using `OPTION BASE 1` before using `DIM` statements would eliminate this wasted memory.

RetroBASIC supports this function, but it has no real effect. Memory constraints are no longer an issue, so there is no reason not to include a 0th item. The only effect is a minor one, the function `LBOUND` will return 0 or 1 depending on this setting.

#### Variations:

Control Data BASIC uses `BASE` in place of `OPTION BASE`.

MAXBASIC allowed any number, not just 0 or 1. For instance `OPTION BASE 5` would make arrays start at index 5.

<!-- TOC --><a name="inputoutput-statements"></a>
## Input/Output Statements

This section describes the input/output statements that are used to access and display data.

<!-- TOC --><a name="print-exp"></a>
### `PRINT` [*exp*{|[;|,]},...]]

`PRINT` is used to produce output on the user's console. It is one of the most common statements found in most BASIC programs. The statement is designed to be very flexible, able to output values from any type of expression. In the case of string expressions, the output is sent unchanged to the console. For numeric values, the values are formatted to ensure very large or small numbers do not fill the screen.

`PRINT` can accept any number of subsequent expressions, including zero. These expressions are separated with one of the three "print separators", the comma, the semicolon, or if the preceding expression is a string constant, nothing. The comma, the only separator in early versions of Dartmouth, adds a variable number of spaces between items so that they line up vertically. This made it easy to print tables. The semicolon, added later, leaves no space between values.

`PRINT` normally outputs a newline after the last expression. It is not uncommon to see a "bare" `PRINT` statement with no expressions as a way to print a newline and leave blank vertical space. The newline is not output if the line ends with the semicolon or comma. In that case, any following `PRINT` will start on the same line.

A curiosity of the BASIC language is that the question-mark may be used as an alias for the `PRINT` statement. This was intended to allow users to type in "questions" at the command line, for instance, `? 5+5`, meaning "what is 5 plus 5?" The interpreter would internally expand the question-mark to `PRINT`, perform the expression, and print the result, `10`. As the question-mark is expanded on entry, using it in a program will expand result in `PRINT` appearing in its place when `LIST`ed.

There are a number of oddities and gotchas in common dialects, many of which are not mentioned in most references.

#### Examples:

    PRINT "Hello, World!"

The classic Hello, World! example in BASIC. The interpreter will evaluate the expression, producing a string, and on determining it is a string, prints it as-is. As it is the last statement and there is no separator following, a newline is also printed.

    ? 2+3+4

In this example, the expression is numeric. The value will be calculated, formatted, and output. A newline will be printed as well. This will produce:

     9

It is not easily visible in that example, but there is an additional leading space in front of the value 9. This is part of the formatting rules for numeric values; it leaves room to print a minus sign for negative values. This way, if a series of numbers is printed that may be negative or positive, they will properly line up vertically on the console.

    100 PRINT "The value of X is ";X
    
This statement uses the semicolon to print two separate expressions: the first is a string constant, which is output as normal, and the second a numeric variable whose value is calculated, formatted, and output. In this case the value of X is not set, so the output will be:

    The value of X is  0

Here the extra space in front of numeric values is more obvious. In the case that one of the values on either side of the semicolon is a string constant, the semicolon can be left off. This code will produce the same output as the example above:

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
    60 PRINT "The total is"T
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

The difference here is the way that the user's input is interpreted. The user can type three values on one line, separated by commas, as noted in the prompt. They can also type a single value and press <return>, which will cause the `INPUT` to display the question mark and continue until all values are provided. In this example run, the user types one value per line:

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

RetroBASIC does not currently allow multiple inputs on a single line, it expected a <return> to indicate the end of each value in a multi-value `INPUT`.

<!-- TOC --><a name="data-concon-read-varvar-and-restore-linenoaexp"></a>
## `DATA`, `READ` and `RESTORE`

`DATA`, `READ` and `RESTORE` statements are used to store multiple constants in the program source code. Early versions of Dartmouth BASIC lacked the ability to work with data files, which made it difficult to store data for use in a program. While one could implement this using multiple assignment statements, this made the code lengthy and difficult to understand. To solve this problem, the `DATA` statement was introduced, which allows constant values to be stored in a compact format. The `READ` statement retrieves these values and `RESTORE` resets the `READ`.

### `DATA` *con*[,*con*...]

`DATA` is followed by a comma-separated list of constants, either strings or numbers. There can be any number of `DATA` statements in a program and any number of values per statement, up to the maximum line length on that platform. On curiosity of the syntax is that string values do not require quote delimiters, unless the string contains a comma.

### `READ` *var*[,*var*...]

When the program first encounters a `READ` statement, it searches through the program for the first `DATA` statement and sets a pointer to the first value in it. The value at the pointer is then read into the associated *var*. One or more variables can be read in a single `READ`, with the variables separated by commas like an `INPUT` statement. As each variable is read, the pointer is moved forward one location in the list of values. This process continues across statements and lines until it reaches the last value in the last `DATA` statement in the program, at which point any further `READ`s will cause an error.

#### Examples:

This program uses `DATA` to define the length and character data for two strings. It `READ`s the length and characters, and then loops to print the characters one at a time. The first string requires quotes, as it contains a comma, the second does not.

    10 DATA 7,"Hello, ",6,World!
    20 FOR I=1 TO 2
    30 READ L
    40 READ S$
    50 FOR J=1 TO L
    50 PRINT MID$(S$,J,1)
    60 NEXT J
    70 NEXT I
    80 END

### `RESTORE` [{*lineno*!*aexp*}]

`RESTORE` is used to reset the data pointer to the start of the list or to the first data element on a particular line indicated by the optional line number or numeric expression.

Several other statements also reset the data pointer, including `CLEAR`, `RUN` and `NEW`.

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

This program will print two totals at the console. The first time through A and B will both be 30, due to the `RESTORE`, so the total will be 60. On the second pass, the pointer will start at the second value, 15, and the `RESTORE` moves it back, so A will be 15 and B will be 30, and the total will be 45.

#### Variations:

Wang BASIC interpreted the optional *aexp* not as a line number but an ordinal, such that `RESTORE 10` would set the pointer to the 10th element in the program's `DATA`. As there is no way to tell which is which, RetroBASIC always interprets the value as a line number, which is far more common.

<!-- TOC --><a name="other-statements"></a>
## Other statements

<!-- TOC --><a name="randomize-aexp"></a>
### `RANDOMIZE` [*aexp*]

In most dialects of BASIC, random numbers returned by the `RND` function are based on an internal mathematical function that produces a new value based on the last one. When a program is first `RUN`, the first number in the sequence is normally zero, and thus every time the program is run, it will produce the same series of values. For a program that is using `RND`, this is generally the opposite of what is desired.

To address this problem, many dialects include the `RANDOMIZE` statement. When used alone, with no *aexp*, this uses a platform-specific solution to generate a new starting number, the **seed**, so it is not zero. With a `RANDOMIZE` statement near the top, every time the program is run it will produce a different series of numbers with `RND`, which is what is desired.

Although `RANDOMIZE` is generally used to produce random seed values, it is also extremely useful during testing and debugging, where the opposite is desired. In this case, using the optional *aexp* will cause the same series of numbers to be returned every time, which makes it much easier to track down problems without the behavior of the program changing every time it runs. In these cases, a `RANDOMIZE 0` near the top of the program is very common.

Later dialects, those developed for home computers, often lack the `RANDOMIZE` statement. Instead, they generate random numbers by applying a simple formula to some internal hardware value, normally a timer on the video circuitry or the internal clock. This makes the random number system very simple to implement, it runs quickly, and there is no need to `RANDOMIZE` as even the shortest delays when `RUN`ning the program will be sufficient to produce completely random values. For the debugging cases, some dialects allowed negative inputs to `RND` to produce `RANDOMIZE`-like results, see `RND` for details.

#### Variations:

Sinclair BASICs use `RAND` as a short form for `RANDOMIZE`.

GW-BASIC has the additional oddity that if the *aexp* is left out, it will pause and ask the user for a seed value similar to an `INPUT` statement. To get the same behavior as other dialects, where it uses the clock as a seed, one uses the `RANDOMIZE TIMER` variation, which is not (currently) supported in RetroBASIC.

#### Notes:

Because `RANDOMIZE` is so useful for debugging and many programs do not include this statement, RetroBASIC allows the seed to be set on the command line using the `--random` switch. This allows you to set the seed without modifying the original program.

#### See:

* `RND`

<!-- TOC --><a name="change-avarsvar-to-svaravar-convert-avarsvar-to-svaravar"></a>
### `CHANGE` {*avar*|*svar*} TO {*svar*|*avar*} and `CONVERT` {*avar*|*svar*} TO {*svar*|*avar*}

The primary difference between the three main families of BASIC is the way they manipulate strings. In Dartmouth versions, this is accomplished with the `CHANGE` command, which takes a string and converts it a series of ASCII values in a numeric array, or takes a numeric array and converts it to a string. The length of the string is stored in the array's zero slot. `CONVERT` is the identical operation found in HP dialects.

#### Examples:

    10 DIM X$(10)
    20 X$="SYSTEM"
    30 CHANGE X$ to X
    40 PRINT"The ASCII codes for the string 'hello' are: "
    50 FOR I=1 TO X(0)
    60 PRINT X(I);",";
    70 NEXT I
    80 END

This program produces:

    The ASCII codes for the string 'hello' are: 104       101       108       108       111

<!-- TOC --><a name="operators"></a>
## Operators

<!-- TOC --><a name="mathematical-operators-arithmetic"></a>
### Mathematical operators (arithmetic)

RetroBASIC supports the standard set of arithmetic operators: `+` for addition, `-` for subtraction, `*` for multiplication, `/` for division, and `^` for exponentiation. It also supports the alternative `**` for exponentiation, which is seen in some older dialects.

`DIV` is used for integer division, which produces the result with any fractional part left off, so `7 DIV 3` returns 2. The `MOD` operator returns the remainder of the division, so that `A = 7.5 MOD 3.5` produces 0.5. Some dialects perform an `INT` on the result, so `7.5 MOD 3.5` returns 0, not 0.5. Others support this functionality using functions, not operators, as detailed in the function section below.

RetroBASIC follows MS's conventions for operator precedence, with parenthetical items and then exponents, multiplication and division, and finally addition and subtraction. 

<!-- TOC --><a name="logical-operators"></a>
### Logical operators

RetroBASIC supports the standard set of logical operators: `=`, `>`, `<`, `<=`, `>=` and `<>` for not-equals. It also supports the HP-style `#` which is the equivalent to `<>`, as well as the seldom-seen `=>` and `=<` variations. It also supports logical `NOT`, `AND`, `OR` and `XOR`.

RetroBASIC also supports two less well-known logical operators, `EQV` and `IMP`. `EQV`, for "equivalent", returns true if both of the parameters are the same, that is, both are true or both are false. `IMP`, for "implies", returns true only if the first parameter is true and the second false, otherwise it returns false.

#### Notes:

Tymshare SUPER BASIC defines a pseudo-variable `EPS`, short for *epsilon*, which holds what that particular machine considers to be a very small value. Comparisons could be performed with the "close to equals" operator, `=#`, which returned true if the two values were equal to within `EPS`. These "close enough" comparisons were used to avoid the rounding issues described in the [*Data* section](#data-in-basic-programs) above.

#### Availability:

`EQV` and `IMP` were added in 2.0.0.

<!-- TOC --><a name="string-operators"></a>
### String operators

RetroBASIC supports only two string operators, `+` and `&`, both of which perform the same operation, string concatenation. A new string is constructed that consists of the string on the right placed on the right end of the string on the left.

String logical operators are the same as the mathematical ones: `=`, `>`, `<`, `<=`, `>=`, `<>` `#`, `=>` and `=<`.

<!-- TOC --><a name="mathematical-functions"></a>
## Mathematical functions

<!-- TOC --><a name="absaexp"></a>
### `ABS`(*aexp*)

Returns the absolute value of a number without regard to whether it is positive or negative. The returned value is always positive.

#### Variations:

According to Lien, some computers accept `A` as a short form, but it is not clear whether this is on entry, in the fashion that `?` expands to `PRINT`, or a separate statement.

### `ADR`(*aexp*)

Returns the address of the data for a variable. This allows programs to directly manipulate variables in memory using `PEEK` and `POKE`.

In RetroBASIC, `ADR` always returns zero.

#### See also:

* `PEEK`
* `POKE`

#### Availability:

`ADR` was added in 2.0.0.

<!-- TOC --><a name="clogaexp"></a>
### `CLOG`(*aexp*)

Returns the logarithm to the base 10, or *common logarithm*, of the variable or expression in parentheses. CLOG(0) gives an error, and CLOG(1)equals 0.

### `DIV`(*aexp1*,*aexp2*)

Performs an integer division on the two parameters. For instance, `DIV(7,2)` returns 3.

#### Variations:

A number of BASICs provide `DIV` as an operator rather than a function. In these, `DIV(7,2)` would be entered as `7 DIV 2`. It is not clear whether any dialects use this function-style version, but as it is known that functional versions of `MOD` are in use, so this has been added as well.

#### See also:

* `MOD`

#### Availability:

`DIV` as a function was added in 2.0.0.

<!-- TOC --><a name="expaexp"></a>
### `EXP`(*aexp*)

Returns the value of *e* (approximately 2.71828283), raised to the power specified by the expression in parentheses. For instance, `EXP(3)`, returns 20.0855365.

<!-- TOC --><a name="fixaexp"></a>
### `FIX`(*aexp*)

Removes any fractional part from the value of *aexp* and returns the resulting integer value. This is similar to C's `trunc` function, and is *not* equivalent to `INT`, which always rounds down. `FIX(-3.445)` will return -3, `INT(-3.445)` returns -4.

#### Notes:

Early Dartmouth versions performed the equivalent of `FIX` for `INT`. It was changed to its current form by Version 4, which is what RetroBASIC emulates. Dialects that supported `FIX` generally did so to provide compatibility with older code. Some used `IP` instead of `FIX` for this function, but this alias is not supported in RetroBASIC as it would interfere with other platforms that might use that as a variable name.

#### See also:

* `FRAC`
* `INT`

<!-- TOC --><a name="fracaexp"></a>
### `FRAC`(*aexp*)

Returns the fractional part of the value of *aexp*. `FRAC(-3.445)` returns -0.445.

#### See also:

* `FIX`
* `INT`

<!-- TOC --><a name="intaexp"></a>
### `INT`(*aexp*)

Returns the greatest integer less than or equal to the value of the expression. This is true whether the expression evaluates to a positive or negative number. Thus, `INT(3.445)` returns 3, while `INT(-3.445)` returns -4. This function is similar to the `floor` function found in most programming languages.

A few dialects, notably earlier versions of Dartmouth and some later dialects like Benton Harbor BASIC, truncate the fractional part instead of performing a floor. On those versions, `INT(-3.445)` returns -3. One particularly common piece of code found in many BASIC programs is something like `INT(X+0.5)`, which is used to round a value. In these dialects, the rounding will be incorrect for negative numbers; for instance, `INT(-3.445+0.5)` will evaluate the interior to -2.945 and then truncate that to -2. In contrast, in dialects that use a floor, that will produce -3, which is the proper answer in this case.

RetroBASIC currently implements `INT` only as a floor, and users should be aware of this when using programs from these (rare) dialects. For those programs that require the older behavior, known as `trunc` in more modern languages, use `FIX` instead.

#### See also:

* `FIX`
* `FRAC`
* `ROUND`

<!-- TOC --><a name="logaexp"></a>
### `LOG`(*aexp*) and `LN`(*aexp*)

Returns the natural logarithm of the number or expression. `LOG(0)` gives an error, and `LOG(1)` equals 0.

#### Variations:

BASICs originating in the UK, including BBC and Sinclair, among others like the Sharp MX, use `LN`. On the UK machines, `LOG` returns the common logarithm, which most dialects support using `CLOG`. This may lead to some problems when running programs from these platforms.

#### Availability:

`LN` was added in 1.9.0.

<!-- TOC --><a name="pidexp"></a>
### `PI`[(*dexp*)]

Returns the value of *pi*, 3.1415... The (*dexp*) is optional; `A=PI`, `A=PI()` and `A=PI(0)` are all accepted.

### `MOD`(*aexp1*,*aexp2*)

Returns the modulus, or remainder, of the division of *aexp1*/*aexp2*. `MOD(7,3)` returns 1. The function performs the equivalent of `INT(X - Y*INT(X/Y))`, which in this example would be performed as INT(7 - 3\*INT(7/3)) = INT(7 - 3\*2) = INT(7 - 6) = 1. This functionality is also available as an operator, where this same call would be written `7 MOD 3`.

#### Variations:

This "functional" style of `MOD` was used in Harris BASIC-V, and has been included for compatibility reasons.

#### See also:

* `DIV`

#### Availability:

`MOD` as a function was added in 2.0.0.

<!-- TOC --><a name="roundaexpaexp"></a>
### `ROUND`(*aexp*[,*aexp*])

Rounds the number to the nearest integer or given decimal place. If only one *aexp* is provided, that number is rounded to the "zeroth decimal", that is, a whole number. `ROUND(1.234)` will return 1. If two *aexp*s are provided, the first value is rounded to the second decimal place, so `ROUND(1.2345,3)` will return 1.235.

<!-- TOC --><a name="rndaexp"></a>
### `RND`([*aexp*])

Returns a random positive number between 0 (inclusive) and 0.999... (exclusive). Some dialects require some form expression in the parentheses even if they do not use it; some do not. RetroBASIC works with either style. In many dialects, the variable or expression in parentheses following RND is a dummy and has no effect on the numbers returned, but there are numerous important exceptions. The variations are so (*ahem*) random, that Lien's *The BASIC Handbook* just gives up and tells you to consult your manual.

Most random number generators are based on a mathematical formula that takes the last random number as its input. This means that each call to the function will return a new value, it cannot be the last one. Systems vary widely on how this is actually implemented. In some, the initial number, or *seed* is always the same and thus the sequence of numbers generated will always be the same. These variations generally offer some method to change the initial value so that different sequences can be generated. Earlier dialects generally use `RANDOMIZE` for this, later ones modified the `RND` itself for this task. The best example is Microsoft and its many variations, which used a negative number as a seed. Other, like Atari BASIC, used an internal hardware timer to produce values, which was both faster and always randomized. Some blended the two options.

`RND` is very common in BASIC programs, especially in games. In most cases, the program actually desires an integer value, and code to the effect of `INT(RND(0)*X+0.5)` can be found in many programs. This works by producing a number between 0 and X-*epsilon*, adds 0.5 to produce a value between 0.5 and X+0.5, and then `INT`s that value, resulting in a value between 1 and X, inclusive. This bit of code is so common that some programs use a user-defined function to make references to this sequence of operations shorter; an example is *Super Star Trek*, which defines a function called `FNR` near the top of the program and then calls it from many locations.

Because this series of operations takes some time to complete, a number of dialects offered ways to generate integer values directly in a single step. Unfortunately, there is no standard solution for this functionality, some use a separate function like `RAND`, while others modify `RND`. Among those that use `RND`, one common solution is that if the *aexp* produces a value between 0 and 1 it returns a floating point value as above, whereas larger positive values produce an integer value from 1 to the provided number. Integer BASIC and BBC BASIC are examples of this style.

Another common variation is found in Microsoft BASICs, although these vary across implementations. In these, a negative *aexp* is equivalent to a `RANDOMIZE` with the positive value, such that `X=RND(-1)` performs the same operations as `RANDOMIZE 1:X=RND(1)`. As almost every other dialect uses only positive values in *aexp*, or ignores them completely, this functionality is considered highly compatible, and is supported in RetroBASIC.

Because there is no way to know which of these optional varieties is being used, it is suggested that you use `RND(1)` in any case where it is not clearly specified.

#### Variations:

ANSI BASIC *requires* the parameter to be empty. Very few dialects followed this rule, although DEC and the APF Imagination Machine are two known to do so.

It is generally the case that any dialect that supports `RANDOMIZE` treats the *aexp* as a dummy.

Apple's Integer BASIC produces only integer values, as these were the only types it could work with. The system always returns a value between 0 and *aexp* - 1, which made it an analog of the more typical floating point versions that never returned the upper bound. To simulate rolling dice, for instance, one could use `LET ROLL=RND(6)+1`.

Sinclair QL BASIC has a similar feature, but uses a more explicit syntax that allows a range to be specified, `RND(10 TO 50)`.

Commodore BASIC uses `RND(0)` to produce a "randomized random value", which is accomplished by mixing the last value with the value from an internal timer. As the timer functions vary across their computer models, the outcome of this function also varies. On most machines, the timer is always running and `RND(0)` operates as if it has been seeded with `RANDOMIZE`. On the Commodore 64 the timer does not start automatically and `RND(0)` will normally always return the same value. Note that this is different than dialects like Dartmouth; those will return different values for `RND(0)` every time it is called, although the *sequence* of values will always be the same (unless `RANDOMIZE`d). On the C64, the value is the same every time and every run. To address this, users were told to add `RND(-TI)` near the start of their programs, using the ticks counter, `TI`, as the seed.

In AppleSoft BASIC, an *aexp* of zero causes the system to return the last value. This appears to be the same implementation as Commodore versions, but with no ability to tie in a timer.

BBC BASIC supports the integer value syntax for *aexp* larger than zero, and this is often found in BBC programs. This returns the values 1 *aexp*, inclusive, in contrast to Integer BASIC which is 0 up to *aexp*. It also supports seeding the random if passed a negative *aexp*, but with the twist that it returns the seed number passed in, not a new random number based on that seed. Like AppleSoft, `RND(0)` returns the last value generated by `RND(1)`. If the function is called with no *aexp* between the parens, it returns a random value between -2147483648 and 2147483647, that is, a 32-bit signed integer. Finally, the sequence is only started with the `RUN` or `CHAIN` commands, so calling it from the prompt in immediate mode will return 0 until the program has started at least once.

#### See also:

* `RANDOMIZE`

#### Availability:

Support for negative values seeding the sequence was added in 1.9.1.
Support for integer values for *aexp* > 1 was added in 1.9.1.

<!-- TOC --><a name="sgnaexp"></a>
### `SGN`(*aexp*)

Returns —1 if *aexp* evaluates to a negative number, a 0 if *aexp* evaluates to 0, or a 1 if *aexp* evaluates to a positive number.

#### Variations:

Early dialects, including Dartmouth, returned 1 for all positive numbers, including 0. Almost all later dialects, including RetroBASIC, return 0 in this case.

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
    
#### Variations:

Apple Business BASIC on the Apple III used the function `TEN` to convert a hex string to decimal. This is not currently supported.

<!-- TOC --><a name="trigonometric-functions"></a>
## Trigonometric functions

Trigonometric functions in BASIC are normally carried out using radians. A few dialects have a feature to switch to degrees, but this is not currently supported in RetroBASIC.

<!-- TOC --><a name="acsaexp"></a>
### `ACS`(*aexp*)

Returns the arccosine of the variable or expression in parentheses.

### Variations:

The Sinclair ZX80 uses `ARCOS` while the SHARP 1211 (TRS-80 Pocket Computer) uses `AC`.

<!-- TOC --><a name="asnaexp"></a>
### `ASN`(*aexp*)

Returns the arcsine of the variable or expression in parentheses.

#### Variations:

Sinclair ZX80 uses `ARCSIN`.

<!-- TOC --><a name="atnaexp"></a>
### `ATN`(*aexp*)

Returns the arctangent of the variable or expression in parentheses.

#### Variations:

Sinclair QL BASIC uses `ATAN`, which is not used on any other of the Sinclair dialects. Most Sinclair's use `ARCTAN.

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
### `TNH`(*aexp*) and `TANH`(*aexp*)

Returns the hyperbolic tangent of the expression in parentheses.

<!-- TOC --><a name="string-functions"></a>
## String functions

<!-- TOC --><a name="ascsexp"></a>
### `ASC`(*sexp*)

This function returns the ASCII code number for the first character of the string expression *sexp*. For instance, `ASC("Hello")` returns 72, the decimal ASCII value for "H".

#### Variations:

Sinclair BASICs use `CODE` instead of `ASC`, which is further confused by the fact that the ZX machines do not use ASCII. `CODE` is not currently supported.

BASIC-PLUS on the DEC-10 uses `ASCII`.

Acorn Atom BASIC used `CH`, for character.

MAXBASIC allowed a second parameter, a length, which returned a series of values, up to that many characters in the string.

Enterprise IS-BASIC uses `ORD` for no obvious reason.

#### Availability:

`ASCII` was added in 2.0.0.

<!-- TOC --><a name="chraexp"></a>
### `CHR$`(*aexp*)

Returns the character as a single-character string, represented by the ASCII code number in parentheses. `CHR$(72)` returns "H".

#### Notes:

The Sinclair ZX series do not use ASCII and will return different characters for any given value.

<!-- TOC --><a name="inkeydexp"></a>
### `INKEY$`(*dexp*)

This function returns the ASCII value of the key currently pressed on the keyboard. If no key is pressed when it is called, it returns 0. In either case, it immediately continues without waiting for user input, unlike `INPUT` or `GET`. `INKEY$` was a later addition to BASIC and mostly found in interactive programs and games. The parameter is a dummy and can be left out, along with the parens, so `I$=INKEY$`, `I$=INKEY$()` and `I$=INKEY$(X)` are all valid in RetroBASIC.

#### Variations:

BBC BASIC will calculate *dexp* and if it is non-zero, wait for that many 1/100ths of a second for input, instead of continuing immediately.

The ORIC-1 and ATMOS used `KEY$`. `KEY$` was also used on the APF Imagination Machine, but this used *dexp* as a parameter selecting a device, 0 was the keyboard, and 1 and 2 were the right and left controllers.

AppleSoft BASIC and Apple Business BASIC used the `GET` *sexp* statement for this functionality.

A number of BASICs, including AppleSoft, Apple Business, Atari, BBC, etc., also used the `GET` statement for similar functionality, but most of these waited for a keystroke before continuing, and thus did not serve the same purpose. On these platforms, `INKEY$` was often implemented using `USR` or `PEEK`. On AppleSoft, one could optionally use an *aexp*, with some caveats. Apply versions also did not echo the typed character.

<!-- TOC --><a name="instr"></a>
### `INSTR`(*sexp1*,*sexp2*[,*aexp*]), `INDEX` and `POS`

`INSTR` searches the string *sexp1* for the first occurrence of *sexp2*, returning the numerical location of the match. If no match is found, `INSTR` returns 0. If the optional *aexp* is provided, searching starts at that index instead.

 `INDEX` and `POS` are aliases for the same feature found in some dialects. Note that `POS` is also used as a system function (see below), RetroBASIC can determine which variation of `POS` is being used based on the parameters and supports both uses of `POS` in the same program.
 
 #### Examples:
 
     10 A$="Hello, World!"
     20 PRINT "'World' is found at location: "INSTR(A$,"World")

This program will produce:

     'World' is found at location: 7

#### See also:

* `POS`

<!-- TOC --><a name="lensexp"></a>
### `LEN`(*sexp*)

This function returns the length in bytes of the designated *sexp*. `LEN("Hello")` returns 5. String variables have a length of zero until characters have been stored in them.

<!-- TOC --><a name="lensexp"></a>
### `LEFT$`(*sexp*,*aexp*)

Returns a new string containing the left-most *aexp* characters from the string *sexp*. `LEFT$("Hello, World!",5)` returns "Hello".

### `MID$`(*sexp*,*aexp1*[,*aexp2*]), `SEG$`, `SUBSTR$` and `SUBSTRING$`

Returns a new string containing characters from *sexp* starting at *aexp1* and running to the end of the string. If the optional *aexp2* is provided, and it often is, it returns up to *aexp2* characters.

`SEG$`, `SUBSTR$` and `SUBSTRING$` are aliases found in some dialects.

#### Examples:

     10 A$="Hello, World!"
     20 PRINT "The string from 7 on is "MID$(A$,7)
     20 PRINT "The string from 7 for 3 is "MID$(A$,7,3)
     
The program will produce:

         The string from 7 on is World!
         The string from 7 for 3 is is Wor

#### Notes:

Apple Business BASIC has the similarly-named `SUB$`, but this is short for "substitute", not "substring".
         
### `RIGHT$`(*sexp*,*aexp*)

Returns a new string containing the right-most *aexp* characters from the string *sexp*. `RIGHT$("Hello, World!",6)` returns "World!".

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
    
## String slicing

### *svar*{(|[}*aexp*[{,|:|TO}*aexp*]{)|]}

String slicing is an alternative way to manipulate string and produce substrings. A "slice" is a substring defined as a starting and ending location within an existing string. Although slicing instructions are not functions in the traditional sense, they produce results similar to the `MID/LEFT/RIGHT` functions. The major difference between the slicing concept and string functions is that the functions take a location and length, not start and end locations. This can result in off-by-one errors when converting code from one system to another.

Slicing syntax is generally similar to accessing a slot in an array, but the exact syntax varies. For instance, in most dialects `A$(1,5)` returns a slice with the first five characters of A$, which produces the same result as `MID$(A$,1,5)` or `LEFT(A$,5)`. They also vary in the way the parameters are separated, most use a comma, but Sinclair uses the `TO` keyword, like `A$(5 TO 5)` and the (little used) Full BASIC used the colon, `A$(5:5)`.

Most slicing implementations allow one or two parameters, with the second parameter optional. Generally, if there is only one parameter it indicates a single character at that location, thus `A$(5)` is the fifth character in the string. To access the portion of the string after a given location, most dialects allowed the second parameter to be empty, `A$(5,)` means "character 5 to the end of the string". This is very useful, as it means you don't have to know the length of the string for common manipulations.

Sinclair and Full BASIC allow either parameter to be optional, `A$( TO 5)` and `A$(:5)` (respectively) mean "the portion of A$ from the start to location 5". This is less useful than the more common one-parameter syntax as the starting location is always 1, whereas allowing the computer to automatically calculate the unknown ending location is very useful.

RetroBASIC is designed to run any program that does not use platform-specific features. As string arrays are relatively commonly, it has to support these and thus has to decide whether a reference in code like `A$(5)` is a slice or an array access. In the case that the syntax is clear, like Sinclair or Full, there is no ambiguity and one can use string arrays and string slicing in the same program using syntax like `A$(5)(5 TO)`, meaning the substring from the 5th character on in the string stored in slot five of `A$`.

To work with the dialects that do not have unique syntax, like Atari BASIC, RetroBASIC uses the `--slicing` command-line switch. When turned on, using `--slicing=1`, all "array like" parameters applied to strings are considered slices.

#### Examples:

Slicing is useful for many types of manipulation that are expensive to perform using functions. For instance, slicing can be used to assign strings into character locations. Consider this code in a MS-derived dialect:

    10 A$="Hello, World!"
    20 A$=LEFT$(A$,5)+". "+RIGHT$(A$,6)
    30 PRINT A$

This code produces:

        Hello. World!

In a slicing dialect, the same code can be expressed much more simply:

    10 A$="Hello, World!"
    20 A$(6,6)="."
    30 PRINT A$

This may seem like a small difference, but it had a significant effect in terms of memory use. The string functions return new strings that have to be combined together in the assignment, so the A$ in line 20 is an entirely new string, and the old value is left in memory as well. Programs that perform string manipulation using functions often run out of memory performing even simple tasks. In contrast, using slicing means the assignment is editing the original string in memory, so there is no additional memory used up.

The same syntax can be used for string concatenation. In MS, one would:

    10 A$="Hello,"
    20 A$=A$+" World!"
    30 PRINT A$

Whereas in slicing systems, this is accomplished with the assignment:

    10 A$="Hello,"
    20 A$(LEN(A$)+1)=" World!"
    30 PRINT A$

In a more practical example that better highlights these differences, consider an MS program that converts a string to upper-case:

    10 A$="Hello, World!"
    20 B$=""
    30 FOR I=1 TO LEN(A$)
    40 IF ASC(MID$(A$,I,1))>97 AND ASC(MID$(A$,I,1))<122 THEN B$=B$+STR$(ASC(MID$(A$,I,1))-64):GOTO 60
    50 B$=B$+STR$(ASC(MID$(A$,I,1))-64)
    60 NEXT I
    70 A$=B$
    80 PRINT A$

Every time through the loop, a new version of `B$` is created, one character longer than the last. If this uses up available memory, MS BASIC runs code to reclaim unused memory, which is slow, buggy, and from the user's perspective, randomly stops the program. In contrast:

    10 A$="Hello, World!"
    20 B$=""
    30 FOR I=1 TO LEN(A$)
    40 IF ASC(A$(I,I))>97 AND ASC(A$(I,I))<122 THEN A$(I,I)=STR$(ASC(A$(I,I)-64))
    50 NEXT I
    60 PRINT A$

This much easier to understand, no new strings are created at any point, and memory is not fragmented.

#### Notes:

HP allowed either parentheses or brackets to be used to denote array slots in numeric arrays, for instance, `A(1,1)` and `A[1,1]` will both return the same value from the array. The same is true for string slices, `A$(1,1)` and `A$[1,1]` will both return the first character in the string.

This is unfortunate, as it means there is no way for the interpreter to distinguish between an array slot and a slice. In HP's case this was not a concern, as they did not support arrays of strings. It treated each string as an array of characters, meaning `A$(1,1)` *was* an array access, albeit with the parameters having a different meaning.

Had HP selected one of these two to indicate slicing instead of both, or alternately used a different definition, like Sinclair's `A$(1 TO 10)`, then BASICs could implement string arrays and slicing. For instance, `A$(2,3)[1,1]` would return the first character of the string in slot (2,3).

#### Variations:

String slicing was common in early microcomputer BASICs, which were often written by programmers that were familiar with HP BASIC. Some worked exactly like HP, Atari and Apple Integer BASIC for instance.

One dialect that did support arrays *and* slicing was SCELBAL, which indicated a slice with a leading colon. Thus `A$(1)` refers to the entire string in slot one in a string array, while `A$(1:5:5)` is the fifth character in that string. To slice a string that was not in an array, the slot was simply left off: `A$(:1:5)` returns the first five characters in A$.

Another that supported arrays and slicing was ANSI Full BASIC, which used a separate colon-separated parameter. So `A$(1)(1:1)` is the first character in the first slot of the A$ array.

#### Availability:

Sinclair `TO` support was added in 1.9.0.

<!-- TOC --><a name="system-functions"></a>
## System functions

<!-- TOC --><a name="fredexp"></a>
### `FRE`(*dexp*)

This function returns the number of bytes of user RAM left. Its primary use is to check the amount of memory left before performing operations that require a large amount of memory.

In RetroBASIC, `FRE` always returns zero.

#### Variations:

Those dialects that allow the program to reserve space in memory for strings, typically using `CLEAR`, generally also allow that amount to be checked by passing in a dummy string variable name. In this case, `FRE()` will return the total amount of memory available, or the amount of memory available for program code, while `FRE(A$)`, where `A$` in this example can be any string variable name, will return the amount of memory in the string area. In early dialects, that was often as little as 50 or 200 bytes.

The TRS-80 II and Genie/Color Genie uses `MEM` for this function, while `FRE` returns string space. The Dragon 32 uses `SIZE`.

<!-- TOC --><a name="peekaexp"></a>
### `PEEK`(*aexp*)

Returns the contents of a specified memory address location *aexp*. The address specified must be an integer or an arithmetic expression that evaluates to an integer between 0 and (typically) 65535 and represents the memory address in decimal notation (not hexadecimal). The number returned will also be a decimal integer with a range from 0 to 255.

In RetroBASIC, `PEEK` always returns zero.

<!-- TOC --><a name="posaexp"></a>
### `POS`(*dexp*)

When POS is called with zero or one dummy parameter, it returns the current position of the cursor. This can be called after `PRINT` and `INPUT` statements to provide more control over output. When called with more parameters, it acts as an alias for `INSTR`, and is covered in the string functions section, above.

<!-- TOC --><a name="linaexp"></a>
### `LIN`(*aexp*)

`LIN` produces *aexp* newlines in the output. The exact nature of `LIN` varies across platforms. On HP systems it is a standalone statement, whereas others treat it as a pseudo-function like `TAB`. RetroBASIC treats it as a true function that returns a string, meaning it has to be placed in `PRINT` statements to produce output.

#### Examples:

    PRINT LIN(3);"Hello"

Produces:




    Hello


<!-- TOC --><a name="spcaexp-spaaexp-and-spaceaexp"></a>
### `SPC`(*aexp*), `SPA`(*aexp*) and `SPACE$`(*aexp*)

`SPC` returns a string containing the number of space characters in *aexp*. `SPA` is the alternate spelling for the same function found in HP, while `SPACE$` is found in other dialects.

#### Examples:

    PRINT SPC(10);"Hello"

Produces:

              Hello

<!-- TOC --><a name="stringsexpaexpaexp"></a>
### `STRING$`(*aexp*,[*sexp*|*aexp2*])

`STRING$` makes a new string containing *aexp* copies of the second parameter. The second parameter can be any string if it is provided as *sexp*, or it can be a single ASCII value if it is an *aexp*. `STRING$` can be used to provide the same functionality as `SPC` if *sexp* contains a single space or *aexp2* produces the value 32.

#### Examples:

    PRINT STRING$(3, "Hello")

Produces:

    HelloHelloHello

#### Variations:

Early instances of `STRING$`, in BASIC-PLUS for instance, only support a single ASCII character value in the second parameter. The ability to use a string parameter appeared later; it was available on the TRS-80, but it is unlikely that was the first example.

<!-- TOC --><a name="tabaexp"></a>
### `TAB`(*aexp*)

`TAB` is a pseudo-function, normally used only in `PRINT` statements. This is used to line up output in tabular format, by specifying the same *aexp* for values that should be aligned.

In most dialects, `TAB` does not return a value; instead, it directly advances the cursor to the column given by *aexp* and returns nothing. For instance, in MS dialects, `A$=TAB(10)` will return a syntax error when run. In RetroBASIC, `TAB` *does* return a string, one containing enough spaces to advance from the current `POS` to the indicated column.

#### Variations:

In Apple's Integer BASIC, `TAB` is a statement, not a function. To advance the cursor to column 10 and print "HELLO", one uses `TAB 10:PRINT "HELLO"`. By any measure, this is a more correct syntax.

#### Examples:

    10 FOR I=1 TO 4
    20 PRINT I;
    30 FOR J=1 TO 3
    40 PRINT TAB(J * 10);J;
    50 NEXT J
    60 PRINT
    70 NEXT I

Produces:

     1         1         2         3
     2         1         2         3
     3         1         2         3
     4         1         2         3
     
#### Availability:

Support for Integer BASIC style TAB statements was added in 1.9.1.

<!-- TOC --><a name="timedexp-and-timeaexp"></a>
### `TIME`{(*dexp*)} and `TIME=`*aexp*

Returns the real-time clock's time value in *jiffies*, which are 1/60ths of a second in RetroBASIC. `TIME` is a pseudo-variable that allows the clock to be set by assigning a value to it. This allows, for instance, portions of a program to be timed by setting `TIME=0` and then `PRINT TIME` later in the code, as `TIME` will now hold the elapsed time. As `TIME` is treated as a variable, only the first two letters of the name are actually read, meaning `PRINT TIME` and `PRINT TI` are identical internally.

#### Examples:

    10 PRINT "This code will time a loop to 10000"
    20 TI=0
    30 FOR I=1 TO 10000
    40 NEXT I
    50 PRINT "Elapsed time is "TI

#### Notes:

The definition of a jiffy is platform-dependant. For instance, on Atari machines, it was 1/30th of a second for machines using NTSC, and 1/25th on those using PAL or SECAM. On the BBC, it was 1/100th. This means that existing code that uses `TIME`, `TIME$` or `PAUSE` may work differently under RetroBASIC.

<!-- TOC --><a name="timedexp-and-clk"></a>
### `TIME$`(*dexp*) and `CLK$`

Returns the real-time clock's time value formatted for printing. In RetroBASIC this is in numeric hours-minutes-seconds format. `CLK$` is the alternative spelling found on Univac systems.

#### Examples:

    PRINT TIME$()

Produces:

    102456

<!-- TOC --><a name="usraexp"></a>
### `USR`(*aexp*)

`USR` is the other common method that BASIC interpreters used to call machine language code, the other being `CALL` and `SYSTEM`. The difference between `CALL` and `USR` is that `USR` expects a return value to be left in a particular location in memory, and the function returns that value.

In RetroBASIC, `USR` always returns zero.

## Matrix commands, operators and functions

Dartmouth BASIC introduced a series of commands and functions that operate on entire arrays with a single operation. These operations can also be implemented using FOR/NEXT loops, but making them a single instruction leads to clearer code and higher performance. The performance issue is especially true in interpreted versions of BASIC, as the code that performs the actions will be a single block of machine code instead of many separate interpreted statements. The downside is that only a few dialects supported these commands, mostly on mainframes, so using them led to portability issues.

One curiosity of the matrix system is that the items in the zero indexes are ignored. So in a vector, the first slot is ignored, while in a matrix the entire zero column and row is ignored. This may lead to "interesting" results if data is inserted in these slots using other statements and then manipulated with the matrix commands, which will cause that data to be cleared out. It is also important to note that these functions do not care about the original `DIM`med dimensions, only the total number of elements in the matrix, so if one does a `DIM A(10,20)`, it is acceptable to access items in `A(15,10)`, as long as the resulting index is still within the total number of slots.


#### Notes:

In most examples of operators and functions in BASIC, the system works by calculating a new value and placing it in temporary storage, normally the evaluation stack. For instance, `A=ABS(A)` calculates a new value by reading the value of A onto the stack, applying the absolute value, placing the result on the stack, and then copies that new value into A. Likewise, `PRINT B*5` performs the multiplication to produce a new value of B times 5 and then places that on the stack where the PRINT statement keyword can use it.

In contrast, the matrix keywords do not operate in this fashion, they directly modify the original value in memory. This leads to the curious syntax where functions don't specify what matrix they are operating on, for instance, `MAT A=INV` is implicitly inverting the value of A, without that being specified in what appears to be a function call on the right. If the syntax was similar to the rest of BASIC, one might expect to be able to `MAT A=INV(B)`.

This is due to the limited amount of memory available on the machines of the era, they could not afford to calculate a new matrix result and then copy that about. So while a typical matrix command looks very much like a function or operator, for instance `MAT A=INV`, internally this operates by directly modifying the existing values in A.

There is an exception of course; the transpose function, `TRN`, takes a parameter indicating a source matrix and returns a new matrix that is copied into the output.
