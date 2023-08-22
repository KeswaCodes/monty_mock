#include "monty.h"

/**
 *main- main execution point
 *@argc: argument count
 *@argv: argument vector
 *Return: 0 successful
 */

int main(int argc, char *argv[])
{
  char buffer[1024];
  FILE *file = NULL;

  if (argc > 2)
    exit(EXIT_FAILURE);
  
  if (!argv[1])
    {
      fprintf(stderr, "USAGE: monty file\n");
      exit(EXIT_FAILURE);
    }

  file = fopen(argv[1], "r");
  if (file == NULL)
    {
      fprintf(stderr, "Error: can't open file %s\n", argv[1]);
      exit(EXIT_FAILURE);
    }

  while (fgets(buffer, 256, file) != NULL)
    printf("%s\n", buffer);
  
  return (0);
    
}
