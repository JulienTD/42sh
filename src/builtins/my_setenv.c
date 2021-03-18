/*
** EPITECH PROJECT, 2018
** my_setenv
** File description:
** my_setenv
*/

#include "42sh.h"

static int rewrite_env(hashmap_t *curr, char *new_value)
{
	free(curr->value);
	if (new_value == NULL) {
		curr->value = NULL;
	} else {
		curr->value = malloc((my_strlen(new_value) + 1) * \
		sizeof(char));
		my_strcpy(curr->value, new_value);
	}
	return (1);
}

int write_env(char *key, char *value, shell_t *shell)
{
	hashmap_t *curr = get_hm_by_key(&(shell->hm_env), key);

	if (curr == NULL) {
		if (value == NULL)
			add_keyvalue(&(shell->hm_env), key, NULL);
		else
			add_keyvalue(&(shell->hm_env), key, value);
	} else {
		rewrite_env(curr, value);
	}
	return (1);
}

int my_setenv(char **args, shell_t *shell)
{
	int ac = my_length_tab(args);

	if (check_error(args, shell))
		return (1);
	if (ac >= 3 && args[2])
		write_env(args[1], args[2], shell);
	else
		write_env(args[1], NULL, shell);
	init_path(shell);
	return (0);
}