/*
** EPITECH PROJECT, 2018
** create_redir
** File description:
** create_redir
*/

#include "42sh.h"

redir_t *create_redir(void)
{
	redir_t *redir = malloc(sizeof(redir_t));

	if (redir == NULL)
		return (NULL);
	redir->file = NULL;
	redir->word = NULL;
	redir->is_double_redir = false;
	return (redir);
}