/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:31:52 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/08/31 19:20:55 by jiwonle2         ###   ########.fr       */
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

int	init_info(t_info *info, char **av)
{
	int	i;

	i = -1;
	info->num_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		info->must_eat = ft_atoi(av[5]);
	else
		info->must_eat = 0;
	info->fork = malloc(sizeof(int) * info->num_philo);
	while (++i < info->num_philo)
		info->fork[i] = 0;
	if (info->num_philo <= 0 || info->time_to_die < 0 || info->time_to_eat < 0
		|| info->time_to_die < 0)
		return (1);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_info	*info;
	int		current_time;

	philo = (t_philo *)arg;
	info = philo->info;
	current_time = get_time();
	if (philo->num % 2)
		usleep(1000);
	while (1)
	{
		info->fork[philo->num] = 1;
		printf("%d %d %s\n", philo->last_eat - current_time, philo->num, FORK);
	}
	// printf("test:%d\n", current_time);
	// printf(",, %d\n", info.number_of_philosophers);
	//printf("%d %d %s\n", philo->last_eat - current_time, philo->num, "has taken a fork");
	return NULL;
}

void	init_thread(t_info info, t_philo **philo)
{
	int		i;

	*philo = malloc(sizeof(t_philo) * info.num_philo);
	i = -1;
	while (++i < info.num_philo)
	{
		(*philo)[i].num = i + 1;
		(*philo)[i].last_eat = get_time();
		(*philo)[i].info = &info;
	}
}

void	make_thread(t_info info, t_philo **philo)
{
	int	i;

	i = -1;
	while (++i < info.num_philo)
		pthread_create(&(*philo)[i].thread, NULL, routine, &(*philo)[i]);
		// pthread_create(&((*philo)[i].thread), NULL, routine, &((*philo)[i]));
}

int	main(int ac, char **av)
{
	t_info	info;
	t_philo	*philo;

	if (ac == 5 || ac == 6)
	{
		init_info(&info, av);
		init_thread(info, &philo);
		make_thread(info, &philo);
	}
	else
		printf("Invalid arguments\n");
	return (0);
}
