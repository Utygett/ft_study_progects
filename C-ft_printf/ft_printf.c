/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 23:18:51 by utygett           #+#    #+#             */
/*   Updated: 2021/10/21 14:27:43 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	p_valist;
	size_t	res;

	res = 0;
	va_start(p_valist, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{	
			res += check_format((char *)str, p_valist);
			if (*(str + 1) == '%')
				res = res + write_char('%');
			str = str + 2;
		}
		else
		{
			write(1, str, 1);
			str++;
			res++;
		}
	}
	va_end(p_valist);
	return (res);
}

int	check_format(char *str, va_list p_valist)
{	
	str++;
	if (*str == 'c')
		return (write_char(va_arg(p_valist, int)));
	if (*str == 's')
		return (write_str(va_arg(p_valist, char *)));
	if (*str == 'd' || *str == 'i')
		return (write_int(va_arg(p_valist, int)));
	if (*str == 'u')
		return (write_unsigned_int(va_arg(p_valist, unsigned int)));
	if (*str == 'x')
		return (write_hex_lower(va_arg(p_valist, unsigned int)));
	if (*str == 'X')
		return (write_hex_upper(va_arg(p_valist, unsigned int)));
	if (*str == 'p')
		return (write_hex_pointer(va_arg(p_valist, long unsigned int)));
	return (0);
}

int	write_hex_lower(unsigned int n)
{
	char	str[17];
	int		i;
	char	*hex_base;

	hex_base = "0123456789abcdef";
	i = 0;
	while (n || i == 0)
	{	
		str[i] = hex_base[n % 16];
		n = n / 16;
		i++;
	}
	str[i] = '\0';
	str_reverse(str);
	return (write_str(str));
}

int	write_hex_upper(unsigned int n)
{
	char	str[17];
	int		i;
	char	*hex_base;

	hex_base = "0123456789ABCDEF";
	i = 0;
	while (n || i == 0)
	{	
		str[i] = hex_base[n % 16];
		n = n / 16;
		i++;
	}
	str[i] = '\0';
	str_reverse(str);
	return (write_str(str));
}

int	write_hex_pointer(long unsigned int n)
{
	char	str[19];
	int		i;
	char	*hex_base;

	hex_base = "0123456789abcdef";
	i = 0;
	while (n || i == 0)
	{	
		str[i] = hex_base[n % 16];
		n = n / 16;
		i++;
	}
	str[i] = 'x';
	str[i + 1] = '0';
	str[i + 2] = '\0';
	str_reverse(str);
	return (write_str(str));
}
