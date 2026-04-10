/**
 * @file cli.c
 * @author Maury Markowitz
 * @date 7 April 2026
 * @brief Interactive CLI implementation for RetroBASIC.
 *
 * Provides the runtime loop and input-handling utilities for the interactive
 * command-line mode used when the interpreter is started without a filename.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "retrobasic.h"
#include "cli.h"
#include "io.h"
#include "list.h"
#include "strng.h"

static void clear_terminal(void)
{
#if defined(WIN32) || defined(_WIN32)
  system("cls");
#else
  if (isatty(STDOUT_FILENO))
    printf("\x1b[2J\x1b[H");
#endif
}

static char *cli_read_line(void)
{
  char *buf = malloc(1024);
  if (!buf)
    return NULL;
  int result = raw_mode_input_line(buf, 1024);
  if (result <= 0) {
    free(buf);
    return (result == 0) ? NULL : strdup("");  /* EOF → NULL, BREAK → empty */
  }
  return buf;
}

/**
 * @copydoc interpreter_cli
 */
void interpreter_cli(void)
{
  clear_terminal();
  printf("RetroBASIC CLI\n\n");

  while (1) {
    printf("%s ", cli_prompt);
    fflush(stdout);

    char *raw_input = cli_read_line();
    if (raw_input == NULL)
      break;

    char *input = str_trim(raw_input);
    if (*input == '\0') {
      free(raw_input);
      continue;
    }

    list_t *statements = NULL;
    if (interpreter_parse_cli_input(input, &statements) != 0) {
      free(raw_input);
      continue;
    }

    if (statements != NULL) {
      bool has_statement = false;
      for (list_t *node = lst_first_node(statements); node != NULL; node = node->next) {
        if (node->data != NULL) {
          has_statement = true;
          break;
        }
      }
      if (has_statement)
        interpreter_execute_statement_list(statements);
      lst_free(statements);
    } else {
      interpreter_state.first_line = -1;
      interpreter_state.current_statement = NULL;
      interpreter_state.next_statement = NULL;
    }

    free(raw_input);
    if (interpreter_state.exit_requested)
      break;
  }
}
