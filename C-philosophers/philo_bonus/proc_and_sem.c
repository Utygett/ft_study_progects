/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_and_sem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:49:32 by utygett           #+#    #+#             */
/*   Updated: 2021/11/25 13:30:26 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_and_kill_child(t_philo_data *data)
{
	int	i;
	int	ret;

	i = 0;
	while (data->number_of_philosopher > i)
	{
		waitpid(-1, &ret, 0);
		if (ret == 0)
		{
			i = 0;
			while (data->number_of_philosopher > i)
			{
				kill(data->pid[i], SIGTERM);
				i++;
			}
		}
		i++;
	}
}

void	semaphore_init(t_philo_data *data)
{
	sem_unlink("/semaphor_for_write");
	sem_unlink("/semaphor_for_frok");
	data->write_sem = sem_open("/semaphor_for_write", O_CREAT, S_IRWXU, 1);
	data->fork_sem = sem_open("/semaphor_for_frok",
			O_CREAT, S_IRWXU, data->number_of_philosopher);
}
