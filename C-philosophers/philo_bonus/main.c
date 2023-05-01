/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:08:23 by utygett           #+#    #+#             */
/*   Updated: 2021/11/25 13:33:21 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	*check_philo(void *philo)
{
	t_philo_data	*data;

	data = philo;
	data->philo.previos_num_of_eat = 0;
	while (1)
	{
		data->time = time_stamp(&data->timer.tv2,
				&data->timer.dtv, &data->timer.tv1);
		if (data->philo.number_of_philo_eat != data->philo.previos_num_of_eat)
		{
			data->philo.previos_num_of_eat = data->philo.number_of_philo_eat;
			data->philo.ms_last_eat = time_stamp(&data->timer.tv2,
					&data->timer.dtv, &data->timer.tv1);
		}
		if (data->time - data->philo.ms_last_eat > data->time_to_die)
		{
			sem_wait(data->write_sem);
			write_status(" died\n", data->number_of_philosopher, &data->timer);
			exit(0);
		}
		usleep(900);
	}
	return (NULL);
}

void	try_eating(t_philo_data *data)
{
	sem_wait(data->fork_sem);
	sem_wait(data->write_sem);
	write_status(" has taken a fork\n",
		data->number_of_philosopher, &data->timer);
	sem_post(data->write_sem);
	sem_wait(data->fork_sem);
	sem_wait(data->write_sem);
	write_status(" has taken a fork\n",
		data->number_of_philosopher, &data->timer);
	write_status(" is eating\n", data->number_of_philosopher, &data->timer);
	sem_post(data->write_sem);
	data->philo.number_of_philo_eat++;
	my_ms_sleep(data->time_to_eat);
	sem_post(data->fork_sem);
	sem_post(data->fork_sem);
}

void	child(t_philo_data *data)
{
	if (pthread_create(&data->thread, NULL, check_philo, data))
		exit(0);
	pthread_detach(data->thread);
	data->philo.number_of_philo_eat = 0;
	usleep((data->number_of_philosopher % 2) * 500);
	while (1)
	{
		if (data->philo.number_of_philo_eat
			== data->number_of_times_each_philosopher_must_eat)
			exit(1);
		try_eating(data);
		if (data->philo.number_of_philo_eat
			== data->number_of_times_each_philosopher_must_eat)
			exit(1);
		sem_wait(data->write_sem);
		write_status(" is sleeping\n",
			data->number_of_philosopher, &data->timer);
		sem_post(data->write_sem);
		my_ms_sleep(data->time_to_sleep);
		sem_wait(data->write_sem);
		write_status(" is thinking\n",
			data->number_of_philosopher, &data->timer);
		sem_post(data->write_sem);
	}
	exit(1);
}

int	main(int argc, char **argv)
{
	t_philo_data	data;
	int				i;

	if (parse_arguments(&data, argc, argv) == 1)
		return (1);
	semaphore_init(&data);
	i = -1;
	gettimeofday(&data.timer.tv1, NULL);
	while (data.number_of_philosopher > ++i)
	{
		data.pid[i] = fork();
		if (data.pid[i] == 0)
			break ;
	}
	if (data.number_of_philosopher == i)
		wait_and_kill_child(&data);
	else
	{
		data.number_of_philosopher = i + 1;
		my_ms_sleep_after_write(200, &data.timer);
		child(&data);
	}
	sem_unlink("/semaphor_for_write");
	sem_unlink("/semaphor_for_frok");
	return (0);
}
