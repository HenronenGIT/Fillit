
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
DB_FLAG = -g $(FLAGS)

#Source files
SRC = ./main.c ./tetrimino_check.c ./mapper.c ./map_estimater.c	\
./print_solution.c ./get_next_line.c
	
OBJ = $(SRC:.c=.o)

#Includes
HEADERS = $(GNL_H) $(LIBFT_H) $(FILLIT_H) 
LIBFT_H = -I ./libft/includes
FILLIT_H = -I ./

#Paths
FILE_PATH = ./eval_tests/test_files/valid_file/

#Library
LIB = -L ./libft -lft

#Remove
RM = /bin/rm -f

all: $(NAME)

$(NAME): $(SRC)
	@@make -C ./libft/ $(LIBFT_H) fclean && make -C ./libft/ $(LIBFT_H)
	@@$(CC) $(FLAGS) $(HEADERS) $(SRC) -o $(NAME) $(LIB)

debug:
	@@make -C ./libft/ $(LIBFT_H) fclean && make -C ./libft/ $(LIBFT_H)
	@@$(CC) $(DB_FLAG) $(HEADERS) $(SRC) -o $(NAME) $(LIB)

clean:
	@@$(RM) $(OBJ)
	@@make clean -C ./libft/


fclean: clean
	@@/bin/rm -f $(NAME)
	@@make fclean -C ./libft/

re: fclean all

11:
	./fillit $(FILE_PATH)1_tetriminos_1.txt
12:
	./fillit $(FILE_PATH)1_tetriminos_2.txt
13:
	./fillit $(FILE_PATH)1_tetriminos_3.txt
14:
	./fillit $(FILE_PATH)1_tetriminos_4.txt
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
custom:
	./fillit $(FILE_PATH)custom_tetriminos.txt
max:
	./fillit $(FILE_PATH)max.txt
error:
	@@$(CC) ./eval_tests/error_test.c -I ./libft/includes/
	@@./a.out

.PHONY: all clean fclean re
