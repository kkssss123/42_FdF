/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:40:23 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/15 10:05:03 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "color.h"
# include "error.h"
# include "keycode.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

# define INT_MAX	2147483647
# define INT_MIN	-2147483648
# define WIDTH		1280
# define HEIGHT		960
# define TITLE 		"fdf"
# define HEX_BASE	"0123456789ABCDEF"
# define RAD_1		0.01745329
# define RAD_30		0.52359877
# define PI			3.14159265

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_map
{
	int		width;
	int		height;
	t_point	**points;
	int		min_z;
	int		max_z;
}	t_map;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		background_color;
}	t_image;

enum {
	NONE,
	ISOMETRIC,
	PERSPECTIVE
};

typedef struct s_camera
{
	int		projection;
	int		zoom;
	float	z_scale;
	int		distance;
	double	alpha;
	double	beta;
	double	gamma;
	int		offset_x;
	int		offset_y;
}	t_camera;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_image		*image;
	t_camera	*cam;
}	t_fdf;

/* destroy functions */
void		destroy_map(t_map *map);
void		destroy_points(t_point **points, int height);
void		destroy_tokens(char **tokens);
void		destroy_all(t_fdf *fdf);
/* error */
void		error_exit(char *errmsg);
/* draw functions */
void		draw(t_fdf *fdf);
int			get_abs(int a);
t_point		get_dir(t_point a, t_point b);
int			get_color(t_point start, t_point end, t_point delta, t_point cur);
void		transform(t_fdf *fdf, t_point *p);
void		scale(t_point *p, t_camera *cam);
void		rotate_xyz(t_point *p, t_camera *cam);
void		translate(t_point *p, t_camera *cam);
void		project(t_fdf *fdf, t_point *p);
/* init functions */
t_fdf		*init_fdf(char *filename);
t_image		*init_img(void	*mlx);
t_camera	*init_cam(t_map *map);
/* init functions for reading map */
t_map		*init_map(char *filename);
int			init_map_width(char *filename);
int			init_map_height(char *filename);
void		parse_line(char *line, t_map *map, int y);
/* event functions */
void		hook_events(t_fdf *fdf);
int			key_press(int keycode, void *param);
int			terminate(void *param);
void		zoom(int keycode, t_fdf *fdf);
void		flatten(int keycode, t_fdf *fdf);
void		move(int keycode, t_fdf *fdf);
void		rotate(int keycode, t_fdf *fdf);
void		change_projection(int keycode, t_fdf *fdf);
void		reverse_color(t_fdf *fdf);

#endif