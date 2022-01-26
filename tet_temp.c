#include "fillit.h"
#include <stdio.h>

void	list_add_back(t_tetrimino **list, t_tetrimino *new)
{
	t_tetrimino	*temp;

	temp = *list;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->next = NULL;
}

t_tetrimino	*save_tetrimino(unsigned short tetrimino)
{
	static t_tetrimino	*list;
	t_tetrimino			*new;

	if (list == NULL)
	{
		list = (t_tetrimino *)malloc(sizeof(t_tetrimino));
		list->value = tetrimino;
		list->next = NULL;
	}
	else
	{
		new = (t_tetrimino *)malloc(sizeof(t_tetrimino));
		new->value = tetrimino;
		list_add_back(&list, new);
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
	if (tetrimino == 34952 || tetrimino == 61440 || tetrimino == 52224
		|| tetrimino == 27648 || tetrimino == 35904 || tetrimino == 50688
		|| tetrimino == 19584 || tetrimino == 35008 || tetrimino == 59392
		|| tetrimino == 50240 || tetrimino == 11776 || tetrimino == 17600
		|| tetrimino == 36352 || tetrimino == 51328 || tetrimino == 57856
		|| tetrimino == 58368 || tetrimino == 19520 || tetrimino == 19968
		|| tetrimino == 35968)
		return (save_tetrimino(tetrimino));
	return (NULL);
}

int	line_check(const char *line, int line_counter)
{
	int				count;
	static int		input;

	if (line_counter == 4)
	{
		if (*line != '\0')
			return (0);
		return (input);
	}
	if (ft_strlen(line) != 4)
		return (0);
	if (line_counter == 0)
		input = 0;
	count = 0;
	while (line[count])
	{
		if (line[count] != '#' && line[count] != '.')
			return (0);
		else if (line[count] == '#')
			input = input | 1 << (15 - 4 * line_counter - count);
		count++;
	}
	if (line_counter == 3)
		return (input);
	return (1);
}

t_tetrimino	*tetrimino_check(const int fd)
{
	char		*line;
	int			line_counter;
	t_tetrimino	*list;

	line_counter = 0;
	while (ft_get_next_line(fd, &line) == 1)
	{
		if (line_counter == 4)
		{
			list = valid_tetrimino(line_check(line, line_counter));
			if (!(list))
				return (NULL);
			line_counter = 0;
		}
		else
		{
			if (!line_check(line, line_counter))
				return (NULL);
			line_counter++;
		}
		free(line);
	}
	if (line_counter != 4)
		return (NULL);
	return (valid_tetrimino(line_check(line, line_counter)));
}
