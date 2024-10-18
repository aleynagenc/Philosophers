/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:58:32 by agenc             #+#    #+#             */
/*   Updated: 2023/11/20 17:49:17 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_join(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->nbr_of_philo)
	{
		pthread_join (table->philos[i]->p_thread, NULL);
		i++;
	}
	pthread_join (table->grim_reaper, NULL);
}

void	*one_philo(void *data)
{
	t_table		*table;

	table = (t_table *)data;
	pthread_mutex_lock (&table->forks[0]);
	printf ("%-10lu    %d %s\n", time_calculator(table->start_time),
		table->philos[0]->philo_id, "has taken fork");
	philo_sleep (table->time_to_die);
	printf ("%-10lu    %d %s\n", time_calculator(table->start_time),
		table->philos[0]->philo_id, "died");
	pthread_mutex_unlock (&table->forks[0]);
	return (NULL);
}

void	*multi_philo(void *data)
{
	t_table		*table;
	int			i;

	table = (t_table *)data;
	pthread_mutex_lock(&table->general_mutex);
	i = table->thread_index;
	pthread_mutex_unlock(&table->general_mutex);
	if (table->philos[i]->philo_id % 2 == 0)
		usleep (100);
	while (1)
	{
		if (necessary_eating(table, i) || real_death(table))
		{
			if (!eating(table, i))
				break ;
			if (!sleeping(table, i))
				break ;
			if (!thinking(table, i))
				break ;
		}
		else
			break ;
	}
	return (0);
}

int	multiple_philosophers(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->nbr_of_philo)
	{
		pthread_mutex_lock(&table->general_mutex);
		table->thread_index = i;
		pthread_mutex_unlock(&table->general_mutex);
		if (pthread_create(&table->philos[i]->p_thread,
				NULL, &multi_philo, table) != 0)
			return (0);
		usleep (100);
		i++;
	}
	if (pthread_create(&table->grim_reaper, NULL, &dead, table) != 0)
		return (0);
	thread_join (table);
	return (1);
}

int	start_simulation(t_table *table)
{
	table->start_time = get_time();
	if (table->nbr_of_philo == 1)
	{
		if (pthread_create(&table->philos[0]->p_thread,
				NULL, &one_philo, table) != 0)
			return (0);
		pthread_join (table->philos[0]->p_thread, NULL);
	}
	else
	{
		if (!multiple_philosophers(table))
			return (0);
	}
	return (1);
}
