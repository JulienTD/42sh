/*
** EPITECH PROJECT, 2018
** 42SH_STRUCTS
** File description:
** 42SH_STRUCTS
*/

#ifndef MY_SHELL_STRUCTS_H_
	#define MY_SHELL_STRUCTS_H_

typedef struct vec_2d_s
{
	int x;
	int y;
} vec_2d_t;

typedef struct hashmap_s
{
	int id;
	char *key;
	char *value;
	struct hashmap_s *next;
} hashmap_t;

typedef struct command_s
{
	char **args;
} command_t;

typedef struct list_s
{
	char *str;
	//command_t *command;
	struct list_s *next;
} list_t;

typedef struct redir_s
{
	char *file;
	char *word;
	bool is_double_redir;
} redir_t;

typedef struct queue_s
{
	char **commands; //
	char *cmd;
	//list_t *command;
	int contain_pipe;
	bool condition_and;
	bool condition_or;
	redir_t *redir_left;
	redir_t *redir_right;
	bool error_ambi;
	bool error_name;
	bool first_cmd;
	bool last_cmd;
	struct queue_s *next;
} queue_t;

typedef struct hist_s {
	int id;
	char *cmd;
	char *hour;
	struct hist_s *next;
} hist_t;

typedef struct alias_s {
	char *old_cmd;
	char *new_cmd;
}alias_t;

typedef struct shell_s
{
	list_t *path;
	hashmap_t *hm_env;
	int to_return;
	hist_t *hist;
	alias_t **alias;
} shell_t;

#endif /* !MY_SHELL_STRUCTS_H_ */
