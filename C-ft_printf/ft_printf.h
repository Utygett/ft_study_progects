/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 23:19:32 by utygett           #+#    #+#             */
/*   Updated: 2021/10/21 14:27:37 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		check_format(char *str, va_list p_valist);
int		write_char(char a);
int		write_str(char *str);
int		write_int(int n);
int		write_hex_lower(unsigned int n);
int		write_hex_upper(unsigned int n);
int		write_hex_pointer(long unsigned int n);
int		write_unsigned_int(unsigned int n);
void	str_reverse(char *str);

#endif