/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:06:06 by sbzizal           #+#    #+#             */
/*   Updated: 2023/06/21 21:44:06 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo {
	pthread_mutex_t	fork;
	pthread_mutex_t	*print_mutex;
	size_t			time_last_eat;
	pthread_t		tid;
	int				id;
	int				count;
	struct s_philo	*next;
	struct s_data	*data;

}	t_philo;

typedef struct s_data {
	int				time_eat;
	int				time_sleep;
	int				must_eat;
	int				all_ate;
	size_t			start;
	size_t			time_die;
	struct s_philo	*philo;

}	t_data;

t_philo		*ft_lstnew(int id, t_data *data);
size_t		get_period(size_t start);
size_t		get_period(size_t start);
size_t		get_current_time(void);
int			ft_atoi(const char *str);
int			pars_philo(char *str);
int			ins_var(char **av, t_data *data, int philo_nb);
int			check_death(t_philo *philos, t_data data, int philo_nb);
void		ft_lstadd_back(t_philo **lst, t_philo *new);
void		*philo_routine(void *temp);
void		ft_usleep(size_t time);
void		taken_fork1(t_philo *philo);
void		taken_fork2(t_philo *philo);
void		is_eating(t_philo *philo);
void		is_sleeping(t_philo *philo);
void		is_thinking(t_philo *philo);
void		check_eat(t_philo *philo);
void		free_all(t_philo *philos, int philo_nb);

#endif
