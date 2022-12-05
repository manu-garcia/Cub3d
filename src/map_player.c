/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:06:44 by manu              #+#    #+#             */
/*   Updated: 2022/12/05 20:06:45 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_tile.h"
#include "map_validation.h"
#include "vector2d.h"

static int	get_player_x_direction(t_tile tile)
{
	if (tile == TILE_PLAYER_N || tile == TILE_PLAYER_S)
		return (0);
	if (tile == TILE_PLAYER_E)
		return (1);
	if (tile == TILE_PLAYER_W)
		return (-1);
	return (0);
}

static int	get_player_y_direction(t_tile tile)
{
	if (tile == TILE_PLAYER_E || tile == TILE_PLAYER_W)
		return (0);
	if (tile == TILE_PLAYER_N)
		return (1);
	if (tile == TILE_PLAYER_S)
		return (-1);
	return (0);
}

int	is_valid_player_tile(t_tile tile)
{
	if (tile == TILE_PLAYER_N
		|| tile == TILE_PLAYER_S
		|| tile == TILE_PLAYER_E
		|| tile == TILE_PLAYER_W)
		return (1);
	return (0);
}

static int	get_player_vector_from_grid(t_map *map, t_vector2d *vector2d)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < map->height)
	{
		while (x < map->width)
		{
			if (is_valid_player_tile(get_tile_at(map, x, y)))
			{
				vector2d->x = x;
				vector2d->y = y;
				return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	init_player(t_state *state)
{
	t_tile	player_tile;

	init_vector(&state->player_tile_pos);
	init_vector(&state->player_dir);
	if (!get_player_vector_from_grid(&state->map, &state->player_tile_pos))
		return (0);
	player_tile = get_tile_at(&state->map, state->player_tile_pos.x, state->player_tile_pos.y);
	if (!is_valid_player_tile(player_tile))
		return (0);
	state->player_dir.x = get_player_x_direction(player_tile);
	state->player_dir.y = get_player_y_direction(player_tile);
	set_tile(&state->map, TILE_FLOOR, state->player_tile_pos.x, state->player_tile_pos.y);
	return (1);
}

int	is_valid_player(t_state *state)
{
	t_vector2d aux_vector2d;

	init_vector(&aux_vector2d);
	if (!get_player_vector_from_grid(&state->map, &aux_vector2d))
		return (0);
	if (!is_valid_surrounded_tile(&state->map, aux_vector2d.x, aux_vector2d.y))
		return (0);
	return (1);
}