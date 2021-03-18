/*
** EPITECH PROJECT, 2018
** get_length
** File description:
** get_length
*/

#include "42sh.h"

int get_list_length(list_t **head)
{
	list_t *curr = *head;
	int i = 0;

	while (curr) {
		i++;
		curr = curr->next;
	}
	return (i);
}
