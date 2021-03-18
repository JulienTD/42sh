/*
** EPITECH PROJECT, 2018
** replace_str_by_env_var
** File description:
** replace_str_by_env_var
*/

#include "42sh.h"

static char *replace_env_id_return(char *cmd, int *index, shell_t *shell)
{
	char *value = my_nbr_to_str(shell->to_return);
	char *new_str = malloc((my_strlen(cmd) + my_strlen(value) + 1) * \
	sizeof(char));
	int j = 0;

	for (int i = 0; i < *index; i++)
		new_str[j++] = cmd[i];
	for (int i = 0; value[i] != '\0'; i++)
		new_str[j++] = value[i];
	for (int i = *index + my_strlen_to(cmd, *index, ' '); \
	i < my_strlen(cmd); i++)
		new_str[j++] = cmd[i];
	new_str[j] = '\0';
	*index = *index + 1;
	return (new_str);
}

static char *replace_env_id(char *cmd, int *index, \
__attribute__((__unused__)) shell_t *shell, hashmap_t *hm)
{
	char *new_str = malloc((my_strlen(cmd) + my_strlen(hm->value) + 1) * \
	sizeof(char));
	int j = 0;

	for (int i = 0; i < *index; i++)
		new_str[j++] = cmd[i];
	for (int i = 0; hm->value[i] != '\0'; i++)
		new_str[j++] = hm->value[i];
	for (int i = *index + my_strlen(hm->key) + 1; i < my_strlen(cmd); i++)
		new_str[j++] = cmd[i];
	new_str[j] = '\0';
	*index = *index + my_strlen(hm->value);
	return (new_str);
}

static char *replace_env2(char *cmd, int *i, shell_t *shell)
{
	int size = my_strlen_to(cmd, *i, ' ');
	char *env_id = get_str_between(*i + 1, *i + size, cmd);
	hashmap_t *hm = get_hm_by_key(&(shell->hm_env), env_id);

	if (hm == NULL && env_id[0] != '?') {
		write(1, env_id, my_strlen(env_id));
		write(1, ": Undefined variable.\n", 22);
		shell->to_return = 1;
		free(cmd);
		free(env_id);
		return (NULL);
	}
	if (env_id[0] == '?')
		cmd = replace_env_id_return(cmd, i, shell);
	else
		cmd = replace_env_id(cmd, i, shell, hm);
	free(env_id);
	return (cmd);
}

char *replace_str_by_env_var(char *cmd, shell_t *shell)
{
	if (cmd == NULL)
		return (NULL);
	for (int i = 0; i < my_strlen(cmd); i++) {
		if (cmd == NULL)
			return (NULL);
		if (cmd[i] == '$' && cmd[i + 1] == '\0')
			return (cmd);
		if (i == 0 && cmd[i] == '$') {
			cmd = replace_env2(cmd, &i, shell);
		} else if (cmd[i] == '$' && cmd[i - 1] != '\\' && \
		is_in_str(cmd, i, '\'') == false) {
			cmd = replace_env2(cmd, &i, shell);
		}
		if (cmd == NULL)
			return (NULL);
	}
	return (cmd);
}
