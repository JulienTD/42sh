/*
** EPITECH PROJECT, 2018
** init_linked_list
** File description:
** Function which permit to init the minked list
*/

#include "42sh.h"
#include "get_next_line.h"

void store_id(int *id, __attribute__((__unused__)) hist_t *head)
{
	int fd = open(HISTORY_FILE, O_CREAT | O_RDWR, 00666);

	if (fd == -1)
		exit(84);
	while (get_next_line(fd) != NULL)
		*id += 1;
	close(fd);
}

int manage_line(char *line, hist_t *hist)
{
	char **parsing = split_line(line);

	if (!parsing)
		exit(84);
	hist->id = atoi(parsing[0]);
	hist->hour = strdup(parsing[1]);
	hist->cmd = strdup(parsing[2]);
	return (0);
}

int store_history(hist_t *hist)
{
	int fd = open(HISTORY_FILE, O_CREAT | O_RDWR, 00666);
	char *line = NULL;

	if (fd == -1) {
		write(2, "Error: can't read the history file !\n", 37);
		exit(84);
	}
	while (line != NULL) {
		line = get_next_line(fd);
		manage_line(line, hist);
	}
	return (0);
}

hist_t *init_linked_list(void)
{
	hist_t *hist = malloc(sizeof(hist_t));

	if (!hist)
		return (NULL);
	hist->cmd = NULL;
	hist->id = 0;
	hist->hour = NULL;
	hist->next = NULL;
	store_history(hist);
	return (hist);
}
