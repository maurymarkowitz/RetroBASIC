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
#include <limits.h>

#if defined(WIN32) || defined(_WIN32)
#include <io.h>
#include <conio.h>
#include <direct.h>

/* Declare Windows functions for cross-compiler compatibility */
int _access(const char *path, int mode);
int _isatty(int fd);

#define F_OK 0
#define R_OK 4
#define W_OK 2
#define access _access
#define isatty _isatty

#define realpath(path, resolved) _fullpath((resolved), (path), PATH_MAX)
#endif

#define MAX_OPEN_FILES 16 //!< the maximum number of files that can be open at once
#define MAX_FILE_NUM 256 //!< the maximum file handle number
FILE* file_handle_map[MAX_FILE_NUM]; //!< maps the file numbers to C handles
char file_name_map[MAX_FILE_NUM][PATH_MAX]; //!< maps the file numbers to C handles

#if !defined(WIN32) && !defined(_WIN32)
static struct termios original_terminal_attrs;
static bool terminal_raw_mode = false;
static int buffered_key = -1;
#endif

/*
 * Sets up the terminal for non-blocking raw input. Called once at startup
 * so that get_key() and peek_key() never need to touch terminal settings.
 */
void setup_terminal_for_input(void)
{
#if !defined(WIN32) && !defined(_WIN32)
  if (terminal_raw_mode)
    return;
  struct termios raw;
  if (tcgetattr(STDIN_FILENO, &original_terminal_attrs) < 0) {
    // stdin is not a TTY (e.g., piped input), skip terminal setup
    return;
  }
  raw = original_terminal_attrs;
  raw.c_lflag &= ~(ICANON | ECHO);  // non-canonical, no echo
  raw.c_oflag |= (OPOST | ONLCR);   // ensure output processing and \n to \r\n conversion
  // ISIG is intentionally left set so Ctrl-C/Ctrl-\ still raise signals
  raw.c_cc[VMIN]  = 0;
  raw.c_cc[VTIME] = 0;
  tcsetattr(STDIN_FILENO, TCSANOW, &raw);
  terminal_raw_mode = true;
#endif
}

/*
 * Restores the terminal to its original canonical state. Call this before
 * any fgets(stdin) so that the user gets normal line-editing, then call
 * setup_terminal_for_input() again afterwards.
 */
void restore_terminal(void)
{
#if !defined(WIN32) && !defined(_WIN32)
  if (!terminal_raw_mode)
    return;
  tcsetattr(STDIN_FILENO, TCSANOW, &original_terminal_attrs);
  terminal_raw_mode = false;
#endif
}

void terminate_retrobasic(int status)
{
#if !defined(WIN32) && !defined(_WIN32)
  restore_terminal();
#endif
  exit(status);
}

/*
 * Returns the file pointer for a given channel.
 */
FILE* handle_for_channel(int channel)
{
  if (channel < 0 || channel >= MAX_FILE_NUM) {
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
  if (channel < 1 || channel >= MAX_FILE_NUM) {
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
  if (channel < 1 || channel >= MAX_FILE_NUM) {
    handle_error(ern_BAD_SUBSCRIPT, "Attempt to use a file channel that is outside the allowed range");
    return false;
  }
  
  // test that we can get to that file, which should never fail because we tested it on open
  char *path = path_for_channel(channel);
  char temp_path[PATH_MAX];
  if (realpath(path, temp_path) == NULL)
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
  for (int i = 0; i < MAX_FILE_NUM; i++) {
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
    handle_error(ern_FILE_OPEN, "Attempt to open a file in a channel that is already open");
    return false;
  }
  
  // don't allow too many files to be open
  int num_open = 0;
  for (int i = 0; i < MAX_FILE_NUM; i++) {
    if (file_handle_map[i] != 0)
      num_open++;
  }
  if (num_open >= MAX_OPEN_FILES) {
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
  for (int i = 0; i < MAX_FILE_NUM; i++) {
    if (strcmp(file_name_map[i], file) == 0) {
      handle_error(ern_FILE_OPEN, "Attempt to open a file that is already open");
      return false;
    }
  }
  
  // force the mode to lower, which Unix demands
  char lmode[2];
  lmode[0] = tolower(mode[0]);
  lmode[1] = '\0';
  
  // if the mode is "r"ead or "a"ppent, the file needs to exist already
  if (lmode[0] == 'r' || lmode[0] == 'a') {
    if (!exists(name)) {
      handle_error(ern_FILE_NOT_FOUND, "Attempt to open a file for read or append but it does not exist");
      return false;
    }
  }
  
  // if the mode is "n"ew, the file *cannot* already exist
  if (lmode[0] == 'n' && exists(name)) {
    handle_error(ern_FILE_EXISTS, "Attempt to open a file for write but it already exists");
    return false;
  }
  
  // "n"ew is the same as "w"rite from C's perspective
  if (lmode[0] == 'n')
    lmode[0] = 'w';

  // all the inputs are valid, try to open the file
  FILE* fp = fopen(name, lmode);
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
 * Tests that the file is not open and then attempts to create it.
 */
bool create_file(const char *file)
{
  // see if the file is open
  for (int i = 0; i < MAX_FILE_NUM; i++) {
    if (strcmp(file_name_map[i], file) == 0) {
      handle_error(ern_FILE_OPEN, "Attempt to create a file that is open");
      return false;
    }
  }
  
  // see if it exists
  if (access(file, F_OK) == 0) {
    handle_error(ern_FILE_NOT_FOUND, "Attempt to create file failed because it already exists");
    return false;
  }
  
  // create it if we can
  FILE* fp = fopen("textFile.txt" ,"a");
  if (fp == NULL) {
    handle_error(ern_FILE_NOT_FOUND, "Attempt to create file failed for unknown reason");
    return false;
  }

  fclose(fp);
  return true;
}

/*
 * Tests that the file is not open and then attempts to delete it.
 */
bool delete_file(const char *file)
{
  // see if the file is open
  for (int i = 0; i < MAX_FILE_NUM; i++) {
    if (strcmp(file_name_map[i], file) == 0) {
      handle_error(ern_FILE_OPEN, "Attempt to delete a file that is open");
      return false;
    }
  }
  
  // see if it exists
  if (access(file, F_OK) == 0) {
    handle_error(ern_FILE_NOT_FOUND, "Attempt to delete file failed because the file doesn't exist");
    return false;
  }
  
  // delete it if we can
  if (remove(file) != 0) {
    handle_error(ern_FILE_NOT_FOUND, "Attempt to delete file failed for unknown reason");
    return false;
  }
  
  return true;
}

/*
 * Waits for a single character. Used for GET.
 * The terminal must already be in raw mode via setup_terminal_for_input().
 */
int get_byte(void)
{
#if defined(_WIN32) || defined(WIN32)
  return _getch();
#else
  if (buffered_key >= 0) {
    int key = buffered_key;
    buffered_key = -1;
    return key;
  }
  unsigned char buf[1];
  int ch = (int)read(STDIN_FILENO, buf, 1);
  return (ch > 0) ? buf[0] : -1;
#endif
}

/*
 * Gets a single keystroke, or 0 if no key is pressed. Used for INKEY$ and GET.
 * The terminal must already be in raw mode via setup_terminal_for_input().
 */
int get_key(void)
{
#if _WIN32
  return kbhit() ? getch() : 0;
#else
  if (buffered_key >= 0) {
    int key = buffered_key;
    buffered_key = -1;
    if (key == 3 || key == 24)
      terminate_retrobasic(EXIT_SUCCESS);
    return key;
  }
  unsigned char buf[1];
  int ch = (int)read(STDIN_FILENO, buf, 1);
  if (ch > 0) {
    if (buf[0] == 3 || buf[0] == 24)
      terminate_retrobasic(EXIT_SUCCESS);
    return buf[0];
  }
  return 0;
#endif
}

/*
 * Returns the next key without consuming it, or 0 if no key is pending.
 * The terminal must already be in raw mode via setup_terminal_for_input().
 */
int peek_key(void)
{
#if _WIN32
  return kbhit() ? 1 : 0;
#else
  if (buffered_key >= 0)
    return buffered_key;
  unsigned char buf[1];
  int ch = (int)read(STDIN_FILENO, buf, 1);
  if (ch > 0) {
    if (buf[0] == 3 || buf[0] == 24)
      terminate_retrobasic(EXIT_SUCCESS);
    buffered_key = buf[0];
    return buf[0];
  }
  return 0;
#endif
}

/*
 * Reads a line from stdin in raw mode, supporting basic editing and detecting ESC for BREAK.
 * Returns 1 on success (line in buffer), 0 on EOF, -1 if ESC/BREAK detected.
 */
int raw_mode_input_line(char *buffer, size_t size)
{
#if defined(_WIN32) || defined(WIN32)
  /* Windows falls back to canonical fgets behavior for INPUT */
  return (fgets(buffer, size, stdin) == buffer) ? 1 : 0;
#else
  /* If stdin is not a TTY, use fgets instead of raw mode */
  if (!isatty(STDIN_FILENO)) {
    return (fgets(buffer, size, stdin) == buffer) ? 1 : 0;
  }
  
  size_t pos = 0;
  unsigned char c;
  
  while (pos < size - 1) {
    /* If peek_key() buffered a character, consume it first */
    if (buffered_key >= 0) {
      c = (unsigned char)buffered_key;
      buffered_key = -1;
    } else {
      /* Use select to wait for input */
      fd_set rfds;
      struct timeval tv;
      FD_ZERO(&rfds);
      FD_SET(STDIN_FILENO, &rfds);
      tv.tv_sec = 0;
      tv.tv_usec = 100000;  /* 100ms timeout to check for BREAK periodically */

      int sel = select(STDIN_FILENO + 1, &rfds, NULL, NULL, &tv);
      if (sel < 0) {
        buffer[pos] = '\0';
        return -1;  /* error */
      }
      if (sel == 0) {
        /* Timeout - loop again */
        continue;
      }

      /* Data available, read one character */
      int ch = read(STDIN_FILENO, &c, 1);
      if (ch <= 0) {
        buffer[pos] = '\0';
        return (ch == 0) ? 0 : -1;  /* EOF or error */
      }
    }
    
    if (c == 27) {  /* ESC */
      buffer[pos] = '\0';
      return -1;     /* BREAK */
    }
    if (c == 3 || c == 24) {  /* Ctrl-C or Ctrl-X */
      buffer[pos] = '\0';
      terminate_retrobasic(EXIT_SUCCESS);
    }
    
    if (c == '\n' || c == '\r') {
      buffer[pos] = '\0';
      write(STDOUT_FILENO, "\n", 1);
      return 1;      /* success */
    }
    
    if (c == 127 || c == 8) {  /* DEL or backspace */
      if (pos > 0) {
        pos--;
        write(STDOUT_FILENO, "\b \b", 3);  /* erase character */
      }
      continue;
    }
    
    if (c >= 32 && c < 127) {  /* printable ASCII */
      buffer[pos++] = c;
      write(STDOUT_FILENO, &c, 1);  /* echo */
    }
    /* ignore other control chars */
  }
  
  buffer[pos] = '\0';
  return 1;  /* buffer full */
#endif
}
