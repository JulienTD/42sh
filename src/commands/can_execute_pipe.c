/*
** EPITECH PROJECT, 2018
** execute_pipe
** File description:
** execute_pipe
*/

#include "42sh.h"

int can_execute_pipe(char **args, shell_t *shell, char *path, queue_t *queue)
{
	struct stat buf;

	if (stat(path, &buf) == -1)
		return (0);
	return (pipe_commands(path, args, queue, shell));
}