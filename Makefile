# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 16:02:22 by rchavez           #+#    #+#              #
#    Updated: 2024/07/10 16:30:10 by rchavez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=ADDRESS

O_FOLDER = OBJ

SRC = philosophers.c

HEADER = philosophers.h

OBJ = $(SRC:%.c=$(O_FOLDER)/%.o)

NAME = philosophers

all : $(NAME)

$(NAME) : $(OBJ) $()
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -pthread

$(O_FOLDER)/%.o : %.c $(O_FOLDER)
	$(CC) $(CFLAGS) $@ $^

$(O_FOLDER) :
	@if [ ! -d $(O_FOLDER) ]; then\
		mkdir $(O_FOLDER);\
	fi

clean :
	@if [ -d $(O_FOLDER) ]; then\
		rm -fr $(O_FOLDER);\
	fi

fclean : clean

re : fclean all

.PHONY : all clean fclean re