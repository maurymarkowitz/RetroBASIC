RetroBASIC build notes
======================

**Copyright © 2020 Maury Markowitz**

[![GPL license](http://img.shields.io/badge/license-GPL-brightgreen.svg)](https://opensource.org/licenses/gpl-license)

## Introduction

This document lists a number of known issues found when building on different platforms.

## makefile use

RetroBASIC should build on any system with a working makefile system. It uses standard ANSI-C, lex and yacc, and has no external dependencies. A simple `make` should produce a runnable binary. If it does not, please file bug reports and/or pull requests. There may be a few warnings from the lex/yacc code but these will be addressed over over time.

## macOS / Unix-like

RetroBASIC uses a standard Makefile that would build out-of-the-box on any Unix-like system, including macOS and Linux.

Build steps:

```sh
make clean
make all
```

Optional install, which adds documentation, examples and the man entry:

```sh
make install
```

Optional uninstall:

```sh
make uninstall
```

`make install` defaults to `/usr/local`; override with `PREFIX` if needed (for example `make PREFIX=/opt/retrobasic install`).

## Windows

RetroBASIC builds on Windows using MSYS2 and MinGW-W64. These tools provide Unix-like development utilities and a C compiler for Windows.

### Prerequisites

1. **Download and install MSYS2**
   - Go to https://www.msys2.org/
   - Download the installer and run it
   - Follow the installation wizard (default path is fine)

2. **Open MSYS2 terminal**
   - Launch "MSYS2 MinGW 64-bit" from your Start menu
   - This opens a Unix-like shell environment

3. **Install required build tools**
   
   In the MSYS2 terminal, run:

   ```sh
   pacman -S mingw-w64-x86_64-toolchain mingw-w64-x86_64-make flex bison zip
   ```

   This installs:
   - `mingw-w64-x86_64-toolchain` — C/C++ compiler and build utilities
   - `mingw-w64-x86_64-make` — GNU make
   - `flex` — Lexical analyzer generator (for src/scan.l)
   - `bison` — Parser generator (for src/parse.y)
   - `zip` — For creating release packages

4. **Build RetroBASIC**

   Clone or navigate to your RetroBASIC repository, then:

   ```sh
   make clean
   make
   ```

   The build produces `retrobasic.exe` in the project root.

### Optional: Cross-compile for Windows from Unix/macOS

If building on a Unix-like system targeting Windows, provide the cross-compiler:

```sh
make CC=x86_64-w64-mingw32-gcc
```

This requires the MinGW-W64 cross-compiler installed on your system.

