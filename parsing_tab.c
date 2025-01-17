/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:43:25 by jnauroy           #+#    #+#             */
/*   Updated: 2025/01/17 11:44:26 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

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
