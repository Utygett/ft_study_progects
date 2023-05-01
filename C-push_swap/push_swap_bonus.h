/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:26:33 by utygett           #+#    #+#             */
/*   Updated: 2021/11/14 16:17:00 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_push
{
	int	size_a;
	int	size_b;
	int	*a;
	int	*afree;
	int	*b;
	int	min;
	int	max;
	int	ave;
}	t_push;

void	free_and_exit(t_push *swap);
int		ft_atoi(char *str, t_push *swap);
void	check_double(t_push *swap);
int		check_sorting(t_push *swap, char sym);
void	swap_top(t_push *swap, char sym, char real);
void	rev_rotate(t_push *swap, char sym, char real);
void	rotate(t_push *swap, char sym, char real);
void	push_a(t_push *swap, char real);
void	push_b(t_push *swap, char real);
void	swap_top(t_push *swap, char sym, char real);
void	free_and_exit_ko(t_push *swap);
int		ft_strcmp(const char *s1, const char *s2);
void	follow_instruction(t_push *swap, char *op);

#endif