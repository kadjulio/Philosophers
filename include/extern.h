/*
** EPITECH PROJECT, 2018
** philo
** File description:
** extern header
*/

#ifndef __LIBRICEFEREE_EXTERN__
#define __LIBRICEFEREE_EXTERN__

#include <pthread.h>

int	RCFStartup(int, char **);
void	RCFCleanup();
int	lphilo_eat();
int	lphilo_sleep();
int	lphilo_think();
int	lphilo_take_chopstick(const pthread_mutex_t *);
int	lphilo_release_chopstick(const pthread_mutex_t *);

#endif /* __LIBRICEFEREE_EXTERN__ */
