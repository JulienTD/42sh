/*
** EPITECH PROJECT, 2018
** complete_hour.c
** File description:
** Function which permit to complete the hour of the history
*/
#include "42sh.h"

void manage_min(char *hour, int min)
{
	if (min < 10) {
		hour[3] = '0';
		hour[4] = min + 48;
	} else {
		hour[3] = min / 10 + 48;
		while (min > 10)
			min -= 10;
		hour[4] = min + 48;
	}
}

void manage_hour(int hours, int min, char *hour)
{
	if (hours < 10) {
		hour[0] = '0';
		hour[1] = hours + 48;
	} else {
		hour[0] = hours / 10 + 48;
		hour[1] = hours % 10 + 48;
	}
	hour[2] = ':';
	manage_min(hour, min);
}

char *complete_hour(void)
{
	time_t secondes;
	struct tm *info = NULL;
	char *hour = malloc(sizeof(char) * 7);
	int hours = 0;
	int min = 0;

	if (!hour)
		exit (84);
	my_init(hour, 7);
	time(&secondes);
	info = localtime(&secondes);
	hours = info->tm_hour;
	min = info->tm_min;
	manage_hour(hours, min, hour);
	return (hour);
}
