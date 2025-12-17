/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:06:19 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/13 14:35:17 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	destroy_map(t_map *map)
{
	destroy_points(map->points, map->height);
	free(map);
}

void	destroy_points(t_point **points, int height)
{
	int	y;

	y = 0;
	while (y < height)
	{
		free(points[y]);
		y++;
	}
	free(points);
}

void	destroy_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
}

void	destroy_all(t_fdf *fdf)
{
	get_next_line(0, true);
	if (fdf->map)
		destroy_map(fdf->map);
	if (fdf->image)
	{
		if (fdf->image->img)
			mlx_destroy_image(fdf->mlx, fdf->image->img);
		free(fdf->image);
	}
	if (fdf->cam)
		free(fdf->cam);
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	free(fdf);
}
