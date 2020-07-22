# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gregory <gregory@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/28 13:46:16 by gregory           #+#    #+#              #
#    Updated: 2020/07/22 12:24:19 by gregory          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= get_next_line
CFLAGS	= -Wall -Werror -Wextra
LDFLAGS	= -shared -fPIC -g
LIBRARY = libft/libft.a
CC		= gcc
FILES	= get_next_line.c \
			main.c
OBJ 		= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)  $(LIBRARY)

$(OBJ): $(FILES)
	$(CC) $(CFLAGS) -c $(FILES)

install:
	cd libft && make && make clean

uninstall:
	cd libft && make fclean

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
