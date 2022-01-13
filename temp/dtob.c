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

void	ft_dtob(int nb)
{
	int	b[16];
	size_t	i;
	int	quotient;

	quotient = 0;
	i = 0;
	remain = 0;
	while ((quotient = nb / 2) != 0)
	{
		bin[i] = (nb % 2);
		i++;
	}
}

int	main(void)
{
	size_t	i;
	int arr[] = {
		1,
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
