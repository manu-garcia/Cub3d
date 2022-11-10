/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:24:59 by manu              #+#    #+#             */
/*   Updated: 2022/11/10 22:27:02 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// #include "image.h"
#include "state.h"
#include "error.h"
#include "ft_printf.h"
#include "mlx.h"
#include "libft.h"
#include "map.h"
// #include "collision.h"
// #include "monster.h"

void	update_frame(t_state *state)
{
	state->time++;
	if (state->time > 20)
	{
		state->time = 0;
		// TODO: IA de los enemigos y otros updates de cada frame
		// if (state->monster_last_axis_move)
		// {
		// 	state->monster_last_axis_move = 0;
		// 	move_monster_vertically(state);
		// }
		// else
		// {
		// 	state->monster_last_axis_move = 1;
		// 	move_monster_horizontally(state);
		// }
	}
}

static void	draw_n_lifes(t_state *state)
{
	char	*str;

	mlx_string_put(state->mlx, state->window, 20, 20,
		0x00FFFFFF, "Life:");
	str = ft_itoa(5);
	if (str)
	{
		mlx_string_put(state->mlx, state->window, 120, 20, 0x00FFFFFF, str);
		free(str);
	}
}

int	on_render_frame(t_state *state)
{
	update_frame(state);
	// draw_map(state);
	draw_n_lifes(state);
	return (1);
}
