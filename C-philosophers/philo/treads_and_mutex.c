/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treads_and_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:28:58 by utygett           #+#    #+#             */
/*   Updated: 2021/11/25 13:30:02 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_time *timer, t_main *main, t_philo_data *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&timer->print_time, NULL))
		return (1);
	while (data->number_of_philosopher > i)
	{
		if (pthread_mutex_init(&main->fork[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

void	philo_thread_init(t_main *main, t_philo_data *data, int i)
{
	main->philosoph[i].number_of_times_each_philosopher_must_eat
		= data->number_of_times_each_philosopher_must_eat;
	main->philosoph[i].time_to_die = data->time_to_die;
	main->philosoph[i].time_to_sleep = data->time_to_sleep;
	main->philosoph[i].time_to_eat = data->time_to_eat;
	main->philosoph[i].fork_left_hand = main->fork + i;
}

void	*philosopher(void *phi)
{
	t_philo	*philo;

	philo = phi;
	philo->ms_last_eat = 0;
	philo->number_of_philo_eat = 0;
	usleep((philo->num_of_philo % 2) * 1000);
	if (philo->number_of_philo_eat
		== philo->number_of_times_each_philosopher_must_eat)
		return (NULL);
	while (1)
	{
		philo_try_eat(philo);
		if (philo->number_of_philo_eat
			== philo->number_of_times_each_philosopher_must_eat)
			return (NULL);
		pthread_mutex_lock(&philo->timer->print_time);
		write_status(" is sleeping\n", philo->num_of_philo, philo->timer);
		pthread_mutex_unlock(&philo->timer->print_time);
		my_ms_sleep(philo->time_to_sleep);
		pthread_mutex_lock(&philo->timer->print_time);
		write_status(" is thinking\n", philo->num_of_philo, philo->timer);
		pthread_mutex_unlock(&philo->timer->print_time);
	}
	return (NULL);
}

int	philo_thread_creat(t_main *main, t_philo_data *data, t_time *timer)
{
	int	i;

	i = 0;
	while (data->number_of_philosopher > i)
	{
		philo_thread_init(main, data, i);
		main->philosoph[i].timer = timer;
		if (i == 0)
			main->philosoph[i].fork_right_hand = main->fork
				+ (data->number_of_philosopher - 1);
		else
			main->philosoph[i].fork_right_hand = main->fork + (i - 1);
		main->philosoph[i].num_of_philo = i + 1;
		if ((pthread_create((main->thread + i), NULL,
					philosopher, main->philosoph + i)))
			return (-1);
		pthread_detach(main->thread[i]);
		i++;
	}
	return (0);
}
