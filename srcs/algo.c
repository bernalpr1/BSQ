/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacarva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 03:46:20 by joacarva          #+#    #+#             */
/*   Updated: 2026/09/21 05:23:12 by berpinhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int get_max(int **grid,	int x, int y)
{
	int min;
	
	min = grid[y][x - 1];
	if (min > grid[y - 1][x])
		min = grid[y - 1][x];
	if (min > grid[y - 1][x - 1])
		min = grid[y - 1][x - 1];

	return (min);
}

int	ft_solver(int **grid, t_square *map)
{
	int i;
	int j;
	int max;
	
	max = 1;
	i = 0;
	while (++i < map->y)
	{
		j = 0;
		while (++j < map->x)
		{
			if (grid[i][j] == 1)
			{
				grid[i][j] = get_max(grid, j, i) + 1;
				if (max < grid[i][j])
					max = grid[i][j];
			}
		}
	}
	return (max);
}

t_max	ft_max_square(int **grid, t_square *map, int max)
{
	int i;
	int j;
	
	t_max	ret;
	ret.cv_x = -1;
	ret.cv_y = -1;
	i = -1;
	while (++i < map->y)
	{
		j = -1;
		while (++j < map->x)
		{
			if (grid[i][j] == max)
			{
				ret.cv_y = i;
				ret.cv_x = j;
				return (ret);
			}	
		}
	}
	return (ret);
}

void	ft_draw(int	**grid, t_max ret, int max)
{
	int	i;
	int	j;

	i = -1;
	if (ret.cv_x == -1)
		return ;
	while (++i < max)
	{
		j = -1;
		while (++j < max)
			grid[ret.cv_y - i][ret.cv_x - j] = -1;
	}
}
