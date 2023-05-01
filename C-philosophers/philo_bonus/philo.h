/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:08:55 by utygett           #+#    #+#             */
/*   Updated: 2021/11/25 12:50:30 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <fcntl.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_time
{
	struct timeval	tv1;
	struct timeval	tv2;
	struct timeval	dtv;
	struct timezone	tz;
	int				simulation_end;
}	t_time;

typedef struct s_philo
{
	int				number_of_times_each_philosopher_must_eat;
	int				number_of_philo_eat;
	int				previos_num_of_eat;
	int				ms_last_eat;

}	t_philo;

typedef struct s_philo_data
{
	t_philo			philo;
	pthread_t		thread;
	t_time			timer;
	sem_t			*write_sem;
	sem_t			*fork_sem;
	int				pid[201];	
	int				number_of_philosopher;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				time;
	int				num_eat_flag;
}	t_philo_data;

long		time_stamp(struct timeval *tv2,
				struct timeval *dtv, struct timeval *tv1);
int			write_str(char *str);
void		str_reverse(char *str);
long		write_long(long long n);
int			write_int(int n);
void		write_status(char *str, int philo_num, t_time *timer);
void		my_ms_sleep_after_write(int timer_ms, t_time *timer);
void		my_ms_sleep(int timer_ms);
int			ft_atoi(char *str);
void		wait_and_kill_child(t_philo_data *data);
void		semaphore_init(t_philo_data *data);

#endif
