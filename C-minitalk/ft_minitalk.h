/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:22:04 by utygett           #+#    #+#             */
/*   Updated: 2021/11/16 14:37:09 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

void	ft_putnbr_fd(int n, int fd);
void	str_reverse(char *str);
int		ft_strlen(char *s);

#endif