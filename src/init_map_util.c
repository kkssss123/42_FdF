/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 08:58:21 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/14 08:33:05 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*trim_line(char *line)
{
	char	*new_line;

	new_line = ft_strtrim(line, " \n");
	free(line);
	return (new_line);
}

static char	*get_next_trimmed_line(int fd)
{
	char	*line;

	line = get_next_line(fd, false);
	if (!line)
		return (NULL);
	line = trim_line(line);
	return (line);
}

static void	check_width(char *line, int width)
{
	if (count_words(line, ' ') != width)
	{
		free(line);
		error_exit(WRONG_MAP_COLUMN);
	}
}

int	init_map_width(char *filename)
{
	int		fd;
	char	*line;
	int		width;

	fd = open(filename, O_RDONLY);
	line = get_next_trimmed_line(fd);
	if (!line)
	{
		close(fd);
		error_exit(MAP_READ_FAILED);
	}
	width = count_words(line, ' ');
	free(line);
	line = get_next_trimmed_line(fd);
	while (line)
	{
		check_width(line, width);
		free(line);
		line = get_next_trimmed_line(fd);
	}
	close(fd);
	return (width);
}

int	init_map_height(char *filename)
{
	int		fd;
	char	*line;
	int		height;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd, false);
	if (!line)
		error_exit(MAP_READ_FAILED);
	height = 0;
	while (line)
	{
		height++;
		if (!ft_isprint(*line))
		{
			free(line);
			close(fd);
			error_exit(MAP_READ_FAILED);
		}
		free(line);
		line = get_next_line(fd, false);
	}
	close(fd);
	return (height);
}
