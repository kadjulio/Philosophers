/*
** EPITECH PROJECT, 2018
** philo.c
** File description:
** PSU_2017_philosophers
*/

#include "philosopher.h"

int	nb_philo;
int	eat_max;
philo_t	**philo;

void	*do_action(void *philo)
{
	int	next_one;
	int	this_one;
	philo_t *phil;

	phil = (philo_t *)philo;
	while (phil->empty_bowl < eat_max) {
		next_one = pthread_mutex_trylock(&phil->next->chopstick);
		this_one = pthread_mutex_trylock(&phil->chopstick);
		if (next_one == 0 && this_one == 0) {
			philo_thinks(phil);
			philo_eats(phil);
			philo_rests();
		} else {
			if (next_one == 0)
				pthread_mutex_unlock(&phil->next->chopstick);
			if (this_one == 0)
				pthread_mutex_unlock(&phil->chopstick);
		}
	}
	return (0);
}

int	check_err(int ac, char **av)
{
	if (ac < 5)
		return (84);
	if (check_args(av) == 84)
		return (84);
	nb_philo = get_philos(av);
	eat_max = get_eat(av);
	if (nb_philo < 2 || eat_max < 1)
		return (84);
	return (0);
}

int	main(int ac, char **av)
{
	RCFStartup(ac, av);
	if (check_err(ac, av) == 84)
		return (84);
	if (init_philo(nb_philo) == 84)
		return (84);
	wait_end_of_threads();
	free_philo(philo);
	RCFCleanup();
	return (0);
}
