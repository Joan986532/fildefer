/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_and_buttons.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:24:16 by jnauroy           #+#    #+#             */
/*   Updated: 2025/02/03 14:45:22 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	ft_destroy(t_mlx_data *data)
{
	if (data->img.mlx_img)
		mlx_destroy_image(data->mlx, data->img.mlx_img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	if (data->grid)
		ft_free_tab(data->grid, data->area.height - 1);
	free(data->mlx);
	exit(1);
}

int	close_window(void *data)
{
	ft_destroy(data);
	return (0);
}

int	ft_key_press(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
		ft_destroy(data);
	return (0);
}
