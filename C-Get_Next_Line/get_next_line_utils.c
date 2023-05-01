/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:01:01 by utygett           #+#    #+#             */
/*   Updated: 2021/10/12 12:30:55 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_list_push_back(t_list **begin_list, char *buf, size_t content_size)
{
	t_list	*list;
	t_list	*b_list;

	b_list = *begin_list;
	list = malloc(sizeof(t_list));
	if (list)
	{
		list->content = buf;
		list->next = 0;
		list->content_size = content_size;
	}
	if (*begin_list == 0)
	{
		*begin_list = list;
	}
	else
	{
		while (b_list->next != 0)
		{
			b_list = b_list->next;
		}
		b_list->next = list;
	}
}

void	free_linked_list(t_list **begin_list)
{
	t_list	*b_list;

	b_list = 0;
	while (*begin_list)
	{
		b_list = (*begin_list)->next;
		free((*begin_list)->content);
		free((*begin_list));
		*begin_list = b_list;
	}	
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s + start))
		p = malloc(sizeof(*p) * (ft_strlen(s + start) + 1));
	else
		p = malloc(sizeof(*p) * (len + 1));
	if (p == 0)
		return (NULL);
	while (*(s + start) && len > 0)
	{	
		*(p + i) = *(s + start);
		s++;
		i++;
		len --;
	}
	*(p + i) = '\0';
	return (p);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*(dst + i) && i < dstsize)
		i++;
	len = i;
	while (*(src + i - len) && i + 1 < dstsize)
	{
		*(dst + i) = *(src + i - len);
		i++;
	}
	if (len < dstsize)
		*(dst + i) = '\0';
	return (len + ft_strlen(src));
}

size_t	ft_strlen(const char *s)
{	
	int	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}
