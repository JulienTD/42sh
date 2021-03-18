/*
** EPITECH PROJECT, 2018
** my_echo
** File description:
** my_echo
*/

#include "42sh.h"

int my_echo(char **args, __attribute__((__unused__)) shell_t *shell, \
bool pipe, int tmp)
{
	for (int i = 1; args[i]; i++) {
		write(1, args[i], my_strlen(args[i]));
		if (args[i + 1] != NULL)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
	if (pipe == false) {
		dup2(tmp, 1);
		close(tmp);
	}
	return (0);
}