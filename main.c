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
	char			*line;
	int				fd;
	int				counter;
	int				count;
	unsigned int	flag;
	unsigned short	tetrimino;

	
	if (argc != 2)
		return (error_handler(1));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() error in main\n");
		return (0);
	}
	tetrimino = 0;
	counter = 1;
	count = 0;
	while ((ft_get_next_line(fd, &line) == 1))
	{
		if (counter > 4)
			return (error_handler(2));
		if (ft_strlen(line) != 4)
			return (error_handler(2));
		while (*line)
		{
			printf("count = %d\n", count);
			if (*line != '#' && *line != '.')
				return(error_handler(2));
			else if (*line == '#')
			{
				flag = 1;
				flag = flag << (15 - count);
				tetrimino = tetrimino | flag;
				printf("%d\n", tetrimino);
			}
			line++;
			count++;
		}
		if (counter == 4)
		{
			printf("tetrimino read\n");
			while (!(tetrimino & 61440) && !(tetrimino & 34952))
				tetrimino = tetrimino << 1;
			printf("%d\n", tetrimino);
		}
		counter++;
	}
	return (0);
}