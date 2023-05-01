/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:50:50 by utygett           #+#    #+#             */
/*   Updated: 2021/10/27 14:56:41 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

# define BUFF_SIZE 4096

typedef struct s_h_col
{
	int	z;
	int	color;
}	t_h_col;

typedef struct s_draw
{
	float	deltax;
	float	deltay;
	int		z1;
	int		z2;
	int		max;
	float	x1;
	float	y1;
}	t_draw;

typedef struct s_map
{
	int		col;
	int		row;
	t_h_col	**field;
	float	x;
	float	y;
	float	b_x;
	float	b_y;
	int		color;
	int		zoom;
	int		cos;
	int		sin;
	float	angle_cos;
	float	angle_sin;
	float	z;
	int		isometric;
	int		error_read;
}	t_map;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		zoom;
	t_map	*map;
}				t_vars;

int		ft_atoi(const char *str);
void	get_map(char *file_name, t_map *map);
int		ft_strlen(const char *s);
char	*ft_realloc(char *str1, char *str2);
char	**get_line(char *file_name, t_map *map);
char	**ft_split(char const *s, char c);
int		hex_to_int(char *str);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_max(int a, int b);
void	from_2d_to_3d(float *x, float *y, int z, t_map *map);
void	draw_zoom(float *x1, float *x2, int shift, int zoom);
void	draw_delta(t_draw *draw, float x, float y);
void	drawLine(float x2, float y2, t_data *img, t_vars *vars);
void	check_some_key(int keycode, t_vars *vars);
int		key_h(int keycode, t_vars *vars);
void	ft_mlx(t_vars *vars);
char	**ft_error(int a, t_map *map, char *str);
void	delta_up(t_draw *draw);

#endif