#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Parser.H"
#include "Interpreter.H"
#include "Absyn.H"

int main(int argc, char ** argv)
{
  FILE *input;
  if (argc > 1) 
  {
    input = fopen(argv[1], "r");
    if (!input)
    {
      fprintf(stderr, "Error opening input file.\n");
      exit(1);
    }
  }
  else input = stdin;
  /* The default entry point is used. For other options see Parser.H */
  Prog *parse_tree = pProg(input);
  if (parse_tree)
  {
    printf("\nParse Succesful!\n");
    return 0;
  }
  return 1;
}

