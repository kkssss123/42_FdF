/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:09:12 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/15 10:35:31 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_PLUS || \
		keycode == NUMPAD_PLUS || \
		keycode == MOUSE_SCROLL_UP)
		fdf->cam->zoom += 1;
	else if (keycode == KEY_MINUS || \
		keycode == NUMPAD_MINUS || \
		keycode == MOUSE_SCROLL_DOWN)
		fdf->cam->zoom -= 1;
	if (fdf->cam->zoom < 1)
		fdf->cam->zoom = 1;
	else if (fdf->cam->zoom > 100)
		fdf->cam->zoom = 100;
	draw(fdf);
}

void	flatten(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_Z)
		fdf->cam->z_scale -= 0.1;
	else if (keycode == KEY_X)
		fdf->cam->z_scale += 0.1;
	if (fdf->cam->z_scale < 0.1)
		fdf->cam->z_scale = 0.1;
	else if (fdf->cam->z_scale > 5)
		fdf->cam->z_scale = 5;
	draw(fdf);
}

void	move(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_W || keycode == UP)
		fdf->cam->offset_y -= 10;
	else if (keycode == KEY_A || keycode == LEFT)
		fdf->cam->offset_x -= 10;
	else if (keycode == KEY_S || keycode == DOWN)
		fdf->cam->offset_y += 10;
	else if (keycode == KEY_D || keycode == RIGHT)
		fdf->cam->offset_x += 10;
	else if (keycode == KEY_J)
		fdf->cam->distance += 5;
	else if (keycode == KEY_K)
		fdf->cam->distance -= 5;
	draw(fdf);
}

static void	normalize(t_camera *cam)
{
	if (cam->alpha < 0)
		cam->alpha += 2 * PI;
	else if (cam->alpha >= 2 * PI)
		cam->alpha -= 2 * PI;
	if (cam->beta < 0)
		cam->beta += 2 * PI;
	else if (cam->beta >= 2 * PI)
		cam->beta -= 2 * PI;
	if (cam->gamma < 0)
		cam->gamma += 2 * PI;
	else if (cam->gamma >= 2 * PI)
		cam->gamma -= 2 * PI;
}

void	rotate(int keycode, t_fdf *fdf)
{
	if (keycode == NUMPAD_1 || keycode == KEY_1)
		fdf->cam->alpha -= RAD_1;
	else if (keycode == NUMPAD_2 || keycode == KEY_2)
		fdf->cam->alpha += RAD_1;
	else if (keycode == NUMPAD_4 || keycode == KEY_4)
		fdf->cam->beta -= RAD_1;
	else if (keycode == NUMPAD_5 || keycode == KEY_5)
		fdf->cam->beta += RAD_1;
	else if (keycode == NUMPAD_7 || keycode == KEY_7)
		fdf->cam->gamma -= RAD_1;
	else if (keycode == NUMPAD_8 || keycode == KEY_8)
		fdf->cam->gamma += RAD_1;
	normalize(fdf->cam);
	draw(fdf);
}
