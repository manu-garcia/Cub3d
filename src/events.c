/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:24:50 by manu              #+#    #+#             */
/*   Updated: 2022/11/10 22:24:53 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "error.h"
// #include "hero.h"
#include "state.h"

int	on_key_pressed(int key_code, t_state *state)
{
	if (key_code == EVENT_KEY_ESC)
		exit_without_error(state);
	// else if (key_code == EVENT_KEY_D)
	// 	hero_move_right(state);
	// else if (key_code == EVENT_KEY_A)
	// 	hero_move_left(state);
	// else if (key_code == EVENT_KEY_W)
	// 	hero_move_up(state);
	// else if (key_code == EVENT_KEY_S)
	// 	hero_move_down(state);
	return (0);
}
