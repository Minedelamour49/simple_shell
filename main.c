#include "main.h"

/**
 * free_data - It frees the data structure
 *
 * @datash: data structure
 * Return: no return
 */
void free_data(data_shell *datash)
{
	unsigned int i;

	for (i = 0; datash->_environment[i]; i++)
	{
		free(datash->_environment[i]);
	}

	free(datash->_environment);
	free(datash->pid);
}

/**
 * set_data - Initializes the data structure
 *
 * @datash: data structure
 * @av: argument vector
 * Return: no return
 */
void set_data(data_shell *datash, char **av)
{
	unsigned int i;
    datash->input = NULL;
	datash->av = av;
	datash->args = NULL;
    datash->counter = 1;
	datash->status = 0;
	
	for (i = 0; environment[i]; i++)
		;

	datash->_environment = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environment[i]; i++)
	{
		datash->_environment[i] = _strdup(environment[i]);
	}

	datash->_environment[i] = NULL;
	datash->pid = auxiliary_itoa(getpid());
}

/**
 * main - Entry point
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	data_shell datash;
	(void) ac;

	signal(SIGINT, get_sigint);
	set_data(&datash, av);
	shell_loop(&datash);
	free_data(&datash);
	if (datash.status < 0)
		return (255);
	return (datash.status);
}

