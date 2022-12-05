/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:16:57 by manu              #+#    #+#             */
/*   Updated: 2022/12/05 20:04:32 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "array.h"
#include "color.h"
#include "error.h"
#include "ft_printf.h"
#include "get_next_line_bonus.h"
#include "map.h"
#include "libft.h"
#include "state.h"

static char	*load_map_file(t_state *state, int fd)
{
	char	*str_map;
	char	*line;
	char	*aux;

	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("Error\nMap file is empty\n");
		exit_with_error(state);
	}
	str_map = NULL;
	while (line)
	{
		if (str_map)
		{
			aux = str_map;
			str_map = ft_strjoin(str_map, line);
			free(aux);
			free(line);
		}
		else
			str_map = line;
		line = get_next_line(fd);
	}
	return (str_map);
}

static void	load_map_sections(t_state *state, char *str_map)
{
	char	**lines;

	lines = ft_split(str_map, '\n');
	state->map.texture_no_path = get_map_value(lines, "NO ");
	state->map.texture_so_path = get_map_value(lines, "SO ");
	state->map.texture_we_path = get_map_value(lines, "WE ");
	state->map.texture_ea_path = get_map_value(lines, "EA ");
	state->map.f = get_map_value(lines, "F ");
	state->map.c = get_map_value(lines, "C ");
	state->map.floor_color = string_to_color(state->map.f);
	state->map.ceiling_color = string_to_color(state->map.c);
	state->map.grid = get_map_grid(lines);
	auto_set_map_dimensions(&state->map);
	free_array(lines);
}

void	load_map(t_state *state, char *file_name)
{
	char	*str_map;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nMap file does not exist: (%s)\n", file_name);
		exit_with_error(state);
	}
	str_map = load_map_file(state, fd);
	close(fd);
	if (!str_map)
	{
		ft_printf("Error\nMap file is invalid: (%s)\n", file_name);
		exit_with_error(state);
	}
	load_map_sections(state, str_map);
	free(str_map);
}

void	free_map(t_state *state)
{
	if (state->map.texture_no_path)
		free(state->map.texture_no_path);
	if (state->map.texture_so_path)
		free(state->map.texture_so_path);
	if (state->map.texture_we_path)
		free(state->map.texture_we_path);
	if (state->map.texture_ea_path)
		free(state->map.texture_ea_path);
	if (state->map.f)
		free(state->map.f);
	if (state->map.c)
		free(state->map.c);
	if (!state->map.grid)
		return ;
	free_array(state->map.grid);
}
