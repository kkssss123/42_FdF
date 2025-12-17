/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:12:45 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/14 15:44:03 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * Todo:
 * 		Include one extra projection (such as parallel or conic)!
 *	 	Add one more bonus of your choice.
 */
int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		error_exit(INCORRECT_USAGE);
	fdf = init_fdf(argv[1]);
	draw(fdf);
	hook_events(fdf);
	mlx_loop(fdf->mlx);
}
