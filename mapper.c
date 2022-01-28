/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:47:33 by hmaronen          #+#    #+#             */
/*   Updated: 2022/01/28 10:47:34 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_to_map(t_tetrimino *list, unsigned short *map, int line)
{
	map[line] = map[line] | list->shape[0];
	map[line + 1] = map[line + 1] | list->shape[1];
	map[line + 2] = map[line + 2] | list->shape[2];
	map[line + 3] = map[line + 3] | list->shape[3];
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

int shift_right_check_fit(t_tetrimino *list, int side, int line)
{
	list->shape[0] = list->shape[0] >> 1;
	list->shape[1] = list->shape[1] >> 1;
	list->shape[2] = list->shape[2] >> 1;
	list->shape[3] = list->shape[3] >> 1;
	if (list->shape[0] & 32768 >> side || list->shape[1] & 32768 >> side
		|| list->shape[2] & 32768 >> side || list->shape[3] & 32768 >> side)
	{
		reset_tetrimino(list->shape, list->reset);
		line++;
	}
	if ((list->shape[0] && line >= side)
		|| (list->shape[1] && line + 1 >= side)
		|| (list->shape[2] && line + 2 >= side)
		|| (list->shape[3] && line + 3 >= side))
	{
		reset_tetrimino(list->shape, list->reset);
		return (-1);
	}
	return (line);
}

int	mapper(t_tetrimino *list, int side)
{
	int						line;
	static unsigned short	map[16];

	line = 0;
	while (list)
	{
		if (list == NULL)
			return (side);
		if (((map[line] & list->shape[0]) == 0)
			&& ((map[line + 1] & list->shape[1]) == 0)
			&& ((map[line + 2] & list->shape[2]) == 0)
			&& ((map[line + 3] & list->shape[3]) == 0))
		{
			put_to_map(list, map, line);
			if (mapper(list->next, side))
			{
				list->line = line;
				return (side);
			}
			remove_tetrimino(list->shape, map, line);
		}
		line = shift_right_check_fit(list, side, line);
		if (line == -1)
		{
			if (list->order > 0)
				return (0);
			line = 0;
			side++;
		}
	}
	return (side);
}
