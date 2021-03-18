/*
** EPITECH PROJECT, 2018
** fork_command
** File description:
** fork_command
*/

#include "42sh.h"

int fork_command(char *path, char **newargv, queue_t *queue, shell_t *shell)
{
	pid_t cpid = 0;
	int wstatus = 0;
	int value = 0;
	char **new_env = hashmap_to_2d(&(shell->hm_env));

	cpid = fork();
	if (cpid == 0) {
		errno = 0;
		apply_redir(queue, false);
		value = execve(path, newargv, new_env);
		if (value == -1)
			print_command_error(errno, path);
		exit(1);
	} else {
		waitpid(cpid, &wstatus, WUNTRACED | WCONTINUED);
		shell->to_return = print_command_result(wstatus);
	}
	return (1);
}