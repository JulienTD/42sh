/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** alias utils
*/

#include "42sh.h"

void **my_realloc_(void **ptr, size_t size)
{
	int len = 0;
	void **ptr_ret = malloc(size);

	while (ptr[len]) {
		ptr_ret[len] = ptr[len];
		len++;
	}
	ptr_ret[len] = NULL;
	free(ptr);
	return (ptr_ret);
}

alias_t **alias_new_size(alias_t **alias, alias_t *alias_to_add)
{
	int len = 0;

	if (alias_to_add == NULL)
		return (alias);
	if (alias == NULL)
		alias = malloc(sizeof(alias_t *) * 2);
	else {
		while (alias[len])
			len++;
		alias = (alias_t **)my_realloc_((void **)alias,
			sizeof(alias_t *) * (len + 2));
	}
	if (alias == NULL)
		exit(84);
	alias[len] = alias_to_add;
	alias[len + 1] = NULL;
	return (alias);
}