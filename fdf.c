/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:13:24 by jnauroy           #+#    #+#             */
/*   Updated: 2025/01/16 17:21:05 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	handle_input(int keysym, t_mlx_data *data, t_img_data *img_data)
{
	(void)img_data;
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	return (0);
}

int	**ft_pars_map(char *map, t_map_size *dimensions)
{
	int fd;
	char *line;
	int **tab;
	
	dimensions->width = 0;
	dimensions->height = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		dimensions->height++;
		if (ft_countword((const char *)line, ' ') >= dimensions->width)
			dimensions->width = ft_countword((const char *)line, ' ');
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	tab = ft_malloc_tab(dimensions);
	if(!tab)
			return (NULL);
	ft_fill_tab(map, tab);
	return (tab);
}

void ft_fill_tab(char *map, int **tab)
{
	int		fd;
	int 	i;
	int		j;
	char	*line;
	char	**arg_split;
	
	j = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		arg_split = ft_split(line, ' ');
		free(line);
		while (arg_split[i])
		{
			tab[j][i] = ft_atoi((const char *)arg_split[i]);
			i++;
		}
		j++;
		arg_split = ft_free(arg_split, i);
		line = get_next_line(fd);
	}
	free(line);
}

int change_color(t_mlx_data *data)
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

int main(int argc, char **argv)
{
	(void)argv;
	t_img_data	img;
	t_mlx_data	data;
	//int			**map;
	//t_map_size	dimensions;

	if (argc != 2)
		return (1);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (1);
	/*data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Hello world!");
	if (data.win == NULL)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		return (1);
	}
	mlx_key_hook(data.win, handle_input, &data);
	map = ft_pars_map(argv[1], &dimensions);
	if (!map)
		return (1);*/
	img.img = mlx_new_image(data.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	/*mlx_put_image_to_window(data.mlx, data.win, img.img, &img.line_length, &img.endian);

	mlx_loop_hook(data.mlx, change_color, &data); 
	mlx_loop(data.mlx);*/
}
