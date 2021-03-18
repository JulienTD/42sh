/*
** EPITECH PROJECT, 2018
** add_queue
** File description:
** add_queue
*/

#include "42sh.h"

int add_queue(queue_t **head, char *cmd, bool cond_and, bool cond_or)
{
	queue_t *curr = *head;
	queue_t *element = init_queue(cmd);

	if (cmd == NULL || element == NULL)
		return (0);
	element->condition_and = cond_and;
	element->condition_or = cond_or;
	if (*head == NULL) {
		*head = element;
	} else {
		while (curr->next)
			curr = curr->next;
		curr->next = element;
	}
	return (1);
}
