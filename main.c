#include "monty.h"

unsigned int line_number = 0;

/**
 * main - control program flow
 * @argc: argument count
 * @argv: argument list
 * Return: Nothing
 */
int main(int argc, char *argv[])
{
	char **tokens = NULL; /* for tokenized list */
	stack_t *head = NULL; /* pointer to top of stack */
	char *buffer = NULL; /* store getline */
	FILE *fp;
	size_t n;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r+");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((getline(&buffer, &n, fp)) != -1)
	{
		line_number++;
		tokens = tokenize(buffer); /* result is at top of list */
		if (tokens)
		{
			call(tokens, &head);
			free(tokens);
		}
	}
	free(buffer);
	free_stack(&head);
	fclose(fp);

	return (0);
}

/**
 * free_stack - free the stack
 * @stack: ptr to stack
 * Return: Nothing
 */
void free_stack(stack_t **stack)
{
	stack_t *head = *stack;

	while (head)
	{
		if (!head->next)
		{
			free(head);
			break;
		}
		head = head->next;
		free(head->prev);
	}
}
