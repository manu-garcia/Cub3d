/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:23:12 by manu              #+#    #+#             */
/*   Updated: 2022/11/29 19:42:56 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "libft.h"

int	create_trgb_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	string_to_color(char *color_str)
{
	char	**rgb_split;
	int		red;
	int		green;
	int		blue;

	rgb_split = ft_split(color_str, ',');
	red = ft_atoi(rgb_split[0]);
	green = ft_atoi(rgb_split[1]);
	blue = ft_atoi(rgb_split[2]);
	free_array(rgb_split);
	return (create_trgb_color(1, red, green, blue));
}
