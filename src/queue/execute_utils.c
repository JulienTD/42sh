/*
** EPITECH PROJECT, 2018
** execute_queue
** File description:
** execute_queue
*/

#include "42sh.h"

pid_t my_fork(char **cmd, shell_t *shell)
{
	if (cmd == NULL)
		return (fork());
	if (cmd[0] == NULL)
		return (fork());
	if (strcmp(cmd[0], "exit") == 0) {
		printf("yolo ça marche !\n");
		my_exit(cmd, shell);
	}
	return (fork());
}

bool condition(bool and_cond, bool or_cond, shell_t *shell)
{
	if (and_cond == false && or_cond == false)
		return (true);
	if (and_cond == true && shell->to_return == 0)
		return (true);
	if (or_cond == true && shell->to_return != 0)
		return (true);
	return (false);
}

int execute_utils(queue_t *curr, shell_t *shell)
{
	int status = 0;

	if (curr->contain_pipe == 1)
		status = fork_execute_pipe(curr, shell);
	else
		execute_basic(curr, shell);
	if (status == 1)
		return (1);
	return (0);
}