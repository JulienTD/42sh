/*
** EPITECH PROJECT, 2018
** print_list
** File description:
** print_list
*/

#include "42sh.h"

int print_list(list_t **list)
{
	list_t *head = *list;

	while (head) {
		write(1, head->str, my_strlen(head->str));
		write(1, "\n", 2);
		head = head->next;
	}
	return (1);
}