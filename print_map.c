/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:08:46 by hmaronen          #+#    #+#             */
/*   Updated: 2022/01/14 14:08:48 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "../libft/includes/libft.h"
#include <stdio.h>

void	print_map(int *map, int side)
{
	int	i;
	int	j;
	int	bin[16];

	i = 0;
	j = -1;
	while (++j != side)
	{
		if (*map == 0)
			printf("000000000000000\n");
		else
		{
			while (*map != 0)
			{
				bin[i] = *map % 2;
				*map = *map / 2;
				i++;
			}
			while (--i != 0)
				ft_putnbr(bin[i]);
			ft_putchar('\n');
		}
		map++;
	}
}
