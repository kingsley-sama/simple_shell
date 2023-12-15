#include "shell.h"

/**
 * env_array - Creates an array of Enviroment Variables.
 * @envi: Array to store Enviroment Variables.
 *
 * Return:Void
 */

void env_array(char **envi)
{
	int i;

	for (i = 0; environ[i]; i++)
	envi[i] = str_dup(environ[i]);
	envi[i] = NULL;
}

/**
 * free_environment - Frees the memory of the created
 *                    Enviroment Variables array
 * @env:  Array of Environment variables
 *
 * Return:Void
 */
void free_environment(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
	free(env[i]);
	}
}
