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
# define LFT_BIT 32768
# define SQUARE 52224
# define S_NORM 27648
# define S_NORM_R 35904
# define S_MIR 50688
# define S_OPP_L 
# define S_OPP_R 19584
# define L_R 59392
# define L_UP 50240
# define L_L 57856
# define L_NORM 17600
# define L_MIR_L 11776
# define L_MIR_R 36352
# define L_MIR_UP 51328
# define L_MIR 35008
# define T_NORM 58368
# define T_R 19520
# define T_UP 19968
# define T_L 35968

typedef struct s_tetrimino
{
	unsigned short		shape[4];
	unsigned int		order;
	unsigned short		reset[4];
	unsigned short		value;
	int					line;
	struct s_tetrimino	*next;
}						t_tetrimino;

int			error_handler(int nb, t_tetrimino **list);
int			tetrimino_check(const int fd, t_tetrimino **list);
int			mapper(t_tetrimino *list, int side);
int			map_estimater(t_tetrimino *list);
int			print_solution(t_tetrimino *list, int side);
int			get_next_line(const int fd, char **line);
#endif
