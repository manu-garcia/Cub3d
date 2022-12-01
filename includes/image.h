/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:56:22 by manu              #+#    #+#             */
/*   Updated: 2022/12/01 19:56:24 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "state.h"

int     load_image(t_state *state, t_image *image, char *file);
void    free_image(t_state *state, t_image *image);
int     load_all_images(t_state *state);
int     free_all_images(t_state *state);

#endif
