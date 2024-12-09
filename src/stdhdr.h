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

#ifndef stdhdr_h
#define stdhdr_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <ctype.h>  // toupper and tolower FIXME: implement internally
#include <errno.h>  // used only while opening the program file, could be removed?
#include <math.h>   // fmax, fabs, etc.
#include <limits.h> // gives INT_MAX

#include <time.h>   // used for TIME and DATE in main and stats

#include "strng.h"  // our replacement for GLib.String
#include "list.h"   // ... and GLib.List and .Tree

#endif /* stdhdr_h */
