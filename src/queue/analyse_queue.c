/*
** EPITECH PROJECT, 2018
** analyse_queue
** File description:
** analyse_queue
*/

#include "42sh.h"

static bool is_pipe_cmd(char *cmd)
{
	if (cmd == NULL)
		return (false);
	for (int i = 0; cmd[i] != '\0'; i++) {
		if (cmd[i] == '|' && is_in_str(cmd, i, '\"') == false \
		&& is_in_str(cmd, i, '\'') == false)
			return (true);
	}
	return (false);
}

static bool check_error_queue2(queue_t *curr, shell_t *shell)
{
	if (curr->error_name) {
		shell->to_return = 1;
		my_putstr("Missing name for redirect.\n");
		return (true);
	}
	return (false);
}

static bool check_error_queue(queue_t *curr, shell_t *shell)
{
	if (curr->cmd == NULL) {
		shell->to_return = 1;
		my_putstr("Invalid null command.\n");
		return (true);
	}
	if (my_strlen(curr->cmd) <= 0) {
		shell->to_return = 1;
		my_putstr("Invalid null command.\n");
		return (true);
	}
	if (curr->error_ambi) {
		shell->to_return = 1;
		my_putstr("Ambiguous input redirect.\n");
		return (true);
	}
	return (check_error_queue2(curr, shell));
}

int analyse_queue(queue_t **queue, shell_t *shell)
{
	queue_t *curr = *queue;
	bool pipe_cmd = false;

	while (curr) {
		pipe_cmd = is_pipe_cmd(curr->cmd);
		curr->cmd = detect_redir(curr->cmd, curr, pipe_cmd);
		if (check_error_queue(curr, shell) == true)
			return (-1);
		if (curr->cmd != NULL && pipe_cmd == true) {
			curr->commands = separate_pipe_commands(curr->cmd);
			curr->contain_pipe = 1;
		}
		if (check_error_queue(curr, shell) == true)
			return (-1);
		curr = curr->next;
	}
	return (1);
}