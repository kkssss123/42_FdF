/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 06:32:14 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/15 09:55:03 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	terminate(void *param)
{
	destroy_all((t_fdf *)param);
	exit(0);
}

int	key_press(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == KEY_ESC)
		terminate(fdf);
	else if (keycode == KEY_PLUS || keycode == NUMPAD_PLUS || \
		keycode == KEY_MINUS || keycode == NUMPAD_MINUS)
		zoom(keycode, fdf);
	else if (keycode == KEY_W || keycode == UP || keycode == KEY_A || \
		keycode == LEFT || keycode == KEY_S || keycode == DOWN || \
		keycode == KEY_D || keycode == RIGHT || keycode == KEY_J || \
		keycode == KEY_K)
		move(keycode, fdf);
	else if (keycode == KEY_Z || keycode == KEY_X)
		flatten(keycode, fdf);
	else if (keycode == NUMPAD_1 || keycode == KEY_1 || keycode == NUMPAD_2 || \
		keycode == KEY_2 || keycode == NUMPAD_4 || keycode == KEY_4 || \
		keycode == NUMPAD_5 || keycode == KEY_5 || keycode == NUMPAD_7 || \
		keycode == KEY_7 || keycode == NUMPAD_8 || keycode == KEY_8)
		rotate(keycode, fdf);
	else if (keycode == KEY_F1 || keycode == KEY_F2 || keycode == KEY_F3)
		change_projection(keycode, fdf);
	else if (keycode == KEY_SPACE)
		reverse_color(fdf);
	return (0);
}

void	hook_events(t_fdf *fdf)
{
	mlx_key_hook(fdf->win, key_press, fdf);
	mlx_hook(fdf->win, DESTROY_NOTIFY, 0, terminate, fdf);
}
