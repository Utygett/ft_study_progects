/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:17:43 by utygett           #+#    #+#             */
/*   Updated: 2021/11/14 16:13:34 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (0);
		else if (!*s1++ || !*s2++)
			return (0);
	}
	return (1);
}

void	follow_instruction(t_push *swap, char *op)
{
	if (ft_strcmp(op, "ra"))
		rotate(swap, 'a', 'v');
	else if (ft_strcmp(op, "rb"))
		rotate(swap, 'b', 'v');
	else if (ft_strcmp(op, "sa"))
		swap_top(swap, 'a', 'v');
	else if (ft_strcmp(op, "sb"))
		swap_top(swap, 'b', 'v');
	else if (ft_strcmp(op, "ss"))
		swap_top(swap, 'c', 'v');
	else if (ft_strcmp(op, "pa"))
		push_a(swap, 'v');
	else if (ft_strcmp(op, "pb"))
		push_b(swap, 'v');
	else if (ft_strcmp(op, "rra"))
		rev_rotate(swap, 'a', 'v');
	else if (ft_strcmp(op, "rrb"))
		rev_rotate(swap, 'b', 'v');
	else if (ft_strcmp(op, "rrr"))
		rev_rotate(swap, 'c', 'v');
	else if (ft_strcmp(op, "rr"))
		rotate(swap, 'c', 'v');
	else
		free_and_exit_ko(swap);
}

void	read_instructions(t_push *swap, int i)
{
	char	buf;
	char	op[5];
	int		j;

	j = 0;
	op[0] = '\0';
	while (i > 0)
	{	
		buf = '1';
		j = 0;
		while (i > 0 && buf != '\n')
		{	
			i = read(0, &buf, 1);
			if (buf == '\n' && i <= 0)
				break ;
			op[j++] = buf;
			if (j > 4)
				free_and_exit_ko(swap);
		}
		op[j] = '\0';
		if (i > 0)
			follow_instruction(swap, op);
	}
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
	read_instructions(&swap, i);
	if (check_sorting(&swap, 'a'))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(swap.afree);
}
