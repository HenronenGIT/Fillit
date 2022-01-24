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

void	move_line_down(t_tetrimino *list, int side)
{
	int	j;
	int	previous_top;

	j = side - 1;
	while (j >= 0)
	{
		if (list->shape[j])
		{
			previous_top = j;
			list->shape[j] = 0;
		}
		j--;
	}
	previous_top++;
	while (++j < 4)
	{
		if (list->reset[j])
			list->shape[previous_top] = list->shape[previous_top] | list->reset[j];
		previous_top++;
	}
}

void	move_tetrimino(t_tetrimino *list, int side)
{
	int	j;
	int	last;
	int	eol;
	int	eom;

	j = 0;
	last = side - 1;
	eol = 0;
	eom = 0;
	while (j < side)
	{
		if (list->shape[j] && (list->shape[j] & (32768 >> last)))
			eol = 1;
		if (eol && list->shape[last])
			eom = 1;
		j++;
	}
	if (eom)
		ft_memdel((void *)&list->shape);
	else if (eol)
		move_line_down(list, side);
	else
	{
		while (--j >= 0)
			list->shape[j] = list->shape[j] >> 1;
	}
}

int	mapper(t_tetrimino *list, int side)
{
	int						line;
	int 					temp;
	static unsigned short	map[16];

	line = 0;
	temp = 0;
	while (list)
	{
		if (list->order == 2)
			temp = -1;
		if (((map[line] | list->shape[line]) != (map[line] + list->shape[line]))
		|| (((32768 >> side) & list->shape[line]))
		|| line == side)
		{
			if (line == side)
			{
				if (mapper(list->next, side))
					return (side);
			}
			while (--line >= 0)
				map[line] = map[line] ^ list->shape[line];
			move_tetrimino(list, side);
			if (list->shape == NULL)
			{
				if (list->order == 0)
					side++;
				list->shape = (unsigned short *)malloc(sizeof(unsigned short) * side);
				//ft_bzero(list->shape, side * 2);
				while (++line < side)
					list->shape[line] = 0;
				//ft_memcpy(list->shape, list->reset, 8);
				line = -1;
				while (list->reset[++line])
					list->shape[line] = list->reset[line];
				if (list->order > 0)
					return (0);
				line = -1;
			}
		}
		else
			map[line] = map[line] | list->shape[line];
		line++;
	}
	//print_map(map, side);
	return (side);
}