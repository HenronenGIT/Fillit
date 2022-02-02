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

void	free_list(t_tetrimino **list)
{
	while (*list)
	{
		free(*list);
		*list = (*list)->next;
	}
}

int	error_handler(int nb, t_tetrimino **list)
{
	if (nb == 1)
		ft_putstr("usage: ./fillit source_file\n");
	if (nb == 2)
		ft_putstr("error\n");
	if (list != NULL)
		free_list(list);
	return (-1);
}

int	main(int argc, char **argv)
{
	int				fd;
	int				side;
	t_tetrimino		*list;

	if (argc != 2)
		return (error_handler(1, NULL));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (error_handler(2, NULL));
	if (!(tetrimino_check(fd, &list)))
		return (error_handler(2, &list));
	side = map_estimater(list);
	if (!side)
		return (error_handler(2, &list));
	side = mapper(list, side);
	if (!print_solution(list, side))
		return (error_handler(2, &list));
	free_list(&list);
	return (0);
}
