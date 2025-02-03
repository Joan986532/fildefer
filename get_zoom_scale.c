/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_zoom_scale.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:37:28 by jnauroy           #+#    #+#             */
/*   Updated: 2025/02/03 18:21:46 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

float	ft_get_height(t_coor **grid, int i, int j, int flag)
{
	float	value;

	if (flag == 0)
	{
		//value = (grid[i][j].x + grid[i][j].y)
		//	* sin(M_PI / 6) + MID_Y - grid[i][j].z;
		value = ( - grid[i][j].z) - ((1 / sqrtf(6))
			* (grid[i][j].x + grid[i][j].y)) + MID_Y;
	}
	else
		//value = (grid[i][j].x - grid[i][j].y) * cos(M_PI / 6) + MID_X;
		value = (sqrtf(2) / 2) * (grid[i][j].x - grid[i][j].y) + MID_X;
	return (value);
}

void	ft_get_zoom(t_coor **grid, t_dim *area, t_zoom *z)
{
	float	x;
	float	min_x;

	z->zoom = 1;
	z->max_y = ft_get_height(grid, area->height - 1, area->width - 1, 0);
	z->min_y = ft_get_height(grid, 0, 0, 0);
	x = ft_get_height(grid, 0, area->width - 1, 1);
	min_x = ft_get_height(grid, area->height - 1, 0, 1);
	z->zoom = fminf(WFIG / (x - min_x), HFIG / (z->max_y - z->min_y));
}
