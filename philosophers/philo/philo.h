/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:32:04 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/08/25 19:12:02 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_info
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	pthread_mutex_t	fork;
}	t_info;

typedef struct s_philo
{
	int			num;
	pthread_t	thread;
}	t_philo;

void	init_info(t_info *info, char **av);
void	make_thread(t_info *info, t_philo **philo);
void	*routine(void *arg);

/* utils */
int		ft_atoi(const char *str);

#endif