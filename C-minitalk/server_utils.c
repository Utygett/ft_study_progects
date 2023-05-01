/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:59:25 by utygett           #+#    #+#             */
/*   Updated: 2021/11/16 14:19:45 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

int	ft_strlen(char *s)
{	
	int	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

void	str_reverse(char *str)
{	
	int		i;
	char	b;
	int		j;

	i = 0;
	if (*str == '-')
		str++;
	j = ft_strlen(str);
	while (j / 2 > i)
	{
		b = *(str + i);
		*(str + i) = *(str + (j - i - 1));
		*(str + (j - i - 1)) = b;
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	str[12];
	int		i;

	i = 0;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		while (n || (i == 0 && n == 0))
		{	
			str[i] = (n % 10) + '0';
			n = n / 10;
			i++;
		}
		str[i] = '\0';
		str_reverse(str);
		write(fd, str, ft_strlen(str));
	}
}
