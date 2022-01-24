/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:36:41 by hmaronen          #+#    #+#             */
/*   Updated: 2021/12/23 15:36:43 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**free_2d_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		ft_memdel((void **)&array[i]);
		i++;
	}
	ft_memdel((void **)array);
	return (NULL);
}
