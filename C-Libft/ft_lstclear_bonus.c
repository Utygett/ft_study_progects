/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:33:10 by utygett           #+#    #+#             */
/*   Updated: 2021/10/08 21:01:44 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{	
	t_list	*b_lst;

	if (lst)
	{
		while (*lst)
		{
			b_lst = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = b_lst;
		}
	}
}
