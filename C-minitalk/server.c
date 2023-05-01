/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:02:32 by utygett           #+#    #+#             */
/*   Updated: 2021/11/16 16:23:39 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	free_and_exit(char *str, int code)
{
	if (str)
		free(str);
	if (code == 1)
		write(2, "malloc error\n", 13);
	exit(1);
}

char	*ft_charjoin(char *s1, char c, int lens1)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (lens1 + 1));
	if (!str)
		free_and_exit(s1, 1);
	while (s1 && lens1--)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = c;
	if (s1)
		free(s1);
	return (str);
}

void	sigaction_handler(int sig, siginfo_t *get_signal, void *oldact)
{
	static int	i;
	static int	c;
	static int	j;
	static char	*str;

	(void) oldact;
	if (sig == SIGUSR1)
		c = c | (1 << i);
	i++;
	if (i % 8 == 0)
	{	
		str = ft_charjoin(str, c, j++);
		c = 0;
		i = 0;
	}
	if (j > 0 && str[j - 1] == '\0')
	{
		write(1, str, j);
		free(str);
		str = NULL;
		j = 0;
	}
	usleep(20);
	kill(get_signal->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	get_signal;

	write(1, "Server PID = ", 13);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	get_signal.sa_flags = SA_SIGINFO;
	get_signal.sa_sigaction = sigaction_handler;
	sigaction(SIGUSR1, &get_signal, NULL);
	sigaction(SIGUSR2, &get_signal, NULL);
	while (1)
		pause();
	return (0);
}
