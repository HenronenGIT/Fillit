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
#include <stdio.h>
//TEMP
#include <stdio.h>
//TEMP
void	print_map(unsigned short *map, int side)
{
	int	i;
	int	j;
	int	k;
	int	bin[16];
	unsigned short	map_cpy;

	i = 0;
	j = -1;
	k = 0;
	while (++j != side)
	{
		map_cpy = map[k];
		if (map_cpy == 0)
			printf("000000000000000\n");
		else
		{
			while(map_cpy != 0)
			{
				bin[i] = map_cpy % 2;
				map_cpy = map_cpy / 2;
				i++;
			}
			while (--i != 0)
				ft_putnbr(bin[i]);
				ft_putchar('\n');
		}
		k++;
	}
	ft_putchar('\n');
}