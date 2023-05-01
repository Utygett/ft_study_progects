/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:27:15 by utygett           #+#    #+#             */
/*   Updated: 2021/11/14 12:05:44 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_and_exit(t_push *swap)
{
	free(swap->afree);
	write(2, "Error\n", 6);
	exit (1);
}

void	free_and_exit_ko(t_push *swap)
{
	free(swap->afree);
	write(2, "KO\n", 3);
	exit (1);
}

int	ft_atoi(char *str, t_push *swap)
{
	long long int	res;
	int				i;
	int				sign;

	res = 0;
	i = 0;
	sign = 1;
	if (!(*str))
		free_and_exit(swap);
	if (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
			sign = -sign;
		i++;
		if (!(*(str + i)))
			free_and_exit(swap);
	}
	while ('0' <= *(str + i) && *(str + i) <= '9')
	{
		res = (res * 10) + (*(str + i) - 48) * sign;
		i++;
	}
	if (*(str + i) || res > 2147483647 || res < -2147483648)
		free_and_exit(swap);
	return (res);
}

void	check_double(t_push *swap)
{
	int	i;
	int	j;

	i = 0;
	while (swap->size_a > i)
	{
		j = i;
		while (swap->size_a - 1 > j)
		{
			if (swap->a[i] == swap->a[j + 1])
				free_and_exit(swap);
			j++;
		}
		i++;
	}
}

int	check_sorting(t_push *swap, char sym)
{
	int	i;

	i = 0;
	while (swap->size_a - 1 > i && sym == 'a')
	{
		if (!(swap->a[i] < swap->a[i + 1]))
			return (0);
		i++;
	}
	while (swap->size_b - 1 > i && sym == 'b')
	{
		if (!(swap->b[i] > swap->b[i + 1]))
			return (0);
		i++;
	}
	return (1);
}
