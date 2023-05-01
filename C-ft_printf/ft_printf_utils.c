/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:15:39 by utygett           #+#    #+#             */
/*   Updated: 2021/10/21 14:24:52 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	write_char(char a)
{
	write(1, &a, 1);
	return (1);
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

int	write_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*(str + i))
	{
		write(1, str + i, 1);
		i++;
	}
	return (i);
}

int	write_unsigned_int(unsigned int n)
{
	char	str[12];
	int		i;

	i = 0;
	while (n || i == 0)
	{	
		str[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	str[i] = '\0';
	str_reverse(str);
	return (write_str(str));
}
