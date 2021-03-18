/*
** EPITECH PROJECT, 2018
** free_hashmap
** File description:
** free_hashmap
*/

#include "42sh.h"

int free_hashmap(hashmap_t **head)
{
	hashmap_t *element = NULL;

	while (*head) {
		element = *head;
		if (element->key != NULL)
			free(element->key);
		if (element->value != NULL)
			free(element->value);
		*head = (*head)->next;
		free(element);
	}
	return (1);
}