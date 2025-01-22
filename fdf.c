/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:13:24 by jnauroy           #+#    #+#             */
/*   Updated: 2025/01/22 16:44:05 by jnauroy          ###   ########.fr       */
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

int	render(t_mlx_data *data)
{
	if (data->win == NULL)
		return (1);
	return (0);
}

int	ft_init_fdf(int argc, t_mlx_data *data)
{
	if (argc != 2)
		return (1);
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (1);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Hello world!");
	if (data->win == NULL)
	{
		free(data->mlx);
		free(data->win);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx_data	data;
	t_dim		dimensions;
	t_coor		**grid;

	if (ft_init_fdf(argc, &data))
		return (1);
	data.img.mlx_img = mlx_new_image(data.mlx, 1920, 1080);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	//mlx_loop_hook(data.mlx, &render, &data);
	mlx_key_hook(data.win, handle_input, &data);
	grid = ft_pars_map(argv[1], &dimensions);
	if (!grid)
		return (1);
	printf("test1\n");
	ft_draw_grid(grid, &dimensions, &data.img);
	ft_bresenham(grid, &dimensions, &data.img);
	mlx_put_image_to_window(data.mlx, data.win, data.img.mlx_img, 0, 0);
	mlx_loop(data.mlx);
}
