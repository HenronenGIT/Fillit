#include "fillit.h"
#include <stdio.h>

t_tetrimino	*save_tetrimino(unsigned short tetrimino, int piece_count)
{
	t_tetrimino *new;

	new = (t_tetrimino *)malloc(sizeof(t_tetrimino));
	new->value = tetrimino;
	new->order = piece_count;
	new->shape = NULL;
	new->reset = NULL;
	new->next = NULL;
	return (new);
}

void	list_add_back(t_tetrimino **list, t_tetrimino *new)
{
	t_tetrimino *temp;

	temp = *list;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->next = NULL;
}

t_tetrimino	*valid_tetrimino(unsigned short tetrimino, int piece_count)
{
	static t_tetrimino	*head;
	t_tetrimino			*new;

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
	{
		if (piece_count == 0)
			head = save_tetrimino(tetrimino, piece_count);
		else
		{
			new = save_tetrimino(tetrimino, piece_count);
			list_add_back(&head, new);
		}
		return (head);
	}
	return (NULL);
}

int	line_check(const char *line, int line_counter)
{
	int				count;
	static int		input;

	if (ft_strlen(line) != 4)
		return (-1);
	if (line_counter == 0)
		input = 0;
	count = 0;
	while (*line)
	{
		if (*line != '#' && *line != '.')
			return (0);
		else if (*line == '#')
			input = input | 1 << (15 - 4 * line_counter - count);
		line++;
		count++;
	}
	if (line_counter == 3)
		return (input);
	return (1);
}

// tee line_counter == 4 tsekkaus ja tarvittavat toimenpiteet siihen
t_tetrimino *tetrimino_check(const int fd)
{
	char 		*line;
	int			line_counter;
	int			piece_count;
	t_tetrimino	*list;

	line_counter = 0;
	piece_count = 0;
	while (ft_get_next_line(fd, &line) == 1)
	{
		if (line_counter == 3)
		{
			list = valid_tetrimino(line_check(line, line_counter), piece_count);
			if (!(list))
				return (NULL);
			piece_count++;
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
	return (list);
}