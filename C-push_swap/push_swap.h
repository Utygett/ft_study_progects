/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:26:33 by utygett           #+#    #+#             */
/*   Updated: 2021/11/14 15:19:17 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_push
{
	int		ave_sort;
	char	cou;
	int		count;
	int		size_a;
	int		size_b;
	int		*a;
	int		*afree;
	int		*b;
	int		min;
	int		max;
	int		ave;
}	t_push;

typedef struct s_sort
{
	int	min_act;
	int	num_act;
	int	now_act;
	int	now_act_buf;
	int	num_ra;
	int	num_rb;
	int	num_rra;
	int	num_rrb;
	int	min_num_ra;
	int	min_num_rb;
	int	min_num_rra;
	int	min_num_rrb;
	int	ano_min_num_rb;
	int	ano_min_num_rrb;
	int	ano_min_num_ra;
	int	ano_min_num_rra;
}	t_sort;

void	free_and_exit(t_push *swap);
int		ft_atoi(char *str, t_push *swap);
int		check_index(t_push *swap, int buf);
void	check_double(t_push *swap);
int		check_sorting(t_push *swap, char sym);
void	swap_top(t_push *swap, char sym, char real);
void	rev_rotate(t_push *swap, char sym, char real);
void	rotate(t_push *swap, char sym, char real);
void	push_a(t_push *swap, char real);
void	push_b(t_push *swap, char real);
void	swap_top(t_push *swap, char sym, char real);
void	buble_sort(int *c, int size);
void	max_min_ave(t_push *swap);
void	s_copy(t_push *swap, t_push *swap1);
void	set_sort(t_sort *action);
void	sorting_low_step_one(t_push *swap);
void	sorting_low_step_two(t_push *swap);
void	sorting_low(t_push *swap);
void	check_rotate(t_sort *action, t_push *swap);
void	check_rotate_step_one(t_sort *action, t_push *swap, int step);
void	check_rotate_step_two(t_sort *action, t_push *swap);
void	sort_step_one(t_push *s);
void	sort_step_two(t_push *swap1, t_sort *action, int i);
void	sort_step_three(t_push *swap1, t_sort *action, int i);
void	sort_step_four(t_push *swap1, t_sort *action, int i);
void	sort_step_four_half(t_push *swap, t_sort *action);
void	sort_step_five(t_push *swap, t_sort *action);
void	sort_step_end(t_push *swap1, t_push *swap, t_sort *action);
int		sort_ave(t_push *swap, int ave_part);
void	best_choice_sort(t_push *swap);
void	ave_sorting(t_push *s);
void	prepare_to_sort(t_push *s);
void	sorting(t_push *swap);

#endif