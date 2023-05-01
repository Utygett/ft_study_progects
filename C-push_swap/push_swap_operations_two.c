/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_two.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:33:01 by utygett           #+#    #+#             */
/*   Updated: 2021/11/14 14:13:31 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	buble_sort(int *c, int size)
{
	int	buf;
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (size - 1 > i)
	{
		j = 0;
		while (size - i - 1 > j)
		{
			if (c[j] > c[j + 1])
			{
				buf = c[j];
				c[j] = c[j + 1];
				c[j + 1] = buf;
			}
			j++;
		}
		i++;
	}
}

void	max_min_ave(t_push *swap)
{
	int	*c;
	int	i;

	i = 0;
	c = malloc(sizeof(int) * swap->size_a);
	while (swap->size_a > i)
	{
		c[i] = swap->a[i];
		i++;
	}
	buble_sort(c, swap->size_a);
	swap->min = c[0];
	swap->max = c[swap->size_a - 1];
	swap->ave = c[swap->size_a / 2];
	free(c);
}

void	s_copy(t_push *swap, t_push *swap1)
{	
	int	i;

	i = 0;
	swap1->size_a = swap->size_a;
	swap1->size_b = swap->size_b;
	swap1->ave = swap->ave;
	swap1->min = swap->min;
	swap1->max = swap->max;
	while ((swap->size_a) > i)
	{	
		swap1->a[i] = swap->a[i];
		i++;
	}
	i = 0;
	while ((swap->size_b) > i)
	{	
		swap1->b[i] = swap->b[i];
		i++;
	}
}

void	set_sort(t_sort *action)
{
	action->min_act = 999999;
	action->num_ra = 0;
	action->num_rb = 0;
	action->num_rra = 0;
	action->num_rrb = 0;
	action->min_num_ra = 0;
	action->min_num_rra = 0;
	action->min_num_rb = 0;
	action->min_num_rrb = 0;
}
