/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:05:59 by utygett           #+#    #+#             */
/*   Updated: 2021/10/14 15:44:21 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

void	check_buffer( t_list **begin_list, int fd, t_list **list_fd)
{	
	char	buf[BUFFER_SIZE + 1];
	int		ret;
	int		i;

	ret = 1;
	i = -1;
	while (ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret <= 0)
			break ;
		while (ret - ++i)
		{
			if (*(buf + i) == '\n')
			{	
				ft_lpb(begin_list, ft_substr(buf, 0, i + 1), i + 1, 0);
				ft_lpb(list_fd, ft_substr(buf, i + 1, ret - i - 1), 0, fd);
				return ;
			}
		}
		*(buf + ret) = '\0';
		ft_lpb(begin_list, ft_substr(buf, 0, ret), ret, 0);
		i = -1;
	}
}

void	get_lin_list_from_read(int fd, t_list **b_list)
{	
	static t_list	*list_fd;
	t_list			*list_b_fd;
	int				i;

	list_b_fd = list_fd;
	i = 0;
	while (list_b_fd && list_b_fd->fd != fd)
		list_b_fd = list_b_fd->next;
	if (list_b_fd && list_b_fd->fd == fd)
	{
		while (*(((char *)list_b_fd->con) + i))
		{	
			if (*((char *)(list_b_fd->con) + i) == '\n')
			{
				ft_lpb(b_list, ft_substr((list_b_fd->con), 0, i + 1), i + 1, 0);
				(list_b_fd->con) = (list_b_fd->con) + i + 1;
				return ;
			}
			if (*(((char *)list_b_fd->con) + i + 1) == '\0')
				ft_lpb(b_list, ft_substr((list_b_fd->con), 0, i + 1), i + 1, 0);
			i++;
		}
		free_one_list(&list_fd, list_b_fd->fd);
	}
	check_buffer(b_list, fd, &list_fd);
}

void	free_one_list(t_list **start_lst, int fd)
{
	t_list	*list_b_fd;
	t_list	*list_b_fd1;
	t_list	*list_b_fd2;

	list_b_fd = *start_lst;
	if (list_b_fd->fd == fd)
	{	
		*start_lst = list_b_fd->next;
		if (list_b_fd->con_start)
			free(list_b_fd->con_start);
		free(list_b_fd);
	}
	else if (list_b_fd->next && list_b_fd->next->fd == fd)
	{	
		list_b_fd1 = list_b_fd;
		list_b_fd2 = list_b_fd->next->next;
		list_b_fd = list_b_fd1->next;
		list_b_fd1->next = list_b_fd2;
		free(list_b_fd->con_start);
		free(list_b_fd);
	}
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
		i = i + b_list->con_size;
		b_list = b_list->next;
	}
	str = malloc(i + 1);
	*str = '\0';
	b_list = begin_list;
	while (b_list)
	{
		ft_strlcat(str, b_list->con, i + 1);
		b_list = b_list->next;
	}
	return (str);
}
