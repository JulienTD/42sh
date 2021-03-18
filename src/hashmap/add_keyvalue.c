/*
** EPITECH PROJECT, 2018
** add_keyvalue
** File description:
** add_keyvalue
*/

#include "42sh.h"

int add_keyvalue(hashmap_t **head, char *key, char *value)
{
	hashmap_t *element = init_hashmap_element();
	hashmap_t *curr = *head;

	if (element == NULL)
		return (0);
	element->key = set_str_to(element->key, key);
	element->value = set_str_to(element->value, value);
	if (*head == NULL) {
		*head = element;
	} else {
		while (curr->next)
			curr = curr->next;
		element->id = curr->id + 1;
		curr->next = element;
	}
	return (1);
}

