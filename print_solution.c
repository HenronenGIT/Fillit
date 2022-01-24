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

	i = -1;
	while (++i != n)
		((char *)s)[i] = '.';
}
//add to libft
char	**ft_arrnew(size_t str, size_t str_len)
{
	char	**arr;
	int		i;

	i = -1;
	arr = (char **)malloc(sizeof(char *) * (str + 1));
	if (!arr)
		return (NULL);
	arr[str] = NULL;
	while (++i != (int)str)
	{
		arr[i] = ft_strnew(str_len);
		if (!arr[i])
			return (NULL);
		ft_bzero(arr[i], str_len);
	}
	return (arr);
}

int	print_solution(t_tetrimino *list, int side)
{
	char	**str;
	int		line;
	int		bit_index;
	int		str_index;
	int		i;

	str_index = -1;
	bit_index = 16;
	line = -1;
	i = -1;
	str = ft_arrnew(side, side);
	if (!str)
		return (0);
	while (++i != side)
		ft_bdot((char *)str[i], side);
	while (list)
	{
		while (++line != side)
		{
			while (++str_index != side && --bit_index)
			{
				if (list->shape[line] & (1 << bit_index))
					str[line][str_index] = 'A' + list->order;
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
