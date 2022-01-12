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

void	ft_dtob(int d)
{
	int	b;
	int	remain;

	while ()
	{

		ft_putnbr(remain = (d % 2));
	}


}

int	main(void)
{
	size_t	i;
	int *arr = {
		1,
		2,
		3,
		10,
		100,
		1000
		0
	};

	i = 0;
	while (arr[i] != 0)
	{
		ft_dtob(arr[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
