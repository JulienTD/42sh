/*
** EPITECH PROJECT, 2018
** split_line.c
** File description:
** Function which permit to split the line
*/

#include "42sh.h"

static int len_cmd(char *str, int *index)
{
	int len = 0;

	for ( ; str[*index] != ' ' ; *index += 1);
	*index += 1;
	for ( ; str[*index] != '\0' ; *index += 1, len++);
	return (len);
}

static int len_id(char *str, int *index)
{
	int len = 0;

	for ( ; str[*index] != ' ' ;  *index += 1);
	*index += 1;
	len = *index;
	return (len);
}

static int alloc_str(char **line, char *str)
{
	int index = 0;

	if (!str || !line) {
		write(2, "Error: split_line\n", 18);
		exit(84);
	}
	line[0] = malloc(sizeof(char) * (len_id(str, &index) + 1));
	line[1] = malloc(sizeof(char) * 6);
	line[2] = malloc(sizeof(char) * (len_cmd(str, &index) + 1));
	return (0);
}

char **split_line(char *str)
{
	char **split = malloc(sizeof(char *) * 3);
	int i = 0;
	int j = 0;

	alloc_str(split, str);
	for ( ; str[j] != ' ' ; i++, j++)
		split[0][i] = str[j];
	split[0][i] = '\0';
	i = 0;
	j++;
	for ( ; str[j] != ' ' ; i++, j++)
		split[1][i] = str[j];
	split[1][i] = '\0';
	i = 0;
	j++;
	for ( ; str[j] != '\0' ; i++, j++)
		split[2][i] = str[j];
	split[2][i] = '\0';
	return (split);
}
