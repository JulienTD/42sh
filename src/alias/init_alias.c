/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** alias init
*/

#include "42sh.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int creat_alias_file(size_t *size)
{
	int fd;

	fd = open(".42shrc", O_CREAT | O_RDWR, S_IRWXO | S_IRWXU | S_IRWXG);
	if (fd == -1) {
		my_puterror(strerror(errno));
		exit (84);
	}
	write(fd, "## Start of .42shrc file ##\n\n", 28);
	write(fd, "## Original alias (you can remove them) ##\n\n", 44);
	write(fd, "alias ls=\"ls --color=auto\"\n", 27);
	write(fd, "alias ll=\"ls -l\"\n", 17);
	write(fd, "alias cls=\"clear\"\n", 18);
	write(fd, "\n## Your alias ##\n\n", 19);
	*size = 28 + 44 + 29 + 17 + 18 + 19;
	close(fd);
	fd = open(".42shrc", O_RDWR);
	return (fd);
}

alias_t *add_alias(char *line, int lindex)
{
	char **equal = my_str_split(line, '=');
	char **temp = my_str_split(equal[0], ' ');
	char **temp2 = my_str_split(line, '\"');
	alias_t *alias = malloc(sizeof(alias_t));

	if (alias == NULL)
		exit (84);
	if (check_error_alias(temp, equal, temp2)) {
		display_invalid_line(line, lindex);
		free_alias_init(temp, equal, alias, temp2);
		return (NULL);
	}
	alias->old_cmd = strdup(temp2[1]);
	alias->new_cmd = strdup(temp[1]);
	free_alias_init(temp, equal, NULL, temp2);
	return (alias);
}

alias_t **find_alias(alias_t **alias, char *line, int lindex)
{
	char **word = my_str_split(line, ' ');
	char *comand[2] = {"alias", NULL};
	int i = 0;
	alias_t *alias_c = NULL;

	while (comand[i]) {
		if (strcmp(comand[i], word[0]) == 0)
			break;
		i++;
	}
	if (check_unknow(word, comand[i], lindex))
		return (alias);
	alias_c = add_alias(line, lindex);
	alias = alias_new_size(alias, alias_c);
	free_2d_tab(word);
	return (alias);
}

alias_t **fill_alias(int fd, size_t size)
{
	alias_t **alias = NULL;
	char **line = NULL;
	char *buffer = malloc(sizeof(char) * (size + 1));

	if (buffer == NULL)
		exit(84);
	if (read(fd, buffer, size) == -1) {
		my_puterror(strerror(errno));
		exit(84);
	}
	buffer[size] = '\0';
	line = my_str_split(buffer, '\n');
	for (int i = 0; line[i]; i++) {
		if (strlen(line[i]) > 0)
			alias = find_alias(alias, line[i], i);
	}
	free_2d_tab(line);
	close(fd);
	return (alias);
}

alias_t **init_alias(void)
{
	struct stat buf;
	size_t size;
	int fd;

	if (stat(".42shrc", &buf) == -1)
		fd = creat_alias_file(&size);
	else {
		fd = open(".42shrc", O_RDWR);
		size = buf.st_size;
	}
	if (fd == -1) {
		my_puterror(strerror(errno));
		exit (84);
	}
	return (fill_alias(fd, size));
}