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

/*int	*create_map(int side_side)
{
	int	*map;
	int	i;

	map = (int *)malloc(sizeof(int) * side_side);
	i = 0;
	while (i < side_side)
	{
		map[i] = 0;
		i++;
	}
	return (map);
}*/

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

int	mapper(t_tetrimino *list)
{
	int				*mapped_tetrimino;
	int				j;
	int				count;
	int				last;
	int				square_side_check;
	static int		map[16];
	static int		side;

	side = 4;
	mapped_tetrimino = map_tetrimino(side, list->shape);
	square_side_check = 1;
	square_side_check = square_side_check << (15 - side);
	count = 0;
	j = 0;
	// the flag variable can be put in a macro e.g. (1 << i)
	while (j < side)
	{
		if ((map[j] | mapped_tetrimino[j]) == (map[j] + mapped_tetrimino[j]))
		{
			count++;
			j++;
		}
		else
		{
			j = 0;
			last = side - 1;
			while (j < side)
			{
				mapped_tetrimino[j] = mapped_tetrimino[j] >> 1;
				if (mapped_tetrimino[j] & (32768 >> side))
				{
					if (mapped_tetrimino[last])
					{
						//map[j] = map[j] ^ (mapped_tetrimino[j] << 1);
						return (0);
					}
					while (j >= 0)
					{
						mapped_tetrimino[j] = mapped_tetrimino[j] << 1;
						j--;
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
				j++;
			}
			j = 0;
			count = 0;
		}
		if (count == side)
		{
			j = 0;
			while (j < side)
			{
				map[j] = map[j] | mapped_tetrimino[j];
				j++;
			}
			if (mapper(list->next) == 0)
			{
				j = 0;
				while (j < side)
				{
					map[j] = map[j] ^ mapped_tetrimino[j];
					j++;
				}
			}
		}
	}
	//printf("%d\n", list->shape);
	return (1);
}