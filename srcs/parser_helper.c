/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacarva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 01:43:24 by joacarva          #+#    #+#             */

/* ************************************************************************** */
#include "../includes/bsq.h"

int	ft_valid_rows(char *buffer, size_t length, t_square *map)
{
	size_t	i;
	size_t	stride;
	size_t	total;
	int		x;

	stride = (size_t)map->x + 1;
	total = length + (length > 0 && buffer[length - 1] != '\n');
	if (total / stride != (size_t)map->y || total % stride != 0)
		return (0);
	i = 0;
	while (i < length)
	{
		x = map->x;
		while (x-- > 0)
		{
			if (buffer[i] != map->emp && buffer[i] != map->obs)
				return (0);
			i++;
		}
		if (i < length && buffer[i++] != '\n')
			return (0);
	}
	return (1);
}

void	fill_grid(char *buffer, int **grid, t_square *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
			grid[y][x++] = (*buffer++ == map->emp);
		y++;
		if (y < map->y)
			buffer++;
	}
}

static int	ft_grow_buffer(char **buffer, size_t *capacity)
{
	char	*next;
	size_t	i;

	if (*capacity > (size_t)-1 / 2)
		return (0);
	next = malloc(*capacity * 2);
	if (!next)
		return (0);
	i = 0;
	while (i < *capacity)
	{
		next[i] = (*buffer)[i];
		i++;
	}
	free(*buffer);
	*buffer = next;
	*capacity *= 2;
	return (1);
}

int	ft_read_all(int fd, char **buffer, size_t *length)
{
	size_t	capacity;
	ssize_t	bytes;

	capacity = 4096;
	*length = 0;
	*buffer = malloc(capacity);
	if (!*buffer)
		return (0);
	while (1)
	{
		if (*length == capacity && !ft_grow_buffer(buffer, &capacity))
			return (free(*buffer), 0);
		bytes = read(fd, *buffer + *length, capacity - *length);
		if (bytes < 0)
			return (free(*buffer), 0);
		if (bytes == 0)
			return (1);
		*length += bytes;
	}
}
