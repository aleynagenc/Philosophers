/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:00:02 by agenc             #+#    #+#             */
/*   Updated: 2023/11/20 17:07:59 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct philo{
	int					philo_id;
	int					eat_count;
	unsigned long		last_eat_time;
	pthread_t			p_thread;
}			t_philo;

typedef struct table{
	int					nbr_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					mand_eat_count;
	int					thread_index;
	int					death_philo;
	unsigned long		start_time;
	pthread_t			grim_reaper;
	pthread_mutex_t		general_mutex;
	pthread_mutex_t		*forks;
	t_philo				**philos;
}			t_table;

int					arg_control(int argc, char **argv);
int					arg_atoi(int ac, char **av, t_table *table);
int					ft_digit(char **str);
int					ft_atoi(char *str);
int					detail_control(t_table *table);
int					init_philo(t_table *table);
unsigned long		get_time(void);
int					init_mutex(t_table *table);
int					start_simulation(t_table *table);
int					multiple_philosophers(t_table *table);
void				*one_philo(void *data);
unsigned long		time_calculator(unsigned long last);
void				philo_sleep(int time_die);
void				thread_join(t_table *table);
void				*multi_philo(void *data);
void				*dead(void *data);
int					eating(t_table *table, int index);
int					real_death(t_table *table);
int					write_status(t_table *table, int i, char *str);
int					necessary_eating(t_table *table, int i);
int					sleeping(t_table *table, int index);
int					thinking(t_table *table, int index);
void				destroy_mutexes(t_table *table);
void				free_table(t_table *table);

#endif
