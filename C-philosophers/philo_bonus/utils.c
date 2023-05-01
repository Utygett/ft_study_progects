/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:22:12 by utygett           #+#    #+#             */
/*   Updated: 2021/11/25 12:34:50 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	write_str(char *str)
{
	int	size;

	size = 0;
	while (*(str + size))
		size++;
	return (write(1, str, size));
}

void	str_reverse(char *str)
{	
	int		i;
	int		size;
	char	b;

	i = 0;
	size = 0;
	if (*str == '-')
		str++;
	while (*(str + size))
		size++;
	while (size / 2 > i)
	{
		b = *(str + i);
		*(str + i) = *(str + (size - i - 1));
		*(str + (size - i - 1)) = b;
		i++;
	}
}

long	write_long(long long n)
{
	char	str[24];
	int		i;

	i = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		i++;
	}
	while (n || (i == 0 && n == 0))
	{	
		str[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	str[i] = '\0';
	str_reverse(str);
	return (write_str(str));
}

int	write_int(int n)
{
	char	str[12];
	int		i;

	i = 0;
	if (n == -2147483648)
		return (write_str("-2147483648"));
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		i++;
	}
	while (n || (i == 0 && n == 0))
	{	
		str[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	str[i] = '\0';
	str_reverse(str);
	return (write_str(str));
}

int	ft_atoi(char *str)
{
	long long int	res;
	int				i;
	int				sign;

	res = 0;
	i = 0;
	sign = 1;
	if (!('0' <= *(str + i) && *(str + i) <= '9'))
		return (-1);
	while ('0' <= *(str + i) && *(str + i) <= '9')
	{
		res = (res * 10) + (*(str + i) - 48) * sign;
		i++;
	}
	if (*(str + i))
		return (-1);
	return (res);
}
