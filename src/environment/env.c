/*
** EPITECH PROJECT, 2018
** env
** File description:
** env
*/

#include "42sh.h"

int init_path(shell_t *shell)
{
	hashmap_t *path = NULL;

	if (shell == NULL)
		return (0);
	free_list(&(shell->path));
	path = get_hm_by_key(&(shell->hm_env), "PATH");
	if (path)
		add_path_to_list(&(shell->path), path->value);
	return (1);
}

int init_env_struct(shell_t *shell)
{
	if (shell == NULL)
		return (0);
	shell->hm_env = NULL;
	shell->path = NULL;
	shell->to_return = 0;
	return (1);
}

void add_path_to_list(list_t **head, char *str)
{
	char **tab = my_str_split(str, ':');

	if (tab == NULL)
		return;
	for (int i = 0; tab[i] != NULL; i++) {
		add_str(head, tab[i]);
		free(tab[i]);
	}
	free(tab);
}

int reload(shell_t *shell)
{
	char *dir_path = NULL;

	if (shell == NULL)
		return (0);
	dir_path = get_dir();
	write_env("PWD", dir_path, shell);
	free(dir_path);
	init_path(shell);
	return (1);
}

int free_env(shell_t *shell)
{
	if (shell == NULL)
		return (0);
	if (shell->hm_env != NULL)
		free_hashmap(&(shell->hm_env));
	if (shell->path != NULL)
		free_list(&(shell->path));
	free(shell);
	return (1);
}