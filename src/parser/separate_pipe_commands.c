/*
** EPITECH PROJECT, 2018
** separate_pipe_commands
** File description:
** separate_pipe_commands
*/

#include "42sh.h"

bool separate_end_pipe(char *cmd, vec_2d_t *vec, int *rows, char **tab)
{
	char *tmp = NULL;

	if (cmd[vec->x + 1] == '\0') {
		tmp = get_str_between(vec->y, vec->x + 1, cmd);
		if (tab == NULL || tmp == NULL)
			return (false);
		tab[*rows] = malloc((my_strlen(tmp) + 1) * sizeof(char));
		tab[*rows] = my_strcpy(tab[*rows], tmp);
		free(tmp);
		vec->y = vec->x + 1;
		*rows = *rows + 1;
		return (true);
	}
	return (false);
}

bool separate_pipe(char *cmd, vec_2d_t *vec, int *rows, char **tab)
{
	char *tmp = NULL;

	if (cmd[vec->x] == '|' && is_in_str(cmd, vec->x, '\"') == false \
	&& is_in_str(cmd, vec->x, '\'') == false) {
		tmp = get_str_between(vec->y, vec->x, cmd);
		if (tab == NULL || tmp == NULL)
			return (false);
		tab[*rows] = malloc((my_strlen(tmp) + 1) * sizeof(char));
		tab[*rows] = my_strcpy(tab[*rows], tmp);
		free(tmp);
		*rows = *rows + 1;
		vec->y = vec->x + 1;
		return (true);
	}
	return (false);
}

static char **init_pipe_tab(char *cmd)
{
	char **t = NULL;
	char **tab = NULL;

	if (cmd == NULL)
		return (NULL);
	t = my_str_split(cmd, '|');
	for (int i = 0; t[i]; i++)
		free(t[i]);
	tab = malloc((my_length_tab(t) + 1) * sizeof(char *));
	return (tab);
}

static char **format_all_pipe(char **tab)
{
	for (int i = 0; tab[i]; i++)
		tab[i] = format_args(tab[i]);
	return (tab);
}

char **separate_pipe_commands(char *cmd)
{
	char **tab = init_pipe_tab(cmd);
	int last_index = 0;
	int rows = 0;
	vec_2d_t vec = {0, 0};

	if (tab == NULL)
		return (NULL);
	for (int i = 0; cmd[i] != '\0'; i++) {
		vec.x = i;
		vec.y = last_index;
		if (separate_end_pipe(cmd, &vec, &rows, tab) == true)
			break;
		separate_pipe(cmd, &vec, &rows, tab);
		if (tab == NULL)
			return (NULL);
		last_index = vec.y;
	}
	tab[rows] = NULL;
	return (format_all_pipe(tab));
}
