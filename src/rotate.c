/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 06:34:53 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/15 08:17:24 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(t_point *p, double theta)
{
	int	y;

	y = p->y;
	p->y = y * cos(theta) - p->z * sin(theta);
	p->z = y * sin(theta) + p->z * cos(theta);
}

static void	rotate_y(t_point *p, double theta)
{
	int	x;

	x = p->x;
	p->x = x * cos(theta) + p->z * sin(theta);
	p->z = -x * sin(theta) + p->z * cos(theta);
}

static void	rotate_z(t_point *p, double theta)
{
	int	x;

	x = p->x;
	p->x = x * cos(theta) - p->y * sin(theta);
	p->y = x * sin(theta) + p->y * cos(theta);
}

void	rotate_xyz(t_point *p, t_camera *cam)
{
	rotate_x(p, cam->alpha);
	rotate_y(p, cam->beta);
	rotate_z(p, cam->gamma);
}
