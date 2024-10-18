/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:59:09 by agenc             #+#    #+#             */
/*   Updated: 2023/11/20 17:45:42 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table		*table;

	if (!arg_control(ac, av))
		return (0);
	table = malloc(sizeof(t_table));
	if (!table)
		return (0);
	if (!arg_atoi(ac, av, table))
		return (0);
	if (!init_philo(table))
		return (0);
	if (!init_mutex(table))
		return (0);
	if (!start_simulation(table))
		return (0);
	destroy_mutexes(table);
	free_table(table);
	return (1);
}
