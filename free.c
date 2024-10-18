/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:57:11 by agenc             #+#    #+#             */
/*   Updated: 2023/11/20 17:08:45 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_table(t_table *table)
{
	int		i;

	i = 0;
	if (!table)
		return ;
	if (table->forks != NULL)
		free(table->forks);
	if (table->philos != NULL)
	{
		i = 0;
		while (i < table->nbr_of_philo)
		{
			if (table->philos[i] != NULL)
				free(table->philos[i]);
			i++;
		}
		free (table->philos);
	}
	free (table);
}
