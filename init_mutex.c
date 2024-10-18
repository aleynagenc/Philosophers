/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:57:22 by agenc             #+#    #+#             */
/*   Updated: 2023/11/20 17:08:50 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_table *table)
{
	int		i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->nbr_of_philo);
	if (!table->forks)
		return (0);
	while (i < table->nbr_of_philo)
	{
		if (pthread_mutex_init(&table->forks[i], 0) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_init(&table->general_mutex, 0) != 0)
		return (0);
	return (1);
}
