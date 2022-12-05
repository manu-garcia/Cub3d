/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tile.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:44:01 by manu              #+#    #+#             */
/*   Updated: 2022/12/05 20:03:47 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TILE_H
# define MAP_TILE_H

# include "map.h"

int		is_valid_tile_type(t_tile tile);
t_tile	get_tile_at(t_map *map, int x, int y);
void	set_tile(t_map *map, t_tile tile, int x, int y);

#endif
