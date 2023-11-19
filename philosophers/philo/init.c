/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:31:04 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/09/18 19:31:50 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_info *info)
{
	int	i;

	if (pthread_mutex_init(&(info->print), NULL))
		return (1);
	info->fork = malloc(sizeof(pthread_mutex_t) * info->num_philo);
	if (!(info->fork))
		return (1);
	i = 0;
	while (i < info->num_philo)
	{
		if (pthread_mutex_init(&info->fork[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

int	init_info(t_info *info, char **av)
{
	info->num_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		info->must_eat = ft_atoi(av[5]);
	else
		info->must_eat = -1;
	info->finish = 0;
	info->total_eat = 0;
	info->start = get_time();
	if (info->num_philo <= 0 || info->time_to_die < 0 || info->time_to_eat < 0
		|| info->time_to_sleep < 0)
		return (1);
	if (init_mutex(info))
		return (1);
	return (0);
}
