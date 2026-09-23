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

#include "../includes/bsq.h"

static int	ft_isprint(char c)
{
	return (c >= 32 && c <= 126);
}

static int	ft_parse_height(char *buffer, size_t length)
{
	int	result;
	int	digit;

	if (*buffer == '+')
	{
		buffer++;
		length--;
	}
	result = 0;
	while (length-- > 0)
	{
		if (*buffer < '0' || *buffer > '9')
			return (0);
		digit = *buffer++ - '0';
		if (result > (INT_MAX - digit) / 10)
			return (0);
		result = result * 10 + digit;
	}
	return (result);
}

static int	ft_parse_header(t_square *map, char *buffer, size_t length)
{
	map->emp = buffer[length - 3];
	map->obs = buffer[length - 2];
	map->ful = buffer[length - 1];
	if (!ft_isprint(map->emp) || !ft_isprint(map->obs)
		|| !ft_isprint(map->ful))
		return (0);
	if (map->emp == map->obs || map->emp == map->ful
		|| map->obs == map->ful)
		return (0);
	map->y = ft_parse_height(buffer, length - 3);
	return (map->y > 0);
}

static int	ft_get_row_len(char *buffer, size_t length)
{
	size_t	width;

	width = 0;
	while (width < length && buffer[width] != '\n')
		width++;
	if (width > INT_MAX)
		return (0);
	return ((int)width);
}

size_t	ft_parse_map(char *buffer, size_t length, t_square *map)
{
	size_t	offset;

	offset = 0;
	while (offset < length && buffer[offset] != '\n')
		offset++;
	if (offset == length || offset < 4)
		return (0);
	if (!ft_parse_header(map, buffer, offset))
		return (0);
	offset++;
	map->x = ft_get_row_len(buffer + offset, length - offset);
	if (map->x == 0)
		return (0);
	if (!ft_valid_rows(buffer + offset, length - offset, map))
		return (0);
	return (offset);
}
