/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 12:00:41 by sbzizal           #+#    #+#             */
/*   Updated: 2023/06/22 13:47:44 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	creat_list(t_philo **philos, t_data data, int philo_nb)
{
	int	i;

	i = 1;
	while (i <= philo_nb)
	{
		ft_lstadd_back(philos, ft_lstnew(i, &data));
		i++;
	}
}

void	creat_thread(t_philo *philos, int philo_nb)
{
	pthread_mutex_t	*mutex_print;
	int				i;

	i = 1;
	mutex_print = malloc(sizeof(pthread_mutex_t));
	if (!mutex_print)
		return ;
	pthread_mutex_init(mutex_print, NULL);
	while (i <= philo_nb)
	{
		philos->print_mutex = mutex_print;
		pthread_create(&philos->tid, NULL, philo_routine, (void *)philos);
		philos = philos->next;
		usleep(100);
		i++;
	}
}

void	detach_theads(t_philo *philos, int philo_nb)
{
	int	i;

	i = 1;
	while (i <= philo_nb)
	{
		pthread_detach(philos->tid);
		philos = philos->next;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_philo			*philos;
	t_data			data;
	int				philo_nb;
	int				i;

	if (ac < 5 || ac > 6)
		return (printf("number_of_philo sleep_time eat_time die_time\n"), 0);
	i = 1;
	while (av[i])
	{
		if (pars_philo(av[i++]))
			return (0);
	}
	philo_nb = ft_atoi(av[1]);
	if (ins_var(av, &data, philo_nb))
		return (0);
	creat_list(&philos, data, philo_nb);
	philos->time_last_eat = get_period(data.start);
	creat_thread(philos, philo_nb);
	detach_theads(philos, philo_nb);
	if (check_death(philos, data, philo_nb))
		return (free_all(philos, philo_nb), 0);
}
