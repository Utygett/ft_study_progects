/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:03:37 by utygett           #+#    #+#             */
/*   Updated: 2021/11/25 12:33:27 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_status(char *str, int philo_num, t_time *timer)
{
	write_long(time_stamp(&timer->tv2, &timer->dtv, &timer->tv1));
	write(1, " ", 1);
	write_int(philo_num);
	write_str(str);
}

void	my_ms_sleep_after_write(int timer_ms, t_time *timer)
{
	struct timeval	tv;

	usleep(timer_ms * 1000 - 1000);
	while (1)
	{
		gettimeofday(&tv, NULL);
		timer->dtv.tv_sec = tv.tv_sec - timer->tv1.tv_sec;
		timer->dtv.tv_usec = tv.tv_usec - timer->tv1.tv_usec;
		if (timer->dtv.tv_usec < 0)
		{
			timer->dtv.tv_sec--;
			timer->dtv.tv_usec += 1000000;
		}
		if ((timer->dtv.tv_sec * 100
				+timer->dtv.tv_usec / 100) >= (timer_ms * 10))
			break ;
		usleep(250);
	}
}

void	my_ms_sleep(int timer_ms)
{
	struct timeval	tv1;
	struct timeval	tv2;
	struct timeval	dtv;

	gettimeofday(&tv1, NULL);
	usleep(timer_ms * 1000 - 1000);
	while (1)
	{
		gettimeofday(&tv2, NULL);
		dtv.tv_sec = tv2.tv_sec - tv1.tv_sec;
		dtv.tv_usec = tv2.tv_usec - tv1.tv_usec;
		if (dtv.tv_usec < 0)
		{
			dtv.tv_sec--;
			dtv.tv_usec += 1000000;
		}
		if ((dtv.tv_sec * 1000 + dtv.tv_usec / 1000) >= timer_ms)
			break ;
		usleep(300);
	}
}

long	time_stamp(struct timeval *tv2,
			struct timeval *dtv, struct timeval *tv1)
{
	gettimeofday(tv2, NULL);
	dtv->tv_sec = tv2->tv_sec - tv1->tv_sec;
	dtv->tv_usec = tv2->tv_usec - tv1->tv_usec;
	if (dtv->tv_usec < 0)
	{
		dtv->tv_sec--;
		dtv->tv_usec += 1000000;
	}
	return ((dtv->tv_sec * 1000 + dtv->tv_usec / 1000) - 200);
}
