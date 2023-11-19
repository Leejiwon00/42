/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:32:04 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/09/18 20:15:48 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define DIE "died"

typedef struct s_info
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				finish;
	int				total_eat;
	long long		start;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	time;
}	t_info;

typedef struct s_philo
{
	int				num;
	long long		last_eat;
	int				count;
	int				left;
	int				right;
	pthread_t		thread;
	struct s_info	*info;
}	t_philo;

int			init_info(t_info *info, char **av);
int			init_mutex(t_info *info);
int			init_philo(t_info *info, t_philo **philo);
int			make_thread(t_info info, t_philo *philo);

void		*routine(void *arg);
void		eat(t_philo *philo, t_info *info);
void		*monitoring(void *arg);
void		print_status(int num, char *msg, t_info *info, int flag);

long long	get_time(void);
int			ft_atoi(const char *str);
int			print_error(char *msg);
void		ft_usleep(long long time, t_info *info);

#endif