/*
** EPITECH PROJECT, 2018
** init_hm_env
** File description:
** init_hm_env
*/

#include "42sh.h"

int init_hm_env(char **env, hashmap_t **hashmap)
{
	char *key = NULL;
	char *value = NULL;

	if (env == NULL)
		return (-1);
	for (int i = 0; env[i] != NULL; i++) {
		key = get_key(env[i]);
		value = get_value(env[i]);
		add_keyvalue(hashmap, key, value);
		if (key)
			free(key);
		if (value)
			free(value);
	}
	return (1);
}