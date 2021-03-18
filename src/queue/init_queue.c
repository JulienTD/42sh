/*
** EPITECH PROJECT, 2018
** init_queue
** File description:
** init_queue
*/

#include "42sh.h"

queue_t *init_queue(char *str)
{
	queue_t *element = malloc(sizeof(queue_t));

	if (element == NULL || str == NULL)
		return (NULL);
	str = clear_str(str);
	element->commands = NULL;
	element->contain_pipe = 0;
	element->condition_and = false;
	element->condition_or = false;
	element->next = NULL;
	element->cmd = NULL;
	element->error_ambi = false;
	element->error_name = false;
	element->redir_left = NULL;
	element->redir_right = NULL;
	element->first_cmd = true;
	element->last_cmd = false;
	element->cmd = set_str_to(element->cmd, str);
	return (element);
}