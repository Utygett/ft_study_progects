/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 09:23:54 by utygett           #+#    #+#             */
/*   Updated: 2021/10/27 13:48:40 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	check_some_key(int keycode, t_vars *vars)
{
	if (keycode == 69)
		vars->zoom += 1;
	if (keycode == 78 && vars->zoom > 1)
		vars->zoom -= 1;
	if (keycode == 126)
		vars->map->sin -= 10;
	if (keycode == 125)
		vars->map->sin += 10;
	if (keycode == 124)
		vars->map->cos += 10;
	if (keycode == 123)
		vars->map->cos -= 10;
}

void	finish_program(t_vars *vars)
{
	if (vars->mlx && vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	while (vars->map->row--)
	{
		free(vars->map->field[vars->map->row]);
	}
	free(vars->map->field);
	exit(0);
}

int	key_h(int keycode, t_vars *vars)
{	
	check_some_key(keycode, vars);
	if (keycode == 91)
		vars->map->angle_sin += 0.05;
	if (keycode == 84)
		vars->map->angle_sin -= 0.05;
	if (keycode == 86)
		vars->map->angle_cos += 0.05;
	if (keycode == 88)
		vars->map->angle_cos -= 0.05;
	if (keycode == 92)
		vars->map->z += 0.1;
	if (keycode == 89 && vars->map->z)
		vars->map->z -= 0.1;
	if (keycode == 53)
		finish_program(vars);
	if (keycode == 87)
	{
		if (vars->map->isometric == 0)
			vars->map->isometric = 1;
		else
			vars->map->isometric = 0;
	}
	ft_mlx(vars);
	return (0);
}

char	**ft_error(int a, t_map *map, char *str)
{	
	free(str);
	map->error_read = 1;
	if (a == 1)
		write(2, "Can't open file", 15);
	if (a == 2)
		write(2, "Can't read file", 15);
	return (NULL);
}

void	delta_up(t_draw *draw)
{
	draw->x1 += draw->deltax;
	draw->y1 += draw->deltay;
}
