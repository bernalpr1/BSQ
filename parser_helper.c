/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacarva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 01:43:24 by joacarva          #+#    #+#             */

/* ************************************************************************** */
#include "bsq.h"

int fill_grid(int fd, int **grid, t_square *map)
{
	int y;
	int x;
	char c;
	
	y = -1;
	while (++y < map->y)
	{
		x = -1;
		while (++x < map->x)
		{
			if (read(fd, &c, 1) != 1)
				return (0);
			if (c == map->emp)
				grid[y][x] = 1;
			else if (c == map->obs)
				grid[y][x] = 0;
		}	
		if (read(fd, &c, 1) != 1 || c != '\n')
				return (0);
	}
	return (1);	
}

int ft_atoi(char *str)
{
	int i;
	int result;
	
	result = 0;
	i = 0;
		
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result);
}

