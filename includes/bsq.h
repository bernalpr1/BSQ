/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berpinhe <berpinhe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 00:14:50 by berpinhe          #+#    #+#             */
/*   Updated: 2026/09/22 12:27:53 by berpinhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef	struct s_square
{
	int	x;
	int	y;
	char	emp;
	char	obs;
	char 	ful;
}	t_square;

typedef struct s_max
{
	int	cv_x;
	int	cv_y;
}	t_max;

t_square	*ft_getsize(int fd);
int	**ft_init_grid(t_square	*square);
int	ft_atoi(char *str);
int fill_grid(int fd, int **grid, t_square *map);
int	ft_solver(int **grid, t_square *map);
void    ft_draw(int     **grid, t_max ret, int max);
t_max   ft_max_square(int **grid, t_square *map, int max);
void    ft_translater(int **grid, t_square *square);

#endif
