/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 07:34:38 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/13 13:47:34 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define MALLOC_FAILED		"Failed to allocate memory.\n"
# define INCORRECT_USAGE 	"Usage: ./fdf map_filename\n"
# define INVALID_MAP_EXT 	"FdF map file must ends with .fdf.\n"
# define INVALID_MAP_NAME	"FdF map file doesn't exist.\n"
# define MAP_READ_FAILED	"Error occured while reading map file.\n"
# define WRONG_MAP_COLUMN	"Found wrong line length.\n"

#endif