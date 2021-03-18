/*
** EPITECH PROJECT, 2018
** my_unsetenv
** File description:
** my_unsetenv
*/

#include "42sh.h"

int my_unsetenv(char **args, shell_t *shell)
{
	int ac = my_length_tab(args);

	if (ac == 1) {
		my_putstr("unsetenv: Too few arguments.\n");
		return (1);
	}
	if (my_strlen(args[1]) == 1 && args[1][0] == '*') {
		free_hashmap(&(shell->hm_env));
		init_path(shell);
		return (0);
	}
	for (int i = 1; i < ac; i++)
		delete_hm_by_key(&(shell->hm_env), args[i]);
	init_path(shell);
	return (0);
}