/*
** EPITECH PROJECT, 2018
** get_dir
** File description:
** get_dir
*/

#include "42sh.h"

char *get_dir(void)
{
	char *buf = malloc(512 * sizeof(char));
	size_t size = 512;

	buf = getcwd(buf, size);
	return buf;
}