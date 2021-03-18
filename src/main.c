/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "42sh.h"

void sigint(__attribute__((unused)) int sig)
{
	write(1, "\n> ", 2);
}

void sigstop(__attribute__((unused)) int sig)
{
}

int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av, \
char **env)
{
	shell_t *shell = malloc(sizeof(shell_t));

	if (shell == NULL)
		return (0);
	shell->to_return = 0;
	signal(SIGINT, sigint);
	signal(SIGTSTP, sigstop);
	shell->alias = init_alias();
	init_env_struct(shell);
	init_hm_env(env, &(shell->hm_env));
	reload(shell);
	delete_hm_by_key(&(shell->hm_env), "OLDPWD");
	ask_user(shell);
	free_env(shell);
	return (shell->to_return);
}