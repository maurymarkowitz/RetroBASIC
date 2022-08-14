RetroBASIC manual
=================

**Copyright © 2020 Maury Markowitz**

[![GPL license](http://img.shields.io/badge/license-GPL-brightgreen.svg)](https://opensource.org/licenses/gpl-license)

## Introduction

RetroBASIC is a BASIC interpreter whose ultimate goal is to run any program for the major 1970s/80s BASIC interpreters. In its current 1.2 version, it is patterned on MS-BASIC as seen on Commodore machines. The ultimate goal is to support almost any variation from the era, including Tiny BASIC, Palo Alto Tiny BASIC (PATB), MS-BASIC (Altair, Commodore, etc.), HP TimeShare BASIC, Atari BASIC and others. 

RetroBASIC also includes a simple analizer that (optionally) prints statistics for the program after it completes. This includes the length of the program and its line number range, the number and types of variables used, and similar details. The original impetus for RetroBASIC was to collect statistics on common programs to provide hints to the retrocomputing field, where new BASICs continue to be developed.

RetroBASIC is based on gnbasic by James Bowman.







## Design notes

RetroBASIC started in 2020 as a project to collect statistics from classic BASIC programs in an effort to find ways to improve the notoriously slow Atari BASIC. The goal was to find low-hanging fruit that would offer the most significant improvements for the least amount of changes to the original code. To do this, one needs useful statistics on what programs of the era actually used.

Initially this led to some work using Python, but it quickly became clear that the complexity of the code would be difficult to manage. For instance, one of the statistics that I wanted to collect was the number and distribution of numeric constants in a typical program. These took up lots of memory in Atari BASIC and I felt that there were possible savings here. However, when one considers all of the places such numbers appear - in formulas, array indexes, line numbers, etc. - separating out the cases appeared complex.

So finally I decided the best solution was to use an actual BASIC interpreter and collect statistics from the tokenized code. Desiring a solution that would run on practically any system with a minimum of external software, I went with lex/yacc as it has existed for decades and is available everywhere. Some more poking about led to an existing GPL-licensed example, gnbasic by James Bowman. The only version I could find, version 0.0.1, was released in 2001. I was able to get it up and running on both the Mac and PC. It proved to have a number of bugs, some quite subtle like the way it handled a "failed" IF statement, but I was able to track these down and do some serious code cleanup at the same time. After that it was a matter of fleshing out missing features and adding a selection of statistics output.

Over time I became increasingly annoyed how hard it was to use GLib on anything other than a basic Unix. Normally I would always use an external library if there's a good one, and GLib *is* a good one, so I had no intention of getting rid of it. But when the M1 Macs came out, the package system moved files around and then it became impossible to have a single Xcode project that worked on Intel and M1 - or at lease I never found a simple solution. So the last major upgrade was to remove GLib and build my own code for these functions.

With the original problem solved, I began considering simple upgrades to make it more compatible with a wider set of sources. This initially led to a number of common functions being added to the small set in gnbasic. It also led to a very deep rabbit hole of reading decades-old manuals from a wide variety of systems looking for anything worth adding to the system. 

### The three BASICs

Today we think of "classic BASIC" as synonomous with MS BASIC, as that was what users found on millions of early computers from the Altair to MSX. But as I read earlier manuals, it became clear there were actually three distinct families of BASIC, and MS was a late-comer to the party. RetroBASIC's purpose then expanded to allow as many of these variations, with reason, to be runnable using the same code. So, let's talk about the three versions.

#### Dartmouth

The original BASIC is Dartmouth BASIC, released in 1964. Almost everything you can think of comes from this version, with the exception of string handling. That's because the original version only allowed string *constants*, in things like PRINT statements and such. There were no string variables and no way to manipulate the strings.

String manipulation appeared in the fourth version, in 1968. This added the now-largely-forgotten CHANGE command, which converted a string into an array of ASCII values or vice versa. So to concatenate two strings, for instance, you would first use `CHANGE A$ TO D` and `CHANGE B$ TO E`, and then loop over E and copy the values one by one into D, assuming the array is long enough, and then finally `CHANGE D TO C$`. Yikes!

Dartmouth was developed on a mainframe and thus they chose to use a compiler. Interpreters require far less memory (most of the time) so it was not easy to port this code to smaller machines. So while versions of the Dartmouth code were found on most mainframes of the era, it saw little use outside that market. Even large minis generally didn't use it as their BASIC.

#### HP

By the time Dartmouth added `CHANGE`, it was too late. That's because at almost the same time, Hewlett-Packard introduced the HP2000, a minicomputer whose primary language was BASIC. Their variation had string support from the start, using the FORTRAN-like concept of "array slicing". For instance, to extract the first five characters of a string, one would `A$ = B$(0,5)`, or to concatenate two strings, `A$(10) = B$`, which means that everything from character 10 on should be replaced by the contents of B$. This provided almost all of the needed functionality with a single syntax, which also has performance advantages (more on this below).

But you can also see a problem: they used the same syntax as an array and so they simply didn't allow arrays of strings. What's particularily odd about this is that they offered an alternative syntax, `A$[10] = B$`. Had they simply specified square brackets for string slicing and round parens for array access, then something like `A$(1)[1:5]` would be possible. But... they didn't.

Largely lost to history today, the HP2000s were *extremely* influential. That's because for the low-low price of about $100,000, one could build out a system that would run up to 32 users off a single machine. For some time, until the first all-in-one microcomputers appeared, the HP dialect was by far the most widely used and there were numerous code examples and books filled with HP-based code. As a result, when other companies entered the mini space, like Data General and dozens of others, they were most familiar with the HP version and generally copied it. For some time, HP BASIC *was* BASIC.

#### DEC

Except, of course, for Digital. Digital was slow to the BASIC game because they were pushing their own language, FOCAL. I had never heard of FOCAL and that led me down another rabbit hole. Long story short, at the same time that Dartmouth was creating BASIC, a team at SRI was creating JOSS. The two languages are very similar in concept and implementation, there's mostly a 1:1 correspondance in the main commands. JOSS did have some things that BASIC didn't, some of them pretty interesting, but today it's lost to history. That's largely because SRI didn't want anyone to call their version JOSS, so there was CAL and FOCAL and lots of others that were all just incompatible enough to be different languages.

One person at DEC, David Ahl, was tired of watching people ignore their PDP-8 because they had FOCAL and HP had BASIC. So he went out and hired someone to write BASIC for the PDP-8. All interest in FOCAL immediately evapourated. He helped by personally porting over many of the popular FOCAL programs, like Lunar Lander and Hamurabi, to BASIC. Given the machine had 4k of memory, you might imagine it was a quite simple dialect, also lacking string manipulation.

But then the PDP-10 came out, and shortly after, the PDP-11. Finally, DEC decided to release their own BASIC, taking it in their own directions. Most notable was their own set of string functions, `MID`, `LEFT`, `RIGHT` and so forth. I have no idea why they went this route when the HP pattern was already widespread, and I suspect the people that know are no longer around, but here we are only a couple of years in and there is yet another solution to the same string problem.

#### What does all this have to do with anything?

So along comes 1975 and the Altair 8800. Within a year there are hundreds of microcomputer kits on the market, and every single one uses BASIC as a primary language. Darthmouth was a compiler that ran on mainframes, so that was going nowhere. That left you with many people who had worked with a BASIC interpreter on a DEC or HP machine, and 
