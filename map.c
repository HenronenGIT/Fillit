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

int	*map_tetrimino(int square, unsigned short shape)
{
	int				*mapped_tetrimino;
	int				i;
	int				j;
	int				flag;

	mapped_tetrimino = (int *)malloc(sizeof(int) * square);
	i = 0;

	while (i < square)
	{
		mapped_tetrimino[i] = 0;
		i++;
	}
	i = 16;
	j = 0;
	while (i-- >= 0)
	{
		flag = 1;
		flag = flag << i;
		if (shape & flag)
		{
			mapped_tetrimino[j] = mapped_tetrimino[j] | flag;
		}
		if (i % 4 == 0)
			j++;
	}
	return (mapped_tetrimino);
}

int	*create_map(int square)
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
}

int	map(t_tetrimino *list)
{
	int			*map;
	int			*mapped_tetrimino;
	static int	square;

	square = 4;
	map = create_map(square);
	mapped_tetrimino = map_tetrimino(square, list->shape);
	//printf("%d\n", list->shape);
	return (1);
}