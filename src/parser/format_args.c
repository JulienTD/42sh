/*
** EPITECH PROJECT, 2018
** format_args
** File description:
** format_args
*/

#include "42sh.h"

static char *remove_char_at(char *str, int index)
{
	int size = my_strlen(str);
	char *new_str = malloc(size * sizeof(char));
	int j = 0;

	for (int i = 0; i < size + 1; i++) {
		if (i == index)
			continue;
		new_str[j++] = str[i];
	}
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

char *format_args(char *str)
{
	char *new_str = NULL;

	if (str[0] == '\"' || str[0] == '\'') {
		new_str = get_str_between(1, my_strlen(str) - 1, str);
		if (new_str == NULL)
			return (NULL);
		str = set_str_to(str, new_str);

	}
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '\\' && (str[i + 1] == '\'' || \
		str[i + 1] == '\"'))
			str = remove_char_at(str, i);
	}
	return (str);
}