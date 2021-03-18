/*
** EPITECH PROJECT, 2018
** env_builtins
** File description:
** env_builtins
*/

#include "42sh.h"

int my_is_alpha(char c)
{
	if (c >= 'A' || c <= 'Z')
		return (1);
	if (c >= 'a' || c <= 'z')
		return (1);
	return (0);
}

int check_error(char **args, shell_t *shell)
{
	int length = my_length_tab(args);

	if (length > 3) {
		my_putstr(SETENV_ERROR_TOO_MANY_ARGS);
		return (1);
	}
	if (length == 1) {
		print_hashmap(&(shell->hm_env));
		return (1);
	}
	if (my_is_alpha(args[1][0]) == 0) {
		my_putstr(SETENV_ERROR_LETTER);
		return (1);
	}
	if (is_alphanumeric(args[1]) == 0) {
		my_putstr(SETENV_ERROR_ALPHA);
		return (1);
	}
	return (0);
}

int my_env(char **args, shell_t *shell)
{
	int size = my_length_tab(args);

	if (size == 1) {
		print_hashmap(&(shell->hm_env));
		return (0);
	}
	return (1);
}