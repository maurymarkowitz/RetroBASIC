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

RetroBASIC is a BASIC interpreter whose ultimate goal is to run any program for the major 1970s/80s BASIC interpreters. In its current 1.0 version, it is patterned on MS-BASIC as seen on Commodore machines. The ultimate goal is to support almost any variation from the era, including Tiny BASIC, Palo Alto Tiny BASIC (PATB), MS-BASIC (Altair, Commodore, etc.), HP TimeShare BASIC, Atari BASIC and others. 

RetroBASIC also includes a simple analizer that (optionally) prints statistics for the program after it completes. This includes the length of the program and its line number range, the number and types of variables used, and similar details. The original impetus for RetroBASIC was to collect statistics on common programs to provide hints to the retrocomputing field, where new BASICs continue to be developed.

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
`--no_run`, `-n` : do not run the BASIC program, simply read and parse it and then exit  
`--print_statistics`, `-p` : send a selection of statistics to the console  
`--write_statistics`, `-w` : write the statistics to the named file in a machine readable format

If you wish to use RetroBASIC to simply check syntax or collect statistics, use the -n and -p switches.

## Building RetroBASIC

The RetroBASIC interpreter is written for lex/yacc/c and is normally compiled with flex/bison. It has a single non-standard dependancy; it uses GLib for string, list and tree suppport. It should compile on any platform with GLib, and has been tested on macOS and Windows with the support of Cygwin.

A sample Xcode project is included, as well as a basic makefile. If anyone would like to contribute a VS.net project, it would be greatly appeciated.

## Missing features and Erata

A complete list is maintained in the TODO file, but here are some important limitations:

* INPUT statements with multiple values currently have to be entered with return/enter between each value, spaces do not work.
* The system does not support "immediate mode" (command line) input. It is not supposed to, but could potentially do so.
* Variable names are currently limited to two characters, which is needed to support "crunched" statements without spaces in MS style.
* LIST, LOAD and SAVE are currently not implemented, in keeping with the use-case.
* File I/O is not supported, commands like OPEN will be parsed but have no effect.
* POKE does nothing, PEEK returns zero.
