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

#ifndef __IO_H__
#define __IO_H__

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
 */

/**
 * Returns the file handle for a previously opened channel/file number.
 *
 * @param channel, the channel number.
 * @return the file/stream pointer, or NULL if the channel is not open.
 *
 */
FILE* handle_for_channel(int channel);

/**
 * Returns the path/file for a given channel/file number.
 *
 * @param channel, the channel number.
 * @return the path/file name, or NULL if the channel is not open.
 *
 */
char* path_for_channel(int channel);

/**
 * Returns whether the selected channel is readable.
 *
 * @param channel, the channel number.
 * @return true if the file exists and can be read, false otherwise.
 *
 */
bool channel_is_readable(int channel);

/**
 * Returns whether the selected channel is writable.
 *
 * @param channel, the channel number.
 * @return true if the file exists and can be written, false otherwise.
 *
 */
bool channel_is_writable(int channel);

/**
 * Opens a new or existing file, checking that the path and name are valid.
 *
 * The modes are "r" for reading, "w" for writing, "a" for appending, and
 * "n" for a new writable file.
 *
 * When opening for "w"riting, if the file already exists it will clear it
 * out and the file will consist only of new data. When opened with "n"ew,
 * it demands that the file not already exist, and will return a FILE EXISTS
 * error if it does. It is otherwise the same as "w".
 *
 * "r"eading and "a"ppending demands that the file already exist, and will
 * raise a FILE NOT FOUND if it doesn't.
 *
 * @param channel, the channel number, from basic.
 * @param name, the file name, optionally including a path, to open.
 * @param mode, the unix-like access mode, n.
 * @return true if the file was opened successfully, false otherwise
 *
 */
bool open_file(const int channel, const char *name, const char *mode);

/**
 * Closes an existing file channel.
 *
 * @param channel, the channel number.
 * @return true if the file was opened successfully, false otherwise
 *
 */
bool close_file(const int channel);

/**
 * Closes all open files and resets the file number map.
 */
void close_all_files(void);

/**
 * Creates an empty file at the provided path. This is primarily used in
 * dialects like Apple Business BASIC that can only write to an existing
 * file.
 *
 * @param name, the file name, optionally including a path, to create.
 *
 */
bool create_file(const char *file);

/**
 * Deletes the file if it is not open and the user has permission.
 *
 * @param name, the file name, optionally including a path, to delete.
 *
 */
bool delete_file(const char *file);

/**
 * Waits for a single character. Used for GET.
 *
 * @param fd, the file descriptor, typically STDIN_FILENO.
 * @return the keycode, NULL if an error occurred.
 */
int getbyte(void);

/**
 * Gets a single keystroke, or null if no key is pressed. Used for INKEY$.
 *
 * @param fd, the file descriptor, typically STDIN_FILENO.
 * @return the keycode, NULL if no key is pressed or an error occurred.
 *
 * See: https://stackoverflow.com/questions/1798511/how-to-avoid-pressing-enter-with-getchar-for-reading-a-single-character-only
 */
int getkey(void);

#endif /* io_h */
