/*
** EPITECH PROJECT, 2018
** clear_str
** File description:
** clear_str
*/

#include "42sh.h"

static char *remove_last_space(char *src)
{
	for (int i = 0; i < my_strlen(src); i++)
		if (src[i] == '\t')
			src[i] = ' ';
	for (int i = my_strlen(src) - 1; i >= 0; i--) {
		if (src[i] != ' ' && src[i] != '\t') {
			src[i + 1] = '\0';
			return (format_raw_commands(src));
		}
	}
	return (format_raw_commands(src));
}

char *clear_str(char *src)
{
	int length = my_strlen(src);
	char *dest = malloc((length + 1) * sizeof(char));
	int j = 0;
	int letter = 0;

	for (int i = 0; i < length; i++) {
		if (letter == 0 && (src[i] == ' ' || src[i] == '\t'))
			continue;
		if (src[i] != ' ' && src[i] != '\t')
			letter = 1;
		if ((src[i] == ' ' || src[i] == '\t') && \
		((i + 1 < length && \
		(src[i + 1] == ' ' || src[i + 1] == '\t'))))
			continue;
		dest[j++] = src[i];
	}
	dest[j] = '\0';
	return (remove_last_space(dest));
}