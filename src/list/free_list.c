/*
** EPITECH PROJECT, 2018
** free_list
** File description:
** free_list
*/

#include "42sh.h"

int free_list(list_t **head)
{
	list_t *element = NULL;

	if (head == NULL || *head == NULL)
		return (1);
	while (*head) {
		element = *head;
		if (element->str != NULL)
			free(element->str);
		*head = (*head)->next;
		if (element)
			free(element);
	}
	return (1);
}