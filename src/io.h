/* io (header) for RetroBASIC
   Copyright (C) 2024 Maury Markowitz
    
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

#ifndef io_h
#define io_h

#include "stdhdr.h"

#if _WIN32
  #include <conio.h>
#else
  #include <sys/termios.h>
#endif

#include <unistd.h>

/**
 * @file io.h
 * @author Maury Markowitz
 * @date 31 December 2024
 * @brief Input/output and file handling routines.
 *
 *
 */

/**
 * Waits for a single character. Used for GET.
 *
 * @param fd, the file descriptor, typically STDIN_FILENO.
 * @return the keycode, NULL if an error occurred.
*/
int getbyte(int fd);

/**
 * Gets a single keystroke, or null if no key is pressed. Used for INKEY$.
 *
 * @param fd, the file descriptor, typically STDIN_FILENO.
 * @return the keycode, NULL if no key is pressed or an error occurred.
 *
 * See: https://stackoverflow.com/questions/1798511/how-to-avoid-pressing-enter-with-getchar-for-reading-a-single-character-only
*/
int getkey(int fd);


#endif /* io_h */
