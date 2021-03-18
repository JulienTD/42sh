/*
** EPITECH PROJECT, 2018
** execute_queue
** File description:
** execute_queue
*/

#include "42sh.h"

int fork_execute_pipe(queue_t *curr, shell_t *shell)
{
	pid_t cpid = 0;
	int wstatus = 0;
	int len = 0;
	for (int i = 0; curr->commands[i]; len = i++)
		if (my_strlen(curr->commands[i]) <= 0 || \
		check_wrong_raw_command(curr->commands[i])) {
			my_putstr("Invalid null command.\n");
			return (1);
		}
	cpid = fork();
	if (cpid == 0) {
		execute_pipe(curr, shell);
		exit(0);
	} else {
		for (int i = 0; i < len; i++)
			waitpid(0, &wstatus, WUNTRACED | WCONTINUED);
		print_command_result(wstatus);
	}
	return (0);
}

int check_ambiguous(char **tab, shell_t *shell, int size)
{
	for (int i = size - 1; i >= 0; i--) {
		if (my_str_contains(tab[i], '<')) {
			shell->to_return = 1;
			my_putstr("Ambiguous input redirect.\n");
			return (1);
		}
	}
	return (0);
}

int execute_pipe(queue_t *curr, shell_t *shell)
{
	int size = my_length_tab(curr->commands);
	char **args = NULL;
	char *new_cmd = NULL;
	int index = 0;

	if (check_ambiguous(curr->commands, shell, size) == 1)
		return (1);
	errno = 0;
	for (int i = size - 1; i >= 0; i--) {
		if (i == 0)
			curr->last_cmd = true;
		new_cmd = clear_str(curr->commands[i]);
		args = separate_arguments(new_cmd, true);
		args = check_alias(args, shell);
		analyse_command(args, shell, true, curr);
		while (args[index])
			free(args[index++]);
		free(args);
		free(new_cmd);
		index = 0;
		curr->first_cmd = false;
	}
	return (1);
}

int execute_basic(queue_t *curr, shell_t *shell)
{
	char **args = NULL;
	char *new_cmd = clear_str(curr->cmd);

	args = separate_arguments(new_cmd, true);
	args = check_alias(args, shell);
	if (curr->cmd == NULL || analyse_command(args, shell, false, curr))
		exit(0);
	free(new_cmd);
	return (1);
}

int execute_queue(queue_t **head, shell_t *shell)
{
	queue_t *curr = *head;
	bool and_cond = false;
	bool or_cond = false;
	int status = 0;

	while (curr) {
		if (condition(and_cond, or_cond, shell))
			status = execute_utils(curr, shell);
		if (status == 1)
			return (1);
		and_cond = curr->condition_and;
		or_cond = curr->condition_or;
		curr = curr->next;
	}
	return (1);
}