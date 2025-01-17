/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:13:24 by jnauroy           #+#    #+#             */
/*   Updated: 2025/01/17 18:42:44 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	return (0);
}
/*
int	change_color(t_mlx_data *data)
{
	mlx_string_put(data->mlx, data->win, 150, 150, data->color, "color changing");
	if (data->color == 0xFF0000)
		data->color = 0x00FF00;
	else if (data->color == 0x00FF00)
		data->color = 0x0000FF;
	else
		data->color = 0xFF0000;
	return (0);
}
*/
int	render_rect(t_mlx_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			my_pixel_put(img, j++, i, 0x00FF00);
		++i;
	}
	return (0);
}

void	render_background(t_mlx_img *img, int color)
{
	int i;
	int j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
			my_pixel_put(img, j++, i, color);
		i++;
	}
}

int	render(t_mlx_data *data)
{
	if (data->win == NULL)
		return (1);
	render_map(&data->img, 0xFFFFFF);
	render_background(&data->img, 0x000000);
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
	return (0);
}

int render_map(t_map_size *dim, t_mlx_img *img, int color)
{
	int start_x;
	int start_y;

	dim->center_x = width / 2 + 1;
	dim->center_y = height / 2 + 1;
	start_x =  


}
int	main(int argc, char **argv)
{
	t_mlx_data	data;
	int			**map;
	t_map_size	dimensions;

	if (argc != 2)
		return (1);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (1);
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Hello world!");
	if (data.win == NULL)
	{
		free(data.mlx);
		free(data.win);
		return (1);
	}
	data.img.mlx_img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_key_hook(data.win, handle_input, &data);
	map = ft_pars_map(argv[1], &dimensions);
	if (!map)
		return (1);
	mlx_loop(data.mlx);
}
