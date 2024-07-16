# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 16:02:22 by rchavez           #+#    #+#              #
#    Updated: 2024/07/16 16:02:18 by rchavez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=ADDRESS

O_FOLDER = OBJ

SRC = philosophers.c msleep.c intro.c routine.c utils.c parsing.c usage.c\
	keeper.c atoli.c

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
	rm -f $(NAME) 

re : fclean all

run : all
	./$(NAME) 42 200 42 42 42

.PHONY : all clean fclean re run