/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** check all alias
*/

#include "42sh.h"

bool test_alias(char **args, shell_t *shell)
{
	if (shell->alias == NULL)
		return (true);
	if (args == NULL)
		return (true);
	if (args[0] == NULL)
		return (true);
	if (strlen(args[0]) < 1)
		return (true);
	return (false);
}

char **my_dup_2d_tab(char **arr)
{
	int len = my_length_tab(arr);
	char **ret = malloc(sizeof(char *) * (len + 1));

	if (ret == NULL)
		exit (84);
	for (int i = 0; arr[i]; i++)
		ret[i] = strdup(arr[i]);
	ret[len] = NULL;
	return (ret);
}

char **change_args_alias(char **args, alias_t *alias)
{
	char **old_cmd = my_str_split(alias->old_cmd, ' ');
	int len = my_length_tab(args) + my_length_tab(old_cmd);
	char **new = malloc(sizeof(char *) * (len));
	int i = 0;

	if (new == NULL)
		exit (84);
	while (old_cmd[i] && strlen(old_cmd[i]) > 0) {
		new[i] = strdup(old_cmd[i]);
		i++;
	}
	for (int j = 1; args[j] && i < len; j++)
		new[i++] = strdup(args[j]);
	new[i] = NULL;
	free_2d_tab(args);
	free_2d_tab(old_cmd);
	return (new);
}

char **check_alias(char **args, shell_t *shell)
{
	int i = 0;

	if (test_alias(args, shell))
		return (args);
	while (shell->alias[i] && shell->alias[i]->new_cmd) {
		if (strcmp(shell->alias[i]->new_cmd, args[0]) == 0)
			break;
		i++;
	}
	if (shell->alias[i] == NULL || shell->alias[i]->new_cmd == NULL)
		return (args);
	if (shell->alias[i]->old_cmd == NULL)
		return (args);
	if (my_char_count(shell->alias[i]->old_cmd, ' ') > 0)
		args = change_args_alias(args, shell->alias[i]);
	else {
		free(args[0]);
		args[0] = strdup(shell->alias[i]->old_cmd);
	}
	return (args);
}