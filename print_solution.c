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
#include <stdio.h>//temp

void	ft_bdot(void *s, int n)
{
	int	i;

	i = 0;
	while (i != n)
	{
		((char *)s)[i] = '.';
		i++;
	}
}

void	print_solution(t_tetrimino *list, int side)
{
	//WHY NOT WORK?
	//char		str[side + 1][side + 1];
	//str[side][0] = '\0';

	char		**str;
	char		letter;
	int			line;
	int			bit_index;
	int			str_index;

	str = (char **)malloc((sizeof(char *) * side) + 1);
	str[side] = NULL;
	//function to allocate 2D array "ft_strnew2d"
	int i;
	i = 0;
	while (i != side)
	{
		str[i] = ft_strnew(side);
		ft_bdot((char *)str[i], side);
		i++;
	}

	str_index = -1;
	bit_index = 16;
	line = -1;
	while (list)
	{
		letter = 'A' + list->order;
		while (++line != side)
		{
			//while (str_index != side && bit_index)
			while (++str_index != side && --bit_index)
			{
				if (list->shape[line] & (1 << bit_index))
					str[line][str_index] = letter;

				//could add to while loop () with &&
				//bit_index--;
				//str_index++;
			}
			str_index = -1;
			bit_index = 16;
			//line++;
		}
		line = -1;
		list = list->next;
	}

	ft_print_array(str);
}