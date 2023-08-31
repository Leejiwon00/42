/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:32:04 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/08/31 19:20:11 by jiwonle2         ###   ########.fr       */
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
	int				*fork;
	pthread_mutex_t	print;
}	t_info;

typedef struct s_philo
{
	int				num;
	int				last_eat;
	pthread_t		thread;
	struct s_info	*info;
}	t_philo;

/* init */
int		init_info(t_info *info, char **av);
void	init_thread(t_info info, t_philo **philo);
void	make_thread(t_info info, t_philo **philo);

/* philo */
void	*routine(void *arg);
int		get_time(void);

/* utils */
int		ft_atoi(const char *str);

#endif