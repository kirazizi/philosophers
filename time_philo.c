/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:58:52 by sbzizal           #+#    #+#             */
/*   Updated: 2023/06/20 13:57:42 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_time(void)
{
	size_t			millisecond;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	millisecond = ((current_time.tv_sec * 1000) +(current_time.tv_usec / 1000));
	return (millisecond);
}

size_t	get_period(size_t start)
{
	return (get_current_time() - start);
}

void	ft_usleep(size_t time)
{
	size_t	start;

	start = get_current_time();
	while (get_period(start) < time)
		usleep(100);
}
