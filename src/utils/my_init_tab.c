/*
** EPITECH PROJECT, 2018
** my_init_tab
** File description:
** my_init_tab
*/

#include "42sh.h"

char *my_init_tab(int length)
{
	char *tab = malloc(length * sizeof(char));

	if (tab == NULL)
		return (NULL);
	for (int i = 0; i < length; i++)
		tab[i] = '\0';
	return (tab);
}
