/*
** EPITECH PROJECT, 2018
** core
** File description:
** core
*/

#include "my.h"

int *positions(char *str, char *str2, int *pos)
{
	while (str2[pos[0]] != '*' && str2[pos[0]] != '\0') {
		if (str2[pos[0]] == str[pos[1]] && str2[pos[0]] != '\0') {
			pos[1] = pos[1] + 1;
			pos[0] = pos[0] + 1;
		} else if (str2[pos[0]] != str[pos[1]] && str2[pos[0]] != '\0\
')
			return (NULL);
		else
			break;
	}
	return (pos);
}

int match(char *str, char *str2)
{
	int *pos = malloc(sizeof(int) * 2);

	pos[0] = 0;
	pos[1] = 0;
	while (str2[pos[0]] != '\0') {
		pos = positions(str, str2, pos);
		if (pos == NULL)
			return (84);
		if (str2[pos[0]] == '\0')
			return (0);
		pos[1] = search(str, str2, pos[0]);
		pos[0] = pos[0] + 1;
	}
	return (0);
}
