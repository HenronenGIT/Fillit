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

int	mapper(t_tetrimino *list)
{
	int				*mapped_tetrimino;
	int				i;
	int				j;
	int				flag;
	int				count;
	int				last;
	int				square_check;
	static int		map[16];
	static int		square;

	square = 4;
	int k;
	k = 0;

	mapped_tetrimino = map_tetrimino(square, list->shape);
	square_check = 1;
	square_check = square_check << (15 - square);
	i = 16;
	count = 0;
	j = 0;
	// the flag variable can be put in a macro e.g. (1 << i)
	while (j < square)
	{
		while (i-- > (15 - square))
		{
			flag = 1;
			flag = flag << i;
			if ((flag & mapped_tetrimino[j]))
			{
				if (!(map[j] & flag))
					count++;
				else
				{
					j = 0;
					last = square - 1;
					while (j < square)
					{
						mapped_tetrimino[j] = mapped_tetrimino[j] >> 1;
						if (mapped_tetrimino[j] & (32768 >> square))
						{
							if (j == last)
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
							break ;
						}
						j++;
					}
					j = 0;
					i = 16;
					count = 0;
				}
			}
			if (count == 4)
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
		i = 16;
		j++;
	}
	//printf("%d\n", list->shape);
	return (1);
}