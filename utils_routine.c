/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:04:07 by sbzizal           #+#    #+#             */
/*   Updated: 2023/06/20 13:45:26 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taken_fork1(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(philo->print_mutex);
	printf("|%zu| Philo nb : %d has taken a fork\n",
		get_period(philo->data->start), philo->id);
	pthread_mutex_unlock(philo->print_mutex);
}

void	taken_fork2(t_philo *philo)
{
	pthread_mutex_lock(&philo->next->fork);
	pthread_mutex_lock(philo->print_mutex);
	printf("|%zu| Philo nb : %d has taken a fork\n",
		get_period(philo->data->start), philo->id);
	pthread_mutex_unlock(philo->print_mutex);
}

void	is_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->print_mutex);
	printf("|%zu| Philo nb : %d is eating\n",
		get_period(philo->data->start), philo->id);
	pthread_mutex_unlock(philo->print_mutex);
}

void	is_sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->print_mutex);
	printf("|%zu| Philo nb : %d is sleeping\n",
		get_period(philo->data->start), philo->id);
	pthread_mutex_unlock(philo->print_mutex);
	ft_usleep(philo->data->time_sleep);
}

void	is_thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->print_mutex);
	printf("|%zu| Philo nb : %d is thinking\n",
		get_period(philo->data->start), philo->id);
	pthread_mutex_unlock(philo->print_mutex);
}
