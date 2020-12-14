/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 23:19:47 by kallard           #+#    #+#             */
/*   Updated: 2020/12/14 15:13:16 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 5 && argc != 6)
		args_error();
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i] && argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				args_error();
			j++;
		}
		i++;
	}
}

void		starting(t_philo *philos, t_setup *setup)
{
	int		i;
	pid_t	*p_ids;

	if (!(p_ids = malloc(sizeof(pid_t) * setup->num_of_philos)))
		malloc_error();
	i = -1;
	while (++i < setup->num_of_philos)
	{
		if (!(i % 2))
			launch_philos(&philos[i], p_ids, i);
	}
	usleep(100);
	i = -1;
	while (++i < setup->num_of_philos)
	{
		if (i % 2)
			launch_philos(&philos[i], p_ids, i);
	}
	setup->p_ids = p_ids;
}

int			main(int argc, char **argv)
{
	t_setup	setup;
	t_philo	*philos;
	
	check_args(argc, argv);
	init_setup_struct(&setup, argc, argv);
	philos = malloc(sizeof(t_philo) * setup.num_of_philos);
	if (!philos)
		malloc_error();
	init_philo_structs(philos, &setup);
	starting(philos, &setup);
	finishing(&setup, philos);
	return (SUCCESS);
}
