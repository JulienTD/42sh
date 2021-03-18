/*
** EPITECH PROJECT, 2018
** format_raw_command
** File description:
** format_raw_command
*/

#include "42sh.h"

static char *my_add_space(char *raw, int index, \
__attribute__((__unused__)) int length)
{
	char *tmp = malloc((my_strlen(raw) + 2) * sizeof(char));
	int j = 0;

	if (tmp == NULL)
		return (NULL);
	for (int i = 0; i < index; i++)
		tmp[j++] = raw[i];
	tmp[j++] = ' ';
	for (int i = index; i < my_strlen(raw); i++)
		tmp[j++] = raw[i];
	tmp[j] = '\0';
	if (raw)
		free(raw);
	return (tmp);
}

static char *check_add_space(char *raw, int i, int length)
{
	if (i + 1 < length && raw[i + 1] != ' ') {
		if ((raw[i] == '|' && raw[i + 1] == '|') || \
		(raw[i] == '&' && raw[i + 1] == '&'))
			return (raw);
		if ((raw[i] == '>' && raw[i + 1] == '>') || \
		(raw[i] == '<' && raw[i + 1] == '<'))
			return (raw);
		raw = my_add_space(raw, i + 1, length);
	}
	return (raw);
}

static char *format_raw_commands2(char *raw, int i)
{
	int length = my_strlen(raw);

	if (i >= 1 && raw[i - 1] != ' ') {
		if ((raw[i] == '<' && raw[i - 1] == '<') || (raw[i] == '>' \
		&& raw[i - 1] == '>'))
			return (check_add_space(raw, i, length));
		if ((raw[i] == '|' && raw[i - 1] == '|') || (raw[i] == '&' \
		&& raw[i - 1] == '&'))
			return (check_add_space(raw, i, length));
		raw = my_add_space(raw, i, length);
	} else {
		raw = check_add_space(raw, i, length);
	}
	return (raw);
}

char *format_raw_commands(char *raw)
{
	if (raw == NULL)
		return (NULL);
	for (int i = 0; raw[i] != '\0'; i++) {
		if ((raw[i] == '<' || raw[i] == '>' || raw[i] == '|' || \
		raw[i] == '&' || raw[i] == ';') && \
		is_in_str(raw, i, '\"') == false && \
		is_in_str(raw, i, '\'') == false) {
			raw = format_raw_commands2(raw, i);
		}
		if (raw == NULL)
			return (NULL);
	}
	return (raw);
}
