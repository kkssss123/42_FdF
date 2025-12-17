/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:21:37 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/13 14:46:13 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	destroy_buff(char *buff[OPEN_MAX])
{
	int	i;

	i = 0;
	while (i < OPEN_MAX)
	{
		if (buff[i])
			free(buff[i]);
		i++;
	}
}

static char	*read_to_buff(int fd, char *buff)
{
	char	*temp;
	int		bytes_read;

	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	bytes_read = 1;
	while (!gnl_strchr(buff, '\n') && bytes_read)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(temp);
			return (free_str(buff));
		}
		temp[bytes_read] = 0;
		buff = gnl_strjoin(buff, temp);
		if (!buff)
		{
			free(temp);
			return (NULL);
		}
	}
	free(temp);
	return (buff);
}

static char	*extract_line(char *start)
{
	char	*end;
	char	*line;
	int		len;
	int		i;

	if (!start[0])
		return (NULL);
	end = gnl_strchr(start, '\n');
	if (!end)
		end = gnl_strchr(start, 0);
	else
		end++;
	len = end - start;
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	i = -1;
	while (++i < len)
		line[i] = start[i];
	line[i] = 0;
	return (line);
}

static char	*update_buff(char *buff)
{
	char	*temp;
	char	*new_buff;
	size_t	size;
	size_t	i;

	temp = gnl_strchr(buff, '\n');
	if (!temp)
	{
		free(buff);
		return (NULL);
	}
	temp++;
	size = gnl_strlen(temp);
	new_buff = (char *)malloc(size + 1);
	if (!new_buff)
	{
		free(buff);
		return (NULL);
	}
	i = -1;
	while (++i < size)
		new_buff[i] = temp[i];
	new_buff[i] = 0;
	free(buff);
	return (new_buff);
}

char	*get_next_line(int fd, bool exec_destroy)
{
	static char	*buff[OPEN_MAX];
	char		*line;

	if (exec_destroy)
	{
		destroy_buff(buff);
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff[fd] = read_to_buff(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	line = extract_line(buff[fd]);
	if (!line)
	{
		free(buff[fd]);
		buff[fd] = NULL;
		return (NULL);
	}
	buff[fd] = update_buff(buff[fd]);
	return (line);
}
