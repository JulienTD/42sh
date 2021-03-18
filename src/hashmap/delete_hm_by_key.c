/*
** EPITECH PROJECT, 2018
** hashmap2
** File description:
** hashmap2
*/

#include "42sh.h"

static int fix_id(hashmap_t **head)
{
	int i = 0;
	hashmap_t *curr = *head;

	if (head == NULL || *head == NULL)
		return (0);
	while (curr) {
		curr->id = i;
		i++;
		curr = curr->next;
	}
	return (1);
}

static int delete_first(hashmap_t **head)
{
	hashmap_t *curr = *head;

	if (head == NULL || *head == NULL)
		return (0);
	*head = (*head)->next;
	if (curr->key != NULL)
		free(curr->key);
	if (curr->value != NULL)
		free(curr->value);
	if (curr != NULL)
		free(curr);
	return (1);
}

static int delete_element2(hashmap_t **head, int id)
{
	hashmap_t *last = NULL;
	hashmap_t *beforelast = NULL;

	if (id == 0) {
		delete_first(head);
		return (1);
	} else if (id == get_hm_length(head) - 1) {
		last = get_hm_by_id(head, get_hm_length(head) - 1);
		beforelast = get_hm_by_id(head, get_hm_length(head) - 2);
		beforelast->next = NULL;
		if (last->key != NULL)
			free(last->key);
		if (last->value != NULL)
			free(last->value);
		if (last != NULL)
			free(last);
		return (1);
	}
	return (0);
}

static int delete_element(hashmap_t **head, int id)
{
	hashmap_t *tmp = NULL;
	hashmap_t *tmp2 = NULL;

	if (*head == NULL || head == NULL)
		return (0);
	if (delete_element2(head, id) == 0) {
		tmp = get_hm_by_id(head, id);
		tmp2 = get_hm_by_id(head, id - 1);
		tmp2->next = tmp->next;
		if (tmp->key != NULL)
			free(tmp->key);
		if (tmp->value != NULL)
			free(tmp->value);
		if (tmp != NULL)
			free(tmp);
	}
	fix_id(head);
	return (1);
}

int delete_hm_by_key(hashmap_t **head, char *key)
{
	hashmap_t *curr = NULL;

	if (key == NULL || *head == NULL || head == NULL)
		return (-1);
	curr = *head;
	while (curr) {
		if (my_are_equals(curr->key, key)) {
			delete_element(head, curr->id);
			return (1);
		}
		curr = curr->next;
	}
	return (0);
}