/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 08:56:39 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/15 11:40:41 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_background(t_fdf *fdf, size_t size)
{
	int	*img;
	int	i;

	ft_bzero(fdf->image->addr, size);
	img = (int *)(fdf->image->addr);
	i = 0;
	while (i < WIDTH * HEIGHT)
		img[i++] = fdf->image->background_color;
}

static void	draw_pixel(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = fdf->image->addr \
		+ y * fdf->image->size_line \
		+ x * fdf->image->bits_per_pixel / 8;
	*(unsigned int *)dst = color;
}

static void	bresenham(t_fdf *fdf, t_point start, t_point end)
{
	t_point	delta;
	t_point	dir;
	t_point	cur;
	int		error[2];

	delta.x = get_abs(start.x - end.x);
	delta.y = get_abs(start.y - end.y);
	dir = get_dir(start, end);
	error[0] = delta.x - delta.y;
	cur = start;
	while (cur.x != end.x || cur.y != end.y)
	{
		draw_pixel(fdf, cur.x, cur.y, get_color(start, end, delta, cur));
		error[1] = error[0] * 2;
		if (error[1] > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += dir.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += dir.y;
		}
	}
}

static void	draw_line(t_fdf *fdf, t_point start, t_point end)
{
	transform(fdf, &start);
	transform(fdf, &end);
	project(fdf, &start);
	project(fdf, &end);
	translate(&start, fdf->cam);
	translate(&end, fdf->cam);
	bresenham(fdf, start, end);
}

void	draw(t_fdf *fdf)
{
	int	x;
	int	y;

	draw_background(fdf, WIDTH * HEIGHT * (fdf->image->bits_per_pixel / 8));
	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (x + 1 < fdf->map->width)
				draw_line(fdf, \
					fdf->map->points[y][x], fdf->map->points[y][x + 1]);
			if (y + 1 < fdf->map->height)
				draw_line(fdf, \
					fdf->map->points[y][x], fdf->map->points[y + 1][x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image->img, 0, 0);
}
