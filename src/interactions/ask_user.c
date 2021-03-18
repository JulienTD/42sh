/*
** EPITECH PROJECT, 2018
** ask_user
** File description:
** ask_user
*/

#include "42sh.h"

bool check_raw_command(char *raw_command, shell_t *shell)
{
	if (raw_command == NULL) {
		write(1, "exit\n", 5);
		exit (shell->to_return % 256);
	}
	if (raw_command == NULL)
		return (true);
	return (false);
}

static int process_cmd(char *raw_command, shell_t *shell)
{
	queue_t *queue = NULL;

	raw_command = clear_str(raw_command);
	store_cmd(raw_command, shell->hist);
	raw_command = replace_str_by_env_var(raw_command, shell);
	if (raw_command == NULL)
		return (1);
	raw_command = format_raw_commands(raw_command);
	separate_commands(raw_command, &queue);
	if (analyse_queue(&queue, shell) != -1)
		execute_queue(&queue, shell);
	free_queue(&queue);
	if (raw_command)
		free(raw_command);
	return (0);
}

int ask_user(shell_t *shell)
{
	char *raw_command = NULL;

	while (1) {
		display_prompt(shell);
		raw_command = get_next_line(0);
		if (check_raw_command(raw_command, shell))
			break;
		if (check_wrong_raw_command(raw_command)) {
			free(raw_command);
			continue;
		}
		process_cmd(raw_command, shell);
	}
	return (0);
}