/*
** EPITECH PROJECT, 2018
** pipe_commands
** File description:
** pipe_commands
*/

#include "42sh.h"

int pipe_commands(char *path, char **newargv, queue_t *queue, shell_t *shell)
{
	int pipefd[2];
	pid_t cpid = 0;
	char **new_env = hashmap_to_2d(&(shell->hm_env));

	if (pipe(pipefd) == -1)
		exit(84);
	if ((cpid = fork()) == -1)
		return (0);
	if (cpid != 0) {
		dup2(pipefd[1], 1);
		close(pipefd[0]);
	} else {
		dup2(pipefd[0], 0);
		close(pipefd[1]);
		apply_redir(queue, true);
		if (execve(path, newargv, new_env) == -1)
			print_command_error(errno, path);
		exit(1);
	}
	return (1);
}