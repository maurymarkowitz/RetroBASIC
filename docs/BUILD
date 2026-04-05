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

Use MSYS2 / MinGW-W64 similarly; provide Windows cross-compiler if needed with `CC=x86_64-w64-mingw32-gcc`.

