/*
** EPITECH PROJECT, 2018
** check_only_space
** File description:
** check_only_space
*/

#include "42sh.h"

static bool check_double_quotes(char *raw_command, int double_quote, \
int quote)
{
	for (int i = 0; raw_command[i] != '\0'; i++) {
		if (raw_command[i] == '\"' && double_quote % 2 == 1) {
			write(1, "Unmatched \'\"\'.\n", 15);
			return (true);
		}
		if (raw_command[i] == '\'' && quote % 2 == 1) {
			write(1, "Unmatched \'\'\'.\n", 15);
			return (true);
		}
	}
	return (false);
}
//TO-DO: Str! "'" -> Not wrong
static bool check_quotes(char *raw_command)
{
	int quote = 0;
	int double_quote = 0;

	for (int i = 0; raw_command[i] != '\0'; i++) {
		if (i == 0 && raw_command[i] == '\'') {
			quote++;
			continue;
		}
		if (raw_command[i] == '\'' && raw_command[i - 1] != '\\')
			quote++;
	}
	for (int i = 0; raw_command[i] != '\0'; i++) {
		if (i == 0 && raw_command[i] == '\"') {
			double_quote++;
			continue;
		}
		if (raw_command[i] == '\"' && raw_command[i - 1] != '\\')
			double_quote++;
	}
	return (check_double_quotes(raw_command, double_quote, quote));
}

static int count_nbr_follow(char *str, char c, char c_exept, int index)
{
	int nbr = 0;

	if (index >= my_strlen(str))
		return (0);
	for (int i = index; i < my_strlen(str); i++) {
		if (str[i] == c)
			nbr++;
		else if (str[i] == c_exept)
			continue;
		else
			return (nbr);
	}
	return (nbr);
}

static bool check_too_many_symbol(char *raw_command)
{
	int nbr = 0;

	for (int i = 0; raw_command[i] != '\0'; i++) {
		nbr = count_nbr_follow(raw_command, raw_command[i], ' ', i);
		if ((raw_command[i] == '&' || raw_command[i] == '|') \
		&&  nbr >= 2 \
		&& is_in_str(raw_command, i, '\'') == false \
		&& is_in_str(raw_command, i, '\'') == false \
		&& i + nbr >= my_strlen(raw_command)) {
			write(1, "Invalid null command.\n", 22);
			return (true);
		}
	}
	return (false);
}

bool check_wrong_raw_command(char *raw_command)
{
	if (my_strlen(raw_command) <= 0 || \
	my_char_count(raw_command, ' ') + \
	my_char_count(raw_command, '\t') + \
	my_char_count(raw_command, ';') + \
	my_char_count(raw_command, '|') + \
	my_char_count(raw_command, '&') + \
	my_char_count(raw_command, '>') + \
	my_char_count(raw_command, '<') == my_strlen(raw_command)) {
		return (true);
	}
	if (check_quotes(raw_command) == true)
		return (true);
	if (check_too_many_symbol(raw_command) == true)
		return (true);
	return (false);
}