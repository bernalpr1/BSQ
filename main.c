/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berpinhe <berpinhe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 02:06:39 by berpinhe          #+#    #+#             */
/*   Updated: 2026/09/21 04:53:14 by berpinhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int		**grid;
	t_square	*square;
	int		fd;
	char	c;
	int	max;
	t_max	ret;
	int	n;
	int i;

	n = 1;
    i = 0;
	while (n < ac)
	{
		fd = open(av[n], O_RDONLY);
		square = ft_getsize(av[n]);
		grid = ft_init_grid(square);
		while (read(fd, &c, 1) == 1)
		{
			if (c == '\n')
				break;
		}
		if (!fill_grid(fd, grid, square))
		{
			return (1);
		}
		max = ft_solver(grid, square);
		ret = ft_max_square(grid, square, max);
		ft_draw(grid, ret, max);
		ft_translater(grid, square);
		n++;
		if (n < ac)
			write(1, "\n", 1);
		free(square);
		while (i < square->y)
		{
			free(grid[i]);
			i++;
		}
		free(grid);
		close(fd);
	}
	return (0);
}
