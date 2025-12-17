/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 10:05:15 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/14 15:02:21 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	transform(t_fdf *fdf, t_point *p)
{
	p->x -= fdf->map->width / 2;
	p->y -= fdf->map->height / 2;
	scale(p, fdf->cam);
	rotate_xyz(p, fdf->cam);
}
