/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:05:59 by utygett           #+#    #+#             */
/*   Updated: 2021/10/14 15:47:16 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_list	*begin_list;
	char	*str;

	if (fd < 0)
		return (NULL);
	begin_list = NULL;
	get_lin_list_from_read(fd, &begin_list);
	if (!begin_list)
		return (NULL);
	str = str_cat_from_list(begin_list);
	free_linked_list(&begin_list);
	if (str == 0)
		return (NULL);
	return (str);
}

char	*check_buffer(char *ptr_buf, t_list **begin_list, int fd, char *buf)
{	
	int			ret;
	int			i;

	ret = 1;
	i = -1;
	while (ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		*(buf + ret) = '\0';
		if (ret <= 0)
			break ;
		while (ret - ++i)
		{
			if (*(buf + i) == '\n')
			{	
				ft_list_push_back(begin_list, ft_substr(buf, 0, i + 1), i + 1);
				ptr_buf = buf;
				ptr_buf = ptr_buf + i + 1;
				return (ptr_buf);
			}
		}
		ft_list_push_back(begin_list, ft_substr(buf, 0, ret), ret);
		i = -1;
	}
	return (ptr_buf);
}

void	get_lin_list_from_read(int fd, t_list **b_list)
{	
	static char	*ptr_buf;
	static char	buf[BUFFER_SIZE + 1];
	int			i;

	i = 0;
	if (ptr_buf)
	{
		while (*(ptr_buf + i))
		{	
			if (*(ptr_buf + i) == '\n')
			{
				ft_list_push_back(b_list, ft_substr(ptr_buf, 0, i + 1), i + 1);
				ptr_buf = ptr_buf + i + 1;
				return ;
			}
			if (*(ptr_buf + i + 1) == '\0')
			{
				ft_list_push_back(b_list, ft_substr(ptr_buf, 0, i + 1), i + 1);
				ptr_buf = ptr_buf + i + 1;
			}
			i++;
		}
	}	
	ptr_buf = check_buffer(ptr_buf, b_list, fd, buf);
}

char	*str_cat_from_list(t_list *begin_list)
{
	size_t	i;
	t_list	*b_list;
	char	*str;

	i = 0;
	b_list = begin_list;
	while (b_list)
	{
		i = i + b_list->content_size;
		b_list = b_list->next;
	}
	str = malloc(i + 1);
	*str = '\0';
	b_list = begin_list;
	while (b_list)
	{
		ft_strlcat(str, b_list->content, i + 1);
		b_list = b_list->next;
	}
	return (str);
}
