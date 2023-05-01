/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 09:54:04 by utygett           #+#    #+#             */
/*   Updated: 2021/10/13 18:03:55 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	size_t			content_size;
}	t_list;

char	*get_next_line(int fd);
char	*str_cat_from_list(t_list *begin_list);
void	get_lin_list_from_read(int fd, t_list **b_list);
char	*check_buffer(char *ptr_buf, t_list **begin_list, int fd, char *buf);

size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	free_linked_list(t_list **begin_list);
void	ft_list_push_back(t_list **begin_list, char *buf, size_t content_size);

#endif