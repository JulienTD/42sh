/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** alias error display
*/

#include "42sh.h"

bool check_unknow(char **word, char *cmd, int lindex)
{
	if (strlen(word[0]) < 2 && word[0][0] != '#') {
		display_unknow(word[0], lindex);
		free_2d_tab(word);
		return (true);
	} else if (word[0][0] == '#') {
		free_2d_tab(word);
		return (true);
	}
	if (cmd == NULL) {
		display_unknow(word[0], lindex);
		free_2d_tab(word);
		return (true);
	}
	return (false);
}

bool check_error_alias(char **temp, char **equal, char **temp2)
{
	if (my_length_tab(equal) < 2)
		return (true);
	if (my_length_tab(temp) != 2 && my_length_tab(temp) != 3)
		return (true);
	if (my_length_tab(temp2) < 3 || strlen(temp2[1]) < 1)
		return (true);
	if (strlen(equal[1]) < 3 || strlen(temp[1]) < 1)
		return (true);
	return (false);
}

void free_alias_init(char **tmp, char **eq, alias_t *alias, char **tmp2)
{
	free_2d_tab(tmp);
	free_2d_tab(tmp2);
	free_2d_tab(eq);
	if (alias != NULL)
		free(alias);
}

void display_invalid_line(char *line, int lindex)
{
	my_putstr("Line ");
	my_put_nbr(lindex + 1);
	my_putstr(": \"");
	my_putstr(line);
	my_putchar('\"');
	my_putstr(" : Invalid line\n");
}

void display_unknow(char *cmd, int lindex)
{
	my_putstr("Line ");
	my_put_nbr(lindex + 1);
	my_putstr(": \"");
	my_putstr(cmd);
	my_putchar('\"');
	my_putstr(": Unknow command\n");
}