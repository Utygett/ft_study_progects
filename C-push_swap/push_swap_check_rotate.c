/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:42:19 by utygett           #+#    #+#             */
/*   Updated: 2021/11/14 15:14:48 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_rotate_step_one(t_sort *action, t_push *swap, int step)
{
	if (step == 1)
	{
		while (action->ano_min_num_ra--)
			rotate(swap, 'c', 'r');
	}
	else if (step == 2)
	{
		while (action->min_num_ra > 0 && action->min_num_rb > 0)
		{
			action->min_num_ra--;
			action->min_num_rb--;
			rotate(swap, 'c', 'r');
		}
	}
	else if (step == 3)
	{
		while (action->min_num_rra > 0 && action->min_num_rrb > 0)
		{
			action->min_num_rra--;
			action->min_num_rrb--;
			rev_rotate(swap, 'c', 'r');
		}
	}
}

void	check_rotate_step_two(t_sort *action, t_push *swap)
{
	while (action->ano_min_num_rra > 0 && action->min_num_rrb > 0)
	{
		action->ano_min_num_rra--;
		action->min_num_rrb--;
		rev_rotate(swap, 'c', 'r');
	}
	while (action->ano_min_num_rra)
	{
		action->ano_min_num_rra--;
		rev_rotate(swap, 'a', 'r');
	}
	while (action->min_num_rrb)
	{
		action->min_num_rrb--;
		rev_rotate(swap, 'b', 'r');
	}
}

void	check_rotate(t_sort *action, t_push *swap)
{	
	if (action->min_num_rra > action->ano_min_num_ra
		&& action->min_num_rrb > action->ano_min_num_rb)
		check_rotate_step_one(action, swap, 1);
	else if (action->min_num_ra > 0 && action->min_num_rb > 0)
		check_rotate_step_one(action, swap, 2);
	else if (action->min_num_rra > 0 && action->min_num_rrb > 0
		&& action->min_num_rra < action->ano_min_num_ra)
		check_rotate_step_one(action, swap, 3);
	else if (action->min_num_rra > action->ano_min_num_ra
		&& action->min_num_rb == 0 && action->ano_min_num_rb == 0)
	{	
		while (action->ano_min_num_ra)
		{	
			action->ano_min_num_ra--;
			rotate(swap, 'a', 'r');
		}
	}
	else if (action->min_num_ra > action->ano_min_num_rra
		&& action->min_num_rb > action->ano_min_num_rrb)
		check_rotate_step_two(action, swap);
}

void	ave_sorting(t_push *s)
{
	while (s->size_a != 3)
	{	
		if (s->size_b > 1 && s->b[0] <= s->ave && s->b[0] < s->b[1])
			rotate(s, 'b', 'r');
		if (s->size_a > 1 && (s->a[0] == s->min || s->a[0] == s->max))
			rotate(s, 'a', 'r');
		else if (s->a[0] <= s->ave)
			push_b(s, 'r');
		else if (s->a[0] > s->ave)
			push_b(s, 'r');
	}
}

void	prepare_to_sort(t_push *s)
{
	while (check_sorting(s, 'a') == 0)
	{
		if (s->a[0] > s->a[1] && s->a[0] < s->a[s->size_a - 1])
			swap_top(s, 'a', 'r');
		else if (s->a[0] < s->a[1] && s->a[0] < s->a[s->size_a - 1])
			swap_top(s, 'a', 'r');
		else if (s->a[0] > s->a[1]
			&& s->a[0] > s->a[s->size_a - 1])
			rotate(s, 'a', 'r');
		else if (s->a[0] < s->a[1] && s->a[0] > s->a[s->size_a - 1])
			rev_rotate(s, 'a', 'r');
		else
			rotate(s, 'a', 'r');
	}	
}
