/*
** EPITECH PROJECT, 2018
** apply_redir
** File description:
** apply_redir
*/

#include "42sh.h"

static int apply_right_redir(queue_t *queue, bool pipe)
{
	int fd = 0;

	if (queue->redir_right) {
		if (pipe == true && queue->last_cmd == false)
			return (1);
		if (queue->redir_right->is_double_redir == false)
			fd = open(queue->redir_right->file, O_RDWR | \
			O_CREAT | O_TRUNC, 0644);
		else
			fd = open(queue->redir_right->file, O_RDWR | \
			O_CREAT | O_APPEND, 0644);
		if (fd < 0) {
			my_putstr(queue->redir_right->file);
			my_putstr(": No such file or directory.\n");
			return (1);
		}
		dup2(fd, 1);
	}
	return (0);
}

static int apply_left_simple_redir(queue_t *queue, bool pipe)
{
	int fd = 0;

	if (queue->redir_left && \
	queue->redir_left->is_double_redir == false) {
		if (pipe == true && queue->first_cmd == false)
			return (1);
		fd = open(queue->redir_left->file, O_RDWR, 0644);
		if (fd < 0) {
			my_putstr(queue->redir_left->file);
			my_putstr(": No such file or directory.\n");
			return (-1);
		}
		dup2(fd, 0);
	}
	return (0);
}

static int apply_left_double_redir(queue_t *queue, bool pipe)
{
	if (queue->redir_left && \
	queue->redir_left->is_double_redir == true) {
		if (pipe == true && queue->first_cmd == false)
			return (1);
		my_putstr("? ");
		ask_text_redirect(queue);
	}
	return (0);
}

int apply_redir(queue_t *queue, bool pipe)
{
	apply_right_redir(queue, pipe);
	apply_left_simple_redir(queue, pipe);
	apply_left_double_redir(queue, pipe);
	return (0);
}