# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchavez@student.42heilbronn.de <rchavez    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 16:02:22 by rchavez           #+#    #+#              #
#    Updated: 2024/07/15 16:37:37 by rchavez@stu      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=ADDRESS

O_FOLDER = OBJ

SRC = philosophers.c msleep.c intro.c routine.c utils.c parsing.c usage.c\
	keeper.c

HEADER = philosophers.h

OBJ = $(SRC:%.c=$(O_FOLDER)/%.o)

NAME = philosophers

all : $(NAME)

$(NAME) : $(O_FOLDER) $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -pthread

$(O_FOLDER)/%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

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

run : all
	./$(NAME) 42 200 42 42 42

.PHONY : all clean fclean re run