/*
** EPITECH PROJECT, 2018
** print_hashmap
** File description:
** print_hashmap
*/

#include "42sh.h"

int print_hashmap(hashmap_t **hashmap)
{
	hashmap_t *head = *hashmap;

	while (head) {
		if (head->key)
			write(1, head->key, my_strlen(head->key));
		write(1, "=", 1);
		if (head->value)
			write(1, head->value, my_strlen(head->value));
		write(1, "\n", 1);
		head = head->next;
	}
	return (1);
}