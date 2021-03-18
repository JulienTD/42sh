/*
** EPITECH PROJECT, 2018
** args_utils
** File description:
** args_utils
*/

#include "42sh.h"

char *get_arg(char *str, int *index)
{
	int size = 0;
	char *word = NULL;
	int j = 0;

	if (str == NULL)
		return (NULL);
	size = l_until_space(str, *index);
	word = malloc((size + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	for (int i = *index; i < *index + size; i++)
		word[j++] = str[i];
	word[j] = '\0';
	*index = *index + size;
	return (word);
}

int add_args_to_list(list_t **head, char *str)
{
	if (str == NULL)
		return (0);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '|' || str[i] == ';')
			break;
		if (str[i] == ' ' || str[i] == '\t')
			continue;
		add_str(head, get_arg(str, &i));
	}
	return (1);
}

int l_until_space(char *str, int index)
{
	int letters = 0;

	if (str == NULL)
		return (0);
	if (index > my_strlen(str))
		return (-1);
	for (int i = index; str[i] != '\0'; i++) {
		if (str[i] == ' ' || str[i] == '\0' || str[i] == '|' \
		|| str[i] == ';')
			return (letters);
		letters++;
	}
	return (letters);
}