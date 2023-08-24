#include "monty.h"
/**
 *_push- pushes a new element to the top of a stack
 *@stack: pointer too pointer of stack structure
 *@line_number: line at which instruction appears
 *Return: void
 */

void _push(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{

stack_t *new_element;
int value;
 struct opcodeValue result;

 get_opcode_and_value(&result);
value = _get_opcode_value();

new_element = malloc(sizeof(stack_t));
if (new_element == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_element->n = result.value;
new_element->next = NULL;
new_element->prev = NULL;

if (*stack == NULL)
*stack = new_element;

else
{
(*stack)->prev = new_element;
new_element->next = *stack;
*stack = new_element;
}

}

/**
 *_pall- prints all elements of stack
 *@stack: pointer to first element on stack
 *@line_number: the line on which error occurs
 *Return: void
 */

void _pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
stack_t *temp = *stack;

if (temp == NULL)
return;

while (temp != NULL)
{
printf("%d\n", temp->n);
temp = temp->next;
}


}
