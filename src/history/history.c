/*
** EPITECH PROJECT, 2018
** history.c
** File description:
** Manage history on the 42sh
*/

#include "42sh.h"
//#include "42sh_structure.h"

int store_in_file(hist_t *end)
{
	FILE *stream = fopen(".42sh_history", "a+");

	if (!stream)
		return (-1);
	fprintf(stream, "  %d  %s   %s\n", end->id, end->hour, end->cmd);
	fclose(stream);
	return (0);
}

int create_new_link(char *cmd, hist_t *head)
{
	hist_t *tmp = head;
	int id = 0;

	store_id(&id, head);
	tmp = malloc(sizeof(hist_t));
	if (!tmp)
		return (-1);
	tmp->id = id + 1;
	tmp->cmd = strdup(cmd);
	tmp->hour = complete_hour();
	tmp->next = NULL;
	store_in_file(tmp);
	return (0);
}

/* JULIEN -> envoyer shell->list */

int store_cmd(char *cmd, hist_t *history)
{
	static int init = 0;

	if (init == 0)
		history = init_linked_list();
	init++;
	if (!cmd)
		return (-1);
	create_new_link(cmd, history);
	return (0);
}
