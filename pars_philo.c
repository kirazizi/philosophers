/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:57:35 by sbzizal           #+#    #+#             */
/*   Updated: 2023/06/22 14:14:14 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pars_philo(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			printf("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	ins_var(char **av, t_data *data, int philo_nb)
{
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->start = get_current_time();
	data->all_ate = 0;
	if (av[5])
		data->must_eat = ft_atoi(av[5]);
	else
		data->must_eat = -1;
	if (philo_nb <= 0)
		return (printf("number of philo must be > 0\n"), 1);
	else if (data->must_eat == 0)
		return (printf("All philos did not eat\n"), 1);
	else if (ft_atoi(av[2]) < 0 || ft_atoi(av[3]) < 0 || ft_atoi(av[4]) < 0)
		return (printf("time must be > 0\n"), 1);
	return (0);
}
