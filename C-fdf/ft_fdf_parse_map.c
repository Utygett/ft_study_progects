/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_parse_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 22:59:50 by utygett           #+#    #+#             */
/*   Updated: 2021/10/27 11:57:30 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

char	**get_line(char *file_name, t_map *map)
{	
	int		fd;
	int		ret;
	char	*line_for_split;
	char	buff[BUFF_SIZE + 1];
	char	**str;

	ret = 1;
	line_for_split = malloc(1);
	*line_for_split = '\0';
	fd = open(file_name, O_RDONLY);
	if (fd <= 0)
		return (ft_error(1, map, line_for_split));
	while (ret)
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret <= 0 && (!*line_for_split))
			return (ft_error(2, map, line_for_split));
		buff[ret] = '\0';
		if (ret)
			line_for_split = ft_realloc(line_for_split, buff);
	}
	close(fd);
	str = ft_split(line_for_split, '\n');
	free(line_for_split);
	return (str);
}

char	*ft_realloc(char *str1, char *str2)
{
	char	*new_line;
	int		i;

	i = 0;
	new_line = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	while (*(str1 + i))
	{	
		*(new_line + i) = *(str1 + i);
		i++;
	}
	while (*str2)
	{
		*(new_line + i) = *str2;
		i++;
		str2++;
	}
	*(new_line + i) = '\0';
	free(str1);
	return (new_line);
}

void	str_nbr_to_int(t_map *map, char *str, int x)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (*(str + i))
	{	
		if (*(str + i) != ' ')
		{	
			map->field[x][y].z = ft_atoi((str + i));
			map->field[x][y].color = 0xffff;
			while ('0' <= *(str + i) && *(str + i) <= '9')
				i++;
			if (*(str + i) == ',')
				map->field[x][y].color = hex_to_int(str + i + 1);
			y++;
		}
		while (*(str + i) && *(str + i) != ' ' && *(str + i))
			i++;
		if (*(str + i) && *(str + i) == ' ')
			i++;
	}
	free(str);
}

void	str_to_int(char **map_str, t_map *map)
{	
	int		x;
	char	*str;

	x = 0;
	map->sin = 0;
	map->cos = 0;
	map->angle_cos = 1;
	map->angle_sin = 1;
	map->z = 1;
	map->isometric = 1;
	map->field = malloc(sizeof(t_h_col *) * map->row);
	while (map->row > x)
	{	
		map->field[x] = malloc(sizeof(t_h_col) * map->col);
		str_nbr_to_int(map, *map_str, x);
		map_str++;
		x++;
	}
}

void	get_map(char *file_name, t_map *map)
{	
	int		i;
	int		**map_int;
	char	**map_str;

	i = 0;
	map->row = 0;
	map->col = 0;
	map->x = 0;
	map->y = 0;
	map->error_read = 0;
	map_str = get_line(file_name, map);
	if (!map_str)
		return ;
	while (*(*map_str + i))
	{
		if (*(*map_str + i) != ' '
			&& (*(*map_str + i + 1) == ' ' || *(*map_str + i + 1) == '\0'))
			map->col++;
		i++;
	}
	while (*(map_str + map->row))
		map->row++;
	str_to_int(map_str, map);
	free(map_str);
}
