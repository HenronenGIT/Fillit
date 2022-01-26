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

int	allocate_map(char ***map, int line_count, int line_len)
{
	int	i;

	i = 0;
	*map = (char **)malloc(sizeof(char *) * line_count + 1);
	if (!(*map))
		return (0);
	//map[line_count] = NULL;
	while (i != line_count)
	{
		(*map)[i] = ft_strnew(line_len);
		if (!(*map)[i])
			return (0);
		ft_bdot((*map)[i], line_len);
		i++;
	}
	return (1);
}

int	print_solution(t_tetrimino *list, int side)
{
	char	**map;
	int		line;
	int		bit_index;
	int		char_index;

	if (!allocate_map(&map, side, side))
		return (0);
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
