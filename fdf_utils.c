/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:22:50 by jnauroy           #+#    #+#             */
/*   Updated: 2025/01/17 17:06:11 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	**ft_malloc_tab(t_map_size *dimensions)
{
	int **tab;
	int i;

	i = 0;
	tab = NULL;
	tab = malloc(sizeof(int *) * dimensions->height);
	if (!tab)
		return (0);
	while (i < dimensions->width)
	{
		tab[i] = malloc(sizeof(int) * dimensions->width);
		if (!tab[i])
			return (ft_free_tab(tab, i));
		i++;
	}
	return (tab);
}

int	**ft_free_tab(int **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}


void	my_pixel_put(t_mlx_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}
