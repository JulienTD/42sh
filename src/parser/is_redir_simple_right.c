/*
** EPITECH PROJECT, 2018
** is_redir_simple_right
** File description:
** is_redir_simple_right
*/

#include "42sh.h"

bool is_redir_simple_right(char **tab, int *index, queue_t *queue, \
bool pipe)
{
	if (my_are_equals(tab[*index], ">") == 0 \
	|| queue->error_ambi || queue->error_name)
		return (false);
	*index = *index + 1;
	if (tab[*index] == NULL || is_symbol(tab[*index]) == true) {
		queue->error_name = true;
		return (true);
	}
	if (queue->redir_right || \
	(pipe && is_last_pipe(tab, *index) == false)) {
		queue->error_ambi = true;
		return (false);
	}
	queue->redir_right = create_redir();
	queue->redir_right->file = \
	set_str_to(queue->redir_right->file, tab[*index]);
	queue->redir_right->is_double_redir = false;
	return (true);
}