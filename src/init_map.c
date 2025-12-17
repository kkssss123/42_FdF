/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 08:19:53 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/14 08:20:59 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	create_points(t_map *map)
{
	int	y;

	map->points = (t_point **)malloc(sizeof(t_point *) * map->height);
	if (!map->points)
		error_exit(MALLOC_FAILED);
	y = 0;
	while (y < map->height)
	{
		map->points[y] = (t_point *)malloc(sizeof(t_point) * map->width);
		if (!map->points[y])
		{
			destroy_map(map);
			error_exit(MALLOC_FAILED);
		}
		y++;
	}
}

static void	read_points(char *filename, t_map *map)
{
	int		fd;
	int		y;
	char	*line;

	fd = open(filename, O_RDONLY);
	y = 0;
	while (y < map->height)
	{
		line = get_next_line(fd, false);
		parse_line(line, map, y);
		free(line);
		y++;
	}
	close(fd);
}

t_map	*init_map(char *filename)
{
	t_map	*map;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit(INVALID_MAP_NAME);
	close(fd);
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		error_exit(MALLOC_FAILED);
	map->width = init_map_width(filename);
	map->height = init_map_height(filename);
	map->min_z = INT_MAX;
	map->max_z = INT_MIN;
	create_points(map);
	read_points(filename, map);
	return (map);
}
