/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:19:11 by utygett           #+#    #+#             */
/*   Updated: 2021/10/27 13:48:42 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	draw_line(float x2, float y2, t_data *img, t_vars *vars)
{
	t_draw	draw;

	draw.x1 = vars->map->x;
	draw.y1 = vars->map->y;
	draw.z1 = 0;
	draw.z2 = 0;
	if (draw.y1 < vars->map->row && draw.x1 < vars->map->col
		&& y2 < vars->map->row && x2 < vars->map->col)
	{
		draw.z1 = vars->map->field[(int)draw.y1][(int)draw.x1].z;
		draw.z2 = vars->map->field[(int)y2][(int)x2].z;
	}
	vars->map->color = vars->map->field[(int)draw.y1][(int)draw.x1].color;
	from_2d_to_3d(&x2, &y2, draw.z2, vars->map);
	from_2d_to_3d(&draw.x1, &draw.y1, draw.z1, vars->map);
	draw_zoom(&draw.x1, &x2, vars->map->cos, vars->map->zoom);
	draw_zoom(&draw.y1, &y2, vars->map->sin, vars->map->zoom);
	draw_delta(&draw, x2 - draw.x1, y2 - draw.y1);
	while ((int)(draw.x1 - x2) || (int)(draw.y1 - y2))
	{	
		if (draw.x1 > 1898 || draw.y1 > 998 || draw.y1 < 0 || draw.x1 < 0)
			break ;
		my_mlx_pixel_put(img, draw.x1, draw.y1, vars->map->color);
		delta_up(&draw);
	}
}

void	ft_mlx(t_vars *vars)
{
	t_data	img;

	vars->map->zoom = vars->zoom;
	img.img = mlx_new_image(vars->mlx, 1900, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	while (vars->map->y < vars->map->row)
	{	
		while (vars->map->x < vars->map->col)
		{	
			if (vars->map->y < vars->map->row - 1)
				draw_line(vars->map->x, vars->map->y + 1, &img, vars);
			if (vars->map->x < vars->map->col - 1)
				draw_line(vars->map->x + 1, vars->map->y, &img, vars);
			vars->map->x++;
		}
		vars->map->x = 0;
		vars->map->y++;
	}
	vars->map->y = 0;
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
}

void	check_size_and_start_pos(t_vars *vars)
{
	if (vars->map->row <= 20 && vars->map->col <= 20)
	{
		vars->map->sin += 20;
		vars->map->cos += 60;
		vars->zoom = 15;
	}
	else if (vars->map->row <= 50 && vars->map->col <= 50)
	{
		vars->map->sin += 10;
		vars->map->cos += 50;
		vars->zoom = 15;
	}
	else if (vars->map->row <= 100 && vars->map->col <= 100)
	{
		vars->zoom = 6;
		vars->map->cos += 130;
	}
	else if (vars->map->row <= 500 && vars->map->col <= 500)
	{
		vars->zoom = 2;
		vars->map->cos += 420;
	}
}

int	main(int argc, char **argv)
{	
	int		fd;
	t_map	map;
	t_vars	vars;

	if (argc == 2)
	{
		get_map(*(argv + 1), &map);
		if (map.error_read != 0)
		{
			return (1);
		}
		vars.zoom = 1;
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, 1900, 1000, "fdf");
		vars.map = &map;
		check_size_and_start_pos(&vars);
		mlx_hook(vars.win, 02, (1L << 0), &key_h, &vars);
		ft_mlx(&vars);
		mlx_loop(vars.mlx);
	}
}
