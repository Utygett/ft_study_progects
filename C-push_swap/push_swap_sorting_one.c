/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting_one.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:44:20 by utygett           #+#    #+#             */
/*   Updated: 2021/11/14 15:15:01 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_step_one(t_push *s)
{
	if (s->ave_sort == 1)
	{
		ave_sorting(s);
	}
	else
	{
		while (s->size_a != 3)
		{	
			if (s->size_b > 1 && s->b[0] >= s->ave && s->b[0] < s->b[1])
				rotate(s, 'b', 'r');
			if (s->size_a > 1 && (s->a[0] == s->min || s->a[0] == s->max))
				rotate(s, 'a', 'r');
			else if (s->a[0] <= s->ave)
				push_b(s, 'r');
			else if (s->a[0] > s->ave)
				push_b(s, 'r');
		}
	}
	prepare_to_sort(s);
}

void	sort_step_two(t_push *swap1, t_sort *action, int i)
{
	action->now_act = 0;
	action->num_ra = 0;
	action->num_rra = 0;
	action->num_rb = 0;
	action->num_rrb = 0;
	action->ano_min_num_rb = 0;
	action->ano_min_num_rrb = 0;
	action->ano_min_num_ra = 0;
	action->ano_min_num_rra = 0;
	if (i > (swap1->size_b / 2))
	{
		action->now_act = swap1->size_b - i;
		action->num_rrb = swap1->size_b - i;
	}
	else
	{
		action->now_act = i;
		action->num_rb = i;
	}
	if (action->num_rb > 0)
		action->ano_min_num_rrb = swap1->size_b - action->num_rb;
	else
		action->ano_min_num_rb = swap1->size_b - action->num_rrb;
}

void	sort_step_three(t_push *swap1, t_sort *action, int i)
{
	while (swap1->a[0] < swap1->b[i]
		|| swap1->a[swap1->size_a - 1] > swap1->b[i])
	{	
		if (swap1->a[0] > swap1->b[i]
			&& swap1->a[swap1->size_a - 1] > swap1->b[i])
		{
			rev_rotate(swap1, 'a', 'v');
			action->num_rra++;
		}
		else if (swap1->a[0] < swap1->b[i]
			&& swap1->a[swap1->size_a - 1] > swap1->b[i])
		{
			rev_rotate(swap1, 'a', 'v');
			action->num_rra++;
		}
		else if (swap1->a[0] < swap1->b[i]
			&& swap1->a[swap1->size_a - 1] < swap1->b[i])
		{
			rotate(swap1, 'a', 'v');
			action->num_ra++;
		}
		action->now_act++;
	}
}

void	sort_step_four(t_push *swap1, t_sort *action, int i)
{
	if (action->num_ra > (swap1->size_a / 2))
	{
		action->num_rra = swap1->size_a - action->num_ra;
		action->num_ra = 0;
	}
	if (action->num_ra > 0)
	{
		action->ano_min_num_rra = swap1->size_a - action->num_ra;
	}
	else
	{
		action->ano_min_num_ra = swap1->size_a - action->num_rra;
	}
	if (action->now_act < action->min_act)
	{
		action->min_act = action->now_act;
		action->num_act = i;
		action->min_num_ra = action->num_ra;
		action->min_num_rra = action->num_rra;
		action->min_num_rb = action->num_rb;
		action->min_num_rrb = action->num_rrb;
	}
}

void	sort_step_five(t_push *swap, t_sort *action)
{
	if (action->ano_min_num_ra > action->min_num_rra)
	{
		while (action->min_num_rra--)
			rev_rotate(swap, 'a', 'r');
	}
	else if (action->ano_min_num_rra > action->min_num_ra)
	{
		while (action->min_num_ra--)
			rotate(swap, 'a', 'r');
	}
	else if (action->ano_min_num_rra < action->min_num_ra)
	{
		while (action->ano_min_num_rra--)
			rev_rotate(swap, 'a', 'r');
	}
}
