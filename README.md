RetroBASIC
=========

**Copyright © 2020 Maury Markowitz**

[![GPL license](http://img.shields.io/badge/license-GPL-brightgreen.svg)](https://opensource.org/licenses/gpl-license)

## Contents

* [Introduction](#introduction)
* [Running RetroBASIC](#running-retrobasic)
* [Building RetroBASIC](#building-retrobasic)
* [Missing features and Erata](#missing-features-and-erata)

## Introduction

RetroBASIC is a BASIC interpreter for programms written using 1970s/80s variations of BASIC. It is patterned mostly on MS-BASIC as seen on Commodore machines and Apple II (and many others). It also includes the alternate string manipulation methods from Dartmouth BASIC v4 and HP Timeshared BASIC, the later of which was widely used in early microcomputer interpreters. The ultimate goal is to support almost any dialect from the era, including Tiny BASIC, Palo Alto Tiny BASIC (PATB), MS-BASIC (Altair, Commodore, etc.), HP Timeshared BASIC (Northstar, Apple, Atari, Sinclair, etc.) and others. 

RetroBASIC also includes a simple static analizer that (optionally) prints statistics for the program after it completes. This includes the length of the program and its line number range, the number and types of variables used, and similar details. The original impetus for RetroBASIC was to collect statistics on common programs to provide hints to the retrocomputing field, where new BASICs continue to be developed.

RetroBASIC can redirect the output from `PRINT` statements and `INPUT` prompts to a file, and read the responces to `INPUT` statements from a file. This can be used to provide the same input to a program multiple times, and then the output can be `diff`ed to look for changes. This ia aided by setting the random seed value, which can be done on the command line to avoid editing the original BASIC code.

RetroBASIC is based on gnbasic by James Bowman.
 
## Running RetroBASIC

RetroBASIC is meant to be used with an existing program source file, not interactively. To run it, use:

```./retrobasic program.bas```

It will accept any text file as input and report (cryptic) errors if it cannot properly parse it. If parsing succeeds, the program (normally) begins running immediately.

Command-line options include:

`--help`, `-h`: print usage notes  
`--version`, `-v`: print version info  
`--upper-case`, `-u`: force input to upper-case, basically like using caps lock  
`--array-base`, `-a`: set base index for arrays, normally 1 but some dialects use 0  
`--tabs`, `-t`: set the number of spaces for comma-separated items, defaults to 10  
`--goto-next`, `-g`: if a branch is to a non-existant line, should it go to the next line or return an error?  
`--random`, `-r`: seed the random number generator  
`--slicing`, `-s`: enable string slicing like HP, Integer, Atari, etc.  
`--output-file`, `-o`: redirect PRINT to the named file  
`--input-file`, `-i`: redirect INPUT from the named file, one INPUT value per line  
`--no_run`, `-n`: do not run the BASIC program, simply read and parse it and then exit  
`--print_statistics`, `-p`: send a selection of statistics to the console  
`--write_statistics`, `-w`: write the statistics to the named file in a machine readable format

If you wish to use RetroBASIC to simply check syntax or collect statistics, use the -n and -p switches.

Short options with no parameters can be gan ganged, for instance -unp.

## Building RetroBASIC

The RetroBASIC interpreter is written for lex/yacc/c and is normally compiled with flex/bison. It has no external depedancies, although cygwin is required for compiling on Windows. A makefile is included that should run on almost any Unix-like system, including macOS.

An Xcode project is also included, which is the primary building method during testing. It has one drawback (currently), the bison build rule in Xcode does not properly build `parse.h` into the `src` folder, but follows yacc-like rules and builds `y.tab.h` file in the `../DerivedFiles` folder. If you make changes to `parse.y`, be sure to copy the new `y.tab.h` to `/src/parse.h` for those changes to be visible.

If anyone would like to contribute a VS.net project, it would be greatly appeciated.

## Missing features and Erata

A complete list is maintained in the TODO file, but here are some important limitations:

* INPUT statements with multiple values currently have to be entered with return/enter between each value, spaces do not work.
* Most dialects of basic perform an "invisible DIM" on all variables, defining them to be arrays 0..10. This is not currently supported, but is *rarely* seen in actual programs.
* Variable names are currently limited to two characters, which is needed to support "crunched" statements without spaces in MS style.
* The system does not support "immediate mode" (command line) input. It is not supposed to, but could potentially do so.
* LIST, LOAD and SAVE are currently not implemented, in keeping with the use-case.
* File I/O is not supported, commands like OPEN will be parsed but have no effect.
* POKE does nothing, PEEK returns zero.
