/*
** EPITECH PROJECT, 2018
** add_str
** File description:
** add_str
*/

#include "42sh.h"

int add_str(list_t **head, char *str)
{
	list_t *element = malloc(sizeof(list_t));
	list_t *curr = *head;

	if (element == NULL || str == NULL)
		return (0);
	element->next = NULL;
	element->str = NULL;
	element->str = set_str_to(element->str, str);
	if (*head == NULL) {
		*head = element;
	} else {
		while (curr->next)
			curr = curr->next;
		curr->next = element;
	}
	return (1);
}