/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:14:43 by jnauroy           #+#    #+#             */
/*   Updated: 2025/02/01 15:09:24 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "Libft/libft.h"
# include <X11/X.h>
# include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# define WIDTH	1920
# define HEIGHT	1080

# define WFIG 1536
# define HFIG 864

# define MID_X 960
# define MID_Y 540

# define FIG_X 768
# define FIG_Y 432

typedef struct s_mlx_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}			t_mlx_img;

typedef struct s_map_size
{
	int	width;
	int	height;
	int	center_x;
	int	center_y;
}		t_dim;

typedef struct s_coordinates
{
	float	x;
	float	y;
	float	z;
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
	int	error;
	int	error2;
}		t_point;

typedef struct s_zoom
{
	float	max_y;
	float	min_y;
	float	y_mid;
	float	x_mid;
	float	zoom;
}			t_zoom;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win;
	t_mlx_img	img;
	t_coor		**grid;
	t_dim		area;
	t_zoom		zoom;
}				t_mlx_data;

//fdf.c
int		main(int argc, char **argv);
void	ft_destroy(t_mlx_data *data);

//pars_n_grid.c
int		ft_fill_tab(char *map, t_coor **tab, t_dim *dimensions);
int		ft_pars_map(t_mlx_data *data, char *map);
int		ft_fill_tabstruct(char *line, int j, t_coor **tab, t_dim *dimensions);
int		ft_draw_grid(t_coor ***grid, char *map, t_dim *are, t_mlx_img *img);
void	ft_draw_points(t_coor **grid, t_dim *area, t_mlx_img *img, int z);

//fdf_utils.c
void	my_pixel_put(t_mlx_img *img, int x, int y, int color);
t_coor	**ft_malloc_tab(t_dim *dimensions);
t_coor	**ft_free_tab(t_coor **tab, int i);
void	**ft_free_split(char **split_tab, int j);
t_coor	**ft_copy_grid(t_coor **grid, t_dim *area);

//get_next_line.c
char	*get_next_line(int fd);
char	*ft_write_right(char *buffer);
char	*ft_write_left(char *string);
int		ft_free_gnl(char *buffer, char *temp, char *string, char *sentence);
char	*ft_read_buffer(int fd, char *buffer, char *string);

//draw_grid.c
void	ft_algo_besenham(t_point *point, t_mlx_img *img);
void	ft_draw_height(t_coor **grid, t_dim *area, t_mlx_img *img);
void	ft_draw_width(t_coor **grid, t_dim *area, t_mlx_img *img);
void	ft_draw_map(t_coor **grid, t_dim *area, t_mlx_img *img, t_zoom *z);

//rotations
void	ft_rotate_clock(t_coor **grid, t_dim *area);
void	ft_zoom(t_coor **copy, t_mlx_data *data);

//get_zoom_scale.c
float	ft_get_height(t_coor **grid, int i, int j, int flag);
void	ft_get_zoom(t_coor **grid, t_dim *area, t_zoom *z);

//keys_and_buttons.c
int		ft_key_press(int keysym, t_mlx_data *data);
int		close_window(void *data);
void	ft_destroy(t_mlx_data *data);

#endif
