/*
** EPITECH PROJECT, 2018
** separate_commands
** File description:
** separate_commands
*/

#include "42sh.h"

bool separate_end_cmd(char *cmd, vec_2d_t *vec, queue_t **queue)
{
	char *tmp = NULL;

	if (cmd[vec->x + 1] == '\0') {
		tmp = get_str_between(vec->y, vec->x + 1, cmd);
		if (tmp == NULL)
			return (NULL);
		add_queue(queue, tmp, false, false);
		free(tmp);
		vec->y = vec->x + 1;
		return (true);
	}
	return (false);
}

bool separate_semicolon_cmd(char *cmd, vec_2d_t *vec, queue_t **queue)
{
	char *tmp = NULL;

	if (cmd[vec->x] == ';' && is_in_str(cmd, vec->x, '\"') == false \
	&& is_in_str(cmd, vec->x, '\'') == false) {
		tmp = get_str_between(vec->y, vec->x, cmd);
		if (tmp == NULL)
			return (NULL);
		tmp = clear_str(tmp);
		if (my_strlen(tmp) <= 0)
			return (true);
		if (check_wrong_raw_command(tmp))
			return (true);
		add_queue(queue, tmp, false, false);
		free(tmp);
		vec->y = vec->x + 1;
		return (true);
	}
	return (false);
}

bool separate_and_cmd(char *cmd, vec_2d_t *vec, queue_t **queue)
{
	char *tmp = NULL;

	if (cmd[vec->x] == '&' && cmd[vec->x + 1] == '&' && \
	is_in_str(cmd, vec->x, '\"') == false && \
	is_in_str(cmd, vec->x, '\'') == false) {
		tmp = get_str_between(vec->y, vec->x, cmd);
		if (tmp == NULL)
			return (NULL);
		add_queue(queue, tmp, true, false);
		free(tmp);
		vec->y = vec->x + 2;
		return (true);
	}
	return (false);
}

bool separate_or_cmd(char *cmd, vec_2d_t *vec, queue_t **queue)
{
	char *tmp = NULL;

	if (cmd[vec->x] == '|' && cmd[vec->x + 1] == '|' && \
	is_in_str(cmd, vec->x, '\"') == false && \
	is_in_str(cmd, vec->x, '\'') == false) {
		tmp = get_str_between(vec->y, vec->x, cmd);
		if (tmp == NULL)
			return (NULL);
		add_queue(queue, tmp, false, true);
		free(tmp);
		vec->y = vec->x + 2;
		return (true);
	}
	return (false);
}

int separate_commands(char *cmd, queue_t **queue)
{
	int last_index = 0;
	vec_2d_t vec = {0, 0};

	for (int i = 0; cmd[i] != '\0'; i++) {
		vec.x = i;
		vec.y = last_index;
		separate_semicolon_cmd(cmd, &vec, queue);
		separate_and_cmd(cmd, &vec, queue);
		separate_or_cmd(cmd, &vec, queue);
		if (separate_end_cmd(cmd, &vec, queue) == true)
			break;
		last_index = vec.y;
	}
	return (0);
}