/*
** EPITECH PROJECT, 2018
** get_hm_by_id
** File description:
** get_hm_by_id
*/

#include "42sh.h"

hashmap_t *get_hm_by_id(hashmap_t **head, int id)
{
	int index = 0;
	hashmap_t *curr = *head;

	while (curr) {
		if (index == id)
			return (curr);
		index++;
		curr = curr->next;
	}
	return (NULL);
}