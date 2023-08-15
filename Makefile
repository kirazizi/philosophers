# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbzizal <sbzizal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 11:13:50 by sbzizal           #+#    #+#              #
#    Updated: 2023/06/22 14:16:39 by sbzizal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Wextra -Werror
 
CFILES = philo.c utils_lst.c pars_philo.c routine_philo.c time_philo.c utils_routine.c check_death.c

OFILES = ${CFILES:.c=.o}

all: $(NAME)

$(NAME): $(OFILES) 
	@$(CC) $(CFLAGS) $(OFILES) -o $(NAME) 

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all