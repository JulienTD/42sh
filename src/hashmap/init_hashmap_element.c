/*
** EPITECH PROJECT, 2018
** init_hashmap_element
** File description:
** init_hashmap_element
*/

#include "42sh.h"

hashmap_t *init_hashmap_element(void)
{
	hashmap_t *element = malloc(sizeof(hashmap_t));

	if (element == NULL)
		return (NULL);
	element->id = 0;
	element->key = NULL;
	element->next = NULL;
	element->value = NULL;
	return (element);
}