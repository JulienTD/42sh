/*
** EPITECH PROJECT, 2018
** my_length_tab
** File description:
** my_length_tab
*/

#include "42sh.h"

int my_length_tab(char **tab)
{
	int length = 0;

	while (tab[length])
		length++;
	return (length);
}