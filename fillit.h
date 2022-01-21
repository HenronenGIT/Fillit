/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:57:29 by hmaronen          #+#    #+#             */
/*   Updated: 2022/01/10 10:57:32 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>

# define TOP_ALL 61440
# define LEFT_ALL 34952

typedef struct s_tetrimino
{
	unsigned short		*shape;
	unsigned int		order;
	unsigned short		*reset;
	struct s_tetrimino	*next;
}						t_tetrimino;

int			error_handler(int nb);
t_tetrimino	*tetrimino_check(const int fd);
int			mapper(t_tetrimino *list, int side);
void		dtob(int b);
void		print_map(unsigned short *map, int side);
void		list_add_back(t_tetrimino **list, t_tetrimino *new);
int			map_estimater(t_tetrimino *list);
int		print_solution(t_tetrimino *list, int side);
#endif
