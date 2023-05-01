/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:22:03 by utygett           #+#    #+#             */
/*   Updated: 2021/11/16 16:20:08 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

int	g_flag;

void	sigaction_handler(int sig, siginfo_t *get_signal, void *oldact)
{
	(void) get_signal;
	(void) oldact;
	(void) sig;
	g_flag = 0;
	usleep(20);
}

void	bit_sen(char c, int pid)
{	
	int	bit;
	int	ret;

	bit = 0;
	while (bit != 8)
	{
		g_flag = 1;
		if (c & (1 << bit))
		{
			ret = kill(pid, SIGUSR1);
		}
		else
		{
			ret = kill(pid, SIGUSR2);
		}
		if (ret == -1)
			exit(1);
		bit++;
		while (g_flag)
			pause();
	}
}

void	send_str(char *str, int pid)
{
	struct sigaction	get_signal;

	get_signal.sa_sigaction = sigaction_handler;
	sigaction(SIGUSR1, &get_signal, NULL);
	while (*str)
	{
		bit_sen(*str, pid);
		str++;
	}
	bit_sen(*str, pid);
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	pid = 0;
	i = 0;
	if (argc != 3)
		return (write(1, "get nortm args", 14));
	while ('0' <= argv[1][i] && argv[1][i] <= '9')
		pid = (pid * 10) + argv[1][i++] - 48;
	if (pid == 0)
		exit (1);
	send_str(argv[2], pid);
}
