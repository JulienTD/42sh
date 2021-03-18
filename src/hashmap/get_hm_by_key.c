/*
** EPITECH PROJECT, 2018
** get_element_by_key
** File description:
** get_element_by_key
*/

#include "42sh.h"

hashmap_t *get_hm_by_key(hashmap_t **head, char *key)
{
	hashmap_t *curr = NULL;

	if (key == NULL)
		return (NULL);
	curr = *head;
	while (curr) {
		if (my_are_equals(curr->key, key) == 1)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}