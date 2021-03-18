/*
** EPITECH PROJECT, 2018
** str_utils
** File description:
** str_utils
*/

#include "42sh.h"

int get_size(char *str, int index)
{
	int size = 0;

	if (index > my_strlen(str) || str == NULL)
		return (-1);
	for (int i = index; str[i] != '\0'; i++) {
		if (str[i] == ':' || str[i] == '\0')
			return (size);
		size++;
	}
	return (size);
}

char *get_path(char *str, int *index)
{
	int size = 0;
	char *word = NULL;
	int j = 0;

	if (str == NULL || index == NULL)
		return (NULL);
	size = get_size(str, *index);
	word = malloc((size + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	for (int i = *index; i < *index + size; i++)
		word[j++] = str[i];
	word[j] = '\0';
	*index = *index + size;
	return (word);
}

int is_alphanumeric(char *str)
{
	if (str == NULL)
		return (0);
	for (int i = 0; str[i] != '\0'; i++) {
		if ((str[i] >= '0' && str[i] <= '9') \
		|| (str[i] >= 'A' && str[i] <= 'Z') \
		|| (str[i] >= 'a' && str[i] <= 'z')) {
		} else {
			return (0);
		}
	}
	return (1);
}

int my_str_contains(char *str, char c)
{
	if (str == NULL)
		return (0);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == c)
			return (1);
	}
	return (0);
}

char *get_str_between(int a, int b, char *str)
{
	char *new_str = NULL;
	int j = 0;

	if (b < a || b - a <= 0)
		return (NULL);
	new_str = malloc((b - a + 1) * sizeof(char));
	for (int i = a; i < b; i++)
		new_str[j++] = str[i];
	new_str[j] = '\0';
	return (new_str);
}