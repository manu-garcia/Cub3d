/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:25:24 by manu              #+#    #+#             */
/*   Updated: 2022/11/28 19:17:43 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "array.h"
#include "array_display.h"
#include "ft_printf.h"
#include "map.h"
#include "map_line.h"
#include "libft.h"
#include "str.h"

static char	**unify_grid_width(char **grid, int width)
{
	char	**unified;
	char	*aux;
	int		i;

	unified = NULL;
	i = 0;
	while (grid && grid[i])
	{
		if ((int) ft_strlen(grid[i]) < width)
		{
			aux = str_span_end(grid[i], width, ' ');
			unified = add_str_to_array(unified, aux);
			free(aux);
		}
		else
		{
			unified = add_str_to_array(unified, grid[i]);
		}
		i++;
	}
	free_array(grid);
	return (unified);
}

void	map_display(t_map *map)
{
	ft_printf("NO: %s\n", map->texture_no_path);
	ft_printf("SO: %s\n", map->texture_so_path);
	ft_printf("WE: %s\n", map->texture_we_path);
	ft_printf("EA: %s\n", map->texture_ea_path);
	ft_printf("F: %s\n", map->f);
	ft_printf("C: %s\n", map->c);
	ft_printf("The map grid:\n\n");
	array_display(map->grid);
}

void	auto_set_map_dimensions(t_map *map)
{
	map->height = count_str_in_array(map->grid);
	map->width = get_largest_map_line(map->grid);
	map->grid = unify_grid_width(map->grid, map->width);
}
