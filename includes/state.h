/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:24:05 by manu              #+#    #+#             */
/*   Updated: 2022/12/01 19:56:34 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

# define MAX_IMAGE_PER_ANIMATION	10
# define TIME_PER_ANIMATION_FRAME	5

# define screenWidth 1920
# define screenHeight 1080

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
	int			n_players;
	char		*texture_no_path;
	char		*texture_so_path;
	char		*texture_we_path;
	char		*texture_ea_path;
	char		*f;
	char		*c;
	int			floor_color;
	int			ceiling_color;
}	t_map;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		posX;
	int		posY;
	int		dirY;
	int		dirX;
	double	moveSpeed;
	double	rotSpeed;
	double	planeX;
	double	planeY;
	// void	*mlx1;
	// void	*mlx1_win;
	double	Oldtime;
	double	Time;
}	t_data;

typedef struct s_state
{
	t_map		map;
	void		*mlx;
	void		*window;
	t_image		wall_no;
	t_image		wall_so;
	t_image		wall_we;
	t_image		wall_ea;
	int			time;
	t_data		img;
}	t_state;

int	init_state(t_state *state, char *map_file_name);
int	free_state(t_state *state);

#endif
