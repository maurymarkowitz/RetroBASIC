/* Global imports for RetroBASIC
   Copyright (C) 2020 Maury Markowitz
 
   Based on gnbasic
   Copyright (C) 1998 James Bowman

This file is part of RetroBASIC.

RetroBASIC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

RetroBASIC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with RetroBASIC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

#pragma once

// this is for MSVC, which complains about standard calls like sprintf
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//#ifdef HAVE_STRING_H
#include <string.h>
//#elif defined(HAVE_STRINGS_H)
//#include <strings.h>
//#endif

#ifndef HAVE_STRCASECMP
#ifdef HAVE_STRICMP
#define strcasecmp(A,B) stricmp((A),(B))
#endif
#endif

#include <ctype.h>  // toupper and tolower
#include <errno.h>  // used only while opening the program file, could be removed?
#include <math.h>   // fmax, fabs, etc.
#include <limits.h> // gives INT_MAX

#include <time.h>   // used for TIME and DATE in main and stats

#include "strng.h"
#include "list.h"

#define FALSE 0
#define TRUE 1

//typedef enum {FALSE = 0, TRUE} boolean; // useful macro (imho)
