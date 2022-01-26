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
	int	prev_top;

	j = side - 1;
	while (j >= 0)
	{
		if (list->shape[j])
		{
			prev_top = j;
			list->shape[j] = 0;
		}
		j--;
	}
	while (++j < 4 && ++prev_top)
	{
		if (list->reset[j])
			list->shape[prev_top] = list->shape[prev_top] | list->reset[j];
	}
}

void	move_tetrimino(t_tetrimino *list, int side)
{
	int	j;
	int	last;
	int	eol;
	int	eom;

	j = -1;
	last = side - 1;
	eol = 0;
	eom = 0;
	while (++j < side)
	{
		if (list->shape[j] && (list->shape[j] & (32768 >> last)))
			eol = 1;
		if (eol && list->shape[last])
			eom = 1;
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
	int						temp;
	static unsigned short	map[16];

	line = 0;
	temp = 0;
	while (list)
	{
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
				list->shape = (unsigned short *)malloc(2 * side);
				while (++line < side)
					list->shape[line] = 0;
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
	return (side);
}
