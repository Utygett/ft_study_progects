/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:25:08 by utygett           #+#    #+#             */
/*   Updated: 2021/11/25 10:32:10 by utygett          ###   ########.fr       */
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

void	my_ms_sleep(int timer_ms)
{
	struct timeval	tv1;
	struct timeval	tv2;
	struct timeval	dtv;

	gettimeofday(&tv1, NULL);
	usleep((timer_ms * 1000) - 5000);
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
		usleep(900);
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
	return (dtv->tv_sec * 1000 + dtv->tv_usec / 1000);
}

void	finish_programm(t_philo_data *data, t_main *main)
{
	int	i;

	i = 0;
	while (data->number_of_philosopher > i)
	{
		pthread_mutex_destroy(&main->fork[i]);
		i++;
	}
}

int	parse_arguments(t_philo_data *data, int argc, char **argv)
{
	if (argc < 4 || argc > 6)
		return (1);
	data->number_of_philosopher = ft_atoi(argv[1]);
	if (data->number_of_philosopher < 0)
		return (1);
	if (data->number_of_philosopher > 200)
		return (1);
	data->time_to_die = ft_atoi(argv[2]);
	if (data->time_to_die < 0)
		return (1);
	data->time_to_eat = ft_atoi(argv[3]);
	if ((data->time_to_eat < 0))
		return (1);
	data->time_to_sleep = ft_atoi(argv[4]);
	if ((data->time_to_sleep < 0))
		return (1);
	if (argc > 5)
	{
		data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
		if (data->number_of_times_each_philosopher_must_eat < 0)
			return (1);
	}
	else
		data->number_of_times_each_philosopher_must_eat = -1;
	return (0);
}
