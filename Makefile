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
SRC = ./main.c

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

run:
	@@./$(NAME)

torture:
	@@make -C ../libft/ fclean && make -C ../libft/
	@@$(CC) $(FLAGS) $(HEADERS) $(LIB) ../get_next_line.c ./tests/torture.c -o get_next_line

leaks:
	@@make -C ../libft/ fclean && make -C ../libft/
	@@$(CC) $(FLAGS) -fsanitize=leak $(HEADERS) $(LIB) $(SRC) -o $(NAME)


debug:
	$(CC) -g $(FLAGS) $(SRC) $(LIB) $(HEADERS)
	lldb

.PHONY: all clean fclean re
