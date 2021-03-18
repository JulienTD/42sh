/*
** EPITECH PROJECT, 2018
** ask_text_redirect
** File description:
** ask_text_redirect
*/

#include "42sh.h"

int pipe_str(char *str)
{
	int pipefd[2];
	pid_t cpid = 0;

	pipe(pipefd);
	cpid = fork();
	if (cpid == 0) {
		dup2(pipefd[1], 1);
		close(pipefd[0]);
	} else {
		dup2(pipefd[0], 0);
		close(pipefd[1]);
		my_putstr(str);
		exit(0);
	}
	return (1);
}

static char *concat_redir_right(char *dest, char *src)
{
	char *tmp = malloc((my_strlen(dest) + my_strlen(src) + 2) * \
	sizeof(char));
	int j = 0;

	for (int i = 0; dest && dest[i] != '\0'; i++)
		tmp[j++] = dest[i];
	for (int i = 0; src && src[i] != '\0'; i++)
		tmp[j++] = src[i];
	tmp[j++] = '\n';
	tmp[j++] = '\0';
	free(dest);
	return (tmp);
}

int ask_text_redirect(queue_t *queue)
{
	char *str = NULL;
	char *full_str = NULL;

	while ((str = get_next_line(0)) != NULL) {
		if (my_are_equals(str, queue->redir_left->word))
			break;
		my_putstr("? ");
		full_str = concat_redir_right(full_str, str);
		if (str)
			free(str);
	}
	if (str)
		free(str);
	pipe_str(full_str);
	return (1);
}
