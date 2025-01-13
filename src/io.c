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

#include "errors.h" // we do error reporting in this module
#include <sys/stat.h> // various unix file utilities

#ifdef WIN32
#include <io.h>
#define F_OK 0
#define access _access
#endif

#define max_open_files 16 //!< the maximum number of files that can be open at once
#define max_file_num 256 //!< the maximum file handle number
FILE* file_handle_map[max_file_num]; //!< maps the file numbers to C handles
char file_name_map[max_file_num][PATH_MAX]; //!< maps the file numbers to C handles

/*
 * Returns the file pointer for a given channel.
 */
FILE* handle_for_channel(int channel)
{
  if (channel < 0 || channel >= max_file_num) {
    handle_error(ern_BAD_SUBSCRIPT, "Attempt to use a file channel that is outside the allowed range");
    return NULL;
  }
  return file_handle_map[channel];
}

/*
 * Returns the path/file name for a given channel.
 */
char* path_for_channel(int channel)
{
  if (channel < 0 || channel >= max_file_num) {
    handle_error(ern_BAD_SUBSCRIPT, "Attempt to use a file channel that is outside the allowed range");
    return NULL;
  }
  return file_name_map[channel];
}

/*
 * Returns whether the file can be read or written, a private method for the following public functions.
 */
bool test_channel(int channel, int how)
{
  if (channel < 0 || channel >= max_file_num) {
    handle_error(ern_BAD_SUBSCRIPT, "Attempt to use a file channel that is outside the allowed range");
    return false;
  }
  
  // test that we can get to that file, which should never fail because we tested it on open
  char *path = path_for_channel(channel);
  char temp_path[PATH_MAX];
  if (realpath(temp_path, path) == NULL)
    return false;

  // now test it
  if (access(temp_path, how) == 0)
    return true;
  else
    return false;
}

/*
 * Returns if the file is readable for a given channel.
 */
bool channel_is_readable(int channel)
{
  return test_channel(channel, R_OK);
}

/*
 * Returns if the file is writable for a given channel.
 */
bool channel_is_writable(int channel)
{
  return test_channel(channel, W_OK);
}

/*
 * Tests whether a file or directory exists.
 */
int exists(const char *path)
{
  struct stat buffer;
  return (stat(path, &buffer) == 0);
}

/*
 * Extracts the path from the filename, if it exists,
 * and expands it to the full path.
 */
bool extract_path(const char *input, char *path, char *file) {
  char temp_path[PATH_MAX];
  const char *last_slash = strrchr(input, '/');
  
  if (last_slash) {
    strncpy(temp_path, input, last_slash - input);
    temp_path[last_slash - input] = '\0';  // null-terminate
    strcpy(file, last_slash + 1);         // copy the rest of the name into file
  } else {
    strcpy(temp_path, ".");  // use the current directory
    strcpy(file, input);     // the input is just the file name
  }
  
  // resolve the absolute path
  if (realpath(temp_path, path) == NULL)
    return false;
  else
    return true;
}
/*
 * Closes any open files and resets the file list to empty.
 */
void close_all_files(void)
{
  for (int i = 0; i < max_file_num; i++) {
    if (file_handle_map[i] != 0) {
      fclose(file_handle_map[i]);
      file_handle_map[i] = 0;
      file_name_map[i][0] = '\0';
    }
  }
}

/*
 * Tests that the path and name are valid, and attempts to
 * open the file. If it is successfully opened, it is recorded
 * in the file_handle_map and the number of open files is ++ed.
 */
bool open_file(const int channel, const char *name, const char *mode)
{
  // see if this channel is already being used
  if (file_handle_map[channel] != 0) {
    handle_error(ern_FILE_OPEN, "Attempt to open a file but that channel is already in use");
    return false;
  }
  
  // don't allow too many files to be open
  int num_open = 0;
  for (int i = 0; i < max_file_num; i++) {
    if (file_handle_map[i] != 0)
      num_open++;
  }
  if (num_open >= max_open_files) {
    handle_error(ern_TOO_MANY_FILES, "Attempt to open a file with too many files already open");
    return false;
  }
  
  // pull the name apart
  char path[PATH_MAX], file[PATH_MAX];
  extract_path(name, path, file);
  
  // see if there is a path, if so, see if it exists
  //  - it is OK to have no path, this means to use the working directory
  if (strlen(path) > 0) {
    if (!exists(path)) {
      handle_error(ern_DEV_NOT_FOUND, "Attempt to open a file with an invalid path");
      return false;
    }
  }
  
  // and check the file as well
  if (strlen(file) == 0) {
    handle_error(ern_FILENAME_MISSING, "Attempt to open a file with no file name");
    return false;
  }
  
  // if all of that is valid, check the file list to see if it's open
  for (int i = 0; i < max_file_num; i++) {
    if (strcmp(file_name_map[i], file) == 0) {
      handle_error(ern_FILE_OPEN, "Attempt to open a file that is already open");
      return false;
    }
  }
  
  // if the mode is "r" or "a", the file needs to exist already
  if (tolower(mode[0]) == 'r' || tolower(mode[0]) == 'a') {
    if (!exists(name)) {
      handle_error(ern_FILE_NOT_FOUND, "Attempt to open a file for read or append but it does not exist");
      return false;
    }
  }
  
  // if the mode is "w", the file *cannot* already exist
  if (tolower(mode[0]) == 'w' && exists(name)) {
    // FIXME: this should be "FILE EXISTS"
    handle_error(ern_FILE_NOT_FOUND, "Attempt to open a file for write but it already exists");
    return false;
  }
  
  // all the inputs are valid, try to open the file
  FILE* fp = fopen(name, mode);
  if (fp == NULL) {
    handle_error(ern_FILE_OPEN, "Attempt to open a file failed for unknown reason");
    return false;
  }
  
  // is it now open, so record it
  file_handle_map[channel] = fp;
  strcpy(file_name_map[channel], name);
  
  return true;
}

/*
 * Tests that the channel is open, errors otherwise.
 */
bool close_file(const int channel)
{
  FILE* fp = file_handle_map[channel];
  if (fp == 0) {
    handle_error(ern_FILE_NOT_OPEN, "Attempt to close a file that is not open");
    return false;
  }
  
  // it is open, so flush it, close it, and forget it
  fflush(fp);
  int c = fclose(fp);
  if (c == EOF) {
    handle_error(ern_FILE_NOT_OPEN, "Attempt to close a file that is not open");
    return false;
  }
  
  file_handle_map[channel] = 0;
  file_name_map[channel][0] = '\0';
  return true;
}

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
