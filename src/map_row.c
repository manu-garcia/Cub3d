/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_row.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:17:14 by manu              #+#    #+#             */
/*   Updated: 2022/11/28 19:17:16 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map_tile.h"

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

int	is_valid_row(t_map *map, char *row)
{
	if (!row)
		return (0);
	if ((int) ft_strlen(row) < 3)
		return (0);
	map->n_players += count_number_tiles(row, TILE_PLAYER_N);
	map->n_players += count_number_tiles(row, TILE_PLAYER_S);
	map->n_players += count_number_tiles(row, TILE_PLAYER_E);
	map->n_players += count_number_tiles(row, TILE_PLAYER_W);
	return (1);
}
