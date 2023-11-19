/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:59:53 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/09/18 21:06:20 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	one_philo(t_philo *philo, t_info *info)
{
	print_status(philo->num + 1, "has taken a fork", info, 0);
	print_status(philo->num + 1, "died", info, 1);
}

void	*routine(void *arg)
{
	t_philo		*philo;
	t_info		*info;

	philo = arg;
	info = philo->info;
	if (info->num_philo == 1)
	{
		one_philo(philo, info);
		return (NULL);
	}
	if (philo->num % 2)
		usleep(1000);
	while (!info->finish)
	{
		eat(philo, info);
		if (info->must_eat == philo->count)
		{
			info->total_eat++;
			break ;
		}
		print_status(philo->num + 1, "is sleeping", info, 0);
		ft_usleep(info->time_to_sleep, info);
		print_status(philo->num + 1, "is thinking", info, 0);
	}
	return (NULL);
}

void	eat(t_philo *philo, t_info *info)
{
	if (!info->finish)
	{
		pthread_mutex_lock(&info->fork[philo->left]);
		print_status(philo->num + 1, "has taken a fork", info, 0);
		pthread_mutex_lock(&info->fork[philo->right]);
		print_status(philo->num + 1, "has taken a fork", info, 0);
		print_status(philo->num + 1, "is eating", info, 0);
		philo->last_eat = get_time();
		ft_usleep(info->time_to_eat, info);
		philo->count++;
		pthread_mutex_unlock(&info->fork[philo->left]);
		pthread_mutex_unlock(&info->fork[philo->right]);
	}
}

void	*monitoring(void *arg)
{
	int			i;
	t_philo		*philo;
	t_info		*info;

	philo = arg;
	info = philo->info;
	while (!info->finish)
	{
		i = 0;
		if (info->total_eat == info->num_philo)
		{
			info->finish = 1;
			break ;
		}
		while (i < info->num_philo)
		{
			if (get_time() >= info->time_to_die + philo[i].last_eat)
			{
				print_status(i + 1, "died", info, 1);
				break ;
			}
			i++;
		}
	}
	return (NULL);
}

void	print_status(int num, char *msg, t_info *info, int flag)
{
	long long	current;

	if (!info->finish)
	{
		pthread_mutex_lock(&info->print);
		current = get_time();
		printf("%lld %d %s\n", current - info->start, num, msg);
		if (flag)
			info->finish = 1;
		pthread_mutex_unlock(&info->print);
	}
}
