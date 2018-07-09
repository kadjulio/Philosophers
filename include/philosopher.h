/*
** EPITECH PROJECT, 2018
** philosopher Header
** File description:
** PSU_philosopher_2017
*/

#ifndef PHILOSOPHER_H_
#define PHILOSOPHER_H_

#include "extern.h"
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct	philo_s
{
	pthread_t	thread;
	pthread_mutex_t	chopstick;
	int		empty_bowl;
	int		position;
	struct	philo_s	*next;
}		philo_t;

extern int	nb_philo;
extern int	eat_max;
extern philo_t	**philo;

void	*create_philo(philo_t *phil, int pos);
void	init_next(philo_t **philo);
int	init_philo(int nb_philo);
int	check_args(char **);
int	get_philos(char **);
int	get_eat(char **);
void	philo_eats(philo_t *philo);
void	philo_thinks(philo_t *philo);
void	philo_rests(void);
void	wait_end_of_threads(void);
void	free_philo(philo_t **philo);
void	*do_action(void *philo);
bool	is_number(char *str);
int	check_err(int ac, char **av);
void	init_struct(int nb_philo);



#endif /* !PHILOSOPHER_H_ */
