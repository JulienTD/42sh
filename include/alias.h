/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** alias.h
*/

#ifndef ALIAS_H_
#define ALIAS_H_

char **check_alias(char **args, shell_t *shell);
alias_t **init_alias(void);
alias_t **alias_new_size(alias_t **alias, alias_t *alias_to_add);
bool check_unknow(char **word, char *cmd, int lindex);
bool check_error_alias(char **temp, char **equal, char **temp2);
void free_alias_init(char **tmp, char **eq, alias_t *alias, char **tmp2);
void display_invalid_line(char *line, int lindex);
void display_unknow(char *cmd, int lindex);
int my_alias(char **args, shell_t *shell);

#endif /* !ALIAS_H_ */
