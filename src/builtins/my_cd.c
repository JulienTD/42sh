/*
** EPITECH PROJECT, 2018
** cd_builtins
** File description:
** cd_builtins
*/

#include "42sh.h"

static int check_cd_flag1(char *str, shell_t *shell)
{
	hashmap_t *home = NULL;
	char *path = NULL;

	if (my_strlen(str) == 1 && str[0] == '~') {
		home = get_hm_by_key(&(shell->hm_env), "HOME");
		if (home != NULL) {
			path = get_dir();
			write_env("OLDPWD", path, shell);
			chdir(home->value);
			path = get_dir();
			write_env("PWD", path, shell);
			free(path);
			return (0);
		} else {
			write(1, "No $home variable set.\n", 23);
			return (1);
		}
	}
	return (2);
}

static int check_cd_flag2(char *str, shell_t *shell)
{
	hashmap_t *old = NULL;
	char *temp = NULL;
	char *path = NULL;

	if (my_strlen(str) == 1 && str[0] == '-') {
		old = get_hm_by_key(&(shell->hm_env), "OLDPWD");
		if (old == NULL) {
			my_putstr(": No such file or directory.\n");
			return (1);
		}
		temp = set_str_to(temp, old->value);
		path = get_dir();
		write_env("OLDPWD", path, shell);
		write_env("PWD", temp, shell);
		chdir(temp);
		free(temp);
		free(path);
		return (0);
	}
	return (2);
}

static int my_cd_status(char **args, shell_t *shell)
{
	int status = 0;

	errno = 0;
	status = check_cd_flag1(args[1], shell);
	if (status == 1)
		return (1);
	else if (status == 0)
		return (0);
	status = check_cd_flag2(args[1], shell);
	if (status == 1)
		return (1);
	else if (status == 0)
		return (0);
	return (-1);
}

int my_cd2(char **args, shell_t *shell)
{
	char *path = get_dir();
	int status = my_cd_status(args, shell);
	
	if (status == 0 || status == 1)
		return (status);
	if (chdir(args[1]) == -1) {
		print_command_error(errno, args[1]);
		free(path);
		return (1);
	}
	write_env("OLDPWD", path, shell);
	free(path);
	path = get_dir();
	write_env("PWD", path, shell);
	free(path);
	return (0);
}

int my_cd(char **args, shell_t *shell)
{
	hashmap_t *home = get_hm_by_key(&(shell->hm_env), "HOME");
	char *path = NULL;

	if (my_length_tab(args) > 2) {
		my_putstr("cd: Too many arguments.\n");
		return (1);
	} else if (my_length_tab(args) == 1) {
		if (home != NULL) {
			path = get_dir();
			write_env("OLDPWD", path, shell);
			chdir(home->value);
			free(path);
			path = get_dir();
			write_env("PWD", path, shell);
			return (0);
		}
		my_putstr("cd: No home directory.\n");
		return (1);
	}
	return (my_cd2(args, shell));
}
