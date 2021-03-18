/*
** EPITECH PROJECT, 2018
** my_strlen_to
** File description:
** my_strlen_to
*/

#include "42sh.h"

int my_strlen_to(char *str, int i, char c)
{
	int j = 0;

	while (str[i] != '\0') {
		if (i > 0 && str[i] == '\"' && str[i - 1] != '\\')
			return (j);
		if (str[i] == c)
			return (j);
		j++;
		i++;
	}
	return (j);
}