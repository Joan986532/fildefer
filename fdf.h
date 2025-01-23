/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:14:43 by jnauroy           #+#    #+#             */
/*   Updated: 2025/01/23 15:06:41 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "Libft/libft.h"
# include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# define WIDTH	1920
# define HEIGHT	1080

# define SCALE 20
# define START_X 800
# define START_Y 200

typedef struct s_mlx_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}			t_mlx_img;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win;
	t_mlx_img	img;
}			t_mlx_data;

typedef struct s_map_size
{
	int	width;
	int	height;
	int	center_x;
	int	center_y;
}		t_dim;

typedef struct s_coordinates
{
	int	x;
	int	y;
	int	z;
}		t_coor;

typedef struct s_grid_coor
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
}		t_point;

//fdf.c
int		main(int argc, char **argv);
void	ft_draw_grid(t_coor **grid, t_dim *area, t_mlx_img *img);

//parsing_tab.c
void	ft_fill_tab(char *map, t_coor **tab);
t_coor	**ft_pars_map(char *map, t_dim *dimensions);
void	ft_fill_tabstruct(char *line, int j, t_coor **tab);

//fdf_utils.c
void	my_pixel_put(t_mlx_img *img, int x, int y, int color);
t_coor	**ft_malloc_tab(t_dim *dimensions);
t_coor	**ft_free_tab(t_coor **tab, int i);
void	**ft_free_split(char **split_tab, int j);

//get_next_line.c
char	*get_next_line(int fd);
char	*ft_write_right(char *buffer);
char	*ft_write_left(char *string);
int		ft_free_gnl(char *buffer, char *temp, char *string, char *sentence);
char	*ft_read_buffer(int fd, char *buffer, char *string);

//draw_grid.c
void	ft_init_besenham(t_point *point, int *error);
void	ft_algo_besenham(t_point *point, t_mlx_img *img);
void	ft_draw_height(t_coor **grid, t_dim *area, t_mlx_img *img);
void	ft_draw_width(t_coor **grid, t_dim *area, t_mlx_img *img);
void	ft_draw_grid(t_coor **grid, t_dim *area, t_mlx_img *img);
#endif
