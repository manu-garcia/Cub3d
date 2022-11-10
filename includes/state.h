/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:24:05 by manu              #+#    #+#             */
/*   Updated: 2022/11/10 22:24:07 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

# define MAX_IMAGE_PER_ANIMATION	10
# define TIME_PER_ANIMATION_FRAME	5

typedef struct s_image
{
	void		*img;
	int			width;
	int			height;
	int			x;
	int			y;
}	t_image;

typedef struct s_animation
{
	t_image	image[MAX_IMAGE_PER_ANIMATION];
	int		n_images;
	int		n_image;
	int		time;
	int		x;
	int		y;
}	t_animation;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	int			n_tiles_exit;
	int			n_tiles_collectible;
	int			n_players;
}	t_map;

typedef struct s_state
{
	t_map		map;
	void		*mlx;
	void		*window;
	t_animation	hero;
	t_animation	monster;
	int			monster_last_axis_move;
	t_image		floor;
	t_image		exit;
	t_image		wall;
	t_image		collectible;
	int			n_hero_moves;
	int			n_collectibles;
	int			time;
}	t_state;

int	init_state(t_state *state, char *map_file_name);
int	free_state(t_state *state);

#endif
