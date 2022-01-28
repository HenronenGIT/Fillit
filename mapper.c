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

int	mapper(t_tetrimino *list, int side)
{
	int						line;
	static unsigned short	map[16];

	line = 0;
	while (list)
	{
		if (((map[line] | list->shape[0]) != (map[line] + list->shape[0]))
			|| ((map[line + 1] | list->shape[1]) != (map[line + 1] + list->shape[1]))
			|| ((map[line + 2] | list->shape[2]) != (map[line + 2] + list->shape[2]))
			|| ((map[line + 3] | list->shape[3]) != (map[line + 3] + list->shape[3])))
		{
			list->shape[0] = list->shape[0] >> 1;
			list->shape[1] = list->shape[1] >> 1;
			list->shape[2] = list->shape[2] >> 1;
			list->shape[3] = list->shape[3] >> 1;
			if (list->shape[0] & LEFTMOST_BIT >> side
				|| list->shape[1] & LEFTMOST_BIT >> side
				|| list->shape[2] & LEFTMOST_BIT >> side
				|| list->shape[3] & LEFTMOST_BIT >> side)
			{
				ft_bzero(list->shape, 8);
				ft_memmove(list->shape, list->reset, 8);
				line++;
			}
		}
		else
		{
			map[line] = map[line] | list->shape[0];
			map[line + 1] = map[line + 1] | list->shape[1];
			map[line + 2] = map[line + 2] | list->shape[2];
			map[line + 3] = map[line + 3] | list->shape[3];
			if (map[side])
			{
				map[line] = map[line] ^ list->shape[0];
				map[line + 1] = map[line + 1] ^ list->shape[1];
				map[line + 2] = map[line + 2] ^ list->shape[2];
				map[line + 3] = map[line + 3] ^ list->shape[3];
				if (list->order == 0)
				{
					ft_bzero(list->shape, 8);
					ft_memmove(list->shape, list->reset, 8);
					side++;
					line = 0;
				}
				else
					return (0);
			}
			else
			{
				if (mapper(list->next, side))
				{
					list->line = line;
					return (side);
				}
				map[line] = map[line] ^ list->shape[0];
				map[line + 1] = map[line + 1] ^ list->shape[1];
				map[line + 2] = map[line + 2] ^ list->shape[2];
				map[line + 3] = map[line + 3] ^ list->shape[3];
				list->shape[0] = list->shape[0] >> 1;
				list->shape[1] = list->shape[1] >> 1;
				list->shape[2] = list->shape[2] >> 1;
				list->shape[3] = list->shape[3] >> 1;
				if (list->shape[0] & LEFTMOST_BIT >> side
					|| list->shape[1] & LEFTMOST_BIT >> side
					|| list->shape[2] & LEFTMOST_BIT >> side
					|| list->shape[3] & LEFTMOST_BIT >> side)
				{
					ft_bzero(list->shape, 8);
					ft_memmove(list->shape, list->reset, 8);
					line++;
				}
			}
		}
	}
	return (side);
}
