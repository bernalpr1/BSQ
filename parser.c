/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berpinhe <berpinhe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 00:14:22 by berpinhe          #+#    #+#             */
/*   Updated: 2026/09/21 01:27:38 by berpinhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
//check format of header and put it in buf
int	ft_read_line1(int fd, char *buf)
{
	int		i;
	int		red;
	char	c;

	i = 0;
	red = read(fd, &c, 1);
	while (red > 0 && c != '\n' && i < 14)
	{
		buf[i] = c;
		i++;
		red = read(fd, &c, 1);
	}
	if (red <= 0 || c != '\n' || i < 4)
		return (-1);
	buf[i] = '\0';
	return (i);
}
//fill struct with data to init grid
int	ft_parse_header(t_square *sq, char *buf, int len)
{
	sq->ful = buf[len - 1];
	sq->obs = buf[len - 2];
	sq->emp = buf[len - 3];
	if (sq->emp == sq->obs || sq->emp == sq->ful || sq->obs == sq->ful)
		return (0);
	buf[len - 3] = '\0';
	sq->y = ft_atoi(buf);
	if (sq->y <= 0)
		return (0);
	return (1);
}
//get map witdht
int	ft_get_row_len(int fd)
{
	int		len;
	int		red;
	char	dummy;

	len = 0;
	red = read(fd, &dummy, 1);
	while (red > 0 && dummy != '\n')
	{
		len++;
		red = read(fd, &dummy, 1);
	}
	if (red <= 0 || len == 0)
		return (-1);
	return (len);
}
//free in error
t_square	*ft_clean_exit(int fd, t_square *sq)
{
	if (fd >= 0)
		close(fd);
	if (sq)
		free(sq);
	return (NULL);
}
//mainfunc
t_square	*ft_getsize(char *file_name)
{
	int			fd;
	int			len;
	char		buf[15];
	t_square	*sq;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	sq = (t_square *)malloc(sizeof(t_square));
	if (!sq)
		return (ft_clean_exit(fd, NULL));
	len = ft_read_line1(fd, buf);
	if (len < 0 || !ft_parse_header(sq, buf, len))
		return (ft_clean_exit(fd, sq));
	sq->x = ft_get_row_len(fd);
	if (sq->x <= 0)
		return (ft_clean_exit(fd, sq));
	close(fd);
	return (sq);
}
