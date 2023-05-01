/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:50:05 by utygett           #+#    #+#             */
/*   Updated: 2021/10/09 15:02:13 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*flist;

	list = 0;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{	
		flist = ft_lstnew(f(lst->content));
		if (!flist || flist->content == NULL)
		{
			if (del)
				ft_lstclear(&list, del);
			return (NULL);
		}
		ft_lstadd_back(&list, flist);
		lst = lst->next;
	}
	return (list);
}
