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

t_tetrimino	*free_line(char **line)
{
	if (line != NULL)
		ft_strdel(line);
	return (NULL);
}

t_tetrimino	*save_tetrimino(unsigned short tetrimino)
{
	static t_tetrimino	*list;
	t_tetrimino			*new;
	t_tetrimino			*temp;

	if (list == NULL)
	{
		list = (t_tetrimino *)malloc(sizeof(t_tetrimino));
		list->value = tetrimino;
		list->line = 0;
		list->next = NULL;
	}
	else
	{
		new = (t_tetrimino *)malloc(sizeof(t_tetrimino));
		new->value = tetrimino;
		list->line = 0;
		temp = list;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->next = NULL;
	}
	return (list);
}

t_tetrimino	*valid_tetrimino(unsigned short tetrimino)
{
	if (tetrimino == 0)
		return (NULL);
	while (!(tetrimino & TOP_ALL))
		tetrimino = tetrimino << 4;
	while (!(tetrimino & LEFT_ALL))
		tetrimino = tetrimino << 1;
	if (tetrimino == LEFT_ALL || tetrimino == TOP_ALL || tetrimino == SQUARE
		|| tetrimino == S_NORM || tetrimino == S_NORM_R || tetrimino == S_MIR
		|| tetrimino == S_OPP_R || tetrimino == L_MIR || tetrimino == L_R
		|| tetrimino == L_UP || tetrimino == L_MIR_L || tetrimino == L_NORM
		|| tetrimino == L_MIR_R || tetrimino == L_MIR_UP || tetrimino == L_L
		|| tetrimino == T_NORM || tetrimino == T_R || tetrimino == T_UP
		|| tetrimino == T_L)
		return (save_tetrimino(tetrimino));
	return (NULL);
}

int	line_check(char *line, int line_counter)
{
	int				count;
	static int		input;

	if (line_counter == 4)
	{
		if (line == NULL || *line == '\0')
			return (input);
		return (0);
	}
	if (ft_strlen(line) != 5)
		return (0);
	if (line_counter == 0)
		input = 0;
	count = -1;
	while (line[++count] != '\n')
	{
		if (line[count] != '#' && line[count] != '.' && line[count] != '\n')
			return (0);
		else if (line[count] == '#')
			input = input | 1 << (15 - 4 * line_counter - count);
	}
	return (1);
}

t_tetrimino	*tetrimino_check(const int fd)
{
	char		*line;
	int			line_counter;
	t_tetrimino	*list;

	line_counter = 0;
	line = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if (line_counter == 4)
		{
			list = valid_tetrimino(line_check(line, line_counter));
			if (!(list))
				return (free_line(&line));
			line_counter = 0;
		}
		else
		{
			if (!line_check(line, line_counter))
				return (free_line(&line));
			line_counter++;
		}
		ft_strdel(&line);
	}
	if (line_counter != 4)
		return (free_line(&line));
	return (valid_tetrimino(line_check(line, line_counter)));
}
