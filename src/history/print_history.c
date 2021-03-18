/*
** EPITECH PROJECT, 2018
** print_history.c
** File description:
** Function which permit to print the history
*/

#include "get_next_line.h"
#include "42sh.h"

int print_history(void)
{
	int fd = open(HISTORY_FILE, S_IROTH);
	char *line = NULL;

	if (fd == -1)
		return (1);
	while ((line = get_next_line(fd)) != NULL) {
		write(1, line, strlen(line));
		write(1, "\n", 1);
	}
	close(fd);
	return (0);
}
