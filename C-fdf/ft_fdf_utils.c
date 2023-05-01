/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 22:58:41 by utygett           #+#    #+#             */
/*   Updated: 2021/10/27 13:48:29 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int	ft_atoi(const char *str)
{
	long long int		res;
	int					a;

	a = 1;
	res = 0;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			a = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * a);
}

int	ft_strlen(const char *s)
{	
	int	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

int	hex_to_int(char *str)
{	
	int		val;
	char	byte;
	char	*str1;

	str1 = str;
	val = 0;
	if (*str == '0' && *(str + 1) == 'x')
		str = str + 2;
	while (('0' <= *str && *str <= '9')
		|| ('a' <= *str && *str <= 'f') || ('A' <= *str && *str <= 'F'))
	{
		byte = *str;
		if (byte >= '0' && byte <= '9')
			byte = byte - '0';
		else if (byte >= 'a' && byte <= 'f')
			byte = byte - 'a' + 10;
		else if (byte >= 'A' && byte <= 'F')
			byte = byte - 'A' + 10;
		val = (val << 4) | (byte & 0xF);
		str++;
	}
	return (val);
}
