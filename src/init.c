/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 07:49:52 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/15 11:37:27 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static bool	is_valid_filename(char	*filename)
{
	char	**tokens;
	bool	result;
	int		i;

	tokens = ft_split(filename, '.');
	if (!tokens)
		return (false);
	result = true;
	if (result && (!tokens[0] || !tokens[1]))
		result = false;
	i = 0;
	if (result)
		while (tokens[i + 1])
			i++;
	if (result && ft_strlen(tokens[i]) != 3)
		result = false;
	if (result && ft_strncmp(tokens[i], "fdf", 3))
		result = false;
	i = 0;
	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
	return (result);
}

t_fdf	*init_fdf(char *filename)
{
	t_fdf	*fdf;

	if (!is_valid_filename(filename))
		error_exit(INVALID_MAP_EXT);
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		error_exit(MALLOC_FAILED);
	fdf->map = init_map(filename);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, TITLE);
	fdf->image = init_img(fdf->mlx);
	if (!fdf->image)
		error_exit(MALLOC_FAILED);
	fdf->cam = init_cam(fdf->map);
	if (!fdf->cam)
		error_exit(MALLOC_FAILED);
	return (fdf);
}

t_image	*init_img(void	*mlx)
{
	t_image	*image;

	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, \
									&image->size_line, &image->endian);
	image->background_color = BLACK;
	return (image);
}

static int	init_zoom(t_map *map)
{
	int	temp;
	int	zoom;

	temp = map->width;
	if (temp < map->height)
		temp = map->height;
	zoom = WIDTH / temp * 0.9;
	if (zoom < HEIGHT / temp * 0.9)
		zoom = HEIGHT / temp * 0.9;
	if (zoom < 1)
		zoom = 1;
	else if (zoom > 30)
		zoom = 30;
	return (zoom);
}

t_camera	*init_cam(t_map *map)
{
	t_camera	*cam;

	cam = (t_camera *)malloc(sizeof(t_camera));
	if (!cam)
		return (NULL);
	cam->projection = ISOMETRIC;
	cam->zoom = init_zoom(map);
	cam->z_scale = 0.8;
	cam->distance = 200;
	if (cam->distance < map->max_z + 1)
		cam->distance = map->max_z + 1;
	cam->alpha = 0;
	cam->beta = 0;
	cam->gamma = 0;
	cam->offset_x = WIDTH / 2;
	cam->offset_y = HEIGHT / 2;
	return (cam);
}
