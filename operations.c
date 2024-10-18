/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:58:41 by agenc             #+#    #+#             */
/*   Updated: 2023/11/20 17:07:47 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	real_death(t_table *table)
{
	pthread_mutex_lock(&table->general_mutex);
	if (table->death_philo == 1)
	{
		pthread_mutex_unlock(&table->general_mutex);
		return (0);
	}
	pthread_mutex_unlock(&table->general_mutex);
	return (1);
}

int	necessary_eating(t_table *table, int i)
{
	pthread_mutex_lock(&table->general_mutex);
	if (table->mand_eat_count == table->philos[i]->eat_count)
	{
		pthread_mutex_unlock(&table->general_mutex);
		return (0);
	}
	pthread_mutex_unlock(&table->general_mutex);
	return (1);
}

int	sleeping(t_table *table, int index)
{
	if (!write_status(table, index, "is sleeping"))
		return (0);
	philo_sleep(table->time_to_sleep);
	return (1);
}

int	thinking(t_table *table, int index)
{
	if (!write_status(table, index, "is thinking"))
		return (0);
	return (1);
}

int	eating(t_table *table, int index)
{
	if (real_death(table))
	{
		pthread_mutex_lock(&table->forks[index]);
		if (!write_status(table, index, "has taken fork"))
			return (0);
		pthread_mutex_lock(&table->forks[(index + 1) % table->nbr_of_philo]);
		if (!write_status(table, index, "has taken fork"))
			return (0);
		if (!write_status(table, index, "is eating"))
			return (0);
		pthread_mutex_lock(&table->general_mutex);
		table->philos[index]->eat_count += 1;
		table->philos[index]->last_eat_time = get_time();
		pthread_mutex_unlock(&table->general_mutex);
		philo_sleep(table->time_to_eat);
		pthread_mutex_unlock(&table->forks[index]);
		pthread_mutex_unlock(&table->forks[(index + 1) % table->nbr_of_philo]);
		return (1);
	}
	else
		return (0);
}
