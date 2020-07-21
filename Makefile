# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gregory <gregory@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/28 13:46:16 by gregory           #+#    #+#              #
#    Updated: 2020/07/21 13:39:08 by gregory          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= get_next_line
CFLAGS	= -Wall -Werror -Wextra
LDFLAGS	= -shared -fPIC -g
LINKER_FLAGS = -lft
CC		= gcc
FILES	= get_next_line.c \
			main.c
OBJ 		= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L/home/gregory/42/prepa/gnl/get_next_line/libft $(LINKER_FLAGS)

$(OBJ): $(FILES)
	$(CC) $(CFLAGS) -c $(FILES)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
