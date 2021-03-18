/*
** EPITECH PROJECT, 2018
** free_queue
** File description:
** free_queue
*/

#include "42sh.h"

int free_queue(queue_t **head)
{
	queue_t *curr = *head;
	queue_t *tmp = NULL;

	for (;curr ;) {
		for (int i = 0; curr->commands && curr->commands[i]; i++)
			free(curr->commands[i]);
		if (curr->commands)
			free(curr->commands);
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	*head = NULL;
	return (0);
}
