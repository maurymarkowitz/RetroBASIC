RetroBASIC Language Reference Manual
====================================

**Copyright © 2023 Maury Markowitz**

Version 2.0.2

[![GPL license](http://img.shields.io/badge/license-GPL-brightgreen.svg)](https://opensource.org/licenses/gpl-license)

<a name="introduction"></a>
## Introduction

<a name="what-is-retrobasic"></a>
### What is RetroBASIC?

RetroBASIC is a multi-dialect version of the BASIC programming language intended to run classic BASIC programs written from the 1960s into the 1980s. It includes most features from three main families of BASIC:

- Dartmouth BASIC Version 4
- HP Timeshared BASIC
- DEC BASIC-PLUS and its better-known offshoot, Microsoft BASIC

The goal of RetroBASIC is to run any program written for these dialects and their many offshoots. RetroBASIC can run the version of Super Star Trek found in *BASIC Computer Games*, written in Microsoft BASIC and likely one of the most widely-ported games in history. But it can also run the (non-Super) Star Trek found in the earlier *101 BASIC Games*, written for DEC BASIC. It can also run most programs from *What to do After You Hit Return*, which are written in HP BASIC. Practically any major program should run properly without conversion.

Programs must be provided in plain text, better known as "source code". RetroBASIC cannot read binary files from other platforms, which was the normal way to store BASIC programs on home computers. There are a variety of programs available that will read these binary files and output text, which can then be run in RetroBASIC.

<a name="what-retrobasic-is-not"></a>
### What RetroBASIC is not

The goal of RetroBASIC is to allow you to run popular BASIC programs written during the language's Golden Age. As such, it is also marked by a number of deliberate limitations:

- the language is intended to *run* programs, not *edit* them, and it thus lacks an interactive editor
- you cannot `LIST` a program, `LOAD` or `SAVE` it
- it does not include any platform-specific instructions like sound or graphics, as these are not portable
- it does not (currently) have file handling features, as these vary considerably across platforms

## Contents

<!-- TOC start (generated with https://github.com/derlin/bitdowntoc) -->

- [About this manual](#about-this-manual)
   * [Abbreviations](#abbreviations)
   * [Formatting and notation](#formatting-and-notation)
- [Some underlying concepts](#some-underlying-concepts)
   * [Syntax example](#syntax-example)
- [Data in BASIC programs](#data-in-basic-programs)
   * [Numbers](#numbers)
   * [Strings](#strings)
   * [Variables](#variables)
   * [Arrays](#arrays)
- [Commands](#commands)
   * [`BYE`](#bye)
   * [`CLEAR` and `CLR`](#clear-and-clr)
   * [`CLS`](#cls)
   * [`END`](#end)
   * [`NEW`, `ERASE` and `SCRATCH`](#new-erase-and-scratch)
   * [`RUN` [*aexp*]](#run-aexp)
   * [`STOP` [*sexp*]](#stop-sexp)
   * [Unsupported commands](#unsupported-commands)
- [Program statements](#program-statements)
   * [{`REM`|`'`|`!`} [*scon*]](#rem-scon)
   * [[`LET`] *var*`=`*expr*](#let-varexpr)
   * [`DIM` *var*(*nexp*[,*nexp*...])[,*var*(*nexp*[,*nexp*...])...]](#dim-varnexpnexpvarnexpnexp)
   * [`GOTO` *aexp* and `GO TO` *aexp*](#goto-aexp-and-go-to-aexp)
   * [`GOSUB`, `GO SUB` and `RETURN` [{*lineno*|*aexp*}]](#gosub-go-sub-and-return-linenoaexp)
   * [`IF` *lexp* `THEN` {*lineno*|*statmnt*[:*statmnt*:...]}](#if-lexp-then-linenostatmntstatmnt)
   * [`ON` *aexpr* {`GOTO`|`GOSUB`} [*lineno*|*aexpr*]{,[*lineno*|*aexpr*],...}](#on-aexpr-gotogosub-linenoaexprlinenoaexpr)
   * [`FOR` *avar*`=`*aexpr1* `TO` *aexpr2* [`STEP` *aexpr3*] {:|`<CR>`} [*statmnt*,{:|`<CR>`}...] and `NEXT` [*avar*,[*avar*,...]]](#for-avaraexpr1-to-aexpr2-step-aexpr3-cr-statmntcr-and-next-avaravar)
   * [`POP` or `DISPOSE`](#pop-or-dispose)
   * [`EXIT`](#exit)
   * [`PAUSE` *aexp*](#pause-aexp)
   * [`LABEL` *nvar*](#label-nvar)
   * [`CALL` *aexp*[,*aexp*...], `EXEC`, `SYSTEM` and `SYS`](#call-aexpaexp-exec-system-and-sys)
   * [`OPTION BASE` [0|1]](#option-base-01)
- [Input/Output Statements](#inputoutput-statements)
   * [`GET` *var*](#get-var)
   * [`INPUT` [{*sexp*}{[;|,]}]*var*[,{*sexp*{[;|,]}}*var*,...]](#input-sexpvarsexpvar)
   * [`PRINT` [*exp*{|[;|,]},...]](#print-exp)
   * [`PRINT USING` [*exp*][,|;][*exp*{|[;|,]},...]]](#print-using-expexp)
   * [`PUT` *var*](#put-var)
- [`DATA`, `READ` and `RESTORE`](#data-read-and-restore)
   * [`DATA` *con*[,*con*...]](#data-concon)
   * [`READ` *var*[,*var*...]](#read-varvar)
   * [`RESTORE` [{*lineno*|*aexp*}]](#restore-linenoaexp)
- [Other statements](#other-statements)
   * [`POKE` *aexp1*,*aexp2*](#poke-aexp1aexp2)
   * [`RANDOMIZE` [*aexp*|`TIMER`]](#randomize-aexptimer)
   * [[`CHANGE`|`CONVERT`] {*avar*|*svar*} `TO` {*svar*|*avar*}](#changeconvert-avarsvar-to-svaravar)
- [Operators](#operators)
   * [Mathematical operators (arithmetic)](#mathematical-operators-arithmetic)
   * [Logical operators](#logical-operators)
   * [String operators](#string-operators)
- [Mathematical functions](#mathematical-functions)
   * [`ABS`(*aexp*)](#absaexp)
   * [`ADR`(*aexp*)](#adraexp)
   * [`CLOG`(*aexp*)](#clogaexp)
   * [`DIV`(*aexp1*,*aexp2*)](#divaexp1aexp2)
   * [`EXP`(*aexp*)](#expaexp)
   * [`FIX`(*aexp*)](#fixaexp)
   * [`FRAC`(*aexp*)](#fracaexp)
   * [`INT`(*aexp*)](#intaexp)
   * [[`LOG`|`LN`] (*aexp*)](#logln-aexp)
   * [`PI`[(*dexp*)]](#pidexp)
   * [`MAX`(*aexp*,...)](#maxaexp)
   * [`MIN`(*aexp*,...)](#minaexp)
   * [`MOD`(*aexp1*,*aexp2*) and `MOD%`(*aexp1*,*aexp2*)](#modaexp1aexp2-and-modaexp1aexp2)
   * [`ROUND`(*aexp*[,*aexp*])](#roundaexpaexp)
   * [`RND`([*aexp*])](#rndaexp)
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
   * [[`CSH`|`COSH`]`(*aexp*)](#cshcoshaexp)
   * [`COS`(*aexp*)](#cosaexp)
   * [`SIN`(*aexp*)](#sinaexp)
   * [`SNH`|`SINH`](#snhsinh)
   * [`TAN`(*aexp*)](#tanaexp)
   * [`TNH`|`TANH`](#tnhtanh)
- [String functions](#string-functions)
   * [`ASC`(*sexp*)](#ascsexp)
   * [`CHR$`(*aexp*)](#chraexp)
   * [`INKEY$`(*dexp*)](#inkeydexp)
   * [`INSTR`|`INDEX`|`POS`](#instrindexpos)
   * [`LEN`(*sexp*)](#lensexp)
   * [`LEFT$`(*sexp*,*aexp*)](#leftsexpaexp)
   * [`MID$`|`SEG$`|`SUBSTR$`|`SUBSTRING$`](#midsegsubstrsubstring)
   * [`RIGHT$`(*sexp*,*aexp*)](#rightsexpaexp)
   * \[`SPC`|`SPA`|`SPACE$`\](#spcspaspace)
   * [{`STRING$`|`REPEAT$`} (*aexp*,[*sexp*|*aexp2*])](#stringrepeat-aexpsexpaexp2)
   * [`STR$`(*aexp*)](#straexp)
   * [`VAL`(*sexp*)](#valsexp)
   * [`UCASE$`(*sexp*) and `LCASE$`(*sexp*)](#ucasesexp-and-lcasesexp)
- [String slicing](#string-slicing)
   * [*svar*{(|[}*aexp*[{,|:|TO}*aexp*]{)|]}](#svaraexptoaexp)
- [System functions](#system-functions)
   * [`FRE`(*dexp*)](#fredexp)
   * [`PEEK`(*aexp*)](#peekaexp)
   * [`POS`(*dexp*)](#posdexp)
   * [`LIN`(*aexp*)](#linaexp)
   * [`TAB`(*aexp*)](#tabaexp)
   * [`TIME`[(*dexp*)] and `TIME=`*aexp*](#timedexp-and-timeaexp)
   * [`TIME$`(*dexp*) and `CLK$`](#timedexp-and-clk)
   * [`USR`(*aexp*)](#usraexp)
- [Matrix statements, operators and functions](#matrix-statements-operators-and-functions)
   * [Matrix statements](#matrix-statements)
   * [`MAT` [`LET`] *var1*[`(`*aexp*,*aexp*`)`]`=[`*var2*[`(`*aexp*,*aexp*`)`] | `(` *exp* `)`]](#mat-let-var1aexpaexpvar2aexpaexp-exp-)
   * [`MAT PRINT` *avar*[,|;][*avar*{|[;|,]},...]]](#mat-print-avaravar)
   * [`MAT INPUT` *avar*[,*avar*,...]]](#mat-input-avaravar)
   * [Matrix operators](#matrix-operators)
   * [`MAT` *avar*`=CON`[(*aexp*,...)]](#mat-avarconaexp)
   * [`MAT` *avar*`=IDN`[(*aexp*,...)]](#mat-avaridnaexp)
   * [`MAT` *avar1*`=INV(`*avar2*`)[`,`*nvar*]](#mat-avar1invavar2nvar)
   * [`MAT` *var1*`=TRN(`*var2*`)`](#mat-var1trnvar2)
   * [`MAT` *var*`=ZER`[(*aexp*,...)]](#mat-varzeraexp)
- [Error handling](#error-handling)
   * [{`TRAP`|`ON ERROR GOTO`|`ONERR GOTO`} [*aexp*]](#trapon-error-gotoonerr-goto-aexp)
   * [{`ERROR`|`RAISE`} *aexp*](#errorraise-aexp)
   * [`RESUME` [`NEXT`, *aexp*]](#resume-next-aexp)
   * [`ERL()`](#erl)
   * [`ERR()` and `ERN()`](#err-and-ern)
   * [`ERR$(`*aexp*`)`](#erraexp)
   * [Example](#example)
- [Error codes](#error-codes)

<!-- TOC end -->

<!-- TOC --><a name="about-this-manual"></a>
## About this manual

This manual is a listing of the operators, commands and statements in the RetroBASIC interpreter. It also details some of the internal structures and differences between dialects of BASIC. It is written in Markdown to make it readable on most platforms.

<!-- TOC --><a name="abbreviations"></a>
### Abbreviations

The following abbreviations will be used in this manual:

- *ncon* - a numeric constant
- *scon* - a string constant
- *con* - either of the constant types above
- *nvar* - a numeric variable
- *svar* - a string variable
- *avar* - an array variable (matrix)
- *var* - any of the variable types above
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
- the ellipsis... indicates "and more of same", normally used in option lists in square brackets

For example:

`PRINT` [*exp*{|[;|,]},...]]

This indicates that the PRINT statement consists of the statement keyword `PRINT` followed by zero or more optional expressions separated by nothing, a semicolon, or a comma. The *exp* indicates that any expression type may be used, numeric or string.

Note that the line number is not indicated at the front, nor are the `\<return\>` or `\<enter\>` at the end, as these are assumed to be in the source code you provide.

<!-- TOC --><a name="some-underlying-concepts"></a>
## Some underlying concepts

Programming languages, in general, use English language words and common mathematical symbols to describe a number of instructions that will be carried out in order to produce a desired result. This textual description is known as the *source code*. These instructions have to be converted into an internal format that the computer understands, as opposed to the source code which is designed to be understood by humans. The result of the conversion is the *machine code* or *p-code* depending on how the system works. This internal language can then be *executed*, or in BASIC lingo, *run*.

Like most computer languages, BASIC has a number of **keywords** that are reserved by the language. In BASIC, the list of keywords is normally static, meaning that users cannot add new keywords or modify the actions of existing ones. This contrasts with programming languages like ALGOL which were based around the idea of creating new keywords in code. As new keywords cannot be created in most BASIC dialects, BASIC tends to have many more reserved keywords than other languages in order to ensure the functionality you need is present.

In BASIC, the series of instructions that makes up the program are known as **statements**. A statement consists of a keyword and then zero or more **expressions**. Only certain keywords can appear at the front of a statement, others only as part of an expression. To confuse matters, the subset of keywords that can appear at the front are often referred to as "statements" as well, while other dialects refer to these special keywords simply as "keywords". To avoid confusion, this manual will use the term **statement keywords** for this subset of reserved words and to clearly separate the concept of a statement from the keywords that define them.

In most dialects, a subset of the statement keywords can only be used in certain circumstances and are known as **commands**. Commands *are* statements, and both commands and other statement keywords can be used *in* statements.

The purpose of an **expression** is to provide data to be acted on by the statements. There are many different types of expressions and much of a program's complexity is found within them. The primary types of expressions are classified by type:

- **number** - such as `10` or `-1.75`. Also known as **numeric constants**.
- **string** - a series of characters surrounded by double-quote marks, like `"Hello, World!"`. Also known as **string constants**.
- **variable** - a symbolic name, often a single letter like `X`, which can store the value of a number or a string for future use.
- **array** - a type of variable that stores multiple values (numbers or strings) at once.
- **operator** - common arithmetic symbols that take one or (typically) two expressions and produces a new number or string.
- **function** - operators using names instead of arithmetic symbols.

In most dialects, variables can contain either a number value or a string value but cannot change from one to another. This split was introduced in Dartmouth BASIC, which required the user to add a dollar sign suffix to variables that wanted to hold a string value. These are known as **string variables**. Non-string variables are sometimes, but not always, referred to as **numeric variables**. A few dialects allow any variable to store any value, and these generally lack the dollar sign. This is not supported in RetroBASIC, because most dialects consider assigning one to the other to be an error, and RetroBASIC needs to report these errors.

BASIC programs are generally organized over multiple **lines**, each of which contains one or more statements. A line starts with a **line number**, which acts as a label so other parts of the program can refer to it, as well as a way for various editing tools to allow the user to indicate which lines they wish to edit. After the line number, there is a statement keyword and then any expressions that keyword may use, forming a complete statement. Lines may have more than one statement separated by colons or backslashes, depending on the dialect.

Execution normally starts with the first statement on the lowest-numbered line in the program, and then continues statement by statement until it reaches the end of the program. Some statements can change this normally linear progression; these are known as **branches**.

BASIC was written in an era when editing was carried out on typewriters and had a fixed-width line, often 132 characters, but sometimes 80 or 72, or rarely, even less. Years later, microcomputers emerged that limited lines to roughly 40 characters. To address the need to allow larger statements to be typed in, most dialects have the concept of a **logical line** versus a **physical line**. A physical line is simply a single line or text as produced by the device the user is typing on, while a logical line can span multiple physical lines up to some pre-set limit. Logical lines also allow the code to operate properly while moving between machines with different physical line lengths, only the display of the line will change.

<!-- TOC --><a name="syntax-example"></a>
### Syntax example

Here is a simple example of a BASIC program that illustrates the overall form that RetroBASIC expects:

    10 LET A=10
    20 B$="Hello"
    30 C=A+5:PRINT C
    40 PRINT B$+", World!"
    50 IF C>10 THEN PRINT "C is > 10"
    60 END

Line 10 of this program uses the `LET` statement keyword to assign a value to the numeric variable `A`, using the operator `=` to separate the variable name from the expression that provides a value. In this case, the associated **arithmetic expression** (or *aexp*) is the numeric constant 10. The assignment statement is almost always the most common statement in a BASIC program, and for this reason, most versions of BASIC allow the `LET` keyword to be left out. This produces an exception to the rule that statements start with a statement keyword; they can actually start with a statement keyword *or* a variable name.

Line 20 of this program is also an assignment statement, leaving off the optional `LET`. Notice the dollar sign on the variable name `B` that indicates that the language should expect a string expression on the other side of the `=` operator, not a number. The expression used in this statement is the string constant "Hello".

Line 30 is an example of a multi-statement line, with two statements separated by a colon. The first statement is an assignment using the addition operator with the value stored in `A` and the numeric constant 5 as the inputs. This will have the effect of assigning the resulting value 15 to the variable `C`. The second statement on this line is a print statement, another very common statement in most programs. This will evaluate the expression, returning the numerical value 15, and then print that value to the user's console.

Line 40 shows an example of *overloading*, where a keyword may mean different things depending on the context. The expression in the print statement has the `+` operator but is being given **string expressions** instead of numeric. In this case, the `+` does not represent numeric addition but *string concatenation*, which places the right-hand string at the end of the left-hand string and returns a new, longer string. The result of this print statement is `Hello, World!` being printed to the console.

Line 50 is an example of a logical comparison, which is indicated by the `IF` statement keyword. This is followed by a **logical expression** (*lexp*) using the larger-than operator, which calculates the results of expressions on both sides of the operator, compares them, and then, depending on the outcome of the comparison, optionally performs the statement following the `THEN`. As `C` will hold the value 15 at this point, and 15 is larger than 10, the statement after `THEN` *will* be performed and produce the string `C is > 10` on the console.

Line 60 is the `END` statement, which takes no expression and stops the execution of the program. `END` is optional in most dialects.

So when this program runs, it will produce:

    15
    Hello, World!
    C is > 10

<!-- TOC --><a name="data-in-basic-programs"></a>
## Data in BASIC programs

The ultimate goal of any program is to manipulate data. In BASIC there are two forms of data: numbers and text, with the latter more widely known as *strings*. Most BASIC dialects have similar concepts of what numbers can be represented as and how to manipulate them. BASICs vary much more widely in the way they store and process strings. RetroBASIC attempts to support as many varieties of both numbers and strings as possible.

Another key concept in most programming languages is the difference between a *constant* and a *variable*. Constants are data entered directly into the code, for instance, the number `100` or the string `"hello"`. Variables are names that are given to the location in memory where data is stored. As the terminology implies, the value of a variable can be changed, whereas constants cannot, at least while the program is running.

The types, capabilities and syntax of constants and variables are fairly constant across dialects, although there are a few optional features found in later versions. RetroBASIC attempts to support as many of these variations as possible.

<!-- TOC --><a name="numbers"></a>
### Numbers

Most BASIC interpreters of the RetroBASIC era store numbers using the equivalent of a *single* type, or what would normally be known as a "decimal number" or "floating point". Unless otherwise indicated, any value will default to this type. Thus, an `I` found in a program would refer to a variable with the name "I" that holds a numeric value, initially zero. The internal format used to store the value was chosen to balance the need to save memory while maximizing precision. Microcomputers generally used 32-bit or 40-bit numeric formats, as larger formats would use up too much of the extremely limited memory available in these machines. Mainframe and minicomputer dialects generally used that platform's "natural" format, whatever that might be.

Some dialects had a second number format, *integer*, or what would normally be called a "counting number" or "whole number". Later versions of Microsoft BASIC adding support for integers, so this feature is widely available in home computer dialects, though rarely used. MS used 16-bit values for integers, potentially saving considerable amounts of memory in programs with large numbers of numeric constants. To indicate that a variable should store the value in integer format, the percent sign, `%`, was added to the end of the variable name. So, `I` would store a value in the default floating point format, normally a 40-bit value, while `I%` would store the value as a 16-bit integer.

A few dialects also added a *double* format as well, once again led by Microsoft in their 12k Extended BASIC. These were indicated by adding the hash symbol, `#`, to the end of the variable name. In dialects that had doubles, it was common for the default internal format of the single to be smaller than normal and then have the programmer use doubles if more precision was required. For instance, on the Atari Microsoft BASIC, a single was 32 bits instead of the more typical 40, while a double was 64 bits. In most of these dialects, a single-precision value could be explicitly indicated by adding the bang, `!`, to the end of a variable name. Single was the default format for variables, so the bang is almost never found in real-world programs.

In MS dialects, the existing floating point code is used to perform all calculations, even those on integer values. If the result is being stored into an integer variable, the `INT` operator is applied to the result. That means 7/3 will result in 2 being stored. This allows them to support integer values without having to write a separate math library, which would be difficult given the very limited memory of the early machines where every byte counted. However, the required conversion back to integers means this code actually runs slower than using floating point. In some dialects, like BBC BASIC, an entirely separate all-integer math library is used for this purpose. This offers higher performance, sometimes significantly.

RetroBASIC uses the 64-bit IEEE double format to store all numbers. This does not affect the programs; the extra precision is hidden within the system. RetroBASIC carries out all calculations using doubles, as performance is no longer an issue. Like MS, it converts the resulting values to integer if the result is being stored in an integer variable.

BASIC inputs and outputs numbers in decimal format, using the same formatting rules as C's "g" format. This means that large numbers and small fractions are output in exponent format, regardless of how they are input. For instance, if the program asks the user to type in a number and they type fifteen ones, when output that value will be rendered something like `1.11111E14`. For those dialects that supported doubles, numeric constants could be set to doubles by changing the E to a D.

RetroBASIC has the additional feature that numeric constants can be entered in hexadecimal, octal or binary format. Hexadecimal values are indicated by placing the prefix `0x`, `0h` or `&` in front of the value, for instance, `&1F3A` will be converted internally to the decimal value 7994. Octal is indicated by `0o`, like `0o3725`, and binary with `0b`, like `0b10110011`. These values can be used in any numeric expression in place of a decimal constant. Like any numeric value, they are converted to IEEE doubles internally.

Because the input and output are in decimal, but the internal format is in binary, there are numbers that one can type into the source code cannot be exactly represented internally. This is similar to the way one cannot exactly represent 1/3 in decimal, which we represent as 0.333... . Generally, when moving values between number formats there will always be some values that cannot be exactly represented.

As a result of the differences between binary and decimal, BASIC programs are subject to "round-off error" that can produce odd results, especially when dealing with fractional values. It is widely suggested that you do not rely on a variable containing a specific value when testing it; instead of `IF X=5 THEN A=1`, you should `IF X<>5 THEN A=A:A-1` in case the value of X rounded up to 5.000111... during a previous calculation. While this solves the problem, it also leads to messy and confusing code. RetroBASIC's double format is not immune to round-off error, although it is *greatly* reduced in frequency by the higher-accuracy numbers being used internally and additional features of modern floating point hardware. As such, this sort of error is *highly* unlikely to be seen and this confusing code can be avoided.

To avoid round-off errors, some dialects used a different format known as binary coded decimal, or BCD, which stores decimal numbers directly. This means that any number one can represent in the source code can be exactly represented in memory. This does not eliminate round-off in calculations, one can still perform `A=1/3`, but the cases where this occurs are more obvious to the user. The downside to BCD is that the numbers take up slightly more memory and are generally slower to perform math on. This was a small price in some settings, and those machines intended for business roles like the Wang 2200 used BCD, as do most handheld calculators. Although not unheard of in general-purpose dialects, only Atari BASIC and TI-99 BASIC used this format in widespread use. It was also used in the later MSX dialect.

The added precision of the IEEE format used in RetroBASIC makes the use of BCD superfluous for its intended uses. Most of the cases where round-off would occur in earlier dialects will not result in round-off in RetroBASIC.

<!-- TOC --><a name="strings"></a>
### Strings

Strings hold zero or more characters to form sentence-like values. They are stored in memory as a series of numbers using ASCII encoding, or more commonly, a platform-specific variation of ASCII like PETASCII or ATASCII. The maximum size of a string varies on different platforms. Those that originated on systems with printer terminals are often limited to 72 or 132 characters, the length of one line on paper, while those from the video terminal and home computer era are normally 128 or 256 characters, which makes it easy to store the length in an 8-bit value. Some dialects allow strings to be limited only by system memory.

RetroBASIC strings are always variable-length and can be any size up to the underlying operating system's limit, typically a 32-bit or 64-bit value. This is always *much* more than any known early dialect of BASIC. So while it is possible that bad code would produce strings that are too long for the machine it was originally written on, causing an error, that same code will likely work fine in RetroBASIC.
 
String constants are normally delimited with double quotes, like `"Hello, World!"`, although some dialects use single-quotes, `'Hello, World!'`, or allow both formats. Dialects vary widely in the way that they include quotes inside string constants; the modern solution of placing two double quotes beside each other inside a string, like `"Hello, ""World""!"`, is a later invention. Another curiosity, also seen in the FOCAL language, is that the closing quote can be left off if it is the last character on the line, although this is *rarely* (if ever?) seen in BASIC programs.

The major difference between dialects of BASIC is the way that string variables are manipulated. These vary significantly between the three "families" of BASIC. Code that manipulates strings using one of these styles will not run on other variations and would normally require some level of porting effort to do so.

Dartmouth introduced the `CHANGE` command in V4. This converts a string of characters into a numeric array containing the length of the string in the zero slot and the ASCII values of each character in the rest of the slots in the array. The values were then manipulated numerically, and then `CHANGE`d back into a string. The system was not easy to use for simple tasks like concatenation, which required loops and copying values from one array to another. It does have some advantages in certain operations, like converting upper to lower case or back, where the ASCII number is what is being used.

HP BASIC introduced a second system, the concept of the *slice*. A slice is a pair of numbers that represents the start and end point of a series of continuous characters within the original string. Slices are efficient as they are represented by a pointer to the starting location and a length, which makes efficient use of memory. They also included the `CHANGE` command from Dartmouth, but renamed it `CONVERT`. While one might argue this is a better name for this feature, changing it seems to offer little advantage compared to the need to modify programs that would otherwise run without change. 

Today, the best-known method of manipulating strings is the version found in MS-derived dialects. This uses the `+` operator for concatenation and the functions `MID$`, `LEFT$` and `RIGHT$` to return substrings. This style of manipulation was originally introduced by Tymshare on their SUPER BASIC, which was then copied by DEC to produce BASIC-PLUS, which was then copied by MS to produce Microsoft BASIC. It is arguably the least efficient method of performing string manipulations and often leads to MS systems running out of memory after performing even a relatively few string operations.
 
When microcomputers were first emerging in the mid-1970s, the programmers on these platforms invariably introduced BASIC for these machines. They almost always copied either the DEC or HP model for strings, depending on which platform they were most familiar with. Few microcomputer users came from the mainframe world, and the Dartmouth concept was forgotten. Versions based on the DEC/MS or HP models were well represented until about 1978, when the first all-in-one machines like the Commodore PET began to take over the market. These platforms almost always licensed MS's code, which quickly became the *de facto* standard. HP-style strings lived on, primarily on platforms where memory was limited or markets where MS was not so established. Atari and Sinclair are examples of later dialects where slicing was the primary style. Slicing had largely disappeared by the mid-1980s.

One of the major goals of RetroBASIC was to support programs from any of the older dialects, and for this reason, it supports all of these styles. It includes the entire set of string functions from MS, slicing from HP, and both `CHANGE` and `CONVERT`.

<!-- TOC --><a name="variables"></a>
### Variables

Variables are named references to a location in computer memory holding data. They are a key part of any programming language. In most BASIC dialects, the name can be one or two characters, the first being A to Z and the optional second character A to Z or 0 to 9. This is the case for Microsoft-derived BASICs, and is the standard followed by RetroBASIC. Some dialects allow only one character, and some allow one character and a digit, not two letters. As RetroBASIC allows any two characters, including lowercase, all such variations will run fine. Some dialects allow variable names to be any length, like Atari BASIC, but this is not currently supported in RetroBASIC.

The 1968 version of Dartmouth BASIC introduced string variables. To indicate it held a string, the dollar sign, \$, was added to the end of the name. Because the \$ is part of the name and most dialects only allow for two characters in the name, it is common to have the limitation that string variables can only have single-character names. There is also a subtlety to note here; as the \$ is part of the variable name, A and A\$ are two different variables, and both can be used independently in a program. Most subsequent versions of BASIC followed this rule. Tymshare SUPER BASIC was an exception, allowing strings or numbers to be assigned to any variable and not using the \$.

Further confusion was added by the later addition of the `DEF` statements, which allow one or more variables to be given a type without using the suffix characters. For instance, one can `DEFSTR A` to indicate that A is a string variable without needing the \$. A and A\$ will still be different variables, but both will hold strings. RetroBASIC supports this feature as well.

#### Notes:

Most BASIC interpreters store the values of the variables in a table with fixed-width fields. The first two locations in these fields hold the variable's name. When the program refers to the variable in code, the interpreter searches through the table from top to bottom until it finds a field with that name. If it does not find a match, it creates a new entry at the bottom of the table.

This means that every time a variable is encountered while the program is running, the interpreter has to perform a linear search. As the number of variables in a program grows, this search takes an increasing amount of time and becomes a performance issue in larger programs. For this reason, large programs often have a line near the top of the code that looks something like:

    10 I=0;J=0;K=0;A=0;X=0;Y=0s

The purpose of this line is to force these six variables to be at the top of the table and thus be found more rapidly, improving the performance of the program. Typically, the list is deliberately ordered so the most commonly used variable ends up first in the list. This was known as *manual caching*.

Not all dialects work this way. Compilers, like Dartmouth, hold links directly to each variable's storage in memory and thus do not have to search the table at runtime. A number of interpreters use the same strategy, Atari BASIC being a notable example. In these versions, from a performance standpoint it is as if every variable is at the top of a one-entry list, and while manual caching will still run, it offers no performance advantage.

<!-- TOC --><a name="arrays"></a>
### Arrays

Most BASIC dialects include the concept of an *array*. An array is a group of related values all referred to by a single variable name. Each value is assigned a *slot* in the array, also known as an *element* or or *entry*. Arrays need to be defined before use (see exception below) using the `DIM`ension statement. Later in the program, the separate values can be referred to using numbers in parentheses placed after the variable name. These numbers are known as *indexes* or *subscripts*. For example:

    10 DIM A(10)
    20 A(1)=5
    30 A(2)=10

This program sets aside eleven locations in memory, or slots, that can hold numeric values. It then assigns the values 5 and 10 to slots 1 and 2. The rest have not been set, and those slots will contain zeros.

The exact handling of arrays depends on the dialect. Some allow a single dimension, while most allow two, and a small number allow three or more. RetroBASIC allows any number of dimensions and should properly run code from any of these dialects. In those dialects that allow two or more dimensions, single-dimension arrays, like the example above, are sometimes referred to as *vectors*, or in a few occasions, *lists*, while those with two dimensions are sometimes known as *matrixes*, or alternately *tables*. When talking about arrays, it is also common to refer to non-array numerical values as *scalars*.

Dialects also vary based on what they consider to be the first entry in the array. Early versions of Dartmouth had slot 1 as the first entry in the array, but this was soon realized to be a mistake as it made it difficult to represent polynomials, which often have a zeroth entry. Later versions of Dartmouth added a zero to every array to correct for this. Thus, the `DIM A(10)` statement above produces an array with 11 entries in it, not 10. Debate over whether to use 0 or 1 for the first slot ran into the 1980s, but this was largely moot as MS variations always included a 0 slot and this was the *de facto* standard.

As there is no indication of whether a particular program expects 0 or 1 as the first index, RetroBASIC always sets up a 0 slot just in case. This has (almost) no effect on programs; if they use index 0, it works; if not, it works. The only effect is on the `LBOUND` function, which returns the first index. This normally returns 0, but can be told to return 1 by setting the command-line switch `--array_base=1` or using the `OPTION BASE 1` statement within a program. As most dialects did not include the `LBOUND` function, it is unlikely this feature will have any effect one way or another in any real program.

There is another oddity to consider. Dartmouth sets aside a 0...10 block of memory for every numeric variable, even if it is not `DIM`med. In the example program above, A is defined to have 11 slots, and then it assigns values to the slots. This program will also work if line 10 is left out, because A will always have the default 11 slots. This is a *very* odd feature and is rarely implemented in non-MS dialects, so programs relying on this feature will not run on those machines. RetroBASIC does implement this "feature" in case there are programs that use it. To date, only one program found "in the wild" has made use of this feature, `DIM` has almost always been used.

Finally, there is the additional oddity that the parens are part of the variable name. That is, the variable `A` is a different variable than the one in `A(0)`. One can assign values to either, and they will be held separately in memory, at least in MS-derived dialects. RetroBASIC follows this convention.

To summarize, consider this program following the MS conventions:

    10 A(0)=5
    20 A(1)=10
    30 A=7
    40 PRINT A(0);A(1);A

The output of this program is ` 5  10  7`.

<!-- TOC --><a name="commands"></a>
## Commands

Dartmouth BASIC consisted of two separate programs, the BASIC compiler and runtime, and a shell program that edited the source code and performed a small number of commands. The shell commands were deliberately intended to look like BASIC statements. So in Dartmouth, some of the statement-looking lines could only be used in the shell, while others could only be used in your program. This led to the concepts of **commands** and **statements**, a separation that many later dialects maintained.

Commands were generally intended to work on the program as a whole, loading or saving the source code, running it, debugging it, etc. Examples include `LOAD` to read source code into memory, `RUN` to execute the program, `LIST` to print the current program to the console, and so forth. Some later dialects allowed these commands to be put into programs as well; for instance, Atari BASIC could `LIST` itself. This blurred the line between statements and commands.

RetroBASIC is intended to be used with known-good BASIC source code, which can be edited in any text editor. It is then loaded and run as part of starting up the program. Thus, there is no need for `LOAD`, `SAVE` or `LIST` as these are accomplished in the editor, and this also eliminates many of the editing statements like `RENUM` and similar. Nor is there a need for `RUN` or `CONT`, as the former occurs automatically and the latter is not needed as one cannot stop the program while it is running. It does, however, include a small number of statement keywords that are normally considered commands in most dialects and are found widely enough in source code to be useful:

<!-- TOC --><a name="bye"></a>
### `BYE`

`BYE` originates with Dartmouth BASIC where it exits the BASIC shell and logs the user off of the system. It matched the `HELO` command which performed a login, but `HELO` was not properly part of BASIC itself, it was part of the underlying operating system shell. `BYE` was relatively common in most dialects, but its effect was varied; in Atari BASIC for instance, it exits to Memo Pad, while on PCs it would return to DOS. In RetroBASIC, `BYE` simply exits the program in the same fashion as `END`, returning you to your system's command shell.

#### Variations:

Later IBM PC dialects used `SYSTEM` instead of `BYE`, exiting to the DOS shell.

Some systems, including Dartmouth, allow `GOODBYE` in place of, or in addition to, `BYE`.

<!-- TOC --><a name="clear-and-clr"></a>
### `CLEAR` and `CLR`

Clears the stored values of all variables, resets the dimensions of all arrays, resets the `DATA` pointer, and clears the runtime stack, thereby resetting all `GOSUB`s and `FOR...NEXT` loops. These same actions are performed when `RUN` is invoked, but `CLEAR` can be called within a program without restarting execution at the top. `CLR` is a common abbreviation, seen in AppleSoft, Commodore and Atari BASIC. This was changed from earlier Microsoft dialects, like BASIC-80, which used `CLEAR`.

#### Variations:

Some dialects allow a parameter to be passed to define how much memory to reserve for string storage. Examples included BASIC-80 and TRS-80 Level II. This is not supported in RetroBASIC, which has (effectively) unlimited memory.

Wang BASIC offers a number of variations on `CLEAR`. Using `CLEAR` by itself performs a `NEW`, erasing the program and all its data. `CLEAR P` removes all the lines of the program but leaves the variables intact. Line number parameters can follow the P, in which case only the range of lines between (and including) those numbers will be removed. This usage matches what most dialects called `DELETE`. `CLEAR V` clears variables, performing the same action as `CLEAR` in other dialects, and `CLEAR N` does the same but only for those variables not previously declared `COMMON`. These variations are used to allow one program to call another at runtime, a feature that most dialects that support this implement using the `CHAIN` command.

Amstrad CPC BASIC offers the `ERASE` variation which is a `CLEAR` that is applied to a list of variables instead of all of them.

<!-- TOC --><a name="cls"></a>
### `CLS`

Clears the screen. On modern machines with scrollback buffers in the console, the scrolled text will likely still be there, as is the case with RetroBASIC running in most consoles.

<!-- TOC --><a name="end"></a>
### `END`

`END` stops the execution of the program and exits RetroBASIC, returning you to the console shell. `END` is optional in most dialects, but adding an `END` was considered good form. `END` does not have to be at the end of the source code, it was often found higher in the code with subroutines below it, preventing them from running unless explicitly called. It can also be called anywhere in the code to exit the program based on user input.

#### See also:

* `STOP`

<!-- TOC --><a name="new-erase-and-scratch"></a>
### `NEW`, `ERASE` and `SCRATCH`

`NEW` clears any existing program and data from memory and prepares to accept a new program to be entered. In RetroBASIC, it simply exits to the shell. `ERASE` and `SCRATCH` are alternative spellings found in some dialects.

#### Variations:

Wang BASIC uses `CLEAR` for this purpose. See notes in that entry.

BBC BASIC also offers `OLD`, which recovers an accidentally `NEW`ed program. This was required because pressing the system reset key erased the program. On most other dialects that had an `OLD`, like Dartmouth, it was the equivalent of `LOAD`.

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

RetroBASIC adds a feature from Wang and IBM 5100 BASIC, which outputs an optional string. This is useful for saying things like "Stopping for debugging, you should PRINT A". If no expression is included, RetroBASIC instead prints the default message "STOPped at line:" along with the line number.

#### Variations:

Harris BASIC-V added the `BREAK` statement, which allowed one to place multiple `STOP` markers in the code in a single statement. For instance, `BREAK 10-50,100` would perform a stop (break) at any line from 10 to 50, or line 100. This is useful as it allows you to easily control debugging without having to edit the entire program, a single statement at the top has the same effect as multiple `STOP` statements spread all over the code. RetroBASIC does not currently support `BREAK`.

#### See also:

* `END`

<!-- TOC --><a name="unsupported-commands"></a>
### Unsupported commands

`LIST` and `CONT` are not (currently) supported.

<!-- TOC --><a name="program-statements"></a>
## Program statements

This section explains the statements associated with loops, conditional and unconditional branches, subroutines, and similar functionality. It also explains the means of accessing data and the optional commands used for defining variables. The following list is not in order; it is meant to group statements with similar functionality.

<!-- TOC --><a name="rem-scon"></a>
### {`REM`|`'`|`!`} [*scon*]

`REM`, short for "remark", is used to insert comment text into the program code. Any text on the line after the `REM` is ignored, and execution immediately moves to the next line. RetroBASIC supports the alternative versions, `'` and `!`. The former was first introduced in Dartmouth v4 and is widely used in MS-derived BASICs. The latter, taken from Fortran, was first found in Tymshare SUPER BASIC, and is seen in a few other dialects. The short forms only work if they are the first non-whitespace character in a statement, the `!` serves other purposes in some dialects but will always be found following a statement keyword.

#### Examples:

    10 REM This program will print Hello! to the user's console
    20 PRINT "Hello";:REM "World" will not be printed:PRINT "World"
    30 PRINT "!"

<!-- TOC --><a name="let-varexpr"></a>
### [`LET`] *var*`=`*expr*

The most common statement found in most programs is the assignment statement, with the keyword `LET`. This calculates the value of the expression *expr* and then assigns the result to *var*. The type of variable must match the type of expression; numeric expressions cannot be assigned to string variables and vice versa, and attempts to do so will raise a runtime error.

The keyword `LET` was made optional in later versions of Dartmouth BASIC, and most dialects followed this rule. Even after it became optional, a lot of the code written for Dartmouth and other mainframe dialects continued to use the `LET` in order to retain backward compatibility. In most minicomputer and microcomputer dialects the keyword is rarely seen.

#### Examples:

    10 LET A=10+10^2
    20 B$="Hello, World!"

Line 10 calculates the value of `10+10^2`, 110, and then copies that value into the numeric variable `A`. Line 20 copies the string constant "Hello, World!" into the string variable `B$`.

<!-- TOC --><a name="dim-varnexpnexpvarnexpnexp"></a>
### `DIM` *var*(*nexp*[,*nexp*...])[,*var*(*nexp*[,*nexp*...])...]

Short for "dimension", `DIM` is used to set up arrays. At least one variable name and associated numeric expression has to be supplied. A variable with one numeric expression produces a one-dimensional array, sometimes referred to as a *vector*, while two-dimensional arrays are sometimes known as a *matrix*. In RetroBASIC, like most dialects, a single `DIM` statement can set up multiple arrays by separating the definitions with commas.

Each dimension of an array has a lower bound of zero and an upper bound set to the supplied *nexp*. That means there are more entries in the array than would appear at first glance. For instance, `DIM A(10)` creates an array with 11 entries, while `DIM M(6,3)` creates one with 28 entries.

In those dialects descending from HP, string arrays are actually arrays of single characters. In Atari BASIC, for instance, `DIM A$(100)` is not making an array of 101 strings but a single string with up to 100 characters. In most such dialects, there is no way to make an array of strings, which can make some programs difficult to construct. Later dialects, like ANSI Full BASIC, use an alternate syntax that allows for real string arrays as well as the "slicing" syntax of HP's model.

#### Examples:

    10 DIM A(100),B(10,10),C$(5)

This dimension statement sets up three arrays: a vector from 0...100, a matrix 0...10,0...10, and a string vector 0...5.

#### Variations:

Some dialects, like Sinclair and TRS-80, allow only a single variable per `DIM` statement.

Enterprise IS-BASIC allows the `TO` keyword to define the upper and lower limits of the array. For instance, `DIM A(10 TO 20)` defines an array with 11 entries, from 10 to 20 instead of 0 to 10.

#### See also:

* `OPTION BASE`
* String slicing

<!-- TOC --><a name="goto-aexp-and-go-to-aexp"></a>
### `GOTO` *aexp* and `GO TO` *aexp*

BASIC progresses through a program by performing statements one at a time, moving to the next statement when one is completed. This normally linear flow is interrupted by **branches**, statements that deliberately send the execution to another point in the program. In BASIC, branches move to a **target**, which is indicated by a line number.

The simplest form of branch in BASIC is the `GOTO`, or as it was in early versions of Dartmouth BASIC, `GO TO`. `GOTO` always moves to the line number following the statement keyword and is thus also known as an **unconditional branch**. In most dialects, the expression following the keyword must be a numeric constant, but some dialects allow any valid numeric expression, examples being Tiny BASIC and Atari BASIC. RetroBASIC allows *aexp* to be any expression that produces a valid line number. The result of the expression will be rounded down to remove any fractional part.

If the line number does not exist, RetroBASIC normally returns an error and stops execution. Some dialects do not cause an error in this case, and instead move to the next valid line. RetroBASIC supports this behavior by turning on the `--goto-next` command line switch.

#### Examples:

    100 PRINT "Hello"
    110 GOTO 200
    120 PRINT " World!"
    200 END
    
This program will print "Hello" to the user's console, as the second print statement, on line 120, will be skipped over by the branch on line 110.

#### See also:

* `LABEL`

<!-- TOC --><a name="gosub-go-sub-and-return-linenoaexp"></a>
### `GOSUB`, `GO SUB` and `RETURN` [{*lineno*|*aexp*}]

`GOSUB` statements are unconditional branches like a `GOTO`, but differ in that they record the position in the code where they were called. They do this by writing down the location of the `GOSUB` in a special area in memory known as the **runtime stack**, or simply the **stack**. They then branch to the target and continue as normal until they encounter a `RETURN` statement. At that time, they remove the entry on the stack they added earlier, and use the location they stored to continue at the statement after the original `GOSUB`.

The name "GOSUB" is a contraction of "go to subroutine". Subroutines are small sub-programs that perform a task and then return. For instance, one might write a subroutine to calculate the circumference of a circle with a given radius and then call that code repeatedly with different input values from different locations in the code. This allows the calculation code to be isolated, often placed near the bottom of the program to separate it visually, and then called from different parts of the rest of the program.

As the lines of code making up subroutines are normal statements, programs might accidentally run them when they reach the end of the main program code. If this occurs, the `RETURN` at the end of the subroutine will be called without a `GOSUB` having placed information on the stack and an error will occur when `RETURN` attempts to retrieve the return location. To prevent this, programs generally place their `END` statement immediately before the subroutines, or alternately, place the `END` at a high line number like 9999 and then `GOTO 9999` at the end of the main code.

RetroBASIC also supports the seldom-used option introduced in MSX BASIC that allows a line number to follow the `RETURN` statement. This is exactly equivalent to calling `POP` or `EXIT` followed by a `GOTO`.

#### Examples:

    100 GOSUB 500:PRINT 100
    110 END
    500 PRINT 200
    510 RETURN

This program will print "200" and then "100".

#### Variations:

Later versions of MS BASIC, notably MSX and BASIC-A, allow a line number expression in the `RETURN`.

#### Notes:

Many dialects of BASIC will search for a branch target by starting at the top of the program and then looking through the entire source code for the matching line. Normally, subroutines are placed at the end of the program to separate them visually, often using large line numbers to make this more obvious. However, this also maximizes the amount of time it takes to find the subroutine at runtime and slows performance. For this reason, programs looking to improve performance would sometimes place their subroutine code at the top of the program and then have a `GOTO` to jump past it when the program started. This led to the code being difficult to read.

#### See also:

* `LABEL`
* `POP`
* `EXIT`

#### Availability:

The ability to RETURN to a line number was added in 2.0.0.

<!-- TOC --><a name="if-lexp-then-linenostatmntstatmnt"></a>
### `IF` *lexp* `THEN` {*lineno*|*statmnt*[:*statmnt*:...]}

`IF` calculates the value of the logical expression *lexp*, producing zero if it is not true and a non-zero value, typically -1, if it is true. Like an assignment, the *type* of expression, numeric or string, must be the same on either side of the logical operator; otherwise, a runtime error will be raised.

In early versions of Dartmouth BASIC, the only thing that could follow the `THEN` was a line number. This was used to perform a **conditional branch**, similar to a `GOTO` but only branching if the logical expression was true. This made the logic of such programs difficult to follow as they tend to perform many such logical comparisons and thus had to jump around a lot to perform different statements. This is one of the reasons BASIC was dismissed by programmers like Dijkstra as causing "brain damage" and led to the common complaint that BASIC always produces "spaghetti code".

This limitation was removed from later versions of Dartmouth, which allow one or more statements of any sort to follow the `THEN`. In the common case where only one statement needs to be performed, placing it after the `THEN`, instead of branching to or around it, can lead to dramatically more readable code. If there is more than one statement after the `THEN`, these are performed all-or-nothing; if the logical expression is true, all of the following statements *on the same line* are performed; if it fails, *none* of them are performed and the program moves to the first statement on the next line. A few memory-limited dialects, notably Sinclair BASIC, lacked the ability to place any statement after `THEN`, and thus followed the original Dartmouth syntax.

This change also leads to the curious syntax that one can still use the `THEN` *lineno* syntax, which was retained for compatibility reasons. A more obvious syntax would be to use `THEN GOTO` *lineno*, but this is never seen in real programs. Some dialects also allow the alternative syntax of a `GOTO` or `GOSUB` without the `THEN`, for instance, `IF X=0 GOTO 100`. RetroBASIC supports all of these options.

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

`IF` statements are often used to construct loops. For instance:

    10 A=9
    20 A=A+1
    30 PRINT A
    40 IF A<20 THEN 20

This causes the program to repeatedly add 1 to the current value of A, print the new value, and then start again at line 20. This loop will continue until the value in A reaches 20, which will occur after 10 loops. In most dialects, loops constructed in this fashion will run much slower than the corresponding `FOR` loop.

#### See also:

* `LABEL`

<!-- TOC --><a name="on-aexpr-gotogosub-linenoaexprlinenoaexpr"></a>
### `ON` *aexpr* {`GOTO`|`GOSUB`} [*lineno*|*aexpr*]{,[*lineno*|*aexpr*],...}

The `ON` statement, also known as the **computed branch**, combines a series of `IF...THEN` statements into a single instruction. The value of *aexpr* is calculated to produce an integer number that is expected to be from 1 up to the number of line numbers in the list following the `GOTO` or `GOSUB`. If there is an entry in the list for that ordinal value, like a 5th entry if *aexpr* returns 5, then the `GOTO` or `GOSUB` is performed with that line as the target. `ON` is often used to respond to user input that selects among a number of options. As is the case for `GOTO` and `GOSUB`, RetroBASIC allows any valid *aexpr* in place of constants for line numbers in the list of targets.

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

#### See also:

* `ON ERROR`

<!-- TOC --><a name="for-avaraexpr1-to-aexpr2-step-aexpr3-cr-statmntcr-and-next-avaravar"></a>
### `FOR` *avar*`=`*aexpr1* `TO` *aexpr2* [`STEP` *aexpr3*] {:|`<CR>`} [*statmnt*,{:|`<CR>`}...] and `NEXT` [*avar*,[*avar*,...]]

Another of the common statements found in BASIC is the FOR/NEXT loop. This is intended to perform a sequence of actions a set number of times. The statements are those between the `FOR` and its corresponding `NEXT`, which is known as the *body* of the loop. The same behavior can be accomplished using IF statements, but FOR/NEXT loops are optimized to make them run much faster.

When a `FOR` is encountered at runtime, the system calculates the values of all of the provided *aexpr*s. `STEP` is optional, and if it is missing, *aexpr3* is set to 1. *avar*, known in this context as the *index variable*, is then set to the value of *aexpr1*. It then continues execution at the next statement, continuing as normal until it reaches the `NEXT`. At that point, it adds the value in *aexpr3* to *avar*. If the result in *avar* is now equal to or larger than *aexpr2*, execution continues with the statement after the `NEXT`. If the value is smaller, execution returns to the statement after the `FOR`, continuing the loop.

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

Some dialects from the early microcomputer era do not have FOR/NEXT loops, the most prominent example being Tiny BASIC. Code for these interpreters will use `IF/THEN` for looping, and run very slow as a result. A few dialects, notably Atari and Sinclair, do not cache the memory location of the first statement in the block, but cache the line number instead. These dialects also run much slower, as they have to search through the entire program to find the top of the loop over and over again. This led to various platform-specific tricks intended to improve performance. All of these run essentially instantaneously in RetroBASIC.

Dartmouth and most other compilers, as well as the later ANSI Full BASIC, do not run the body of the loop if the index value is beyond the upper limit when it enters the loop. For instance:

    10 FOR X = 1 TO 0
    20 PRINT X
    30 NEXT X
    40 PRINT "DONE"

On most interpreted dialects, the output will be:

    1
    DONE

On Dartmouth derived versions, the loop body is not performed and the the output would be:

    DONE

This style of execution is not currently supported in RetroBASIC.

#### See also:

* `POP`
* `EXIT`

<!-- TOC --><a name="pop-or-dispose"></a>
### `POP` or `DISPOSE`

`FOR/NEXT` loops and `GOSUB`s store information in memory in an area called the *runtime stack*. This information is removed from memory when the loop completes or a `RETURN` is encountered. Under certain circumstances, this information can be left behind. If this occurs, the next loop or subroutine that is called may not operate properly.

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

In this example, the `GOSUB` statement on line 10 puts an item on the stack saying the program should return to the next statement, line 20. When it enters the subroutine at line 1000, it sets the value of A and then calls another subroutine at line 2000 and puts the new return location on the stack, line 1020. However, the second subroutine exits before calling `RETURN`, leaving behind the entry that says it should return to 1020. When the `RETURN` on line 1020 is called, it returns to line 1020, not 20, and removes that entry. It then continues, falling into the second subroutine again, eventually reaching line 2020 and then returning to line 20. Depending on the order of operations and the sequence of calls, the result will be that the code does not follow the expected flow, or you may get an error about "NEXT without FOR" or "RETURN without GOSUB".

`POP` is intended to correct these situations by removing the last entry on the stack when the program knows it needs to break out of the normal flow. In the example above, the expected behavior is being upset on line 2010. This can be addressed by modifying that line to read:

    2010 IF A=5 THEN POP:GOTO 1020

The `POP` will remove the last entry on the stack, the dangling subroutine call, and then GOTO to code on 1020 and return to the correct location.

#### Variations:

Commodore BASIC 3.5 and later added `DISPOSE` which works exactly like POP.

#### Availability:

`DISPOSE` was added in 2.0.0.

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

The definition of a jiffy varies widely across platforms, so a `PAUSE` statement found in existing code may not pause for the same amount of time. See details in `TIME`.

#### See also:

* `TIME`

#### Availability:

`PAUSE` was added in 1.8.4.

<!-- TOC --><a name="label-nvar"></a>
### `LABEL` *nvar*

`LABEL` is an assignment statement, like `LET`, that sets the value of the *nvar* to the current line number. This is intended to be used with branches that may wish to use a variable instead of a numeric constant.

RetroBASIC allows any numeric expression to be used as a line number target, which means one could simply set a variable to the target line number and use that, like `A=100... GOTO A`. However, if the code is modified and the target changes line numbers, the variable will no longer point to the right line of code. Using `LABEL` to set these values ensures the variable always contains the correct value, even if the program is edited, as the correct line number will be assigned when the program runs.

A number of dialects included a `LABEL`-like feature, but there was no standard syntax for this concept. For example, Acorn Atom BASIC had labels that were implemented by typing a single lower-case letter after the line number on the line to be labeled. Atari and Tiny BASIC allowed branches to expressions, but lacked a `LABEL` concept and was thus subject to errors if the program was edited.

`LABEL` should be considered a RetroBASIC-only feature, useful for converting code from those platforms that support a similar feature. For instance, an Atom program that has a `s` label on a line can be converted to RetroBASIC by adding the statement `LABEL s` to the start of that line.

#### Examples:

    10 LABLE T
    20 PRINT "Hello, World!"
    30 GOTO T

#### Availability:

`LABEL` was added in 1.8.3.

<!-- TOC --><a name="call-aexpaexp-exec-system-and-sys"></a>
### `CALL` *aexp*[,*aexp*...], `EXEC`, `SYSTEM` and `SYS`

`CALL` is two of the common ways that BASIC interpreters supported machine language code being called from a BASIC program. This was often used to access operating system routines and sound and graphics commands. The required *aexp* represents a memory address where execution should begin. The machine language code is expected to call that platform's equivalent of a `RETURN` at the end of the code. When these `CALL`s are encountered in RetroBASIC, they perform no action.

In some dialects, `CALL` is also used to run user-written subroutines in BASIC. The difference between `CALL` and `GOSUB` is that the `CALL`ed routine is referenced by name, not a line number. This is paired with another statement keyword that indicates the start of the named routine, like `SUB` or `FUNCTION`. This variation of `CALL` is not (currently) supported in RetroBASIC.

#### Variations:

Most platforms used `CALL`, the notable exception being Commodore BASIC which used `SYS`, which they took from BASIC-PLUS on the DEC-10. Sperry Univac System/9 also used `SYS`. The Dragon-32 used `EXEC`.

The Color Genie required the address to be passed in hex format. All number constants in RetroBASIC can be entered in hex format, so this will work properly as long as the `&` prefix is placed on the constant.

Some dialects allowed parameters to be passed in after the address. Amstrad CPC allowed a single parameter, BBC BASIC allowed a list.

Later IBM PC dialects used `SYSTEM` as an alias for `BYE`, exiting to the DOS shell.

Dartmouth BASIC used `SYSTEM` to load a language, either BASIC or ALGOL. It was not part of the BASIC language itself.

#### See also:

* `USR`

<!-- TOC --><a name="option-base-01"></a>
### `OPTION BASE` [0|1]

`OPTION BASE` was introduced in Dartmouth BASIC version 4. It allows you to select whether arrays start at index 0, or 1. Earlier versions used base 1, and when base 0 was introduced in later version that meant that all arrays ended up with additional unused elements. For those programs that used a base index of 1, which is many of them, using `OPTION BASE 1` before using `DIM` statements would eliminate this wasted memory.

RetroBASIC supports this function, but it has no real effect. Memory constraints are no longer an issue, so there is no reason not to include a zeroth item. The only effect is a minor one, the function `LBOUND` will return 0 or 1 depending on this setting.

#### Variations:

Control Data BASIC uses `BASE` in place of `OPTION BASE`.

MAXBASIC allowed any number, not just 0 or 1. For instance `OPTION BASE 5` would make arrays start at index 5.

<!-- TOC --><a name="inputoutput-statements"></a>
## Input/Output Statements

This section describes the input/output statements that are used to access and display data.

<!-- TOC --><a name="get-var"></a>
### `GET` *var*

Reads a single byte from the keyboard and puts the value into *var*. If *var* is a numeric value it receives the ASCII value, if it is a string, it becomes a one-character string. `GET` is very similar to `INKEY$`, and was used instead of that function in MS BASIC. It's counterpart for output is `PUT`.

#### Variations:

In AppleSoft and Atari BASIC, `GET` waits for a key to be pressed before continuing. In this respect it is more like a single-character `INPUT` than a replacement for `INKEY$`. On both platforms the only way to simulate the `INKEY$`-like behaviour was to use a `PEEK`.

A few dialects, NEC's N-BASIC, TRS-80 Extended Color BASIC, and Microsoft Level III BASIC, use `GET@` to produce an array of the character data within a given rectangular area on the screen.

HP BASICs use `GET` as a synonym for `LOAD`, with an additional optional expression indicating the line number to start from. This allowed programs to be merged together. Most dialects that had a similar feature called it `APPEND`.

#### See also:

* `PUT`
* `INKEY$`

<!-- TOC --><a name="input-sexpvarsexpvar"></a>
### `INPUT` [{*sexp*}{[;|,]}]*var*[,{*sexp*{[;|,]}}*var*,...]

`INPUT` is the primary statement for asking the user to input data from the keyboard. When it is encountered in a program, execution stops and a question-mark prompt is displayed on the console to indicate the computer is waiting for input. The user then enters their response and indicates they are done by pressing the \<return\> key. The value that they typed in is then processed and assigned to corresponding *var*.

`INPUT` can accept multiple values in a single statement, using a comma-separated list of variables. The user may enter any value on its own and press \<return\>, or they can enter multiple values on a single line by separating the values with commas. If the variable is a string, a comma can be typed within the string by surrounding it with quotes, in the same fashion as a `DATA` statement. When there are multiple variables in the `INPUT`, if the user types fewer than that number on any one line, the system will print a `??` to indicate more data is needed.

The handling of empty inputs, which occurs when the user hits \<return\> without typing a value, varies across implementations. Some dialects, like early Commodore BASIC on the PET, stop execution of the program and return to the READY prompt without reporting an error. Atari BASIC will exit and also print error 8, "INPUT or READ type mismatch". Others, like Commodore BASIC V2 on the C64, interpret this as the user saying "no change", and continue execution leaving the variable's previous values unchanged. RetroBASIC follows this pattern, as it appears to be the most common and has no real downsides.

If the optional *sexp* is included, that text will be printed before the question-mark as an additional prompt. This eliminates the need to use a separate `PRINT` statement to tell the user what they are expected to type in. Commodore BASIC requires the separator between the prompt and list of variables be a semicolon, while most demand a comma. RetroBASIC supports either, and always treats them like a semicolon so that no space is inserted between the prompt string and the question mark.

A few dialects allow prompts to be inserted at any point in the parameter list, and RetroBASIC follows this convention. In the case of multi-variable `INPUT`s, any prompts after the first one will only appear if the user does not type in all the values in a single line.

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

The user responds by typing a number and pressing \<return\>. This returns to the top of the `FOR` loop and repeats, so the complete interaction would be something like:

    Enter five numbers to be summed...
    Number? 5
    Number? 3
    Number? 1
    Number? 1
    Number? 7
    The total is 17

Using multiple variables in a single `INPUT` has a similar effect. For instance:

    10 PRINT "Enter three numbers to be summed..."
    20 INPUT "Type three numbers separated by commas ",A,B,C
    30 PRINT "The total is "A+B+C

The difference here is the way that the user's input is handled, in this case user can type three values on one line separated by commas. They can also type a single value and press \<return\>, which will cause the `INPUT` to display two question marks and continue asking until all values are provided. In this example run, the user types one value per line:

    Enter three numbers to be summed...
    Type three numbers separated by commas? 3
    ?? 2
    ?? 1
    The total is 6

The user could also type them all on one line:

    Enter three numbers to be summed...
    Type three numbers separated by commas? 3,2,1
    The total is 6

RetroBASIC allows multiple prompt strings in a single statement:

    10 PRINT "Enter three numbers to be summed..."
    20 INPUT "What is value 1 "A,"What is value 2",B,"What is value 3",C
    30 PRINT "The total is "A+B+C

If the user types in all the values at once, the interaction might look like this:

    Enter three numbers to be summed...
    Type three numbers separated by commas? 3,2,1
    The total is 6

Alternately, they may type in the values separately, as in the example above. In that case the additional prompts will appear:

    Enter three numbers to be summed...
    Type three numbers separated by commas? 3,2
    What is value 3?? 1
    The total is 6

#### Variations:

Although the question-mark prompt is almost universal, Tiny BASIC prints a colon, `:`.

Some dialects allow the question-mark to be suppressed, but there is no standard for this feature.

IBM 5100 BASIC requires single quotes around string entries made by the user, but this is not needed in RetroBASIC.

<!-- TOC --><a name="print-exp"></a>
### `PRINT` [*exp*{|[;|,]},...]

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
    
The column widths for commas vary across platforms; Dartmouth used 15 but the most common setting is 10 spaces, which is used by MS BASIC. RetroBASIC defaults to 10, but this can be changed with the `--tabs` command line switch.

#### Variations:

Tiny BASIC (at least some versions) allow the width of a field to be defined by placing a hash and then number of digits, like `PRINT #3,A`, which will print out only three digits of A. These can be placed at any point in the list of expressions so a single `PRINT` can have multiple formats, like `PRINT #3,A,#4,B,C,D`. The last format seen remains in effect until the end of the statement, where it is reset to "standard format"."

Digital Group Opus BASIC uses a similar system but uses the percent sign as the indicator instead of the hash, and offers a number of different formats like dollars, commas, and field widths in a Fortran-like format. This includes things like `%$10F2`, which means that the values will be printed in a floating-point format with up to 10 characters in total, including a leading dollar sign and a maximum of two decimal places.

Neither of these is currently supported in RetroBASIC, although `PRINT USING` can be used to produce the same effect.

#### See also:

* `POS`

<!-- TOC --><a name="print-using-expexp"></a>
### `PRINT USING` [*exp*][,|;][*exp*{|[;|,]},...]]

`PRINT USING` is a variation of the `PRINT` statement that adds a "format string" to define how the following expressions should be formatted. This can define, for instance, how floating point numbers should be printed, including the number of digits after the decimal point, or to add a dollar sign at the front. There are a wide variety of formatting strings supported by various dialects, as well as different ways to specify them in the statement. RetroBASIC does its best to support as many of these as possible.

The most common variations allow a string constant to be placed directly after the `USING`, known as the "image" or "format string". The image contains special characters that indicate what should be printed at that location. Other characters found in the image are output as-is. One of the most commonly used special characters is the hash, `#`, which indicates a digit should be printed in that location. Values can be forced to integer format using an image string like `"####`" or currency format with `"###.##"`. Because other characters are output as-is, a typical image mixes the two, for instance, `"The price is $####.## per pound."`

While a number of dialects require the image to be specified as a string constant, some allow the image to be stored in a string variable. Additionally, most dialects supported some way to specify the image explicitly on a separate line, as was the case in Fortran where this feature originates. The most common syntax was to place a colon directly after a line number, and then refer to that in the `USING` clause by that line number. HP BASIC used the `IMAGE` statement which worked in a similar fashion, but used different format characters.

One curiosity to note is that `PRINT USING` *always* prints a \<return\> at the end of the line, ignoring the normal behaviour when a comma or semicolon is found at the end of the expression list.

RetroBASIC currently only supports the hash for numeric definitions. A more full treatment will follow in the future.

#### Examples:

    PRINT USING "##.##";.78
     0.78

    PRINT USING "###.##";987.654
     987.65
     
    PRINT USING "##.##";10.2;5.3;66.789;.234
     10.20 5.30 66.79 0.23

#### Variations:

GW BASIC uses a semicolon between the image and expressions, not a comma. RetroBASIC allows either.

*Illustrating BASIC* notes that "one BASIC uses % not :" for specifying an `IMAGE` line, but does not specify which BASIC that is. It also notes that "N.C.C Standard BASIC" suggests the separator between the image specification and expression list is a colon, although no dialect that actually followed that rule was known. 

<!-- TOC --><a name="put-var"></a>
### `PUT` *var*

Writes a single byte from *var* to the screen. If *var* is a numeric value it prints the ASCII character with that value, if it is a string, it prints the first character of that string. It's counterpart for input is `GET`.

#### See also:

* `GET`
* `PRINT`

<!-- TOC --><a name="data-read-and-restore"></a>
## `DATA`, `READ` and `RESTORE`

`DATA`, `READ` and `RESTORE` statements are used to store and process multiple constants in the program source code.

Early versions of Dartmouth BASIC lacked the ability to work with data files, which made it difficult to store data for use in a program. While one could implement this using multiple assignment statements, this made the code lengthy and difficult to understand. To solve this problem, the `DATA` statement was introduced, which allows constant values to be stored in a compact format. The `READ` statement retrieves these values and `RESTORE` resets the `READ` to the first `DATA`. The system essentially simulates reading data from a file.

<!-- TOC --><a name="data-concon"></a>
### `DATA` *con*[,*con*...]

`DATA` is followed by a comma-separated list of constants, either strings or numbers. There can be any number of `DATA` statements in a program and any number of values per statement, up to the maximum line length on that platform. One curiosity of the syntax is that any leading or trailing whitespace will be removed. Another is that string values do not require quote delimiters, unless the string contains a comma, colon, or deliberate whitespace at the start or end.

#### Examples:

Due to the quoting and whitespace handling, all of these statements are equivalent:

    10 DATA "one","two"
    20 DATA "one",two
    30 DATA one,two
    40 DATA one,"two
    50 DATA one      ,      two

The following line is *not* the same, as quotes are used to preserve the whitespace:

    60 DATA "one      ","      two"

<!-- TOC --><a name="read-varvar"></a>
### `READ` *var*[,*var*...]

When the program first encounters a `READ` statement, it searches through the program for the first `DATA` statement and sets a pointer to the first value in that statement. The value at the pointer is then read into the associated *var*. One or more variables can be read in a single `READ`, with the variables separated by commas. As each variable is read, the pointer is moved forward one location in the list of values. This process continues across statements and lines until it reaches the last value in the last `DATA` statement in the program, at which point any further `READ`s will cause an error.

`READ` does not care about the type of the data in the `DATA` statement, that is determined by the variable type. It will only return an error if the variable is numeric and the data item cannot be converted to a number, like `1x5`. In the opposite case, where a string variable reads what looks like a numeric value in the `DATA`, it will be treated as an unquoted string. That is, the number `1.2345` will be treated as `"1.2345"`.

#### Examples:

This program uses `DATA` to define the length and character data for two strings. It `READ`s the length and characters, and then loops to print the characters one at a time. The first string requires quotes, as it contains a comma and explicit whitespace, the second does not.

    10 DATA 7,"Hello, ",6,World!
    20 FOR I=1 TO 2
    30 READ L
    40 READ S$
    50 FOR J=1 TO L
    60 PRINT MID$(S$,J,1);
    70 NEXT J
    80 NEXT I
    90 END

This program produces:

    Hello, World!

<!-- TOC --><a name="restore-linenoaexp"></a>
### `RESTORE` [{*lineno*|*aexp*}]

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

Wang BASIC interpreted the optional *aexp* not as a line number but an ordinal, such that `RESTORE 10` would set the pointer to the 10th element in the program's `DATA`. As there is no way to tell which dialect any given code is using, RetroBASIC always interprets the value as a line number, which is far more common.

<!-- TOC --><a name="other-statements"></a>
## Other statements

<!-- TOC --><a name="poke-aexp1aexp2"></a>
### `POKE` *aexp1*,*aexp2*

Deposits the numeric value of *aexp2* in the memory location at *aexp1*. *aexp2* must be a value between 0 and 255. `POKE` was widely used on many platforms to access features that were not part of the BASIC language itself.

In RetroBASIC, `POKE` does nothing, and is included only to allow programs to load properly. As the effects of a `POKE` are often display related, like setting a color or text mode, programs with these statements may still function properly in RetroBASIC.

#### Variations:

Digital Group Opus BASIC used `STUFF` for this role, this is not supported in RetroBASIC.

North Star BASIC used `FILL` for this role, this is not supported in RetroBASIC.

A number of later BASICs added a variation on `POKE` that allowed a 16-bit value to be written in a single statement, an example is the `DPOKE` statement in Turbo-BASIC XL on the Atari.

#### See also:

* `PEEK`

<!-- TOC --><a name="randomize-aexptimer"></a>
### `RANDOMIZE` [*aexp*|`TIMER`]

In most dialects of BASIC, random numbers returned by the `RND` function are based on an internal mathematical function that produces a new value based on the last one. When a program is first `RUN`, the first number in the sequence is normally zero, and thus every time the program is run, it will produce the same series of values. For a program that is using `RND`, this is generally the opposite of what is desired.

To address this problem, some dialects include the `RANDOMIZE` statement. When used alone, with no *aexp*, this uses a platform-specific solution to generate a new starting number, known as the *seed*, so it is not zero. With a `RANDOMIZE` statement near the top, the program will produce a different series of numbers with `RND` every time the program is run, which is what is desired.

Although `RANDOMIZE` is generally used to produce random seed values, it is also extremely useful during testing and debugging when the opposite is desired. Using the optional *aexp* will cause the same series of numbers to be returned every time, which makes it much easier to track down problems without the behavior of the program changing every time it runs. In these cases, a `RANDOMIZE 0` near the top of the program is very common.

Later dialects, those developed for home computers, often lack the `RANDOMIZE` statement. Instead, they generate random numbers by applying a formula to some internal hardware value, normally a timer on the video circuitry or the internal realtime clock. This makes the random number system very simple to implement, it runs quickly, and there is no need to `RANDOMIZE` as even the shortest delays when `RUN`ning the program will be sufficient to produce completely random values. `RANDOMIZE` is still useful in the debugging cases, so some dialects included it, while others allowed negative inputs to `RND` to produce `RANDOMIZE`-like results. See `RND` for further details.

#### Variations:

Sinclair BASICs use `RAND` as a short form for `RANDOMIZE`.

GW-BASIC has the additional oddity that if the *aexp* is left out, it will pause and ask the user for a seed value similar to an `INPUT` statement. This is not supported in RetroBASIC. In GW, to get the same behavior as other dialects that use the clock as a seed, one uses the `RANDOMIZE TIMER` variation. This is almost always found in GW programs. This is supported in RetroBASIC.

#### Notes:

Because `RANDOMIZE` is so useful for debugging and many programs do not include this statement, RetroBASIC allows the seed to be set on the command line using the `--random` switch. This allows you to set the seed without modifying the original program.

#### See also:

* `RND`

#### Versions:

`RANDOMIZE TIMER` was added in 2.0.0.

<!-- TOC --><a name="changeconvert-avarsvar-to-svaravar"></a>
### [`CHANGE`|`CONVERT`] {*avar*|*svar*} `TO` {*svar*|*avar*}

The primary difference between the three main families of BASIC is the way they manipulate strings. In Dartmouth versions, this is accomplished with the `CHANGE` statement, which takes a string and converts it a series of ASCII values in a numeric array, or takes a numeric array and converts it to a string. The length of the string is stored in the array's zero slot. `CONVERT` is the identical operation found in HP dialects.

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

RetroBASIC supports the standard set of arithmetic operators: `+` for addition, `-` for subtraction, `*` for multiplication, `/` for division, and `^` for exponentiation. It also supports the alternative `**` for exponentiation, which is seen in some older dialects that did not have a ^ character on their keyboards.

`DIV` is used for integer division, which produces the result with any fractional part left off, so `7 DIV 3` returns 2. The `MOD` operator returns the remainder of the division, so that `A = 7.5 MOD 3.5` produces 0.5. Some dialects perform an `INT` on the result, so `7.5 MOD 3.5` returns 0, not 0.5. Others support this functionality using functions, not operators, as detailed in the function section below.

RetroBASIC follows MS's conventions for operator precedence, with parenthetical items and then exponents, multiplication and division, and finally addition and subtraction. 

<!-- TOC --><a name="logical-operators"></a>
### Logical operators

RetroBASIC supports the standard set of logical operators: `=`, `>`, `<`, `<=`, `>=` and `<>` for not-equals. It also supports the HP-style `#` which is the equivalent to `<>`, as well as the seldom-seen `=>` and `=<` variations.

RetroBASIC supports the basic logical operators `NOT`, `AND` and `OR`, as well as the less-seen but useful `XOR`.

RetroBASIC also supports two less well-known logical operators, `EQV` and `IMP`. `EQV`, for "equivalent", returns true if both of the parameters are the same, that is, both are true or both are false. `IMP`, for "implies", returns true only if the first parameter is true and the second false, otherwise it returns false.

#### Notes:

Tymshare SUPER BASIC defines a pseudo-variable `EPS`, short for *epsilon*, which holds what that particular machine considers to be a very small value. Comparisons could be performed with the "close to equals" operator, `=#`, which returned true if the two values were equal to within `EPS`. These "close enough" comparisons were used to avoid the rounding issues described in the [*Data* section](#data-in-basic-programs) above. RetroBASIC does not currently support this feature.

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

According to Lien, some computers accept `A` as a short form, but it is not clear whether this is on entry, in the fashion that `?` expands to `PRINT`, or a separate statement keyword. It is likely the former, as it would be difficult to know if something like `C=A(B)` is referring to the `ABS` function or a an array variable named `A`. RetroBASIC does not support this short form.

<!-- TOC --><a name="adraexp"></a>
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

Returns the logarithm to the base 10, or *common logarithm*, of the variable or expression in parentheses. `CLOG(0)` gives an error, and `CLOG(1)` equals 0.

<!-- TOC --><a name="divaexp1aexp2"></a>
### `DIV`(*aexp1*,*aexp2*)

Performs an integer division on the two parameters. For instance, `DIV(7,2)` returns 3.

#### Variations:

A number of BASICs provide `DIV` as an operator rather than a function. In these, the equivalent of `DIV(7,2)` would be entered as `7 DIV 2`. It is not clear whether any dialects use the function-style version of `DIV`, but as it *is* known that functional versions of `MOD` are in use, so this has been added as well.

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

<!-- TOC --><a name="logln-aexp"></a>
### [`LOG`|`LN`] (*aexp*)

Returns the natural logarithm of the number or expression. `LOG(0)` gives an error, and `LOG(1)` equals 0.

#### Variations:

BASICs originating in the UK, including BBC and Sinclair, among others like the Sharp MX, use `LN`. On the UK machines, `LOG` returns the common logarithm, which most dialects support using `CLOG`. This may lead to some problems when running programs from these platforms.

#### Availability:

`LN` was added in 1.9.0.

<!-- TOC --><a name="pidexp"></a>
### `PI`[(*dexp*)]

Returns the value of *pi*, 3.1415... The (*dexp*) is optional; `A=PI`, `A=PI()` and `A=PI(0)` are all accepted.

<!-- TOC --><a name="maxaexp"></a>
### `MAX`(*aexp*,...)

Returns the largest number in the provided list, `MAX(7,5)` returns 7. This functionality is also available as an operator, where this same call would be written `7 MAX 5`.

#### Variations:

The "functional" style of `MAX` was used in Micropolis BASIC, and likely others.

Tymshare SUPER BASIC allows any number of expressions in the functional style, this is not currently supported.

#### See also:

* `MIN`

#### Availability:

`MAX` was added in 2.0.0.

<!-- TOC --><a name="minaexp"></a>
### `MIN`(*aexp*,...)

Returns the smallest number in the provided list, `MIN(7,5)` returns 5. This functionality is also available as an operator, where this same call would be written `7 MIN 5`.

#### Variations:

The "functional" style of `MIN` was used in Micropolis BASIC, and likely others.

Tymshare SUPER BASIC allows any number of expressions in the functional style, this is not currently supported.

#### See also:

* `MAX`

#### Availability:

`MIN` was added in 2.0.0.

<!-- TOC --><a name="modaexp1aexp2-and-modaexp1aexp2"></a>
### `MOD`(*aexp1*,*aexp2*) and `MOD%`(*aexp1*,*aexp2*)

Returns the modulus, or remainder, of the division of *aexp1*/*aexp2*. `MOD(7,3)` returns 1. The function performs the equivalent of `INT(X - Y*INT(X/Y))`, which in this example would be performed in order as as INT(7 - 3\*INT(7/3)) = INT(7 - 3\*2) = INT(7 - 6) = 1. This functionality is also available as an operator, where this same call would be written `7 MOD 3`.

`MOD%` performs the same operations but then applies a final `INT` operation on the result.

#### Variations:

This "functional" style of `MOD` was used in Harris BASIC-V and DEC BASIC-PLUS. BASIC-PLUS also added `MOD%`.

#### See also:

* `DIV`

#### Availability:

`MOD` as a function and `MOD%` were added in 2.0.0.

<!-- TOC --><a name="roundaexpaexp"></a>
### `ROUND`(*aexp*[,*aexp*])

Rounds the number to the nearest integer or given decimal place. If only one *aexp* is provided, that number is rounded to the "zeroth decimal", that is, a whole number. `ROUND(1.234)` will return 1. If two *aexp*s are provided, the first value is rounded to the second decimal place, so `ROUND(1.2345,3)` will return 1.235.

<!-- TOC --><a name="rndaexp"></a>
### `RND`([*aexp*])

Returns a random positive number between 0 (inclusive) and 1 (exclusive). Some dialects require some form of expression in the parentheses even if they do not use it; others do not and you can leave the parameter empty. RetroBASIC works with either style. In many dialects, if a variable or expression is passed in the parentheses it is ignored and has no effect on the numbers returned, but there are numerous important exceptions. The variations are so (*ahem*) random, that Lien's *The BASIC Handbook* gives up and tells you to consult your manual.

Most random number generators are based on a mathematical formula that takes the last random number as its input. This means that each call to the function is guaranteed to return a new value in a random sequence. Systems vary widely on how this is actually implemented. In some, the initial number, or *seed* is always the same and thus the *sequence* of numbers generated will always be the same. These variations generally offer some method to change the initial value so that different sequences can be generated. Earlier dialects generally use `RANDOMIZE` for this, but later ones generally modified the `RND` itself for this task. The best example is Microsoft and its many variations, where a negative number in the parameter is converted to a positive value and used as the seed, whereas a positive value is simply ignored. Others, like Atari BASIC, ignored the parameter completely and used an internal hardware timer to produce random values, which was both faster and always randomized. Some blended the two options.

`RND` is very common in BASIC programs, especially in games. In most cases, the program actually desires an integer value, and code to the effect of `INT(RND(0)*X+0.5)` can be found in many programs. This bit of code is so common that some programs use a user-defined function to make references to this sequence of operations shorter; an example is *Super Star Trek*, which defines a function called `FNR` near the top of the program and then calls it from many locations.

Because this series of operations to produce a random integer takes some time to complete, a number of dialects offered ways to generate integer values directly in a single step. Unfortunately, there is no standard solution for this functionality, some use a separate function like `RAND`, while others modify `RND`. Among those that use `RND`, one common solution is that if the *aexp* produces any value between 0 and 1 it returns a floating point value as above, whereas larger positive values produce an integer value from 1 to the provided number. Apple's Integer BASIC and BBC BASIC are examples of this style.

Another common variation is found in Microsoft BASICs, although these vary across implementations. In these, a negative *aexp* is equivalent to a `RANDOMIZE` with the positive value, such that `X=RND(-1)` performs the same operations as `RANDOMIZE 1:X=RND(1)`. As almost every other dialect uses only positive values in *aexp*, or ignores *aexp* completely, this MS-style functionality is highly compatible, and is supported in RetroBASIC.

Because there is no way to know which of these optional varieties is being used, it is suggested that you use `RND(1)` in any case where it is not clearly specified.

#### Variations:

ANSI BASIC *requires* the parameter to be empty. Very few dialects followed this rule, although DEC and the APF Imagination Machine are two known to do so.

It is generally the case that any dialect that supports `RANDOMIZE` treats the *aexp* as a dummy. RetroBASIC is an exception, as it supports seeding in `RANDOMIZE` or `RND`.

Apple's Integer BASIC produces only integer values, as these were the only numbers it could work with. The system always returns a value between 0 and *aexp*-1, which made it an analog of the more typical floating point versions that never returned the upper bound. To simulate rolling dice, for instance, one would use `LET ROLL=RND(6)+1`.

Sinclair QL BASIC has a similar feature, but uses a more explicit syntax that allows a range to be specified, `RND(10 TO 50)`.

Commodore BASIC uses `RND(0)` to produce a "randomized random value", which is accomplished by mixing the last value with the value from an internal timer. As the timer functions vary across their computer models, the outcome of this function also varies. On most machines, the timer is always running and `RND(0)` operates as if it has been seeded with `RANDOMIZE`. On the Commodore 64 the timer does not start automatically and `RND(0)` will always return the same value. Note that this is different than dialects like Dartmouth; those will return different values for `RND(0)` every time it is called, although the *sequence* of values will always be the same (unless `RANDOMIZE`d). On the C64, the *value* is the same every time it is called as well as every time it is run. To address this, users were told to add `RND(-TI)` near the start of their programs, using the ticks counter, `TI`, as the seed. This is not needed in RetroBASIC, but will work as expected.

In AppleSoft BASIC, an *aexp* of zero causes the system to return the last value. This appears to be the same implementation as Commodore versions (which were based on the same original code), but without the ability to tie in a timer.

BBC BASIC supports the integer value syntax for *aexp* larger than zero, and this is often found in BBC programs. This returns the values 1 to *aexp*, inclusive, in contrast to Integer BASIC which is 0 up to *aexp*. It also supports seeding the random if passed a negative *aexp*, but with the twist that it returns the seed number passed in, not a new random number based on that seed. Like AppleSoft, `RND(0)` returns the last value generated by `RND(1)`. If the function is called with no *aexp* between the parens, it returns a random value between -2147483648 and 2147483647, that is, a 32-bit signed integer. Finally, the sequence is only started with the `RUN` or `CHAIN` commands, so calling it from the prompt in immediate mode will always return 0 until the program has started at least once.

#### See also:

* `RANDOMIZE`

#### Availability:

Support for negative values seeding the sequence was added in 1.9.1.
Support for integer values for *aexp* > 1 was added in 1.9.1.

<!-- TOC --><a name="sgnaexp"></a>
### `SGN`(*aexp*)

Returns —1 if *aexp* evaluates to a negative number, a 0 if *aexp* evaluates to 0, or a 1 if *aexp* evaluates to a positive number.

#### Variations:

Early Dartmouth dialects returned 1 for all positive numbers, including 0. Almost all later dialects, including RetroBASIC, return 0 in this case.

<!-- TOC --><a name="sqraexp"></a>
### `SQR`(*aexp*)

Returns the square root of the *aexp* which must be positive. If *aexp* is negative, an error will be raised.

<!-- TOC --><a name="uboundavaraexp-and-lboundavaraexp"></a>
### `LBOUND`(*avar*{,*aexp*}) and `UBOUND`(*avar*{,*aexp*})

Returns the lower and upper bounds of the array in *avar*, respectively. In RetroBASIC, the lower bound is normally zero, but will be 1 if `OPTION BASE 1` has been encountered. The upper bound is normally the value in the associated `DIM` statement, or 10 if the variable has not been `DIM`ensioned.

For multi-dimensional arrays, the optional *aexp* indicates which dimension to count, starting at one. If *aexp* is not included and the array is multi-dimensional, they return the values for the first dimension.

#### Examples:

    10 DIM A(25,15)
    20 PRINT "The length of dimension 1 is "UBOUND(A)
    30 PRINT "The length of dimension 2 is "UBOUND(A,2)
    40 PRINT "The length of B is "UBOUND(B)

Produces:

        The length of dimension 1 is 25
        The length of dimension 2 is 15
        The length of B is 10

#### See also:

* `OPTION BASE`

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

Apple Business BASIC on the Apple III used the function `TEN` to convert a hex string to decimal. This is not currently supported in RetroBASIC.

<!-- TOC --><a name="trigonometric-functions"></a>
## Trigonometric functions

Trigonometric functions in BASIC are normally carried out using radians. A few dialects have a feature to switch to degrees, but this is not currently supported in RetroBASIC.

<!-- TOC --><a name="acsaexp"></a>
### `ACS`(*aexp*)

Returns the arccosine of the variable or expression in parentheses.

#### Variations:

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

Sinclair QL BASIC uses `ATAN`, which is not used on any other of the Sinclair dialects. Most Sinclair's use `ARCTAN`.

<!-- TOC --><a name="cshcoshaexp"></a>
### \[`CSH`|`COSH`\](*aexp*)

Returns the hyperbolic cosine of the expression in parentheses.

<!-- TOC --><a name="cosaexp"></a>
### `COS`(*aexp*)

Returns the cosine of the expression in parentheses.

<!-- TOC --><a name="sinaexp"></a>
### `SIN`(*aexp*)

Returns the sine of the expression in parentheses.

<!-- TOC --><a name="snhsinh"></a>
### \[`SNH`|`SINH`\](*aexp*)

Returns the hyperbolic sine of the expression in parentheses.

<!-- TOC --><a name="tanaexp"></a>
### `TAN`(*aexp*)

Returns the tangent of the expression in parentheses.

<!-- TOC --><a name="tnhtanh"></a>
### \[`TNH`|`TANH`\](*aexp*)

Returns the hyperbolic tangent of the expression in parentheses.

<!-- TOC --><a name="string-functions"></a>
## String functions

<!-- TOC --><a name="ascsexp"></a>
### `ASC`(*sexp*)

This function returns the ASCII code number for the first character of the string expression *sexp*. For instance, `ASC("Hello")` returns 72, the decimal ASCII value for "H".

#### Variations:

Sinclair BASICs use `CODE` instead of `ASC`, which is further confused by the fact that the ZX machines do not use ASCII character encoding. `CODE` is not currently supported.

BASIC-PLUS on the DEC-10 uses `ASCII` instead of `ASC`. This is supported in RetroBASIC.

Acorn Atom BASIC used `CH`, for character.

MAXBASIC allowed a second parameter, a length, which returned a series of values, up to that many characters in the string.

Enterprise IS-BASIC uses `ORD` for no obvious reason.

#### Availability:

`ASCII` was added in 2.0.0.

<!-- TOC --><a name="chraexp"></a>
### `CHR$`(*aexp*)

Returns the character as a single-character string, represented by the ASCII code number in parentheses. `CHR$(72)` returns "H".

#### Notes:

The Sinclair ZX series do not use ASCII for their character encoding and will return different characters if passed a value from a program that assumes ASCII.

<!-- TOC --><a name="inkeydexp"></a>
### `INKEY$`(*dexp*)

This function returns the ASCII value of the key currently pressed on the keyboard. If no key is pressed when it is called, it returns 0. In either case, it immediately continues without waiting for user input, unlike `INPUT` or `GET`.

`INKEY$` was a later addition to BASIC and mostly used in interactive programs and games. The parameter is a dummy and can be left out, along with the parens, so `I$=INKEY$`, `I$=INKEY$()` and `I$=INKEY$(X)` are all valid in RetroBASIC.

#### Variations:

BBC BASIC will calculate *dexp* and if it is non-zero, wait for that many 1/100ths of a second for input, instead of continuing immediately.

The ORIC-1 and ATMOS used `KEY$`.

`KEY$` was also used on the APF Imagination Machine, but this used *dexp* as a parameter selecting a device, 0 was the keyboard, and 1 and 2 were the right and left controllers.

AppleSoft BASIC and Apple Business BASIC used the `GET` *sexp* statement for this functionality.

A number of BASICs, including AppleSoft, Apple Business, Atari, BBC, etc., also used the `GET` statement for similar functionality, but most of these waited for a keystroke before continuing, and thus did not serve exactly the same purpose. On these platforms, `INKEY$` was often implemented using `USR` or `PEEK`. On AppleSoft, one could optionally use an *aexp*, with some caveats. Apple versions also did not echo the typed character.

<!-- TOC --><a name="instrindexpos"></a>
### \[`INSTR`|`INDEX`|`POS`\](*sexp1*,*sexp2*[,*aexp*])

`INSTR` searches the string *sexp1* for the first occurrence of *sexp2*, returning the numerical location of the match. If no match is found, `INSTR` returns 0. If the optional *aexp* is provided, searching starts at that index instead.

 `INDEX` and `POS` are aliases for the same feature found in some dialects. Note that `POS` is also used as a system function in some dialects (see below). RetroBASIC can determine which variation of `POS` is being used based on the parameters and supports both uses of `POS` in the same program.
 
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

<!-- TOC --><a name="leftsexpaexp"></a>
### `LEFT$`(*sexp*,*aexp*)

Returns a new string containing the left-most *aexp* characters from the string *sexp*. `LEFT$("Hello, World!",5)` returns "Hello".

<!-- TOC --><a name="midsegsubstrsubstring"></a>
### \[`MID$`|`SEG$`|`SUBSTR$`|`SUBSTRING$`\](*sexp*,*aexp1*[,*aexp2*])

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

Apple Business BASIC has the similarly-named `SUB$`, but this is short for "substitute", not "substring". This performs replacement of one portion of a string with another, which is useful in a system with MID/LEFT/RIGHT where this operation can be complex. For instance, `SUB$("Hello!", "XX", 2)` produces HXXlo!
         
<!-- TOC --><a name="rightsexpaexp"></a>
### `RIGHT$`(*sexp*,*aexp*)

Returns a new string containing the right-most *aexp* characters from the string *sexp*. `RIGHT$("Hello, World!",6)` returns "World!".

<!-- TOC --><a name="spcspaspace"></a>
### \[`SPC`|`SPA`|`SPACE$`\](*aexp*)

`SPC` returns a string containing the number of space characters in *aexp*. `SPA` is the alternate spelling for the same function found in HP, while `SPACE$` is found in other dialects.

#### Examples:

    PRINT "Hello";SPC(10);"Hello"

Produces:

    Hello          Hello

<!-- TOC --><a name="stringrepeat-aexpsexpaexp2"></a>
### {`STRING$`|`REPEAT$`} (*aexp*,[*sexp*|*aexp2*])

`STRING$` makes a new string containing *aexp* copies of the second parameter. The second parameter can be any string if it is provided as *sexp*, or it can be a single ASCII value if it is an *aexp*. `STRING$` can be used to provide the same functionality as `SPC` if *sexp* contains a single space or *aexp2* produces the value 32.

#### Examples:

    PRINT STRING$(3, "Hello")

Produces:

    HelloHelloHello

#### Variations:

Early instances of `STRING$`, in BASIC-PLUS for instance, only support a single ASCII character value in the second parameter. The ability to use a string parameter appeared later; it was available on the TRS-80, but it is unlikely that was the first example.

`REPEAT$` is an alternative listed in Lien's *The BASIC Handbook*, but it does not mention which dialects use it. RetroBASIC does support this variation.

#### Availability:

`REPEAT$` was added in 2.0.0.

<!-- TOC --><a name="straexp"></a>
### `STR$`(*aexp*)

This function returns a string that represents the ASCII representation of the number in *aexp*. For instance, if the *aexp* evaluates to 25, this function returns the string "25". The `PRINT` statement performs this conversion automatically, so `STR$` is normally used when constructing strings from multiple parts, like `A$="Hello, "+STR$(25)+" times."`, which produces "Hello, 25 times.".

<!-- TOC --><a name="valsexp"></a>
### `VAL`(*sexp*)

This function returns a number of the same value as the number stored as a string, performing the opposite operation of the `STR$` function. For instance, if *sexp* evaluates to "25", this function will return the numerical value 25. `VAL` is generally more common than `STR$` as it is commonly used to convert user inputs into numbers.

#### Variations:

Digital Group BASIC uses `NUM` instead of `VAL` for this functionality. In most dialects, at least those supporing matrix statements, `NUM` returns the number of items typed in a `MAT INPUT` statement. RetroBASIC supports both of these uses of `NUM`, as the matrix version has no parameters while the `VAL`-like version requires a single string parameter.

<!-- TOC --><a name="ucasesexp-and-lcasesexp"></a>
### `UCASE$`(*sexp*) and `LCASE$`(*sexp*)

`UCASE$` and `LCASE$` convert a string to upper case or lower case, respectively, and return the new string. The original string in *sexp* is unchanged.

#### Examples:

    PRINT UCASE$("hello world"),LCASE$("Hello World")

Produces:

    HELLO WORLD         hello world
    
<!-- TOC --><a name="string-slicing"></a>
## String slicing

<!-- TOC --><a name="svaraexptoaexp"></a>
### *svar*{(|[}*aexp*[{,|:|TO}*aexp*]{)|]}

String slicing is an alternative way to manipulate strings and produce substrings. A "slice" is a substring defined as a starting and ending location within an existing string. Although slicing instructions are not functions in the traditional sense, they produce results similar to the `MID/LEFT/RIGHT` functions seen in the DEC and Microsoft dialects. The major difference between the slicing concept and string functions is that the functions take a location and length, not start and end locations. This can result in off-by-one errors when converting code from one system to another.

Slicing syntax is generally similar to accessing a slot in an array, but the exact syntax varies. For instance, in most dialects `A$(1,5)` returns a slice with the first five characters of A$, which produces the same result as `MID$(A$,1,5)` or `LEFT(A$,5)`. They also vary in the way the parameters are separated, most dialects use a comma, but Sinclair uses the `TO` keyword, like `A$(1 TO 5)` and the (little used) Full BASIC used the colon, `A$(1:5)`.

Most slicing implementations allow one or two parameters, with the second parameter optional. Generally, if there is only one parameter it indicates a single character at that location, thus `A$(5)` is the fifth character in the string. To access the portion of the string after a given location, most dialects allowed the second parameter to be empty, `A$(5,)` means "character 5 to the end of the string". This is very useful, as it means you don't have to know the length of the string when performing common manipulations.

Sinclair and Full BASIC allow either parameter to be optional, `A$( TO 5)` and `A$(:5)` (respectively) mean "the portion of A$ from the start to location 5". Since the starting position of the string is always 1, this syntax performs the equivalent to a `LEFT$` operation.

RetroBASIC is designed to run any program that does not use platform-specific features. As string arrays are relatively commonly, it has to support them. This leads to it having to decide whether a reference in code like `A$(5)` is a slice or an array access. In the case that the syntax is clear, like Sinclair or Full, there is no ambiguity and one can use string arrays and string slicing in the same program using syntax like `A$(5)(5 TO 10)`, meaning the substring from the 5th to 10th character on in the string stored in slot five of `A$`.

To work with the dialects that do not have unique syntax, like Dartmouth or Atari BASIC, RetroBASIC offers the `--slicing` command-line switch. When turned on, using `--slicing=1`, all "array like" parameters applied to strings are considered slices.

#### Examples:

Slicing is useful for many types of manipulation that are expensive to perform using functions. For instance, slicing can be used to assign strings into character locations in another string. Consider this code in a MS-derived dialect:

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

In slicing systems, this is accomplished with the assignment:

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

Had HP selected *one* of these two to indicate slicing, instead of both, or alternately used a different definition, like Sinclair's `A$(1 TO 10)`, then other BASICs copying them could implement string arrays and slicing. For instance, `A$(2,3)[1,1]` would return the first character of the string in slot (2,3) of the array of strings.

#### Variations:

String slicing was common in early microcomputer BASICs, which were often written by programmers that were familiar with HP BASIC. The best example is Apple's Integer BASIC, which Woz wrote based on a HP manual while he worked at HP. Others also copied this style, Atari and North Star BASIC for instance.

One dialect that did support arrays *and* slicing was SCELBAL, which indicated a slice with a leading colon. Thus `A$(1)` refers to the entire string in slot one in a string array, while `A$(1:5:5)` is the fifth character in that string. To slice a string that was not in an array, the slot was simply left off: `A$(:1:5)` returns the first five characters in A$.

Another dialect that supported arrays and slicing was ANSI Full BASIC, which used a separate colon-separated parameter. So `A$(1)(1:1)` is the first character in the first slot of the A$ array.

#### Availability:

Sinclair `TO` support was added in 1.9.0.

<!-- TOC --><a name="system-functions"></a>
## System functions

<!-- TOC --><a name="fredexp"></a>
### `FRE`(*dexp*)

This function returns the number of bytes of user RAM left. Its primary use is to check the amount of memory left before performing operations that require a large amount of memory.

In RetroBASIC, `FRE` always returns zero.

#### Variations:

Those dialects that allow the program to reserve space in memory for strings, typically using `CLEAR`, generally also allow that amount to be checked by passing in a string variable name. In this case, `FRE()` will return the total amount of memory available, or the amount of memory available for program code, while `FRE(A$)`, where `A$` in this example can be any string variable name, will return the amount of memory in the string area. In early dialects, that was often as little as 50 or 200 bytes.

The TRS-80 II and Genie/Color Genie uses `MEM` for this function, while `FRE` returns string space. The Dragon 32 uses `SIZE`.

### `NUM`[(*sexp*)]

`NUM` is a function with two completely different uses.

The main purpose of this function is to return the number of items typed into the last `INPUT` or `MAT INPUT` statement. This was initially introduced in dialects that had matrix support, as it was common for users to enter a blank value in order to stop the `INPUT` statement in the case of large matricies. The program could then use `NUM` to test whether the entire matrix had been filled out, or, for instance, fill out the slots for any non-entered values with zero or some other value.

In RetroBASIC, the functionality of `NUM` has been expanded to also work with conventional `INPUT` statements, as the same issues arise in this case and `NUM` can be just as useful here.

The value of `NUM` is reset at the start of every `INPUT` or `MAT INPUT`, as well as when running a `CLEAR`/`CLR` statement.

The other use of `NUM` is to support the dialect-specific funtion found in Digital Group BASICs, where it is the equivalent of `VAL`. This version will be called if a string expression is provided in *sexp*.

#### Availability:

`NUM` was added in 2.0.2.

<!-- TOC --><a name="peekaexp"></a>
### `PEEK`(*aexp*)

Returns the contents of a specified memory address location *aexp*. The address specified must be an integer or an arithmetic expression that evaluates to an integer between 0 and (typically) 65535 and represents the memory address in decimal notation (not hexadecimal). The number returned will also be a decimal integer with a range from 0 to 255.

In RetroBASIC, `PEEK` always returns zero.

#### Variations:

Digital Group MAXI-BASIC and North Star BASIC used `EXAM` for this purpose.

Digital Group Opus BASIC used `FETCH` for this purpose.

A number of later BASICs added a variation of `PEEK` that allowed a 16-bit value to be read in a single statement, an example is the `DPEEK` function in Turbo-BASIC XL on the Atari.

#### See also:

* `POKE`

<!-- TOC --><a name="posdexp"></a>
### `POS`(*dexp*)

When POS is called with zero or one dummy parameter, it returns the current position of the cursor. This can be called after `PRINT` and `INPUT` statements to provide more control over output. When called with more parameters, it acts as an alias for `INSTR`, and is covered in the string functions section, above.

<!-- TOC --><a name="linaexp"></a>
### `LIN`(*aexp*)

`LIN` produces *aexp* newlines in the output. The exact nature of `LIN` varies across platforms. On HP systems it is a standalone statement, whereas others treat it as a pseudo-function like `TAB`. RetroBASIC treats it as a true function that returns a string, meaning it has to be placed in `PRINT` statements to produce output.

#### Examples:

    PRINT LIN(3);"Hello"

Produces:




    Hello

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
### `TIME`[(*dexp*)] and `TIME=`*aexp*

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

This means it is 10 AM, 24 minutes and 56 seconds.

<!-- TOC --><a name="usraexp"></a>
### `USR`(*aexp*)

`USR` is one common method that BASIC interpreters used to call machine language code, the other being `CALL` and `SYSTEM`. The difference between `CALL` and `USR` is that `USR` expects a return value to be left in a particular location in memory, and the function returns that value. Thus if one uses `A=USR(1000)` to call a routine that returns the status of the fire button on a joystick, `A` will be set to that value.

In RetroBASIC, `USR` always returns zero.

#### Variations:

DEC's BASIC-PLUS, on TOPS at least, used `USR$` to return a listing of the files in the user's directory.

## File handling

Most versions of BASIC include some form of file handling based on the `OPEN` and `CLOSE` statements. Unfortunately, that is where the commonality ends. Devices on early computers varied widely in their underlying concepts as well as their implementations, such that sending data to one device, like a tape drive, would have entirely different syntax as sending the same data to a printer. Even those dialects that had the same underlying code, like Commodore BASIC and AppleSoft, vary too much to allow code to be portable, and often differ even between models from the same company, like the PET vs. C64.

One of the goals for RetroBASIC is to run known-good programs with few or no changes to the original code. In the case of file handling this is simply not possible. One could choose a target platform and copy that syntax, say the C64, but this would force every other platform to be changed to that style. Instead, RetroBASIC implements the same basic set of file statements as most BASICs, but uses Unix-like syntax to refer to the files and devices. All file input/output takes place through a filename and uses Unix-like modes for access, "r" for read, "w" for write, and "a" for append. The filename may contain a path, which can include path elements like `.`, `..` and `~`, which will be correctly expanded into complete paths.

When a file is `OPEN`ed, it is assigned a number. The name for these also varies, MS calls these "logical file numbers" while Atari called them "IOCB numbers". RetroBASIC refers to these as "channels". Once a channel is opened, any input or output to that device is handled using that channel number. RetroBASIC allows channel numbers between 0 and 255 and allows a maximum of 16 channels to be open at a time. Although these limits are arbitrary and much less than any modern machine can handle, a BASIC program that runs outside these limits is likely doing so due to an error in the code, so breaking either limit returns an error in RetroBASIC.

### `OPEN`[`#`] *aexp*,*sexp1*,*sexp2*

Opens a channel with the number *aexp*, attached to the physical file at path/file *sexp1* with access mode *sexp2*. *aexp* must be between 0 and 255, and an error will be returned if that channel is already open or if there are too many files opened already.

The file name in *sexp1* can be simply the name of a file, or contain a path as well. If there is no path, the file will be opened in the current directory, normally the same location as the RetroBASIC executable. If a path is provided, it will be expanded into a complete path and checked to ensure that the user can access the resulting file. Any given path/file can only be opened once, you cannot, for instance, open a file for writing in one channel and reading in another.

The mode in *sexp2* is one of three single-character values, "r" for reading, "w" for writing, and "a" for appending, that is, writing to the end of an existing file. If the mode is "r" or "a", the file must already exist and will return an error otherwise. If the mode is "w" the file *cannot* already exist, and will return an error if it does.

#### Variations:

The vast majority of dialects use `OPEN` without a following `#`, but Atari BASIC and Apple Business BASIC demand it. RetroBASIC allows either format.

### `CLOSE`[`#`] *aexp*

Closes the channel *aexp* and removes it from the list of active channels. Will return an error if that channel number is not currently open.

The `LOAD`, `CLEAR`/`CLR`, `NEW` and `RUN` statements close all files. The `CHAIN` command (currently unsupported) does *not* close files.

#### Variations:

As with `OPEN`, most dialects use `CLOSE` without a following `#`, with Atari BASIC being an exception. Apple Business BASIC allows the # to be optional, in which case it can be any expression that returns a number. RetroBASIC allows either format.

### `PRINT#` *aexp*,[*exp*{|[;|,]},...]

`PRINT#` works exactly like the standard `PRINT` statement, but directs the output to channel *aexp*. If the channel is not open, or it is opened only for read access, RetroBASIC will return an error.

### `INPUT#` *aexp*,[*exp*{|[;|,]},...]

`INPUT#` works in a fashion similar to the standard `INPUT` statement, but does not print any user-supplied prompt strings or the question mark. It reads one line from the file and then parses it using the same logic as a normal `INPUT`, meaning that if there are fewer values in the read line than there are variables in the list, the next line of input will be read until the variables all have values or the end of the file is reached.


<!-- TOC --><a name="matrix-statements-operators-and-functions"></a>
## Matrix statements, operators and functions

Later versions of Dartmouth BASIC introduced a series of matrix related statements and functions that operate on entire arrays with a single operation. These sorts of operations can also be implemented using FOR/NEXT loops, but using a single instruction leads to higher performance and more clearly indicates the actual intent of the program. The downside is that only a few dialects supported these commands, mostly on mainframes, so using them also leads to portability issues.

The basic idea is that the common statements `PRINT`, `INPUT` and `READ` now have matrix-aware versions, `MAT PRINT`, `MAT INPUT` and `MAT READ`. When called, these versions loop over the array and perform the statement on all of the slots within it. So, for instance, `MAT PRINT A` will print out the entire array instead of having to use a FOR loop to print each slot separately. There are also a number of matrix operators and functions. For instance, one can use the assignment statement `MAT A=ZER` to set all the slots in a matrix to 0. All of these instructions begin with the statement keyword `MAT`.

The system allows the dimensions of the array to be specified to limit the slots that a function will operate on. In the following documentation, we will refer to this as a *subarray*. For instance, if a program starts with `DIM A(10,10)`, then `MAT A=ZER` will assign 0 to all of the slots in A, 10 by 10, whereas `MAT A=ZER(5,5)` will change the values only in the subarray of 1..5 in the rows and columns, leaving the other values, in 6..10, unchanged. This works as long as the largest slot number, M times N, is less than the total number of slots original dimensioned. For instance, it is acceptable to call `MAT A=DET(15,1)`, despite A being DIMmed (10,10). This is very much at odds with normal BASIC behavior, where a reference to `A(15,1)` would cause a runtime error, `?BAD SUBSCRIPT`.

When subarrays are used, the size of the original array is changed. So in this example, A will now be a (5,5) array. This is required to properly support any subsequent matrix operations. For instance, after `MAT A=ZER(5,5)`, a `MAT PRINT A` needs to know it has to print a 5 by 5 array, not the original 10 by 10. These bounds are also used in non-matrix operations, so after redimensioning a reference to `A(7,2)` will now fail with `?BAD SUBSCRIPT`.

IBM's BASIC for the 5100 allowed the subarray limits to be placed on either side of the equals sign, such that `MAT A(5,5)=ZER` would have the same result as `MAT A=ZER(5,5)`. This allows a subarray to be used even on operations where it would normally not be allowed. For instance, when adding two matrixes, the two inputs have to be the same size and subarrays cannot be defined on them. The IBM syntax allows the result to be resized after calculation, so one might `MAT A(3,3)=B+C` to make a 3 by 3 matrix from two 5 by 5 matrixes. As only one subarray specification can be used in any given statement, if multiple ones are found, RetroBASIC uses the rightmost one, such that `MAT A(5,5)=B(10,10)` will use (10,10) as the limits.

One "gotcha" to be aware of is that items in the slots at the zero indexes are ignored. So in a vector, the first slot is ignored, while in a matrix, all of the slots in the zero column and row are ignored. This may lead to unexpected results if data has been inserted in these slots using other statements and then manipulated with the matrix commands, which may cause that data to be cleared out, or alternately, data in those slots to appear in non-zero slots. For instance, in the original 10 by 10 dimension version of `A`, slot 10 holds the value for index (1,0), if a value was placed in this slot and the array redimensioned to 5 by 5, that value is now in slot (2, 4), and will now be used in subsequent matrix operations. For this reason, BASIC code should be careful to ensure the slots in the zero indexes are never assigned values, and should generally zero out arrays between uses to avoid data being left behind.

Another issue to be aware of is that the matrix functions can only be used one at a time, in contrast to normal math expressions. For instance, one can `LET A=B+C-D`, but it is not possible to `MAT A=B+C-D`. This is due to the limited memory of the machines of the era - there was simply not enough memoty store the values of intermediate steps like the `B+C`. Although a lack of memory is no longer an issue on modern machines, RetroBASIC follows this rule in keeping with its goal for remaining compatible where possible.

Dartmouth BASIC did not allow the same matrix to appear on both sides of most operations, for instance one could not `MAT A=TRN(A)`. This was legal in other variants and is supported in RetroBASIC for that reason.

And finally, like Dartmouth's `CHANGE` statement, `MAT` instructions always look for an array variable with the given name, even if there are no parentheses. This means that `MAT PRINT A` will *not* find the variable named `A`, but will look for the *array* `A`, in effect, `A()`. This means you can `LET A=5:DIM A(5,5):A(3,3)=10` and only the 10 will appear in a `MAT PRINT A`.

According to Lien's *The BASIC Handbook*, "Some computers allow the word MAT to be optional", and suggests these allow `A=B` to perform what would normally be `MAT A=B`. However, no particular variant is mentioned, nor has one been found. Given most dialects treat A and A() as two different variables, it is not clear how they would understand the difference between normal statements and matrix statements. RetroBASIC does not allow the `MAT` to be left off.

<!-- TOC --><a name="matrix-statements"></a>
### Matrix statements

There are only four matrix statements; assignment (`LET`), `PRINT`, `INPUT` and `READ`. All of these loop over the list of variables and then perform their normal actions on all of the elements in the array or the selected subarray. For instance, `MAT READ A` will read one value from the program's `DATA` statements for each slot in the matrix A, ignoring the zero slots. Thus a `MAT READ A` on a variable defined `DIM A(3,3)` will read nine values.

<!-- TOC --><a name="mat-let-var1aexpaexpvar2aexpaexp-exp-"></a>
### `MAT` [`LET`] *var1*[`(`*aexp*,*aexp*`)`]`=[`*var2*[`(`*aexp*,*aexp*`)`] | `(` *exp* `)`]

Assigns the values in *var2* to the corresponding slots in *var1*, or the value of *exp* into all the slots of *var1*,. Works with both numbers and strings.

If *var2* has more slots than *var1*, the statement will fail. If *var2* has fewer slots than *var1*, *var1* will be redimensioned to match *var2*. If the optional dimensions are provided on *var1* or *var2*, *var1* will be redimensioned to that size, and fail if it does not have enough slots available to do so.

#### Variations:

The ability to place an expression in parens on the right hand side comes from the IBM 5100, a few other dialects also supported this. This is allowed in all MAT statements in RetroBASIC.

McD DATA/BASIC allowed you to use assignment to assign a numeric value to all the slots, `MAT A=5`, or `MAT A=0` without the parens. It also allowed you to assign a 1-D to 2-D array and vice versa, in "row major order", meaning that if you `DIM X(5,2),Y(10)` and then `MAT Y=X(2,3)` would copy the value into Y's slot 2x2+3 = slot 7. This capability appears in no other dialect, and neither of these features are supported in RetroBASIC.

#### Examples:

    10 DIM A(3,4),B(3,4),C(2,3)
    20 MAT READ A
    20 MAT READ B
    30 MAT READ C
    100 MAT A=B
    110 MAT A=C
    120 MAT C=B(2,3)
    130 MAT C=B
    200 DATA ...

In this example, line 100 will overwrite the values in A with those in B. The dimensions are the same so A remains otherwise unchanged. Line 110 will redimension A to (2,3) to match the dimensions of C, and then copy the values. Line 120 copies only the (2,3) elements from B, so C does not have to be redimensioned. Line 140 will cause a `?BAD SUBSCRIPT` error as C is not large enough to hold all the values in B.

<!-- TOC --><a name="mat-print-avaravar"></a>
### `MAT PRINT` *avar*[,|;][*avar*{|[;|,]},...]]

`MAT PRINT` works in a fashion similar to `PRINT`, with a few significant differences. One is that there is no allowance for constants or other expression types, only array variables and separators are valid parameters. Any other type appearing in the parameter list will cause a `?TYPE MISMATCH`. Additionally, there must be at least one variable in the statement, an "empty" `MAT PRINT` is not allowed. This contrasts with an empty `PRINT`, which will print a blank line.

One oddity is that the output differs depending on the type of array. If the array is 1-d, a vector, it will be considered a column and normally printed with each value on a separate line. In contrast, a matrix will be printed in a 2-d fashion, rows and columns. In both cases, the layout can be changed by adding a comma or semicolon, which operate in a fashion similar to the normal `PRINT` statement, adjusting the width between the numbers. When a comma or semi is added after a vector, this causes it to print out in a single row, not in column layout. Additionally, if you want to have a vector that prints like a matrix, you can define it with zero rows, `DIM A(0,5)` will print in row layout.

#### Examples:

    10 DIM A(5),B(3,3)
    20 MAT READ A
    30 MAT READ B
    40 MAT PRINT A
    50 MAT PRINT B;
    100 DATA 1,2,3,4,5
    110 DATA 1,2,3,4,5,6,7,8,9

This code reads a vector of 5 values, then a 3 by 3 matrix. It then prints:

    1
    2
    3
    4
    5
    1 2 3
    4 5 6
    7 8 9
  
`A` is a vector, or "column array", and thus printed out vertically. The second `MAT PRINT` has a trailing semicolon, which, as is the case in a normal `PRINT`, causes the output to be closely spaced.

#### Variations:

According to *Illustrating BASIC*, some, or many, versions of MAT PRINT add an empty line between the rows of a matrix. RetroBASIC does not do this.

<!-- TOC --><a name="mat-input-avaravar"></a>
### `MAT INPUT` *avar*[,*avar*,...]]

`MAT INPUT` reads multiple values from the command line, filling the vector or matrix by column and then row. Unlike a normal `INPUT`, no prompt is allowed, and only array variables can be used.

`MAT INPUT` normally reads a value for every slot in the array, similar to `MAT READ`. However, it parses this data from a single input line, which may not contain enough values to fully populate the array. In this case, no error is reported, and the remaining slots are simply ignored and will contain any value they did before. It sets the pseudo-variable `NUM` to the number of items read, so you can check for this case in code.

*Illustrating BASIC* suggests you should *not* use `MAT INPUT`. This is because the command does not allow a prompt and there is no chance to print anything between each value being input. Worse, there is no way to test the results one-by-one, you will only know there is an issue after all of the values have been typed in and will now have to be re-entered from the start if there is a problem. Using an `INPUT` in a `FOR` loop allows the values to be tested and re-typed individually.

There is also the issue that terminals of the era did not allow you to type more values than could fit on a single line and different implementations offered different solutions to this problem, or none at all. Dartmouth BASIC, for instance, allowed you to type an ampersand to indicate more data would follow on the next line, but this was not universal across implementations. For all of these reasons *Illustrating BASIC* concludes "So for the sake of portability, if nothing else, don't use 'MAT INPUT' for demanding data from the keyboard."

#### See also:

* `NUM`

<!-- TOC --><a name="matrix-operators"></a>
### Matrix operators

The matrix system includes mathematical operators that mirror those that apply to scalar values. Dartmouth has assignment, addition, subtraction and multiplication. Generally, these instructions require the variables to be of the same type and dimensions, you can add a matrix to a matrix or vector to vector, but you cannot add a vector to a matrix. Dartmouth also added the ability to multiply all of the elements by a scalar value, which uses a separate format that demands the scalar expression be in parentheses and be the left-hand-side of the operator. Scalar addition, subtraction and division is not supported.

#### Examples:

    MAT A=B

Assigns the values in B to the corresponding slot in A, making a copy of B. A must be DIMensioned large enough to hold all of the elements in B, and after this operation completes, A will have the same dimensions as B. If B has fewer elements than A, the leftover space is unused. One can also:

    MAT A=B(5,5)

Which assigns the values of B(1,1) through B(5,5) into A. A will now be a 5x5 matrix. RetroBASIC also allows you to use the IBM 5100 version of the subarray specification:

    MAT A(5,5)=B

Also following the 5100 models, RetroBASIC also allows the right-hand-side to be an expression that returns a value instead of a second array. In this case, the value will be assigned to all of the slots in the destination array. To indicate this you have to place the expression in parens:

    MAT A=(5)

Will assign the value "5" to every slot in A. This syntax can be used to replace calls to ZER and CON, but this should be avoided for compatibility reasons.

    MAT A=B+C

Adds the value in slot (m,n) in B with the value in slot (m,n) in C, and places the result in slot (m,n) in A. This is only valid if B and C have the same dimensions, if they differ, a runtime error will occur. If the result array has different dimensions, it will be redimensioned to fit the result if possible.

    MAT A=B*C

Multiplies the values in slot (m,n) in B with the value in slot (o,p) in C. A is resized to (m,p) if possible.

    MAT A=(5)*B

Scalar multiplication; calculates the value of the expression on the left, in this case the constant 5, and then multiplies all the values in B by that value and places the results in A. A will be resized to match B.

<!-- TOC --><a name="mat-avarconaexp"></a>
### `MAT` *avar*`=CON`[(*aexp*,...)]

Changes all of the slots in *avar* to 1, or the slots in the subarray. Works for both 1-d vectors and 2-d matrixes. Cannot be used with string arrays.

<!-- TOC --><a name="mat-avaridnaexp"></a>
### `MAT` *avar*`=IDN`[(*aexp*,...)]

Places 1's in the diagonal of a 2-d matrix, creating an *identity matrix*. A runtime error will occur if *avar* is a vector or scalar, and the array must be square. Cannot be used with string arrays.

<!-- TOC --><a name="mat-avar1invavar2nvar"></a>
### `MAT` *avar1*`=INV(`*avar2*`)[`,`*nvar*]

Inverts the matrix *avar2*, if possible, and places the results in *avar1*. A runtime error will occur if *avar2* is not a square matrix or contains strings.

A side-effect of running the INV is that the `DET` function will now return the determinant. If DET is zero, the inversion did not work and should not be used. The determinant will also be placed in the optional *nvar*, if provided, so `MAT A=INV(B),D` will result in the inverted matrix in A (if it worked) and the determinant value in D.

#### Variations:

The optional *nvar* for the determinant was introduced in IBM 5100 BASIC.

<!-- TOC --><a name="mat-var1trnvar2"></a>
### `MAT` *var1*`=TRN(`*var2*`)`

Transposes *var2*, rotating it so columns become rows and rows columns, and places the result in *var1*. This may be used with numeric or string arrays.

<!-- TOC --><a name="mat-varzeraexp"></a>
### `MAT` *var*`=ZER`[(*aexp*,...)]

Changes all of the slots in *avar* to 0, or if the optional *aexp*s are provided, the result array will be resized to the subarray. Works for both 1-d vectors and 2-d matrixes, and matrixes do not have to be square. This statement was widely used in Dartmouth programs in order to quickly reset or resize an array, even in programs that did not make use of other matrix features.

`ZER` can also be used with string arrays, which sets all values to the empty string.

### `DET`[(*aexp*)]

`DET` is a scalar function that returns the determinant calculated on the last call of `INV`. It is reset to zero when the program is run or `CLEAR`ed. Very small values, under 0.01, should generally be considered a sign that the inversion failed and the resulting matrix should not be used.

#### Examples:

   100 DIM A(5,5),B(5,5)
   110 MAT READ A
   120 MAT B=INV(A)
   130 IF ABS(DET)<0.01 THEN PRINT "MATRIX INVERSION FAILED"

<!-- TOC --><a name="error-handling"></a>
## Error handling

Some versions of BASIC provide rudimentary error handling using the `TRAP` or `ON ERROR` statements. These will both be referred to here as *traps*. When a trap is turned on and an error occurs, or is *raised*, instead of printing the error message and stopping the program, the system branches to the indicated line and execution continues.

The code at this line is known as an *error handler*. When an error occurs, the error number and line number are placed in memory and then the system performs a `GOTO` into the handler. The handler allows the program to examine the error and decide how to continue. Most dialects allow the error number to be examined, as well as the line number where the error occurred. Jumping into the handler does not clear these values out, as one will generally want to examine them in the handler code. This is the purpose of the `RESUME` statement seen in some dialects, which clears the error codes and returns to the point where the error occurred. A `NEW`, `CLR` and `RUN` also clear out these values.

Dialects differ significantly on the details of how these features are turned on and off, and how the error can be examined and recovered. For instance, in Applesoft BASIC, which supports the `ONERR` statement, the error number is discovered using `PEEK(222)`. On the Atari, which uses `TRAP`, it is `PEEK(195)`. One of the few contemporary dialects that directly supported reading the error number was Commodore BASIC, which used a system variable `ER` that was set to the error number and `EL` which held the line number. Attempting to assign a value to these would cause an error. Unfortunately, these are valid variable names, which meant that programs that used these as normal variables would cause errors when run under 3.5. RetroBASIC implements these as functions instead of variables, `ERR()` for error number and `ERL()` for error line, which avoids this problem.

The simple trap concept used in BASIC is subject to a number of problems. Among these is that if an error occurs *in* the handler, then it can trap back into itself and cause an infinite loop. Additionally, few, if any, dialects allow only specific errors to be trapped, it's normally all or nothing, which means the handler has to be very generic as it might receive any error, not just the ones it was written to handle.

<!-- TOC --><a name="trapon-error-gotoonerr-goto-aexp"></a>
### {`TRAP`|`ON ERROR GOTO`|`ONERR GOTO`} [*aexp*]

When any of these equivalent statements is encountered in a program, the *aexp* is evaluated, converted to a line number, and then stored for future reference. If an error occurs any time after the statement is encountered, execution will branch to the line number in *aexp*. If that line number does not exist, an error will be printed and execution will stop.

The method of turning the trap off differs across dialects. In Commodore BASIC, one uses `TRAP` with no parameter, in Atari BASIC you `TRAP` with any line number above 32767, and in AppleSoft one has to `POKE 216,0`. In RetroBASIC, traps are turned off with an empty parameter or any expression that evaluates to zero or a negative value.

Note that `ON ERROR` can only be used with a `GOTO`, in contrast to a normal `ON` statement which also allows `GOSUB`. Using `GOSUB` here is not allowed and will return a syntax error prior to the program running.

<!-- TOC --><a name="errorraise-aexp"></a>
### {`ERROR`|`RAISE`} *aexp*

Causes an error to be raised with the error number *aexp*. Generally used for testing purposes.

<!-- TOC --><a name="resume-next-aexp"></a>
### `RESUME` [`NEXT`, *aexp*]

When a handler is complete, `RESUME` is used to clear out the error condition and return execution to the main code. It is similar in concept to the `RETURN` statement used with `GOSUB`. If a `RESUME` statement is executed with no active trap being set, an error will occur, similar to encountering a `RETURN` with no corresponding `GOSUB`.

If the statement is used with no parameter, execution returns to the start of the line where the error occurred. If *aexp* is provided, it performs the equivalent of a `GOTO` to the provided line number. Using `NEXT` as the parameter tells it to return to the statement *after* the error, which is likely the most useful option in most cases.

<!-- TOC --><a name="erl"></a>
### `ERL()`

Returns the line number where the last error occurred. `RESUME` resets this to 0. The parens are optional.

<!-- TOC --><a name="err-and-ern"></a>
### `ERR()` and `ERN()`

Returns the error number for the last error. `ERN` is often used as the input to `ERR$`. `RESUME` resets this to 0. The parens are optional.

#### Variations:

TRS-80 Level II BASIC stores a value in the ERR function that does not equal the actual error code. In TRS-80 programs, you will see the value in ERR being divided by 2 and then adding 1 to get the actual value.

Some versions of HP BASIC use `ERRN` instead of `ERR`. This is not currently supported in RetroBASIC.

<!-- TOC --><a name="erraexp"></a>
### `ERR$(`*aexp*`)`

Returns a string with the error message for a given error number. This function can be called at any time, an error does not have to be trapped for it to work. A list of the codes and their messages follows.

<!-- TOC --><a name="example"></a>
### Example

The following code illustrates a typical handler system using all of the functionality above:

    100 TRAP 2000
    110 RAISE 21:PRINT " ... CONTINUED"
    120 END
    2000 REM TRAP ROUTINE
    2010 PRINT ERR; ERR$(ERR) " ERROR IN LINE" ERL "!"
    2020 RESUME NEXT
    
This program starts by setting a trap and then raising a syntax error, error 21. That causes it to jump into the handler at line 2000, which prints the error number, string and line number. The `RESUME NEXT` then picks up execution where it left off, so the `PRINT` on line 110 is executed. The result is:

    21 SYNTAX ERROR IN LINE 110!
    ... CONTINUED

<!-- TOC --><a name="error-codes"></a>
## Error codes

RetroBASIC's error codes are mostly modelled on Commodore BASIC 3.5 seen on the Commodore 128, as their list is fairly generic. A few additional errors have been added to handle new functionality. Others have been left out as they apply to specific tasks like operating the cassette tape. Not all of these codes can occur in RetroBASIC, but have been added for completeness.

<!-- This simulates a definition list by placing two spaces behind the first two lines of each entry. Be careful with edits! -->
0  
(none)  
There is no current error code. Commodore BASIC 3.5 used -1 for this.

1  
TOO MANY FILES  
The program is attempting to open a file with too many already open.

2  
FILE OPEN  
Attempt to open a file that is already open.

3  
FILE NOT OPEN  
Attempt to use a file handle that has not been opened.

4  
FILE NOT FOUND  
Attempt to open a file but the file cannot be found at the provided path.

5  
DEVICE NOT PRESENT  
The file is on a device that is not responding. Not used in RetroBASIC.

6  
FILE NOT INPUT  
Attempt to read from a file that is opened for writing.

7  
FILE NOT OUTPUT  
Attempt to write to a file that is opened for reading.

8  
FILENAME MISSING  
Attempt to open a file without passing in a valid file name.

9  
ILLEGAL DEVICE NUMBER  
Attempt to open a file on a non-existent device. Not used in RetroBASIC.

14  
BREAK  
Indicates that the BREAK key was pressed and entered the handler. Not used in RetroBASIC.

15  
EXTRA IGNORED  
More items were entered during an INPUT than there are variables to hold it. Extra items at the end are ignored.

16  
REDO FROM START  
The input cannot be converted to a number, and the INPUT statement asks for the same value again.

20  
NEXT WITHOUT FOR  
A NEXT statement was encountered but no matching FOR has been called.

21  
SYNTAX  
Syntax error. As RetroBASIC pre-parses before running, this cannot not occur at runtime.

22  
RETURN WITHOUT GOSUB  
A RETURN statement was encountered but no matching GOSUB has been called.

23  
OUT OF DATA  
A READ statement is asking for more data, but there are no remaining DATA values.

24  
ILLEGAL QUANTITY  
Any parameter in a statement or function that is out-of-range, like a MID with a start parameter outside the string.

25  
OVERFLOW  
Result of calculation or formula is out-of-range. Should not occur in RetroBASIC.

26  
OUT OF MEMORY  
The system has run out of memory, or the runtime stack has run out of room. Not used in RetroBASIC.

27  
UNDEFINED STATEMENT  
Branch (THEN/GOTO/GOSUB) to a non-existing line.

28  
BAD SUBSCRIPT  
Array indexes are outside the DIMmed range.

29  
REDIM'D ARRAY  
DIM being called on an already DIMed variable.

30  
DIVISION BY ZERO  
Any division by zero, including integer division, MOD, etc.

31  
ILLEGAL DIRECT  
A statement was entered in direct mode that can only be used in program mode. Examples are INPUT and GET. Not currently supported.

32  
TYPE MISMATCH  
A number was provided to a string parameter or vice versa.

33  
STRING TOO LONG  
Unused in RetroBASIC, string sizes are effectively unlimited.

34  
FILE DATA  
An INPUT or GET from a file returned numeric data for a string or vice versa. Not used in RetroBASIC, 32 will be returned in this case.

35  
FORMULA TOO COMPLEX  
The equation or formula was too complex to be interpreted. Does not occur in RetroBASIC.

37  
UNDEFINED FUNCTION  
Call to user-defined function with no corresponding DEF FN.

40  
OUT OF STACK  
Too many nested GOSUBs and FORs. Does not occur in RetroBASIC.

41  
UNABLE TO RESUME  
RESUME was called but the error is fatal.

44  
RESUME WITHOUT TRAP  
A RESUME was encountered with no corresponding TRAP or ON ERROR. Commodore BASIC returned a syntax error in this case.
