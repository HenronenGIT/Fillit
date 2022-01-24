# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 10:42:20 by hmaronen          #+#    #+#              #
#    Updated: 2022/01/10 10:42:22 by hmaronen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

#Compilation and flags
CC = gcc
FLAGS = -Wall -Wextra -Werror

#Source files
SRC = ./main.c ./tetrimino_check.c ./mapper.c ./dtob.c ./print_map.c	\
	./map_estimater.c ./print_solution.c
	
OBJ = $(SRC:.c=.o)
#TEST_PATH = ./tests

#Includes
HEADERS = $(GNL_H) $(LIBFT_H) $(FILLIT_H) 
LIBFT_H = -I ./libft/includes
FILLIT_H = -I ./

#Library
LIB = -L ./libft -lft

#Remove
RM = /bin/rm -f

all: $(NAME)

$(NAME): $(SRC)
	@@make -C ./libft/ $(LIBFT_H) fclean && make -C ./libft/ $(LIBFT_H)
	@@$(CC) $(FLAGS) $(LIB) $(HEADERS) $(SRC) -o $(NAME)

clean:
	@@$(RM) $(OBJ)

fclean: clean
	@@/bin/rm -f $(NAME)

re: fclean all

1:
	./fillit 1_tetrimino.txt
2:
	./fillit 2_tetriminos.txt
3:
	./fillit 3_tetrimino.txt
4:
	./fillit 4_tetrimino.txt
5:
	./fillit 5_tetrimino.txt
10:
	./fillit 10_tetrimino.txt
15:
	./fillit 15_tetrimino.txt
max:
	./fillit max.txt

.PHONY: all clean fclean re
