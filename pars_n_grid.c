/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_n_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:43:25 by jnauroy           #+#    #+#             */
/*   Updated: 2025/02/03 15:25:28 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	ft_count_tab(int fd, t_dim *dimensions)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		return (1);
	}
	while (line)
	{
		dimensions->height++;
		if (ft_countword((const char *)line, ' ') >= dimensions->width)
			dimensions->width = ft_countword((const char *)line, ' ');
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	dimensions->center_x = dimensions->width / 2;
	dimensions->center_y = dimensions->height / 2;
	return (0);
}

int	ft_pars_map(t_mlx_data *data, char *map)
{
	int		fd;

	data->area.width = 0;
	data->area.height = 0;
	fd = open(map, O_RDONLY);
	if (ft_count_tab(fd, &data->area))
		ft_destroy(data);
	close(fd);
	data->grid = ft_malloc_tab(&data->area);
	if (!data->grid)
		ft_destroy(data);
	if (ft_fill_tab(map, data->grid, &data->area))
		ft_destroy(data);
	ft_get_zoom(data->grid, &data->area, &data->zoom);
	return (0);
}

int	ft_fill_tabstruct(char *line, int j, t_coor **tab, t_dim *dimensions)
{
	int		i;
	char	**arg_split;

	i = 0;
	arg_split = ft_split(line, ' ');
	if (!arg_split)
		return (1);
	while (arg_split[i])
	{
		tab[j][i].x = i - dimensions->center_x;
		tab[j][i].y = j - dimensions->center_y;
		tab[j][i].z = ft_atoi((const char *)arg_split[i]);
		i++;
	}
	ft_free_split(arg_split, i);
	while (i < dimensions->width)
	{
		tab[j][i].x = i - dimensions->center_x;
		tab[j][i].y = j - dimensions->center_y;
		tab[j][i].z = 0;
		i++;
	}
	return (0);
}

int	ft_fill_tab(char *map, t_coor **tab, t_dim *dimensions)
{
	int		fd;
	int		j;
	char	*line;

	j = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	if (!line)
		return (1);
	while (line)
	{
		if (ft_fill_tabstruct(line, j, tab, dimensions))
		{
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
		j++;
	}
	free(line);
	return (0);
}
