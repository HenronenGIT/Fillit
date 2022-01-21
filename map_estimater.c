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
//TEMP
#include <math.h>
//TEMP
#include <stdio.h>
//TEMP

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
	int			multiplication;
	t_tetrimino	*temp_ptr;

	piece_count = 0;
	temp_ptr = list;
	piece_count = 0;
	multiplication = 0;
	while (temp_ptr->next)
		temp_ptr = temp_ptr->next;
	piece_count = (temp_ptr->order + 1);
	multiplication = (piece_count * 4);
	printf("square root of multiplication: %f\n", sqrt(multiplication));
	printf("square root of ft_sqrt: %d\n", ft_sqrt(multiplication));
	return (sqrt(multiplication));
}
