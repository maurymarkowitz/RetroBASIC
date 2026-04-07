/**
 * @file cli.h
 * @author Maury Markowitz
 * @date 7 April 2026
 * @brief Public declarations for the RetroBASIC interactive CLI.
 *
 * This header exposes the entry point for the command-line interface used
 * when RetroBASIC is launched without a source filename.
 */

#ifndef __CLI_H__
#define __CLI_H__

/**
 * Start the interactive RetroBASIC command-line interface.
 *
 * The CLI accepts immediate-mode statements, program line edits, and
 * commands like RUN, LIST, LOAD, SAVE, CONT and BYE.
 */
void interpreter_cli(void);

#endif // __CLI_H__
