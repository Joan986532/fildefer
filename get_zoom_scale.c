/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_zoom_scale.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:37:28 by jnauroy           #+#    #+#             */
/*   Updated: 2025/01/31 19:07:10 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
/*float	ft_get_height(t_coor **grid, int i, int j, int flag)
{
	int	value;

	if (flag == 0)
	{
		value = (grid[i][j].x + grid[i][j].y)
			* sin(M_PI / 6) - grid[i][j].z;
	}
	else
		value = (grid[i][j].x - grid[i][j].y) * cos(M_PI / 6);
	return (value);
}*/
float	ft_get_height(t_coor **grid, int i, int j, int flag)
{
	int	value;

	if (flag == 0)
	{
		value = (sqrtf(2 / 3) * grid[i][j].z)
			- (1 / sqrtf(6)) * (grid[i][j].x + grid[i][j].y) + MID_Y;
	}
	else
		value = (sqrtf(2) / 2) * (grid[i][j].x - grid[i][j].y) + MID_X;
	return (value);
}

void	ft_get_center(t_zoom *zoom, int x, int min_x)
{
	zoom->y_mid = ((zoom->max_y + zoom->min_y) / 2);
	zoom->x_mid = ((x + min_x) / 2);
}

void	ft_get_zoom(t_coor **grid, t_dim *area, t_zoom *z)
{
	int		i;
	int		j;
	float	x;
	float	min_x;

	i = 0;
	z->max_y = ft_get_height(grid, 0, 0, 0);
	z->min_y = ft_get_height(grid, 0, 0, 0);
	while (i < area->height)
	{
		j = 0;
		while (j < area->width)
		{
			if (ft_get_height(grid, i, j, 0) > z->max_y)
				z->max_y = ft_get_height(grid, i, j, 0);
			else if (ft_get_height(grid, i, j, 0) < z->min_y)
				z->min_y = ft_get_height(grid, i, j, 0);
			j++;
		}
		i++;
	}
	x = ft_get_height(grid, 0, area->width - 1, 1);
	min_x = ft_get_height(grid, area->height - 1, 0, 1);
	z->zoom = fminf(WFIG / (x - min_x), HFIG / (z->max_y - z->min_y));
	ft_get_center(z, x, min_x);
}
