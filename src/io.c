/* io (implementation) for RetroBASIC
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

#include "io.h"

/*
 * Waits for a single character. Used for GET.
*/
int getbyte(int fd)
{
  int ch;
  struct termios old_attrs, new_attrs;
  tcgetattr(STDIN_FILENO, &old_attrs);
  new_attrs = old_attrs;
  new_attrs.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &new_attrs);
  system("stty -echo"); //shell out to kill echo
  ch = getchar();
  system("stty echo");
  tcsetattr(STDIN_FILENO, TCSANOW, &old_attrs);
  return ch;
}

/*
 * Gets a single keystroke, or null if no key is pressed. Used for INKEY$.
*/
int getkey(int fd)
{
#if _WIN32
    if (kbhit) {
      return getch();
    } else {
      return 0;
    }
#else
  int ch;
  unsigned char buf[1];
  struct termios old_attrs, new_attrs;
  tcgetattr(STDIN_FILENO, &old_attrs);
  new_attrs = old_attrs;
  cfmakeraw(&new_attrs);
  new_attrs.c_cc[VMIN] = 0;
  new_attrs.c_cc[VTIME] = 0;
  new_attrs.c_lflag &= ~(ICANON | ECHO);
//  newt.c_cc[VMIN] = 0;
  tcsetattr(STDIN_FILENO, TCSANOW, &new_attrs);
  ch = (int)read(STDIN_FILENO, buf, 1);
  if (ch > 0)
      ch = buf[0];
  tcsetattr(STDIN_FILENO, TCSANOW, &old_attrs);
  return ch;
#endif
}
