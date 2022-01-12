/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:04:30 by hmaronen          #+#    #+#             */
/*   Updated: 2022/01/12 13:04:48 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrimino	*valid_tetrimino(unsigned short tetrimino, int piece_count)
{
	t_tetrimino	*piece;

	while (!(tetrimino & left_all))
		tetrimino = tetrimino << 4;
	while (!(tetrimino & top_all))
		tetrimino = tetrimino << 1;
	if (tetrimino == 34952 || tetrimino == 61440 || tetrimino == 52224
	|| tetrimino == 27648 || tetrimino == 35904 || tetrimino == 50688
	|| tetrimino == 19584 || tetrimino == 35008 || tetrimino == 59392
	|| tetrimino == 50240 || tetrimino == 11776 || tetrimino == 17600
	|| tetrimino == 36352 || tetrimino == 51328 || tetrimino == 57856
	|| tetrimino == 58368 || tetrimino == 19520 || tetrimino == 19968
	|| tetrimino == 35968)
	{
		if (piece_count == 0)
		{
			piece = (t_tetrimino *)malloc(sizeof(t_tetrimino));
			piece->shape = tetrimino;
			piece->order = piece_count;
			piece->next = NULL;
		}
		else
		{
			piece = piece->next;
			piece = (t_tetrimino *)malloc(sizeof(t_tetrimino));
			piece->shape = tetrimino;
			piece->order = piece_count;
			piece->next = NULL;
		}
		return (piece);
	}
	return (NULL);
}

unsigned short	save_tetrimino(const char *line)
{
	int				count;
	unsigned int	flag;
	unsigned short	tetrimino;

	count = 0;
	while (*line)
	{
		if (*line != '#' && *line != '.')
			return (-1);
		else if (*line == '#')
		{
			flag = 1;
			flag = flag << (15 - count);
			tetrimino = tetrimino | flag;
		}
		line++;
		count++;
	}
	return (tetrimino);
}

int	tetrimino_check(const int fd)
{
	int				line_counter;
	int				piece_count;
	char			*line;
	unsigned short	tetrimino;
	
	tetrimino = 0;
	line_counter = 1;
	piece_count = 0;
	while ((ft_get_next_line(fd, &line) == 1))
	{
		if (line_counter == 5 && *line == '\0')
			line_counter = 0;
		else
			return (-1);
		if (ft_strlen(line) != 4)
			return (-1);
		tetrimino = save_tetrimino(line);
		if (line_counter == 4)
		{
			if (!valid_tetrimino(tetrimino, piece_count))
				return (-1);
			piece_count++;
		}
		line_counter++;
	}
	return (1);
}