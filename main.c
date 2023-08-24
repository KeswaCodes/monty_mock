#include "monty.h"

/**
 *main- main execution point
 *@argc: argument count
 *@argv: argument vector
 *Return: 0 successful
 */

int main(int argc, char *argv[])
{
char *opcode, *opcode_value;
FILE *file = NULL;
void (*f)(stack_t **stack, unsigned int line_number);
stack_t *stack = NULL;
unsigned int line_num = 0;
struct opcodeValue result;

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

_get_opcode_and_value(&result);
opcode = _get_opcode_and_value(file, 1);
opcode_value = _get_opcode_and_value(file, 0);

f = get_opcode_function(opcode);
if (f == NULL)
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
exit(EXIT_FAILURE);
}
f(&stack, line_num);
}
return (0);
}
