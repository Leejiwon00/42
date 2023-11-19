/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:31:52 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/09/18 20:36:02 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long long time, t_info *info)
{
	long long	current;
	long long	update;

	current = get_time();
	while (!(info->finish))
	{
		update = get_time();
		if ((update - current) >= time)
			break ;
		usleep(50);
	}
}

int	init_philo(t_info *info, t_philo **philo)
{
	int		i;

	*philo = malloc(sizeof(t_philo) * info->num_philo);
	if (!(*philo))
		return (1);
	i = -1;
	while (++i < info->num_philo)
	{
		(*philo)[i].num = i;
		(*philo)[i].count = 0;
		(*philo)[i].left = i;
		(*philo)[i].right = (i - 1 + info->num_philo) % info->num_philo;
		(*philo)[i].info = info;
	}
	return (0);
}

int	make_thread(t_info info, t_philo *philo)
{
	int			i;
	pthread_t	monitor;

	i = -1;
	while (++i < info.num_philo)
	{
		philo[i].last_eat = get_time();
		if (pthread_create(&(philo[i].thread), NULL, routine, &philo[i]))
			return (1);
	}
	if (pthread_create(&monitor, NULL, monitoring, philo))
		return (1);
	i = -1;
	while (++i < info.num_philo)
		pthread_join(philo[i].thread, NULL);
	pthread_join(monitor, NULL);
	i = -1;
	return (0);
}

int	main(int ac, char **av)
{
	t_info	info;
	t_philo	*philo;

	if (ac == 5 || ac == 6)
	{
		if (init_info(&info, av))
			return (print_error("init fail\n"));
		if (init_philo(&info, &philo))
			return (print_error("init fail\n"));
		if (make_thread(info, philo))
			return (print_error("thread creation fail\n"));
		free(philo);
		free(info.fork);
	}
	else
		printf("invalid num of arguments\n");
	return (0);
}
