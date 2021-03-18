/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** alias command
*/

#include "42sh.h"

void print_alias(shell_t *shell, char *str)
{
	if (shell->alias == NULL)
		return;
	if (str == NULL) {
		for (int i = 0; shell->alias[i]; i++)
			my_printf("%s\t%s\n",
				shell->alias[i]->new_cmd,
				shell->alias[i]->old_cmd);
		return;
	}
	if (strlen(str) < 1)
		return;
	for (int i = 0; shell->alias[i]; i++)
		if (my_are_equals(shell->alias[i]->new_cmd, str)) {
			my_printf("%s\t%s\n",
				shell->alias[i]->new_cmd,
				shell->alias[i]->old_cmd);
			return;
		}
}

void add_new_alias(shell_t *shell, char **args)
{
	alias_t *alias = malloc(sizeof(alias_t));
	int len = 0;

	for (int i = 2; args[i]; i++)
		len += strlen(args[i]) + 1;
	alias->old_cmd = malloc(sizeof(char) * (len + 1));
	my_init(alias->old_cmd, len);
	my_strcpy(alias->old_cmd, args[2]);
	for (int i = 3; args[i]; i++) {
		my_strcat(alias->old_cmd, " ");
		my_strcat(alias->old_cmd, args[i]);
	}
	alias->old_cmd[len] = '\0';
	alias->new_cmd = strdup(args[1]);
	shell->alias = alias_new_size(shell->alias, alias);
}

int my_alias(char **args, shell_t *shell)
{
	if (my_length_tab(args) == 1)
		print_alias(shell, NULL);
	else if (my_length_tab(args) == 2)
		print_alias(shell, args[1]);
	else
		add_new_alias(shell, args);
	return (0);
}