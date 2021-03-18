/*
** EPITECH PROJECT, 2018
** my_exit
** File description:
** my_exit
*/

#include "42sh.h"

void my_exit_last_return(shell_t __attribute__((__unused__)) *shell)
{
	write(1, "exit\n", 5);
	exit(0);
}

int my_exit_utils(char **args)
{
	int value = my_is_nbr(args[1]);

	if (value == 1) {
		value = my_get_nbr(args[1]);
	} else if (value == 0) {
		my_putstr("exit: Expression Syntax.\n");
		return (-1);
	} else {
		my_putstr("exit: Badly formed number.\n");
		return (-1);
	}
	return (value);
}

int my_exit(char **args, shell_t *shell)
{
	int value = 0;
	int length = my_length_tab(args);

	if (length == 1) {
		my_exit_last_return(shell);
	} else if (length > 2) {
		my_putstr("exit: Expression Syntax.\n");
		return (1);
	}
	value = my_exit_utils(args);
	if (value == -1)
		return (1);
	write(1, "exit\n", 5);
	exit(value % 256);
}