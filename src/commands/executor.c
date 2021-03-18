/*
** EPITECH PROJECT, 2018
** executor
** File description:
** executor
*/

#include "42sh.h"

char *get_full_path(char *path, char *name)
{
	char *str = malloc(my_strlen(path) + my_strlen(name) + 2);
	int j = 0;

	for (int i = 0; i < my_strlen(path); i++)
		str[j++] = path[i];
	if (str[j - 1] != '/')
		str[j++] = '/';
	for (int i = 0; i < my_strlen(name); i++)
		str[j++] = name[i];
	str[j] = '\0';
	return (str);
}

static int can_execute_here(char **args, shell_t *shell, queue_t *queue, \
bool pipe)
{
	int status = 0;

	if (pipe == true)
		status = can_execute_pipe(args, shell, args[0], queue);
	else if (pipe == false)
		status = can_execute_basic(args, shell, args[0], queue);
	if (status == 1 || status == -1)
		return (1);
	return (0);
}

static int executor_check_error(char **args, shell_t *shell)
{
	if (my_strlen(args[0]) <= 0)
		return (1);
	my_putstr(args[0]);
	my_putstr(": Command not found.\n");
	shell->to_return = 1;
	return (1);
}

int execute_all(char **args, shell_t *shell, bool pipe, queue_t *queue)
{
	list_t *path = shell->path;
	char *path_tmp = NULL;

	if (can_execute_here(args, shell, queue, pipe) == 1)
		return (1);
	while (path && args && my_strlen(args[0]) > 0 && args[0][0] != '.') {
		path_tmp = get_full_path(path->str, args[0]);
		if (pipe == true && \
		can_execute_pipe(args, shell, path_tmp, queue) == 1)
			return (1);
		else if (pipe == false && \
		can_execute_basic(args, shell, path_tmp, queue) == 1)
			return (1);
		free(path_tmp);
		path = path->next;
	}
	return (executor_check_error(args, shell));
}