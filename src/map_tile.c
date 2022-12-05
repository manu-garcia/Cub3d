/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:43:16 by manu              #+#    #+#             */
/*   Updated: 2022/12/05 20:04:49 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "map.h"
#include "map_player.h"
#include "error.h"

int	is_valid_tile_type(t_tile tile)
{
	if (tile == TILE_FLOOR
		|| tile == TILE_WALL
		|| tile == TILE_EMPTY
		|| is_valid_player_tile(tile))
		return (1);
	return (0);
}

t_tile	get_tile_at(t_map *map, int x, int y)
{
	if (x < 0 || x > map->width)
		printf("get_tile_at x axis error (%d)\n", x);
	if (y < 0 || y > map->height)
		printf("get_tile_at y axis error (%d)\n", y);
	return (map->grid[y][x]);
}

void	set_tile(t_map *map, t_tile tile, int x, int y)
{
	if (x < 0 || x > map->width)
		printf("set_tile_at x axis error (%d)\n", x);
	if (y < 0 || y > map->height)
		printf("set_tile_at y axis error (%d)\n", y);
	map->grid[y][x] = tile;
}
