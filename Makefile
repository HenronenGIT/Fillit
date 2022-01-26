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

#Paths
FILE_PATH = ./eval_tests/valid_file/

#Library
LIB = -L ./libft -lft

#Remove
RM = /bin/rm -f

all: $(NAME)

$(NAME): $(SRC)
	@@make -C ./libft/ $(LIBFT_H) fclean && make -C ./libft/ $(LIBFT_H)
	@@$(CC) $(FLAGS) $(HEADERS) $(SRC) -o $(NAME) $(LIB)

clean:
	@@$(RM) $(OBJ)

fclean: clean
	@@/bin/rm -f $(NAME)

re: fclean all

1:
	./fillit $(FILE_PATH)1_tetriminos.txt
2:
	./fillit $(FILE_PATH)2_tetriminos.txt
3:
	./fillit $(FILE_PATH)3_tetriminos.txt
4:
	./fillit $(FILE_PATH)4_tetriminos.txt
5:
	./fillit $(FILE_PATH)5_tetriminos.txt
10:
	./fillit $(FILE_PATH)10_tetriminos.txt
15:
	./fillit $(FILE_PATH)15_tetriminos.txt
max:
	./fillit $(FILE_PATH)max.txt
error:
	@@$(CC) ./eval_tests/error_test.c -I ./libft/includes/
	@@./a.out

.PHONY: all clean fclean re
