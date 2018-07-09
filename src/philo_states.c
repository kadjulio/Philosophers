/*
** EPITECH PROJECT, 2018
** philo states
** File description:
** philosophers
*/

#include "philosopher.h"

int	nb_philo;
int	eat_max;
philo_t	**philo;

void	philo_eats(philo_t *philo)
{
	lphilo_take_chopstick(&philo->chopstick);
	lphilo_take_chopstick(&philo->next->chopstick);
	lphilo_eat();
	usleep(500);
	philo->empty_bowl++;
	lphilo_release_chopstick(&philo->chopstick);
	lphilo_release_chopstick(&philo->next->chopstick);
	pthread_mutex_unlock(&philo->chopstick);
	pthread_mutex_unlock(&philo->next->chopstick);
}

void	philo_thinks(philo_t *philo)
{
	lphilo_take_chopstick(&philo->chopstick);
	lphilo_think();
	usleep(500);
	lphilo_release_chopstick(&philo->chopstick);
	pthread_mutex_unlock(&philo->chopstick);
}

void	philo_rests(void)
{
	lphilo_sleep();
}

void	wait_end_of_threads(void)
{
	int	i;

	i = 0;
	while (i < nb_philo) {
		pthread_join((philo[i]->thread), NULL);
		i = i + 1;
	}
}

void	free_philo(philo_t **philo)
{
	int	i = 0;

	while (i < nb_philo) {
		free(philo[i]);
		i++;
	}
	free(philo);
}