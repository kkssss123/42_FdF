/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 11:08:41 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/15 07:43:04 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_abs(int a)
{
	if (a < 0)
		a = -a;
	return (a);
}

t_point	get_dir(t_point a, t_point b)
{	
	t_point	dir;

	if (a.x < b.x)
		dir.x = 1;
	else
		dir.x = -1;
	if (a.y < b.y)
		dir.y = 1;
	else
		dir.y = -1;
	return (dir);
}

static double	get_ratio(int start, int end, int cur)
{
	if (end == start)
		return (1.0);
	return ((cur - start) / (double)(end - start));
}

static int	lerp(int start, int end, double ratio)
{
	return ((int)((1 - ratio) * start + ratio * end));
}

int	get_color(t_point start, t_point end, t_point delta, t_point cur)
{
	double	ratio;
	int		r;
	int		g;
	int		b;

	if (delta.x > delta.y)
		ratio = get_ratio(start.x, end.x, cur.x);
	else
		ratio = get_ratio(start.y, end.y, cur.y);
	r = lerp((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, ratio);
	g = lerp((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, ratio);
	b = lerp(start.color & 0xFF, end.color & 0xFF, ratio);
	return (r << 16 | g << 8 | b);
}
