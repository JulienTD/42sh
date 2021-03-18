/*
** EPITECH PROJECT, 2018
** get_hm_length
** File description:
** get_hm_length
*/

#include "42sh.h"

int get_hm_length(hashmap_t **head)
{
	hashmap_t *curr = *head;
	int i = 0;

	while (curr) {
		i++;
		curr = curr->next;
	}
	return (i);
}