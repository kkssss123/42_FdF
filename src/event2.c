/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:10:20 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/15 11:48:31 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_projection(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_F1)
		fdf->cam->projection = NONE;
	else if (keycode == KEY_F2)
		fdf->cam->projection = ISOMETRIC;
	else if (keycode == KEY_F3)
		fdf->cam->projection = PERSPECTIVE;
	draw(fdf);
}

void	reverse_color(t_fdf *fdf)
{
	t_point	**points;
	int		x;
	int		y;

	if (fdf->image->background_color == BLACK)
		fdf->image->background_color = GRAY;
	else
		fdf->image->background_color = BLACK;
	points = fdf->map->points;
	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			points[y][x].color = 0xFFFFFF - points[y][x].color;
			x++;
		}
		y++;
	}
	draw(fdf);
}
