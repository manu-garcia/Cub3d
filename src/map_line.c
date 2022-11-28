/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:16:45 by manu              #+#    #+#             */
/*   Updated: 2022/11/28 19:16:48 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "map_tile.h"
#include "libft.h"

static char	*get_last_part_in_line(char *line)
{
	char	**parts;
	char	*last_part;
	int		len;

	parts = ft_split(line, ' ');
	len = count_str_in_array(parts);
	if (!len)
		last_part = ft_strdup("");
	else
		last_part = ft_strdup(parts[len - 1]);
	free_array(parts);
	return (last_part);
}

char	*get_map_value(char **lines, char *key)
{
	int		count;
	char	*line;
	char	*value;

	value = NULL;
	if (!lines || !count_str_in_array(lines))
		return (value);
	count = 0;
	while (!value && lines && lines[count])
	{
		line = ft_strtrim(lines[count], " ");
		if (line)
		{
			if (!ft_strncmp(line, key, ft_strlen(key)))
				value = get_last_part_in_line(line);
			free(line);
		}
		count++;
	}
	return (value);
}

static int	is_first_grid_line(char *line)
{
	int		is_first;
	char	*aux;

	if (!ft_strlen(line))
	{
		free(line);
		return (0);
	}
	is_first = 1;
	aux = line;
	while (aux && *aux)
	{
		if (!is_valid_tile_type(*aux))
		{
			is_first = 0;
			break ;
		}
		aux++;
	}
	return (is_first);
}

char	**get_map_grid(char **lines)
{
	int		i;
	char	**grid;

	grid = NULL;
	i = 0;
	while (lines && !is_first_grid_line(lines[i]))
		i++;
	while (lines && lines[i])
	{
		grid = add_str_to_array(grid, lines[i]);
		i++;
	}
	return (grid);
}

int	get_largest_map_line(char **grid)
{
	int	width;
	int	i;

	width = 0;
	i = 0;
	while (grid && grid[i])
	{
		if ((int)ft_strlen(grid[i]) > width)
			width = ft_strlen(grid[i]);
		i++;
	}
	return (width);
}
