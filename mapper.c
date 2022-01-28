/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:00:45 by hmaronen          #+#    #+#             */
/*   Updated: 2022/01/28 11:00:48 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_to_map(t_tetrimino *list, unsigned short *map)
{
	map[list->line] = map[list->line] | list->shape[0];
	map[list->line + 1] = map[list->line + 1] | list->shape[1];
	map[list->line + 2] = map[list->line + 2] | list->shape[2];
	map[list->line + 3] = map[list->line + 3] | list->shape[3];
}

void	remove_tetrimino(unsigned short *shape, unsigned short *map, int line)
{
	map[line] = map[line] ^ shape[0];
	map[line + 1] = map[line + 1] ^ shape[1];
	map[line + 2] = map[line + 2] ^ shape[2];
	map[line + 3] = map[line + 3] ^ shape[3];
}

void	reset_tetrimino(unsigned short *shape, unsigned short *reset)
{
	shape[0] = reset[0];
	shape[1] = reset[1];
	shape[2] = reset[2];
	shape[3] = reset[3];
}

int	shift_right_check_fit(t_tetrimino *list, int side)
{
	list->shape[0] = list->shape[0] >> 1;
	list->shape[1] = list->shape[1] >> 1;
	list->shape[2] = list->shape[2] >> 1;
	list->shape[3] = list->shape[3] >> 1;
	if (list->shape[0] & 32768 >> side || list->shape[1] & 32768 >> side
		|| list->shape[2] & 32768 >> side || list->shape[3] & 32768 >> side)
	{
		reset_tetrimino(list->shape, list->reset);
		list->line++;
	}
	if ((list->shape[0] && list->line >= side)
		|| (list->shape[1] && list->line + 1 >= side)
		|| (list->shape[2] && list->line + 2 >= side)
		|| (list->shape[3] && list->line + 3 >= side))
	{
		reset_tetrimino(list->shape, list->reset);
		return (0);
	}
	return (1);
}

int	mapper(t_tetrimino *list, int side)
{
	static unsigned short	map[16];

	while (list)
	{
		if (((map[list->line] & list->shape[0]) == 0)
			&& ((map[list->line + 1] & list->shape[1]) == 0)
			&& ((map[list->line + 2] & list->shape[2]) == 0)
			&& ((map[list->line + 3] & list->shape[3]) == 0))
		{
			put_to_map(list, map);
			if (mapper(list->next, side))
				return (side);
			remove_tetrimino(list->shape, map, list->line);
		}
		if (shift_right_check_fit(list, side) == 0)
		{
			list->line = 0;
			if (list->order > 0)
				return (0);
			side++;
		}
	}
	return (side);
}
