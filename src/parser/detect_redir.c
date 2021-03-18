/*
** EPITECH PROJECT, 2018
** detect_redir
** File description:
** detect_redir
*/

#include "42sh.h"

bool is_last_pipe(char **tab, int index)
{
	int nbr_pipe = 0;
	int curr_pipe = 0;

	for (int i = 0; tab[i]; i++)
		if (my_are_equals(tab[i], "|"))
			nbr_pipe++;

	for (int i = 0; tab[i]; i++) {
		if (i == index && curr_pipe == nbr_pipe)
			return (true);
		else if (i == index && curr_pipe != nbr_pipe)
			return (false);
		if (my_are_equals(tab[i], "|"))
			curr_pipe++;
	}
	return (true);
}

bool is_first_pipe(char **tab, int index)
{
	int nbr_pipe = 0;
	int curr_pipe = 0;

	for (int i = 0; tab[i]; i++)
		if (my_are_equals(tab[i], "|"))
			nbr_pipe++;
	for (int i = 0; tab[i]; i++) {
		if (i == index && curr_pipe == 0)
			return (true);
		else if (i == index && curr_pipe != 0)
			return (false);
		if (my_are_equals(tab[i], "|"))
			curr_pipe++;
	}
	return (true);
}

char *my_concat(char *new_str, char *tmp, int *j)
{
	for (int i = 0; i < my_strlen(tmp); i++) {
		new_str[*j] = tmp[i];
		*j = *j + 1;
	}
	new_str[*j] = ' ';
	*j = *j + 1;
	new_str[*j] = '\0';
	return (new_str);
}

static bool detect_redir2(char **tab, int *i, queue_t *queue, bool pipe_cmd)
{
	if (is_redir_double_right(tab, i, queue, pipe_cmd) == true)
		return (true);
	if (is_redir_simple_right(tab, i, queue, pipe_cmd) == true)
		return (true);
	if (is_redir_double_left(tab, i, queue, pipe_cmd) == true)
		return (true);
	if (is_redir_simple_left(tab, i, queue, pipe_cmd) == true)
		return (true);
	return (false);
}

char *detect_redir(char *cmd, queue_t *queue, bool pipe_cmd)
{
	char **tab = separate_arguments(cmd, false);
	char *new_str = my_init_tab(my_strlen(cmd) + 2);
	int index = 0;
	int size = my_length_tab(tab);

	for (int i = 0; i < size; i++) {
		if (queue->error_ambi || queue->error_name)
			break;
		if (detect_redir2(tab, &i, queue, pipe_cmd))
			continue;
		if (queue->error_ambi || queue->error_name)
			break;
		if (i < size)
			new_str = my_concat(new_str, tab[i], &index);
	}
	for (int i = 0; tab[i]; i++)
		free(tab[i]);
	return (clear_str(new_str));
}