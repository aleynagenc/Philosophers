/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:56:28 by agenc             #+#    #+#             */
/*   Updated: 2023/11/20 17:08:14 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_digit(char **str)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] < '0' || str[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	arg_control(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf ("Number of invalid arguments!");
		return (0);
	}
	if (!ft_digit(argv))
	{
		printf ("Invalid character!");
		return (0);
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int				i;
	long long int	result;

	result = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
		|| str[i] == ' ' || str[i] == 'f')
		i++;
	while (str[i])
	{
		result = (result * 10) + (str[i] - 48);
		if (result > 2147483647 || result < -2147483647)
			return (-1);
		i++;
	}
	return (result);
}

int	detail_control(t_table *table)
{
	if (table->nbr_of_philo == -1 || table->time_to_die == -1
		|| table->time_to_eat == -1 || table->time_to_sleep == -1
		|| table->mand_eat_count == -1)
	{
		printf("Argument is outside the desired integer range!");
		return (0);
	}
	if (table->nbr_of_philo == 0)
		return (0);
	if (table->time_to_die == 0)
	{
		printf ("0 1 died");
		return (0);
	}
	return (1);
}

int	arg_atoi(int ac, char **av, t_table *table)
{
	int	temp;

	temp = 0;
	table->nbr_of_philo = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		temp = ft_atoi(av[5]);
		if (temp == 0)
			return (0);
		else
			table->mand_eat_count = temp;
	}
	else
		table->mand_eat_count = -2;
	if (!detail_control(table))
		return (0);
	return (1);
}
