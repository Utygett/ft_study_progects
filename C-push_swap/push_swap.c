/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:17:43 by utygett           #+#    #+#             */
/*   Updated: 2021/11/14 15:16:19 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_step_four_half(t_push *swap, t_sort *action)
{	
	int	buf;

	buf = swap->b[action->num_act];
	check_rotate(action, swap);
	action->num_act = check_index(swap, buf);
	while (swap->b[0] != buf)
	{	
		if (action->num_act > (swap->size_b / 2))
			rev_rotate(swap, 'b', 'r');
		else
			rotate(swap, 'b', 'r');
	}
	sort_step_five(swap, action);
	while (swap->a[0] < swap->b[0] || swap->a[swap->size_a - 1] > swap->b[0])
	{
		if (swap->a[0] > swap->b[0]
			&& swap->a[swap->size_a - 1] > swap->b[0])
			rev_rotate(swap, 'a', 'r');
		else if (swap->a[0] < swap->b[0]
			&& swap->a[swap->size_a - 1] > swap->b[0])
			rev_rotate(swap, 'a', 'r');
		else if (swap->a[0] < swap->b[0]
			&& swap->a[swap->size_a - 1] < swap->b[0])
			rotate(swap, 'a', 'r');
	}
}

void	sort_step_end(t_push *swap1, t_push *swap, t_sort *action)
{	
	int	i;
	int	buf;

	buf = swap->b[action->num_act];
	i = 0;
	free(swap1->afree);
	max_min_ave(swap);
	buf = swap->min;
	i = 0;
	while (swap->a[i] != buf)
		i++;
	if (i < swap->size_a / 2)
	{
		while (check_sorting(swap, 'a') == 0)
			rotate(swap, 'a', 'r');
	}
	else
	{
		while (check_sorting(swap, 'a') == 0)
			rev_rotate(swap, 'a', 'r');
	}
}

void	sorting(t_push *swap)
{	
	int		i;
	t_push	swap1;
	t_sort	action;

	if (check_sorting(swap, 'a') == 1)
		return ;
	swap1.afree = malloc(sizeof(int) * (swap->size_a * 2));
	swap1.a = swap1.afree;
	swap1.b = swap1.a + swap->size_a;
	sort_step_one(swap);
	while (swap->size_b != 0)
	{
		set_sort(&action);
		i = -1;
		while (swap->size_b > ++i)
		{	
			s_copy(swap, &swap1);
			sort_step_two(&swap1, &action, i);
			sort_step_three(&swap1, &action, i);
			sort_step_four(&swap1, &action, i);
		}
		sort_step_four_half(swap, &action);
		push_a(swap, 'r');
	}
	sort_step_end(&swap1, swap, &action);
}

int	main(int argc, char **argv)
{
	int		i;
	t_push	swap;

	i = 0;
	if (!(argc >= 2))
		exit (1);
	swap.size_a = argc - 1;
	swap.size_b = 0;
	swap.afree = malloc(sizeof(int) * ((swap.size_a) * 2));
	swap.a = swap.afree;
	swap.b = swap.a + swap.size_a;
	while (swap.size_a > i)
	{
		*(swap.a + i) = ft_atoi(*(argv + i + 1), &swap);
		i++;
	}
	check_double(&swap);
	max_min_ave(&swap);
	swap.cou = 'y';
	if (argc < 7)
		sorting_low(&swap);
	else
		best_choice_sort(&swap);
	free(swap.afree);
}
