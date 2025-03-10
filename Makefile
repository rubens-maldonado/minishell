##########################################################
#					FLAGS								#
##########################################################

NAME		:= minishell
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g -Iincludes
CPPFLAGS    := -I ~/.brew/opt/readline/include
LDFLAGS     := -L ~/.brew/opt/readline/lib
DEBUG		:= -g
LIBFT		:= includes/libft

##########################################################
#					PROGRAM`S SRCS						 #
##########################################################

SRCS		:= srcs/start.c \
			   srcs/signals.c \
			   srcs/lexer/token.c \
			   srcs/parse/parse.c \
			   srcs/executor/builtins/commands.c \
			   srcs/executor/builtins/echo.c \
			   srcs/executor/builtins/pwd.c \
			   srcs/executor/builtins/cd.c \
			   srcs/executor/builtins/env.c \
			   srcs/executor/builtins/env_2.c \
			   srcs/executor/builtins/export.c \
			   srcs/executor/builtins/unset.c \
			   srcs/executor/executor.c \
			   srcs/executor/executor2.c \
			   srcs/executor/pipex.c \
			   srcs/executor/check_dir.c \
			   srcs/executor/redirects_utils.c \
			   srcs/executor/redirects.c \
			   srcs/executor/redirects_2.c \
			   srcs/executor/heredoc.c	\
			   srcs/expanser/expanser.c \
			   srcs/expanser/expanser_path.c \
			   srcs/expanser/expanser_str.c \
			   srcs/expanser/quotes.c \
			   srcs/expanser/simple_quotes.c \
			   srcs/utils/utils.c \
			   srcs/utils/free.c \
			   srcs/utils/free2.c 

OBJS		:= $(SRCS:.c=.o)

#########################################################
#						COLORS							#
#########################################################

CLR_RMV	:= \033[0m
RED		:= \033[1;31m
GREEN	:= \033[1;32m
YELLOW	:= \033[1;33m
BLUE    := \033[1;34m
CYAN	:= \033[1;36m

########################################################
#						FUNCTIONS					   #
########################################################

all: $(NAME)

$(NAME): $(OBJS)
		@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
		@$(MAKE) -s -C $(LIBFT) all
		@ cp ./includes/libft/libft.a .
		@ cc -o $@ $^ -L ~/.brew/opt/readline/lib libft.a -I ~/.brew/opt/readline/include -lreadline
		@ echo "$(GREEN)$(NAME) created ✔️"

clean:
	@ rm -rf $(OBJS) libft.a
	@ echo "$(RED)Cleaning up$(CLR_RMV)..."

fclean: clean
	@ rm -rf ${NAME}
	@ echo "$(CYAN)Removing libft$(CLR_RMV)..."
	@$(MAKE) -s -C $(LIBFT) fclean
	@ echo "$(RED)OBJS AND LIBFT REMOVED ✔️"

re: fclean all

.PHONY: all clean fclean re

