/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:46:48 by sbzizal           #+#    #+#             */
/*   Updated: 2023/06/21 17:40:10 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	signe;

	i = 0;
	res = 0;
	signe = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - 48;
	}
	return (res * signe);
}

t_philo	*ft_lstlast(t_philo *lst)
{
	t_philo	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next != NULL && tmp->next != lst)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*last;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		(*lst)->next = *lst;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
	new->next = *lst;
}

t_philo	*ft_lstnew(int id, t_data *data)
{
	t_philo	*philo;

	philo = NULL;
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = id;
	pthread_mutex_init(&philo->fork, NULL);
	philo->count = 0;
	philo->data = data;
	philo->next = NULL;
	return (philo);
}
