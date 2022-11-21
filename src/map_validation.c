/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:25:15 by manu              #+#    #+#             */
/*   Updated: 2022/11/21 20:59:01 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>

#include "error.h"
#include "ft_printf.h"
#include "get_next_line_bonus.h"
#include "libft.h"
#include "map.h"
#include "map_tile.h"
#include "state.h"

static int	count_number_tiles(char *row, t_tile tile)
{
	int	col;
	int	n_tiles;

	col = 0;
	n_tiles = 0;
	while (row[col])
	{
		if ((t_tile) row[col] == tile)
			n_tiles++;
		col++;
	}
	return (n_tiles);
}

static int	is_valid_row(t_state *state, char *row)
{
	if (!row)
		return (0);
	if ((int) ft_strlen(row) < 3)
		return (0);
	state->map.n_players += count_number_tiles(row, TILE_PLAYER_N);
	state->map.n_players += count_number_tiles(row, TILE_PLAYER_S);
	state->map.n_players += count_number_tiles(row, TILE_PLAYER_E);
	state->map.n_players += count_number_tiles(row, TILE_PLAYER_W);
	return (1);
}

static int	has_textures(t_map *map)
{
	if (!map || !map->texture_no_path || !map->texture_so_path
		|| !map->texture_we_path || !map->texture_ea_path)
		return (0);
	return (1);
}

int	is_valid_surrounded_tile(t_map *map, int x, int y)
{
	t_tile	tile;

	tile = get_tile_at(map, x, y);
	if (tile != TILE_FLOOR)
		return (1);
	if (x > 0 && get_tile_at(map, x - 1, y) == TILE_EMPTY)
		return (0);
	if (x < (map->width - 1)
		&& get_tile_at(map, x + 1, y) == TILE_EMPTY)
		return (0);
	if (y > 0 && get_tile_at(map, x, y - 1) == TILE_EMPTY)
		return (0);
	if (y < (map->height - 1)
		&& get_tile_at(map, x, y + 1) == TILE_EMPTY)
		return (0);
	return (1);
}

static int	is_walled_map(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < map->height)
	{
		while (x < map->width)
		{
			if (!is_valid_surrounded_tile(map, x, y))
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

int	is_valid_map(t_state *state)
{
	int	i;

	i = 0;
	if (!has_textures(&state->map))
		return (0);
	while (state->map.grid[i])
	{
		if (!is_valid_row(state, state->map.grid[i]))
			return (0);
		i++;
	}
	if (!is_walled_map(&state->map))
		return (0);
	// if (state->map.width < 3 || state->map.height < 3)
	// 	return (0);
	if (state->map.n_players != 1)
		return (0);
	return (1);
}
