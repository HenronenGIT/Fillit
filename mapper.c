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
