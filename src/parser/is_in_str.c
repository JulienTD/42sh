/*
** EPITECH PROJECT, 2018
** is_in_str
** File description:
** is_in_str
*/

#include "42sh.h"

bool is_in_str(char *str, int index, char c)
{
	bool status = false;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == c && i == 0)
			status = (status == true) ? false : true;
		else if (str[i] == c && str[i - 1] != '\\')
			status = (status == true) ? false : true;
		if (i == index)
			return (status);
	}
	return (status);
}