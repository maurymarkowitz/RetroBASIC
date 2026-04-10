RetroBASIC
=========

**Copyright © 2020 Maury Markowitz**

[![GPL license](http://img.shields.io/badge/license-GPL-brightgreen.svg)](https://opensource.org/licenses/gpl-license)

## Contents

* [Introduction](#introduction)
* [Installing RetroBASIC](#installing-retrobasic)
* [Building RetroBASIC](#building-retrobasic)
* [Running RetroBASIC with an existing program](#running-retrobasic-with-an-existing-program)
* [Running RetroBASIC interactively](#running-retrobasic-interactively)
* [Missing features and Errata](#missing-features-and-errata)

## Introduction

RetroBASIC is an interpreter for programs written using 1970s/80s variations of BASIC. It is patterned mostly on MS-BASIC as seen on Commodore machines and Apple II (and many others). It also includes the alternate string manipulation methods from Dartmouth BASIC v4 and HP Timeshared BASIC, the latter of which was widely used in early microcomputer interpreters. The ultimate goal is to support almost any dialect from the era, including Dartmouth BASIC, Tiny BASIC (including Palo Alto), MS-BASIC (Altair, Commodore, etc.), HP Timeshared BASIC (Northstar, Apple, Atari, Sinclair, etc.) and others. 

RetroBASIC also includes a simple static analyzer that (optionally) prints statistics for the program after it completes. This includes the length of the program and its line number range, the number and types of variables used, and similar details. The original impetus for RetroBASIC was to collect statistics on common programs to provide hints to the retrocomputing field, where new BASICs continue to be developed.

The installation also includes an extensive reference manual which includes a complete list of the BASIC language and how it differs across various platforms. This can be used both as a reference for RetroBASIC as well as a general guide to the many dialects of BASIC and a useful guide to porting older programs between platforms.

RetroBASIC is based on gnbasic by James Bowman.

## Installing RetroBASIC

The latest source code and any prebuilt binaries are available at:

https://github.com/maurymarkowitz/RetroBASIC/releases

Binary packages are be provided for macOS, Linux, and Windows.

On macOS and Linux, you can use Homebrew:

```sh
brew tap maurymarkowitz/tap https://github.com/maurymarkowitz/homebrew-tap
brew install maurymarkowitz/tap/retrobasic
```

**Note** Homebrew installs to `/opt/homebrew/bin` instead of `/usr/local/bin` on Apple Silicon Macs.

On Windows, you can use Scoop:

```powershell
scoop bucket add maurymarkowitz https://github.com/maurymarkowitz/scoop-bucket
scoop install retrobasic
```

## Building RetroBASIC

You can also easily build the project from source.  It is a makefile project that does not require `autoconfig` or other steps. A simple `make` in the root directory should produce a working executable on practically any unix-like system.

Windows compatibility is provided using MinGW, which needs to be installed manually. The same makefile is used for both Unix and Windows, and the `make` utility supplied with MinGW works perfectly. Flex and Bison will generally have to be manually specified as most basic MinGW installs will not include them by default.

Both platforms support `make install` which adds the manuals to the proper locations, and `make uninstall` to cleanly remove all the parts. `make install` defaults to `/usr/local`; override with `PREFIX` if needed (for example `make PREFIX=/opt/retrobasic install`).

## Running RetroBASIC with an existing program

RetroBASIC is generally used to run existing programs, saved to a text file normally with the extension `.bas`. You can use it this way using a command similar to this example, replacing the `program.bas` with the name of the text file containing the BASIC program you wish to run:

```./retrobasic program.bas```

It will accept any text file as input and report (cryptic) errors if it cannot properly parse it. If parsing succeeds, the program (normally) begins running immediately.

Command-line options include:

`--help`, `-h`: print usage notes  
`--version`, `-v`: print version info  
`--upper-case`, `-u`: force input to upper-case, basically like using caps lock  
`--array-base`, `-a`: set base index for arrays, normally 1 but some dialects use 0  
`--trace`, `-t`: turn on line number tracing  
`--tabs`: set the number of spaces for comma-separated items, defaults to 10  
`--goto-next`, `-g`: if a branch is to a non-existent line, should it go to the next line or return an error?  
`--random`, `-r`: seed the random number generator  
`--slicing`, `-s`: enable string slicing like HP, Integer, Atari, etc.  
`--prompt`: set the interactive prompt string, default is `>`  
`--output-file`, `-o`: redirect PRINT to the named file  
`--input-file`, `-i`: redirect INPUT from the named file, one INPUT value per line  
`--no_run`, `-n`: do not run the BASIC program, simply read and parse it and then exit  
`--print_statistics`, `-p`: send a selection of statistics to the console  
`--write_statistics`, `-w`: write the statistics to the named file in a machine readable format  

If you wish to use RetroBASIC to simply check syntax or collect statistics, use the `-n` and `-p` switches.

Short options with no parameters can be ganged, for instance, `-unp`.

## Running RetroBASIC interactively

Starting in version 3.0, RetroBASIC now includes a simple line-oriented editor that allows you to create and edit programs interactively, as well as `RUN`, `LOAD` and `SAVE` them. For instance, to play a game of Super Star Trek, you can launch RetroBASIC wit no parameters and then use the `LOAD` and `RUN` commands:

```
./retrobasic

RetroBASIC CLI

> LOAD "bas/superstartrek.bas"
> RUN
```

As part of this addition, support for a "break" key was added. This is wired to the `Esc` key on Unix and macOS machines. On Windows machines, you can use both `Esc` as well as the `Pause`/`Break` key above the cursor controls. Break also works in non-interactive mode, but in that case it will exit directly to the shell. In interactive mode, it return sto the line editor, where you can modify the program and then `CONT`inue. If you wish to exit to the shell from interactive mode, use `BYE` or Control-C.

## Missing features and Errata

A complete list is maintained in the TODO file, but here are some important limitations:

* Variable names are currently limited to two characters, which is needed to support "crunched" statements without spaces in MS style.
