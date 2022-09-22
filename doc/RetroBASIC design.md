RetroBASIC design notes
=======================

**Copyright © 2020 Maury Markowitz**

[![GPL license](http://img.shields.io/badge/license-GPL-brightgreen.svg)](https://opensource.org/licenses/gpl-license)

## Introduction

This document explains some of the design goals, coding decisions and style selections used in RetroBASIC.

## History

RetroBASIC started in 2020 as a project to collect statistics from classic BASIC programs in an effort to find ways to improve the notoriously slow Atari BASIC. The goal was to find low-hanging fruit that would offer the most significant improvements for the least amount of changes to the original code. To do this, one needs useful statistics on what sorts of things programs of the era actually did.

Initially this led to some regex-like work in Python, but it quickly became clear that the complexity of the code was daunting. For instance, one of the statistics that I wanted to collect was the number and distribution of numeric constants in a typical program. These took up lots of memory in Atari BASIC and I felt that there were possible savings here. But it was also useful to know the difference between constants and line numbers, and the distribution of each. When one considers all of the places such numbers appear - in formulas, array indexes, line numbers, etc. - separating out the cases appeared complex.

So I decided the best solution was to use an actual BASIC interpreter and collect statistics from the tokenized code. Desiring a solution that would run on practically any system with a minimum of external software, I went with lex/yacc, as it has existed for decades and is available everywhere. While it is no longer as widely used as it once was, there's lots of example code out there and still a lot of experience available to help on the 'net.

Some poking about led to an existing GPL-licensed example, gnbasic by James Bowman. The only version I could find, version 0.0.1, was released in 2001. I was able to get it up and running on both the Mac and PC (using Cygwin). It proved to have a number of bugs, some quite subtle like the way it handled a "failed" IF statement, but I was able to track these down and do some serious code cleanup at the same time. After that, it was a matter of fleshing out missing features and adding a selection of statistics output.

gnbasic made use of the excellent GLib code to provide some common string handling functions and support for lists and trees. Normally I would have loved to let someone else handle these bits of common code. However, using GLib on anything other than "real Unix" turned out to be more annoying than I would have imagined; on the Mac, for instance, the library was found in different locations depending on the processor model. I eventually decided to rewrite those bits of the GLib code that were being used.

With the basic system up and running, it has since been expanded with statements and functions from a variety of BASIC dialects. This allows it to run unmodified code from a variety of early BASICs that would otherwise require inter-dialect conversion.

## The three BASIC families

Today we think of "classic BASIC" as synonomous with MS BASIC, as that was what users found on millions of early computers from the Altair to MSX. But as I read manuals from other platforms, three distinct families of BASIC emerged and it turns out MS was a late-comer to the party. RetroBASIC's purpose to run these early programs expanded in scope to include those variations wherever possible.

### Dartmouth

The original BASIC is Dartmouth BASIC, released in 1964. Almost everything you can think of comes from this version, with the exception of string handling. That's because the original version only allowed string *constants*, in things like `PRINT "hello world"` and such. There were no string *variables* and no way to manipulate the string constants.

String variables appeared in the fourth version, in 1968. This also added a single way to manipulate the data, the CHANGE command, which converted a string into an array of ASCII values or vice versa. So, for instance, to concatenate two strings you would first use `CHANGE A$ TO D` and `CHANGE B$ TO E`, and then loop over E and copy the values one by one into D, assuming the array D is long enough, and then finally `CHANGE D TO C$`. Yikes!

Dartmouth was developed on a mainframe and they chose to implement the language as a compiler. Interpreters require far less memory (most of the time) so it was not easy to port the original code to smaller machines. So while versions of the Dartmouth code were found on most mainframes of the era, it saw little use outside that market. Even large minis generally didn't use the Darmouth dialect.

### HP

At almost the same time that Dartmouth v4 appeared, Hewlett-Packard introduced the HP2000, a minicomputer whose primary language was BASIC. Their variation had string support using the FORTRAN-like concept of "array slicing". For instance, to extract the first five characters of a string, one would `A$ = B$(1,5)`, or to concatenate two strings, `A$(10) = B$`, which means that everything from character 10 on should be replaced by the contents of B$. This provided almost all of the needed functionality with a single syntax, which also has performance advantages (more on this below).

But you can also see a problem: they used the same syntax as an array and so they didn't allow arrays of strings. What's particularily odd about this is that they offered an alternative syntax, `A$[10] = B$`. Had they simply specified square brackets for string slicing and round parens for array access, then something like `A$(1)[1,5]` would be possible. But... they didn't.

Largely lost to history today, the HP2000s were *extremely* influential. That's because for the low-low price of about $50,000, one could build out a system that would run up to 16 users on a single rack-mount machine. For some time, until the first all-in-one microcomputers appeared, the HP dialect was by far the most widely used and there and books filled with HP code. When other companies entered the mini space, like Data General, they were most familiar with the HP version and generally copied it. For a time, HP BASIC *was* BASIC.

### DEC

Except, of course, for Digital. DEC was slow to the BASIC game because they were pushing their own language, FOCAL. At the same time that Dartmouth was creating BASIC, a team at SRI was creating JOSS. BASIC and JOSS are very similar in concept and implementation, there's mostly a 1:1 correspondance in the statements. JOSS did have some things that BASIC didn't, some of them pretty interesting, but today it's lost to history. That's largely because SRI didn't want anyone to call their version JOSS, so there was CAL and FOCAL and lots of others that were all *just* incompatible enough to be different languages.

One person at DEC, David Ahl, was tired of watching people ignore their PDP-8 in favor of the HP2000 because DEC had FOCAL and HP had BASIC. So he went out and hired someone to write BASIC for the PDP-8. All interest in FOCAL immediately evapourated. He helped this process along by personally porting over many of the popular FOCAL programs to BASIC, like Lunar Lander and Hamurabi. The machine had only 4k of memory, so it was a simple dialect, lacking string manipulation.

But then DEC released the PDP-10, and shortly after, the PDP-11. DEC finally decided to release their own BASIC, taking it in their own directions. Most notable was their own set of string functions, `MID`, `LEFT`, `RIGHT` and so forth. I have no idea why they went this route when the HP pattern was already widespread, and I suspect the people that know are no longer around, but here we are only a couple of years in and there is yet another solution to the same string problem.

There is a real drawback to DEC's solution. Consider the code `A$="HELLO WORLD":PRINT LEFT$(A$,5);:PRINT " ";:PRINT RIGHT$(A$,5)`. This code produces three separate strings on the heap, because the string functions return new strings. In contrast, A$="HELLO WORLD":PRINT A$(0,5);:PRINT " ";:PRINT A$(5) in the HP dialect results in only one string on the heap because the slices are simply pointers into the existing string. The HP concept is generally much more memory efficient.

### What does all this have to do with anything?

So along comes 1975 and the Altair 8800. Within a year there are dozens of microcomputer kits on the market, and every single one uses BASIC as a primary language. Darthmouth was a compiler that ran on mainframes, so that was going nowhere. That left you with many people who had worked with a BASIC interpreter on a DEC or HP machine.

When Gates, Allen and Davidoff began writing their BASIC for the Altair, they did so on the PDP-10, and natually the result looks a lot like DEC's BASIC-PLUS. In contrast, when Woz wrote Apple BASIC while working a day job at HP, it naturally ended up looking like HP BASIC. For a time, 1975 through about 1978, the two dialects were equally common.

Things started changing in 1977, when over a period of about six months, the Apple II, TRS-80 and Commodore PET were released. Commodore licensed MS's new 6502 version as its dialect, and Apple shipped it as an loadable program before including it in the ROM as the standard BASIC in the II+. From that point on, the HP dialect starts to disappear. It was used as the basis for Atari BASIC in 1979, and Sinclair and other UK-based systems shortly after that, but even as early as 1980 anything that didn't use MS-style strings was considered non-standard.

### RetroBASICs solution

RetroBASIC aims to run any early BASIC program without modification. There is the important caviat that the programs does not make use of platform-specific extensions or invoke code using CALL or PEEKs and POKEs. But such was the case for most early programs when BASIC was a primary language on hundreds of different platforms and users exchanging programs wrote them to be as portable as possible. In most cases, it was only the string handling and a few more subtle differences that had to be ported.

There are, of course, many additional keywords and features found in one dialect or another. Unfortunately, some of these are incompatible with each other. For instance, the of Commodore BASIC for the (unreleased) C65 included a CHANGE command used for doing find and replace in a program text, which is obviously incompatible with the Dartmouth version of the same command. HP had its own version of CHANGE, (the better-named) CONVERT, but Wang BASIC had an entirely different CONVERT function. When such issues arose, RetroBASIC selected the "most standard" version, the one that would result in the most programs working properly without conversion.

As a result, RetroBASIC is essentially a superset of MS BASIC with the following features:

1) MS-style string handling for contatenation (+ and &) and functions like MID$
2) Dartmouth style CHANGE A$ to A and CHANGE A TO A$, and HP's CONVERT synonym
3) HP-style string slicing, including defaulting to considering [] separate from () allowing string arrays
4) HP-style GOTO..ON and GOSUB..ON variations of MS's ON..GOTO and ON..GOSUB

## Random notes

Later versions of MS, and those that followed its pattern, allow FOR loops to be terminated in one of three ways. NEXT I closes the current loop and returns "NEXT WITHOUT FOR" if the currrent loop isn't I. NEXT closes any open loop, including multiple open loops. Finally, NEXT I,J closes the loops opened with I or J. This last case is weird, thing is that the order doesn't matter. If the code FOR I= and then FOR J=, NEXT I,J will work properly as long as the current loop is in the list of variable names.

## Coding style

RetroBASIC is writen in a semi-cannonical C format, as defined by the [Canonical C Style Guide](https://people.canonical.com/~msawicz/guides/c/cguide.html). There are two main differences:

1) single-line "blocks" are separated onto two lines to make them look more like multi-line blocks

  while (condition)
     dosomething;
            
  as opposed to:
  
  while (condition) dosomething;
  
2) multi-line blocks have the opening brace on the statement line, to make them look more like single-line blocks

  while (condition) {
     dosomething;
     andsomethingelse;
  }
  
    as opposed to:

  while (condition)
  {
     dosomething;
     andsomethingelse;
  }



