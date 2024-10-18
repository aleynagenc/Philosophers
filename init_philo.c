/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:58:48 by agenc             #+#    #+#             */
/*   Updated: 2023/11/20 17:08:54 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_table *table)
{
	int		i;

	i = 0;
	table->philos = malloc(sizeof(t_philo *) * table->nbr_of_philo);
	if (!table->philos)
		return (0);
	table->death_philo = 0;
	table->thread_index = 0;
	while (i < table->nbr_of_philo)
	{
		table->philos[i] = malloc(sizeof(t_philo));
		if (!table->philos[i])
			return (0);
		table->philos[i]->philo_id = i + 1;
		table->philos[i]->eat_count = 0;
		table->philos[i]->last_eat_time = get_time();
		i++;
	}
	return (1);
}
