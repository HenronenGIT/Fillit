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
# define top_all 61440
# define left_all 34952

typedef struct	s_tetrimino
{
	unsigned short		shape;
	unsigned int		order;
	struct s_tetrimino	*next;
} 						t_tetrimino;


int	error_handler(int nb);
int	tetrimino_check(const int fd);

#endif
