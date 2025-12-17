/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 09:38:25 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/14 12:44:48 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_hex(char c)
{
	int	hex;

	hex = 0;
	while (c != HEX_BASE[hex])
	{
		if (hex > 15)
			return (-1);
		hex++;
	}
	return (hex);
}

static int	ft_atoi_hex(const char *str)
{
	int	num;
	int	hex;

	num = 0;
	while (*str && *str != '\n')
	{
		num *= 16;
		hex = get_hex(ft_toupper(*str));
		if (hex == -1)
			return (-1);
		num += hex;
		str++;
	}
	return (num);
}

static int	parse_color(char *token)
{
	char	*start;

	start = ft_strchr(token, ',');
	if (!start)
		return (WHITE);
	if (ft_strlen(start + 1) < 3 || ft_strncmp(start + 1, "0x", 2))
		return (-1);
	return (ft_atoi_hex(start + 3));
}

void	parse_line(char *line, t_map *map, int y)
{
	char	*trimmed_line;
	char	**tokens;
	int		x;

	trimmed_line = ft_strtrim(line, " \n");
	tokens = ft_split(trimmed_line, ' ');
	x = 0;
	while (tokens[x])
	{
		map->points[y][x].y = y;
		map->points[y][x].x = x;
		map->points[y][x].z = ft_atoi(tokens[x]);
		if (map->points[y][x].z == 0 && tokens[x][0] != '0')
			error_exit(MAP_READ_FAILED);
		if (map->min_z > map->points[y][x].z)
			map->min_z = map->points[y][x].z;
		if (map->max_z < map->points[y][x].z)
			map->max_z = map->points[y][x].z;
		map->points[y][x].color = parse_color(tokens[x]);
		if (map->points[y][x].color < 0)
			error_exit(MAP_READ_FAILED);
		x++;
	}
	free(trimmed_line);
	destroy_tokens(tokens);
}
