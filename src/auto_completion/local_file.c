/*
** EPITECH PROJECT, 2018
** local_files
** File description:
** Comparison with local files
*/

#include "42sh.h"

char *auto_complit(shell_t *shell, char *str)
{
	char *name = NULL;
	list_t *path = shell->path;

	name = compare_file(".", str);
	if (name)
		return (name);
	while (path) {
		name = compare_file(path, str);
		path = path->next;
		if (name)
			return (name);
	}
	return (NULL);
}

char *compare_file(char *path, char *str)
{
	DIR *dir;
	struct dirent *entry;
	char **names = malloc(sizeof(char *));
	int tot = 0;

	dir = opendir(path);
	entry = readdir(dir);
	while (entry > 1) {
		if (entry->d_name[0] != '.') {
			realloc(names, sizeof(char *));
			strcpy(names[tot], entry->d_name);
			tot++;
		}
		entry = readdir(dir);
	}
	closedir(dir);
	return (compare_names(names, str, tot));
}

char *compare_names(char **names, char *str, int tot)
{
	char *name = NULL;
	int nbr = 0;

	for (int i = 0 ; i < tot ; i++) {
		if (strncmp(str, names[i], my_strlen(str))) {
			strcpy(name, names[i]);
			nbr++;
		}
	}
	if (nbr == 1)
		return (name);
	else
		return (NULL);
}