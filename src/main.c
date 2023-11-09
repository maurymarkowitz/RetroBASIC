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

#include <getopt.h>

#include "retrobasic.h"
#include "statistics.h"
#include "parse.h"

/* simple version info for --version command line option */
static void print_version()
{
  puts("RetroBASIC 1.8.3");
}

/* usage short form, just a list of the switches */
static void print_usage(char *argv[])
{
  printf("Usage: %s [-hvsngu] [-a number] [-t spaces] [-r seed] [-p | -w stats_file] [-o output_file] [-i input_file] FILE\n", argv[0]);
}

/* full usage notes, both for the user and for documenting the code below */
static void print_help(char *argv[])
{
  printf("Usage: retrobasic [-hvsngu] [-a number] [-t spaces] [-r seed] [-p | -w stats_file] [-o output_file] [-i input_file] FILE\n");
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

static struct option program_options[] =
{
  {"help", no_argument, NULL, 'h'},
  {"version", no_argument, NULL, 'v'},
  {"upper-case", no_argument, NULL, 'u'},
  {"array-base", required_argument, NULL, 'a'},
  {"tabs", required_argument, NULL, 't'},
  {"random", optional_argument, NULL, 'r'},
  {"slicing", no_argument, NULL, 's'},
  {"goto-next", no_argument, NULL, 'g'},
  {"input-file", required_argument, NULL, 'i'},
  {"output-file", required_argument,  NULL, 'o'},
  {"print-stats", no_argument, NULL, 'p'},
  {"write-stats", required_argument, NULL, 'w'},
  {"no-run", no_argument, NULL, 'n'},
  {0, 0, 0, 0}
};

void parse_options(int argc, char *argv[])
{
  int option_index = 0;
  int printed_help = false;
  
  // one annoyance with getopt is that if you define a switch with an optional_argument,
  // it will always eat the next entry, if there is one, as its parameter. So, for instance:
  //
  // ./retrobasic -r sst.bas
  //
  // will return "sst.bas" as the parameter for -r, and eat the input. So for any optional
  // parameter switches, be sure to test the input is what you expect, and if not, back
  // up optind one space so it can be used by the next loop. see -r for an example
  char *test;
  
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
        print_help(argv);
        printed_help = true;
        break;
        
      case 'v':
        print_version();
        printed_help = true;
        break;
        
      case 'u':
        upper_case = true;
        break;
        
      case 'g':
        goto_next_highest = true;
        break;
        
      case 'n':
        run_program = false;
        break;
        
      case 's':
        string_slicing = true;
        break;
        
      case 'p':
        print_stats = true;
        break;
        
      case 'a':
        array_base = (int)strtol(optarg, 0, 10);
        break;
        
      case 't':
        tab_columns = (int)strtol(optarg, 0, 10);
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
        test = optarg;
        random_seed = (int)strtol(optarg, &test, 10);
        
        // now see if we actually read anything, we might have been handed the
        // next switch or option rather than a number. if so, use zero as the
        // seed and back up the optind so it can read it correctly
        if (test == optarg)
          optind--;
        
        break;
        
      default:
        abort();
    }
  } // while
  
  // now see if there's a filename
  if (optind <= argc && argc > 1)
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

int main(int argc, char *argv[])
{
  extern int yyparse(void);
  extern FILE *yyin;
  
  // turn this on to add verbose debugging
#if YYDEBUG
  yydebug = 1;
#endif
#define YYDEBUG 1


  // parse the options and make sure we got a filename somewhere
  parse_options(argc, argv);
  
  // call the interpreter's setup to create the state needed to parse the file
  interpreter_setup();
  
  // open the file and see if it exists
  if (strlen(source_file) == 0) {
    fprintf(stderr, "No filename provided.\n");
    exit(EXIT_FAILURE);
  }
  yyin = fopen(source_file, "r");
  if (yyin == NULL) {
    if (errno == ENOENT) {
      fprintf(stderr, "File not found or invalid filename provided.\n");
      exit(EXIT_FAILURE);
    } else {
      fprintf(stderr, "Error %i when opening file.\n", errno);
      exit(EXIT_FAILURE);
    }
  }
  // if we were able to open the file, parse it
  yyparse();
  
  // prepare the code for running
  interpreter_post_parse();
  
  // seed the random with the provided number or randomize it
  if (random_seed > -1)
    srand(random_seed);
  else
    srand((unsigned int)time(NULL) | (getpid() << 8));
  
  // now call rand to prime the pump, see:
  // https://stackoverflow.com/questions/76367489/srand-rand-slowly-changing-starting-value/76367884#76367884
  (void)rand();
  (void)rand();

  // and go!
  if (run_program)
    interpreter_run();
  
  // we're done, print/write desired stats
  if (print_stats || write_stats)
    print_statistics();
  
  // and exit
  exit(EXIT_SUCCESS);
}
