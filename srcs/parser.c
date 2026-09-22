/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berpinhe <berpinhe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 00:14:22 by berpinhe          #+#    #+#             */
/*   Updated: 2026/09/22 16:01:27 by berpinhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_isprint(char c)
{
	return (c >= 32 && c <= 126);
}
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
	int i;

	sq->ful = buf[len - 1];
	sq->obs = buf[len - 2];
	sq->emp = buf[len - 3];
	if (!ft_isprint(sq->emp) || !ft_isprint(sq->obs) || !ft_isprint(sq->ful))
		return (0); 
	if (sq->emp == sq->obs || sq->emp == sq->ful || sq->obs == sq->ful)
		return (0);
	i = 0;
	while (i < len - 3)
	{
		if (buf[i] < '0' || buf[i] > '9')
			return (0);
		i++;
	}
	if (buf[0] == '0' && (len - 3) > 1)
		return (0);
	buf[len - 3] = '\0';
	sq->y = ft_atoi(buf);
	return (sq->y > 0);
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
	if (red <= 0 || len == 0 || dummy != '\n')
		return (-1);
	return (len);
}

t_square	*ft_getsize(int fd)
{
	int			len;
	char		buf[15];
	t_square	*sq;

	sq = (t_square *)malloc(sizeof(t_square));
	if (!sq)
		return (NULL);
	len = ft_read_line1(fd, buf);
	if (len < 0 || !ft_parse_header(sq, buf, len))
	{
		free(sq);
		return (NULL);
	}
	sq->x = ft_get_row_len(fd);
	if (sq->x <= 0)
	{
		free(sq);
		return (NULL);
	}
	return (sq);
}
