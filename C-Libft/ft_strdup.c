/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:15:55 by utygett           #+#    #+#             */
/*   Updated: 2021/10/05 14:57:26 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		i;

	i = 0;
	if (!(*s1) && !s1)
		return (0);
	p = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (p == 0)
		return (0);
	while (*s1)
	{
		*(p + i) = *s1;
		s1++;
		i++;
	}
	*(p + i) = '\0';
	return (p);
}
