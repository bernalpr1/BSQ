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

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_square
{
	int		x;
	int		y;
	char	emp;
	char	obs;
	char	ful;
}	t_square;

typedef struct s_max
{
	int	cv_x;
	int	cv_y;
}	t_max;

int		ft_read_all(int fd, char **buffer, size_t *length);
size_t	ft_parse_map(char *buffer, size_t length, t_square *map);
int		ft_valid_rows(char *buffer, size_t length, t_square *map);
int		**ft_init_grid(t_square *square);
void	fill_grid(char *buffer, int **grid, t_square *map);
int		ft_solver(int **grid, t_square *map);
void	ft_draw(int **grid, t_max ret, int max);
t_max	ft_max_square(int **grid, t_square *map, int max);
void	ft_translater(int **grid, t_square *square);

#endif
