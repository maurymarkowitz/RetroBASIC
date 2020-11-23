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

RetroBASIC also includes a static analizer that prints statistics for the program after it completes. This includes the length of the program and its line number range, the number and types of variables used, and similar details. The original impetus for RetroBASIC was to collect statistics on common programs to provide hints to the retrocomputing field, where new BASICs continue to be developed.

RetroBASIC is based on gnbasic by James Bowman.
 
## Running RetroBASIC

RetroBASIC is meant to be used with an existing program source file, not interactively. To run it, use ```./retrobasic program.bas```. It will accept any text file as input and report (cryptic) errors if it cannot properly parse it.

If parsing succeeds, the program (normally) begins running immediately. Most programs should run correctly, although file I/O is not currently implemented, user functions return zero, and INPUT statements with multiple assignments currently require returns between each value.

If your goal is to simply check the syntax of the program, or to list statistics, use the `--no_run switch`, `-n` for short. This will load and parse the BASIC source, but not run it. This is normally combined with `--print_statistics`.

## Building RetroBASIC

The RetroBASIC interpreter is written for lex/yacc and is normally compiled with flex/bison. It has a single non-standard dependancy; it uses GLib for string, list and tree suppport. It should compile on any platform with GLib, and has been tested on macOS (native) and Windows (with Cygwin). A sample Xcode project is included.

## Missing features and Erata

* LIST is not supported
* DEF FNx does not parse "local" values for paramters, the global versions are used
* INPUT statements with multiple values currently have to be entered with return/enter between each value.
* POKE does nothing, PEEK returns zero
* String "slicing" as seen in HP, Atari and Integer is not yet supported, but this is an important feature to add.
* LIST, LOAD and SAVE are currently not implemented, in keeping with the use-case.
* REMs do not remember the comment, although it should be easy to add this if LIST support is desired.
* Variable names are currently limited to two characters, which is needed to support "crunched" statements without spaces in MS style.
* The system does not support "immediate mode" (command line) input. It is not supposed to.
