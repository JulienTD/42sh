/*
** EPITECH PROJECT, 2018
** get_list_by_id
** File description:
** get_list_by_id
*/

#include "42sh.h"

list_t *get_list_by_id(list_t **head, int id)
{
	int index = 0;
	list_t *curr = *head;

	while (curr) {
		if (index == id)
			return (curr);
		index++;
		curr = curr->next;
	}
	return (NULL);
}
