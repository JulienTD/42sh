/*
** EPITECH PROJECT, 2018
** utilities
** File description:
** utilities
*/

#include "my.h"

int search(char *str, char *str2, int pos)
{
	int i = 0;

	if (pos - 1 >= 0)
		i = pos - 1;
	while (str[i] != str2[pos + 1] && str[i] != '\0')
		i = i + 1;
	return (i);
}
