/*
** EPITECH PROJECT, 2018
** display_prompt
** File description:
** display_prompt
*/

#include "42sh.h"

int display_prompt(shell_t *shell)
{
	hashmap_t *user = get_hm_by_key(&(shell->hm_env), "USER");
	hashmap_t *pwd = get_hm_by_key(&(shell->hm_env), "PWD");

	if (user) {
		write(1, "\033[36;1;5m", 9);
		write(1, user->value, my_strlen(user->value));
		write(1, " ~> ", 4);
		write(1, "\033[0m", 4);
	}
	if (pwd) {
		write(1, "\033[36;1;5m", 9);
		write(1, pwd->value, my_strlen(pwd->value));
		write(1, "\033[0m", 4);
	}
	write(1, "\033[36;1;5m", 9);
	write(1, "> ", 2);
	write(1, "\033[0m", 4);
	return (1);
}