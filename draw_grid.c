/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:49:10 by jnauroy           #+#    #+#             */
/*   Updated: 2025/01/23 14:57:37 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	ft_init_besenham(t_point *point, int *error)
{
	point->dx = abs(point->x2 - point->x1);
	point->dy = abs(point->y2 - point->y1) * (-1);
	if (point->x1 < point->x2)
		point->sx = 1;
	else
		point->sx = -1;
	if (point->y1 < point->y2)
		point->sy = 1;
	else
		point->sy = -1;
	(*error) = point->dx + point->dy;
}

void	ft_algo_besenham(t_point *point, t_mlx_img *img)
{
	int	error;
	int	error2;

	ft_init_besenham(point, &error);
	while (1)
	{
		my_pixel_put(img, point->x1, point->y1, 0xFFFFFF);
		if (point->x1 == point->x2 && point->y1 == point->y2)
			break ;
		error2 = error;
		if (error2 >= point->dy)
		{
			if (point->x1 == point->x2)
				break ;
			error += point->dy;
			point->x1 += point->sx;
		}
		if (error2 <= point->dx)
		{
			if (point->y1 == point->y2)
				break ;
			error += point->dx;
			point->y1 += point->sy;
		}
	}
}

void	ft_draw_height(t_coor **grid, t_dim *area, t_mlx_img *img)
{
	int		i;
	int		j;
	t_point	point;

	j = 0;
	while (j < area->width)
	{
		i = 0;
		while (i < area->height - 1)
		{
			point.x1 = 960 + (grid[i][j].x - grid[i][j].y)
				* cos(M_PI / 6) * SCALE;
			point.y1 = 200 + (grid[i][j].x + grid[i][j].y - grid[i][j].z)
				* sin(M_PI / 6) * SCALE;
			point.x2 = 960 + (grid[i + 1][j].x - grid[i + 1][j].y)
				* cos(M_PI / 6) * SCALE;
			point.y2 = 200 + (grid[i + 1][j].x + grid[i + 1][j].y
					- grid[i + 1][j].z) * sin(M_PI / 6) * SCALE;
			ft_algo_besenham(&point, img);
			i++;
		}
		j++;
	}
}

void	ft_draw_width(t_coor **grid, t_dim *area, t_mlx_img *img)
{
	int		i;
	int		j;
	t_point	point;

	i = 0;
	while (i < area->height)
	{
		j = 0;
		while (j < area->width - 1)
		{
			point.x1 = 960 + (grid[i][j].x - grid[i][j].y)
				* cos(M_PI / 6) * SCALE;
			point.y1 = 200 + (grid[i][j].x + grid[i][j].y - grid[i][j].z)
				* sin(M_PI / 6) * SCALE;
			point.x2 = 960 + (grid[i][j + 1].x - grid[i][j + 1].y)
				* cos(M_PI / 6) * SCALE;
			point.y2 = 200 + (grid[i][j + 1].x + grid[i][j + 1].y
					- grid[i][j + 1].z) * sin(M_PI / 6) * SCALE;
			point.dx = abs(point.x2 - point.x1);
			point.dy = abs(point.y2 - point.y1) * (-1);
			ft_algo_besenham(&point, img);
			j++;
		}
		i++;
	}
}

void	ft_draw_grid(t_coor **grid, t_dim *area, t_mlx_img *img)
{
	int	i;
	int	j;

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
	ft_draw_width(grid, area, img);
	ft_draw_height(grid, area, img);
}
