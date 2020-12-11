/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 23:19:47 by kallard           #+#    #+#             */
/*   Updated: 2020/12/11 10:25:46 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

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
	launch_philos(&setup, philos);
	finishing(&setup, philos);
	return (SUCCESS);
}
