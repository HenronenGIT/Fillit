/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:59:09 by hmaronen          #+#    #+#             */
/*   Updated: 2022/01/10 10:59:11 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	error_handler(int nb)
{
	if (nb == 1)
		ft_putstr("usage: ./fillit source_file\n");
	if (nb == 2)
		ft_putstr("error\n");
	return (-1);
}

int	main(int argc, char **argv)
{
	int				fd;
	t_tetrimino		*list;
	
	if (argc != 2)
		return (error_handler(1));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() error in main\n");
		return (0);
	}
	list = tetrimino_check(fd);
	if (!(list))
		return (error_handler(2));
	//system("leaks fillit");
	return (0);
}