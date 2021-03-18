/*
** EPITECH PROJECT, 2018
** execute_basic
** File description:
** execute_basic
*/

#include "42sh.h"

int can_execute_basic(char **args, shell_t *shell, char *path, queue_t *queue)
{
	struct stat buf;

	if (stat(path, &buf) == -1)
		return (0);
	return (fork_command(path, args, queue, shell));
}