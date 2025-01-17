/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:14:43 by jnauroy           #+#    #+#             */
/*   Updated: 2025/01/16 17:11:04 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "Libft/libft.h"
# include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define WIDTH	1920
# define HEIGHT	1080

typedef struct s_data
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img_data;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	int		color;
}			t_mlx_data;

typedef struct s_map_size
{
	int	width;
	int height;
}		t_map_size;

//fdf.c
int		main(int argc, char **argv);
void	ft_fill_tab(char *map, int **tab);
int		**ft_pars_map(char *map, t_map_size *dimensions);

//fdf_utils.c
void	my_pixel_put(t_img_data *data, int x, int y, int color);
int		**ft_malloc_tab(t_map_size *dimensions);
int		**ft_free_tab(int **tab, int i);

//get_next_line.c
char	*get_next_line(int fd);
char	*ft_write_right(char *buffer);
char	*ft_write_left(char *string);
int		ft_free_gnl(char *buffer, char *temp, char *string, char *sentence);
char	*ft_read_buffer(int fd, char *buffer, char *string);

/*void	ft_circle(t_img_data *img)
{
	int angle;

	angle = 0;
	while (angle < 10000)
	{
		my_pixel_put(img, 960 + (cos(angle) * 400), 500 + (sin(angle) * 400),
				0x00FF00);
		angle++;
	}
}*/


#endif
