/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:44:51 by utygett           #+#    #+#             */
/*   Updated: 2021/10/08 17:54:49 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*b_list;

	b_list = *lst;
	if (!(*lst))
		*lst = new;
	else
	{
		while (b_list->next)
		{
			b_list = b_list->next;
		}
		b_list->next = new;
	}
}
