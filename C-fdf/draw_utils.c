/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 09:15:19 by utygett           #+#    #+#             */
/*   Updated: 2021/10/27 13:48:33 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

void	from_2d_to_3d(float *x, float *y, int z, t_map *map)
{	
	if (map->isometric == 1)
	{
		*x = (*x - *y) * cos(map->angle_cos);
		*y = ((*x + *y) * sin(map->angle_sin) - z * map->z);
	}
}

void	draw_zoom(float *x1, float *x2, int shift, int zoom)
{
	*x1 = ((*x1) + shift) * zoom;
	*x2 = ((*x2) + shift) * zoom;
}

void	draw_delta(t_draw *draw, float x, float y)
{
	draw->deltax = x;
	draw->deltay = y;
	draw->max = ft_max(fabsf(draw->deltax), fabsf(draw->deltay));
	draw->deltax /= draw->max;
	draw->deltay /= draw->max;
}
