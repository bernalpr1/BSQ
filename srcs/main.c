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

#include "bsq.h"

static void	ft_free_all(int **grid, t_square *sq)
{
	int	i;

	if (grid && sq)
	{
		i = 0;
		while (i < sq->y)
		{
			if (grid[i])
				free(grid[i]);
			i++;
		}
		free(grid);
	}
	if (sq)
		free(sq);
}

static void	ft_skip_header(int fd)
{
	char	c;

	while (read(fd, &c, 1) == 1)
	{
		if (c == '\n')
			break ;
	}
}

static int	ft_process_file(char *file)
{
	int			fd;
	t_square	*square;
	int			**grid;
	int			max;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	square = ft_getsize(fd);
	close(fd);
	if (!square)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_free_all(NULL, square), 0);
	ft_skip_header(fd);
	grid = ft_init_grid(square);
	if (!grid || !fill_grid(fd, grid, square))
	{
		close(fd);
		return (ft_free_all(grid, square), 0);
	}
	close(fd);
	max = ft_solver(grid, square);
	ft_draw(grid, ft_max_square(grid, square, max), max);
	ft_translater(grid, square);
	return (ft_free_all(grid, square), 1);
}

static int	ft_process_stdin(void)
{
	int			tmp_fd;
	char		buf[1024];
	int			bytes;

	tmp_fd = open(".bsq_tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (tmp_fd < 0)
		return (0);
	bytes = read(0, buf, 1024);
	while (bytes > 0)
	{
		write(tmp_fd, buf, bytes);
		bytes = read(0, buf, 1024);
	}
	close(tmp_fd);
	if (!ft_process_file(".bsq_tmp"))
	{
		unlink(".bsq_tmp");
		return (0);
	}
	unlink(".bsq_tmp");
	return (1);
}

int	main(int ac, char **av)
{
	int	n;

	if (ac == 1)
	{
		if (!ft_process_stdin())
			write(2, "map error\n", 10);
	}
	else
	{
		n = 1;
		while (n < ac)
		{
			if (!ft_process_file(av[n]))
				write(2, "map error\n", 10);
			n++;
			if (n < ac)
				write(1, "\n", 1);
		}
	}
	return (0);
}
