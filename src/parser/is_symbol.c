/*
** EPITECH PROJECT, 2018
** is_symbol
** File description:
** is_symbol
*/

#include "42sh.h"

bool is_symbol(char *str)
{
	if (my_are_equals(str, "&&") == 1 || my_are_equals(str, "||") == 1 \
	|| my_are_equals(str, ";") == 1 || my_are_equals(str, ">") == 1 \
	|| my_are_equals(str, ">>") == 1 || my_are_equals(str, "<") == 1 \
	|| my_are_equals(str, "<<") == 1 || my_are_equals(str, "&") == 1 \
	|| my_are_equals(str, "|") == 1)
		return (true);
	return (false);
}