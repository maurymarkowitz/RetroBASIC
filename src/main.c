/* Main for RetroBASIC
 Copyright (C) 2020 Maury Markowitz
 
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

#ifdef _WIN32
#else
#include <getopt.h>
#endif // _WIN32

#include "retrobasic.h"
#include "statistics.h"
#include "parse.h"

/* defitions of variables used by the static analyzer */
#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
  #define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
ULONGLONG start_ticks, end_ticks;         // start and end ticks, for calculating CPU time
SYSTEMTIME start_time, end_time;
#else
clock_t start_ticks = 0, end_ticks = 0;   // start and end ticks, for calculating CPU time
struct timeval start_time, end_time;      // start and end clock, for total run time
#endif

/* simple version info for --version command line option */
static void print_version()
{
  puts("RetroBASIC 1.2");
}

/* usage short form, just a list of the switches */
static void print_usage_unix(char *argv[])
{
  puts("Usage: retrobasic [-hvsngu] [-a number] [-t spaces] [-r seed] [-p | -w stats_file] [-o output_file] [-i input_file] source_file\n");
}

/* same for win */
static void print_usage_windows(char* argv[])
{
  puts("RETROBASIC [/H] [/V] [/S] [/N] [/G} [/U] [/T:spaces] [/R:seed][/P | /W:stats_file] [/O:output_file] [/I:input_file] [drive:][path][source_file]\n");
}

/* full usage notes, both for the user and for documenting the code below */
static void print_help_unix(char *argv[])
{
  printf("Usage: retrobasic [-hvsngu] [-a number] [-t spaces] [-r seed] [-p | -w stats_file] [-o output_file] [-i input_file] source_file\n");
  puts("\nOptions:");
  puts("  -h, --help: print this description");
  puts("  -v, --version: print version info");
  puts("  -u, --upper-case: convert all input to upper case");
  puts("  -a, --array-base: minimum array index, normally 1");
  puts("  -s, --slicing: turn on string slicing (turning off string arrays)");
  puts("  -n, --no-run: don't run the program after parsing");
  puts("  -g, --goto-next: if a branch target doesn't exist, go to the next line");
  puts("  -t, --tabs: set the number of spaces for comma-separated items");
  puts("  -r, --random: seed the random number generator");
  puts("  -p, --print-stats: when the program exits, print statistics");
  puts("  -w, --write-stats: on exit, write statistics to a file");
  puts("  -o, --output-file: redirect PRINT and PUT to the named file");
  puts("  -i, --input-file: redirect INPUT and GET from the named file");
}

/* similar to above, but with the DOS-style argument list */
static void print_help_windows(char* argv[])
{
  printf("Runs old BASIC programs provided in text format.\n\n");
  printf("RETROBASIC [/H] [/V] [/S] [/N] [/G} [/U] [/T:spaces] [/R:seed][/P | /W:stats_file] [/O:output_file] [/I:input_file] [drive:][path][source_file]\n");
  puts("  [drive:][path][filename]");
  puts("              Specifies drive, directory and the filename to open and run.\n");
  puts("\nOptions:");
  puts("  -h, --help: print this description");
  puts("  -v, --version: print version info");
  puts("  -u, --upper-case: convert all input to upper case");
  puts("  -a, --array-base: minimum array index, normally 1");
  puts("  -s, --slicing: turn on string slicing (turning off string arrays)");
  puts("  -n, --no-run: don't run the program after parsing");
  puts("  -g, --goto-next: if a branch target doesn't exist, go to the next line");
  puts("  -t, --tabs: set the number of spaces for comma-separated items");
  puts("  -r, --random: seed the random number generator");
  puts("  -p, --print-stats: when the program exits, print statistics");
  puts("  -w, --write-stats: on exit, write statistics to a file");
  puts("  -o, --output-file: redirect PRINT and PUT to the named file");
  puts("  -i, --input-file: redirect INPUT and GET from the named file");
}

/* parse the options */
#ifdef _WIN32
void parse_options_windows(int argc, char* argv[])
{
  //TODO!
}
#else
static struct option program_options[] =
{
  {"help", no_argument, NULL, 'h'},
  {"version", no_argument, NULL, 'v'},
  {"upper-case", no_argument, NULL, 'u'},
  {"array-base", required_argument, NULL, 'a'},
  {"tabs", required_argument, NULL, 't'},
  {"random", required_argument, NULL, 'r'},
  {"slicing", no_argument, NULL, 's'},
  {"goto-next", no_argument, NULL, 'g'},
  {"input-file", required_argument, NULL, 'i'},
  {"output-file", required_argument,  NULL, 'o'},
  {"print-stats", no_argument, NULL, 'p'},
  {"write-stats", required_argument, NULL, 'w'},
  {"no-run", no_argument, NULL, 'n'},
  {0, 0, 0, 0}
};

void parse_options_unix(int argc, char *argv[])
{
  int option_index = 0;
  int printed_help = FALSE;
  
  while (1) {
    // eat an option and exit if we're done
    int c = getopt_long(argc, argv, "hvua:t:r:i:o:w:spn", program_options, &option_index); // should match the items above, but with flag-setters excluded
    if (c == -1) break;
    
    switch (c) {
      case 0:
        // flag-setting options return 0 - these are s, p and n
        if (program_options[option_index].flag != 0)
          break;
        
      case 'h':
        print_help_unix(argv);
        printed_help = TRUE;
        break;
        
      case 'v':
        print_version();
        printed_help = TRUE;
        break;
        
      case 'u':
        upper_case = TRUE;
        break;
        
      case 'g':
        goto_next_highest = TRUE;
        break;
        
      case 'n':
        run_program = FALSE;
        break;
        
      case 's':
        string_slicing = TRUE;
        break;
        
      case 'p':
        print_stats = TRUE;
        break;
        
      case 'a':
        array_base = (int)strtol(optarg, 0, INT_MAX);;
        break;
        
      case 't':
        tab_columns = (int)strtol(optarg, 0, INT_MAX);;
        break;
        
      case 'i':
        input_file = optarg;
        break;
        
      case 'o':
        print_file = optarg;
        break;
        
      case 'w':
        write_stats = 1;
        stats_file = optarg;
        break;
        
      case 'r':
        random_seed = strtol(optarg, 0, INT_MAX);
        
      default:
        abort();
    }
  } // while
  
  // now see if there's a filename
  if (optind < argc)
    // we'll just assume one file if any
    source_file = argv[argc - 1];
  else
    // not always a failure, we might have just been asked for usage
    if (printed_help)
      exit(EXIT_SUCCESS);
    else {
      print_usage(argv);
      exit(EXIT_FAILURE);
    }
}
#endif // _WIN32

int main(int argc, char *argv[])
{
  extern int yyparse(void);
  extern FILE *yyin;
  
  // turn this on to add verbose debugging
#if YYDEBUG
  yydebug = 1;
#endif

  // parse the options and make sure we got a filename somewhere
#ifdef _WIN32
  parse_options_windows(argc, argv);
#else
  parse_options_unix(argc, argv);
#endif
  
  // call the interpreter's setup to create the state needed to parse the file
  interpreter_setup();
  
  // open the file and see if it exists
  yyin = fopen(source_file, "r");
  if (yyin == NULL) {
    if (errno == ENOENT) {
      fprintf(stderr, "File not found or no filename provided.");
      exit(EXIT_FAILURE);
    } else {
      fprintf(stderr, "Error %i when opening file.", errno);
      exit(EXIT_FAILURE);
    }
  }
  // if we were able to open the file, parse it
  yyparse();
  
  // prepare the code for running
  interpreter_post_parse();
  
  // seed the random with the provided number or randomize it
  if (random_seed > -1)
    srand((unsigned int)random_seed);
  else
    srand((unsigned int)time(0));

  // start the clock
#ifdef _WIN32
  start_ticks = GetTickCount64();
  GetSystemTime(&start_time);
#else
  start_ticks = clock();
  gettimeofday(&start_time, NULL);
#endif
  
  // and go!
  if (run_program)
    interpreter_run();

  // stop the clock
#ifdef _WIN32
  end_ticks = GetTickCount64();
  GetSystemTime(&end_time);
#else
  end_ticks = clock();
  gettimeofday(&end_time, NULL);
#endif

  // we're done, print/write desired stats
  if (print_stats || write_stats)
    print_statistics();
  
  // and exit
  exit(EXIT_SUCCESS);
}
