/*
** EPITECH PROJECT, 2018
** is_redir_double_left
** File description:
** is_redir_double_left
*/

#include "42sh.h"

bool is_redir_double_left(char **tab, int *index, queue_t *queue, \
bool pipe)
{
	if (my_are_equals(tab[*index], "<<") == 0 \
	|| queue->error_ambi || queue->error_name)
		return (false);
	*index = *index + 1;
	if (tab[*index] == NULL || is_symbol(tab[*index]) == true) {
		queue->error_name = true;
		return (true);
	}
	if (queue->redir_left \
	|| (pipe && is_first_pipe(tab, *index) == false)) {
		queue->error_ambi = true;
		return (false);
	}
	queue->redir_left = create_redir();
	queue->redir_left->word = \
	set_str_to(queue->redir_left->word, tab[*index]);
	queue->redir_left->is_double_redir = true;
	return (true);
}