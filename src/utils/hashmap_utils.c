/*
** EPITECH PROJECT, 2018
** hashmap_utils
** File description:
** hashmap_utils
*/

#include "42sh.h"

int get_key_size(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0') {
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (i);
}

char *get_key(char *str)
{
	int key_size = 0;
	char *key = NULL;
	int i = 0;

	if (str == NULL)
		return (NULL);
	key_size = get_key_size(str);
	key = malloc((key_size + 1) * sizeof(char));
	if (key == NULL)
		return (NULL);
	while (i < key_size) {
		key[i] = str[i];
		i++;
	}
	key[i] = '\0';
	return (key);
}

char *get_value(char *str)
{
	char *value = NULL;
	int value_size = 0;
	int j = 0;

	if (str == NULL)
		return (NULL);
	value_size = my_strlen(str) - get_key_size(str);
	value = malloc((value_size) * sizeof(char));
	if (value == NULL)
		return (NULL);
	for (int i = get_key_size(str) + 1; str[i] != '\0'; i++)
		value[j++] = str[i];
	value[j] = '\0';
	return (value);
}