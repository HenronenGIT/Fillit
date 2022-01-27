/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_estimater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:53:31 by hmaronen          #+#    #+#             */
/*   Updated: 2022/01/21 09:53:33 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	set_list(t_tetrimino *list)
{
	int	i;
	int	j;
	int	offset;

	while (list)
	{
		list->shape = (unsigned short *)malloc(sizeof(unsigned short) * 4);
		ft_bzero(list->shape, 8);
		offset = 0;
		i = 16;
		j = 0;
		while (j < 4 && --i)
		{
			if (list->value & (1 << i))
				list->shape[j] = list->shape[j] | (1 << i) << offset;
			if (i % 4 == 0)
				offset += 4;
			if (i % 4 == 0)
				j++;
		}
		list->reset = (unsigned short *)malloc(sizeof(unsigned short) * 4);
		ft_bzero(list->reset, 8);
		ft_memmove(list->reset, list->shape, sizeof(list->shape));
		list = list->next;
	}
}

int	ft_sqrt(int nb)
{
	int	odd_nbr;
	int	sqr_root;

	sqr_root = 0;
	odd_nbr = 1;
	while (nb > 0)
	{
		nb = nb - odd_nbr;
		odd_nbr = odd_nbr + 2;
		sqr_root++;
	}
	return (sqr_root);
}

int	map_estimater(t_tetrimino *list)
{
	int			piece_count;
	int			side;
	int			multiplication;
	int			check;
	t_tetrimino	*head;

	piece_count = 0;
	head = list;
	piece_count = 0;
	multiplication = 0;
	check = 0;
	while (list)
	{
		if (list->value == 61440 || list->value == 34952)
			check = 1;
		list->order = piece_count;
		list = list->next;
		piece_count++;
	}
	multiplication = (piece_count * 4);
	side = ft_sqrt(multiplication);
	if (piece_count < 3 && check == 1)
		side = 4;
	set_list(head);
	return (side);
}
