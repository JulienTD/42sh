/*
** EPITECH PROJECT, 2018
** error_command
** File description:
** error_command
*/

#include "42sh.h"

int print_command_error(int id, char *path)
{
	if (id == EACCES) {
		write(1, path, my_strlen(path));
		write(1, ": Permission denied.\n", 21);
	}
	if (id == ENOTDIR) {
		my_putstr(path);
		my_putstr(": Not a directory.\n");
	}
	if (id == ENOEXEC) {
		my_putstr(path);
		my_putstr(": Exec format error. Wrong Architecture.\n");
	}
	if (id == 2) {
		my_putstr(path);
		my_putstr(": No such file or directory.\n");
	}
	return (1);
}

int print_command_result(int id)
{
	int to_return = WEXITSTATUS(id);

	if (WIFSIGNALED(id) == 0)
		return (to_return);
	if (WTERMSIG(id) == SIGSEGV) {
		my_putstr("Segmentation fault");
		to_return = 139;
	}
	if (WTERMSIG(id) == SIGFPE) {
		my_putstr("Floating exception");
		to_return = 136;
	}
	if (WCOREDUMP(id))
		my_putstr(" (core dumped)");
	my_putstr("\n");
	return (to_return);
}