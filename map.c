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
int	*map_tetrimino(int square, unsigned short shape)
{
	int				*mapped_tetrimino;
	int				i;
	int				j;
	int				offset;
	int				flag;

	mapped_tetrimino = (int *)malloc(sizeof(int) * square);
	i = 0;
	while (i < square)
	{
		mapped_tetrimino[i] = 0;
		i++;
	}
	offset = 0;
	j = 0;
	i = 15;
	while (j < square)
	{
		flag = 1;
		flag = flag << i;
		//1000 0000 0000 0000
		//2 line flag = 0001 0000 0000 0000
		//	shape = 	1100 1100 0000 0000
		//
		//	flag = 		0000 1000 0000 0000
		// shape = 		1100 1100 0000 0000
		// line[1]	 =  	 1000 0000 0000
		//
		//	flag = 		0000 0100 0000 0000
		//	line[2] = 	0000 1100 0000 0000

		if (shape & flag)
			mapped_tetrimino[j] = mapped_tetrimino[j] | (flag << offset);
		if (i % square == 0)
		{
			//dtob(mapped_tetrimino[j]);
			offset += 4;
			j++;
		}
		i--;
	}
	return (mapped_tetrimino);
}

/*int	*create_map(int square)
{
	int	*map;
	int	i;

	map = (int *)malloc(sizeof(int) * square);
	i = 0;
	while (i < square)
	{
		map[i] = 0;
		i++;
	}
	return (map);
}*/

int	*max_left_shift(int *mapped_tetrimino, int square)
{
	int	i;
	int	max_check;

	max_check = 0;
	i = 0;
	while (i < square)
	{
		if (mapped_tetrimino[i] & 32768)
			max_check = 1;
		i++;
	}
	if (max_check == 0)
	{
		i = 0;
		while (i < square)
		{
			mapped_tetrimino[i] = mapped_tetrimino[i] << 1;
			i++;
		}
		return (max_left_shift(mapped_tetrimino, square));
	}
	return (mapped_tetrimino);
}

int	mapper(t_tetrimino *list)
{
	int				*mapped_tetrimino;
	int				j;
	int				count;
	int				last;
	int				square_check;
	static int		map[16];
	static int		square;

	square = 4;
	mapped_tetrimino = map_tetrimino(square, list->shape);
	square_check = 1;
	square_check = square_check << (15 - square);
	count = 0;
	j = 0;
	// the flag variable can be put in a macro e.g. (1 << i)
	while (j < square)
	{
		if ((map[j] | mapped_tetrimino[j]) == (map[j] + mapped_tetrimino[j]))
		{
			count++;
			j++;
		}
		else
		{
			j = 0;
			last = square - 1;
			while (j < square)
			{
				mapped_tetrimino[j] = mapped_tetrimino[j] >> 1;
				if (mapped_tetrimino[j] & (32768 >> square))
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
					mapped_tetrimino = max_left_shift(mapped_tetrimino, square);
					break ;
				}
				j++;
			}
			j = 0;
			count = 0;
		}
		if (count == square)
		{
			j = 0;
			while (j < square)
			{
				map[j] = map[j] | mapped_tetrimino[j];
				j++;
			}
			if (mapper(list->next) == 0)
			{
				j = 0;
				while (j < square)
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