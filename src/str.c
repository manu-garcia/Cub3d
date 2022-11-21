/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:11:41 by manu              #+#    #+#             */
/*   Updated: 2022/11/21 20:59:56 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_malloc.h"

char	*str_span_end(char *str, int width, char c)
{
	char	*spanned;
	int		len;
	int		i;

	len = ft_strlen(str);
	i = len;
	spanned = (char *)ft_malloc(width + 1);
	ft_strlcpy(spanned, str, len + 1);
	while (i < width)
	{
		spanned[i] = c;
		i++;
	}
	spanned[i] = '\0';
	return (spanned);
}
