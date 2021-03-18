/*
** EPITECH PROJECT, 2018
** list_to_2d
** File description:
** list_to_2d
*/

#include "42sh.h"

char **list_to_2d(list_t **head)
{
	char **flags = malloc((get_list_length(head)) * sizeof(char *));
	list_t *curr = *head;
	int tab_id = 0;

	while (curr) {
		flags[tab_id] = malloc((my_strlen(curr->str) + 1) \
		* sizeof(char));
		my_strcpy(flags[tab_id], curr->str);
		tab_id++;
		curr = curr->next;
	}
	return (flags);
}