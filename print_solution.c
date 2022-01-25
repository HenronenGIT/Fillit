/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:43:53 by hmaronen          #+#    #+#             */
/*   Updated: 2022/01/21 14:43:54 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static void	ft_bdot(void *s, int n)
{
	int	i;

	i = -1;
	while (++i != n)
		((char *)s)[i] = '.';
}

static int	allocate_map(char ***char_map, int line_count, int line_len)
{
	int		i;

	i = -1;
	*char_map = ft_arrnew(line_count, line_len);
	if (!char_map)
		return (-1);
	while (++i != line_count)
		ft_bdot((char *)*char_map[i], line_count);
	return (1);
}

int	print_solution(t_tetrimino *list, int side)
{
	char	**map;
	int		line;
	int		bit_index;
	int		char_index;

	//map = allocate_map(side, side);
	//if (!map)
	//	return (-1);

	if (!allocate_map(&map, side, side))
		return (-1);
	while (list)
	{
		line = -1;
		while (++line != side)
		{
			char_index = -1;
			bit_index = 16;
			while (++char_index != side && --bit_index)
			{
				if (list->shape[line] & (1 << (bit_index)))
					map[line][char_index] = 'A' + list->order;
			}
		}
		list = list->next;
	}
	ft_print_array(map);
	ft_free_2d_array(map);
	return (1);
}
