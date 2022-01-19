/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:31:45 by hmaronen          #+#    #+#             */
/*   Updated: 2022/01/13 16:31:47 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*Converts short tetrimino struct to int type map*/
int	*map_tetrimino(int side_side, unsigned short shape)
{
	int				*mapped_tetrimino;
	int				i;
	int				j;
	int				offset;
	int				flag;

	mapped_tetrimino = (int *)malloc(sizeof(int) * side_side);
	i = 0;
	while (i < side_side)
	{
		mapped_tetrimino[i] = 0;
		i++;
	}
	offset = 0;
	j = 0;
	i = 15;
	while (j < side_side)
	{
		flag = 1;
		flag = flag << i;

		if (shape & flag)
			mapped_tetrimino[j] = mapped_tetrimino[j] | (flag << offset);
		if (i % side_side == 0)
		{
			offset += 4;
			j++;
		}
		i--;
	}
	return (mapped_tetrimino);
}

int	*max_left_shift(int *mapped_tetrimino, int side)
{
	int	i;
	int	max_check;

	max_check = 0;
	i = 0;
	while (i < side)
	{
		if (mapped_tetrimino[i] & 32768)
			max_check = 1;
		i++;
	}
	if (max_check == 0)
	{
		i = 0;
		while (i < side)
		{
			mapped_tetrimino[i] = mapped_tetrimino[i] << 1;
			i++;
		}
		return (max_left_shift(mapped_tetrimino, side));
	}
	return (mapped_tetrimino);
}

int	*move_tetrimino(int *mapped_tetrimino, int side)
{
	int	last;
	int	line;

	last = 0;
	line = 0;
	last = side - 1;
	while (line < side)
	{
		mapped_tetrimino[line] = mapped_tetrimino[line] >> 1;
		if (mapped_tetrimino[line] & (32768 >> side))
		{
			if (mapped_tetrimino[last])
				return (NULL);
			while (line >= 0)
			{
				mapped_tetrimino[line] = mapped_tetrimino[line] << 1;
				line--;
			}
			while (last > 0)
			{
				mapped_tetrimino[last] = 0;
				mapped_tetrimino[last] = mapped_tetrimino[last] | mapped_tetrimino[last - 1];
				last--;
			}
			mapped_tetrimino[last] = 0;
			mapped_tetrimino = max_left_shift(mapped_tetrimino, side);
			break ;
		}
		line++;
	}
	return (mapped_tetrimino);
}



int	mapper(t_tetrimino *list)
{
	int				*mapped_tetrimino;
	int				line;
	static int		map[16];
	static int		side;

	side = 4;
	mapped_tetrimino = map_tetrimino(side, list->shape);
	line = -1;
	while (line++ < side)
	{
		if ((map[line] | mapped_tetrimino[line]) == (map[line] + mapped_tetrimino[line]))
			map[line] = map[line] | mapped_tetrimino[line];
		else
		{
			while (--line >= 0)
				map[line] = map[line] ^ mapped_tetrimino[line];
			mapped_tetrimino = move_tetrimino(mapped_tetrimino, side);
			if (!(mapped_tetrimino))
				return (0);
		}
		if (line == side)
		{
			if (mapper(list->next) == 0)
			{
				while (--line >= 0)
					map[line] = map[line] ^ mapped_tetrimino[line];
				mapped_tetrimino = move_tetrimino(mapped_tetrimino, side);
				if (!mapped_tetrimino)
					return (0);
			}
		}
	}
	//printf("%d\n", list->shape);
	return (1);
}