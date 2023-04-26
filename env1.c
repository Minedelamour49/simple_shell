#include "main.h"

/**
 * cmp_env_name - compares env variables names
 * with the name passed.
 * @nenv: name of the environment variable
 * @name: name passed
 *
 * Return: 0 if are not equal. Another value if they are.
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * _getenv - get an environment variable
 * @name: name of the environment variable
 * @_environment: environment variable
 *
 * Return: value of the environment variable if is found.
 * In other case, returns NULL.
 */
char *_getenv(const char *name, char **_environment)
{
	char *ptr_env;
	int i, mov;

	/* Initialize ptr_env value */
	ptr_env = NULL;
	mov = 0;
	/* Compare all the environment variables */
	/* environment is declared in the header file */
	for (i = 0; _environment[i]; i++)
	{
		/* If the name and env are equal */
		mov = cmp_env_name(_environment[i], name);
		if (mov)
		{
			ptr_env = _environment[i];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * _env - prints the environment variables
 *
 * @datash: data relevant.
 * Return: 1 on success.
 */
int _env(data_shell *datash)
{
	int i, j;

	for (i = 0; datash->_environment[i]; i++)
	{

		for (j = 0; datash->_environment[i][j]; j++)
			;

		write(STDOUT_FILENO, datash->_environment[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
