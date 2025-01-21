/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:43:25 by jnauroy           #+#    #+#             */
/*   Updated: 2025/01/21 14:15:45 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

t_coor	**ft_pars_map(char *map, t_dim *dimensions)
{
	int fd;
	char *line;
	t_coor **tab;
	
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
	dimensions->center_x = dimensions->width / 2 + 1;
	dimensions->center_y = dimensions->height / 2 + 1;
	free(line);
	close(fd);
	tab = ft_malloc_tab(dimensions);
	if(!tab)
			return (NULL);
	ft_fill_tab(map, tab);
	return (tab);
}

void ft_fill_tabstruct(char *line, int j, t_coor **tab)
{
	int		i;
	char	**arg_split;

	i = 0;
	arg_split = ft_split(line, ' ');
	free(line);
	while (arg_split[i])
	{
		tab[j][i].x = i;
		tab[j][i].y = j;
		tab[j][i].z = ft_atoi((const char *)arg_split[i]);
		i++;
	}
	arg_split = ft_free(arg_split, i);
}

void ft_fill_tab(char *map, t_coor **tab)
{
	int		fd;
	int		j;
	char	*line;
	
	j = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		ft_fill_tabstruct(line, j, tab);
		line = get_next_line(fd);
		j++;
	}
	free(line);
}
