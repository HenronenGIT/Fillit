/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:39:47 by hmaronen          #+#    #+#             */
/*   Updated: 2022/01/11 15:39:49 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Decimal to binary convertor */

void	ft_dtob(unsigned short nb)
{	
	size_t	i;
	int	b[15];

	i = 0;
	while (i != 16)
	{
		b[i] = (nb % 2);
		nb = nb / 2;
		i++;
	}
	while (i-- != 0)
		ft_putnbr(b[i]);
}
