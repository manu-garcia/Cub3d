/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:57:18 by manu              #+#    #+#             */
/*   Updated: 2022/12/01 19:57:20 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "ft_printf.h"
#include "mlx.h"
#include "state.h"

int	load_image(t_state *state, t_image *image, char *file)
{
	image->img = mlx_xpm_file_to_image(state->mlx, file,
			&image->width, &image->height);
	if (!image->img)
	{
		ft_printf("Error\nError loading image (%s)\n", file);
		return (exit_with_error(state));
	}
	return (1);
}

void	free_image(t_state *state, t_image *image)
{
	if (image->img)
		mlx_destroy_image(state->mlx, image->img);
}

int	load_all_images(t_state *state)
{
	load_image(state, &(state->wall_no), state->map.texture_no_path);
	load_image(state, &(state->wall_so), state->map.texture_so_path);
	load_image(state, &(state->wall_we), state->map.texture_we_path);
	load_image(state, &(state->wall_ea), state->map.texture_ea_path);
	return (1);
}

int	free_all_images(t_state *state)
{
	free_image(state, &state->wall_no);
	free_image(state, &state->wall_so);
	free_image(state, &state->wall_we);
	free_image(state, &state->wall_ea);
	return (1);
}
