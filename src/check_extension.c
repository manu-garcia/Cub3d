/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:24:35 by manu              #+#    #+#             */
/*   Updated: 2022/11/10 22:24:37 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

int	check_extension(char *path, char *extension)
{
	char	**path_split;
	int		i;
	int		same_extension;

	path_split = ft_split(path, '.');
	if (!path_split || !path_split[0])
		return (0);
	i = 0;
	same_extension = 0;
	while (path_split[i])
	{
		if (path_split[i] && !path_split[i + 1])
		{
			if (!ft_strncmp(path_split[1], extension, ft_strlen(extension)))
				same_extension = 1;
		}
		free(path_split[i]);
		i++;
	}
	free(path_split);
	return (same_extension);
}
