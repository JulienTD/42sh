##
## EPITECH PROJECT, 2017
## 42sh
## File description:
## 42sh
##

NAME			=	42sh

SRC			=	./src/main.c

SRC_COMMANDS		=	./src/commands/executor.c \
				./src/commands/analyse_command.c \
				./src/commands/can_execute_basic.c \
				./src/commands/can_execute_pipe.c \
				./src/commands/pipe_commands.c \
				./src/commands/fork_command.c

SRC_ENVIRONMENT		=	./src/environment/env.c \
				./src/environment/init_hm_env.c

SRC_INTERACTIONS	=	./src/interactions/ask_user.c \
				./src/interactions/display_prompt.c

SRC_UTILS 		= 	./src/utils/hashmap_utils.c \
				./src/utils/str_utils.c \
				./src/utils/args_utils.c \
				./src/utils/get_dir.c \
				./src/utils/my_length_tab.c \
				./src/utils/my_strlen_to.c \
				./src/utils/my_init_tab.c

SRC_BUILTINS		=	./src/builtins/my_setenv.c \
				./src/builtins/my_unsetenv.c \
				./src/builtins/my_env.c \
				./src/builtins/my_cd.c \
				./src/builtins/my_exit.c \
				./src/builtins/my_echo.c \
				./src/builtins/my_print_history.c

SRC_LIST		=	./src/list/add_str.c \
				./src/list/free_list.c \
				./src/list/get_list_by_id.c \
				./src/list/get_list_length.c \
				./src/list/list_to_2d.c \
				./src/list/print_list.c

SRC_HASHMAP		=	./src/hashmap/add_keyvalue.c \
				./src/hashmap/free_hashmap.c \
				./src/hashmap/print_hashmap.c \
				./src/hashmap/delete_hm_by_key.c \
				./src/hashmap/get_hm_by_key.c \
				./src/hashmap/hashmap_to_2d.c \
				./src/hashmap/init_hashmap_element.c \
				./src/hashmap/get_hm_length.c \
				./src/hashmap/get_hm_by_id.c

SRC_ERRORS		=	./src/errors/error_command.c

SRC_QUEUE		=	./src/queue/add_queue.c \
				./src/queue/analyse_queue.c \
				./src/queue/execute_queue.c \
				./src/queue/free_queue.c \
				./src/queue/init_queue.c \
				./src/queue/execute_utils.c

SRC_PARSER		=	./src/parser/clear_str.c \
				./src/parser/format_raw_command.c \
				./src/parser/check_wrong_raw_command.c \
				./src/parser/is_in_str.c \
				./src/parser/replace_str_by_env_var.c \
				./src/parser/separate_commands.c \
				./src/parser/format_args.c \
				./src/parser/separate_arguments.c \
				./src/parser/separate_pipe_commands.c \
				./src/parser/detect_redir.c \
				./src/parser/is_redir_double_left.c \
				./src/parser/is_redir_simple_left.c \
				./src/parser/is_redir_double_right.c \
				./src/parser/is_redir_simple_right.c \
				./src/parser/is_symbol.c

SRC_CRITERION		=	./tests/raw_commands.c

SRC_HISTORY		=	./src/history/complete_hour.c \
				./src/history/history.c \
				./src/history/init_linked_list.c \
				./src/history/print_history.c \
				./src/history/split_line.c

SRC_ALIAS		=	./src/alias/init_alias.c \
				./src/alias/alias_error_display.c \
				./src/alias/alias_utils.c \
				./src/alias/check_alias.c \
				./src/alias/alias_command.c \

SRC_REDIRECTIONS	=	./src/redirections/apply_redir.c \
				./src/redirections/ask_text_redirect.c \
				./src/redirections/create_redir.c

OBJ			=	$(SRC:.c=.o) $(SRC_UTILS:.c=.o) $(SRC_BUILTINS:.c=.o) $(SRC_LIST:.c=.o) $(SRC_REDIRECTIONS:.c=.o) \
				$(SRC_HASHMAP:.c=.o) $(SRC_COMMANDS:.c=.o) $(SRC_ENVIRONMENT:.c=.o) $(SRC_INTERACTIONS:.c=.o) \
				$(SRC_ERRORS:.c=.o) $(SRC_QUEUE:.c=.o) $(SRC_PARSER:.c=.o) $(SRC_HISTORY:.c=.o) $(SRC_ALIAS:.c=.o)

OBJ_CRITERION		=	$(SRC_CRITERION:.c=.o)

CFLAGS			=	-I./include/ -L./lib/my -lmy -Wall -W -Wextra -pedantic

all:	$(NAME)


search:
	cat $(SRC_UTILS) $(SRC_BUILTINS) $(SRC_LIST) $(SRC_HASHMAP) $(SRC_COMMANDS) $(SRC_ENVIRONMENT) $(SRC_INTERACTIONS) $(SRC_ERRORS) $(SRC_QUEUE) $(SRC_PARSER) $(SRC_HISTORY) | grep "255"

valgrind:
	valgrind --leak-check=yes --show-reachable=yes -v ./42sh

wc:
	wc $(SRC)

tests_run:	$(SRC_UTILS) $(SRC_BUILTINS) $(SRC_LIST) $(SRC_HASHMAP) $(SRC_COMMANDS) $(SRC_ENVIRONMENT) $(SRC_INTERACTIONS) $(SRC_ERRORS) $(SRC_QUEUE) $(SRC_PARSER) $(SRC_HISTORY)
	make re -C ./lib/my
	gcc $(SRC_UTILS) $(SRC_BUILTINS) $(SRC_LIST) $(SRC_HASHMAP) $(SRC_COMMANDS) $(SRC_ENVIRONMENT) $(SRC_INTERACTIONS) $(SRC_ERRORS) $(SRC_QUEUE) $(SRC_PARSER) $(SRC_HISTORY) -o all_tests -lcriterion --coverage $(CFLAGS)
	./all_tests

cov:	tests_run
	gcov *

$(NAME):	$(OBJ)
	make re -C ./lib/my
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

re:	fclean all

clean:
	rm -f $(OBJ) $(OBJ_CRITERION) *.o *.gcov *.gcda *.gcno *~ \#*\#
	make clean -C ./lib/my

fclean:	clean
	rm -f $(NAME)
	rm -f all_tests
	make fclean -C ./lib/my
