/*
** EPITECH PROJECT, 2018
** hashmap_to_2d
** File description:
** hashmap_to_2d
*/

#include "42sh.h"

char **hashmap_to_2d(hashmap_t **head)
{
	char **tab = malloc((get_hm_length(head) + 1) * sizeof(char *));
	hashmap_t *curr = *head;
	int j = 0;
	int index = 0;

	if (tab == NULL || *head == NULL || head == NULL)
		return (NULL);
	for (; curr; curr = curr->next) {
		tab[index] = malloc((my_strlen(curr->key) + \
		my_strlen(curr->value) + 2) * sizeof(char));
		for (int i = 0; i < my_strlen(curr->key); i++)
			tab[index][j++] = curr->key[i];
		tab[index][j++] = '=';
		for (int i = 0; i < my_strlen(curr->value); i++)
			tab[index][j++] = curr->value[i];
		tab[index++][j] = '\0';
		j = 0;
	}
	tab[index] = NULL;
	return (tab);
}

int free_2d_tab(char **tab)
{
	if (tab == NULL)
		return (0);
	for (int i = 0; tab[i] != NULL; i++)
		free(tab[i]);
	free(tab);
	return (1);
}