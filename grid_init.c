/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berpinhe <berpinhe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 01:27:53 by berpinhe          #+#    #+#             */
/*   Updated: 2026/09/21 01:41:04 by berpinhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	**ft_init_grid(t_square	*square)
{
	int	**grid;
	int	i;

	grid = malloc(sizeof(int *) * square->y);
	if (!grid)
		return (NULL);
	i = 0;
	while (i < square->y)
	{
		grid[i] = malloc(sizeof(int) * square->x);
		if (!grid[i])
		{
			while (--i >= 0)
				free(grid[i]);
			free(grid);
			return (NULL);
		}
		i++;
	}
	return (grid);
}
