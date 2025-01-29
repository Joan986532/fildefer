/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:49:10 by jnauroy           #+#    #+#             */
/*   Updated: 2025/01/29 16:42:57 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	ft_init_besenham(t_point *point)
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
	point->error = point->dx + point->dy;
}

void	ft_algo_besenham(t_point *point, t_mlx_img *img)
{
	ft_init_besenham(point);
	while (1)
	{
		//if (point->x1 < WIDTH && point->y1 < HEIGHT
		//	&& point->x1 >= 0 && point->y1 >= 0)
		my_pixel_put(img, point->x1, point->y1, 0xFF00FF);
		if (point->x1 == point->x2 && point->y1 == point->y2)
			break ;
		point->error2 = 2 * point->error;
		if (point->error2 >= point->dy)
		{
			if (point->x1 == point->x2)
				break ;
			point->error += point->dy;
			point->x1 += point->sx;
		}
		if (point->error2 <= point->dx)
		{
			if (point->y1 == point->y2)
				break ;
			point->error += point->dx;
			point->y1 += point->sy;
		}
	}
}

void	ft_draw_height(t_coor **grid, t_dim *area, t_mlx_img *img)
{
	int		j;
	int		i;
	t_point	point;

	j = 0;
	while (j < area->width)
	{
		i = 0;
		while (i < area->height - 1)
		{
			point.x1 = grid[i][j].x;
			point.y1 = grid[i][j].y;
			point.x2 = grid[i + 1][j].x;
			point.y2 = grid[i + 1][j].y;
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
			point.x1 = grid[i][j].x;
			point.y1 = grid[i][j].y;
			point.x2 = grid[i][j + 1].x;
			point.y2 = grid[i][j + 1].y;
			point.dx = abs(point.x2 - point.x1);
			point.dy = abs(point.y2 - point.y1) * (-1);
			ft_algo_besenham(&point, img);
			j++;
		}
		i++;
	}
}

void	ft_draw_map(t_coor **grid, t_dim *area, t_mlx_img *img, t_zoom *z)
{
	int		i;
	int		j;
	int		x;

	i = 0;
	while (i < area->height)
	{
		j = 0;
		while (j < area->width)
		{
			x = grid[i][j].x;
			grid[i][j].x = MID_X + (x - grid[i][j].y) * cos(M_PI / 6) * z->zoom;
			grid[i][j].y = MID_Y + (x + grid[i][j].y - grid[i][j].z)
				* sin(M_PI / 6) * z->zoom;
			my_pixel_put(img, grid[i][j].x, grid[i][j].y, 0xFF00FF);
			j++;
		}
		i++;
	}
	ft_draw_width(grid, area, img);
	ft_draw_height(grid, area, img);
}
