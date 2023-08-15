/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:41:34 by sbzizal           #+#    #+#             */
/*   Updated: 2023/06/22 13:45:40 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_philo *philos, int philo_nb)
{
	t_philo	*temp;

	if (philo_nb == 1)
		free(philos->print_mutex);
	while (philos && philo_nb)
	{
		temp = philos;
		philos = philos->next;
		pthread_mutex_destroy(&temp->fork);
		pthread_mutex_destroy(temp->print_mutex);
		free(temp);
		philo_nb--;
	}
	philos = NULL;
}

int	check_death(t_philo *philos, t_data data, int philo_nb)
{
	while (philos)
	{
		pthread_mutex_lock(philos->print_mutex);
		if (get_period(philos->data->start) - philos->time_last_eat
			> philos->data->time_die)
		{
			printf("|%zu| Philo nb : %d is died\n", get_period
				(philos->data->start), philos->id);
			return (1);
		}
		pthread_mutex_unlock(philos->print_mutex);
		pthread_mutex_lock(philos->print_mutex);
		if (philos->data->all_ate >= philo_nb)
		{
			printf("All philos has eating %d times\n", data.must_eat);
			return (1);
		}
		pthread_mutex_unlock(philos->print_mutex);
		philos = philos->next;
		usleep(50);
	}
	return (0);
}
