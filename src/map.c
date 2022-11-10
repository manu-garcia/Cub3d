/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:25:24 by manu              #+#    #+#             */
/*   Updated: 2022/11/10 22:25:26 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line_bonus.h"
#include "state.h"
#include "error.h"
#include "map.h"

static char	*load_map_string(t_state *state, int fd)
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
	str_map = load_map_string(state, fd);
	close(fd);
	if (!str_map)
	{
		ft_printf("Error\nMap file is invalid: (%s)\n", file_name);
		exit_with_error(state);
	}
	state->map.grid = ft_split(str_map, '\n');
	free(str_map);
}

void	free_map(t_state *state)
{
	int		i;

	if (!state->map.grid)
		return ;
	i = 0;
	while (state->map.grid[i])
	{
		free(state->map.grid[i]);
		i++;
	}
	free(state->map.grid);
	state->map.grid = NULL;
	state->map.width = 0;
	state->map.height = 0;
}

void	set_tile(t_state *state, t_tile tile, int x, int y)
{
	state->map.grid[y][x] = tile;
}
