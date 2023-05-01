/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:08:23 by utygett           #+#    #+#             */
/*   Updated: 2021/11/25 10:34:58 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_eat_and_life(t_main *main, int *eat, int i)
{
	if (main->philosoph[i].number_of_philo_eat
		== main->philosoph[i].number_of_times_each_philosopher_must_eat)
		(*eat)++;
	else
	{
		pthread_mutex_lock(&main->timer->print_time);
		write_status(" died\n", i + 1, main->timer);
		return (1);
	}
	return (0);
}

void	check_life(t_main *main)
{
	long	time;
	int		i;
	int		eat;

	while (1)
	{
		time = time_stamp(&main->timer->tv2,
				&main->timer->dtv, &main->timer->tv1);
		i = 0;
		eat = 0;
		while (main->data->number_of_philosopher > i)
		{
			if (time - main->philosoph[i].ms_last_eat > main->data->time_to_die)
			{
				if (check_eat_and_life(main, &eat, i))
					return ;
			}
			i++;
		}
		if (eat == main->data->number_of_philosopher)
			return ;
		usleep(1000);
	}
}

void	philo_try_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left_hand);
	pthread_mutex_lock(&philo->timer->print_time);
	write_status(" has taken a fork\n", philo->num_of_philo, philo->timer);
	pthread_mutex_unlock(&philo->timer->print_time);
	pthread_mutex_lock(philo->fork_right_hand);
	pthread_mutex_lock(&philo->timer->print_time);
	write_status(" has taken a fork\n", philo->num_of_philo, philo->timer);
	write_status(" is eating\n", philo->num_of_philo, philo->timer);
	philo->number_of_philo_eat++;
	philo->ms_last_eat = time_stamp(&philo->timer->tv2,
			&philo->timer->dtv, &philo->timer->tv1);
	pthread_mutex_unlock(&philo->timer->print_time);
	my_ms_sleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->fork_left_hand);
	pthread_mutex_unlock(philo->fork_right_hand);
}

int	main(int argc, char **argv)
{
	t_philo_data	data;
	t_main			main;
	t_time			timer;

	if (parse_arguments(&data, argc, argv) == 1)
		return (1);
	main.argc = argc;
	if (init_mutex(&timer, &main, &data) < 0)
		return (1);
	gettimeofday(&timer.tv1, NULL);
	if (philo_thread_creat(&main, &data, &timer) < 0)
	{
		finish_programm(&data, &main);
		return (1);
	}
	main.data = &data;
	main.timer = &timer;
	check_life(&main);
	usleep(200000);
	finish_programm(&data, &main);
	pthread_mutex_destroy(&timer.print_time);
	return (0);
}
