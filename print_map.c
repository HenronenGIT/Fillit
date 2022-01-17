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

void	print_map(int nb, int side)
{
	int	i;
	int	map[32];

	i = 0;	
	while (nb != 0) 
	{
		map[i] = nb % 2;
		nb = nb / 2;
		i++;
	}
	while (i > 0)
	{
		i--;
		ft_putnbr(map[i]);
		if ((i % side) == 0)
			ft_putchar('\n');
	}
}
