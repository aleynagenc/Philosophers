/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:58:35 by agenc             #+#    #+#             */
/*   Updated: 2023/11/20 17:09:54 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_time(void)
{
	struct timeval		tv;

	gettimeofday (&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec * 0.001));
}

unsigned long	time_calculator(unsigned long last)
{
	return (get_time() - last);
}

void	philo_sleep(int time_to_die)
{
	unsigned long	time;

	time = get_time() + time_to_die;
	while (get_time() <= time)
		usleep(100);
}
