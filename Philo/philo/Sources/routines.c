/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:34:58 by rvikrama          #+#    #+#             */
/*   Updated: 2025/04/01 16:15:55 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


void	print_action(t_data *data, int id, char *str)
{
	pthread_mutex_lock(&(data->writing_lock));
	printf("%lld ", gettime() - data->args->start_time);
	printf("%d ", id + 1);
	printf("%s\n", str);
	pthread_mutex_unlock(&(data->writing_lock));

}

void	eat(t_philo *philo)
{
	t_data *data;

	
	data = philo->data;
	pthread_mutex_lock(&(data->fork[data->philo->id_left]));
	print_action(data, philo->id, "has taken a fork");

	if (data->philo_sum == 1)
	{
		pthread_mutex_unlock(&(data->fork[philo->id_left]));
		return;
	}
	
	pthread_mutex_lock(&(data->fork[data->philo->id_right]));
	print_action(data, philo->id, "has taken a fork");
	
	data->philo->last_feast = gettime();
	print_action(data, philo->id, "is eating");
	data->philo->num_of_meals++;

	timer(data->args->feasting_time);
	
	pthread_mutex_unlock(&(data->fork[data->philo->id_left]));
	pthread_mutex_unlock(&(data->fork[data->philo->id_right]));
}


void	*routine(void *philosopher)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)philosopher;
	philo->last_feast = gettime();
	data = philo->data;
	// if (data->philo_sum == 1)
	// 	return (single_philo());
	if (philo->id % 2 == 0)
	{
		print_action(data, philo->id, "is thinking");
		timer(data->args->feasting_time);
	}
	while (1)
	{
		eat(philo);
		print_action(data, philo->id, "is sleeping");
		timer(data->args->sleeping_time);
		print_action(data, philo->id, "is thinking");
	}
	return (NULL);
}


void	end_checker(t_data *data)
{
	int	i;

	i = 0;
	usleep(200);
	while (1)
	{
		while (i < data->philo_sum)
		{
			// printf("Hi i am in this loop\n");
			if (gettime() - data->philo[i].last_feast > data->args->death_time)
			{
				print_action(data, i, "died");
				exit(0);
			}
			i++;
		}
		i = 0;
		if (data->args->meals_sum!= -1)
		{
			while (data->philo[i].num_of_meals >= data->philo_sum)
				i++;
			if (i == data->philo_sum)
				exit(0);
		}
	}
}



void create_threads(t_data * data)
{
	int i;

	i = 0;
	// printf("%d\n", data->philo_sum);
	// printf("%d\n", data->philo_sum);
	while ( i < data->philo_sum) // Lopps til all philo has got a tread on its own.
	{
		if (pthread_create(&(data->philo[i].thread), NULL, routine,
			&(data->philo[i])) != 0)
			print_error(4);// Error, just incase if the thread creation fails.
		i++;// Increment.
	}
}

void	start_sim(t_data *data)
{
	int i;

	data->args->start_time = gettime(); // Stroing the starting time of the sim.
	// printf("%d\n", data->philo_sum);
	create_threads(data); //Calls function to create the threads for the philo.
	end_checker(data); // Function to help monitor the sim.


	i = 0;
	while (i < data->philo_sum)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}

	i = 0;
	while (i < data->philo_sum)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&data->writing_lock);
	// while ( i < data->philo_sum) // Lopps til all philo has got a tread on its own.
	// {
	// 	pthread_join(data->philo[i].thread, NULL);
	// 	i++;// Increment.
	// }
	printf("eeeeeeeeeeeeee\n");
}


