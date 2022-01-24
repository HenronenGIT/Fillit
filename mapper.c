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
//TEMP
#include <stdio.h>

unsigned short	*max_left_shift(unsigned short *shape, int side)
{
	int	i;
	int	max_check;

	max_check = 0;
	i = -1;
	while (++i < side)
	{
		if (shape[i] & 32768)
			max_check = 1;
	}
	if (max_check == 0)
	{
		i = -1;
		while (++i < side)
			shape[i] = shape[i] << 1;
		return (max_left_shift(shape, side));
	}
	return (shape);
}

unsigned short	*move_tetrimino(unsigned short *shape, int side)
{
	int	last;
	int	line;

	last = 0;
	line = 0;
	last = side - 1;
	while (line < side)
	{
		shape[line] = shape[line] >> 1;
		if (shape[line] & (32768 >> side))
		{
			if (shape[last])
			{
				ft_memdel((void *)&shape);
				return (NULL);
			}
			while (line >= 0)
			{
				shape[line] = shape[line] << 1;
				line--;
			}
			while (last > 0)
			{
				shape[last] = 0;
				shape[last] = shape[last] | shape[last - 1];
				last--;
			}
			shape[last] = 0;
			shape = max_left_shift(shape, side);
			break ;
		}
		line++;
	}
	return (shape);
}

int	mapper(t_tetrimino *list, int side)
{
	int						line;
	static unsigned short	map[16];

	line = 0;
	while (list)
	{
		if (((map[line] | list->shape[line]) != (map[line] + list->shape[line])) || line == side)
		{
			if (line == side)
			{
				if (mapper(list->next, side))
					return (1);
			}
			while (--line >= 0)
				map[line] = map[line] ^ list->shape[line];
			list->shape = move_tetrimino(list->shape, side);
			if (list->shape == NULL)
			{
				if (list->order == 0)
					side++;
				list->shape = (unsigned short *)malloc(sizeof(unsigned short) * side);
				ft_bzero(list->shape, side * 2);
				ft_memcpy(list->shape, list->reset, 8);
				if (list->order > 0)
					return (0);
			}
		}
		else
			map[line] = map[line] | list->shape[line];
		line++;
	}
	//print_map(map, side);
	return (1);
}