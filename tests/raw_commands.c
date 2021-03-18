/*
** EPITECH PROJECT, 2018
** crtierion
** File description:
** raw_command
*/

#include <criterion/criterion.h>
#include "42sh.h"

Test(check_wrong_raw_command, wrong_input) {
	char *cmd = "\'&;|\'";

	cr_assert(check_wrong_raw_command(cmd) == true);
}

Test(check_wrong_raw_command, right_input) {
	char *cmd = "ls ; pwd > file ; cat file | grep home";

	cr_assert(check_wrong_raw_command(cmd) == false);
}
