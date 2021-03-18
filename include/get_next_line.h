/*
** EPITECH PROJECT, 2017
** get_next_line.h
** File description:
** get_next_line.h
*/

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_
#define READ_SIZE (1)

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct listg_s listg_t;
struct listg_s
{
	char letter;
	listg_t *next;
};
char *get_next_line(int fd);

#endif /* !GET_NEXT_LINE_H_ */
