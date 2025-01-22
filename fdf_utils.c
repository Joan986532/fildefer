/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:22:50 by jnauroy           #+#    #+#             */
/*   Updated: 2025/01/21 18:22:32 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

t_coor	**ft_malloc_tab(t_dim *dimensions)
{
	t_coor **tab;
	int i;

	i = 0;
	tab = NULL;
	tab = malloc(sizeof(t_coor *) * dimensions->height);
	if (!tab)
		return (0);
	while (i < dimensions->height)
	{
		tab[i] = malloc(sizeof(t_coor) * dimensions->width);
		if (!tab[i])
			return (ft_free_tab(tab, i));
		i++;
	}
	return (tab);
}

void	**ft_free_split(char **split_tab, int j)
{
	int	i;

	i = 0;
	while (i <= j)
	{
		free(split_tab[i]);
		i++;
	}
	free(split_tab);
	return (NULL);
}

t_coor	**ft_free_tab(t_coor **tab, int i)
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
