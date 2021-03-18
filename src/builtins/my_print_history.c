/*
** EPITECH PROJECT, 2018
** my_print_history
** File description:
** my_print_history
*/

#include "42sh.h"

int my_print_history(char **args __attribute__((__unused__)), \
shell_t *shell __attribute__((__unused__)))
{
	return (print_history());
}