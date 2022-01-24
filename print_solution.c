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
//add to libft
char	**ft_arrnew(size_t str, size_t str_len)
{
	char 	**arr;
	int		i;

	i = -1;
	arr = (char**)malloc(sizeof(char *) * (str + 1));
	if (!arr)
		return (NULL);
	arr[str] = NULL;
	while (++i != (int)str)
	{
		arr[i] = ft_strnew(str_len);
		//malloc protect
		ft_bzero(arr[i], str_len);
	}
	return (arr);
}

int	print_solution(t_tetrimino *list, int side)
{
	//WHY NOT WORK?
	//char		str[side + 1][side + 1];
	//str[side][0] = '\0';

	char		**str;
	char		letter;
	int			line;
	int			bit_index;
	int			str_index;
	int 		i;

	//combine str_indexes?
	str_index = -1;
	bit_index = 16;
	line = -1;
	i = -1;
	str = ft_arrnew(side, side);
	//malloc protect
	while (++i != (int)side)
		ft_bdot((char *)str[i], side);
	while (list)
	{
		letter = 'A' + list->order;
		while (++line != side)
		{
			while (++str_index != side && --bit_index)
			{
				if (list->shape[line] & (1 << bit_index))
					str[line][str_index] = letter;
			}
			str_index = -1;
			bit_index = 16;
		}
		line = -1;
		list = list->next;
	}
	ft_print_array(str);
	return (1);
}
