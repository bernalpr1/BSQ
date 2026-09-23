/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berpinhe <berpinhe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 02:06:39 by berpinhe          #+#    #+#             */
/*   Updated: 2026/09/22 12:36:32 by berpinhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

static void	ft_free_grid(int **grid, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(grid[i++]);
	free(grid);
}

static int	ft_process_map(char *buffer, size_t length)
{
	t_square	map;
	int			**grid;
	size_t		offset;
	int			max;

	offset = ft_parse_map(buffer, length, &map);
	if (!offset)
		return (0);
	grid = ft_init_grid(&map);
	if (!grid)
		return (0);
	fill_grid(buffer + offset, grid, &map);
	max = ft_solver(grid, &map);
	ft_draw(grid, ft_max_square(grid, &map, max), max);
	ft_translater(grid, &map);
	ft_free_grid(grid, map.y);
	return (1);
}

static int	ft_process_fd(int fd)
{
	char	*buffer;
	size_t	length;
	int		result;

	if (!ft_read_all(fd, &buffer, &length))
		return (0);
	result = ft_process_map(buffer, length);
	free(buffer);
	return (result);
}

static int	ft_process_file(char *file)
{
	int	fd;
	int	result;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	result = ft_process_fd(fd);
	close(fd);
	return (result);
}

int	main(int ac, char **av)
{
	int	n;

	if (ac == 1)
	{
		if (!ft_process_fd(0))
			write(1, "map error\n", 10);
	}
	else
	{
		n = 1;
		while (n < ac)
		{
			if (!ft_process_file(av[n]))
				write(1, "map error\n", 10);
			n++;
			if (n < ac)
				write(1, "\n", 1);
		}
	}
	return (0);
}
