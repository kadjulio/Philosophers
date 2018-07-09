/*
** EPITECH PROJECT, 2018
** philo
** File description:
** parsing arguments
*/

#include "philosopher.h"

bool	is_number(char *str)
{
	int	i = 0;

	while (str[i]) {
		if (!isdigit(str[i]))
			return (false);
		i += 1;
	}
	return (true);
}

int	check_args(char **argv)
{
	bool	p = (!strcmp(argv[1], "-p") || !strcmp(argv[3], "-p"));
	bool	e = (!strcmp(argv[1], "-e") || !strcmp(argv[3], "-e"));

	if (!is_number(argv[2]) || !is_number(argv[4]) || !e || !p)
		return (84);
	return (0);
}

int	get_philos(char **argv)
{
	int	i = 0;

	if (!strcmp(argv[1], "-p"))
		i = 2;
	else if (!strcmp(argv[3], "-p"))
		i = 4;
	return (atoi(argv[i]));
}

int	get_eat(char **argv)
{
	int	i = 0;

	if (!strcmp(argv[1], "-e"))
		i = 2;
	else if (!strcmp(argv[3], "-e"))
		i = 4;
	return (atoi(argv[i]));
}
