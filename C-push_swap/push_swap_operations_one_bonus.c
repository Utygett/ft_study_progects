/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_one_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:33:24 by utygett           #+#    #+#             */
/*   Updated: 2021/11/14 16:17:50 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rev_rotate(t_push *swap, char sym, char real)
{
	int	i;
	int	buf;

	i = -1;
	if (swap->size_a > 1 && (sym == 'a' || sym == 'c'))
	{
		buf = swap->a[swap->size_a - 1];
		while (swap->size_a > ++i)
			swap->a[swap->size_a - i] = swap->a[swap->size_a - i - 1];
		swap->a[0] = buf;
	}
	i = -1;
	if (swap->size_b > 1 && (sym == 'b' || sym == 'c'))
	{
		buf = swap->b[swap->size_b - 1];
		while (swap->size_b > ++i)
			swap->b[swap->size_b - i] = swap->b[swap->size_b - i - 1];
		swap->b[0] = buf;
	}
	if (sym == 'a' && real == 'r')
		write(1, "rra\n", 4);
	else if (sym == 'b' && real == 'r')
		write(1, "rrb\n", 4);
	else if (sym == 'c' && real == 'r')
		write(1, "rrr\n", 4);
}

void	rotate(t_push *swap, char sym, char real)
{
	int	i;
	int	buf;

	i = -1;
	if (swap->size_a > 1 && (sym == 'a' || sym == 'c'))
	{
		buf = swap->a[0];
		while (swap->size_a - 1 > ++i)
			swap->a[i] = swap->a[i + 1];
		swap->a[i] = buf;
	}
	i = -1;
	if (swap->size_b > 1 && (sym == 'b' || sym == 'c'))
	{
		buf = swap->b[0];
		while (swap->size_b - 1 > ++i)
			swap->b[i] = swap->b[i + 1];
		swap->b[i] = buf;
	}
	if (sym == 'a' && real == 'r')
		write(1, "ra\n", 3);
	else if (sym == 'b' && real == 'r')
		write(1, "rb\n", 3);
	else if (sym == 'c' && real == 'r')
		write(1, "rr\n", 3);
}

void	push_a(t_push *swap, char real)
{
	int	i;
	int	buf;

	i = 0;
	if (swap->size_b >= 1)
	{
		buf = swap->b[0];
		while (swap->size_a >= i)
		{
			swap->a[swap->size_a - i + 1] = swap->a[swap->size_a - i];
			i++;
		}
		swap->size_a++;
		swap->a[0] = buf;
		i = 0;
		while (swap->size_b > i)
		{
			swap->b[i] = swap->b[i + 1];
			i++;
		}
		swap->size_b--;
	}
	if (real == 'r')
		write(1, "pa\n", 3);
}

void	push_b(t_push *swap, char real)
{
	int	i;
	int	buf;

	i = 0;
	if (swap->size_a >= 1)
	{
		buf = swap->a[0];
		while (swap->size_b >= i)
		{
			swap->b[swap->size_b - i + 1] = swap->b[swap->size_b - i];
			i++;
		}
		swap->size_b++;
		swap->b[0] = buf;
		i = 0;
		while (swap->size_a > i)
		{
			swap->a[i] = swap->a[i + 1];
			i++;
		}
		swap->size_a--;
	}
	if (real == 'r')
		write(1, "pb\n", 3);
}

void	swap_top(t_push *swap, char sym, char real)
{
	int	buf;

	if (swap->size_a > 1 && ((sym == 'a') || (sym == 'c')))
	{
		buf = swap->a[0];
		swap->a[0] = swap->a[1];
		swap->a[1] = buf;
		if (real == 'r')
			write(1, "sa\n", 3);
	}
	if (swap->size_b > 1 && ((sym == 'b') || (sym == 'c')))
	{
		buf = swap->b[0];
		swap->b[0] = swap->b[1];
		swap->b[1] = buf;
		if (real == 'r')
			write(1, "sb\n", 3);
	}
}
