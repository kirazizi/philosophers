/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:00:59 by sbzizal           #+#    #+#             */
/*   Updated: 2023/06/21 20:39:11 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_eat(t_philo *philo)
{
	if (philo->data->must_eat > 0 && philo->count >= philo->data->must_eat)
	{
		pthread_mutex_lock(philo->print_mutex);
		philo->data->all_ate++;
		pthread_mutex_unlock(philo->print_mutex);
	}
}

void	*philo_routine(void *temp)
{
	t_philo	*philo;

	philo = temp;
	while (1)
	{
		taken_fork1(philo);
		taken_fork2(philo);
		is_eating(philo);
		pthread_mutex_lock(philo->print_mutex);
		philo->count++;
		pthread_mutex_unlock(philo->print_mutex);
		check_eat(philo);
		ft_usleep(philo->data->time_eat);
		pthread_mutex_lock(philo->print_mutex);
		philo->time_last_eat = get_period(philo->data->start);
		pthread_mutex_unlock(philo->print_mutex);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		is_sleeping(philo);
		is_thinking(philo);
	}
}
