/*
** EPITECH PROJECT, 2018
** 42SH
** File description:
** 42SH
*/

#ifndef MY_SHELL_H_
	#define MY_SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <signal.h>
#include <errno.h>
#include <stdbool.h>
#include <fcntl.h>
#include <time.h>
#include "my.h"
#include "42sh_structure.h"
#include "alias.h"

#define SETENV_ERROR_ALPHA "setenv: Variable name must contain alphanumeric characters.\n"
#define SETENV_ERROR_LETTER "setenv: Variable name must begin with a letter.\n"
#define SETENV_ERROR_TOO_MANY_ARGS "setenv: Too many arguments.\n"

#define HISTORY_FILE ("./.42sh_history")

int analyse_command(char **args, shell_t *shell, bool pipe, queue_t *queue);
void sigint(int sig);
void sigstop(int sig);
int execute(char **args, shell_t *shell, char *path, bool pipe);
char *get_full_path(char *path, char *name);
int execute_all(char **args, shell_t *shell, bool pipe, queue_t *queue);
int init_env_struct(shell_t *shell);
void add_path_to_list(list_t **head, char *str);
int init_path(shell_t *shell);
int reload(shell_t *shell);
int free_env(shell_t *shell);
int display_prompt(shell_t *shell);
int ask_user(shell_t *shell);
int get_size(char *str, int index);
char *init_str(char *str);
char *get_path(char *str, int *index);
int is_alphanumeric(char *str);
int my_str_contains(char *str, char c);
int get_key_size(char *str);
char *get_key(char *str);
char *get_value(char *str);
char *get_dir(void);
char *get_arg(char *str, int *index);
int add_args_to_list(list_t **head, char *str);
int l_until_space(char *str, int index);
char **list_to_2d(list_t **head);
int add_str(list_t **head, char *str);
int free_list(list_t **head);
int print_list(list_t **list);
int get_lenght(list_t **head);
list_t *get_list_by_id(list_t **head, int id);
hashmap_t *get_hm_by_id(hashmap_t **head, int id);
int get_lenght_hm(hashmap_t **head);
char **hashmap_to_2d(hashmap_t **head);
int free_2d_tab(char **tab);
hashmap_t *get_hm_by_key(hashmap_t **head, char *key);
int delete_hm_by_key(hashmap_t **head, char *key);
int print_hashmap(hashmap_t **hashmap);
int init_hm_env(char **shell, hashmap_t **hashmap);
int add_keyvalue(hashmap_t **head, char *key, char *value);
int free_hashmap(hashmap_t **head);
int my_unsetenv(char **args, shell_t *shell);
int write_env(char *key, char *value, shell_t *shell);
int my_setenv(char **args, shell_t *shell);
int my_exit(char **args, shell_t *shell);
int check_error(char **args, shell_t *shell);
int my_env(char **args, shell_t *shell);
int my_cd2(char **args, shell_t *shell);
int my_cd(char **args, shell_t *shell);
char *get_next_line(int fd);
int print_command_error(int id, char *path);
int print_command_result(int id);
int queue_commands(queue_t **queue, char *cmd);
int free_queue(queue_t **head);
int add_queue(queue_t **head, char *cmd, bool cond_and, bool cond_or);
queue_t *init_queue(char *str);
int analyse_queue(queue_t **queue, shell_t *shell);
int execute_queue(queue_t **head, shell_t *shell);
int execute_pipe(queue_t *curr, shell_t *shell);
char *clear_str(char *src);
int my_length_tab(char **tab);
bool check_only_space(char *raw_command);
int can_redirect_right(char **args, int i, bool pipe);
bool check_redirection(char **args, bool pipe);
int can_redirect_left(char **args, int i, bool pipe);
int can_redirect_double_left(char **args, int i, bool pipe);
int pipe_str(char *str);
int check_if_redirect_error(char **args, int i, bool pipe);
hashmap_t *init_hashmap_element(void);
int get_hm_length(hashmap_t **head);
int get_list_length(list_t **head);
char *format_raw_commands(char *raw);
int my_echo(char **args, shell_t *shell, bool pipe, int tmp);
bool check_wrong_raw_command(char *raw_command);
char *get_str_between(int a, int b, char *str);
int my_strlen_to(char *str, int i, char c);
char *replace_str_by_env_var(char *cmd, shell_t *shell);
bool is_in_str(char *str, int index, char c);
int separate_commands(char *cmd, queue_t **queue);
char *format_args(char *str);
char **separate_arguments(char *cmd, bool format_args);
bool condition(bool and_cond, bool or_cond, shell_t *shell);
int execute_utils(queue_t *curr, shell_t *shell);
char **separate_pipe_commands(char *cmd);
char *complete_hour(void);
hist_t *init_linked_list();
void store_id(int *id, hist_t *head);
int print_history(void);
void manage_min(char *hour, int min);
void manage_hour(int hours, int min, char *hour);
char *complete_hour(void);
int store_in_file(hist_t *end);
int create_new_link(char *cmd, hist_t *head);
int store_cmd(char *cmd, hist_t *history);
void store_id(int *id, hist_t *head);
int manage_line(char *line, hist_t *hist);
int store_history(hist_t *hist);
hist_t *init_linked_list(void);
int print_history(void);
int my_print_history(char **args, shell_t *shell);
bool set_redir(redir_t *redir_a, char *file, char *word, \
bool is_double_redir);
redir_t *create_redir(void);
char *detect_redir(char *cmd, queue_t *queue, bool pipe_cmd);
int can_execute_pipe(char **args, shell_t *shell, char *path, queue_t *queue);
int can_execute_basic(char **args, shell_t *shell, char *path, \
queue_t *queue);
int ask_text_redirect(queue_t *queue);
char **split_line(char *str);
int execute_basic(queue_t *curr, shell_t *shell);
int fork_execute_pipe(queue_t *curr, shell_t *shell);
int pipe_commands(char *path, char **newargv, queue_t *queue, shell_t *shell);
int fork_command(char *path, char **newargv, queue_t *queue, shell_t *shell);
int apply_redir(queue_t *queue, bool pipe);
bool is_symbol(char *str);
bool is_redir_double_left(char **tab, int *index, queue_t *queue, \
bool pipe);
bool is_redir_double_right(char **tab, int *index, queue_t *queue, \
bool pipe);
bool is_redir_simple_left(char **tab, int *index, queue_t *queue, \
bool pipe);
bool is_redir_simple_right(char **tab, int *index, queue_t *queue, \
bool pipe);
char *my_concat(char *new_str, char *tmp, int *j);
bool is_first_pipe(char **tab, int index);
bool is_last_pipe(char **tab, int index);
char *my_init_tab(int length);
alias_t **init_alias(void);

#endif /* !MY_SHELL_H_ */
