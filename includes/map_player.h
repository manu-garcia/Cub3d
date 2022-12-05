/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_player.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:03:16 by manu              #+#    #+#             */
/*   Updated: 2022/12/05 20:03:22 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PLAYER_H
# define MAP_PLAYER_H

# include "map_tile.h"
# include "state.h"

int	is_valid_player(t_state *state);
int	is_valid_player_tile(t_tile tile);
int	init_player(t_state *state);

#endif
