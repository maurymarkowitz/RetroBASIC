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

RetroBASIC is a C language BASIC interpreter who's goal is to run any program for the major 1970s/80s BASIC interpreters, including Tiny BASIC, Palo Alto Tiny BASIC, MS-BASIC (Altair, Commodore, etc.), HP TimeShare BASIC, Atari BASIC and others. In its current 1.0 version, it is aimed purely at MS-BASIC.

RetroBASIC also includes a static analizer that optionally prints statistics for the program after it completes. This includes the length of the program and its line number range, the number and types of variables used, and similar details. The original impetus for RetroBASIC was to collect statistics on common programs to provide hints to the retrocomputing field, where new BASICs continue to be developed.

RetroBASIC is based on gnbasic by James Bowman.
 
## Running RetroBASIC

RetroBASIC is meant to be used with an existing program source file, not interactively. To run it, use:

```./retrobasic program.bas```

It will accept any text file as input and report (cryptic) errors if it cannot properly parse it. If parsing succeeds, the program (normally) begins running immediately.

If your goal is to simply check the syntax of the program, or to list statistics, use the `--no_run` switch, `-n` for short. This will load and parse the BASIC source, but not run it. This is often combined with `--print_statistics` (`-p`). You can also `--write_statistics` (`-w`) to a file of your choice, which outputs a slightly different format more suitable for automating the collection of the statistics.

Other command-line options include:

`--help`, `-h`: print usage notes  
`--version`, `-v`: print version info  
`--upper-case`, `-u`: force input to upper-case, basically like using caps lock  
`--array-base`, `-a`: set base index for arrays, normally 1 but some dialects use 0  
`--tabs`, `-t`: set the number of spaces for comma-separated items, defaults to 10  
`--goto-next`, `-g`: if a branch targers a non-existant line, should it go to the next line? normally false
`--random`, `-r`: seed the random number generator  
`--output-file`, `-o`: redirect PRINT to the named file  
`--input-file`, `-i`: redirect INPUT from the named file  

## Building RetroBASIC

The RetroBASIC interpreter is written for lex/yacc and is normally compiled with flex/bison. It has a single non-standard dependancy; it uses GLib for string, list and tree suppport. It should compile on any platform with GLib, and has been tested on macOS (native) and Windows (with Cygwin).

A sample Xcode project is included, as well as a basic makefile. If anyone would like to contribute a VS project, it would be greatly appeciated.

## Missing features and Erata

* File I/O is not supported, commands like OPEN will be parsed but have no effect
* LIST is not supported
* DEF FNx does not parse "local" values for paramters, the global versions are used
* INPUT statements with multiple values currently have to be entered with return/enter between each value.
* POKE does nothing, PEEK returns zero
* String "slicing" as seen in HP, Atari and Integer is not yet supported, but this is an important feature to add.
* LIST, LOAD and SAVE are currently not implemented, in keeping with the use-case.
* Variable names are currently limited to two characters, which is needed to support "crunched" statements without spaces in MS style.
* The system does not support "immediate mode" (command line) input. It is not supposed to.
