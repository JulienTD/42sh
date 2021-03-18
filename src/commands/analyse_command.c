/*
** EPITECH PROJECT, 2018
** analyse_command
** File description:
** analyse_command
*/

#include "42sh.h"

static int analyse_command3(char **args, shell_t *shell, bool pipe, \
queue_t *queue)
{
	int tmp = 0;

	if (my_are_equals(args[0], "alias") == 1) {
		if (pipe == true)
			apply_redir(queue, true);
		shell->to_return = my_alias(args, shell);
		return (0);
	}
	if (my_are_equals(args[0], "echo") == 1) {
		if (pipe == true)
			apply_redir(queue, true);
		else {
			tmp = dup(1);
			apply_redir(queue, false);
		}
		shell->to_return = my_echo(args, shell, pipe, tmp);
		return (0);
	}
	execute_all(args, shell, pipe, queue);
	return (0);
}

static int analyse_command2(char **args, shell_t *shell, bool pipe, \
queue_t *queue)
{
	if (my_are_equals(args[0], "unsetenv") == 1) {
		if (pipe == true)
			apply_redir(queue, true);
		shell->to_return = my_unsetenv(args, shell);
		return (0);
	}
	if (my_are_equals(args[0], "cd") == 1) {
		if (pipe == true)
			apply_redir(queue, true);
		shell->to_return = my_cd(args, shell);
		return (0);
	}
	if (my_are_equals(args[0], "history") == 1) {
		if (pipe == true)
			apply_redir(queue, true);
		shell->to_return = my_print_history(args, shell);
		return (0);
	}
	return (analyse_command3(args, shell, pipe, queue));
}

int analyse_command(char **args, shell_t *shell, bool pipe, queue_t *queue)
{
	if (my_are_equals(args[0], "exit") == 1) {
		if (pipe == true)
			apply_redir(queue, true);
		shell->to_return = my_exit(args, shell);
		return (0);
	}
	if (my_are_equals(args[0], "env") == 1) {
		if (pipe == true)
			apply_redir(queue, true);
		shell->to_return = print_hashmap(&(shell->hm_env));
		return (0);
	}
	if (my_are_equals(args[0], "setenv") == 1) {
		if (pipe == true)
			apply_redir(queue, true);
		shell->to_return = my_setenv(args, shell);
		return (0);
	}
	return (analyse_command2(args, shell, pipe, queue));
}