/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 10:08:29 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/15 09:49:40 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	apply_isometric(t_point *p)
{
	int	x;

	x = p->x;
	p->x = (x - p->y) * cos(RAD_30);
	p->y = (x + p->y) * sin(RAD_30) - p->z;
}

static void	apply_perspective(t_point *p, t_camera *cam)
{
	double	depth;

	depth = cam->distance - p->z;
	if (depth < 1)
		depth = 1.0;
	p->x *= 1.0 / depth;
	p->y *= 1.0 / depth;
}

void	project(t_fdf *fdf, t_point *p)
{
	if (fdf->cam->projection == NONE)
		return ;
	else if (fdf->cam->projection == ISOMETRIC)
		apply_isometric(p);
	else if (fdf->cam->projection == PERSPECTIVE)
		apply_perspective(p, fdf->cam);
}
