/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:58:50 by aarchiba          #+#    #+#             */
/*   Updated: 2022/04/03 18:01:53 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s1, char const *set)
{
	int		i;
	int		a;
	int		tmp;
	char	*res;

	i = 0;
	a = -1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	tmp = i - 1;
	while (s1[i])
		i++;
	while (i >= 0 && ft_strchr(set, s1[i]) && i > tmp)
		i--;
	res = malloc(sizeof(char) * ((i - tmp) + 1));
	if (!res)
		return (NULL);
	while (tmp < i)
		res[++a] = s1[++tmp];
	res[a] = '\0';
	free(s1);
	return (res);
}

char	*ft_isspace_strtrim(char *s1)
{
	int		i;
	int		a;
	int		tmp;
	char	*res;

	i = 0;
	a = -1;
	while (s1[i] && space(s1[i]))
		i++;
	tmp = i - 1;
	while (s1[i])
		i++;
	while (i > 0 && space(s1[i - 1]) && i > tmp)
		i--;
	res = malloc(sizeof(char) * ((i - tmp) + 1));
	if (!res)
		error_end(3);
	while (tmp < i)
		res[++a] = s1[++tmp];
	res[a] = '\0';
	return (res);
}
