/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:05:32 by manu              #+#    #+#             */
/*   Updated: 2022/12/05 20:05:53 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "state.h"
#include "map_player.h"

int	world_init(t_state *state)
{
	if (!init_player(state))
	{
		ft_printf("Error\nPlayer not found on the map.\n");
		return (0);
	}
	return (1);
}
