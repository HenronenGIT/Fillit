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
int	*map_tetrimino(int square_side, unsigned short shape)
{
	int				*mapped_tetrimino;
	int				i;
	int				j;
	int				offset;
	int				flag;

	mapped_tetrimino = (int *)malloc(sizeof(int) * square_side);
	i = 0;
	while (i < square_side)
	{
		mapped_tetrimino[i] = 0;
		i++;
	}
	offset = 0;
	j = 0;
	i = 15;
	while (j < square_side)
	{
		flag = 1;
		flag = flag << i;

		if (shape & flag)
			mapped_tetrimino[j] = mapped_tetrimino[j] | (flag << offset);
		if (i % square_side == 0)
		{
			//dtob(mapped_tetrimino[j]);
			offset += 4;
			j++;
		}
		i--;
	}
	return (mapped_tetrimino);
}

/*int	*create_map(int square_side)
{
	int	*map;
	int	i;

	map = (int *)malloc(sizeof(int) * square_side);
	i = 0;
	while (i < square_side)
	{
		map[i] = 0;
		i++;
	}
	return (map);
}*/

int	mapper(t_tetrimino *list)
{
	int				*mapped_tetrimino;
	int				i;
	int				j;
	int				flag;
	int				count;
	int				last;
	int				square_side_check;
	static int		map[16];
	static int		square_side;

	square_side = 4;
	int k;
	k = 0;

	mapped_tetrimino = map_tetrimino(square_side, list->shape);
	square_side_check = 1;
	square_side_check = square_side_check << (15 - square_side);
	i = 16;
	count = 0;
	j = 0;
	// the flag variable can be put in a macro e.g. (1 << i)
	while (j < square_side)
	{
		while (i-- > (15 - square_side))
		{
			flag = 1;
			flag = flag << i;
			//if mapped_tetrimino contains bit
			if ((flag & mapped_tetrimino[j]))
			{
				if (!(map[j] & flag))
					count++;
				else
				{
					j = 0;
					last = square_side - 1;
					if (mapped_tetrimino[j] & (1 << (12 - j * square_side)))
					{
						while (last > 0)
						{
							mapped_tetrimino[last] = mapped_tetrimino[last] | mapped_tetrimino[last - 1];
							// KESKEN
						}
					}
					else
					{
						while (j < square_side)
						{
							mapped_tetrimino[j] = mapped_tetrimino[j] >> 1;
							j++;
						}
					}
					j = 0;
					i = 16;
					count = 0;
				}
			}
			if (count == 4)
			{
				j = 0;
				while (j < square_side)
				{
					map[j] = map[j] | mapped_tetrimino[j];
					j++;
				}
				mapper(list->next);
			}
		}
		i = 16;
		j++;
	}
	//printf("%d\n", list->shape);
	return (1);
}