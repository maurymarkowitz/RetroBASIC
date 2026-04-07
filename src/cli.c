/**
 * @file cli.c
 * @author Maury Markowitz
 * @date 7 April 2026
 * @brief Interactive CLI implementation for RetroBASIC.
 *
 * Provides the runtime loop and input-handling utilities for the interactive
 * command-line mode used when the interpreter is started without a filename.
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "retrobasic.h"
#include "cli.h"
#include "list.h"
#include "strng.h"

static char *cli_read_line(void)
{
  char *line = NULL;
  size_t size = 0;

  if (getline(&line, &size, stdin) == -1) {
    if (feof(stdin)) {
      free(line);
      return NULL;
    }
    if (errno == EINTR) {
      clearerr(stdin);
      if (line) free(line);
      return strdup("");
    }
    free(line);
    return NULL;
  }

  size_t len = strlen(line);
  while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r')) {
    line[--len] = '\0';
  }

  return line;
}

/**
 * @copydoc interpreter_cli
 */
void interpreter_cli(void)
{
  printf("RetroBASIC CLI\n");
  printf("Type RUN to execute, LIST to display the program, or BYE to return to the prompt.\n");

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
  }
}
