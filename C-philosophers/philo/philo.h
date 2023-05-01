/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:08:55 by utygett           #+#    #+#             */
/*   Updated: 2021/11/25 10:38:13 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_time
{
	struct timeval	tv1;
	struct timeval	tv2;
	struct timeval	dtv;
	struct timezone	tz;
	pthread_mutex_t	print_time;
}	t_time;

typedef struct s_philo_data
{
	int	number_of_philosopher;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}	t_philo_data;

typedef struct s_philo
{
	t_time			*timer;
	pthread_mutex_t	*fork_right_hand;
	pthread_mutex_t	*fork_left_hand;
	long			ms_last_eat;
	int				death_int;
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				number_of_philo_eat;
	int				num_eat_flag;
}	t_philo;

typedef struct s_main
{
	int				argc;
	t_philo_data	*data;
	t_time			*timer;
	t_philo			philosoph[201];
	pthread_t		thread[201];
	pthread_mutex_t	fork[201];
}	t_main;
void		my_ms_sleep(int timer_ms);
void		write_status(char *str, int philo_num, t_time *timer);
long		time_stamp(struct timeval *tv2,
				struct timeval *dtv, struct timeval *tv1);
int			write_str(char *str);
void		str_reverse(char *str);
long		write_long(long long n);
int			write_int(int n);
int			ft_atoi(char *str);
int			init_mutex(t_time *timer, t_main *main, t_philo_data *data);
void		philo_thread_init(t_main *main, t_philo_data *data, int i);
int			philo_thread_creat(t_main *main, t_philo_data *data, t_time *timer);
void		finish_programm(t_philo_data *data, t_main *main);
int			parse_arguments(t_philo_data *data, int argc, char **argv);
void		finish_programm(t_philo_data *data, t_main *main);
void		*philosopher(void *phi);
void		philo_try_eat(t_philo *philo);

#endif
