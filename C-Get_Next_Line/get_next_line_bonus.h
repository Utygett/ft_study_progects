/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 09:54:04 by utygett           #+#    #+#             */
/*   Updated: 2021/10/13 18:03:20 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*con;
	void			*con_start;
	struct s_list	*next;
	size_t			con_size;
	int				fd;
}	t_list;

char	*get_next_line(int fd);
char	*str_cat_from_list(t_list *begin_list);
void	get_lin_list_from_read(int fd, t_list **b_list);
void	check_buffer(t_list **begin_list, int fd, t_list **list_fd);
void	free_one_list(t_list **start_lst, int fd);

size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	free_linked_list(t_list **begin_list);
void	ft_lpb(t_list **begin_list, char *buf, size_t con_size, int fd);

#endif