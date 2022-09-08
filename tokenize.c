#include "monty.h"

/**
 * tokenize - tokenize a given buffer
 * @buffer: string to tokenize
 *
 * Return: an array
 */
char **tokenize(char *buffer)
{
	char *token = NULL; /* ptr to next token */
	char **store; /* store tokens in array */
	int idx = 3;
	char *delim = "\t  \r\n";

	token = strtok(buffer, delim);

	if (token == NULL)
		return (NULL);

	store = malloc(sizeof(char **) * 3);
	if (store == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free(buffer);
		exit(EXIT_FAILURE);
	}

	while (--idx)
		store[idx - 1] = NULL;

	while (token)
	{
		if (idx < 3)
			store[idx] = token;
		token = strtok(NULL, delim); /* pt to next token */
		idx++;
	}

	store[2] = NULL;

	return (store);
}
