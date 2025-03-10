# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 10:36:55 by jsantann          #+#    #+#              #
#    Updated: 2023/04/18 00:22:59 by jsantann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a
SRCS =	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_memcpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strchr.c \
			ft_strncmp.c \
			ft_strjoin.c \
			ft_strjoin_nofree.c \
			ft_substr.c \
			ft_strtrim.c \
			ft_split.c \
			ft_strdup.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_strlen.c \
			ft_hexadecimal.c \
			ft_pointer.c \
			ft_print_utils.c \
			ft_printf.c \
			ft_putnbr.c \
			ft_putchar.c \
			ft_remove.c \
			ft_strcmp.c \
			ft_putstr.c 

SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c\
			ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
			ft_lstend.c ft_lstpenultimate.c
CC	=	cc
CFLAGS	= -Wall -Wextra -Werror -g
OBJS = $(SRCS:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
RM = rm -f
LIBC = ar -rcs

.c.o:
	$(CC) $(CFLAGS) -I . -c $< -o $@

all: $(NAME) bonus

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

bonus: $(OBJ_BONUS)
	$(LIBC) $(NAME) $(OBJ_BONUS)


clean:
	$(RM) $(OBJS) 
	$(RM) $(OBJ_BONUS)
	
fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all fclean clean re
