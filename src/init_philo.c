/*
** EPITECH PROJECT, 2018
** init_philo
** File description:
** philosophers
*/

#include "philosopher.h"

int	nb_philo;
int	eat_max;
philo_t	**philo;

void	*create_philo(philo_t *phil, int pos)
{
	phil->empty_bowl = 0;
	phil->position = pos;
	pthread_mutex_init(&phil->chopstick, NULL);
	return (phil);
}

void	init_next(philo_t **philo)
{
	int	i = 0;

	while (i < nb_philo - 1)
	{
		philo[i]->next = philo[i + 1];
		i++;
	}
	philo[nb_philo - 1]->next = philo[0];
}


void	init_struct(int nb_philo)
{
	int	i = 0;

	philo = malloc(sizeof(philo_t) * nb_philo);
	while (i < nb_philo) {
		philo[i] = malloc(sizeof(philo_t));
		philo[i] = create_philo(philo[i], i);
		i++;
	}
	init_next(philo);
}

int	init_philo(int nb_philo)
{
	init_struct(nb_philo);
	int	i = 0;
	while (i < nb_philo) {
		if (pthread_create(&philo[i]->thread, NULL,
			do_action, (void *) philo[i]) == -1)
			return (84);
		i++;
	}
	return (0);
}
