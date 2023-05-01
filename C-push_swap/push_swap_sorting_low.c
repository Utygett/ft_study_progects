/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting_low.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:39:12 by utygett           #+#    #+#             */
/*   Updated: 2021/11/14 15:16:13 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_low_step_one(t_push *swap)
{
	if (swap->size_a > 3)
	{
		while (swap->size_a > swap->size_b + 1 && swap->size_a > 2)
		{	
			max_min_ave(swap);
			if (swap->a[0] == swap->min || swap->a[0] == swap->max)
				push_b(swap, 'r');
			else if ((swap->a[1] == swap->min || swap->a[1] == swap->max)
				&& (swap->a[0] != swap->min && swap->a[0] != swap->max))
				swap_top(swap, 'a', 'r');
			else if (swap->a[swap->size_a - 1] == swap->min
				|| swap->a[swap->size_a - 1] == swap->max)
				rev_rotate(swap, 'a', 'r');
			else
				rotate(swap, 'a', 'r');
		}
	}
}

void	sorting_low_step_two(t_push *swap)
{
	while (check_sorting(swap, 'a') == 0)
	{
		if (swap->a[0] > swap->a[1] && swap->a[0] < swap->a[swap->size_a - 1])
			swap_top(swap, 'a', 'r');
		else if (swap->a[0] < swap->a[1]
			&& swap->a[0] < swap->a[swap->size_a - 1])
			swap_top(swap, 'a', 'r');
		else if (swap->a[0] > swap->a[1]
			&& swap->a[0] > swap->a[swap->size_a - 1])
			rotate(swap, 'a', 'r');
		else if (swap->a[0] < swap->a[1]
			&& swap->a[0] > swap->a[swap->size_a - 1])
			rev_rotate(swap, 'a', 'r');
		else
			rotate(swap, 'a', 'r');
	}
}

void	sorting_low(t_push *swap)
{
	if (check_sorting(swap, 'a'))
		return ;
	sorting_low_step_one(swap);
	sorting_low_step_two(swap);
	while (swap->size_b)
	{
		max_min_ave(swap);
		if (swap->b[0] < swap->b[1])
			swap_top(swap, 'b', 'r');
		if (swap->a[0] == swap->min && swap->a[0] > swap->b[0])
			push_a(swap, 'r');
		else if (swap->a[swap->size_a - 1] == swap->max
			&& swap->a[swap->size_a - 1] < swap->b[0])
			push_a(swap, 'r');
		else if (swap->a[0] == swap->max
			&& swap->b[0] > swap->a[swap->size_a - 1])
			push_a(swap, 'r');
		else
			rotate(swap, 'a', 'r');
	}
	while (check_sorting(swap, 'a') == 0)
		rotate(swap, 'a', 'r');
}

int	sort_ave(t_push *swap, int ave_part)
{
	t_push	swap1;
	int		res;

	swap1.afree = malloc(sizeof(int) * (swap->size_a * 2));
	swap1.a = swap1.afree;
	swap1.b = swap1.a + swap->size_a;
	s_copy(swap, &swap1);
	swap1.count = 1;
	swap1.cou = 'n';
	swap1.ave_sort = ave_part;
	sorting(&swap1);
	res = swap1.count;
	free(swap1.afree);
	return (res);
}

void	best_choice_sort(t_push *swap)
{
	if (sort_ave(swap, 1) > sort_ave(swap, 2))
		swap->ave_sort = 2;
	else
		swap->ave_sort = 1;
	sorting(swap);
}
