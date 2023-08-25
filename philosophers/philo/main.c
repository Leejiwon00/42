/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:31:52 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/08/25 19:18:45 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	g_global;
// pthread_mutex_t	g_lock = PTHREAD_MUTEX_INITIALIZER;

// void	*test(void *arg)
// {
// 	int	i = -1;
// 	char *name = (char *)arg;

// 	pthread_mutex_lock(&lock);
// 	global = 0;
// 	while (++i < 10){
// 		printf("%s --> %d\n", name, global);
// 		global++;
// 	}
// 	pthread_mutex_unlock(&lock);
// 	return arg;
// }

void	init_info(t_info *info, char **av)
{
	info->number_of_philosophers = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		info->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	else
		info->number_of_times_each_philosopher_must_eat = 0;
}

void	*routine(void *arg)
{
	
}

void	make_thread(t_info *info, t_philo **philo)
{
	int		i;

	*philo = malloc(sizeof(t_philo) * info->number_of_philosophers);
	i = -1;
	while (++i < info->number_of_philosophers)
		(*philo)[i].num = i + 1;
}

int	main(int ac, char **av)
{
	t_info	info;
	t_philo	*philo;

	if (ac == 5 || ac == 6)
	{
		init_info(&info, av);
		make_thread(&info, &philo);
	}
	else
		printf("Invalid arguments\n");
	return (0);
}
