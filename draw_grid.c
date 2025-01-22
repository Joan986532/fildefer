/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:49:10 by jnauroy           #+#    #+#             */
/*   Updated: 2025/01/22 17:25:55 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	ft_draw_grid(t_coor **grid, t_dim *area, t_mlx_img *img)
{
	int i;
	int j;

	i = 0;
	while (i < area->height)
	{
		j = 0;
		while (j < area->width)
		{
			my_pixel_put(img,
				960 + (grid[i][j].x - grid[i][j].y) * cos(M_PI / 6) * SCALE,
				200 + (grid[i][j].x + grid[i][j].y - grid[i][j].z)
				* sin(M_PI / 6) * SCALE,
				0xFFFFFF);
			j++;
			printf("(%d, %d)\n", grid[i][j].x, grid[i][j].y);
		}
		i++;
	}
}

void	ft_convert_coor(t_coor **grid, int i, int j, t_mlx_img *img)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	dx;
	int	dy;
	int	cumul;

	x1 = 960 + (grid[j][i].x - grid[j][i].y) * cos(M_PI / 6) * SCALE;
	y1 = 200 + (grid[j][i].x + grid[j][i].y - grid[j][i].z)
		* sin(M_PI / 6) * SCALE;
	x2 = 960
		+ (grid[j + 1][i].x - grid[j + 1][i].y) * cos(M_PI / 6)
		* SCALE;
	y2 = 200
		+ (grid[j + 1][i].x + grid[j + 1][i].y - grid[j + 1][i].z)
		* sin(M_PI / 6) * SCALE;
	dx = x2 - x1;
	dy = y2 - y1;
	cumul = dx / 2;
	while (x1 < x2)
	{
		cumul += dy;
		if (cumul >= dx)
		{
			cumul -= dx;
			y1 += 1;
		}
		my_pixel_put(img, x1, y1, 0xFFFFFF);
		x1++;
	}
}

void ft_bresenham(t_coor **grid, t_dim *area, t_mlx_img *img)
{
	int i;
	int j;

	i = 0;
	while (i < area->width)
	{
		j = 0;
		while (j < area->height - 1)
		{
			ft_convert_coor(grid, i, j, img);
			j++;
		}
		i++;
	}
}
