/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:03:18 by rvikrama          #+#    #+#             */
/*   Updated: 2025/04/03 22:41:38 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// When you pass by reference (&), you keep modifying the original struct.
// When you pass by value, a copy is made, so changes don’t reflect outside.

int		setup_fork_mutex(t_data *data)
{
	int fork;
	int error;

	fork = 0;
	while (fork < data->philo_sum)
	{
		printf("%d\n",fork);
		error = pthread_mutex_init(&data->fork[fork], NULL);
		if (error != 0)
		{
			// printf("%d\n", error);
			// printf("%d\n", fork);
			return(printf(ERR_00));
		}
		else
			printf(ERR_01);
		fork++;

	}
	// printf(ERR_02);
	error = pthread_mutex_init(&data->writing_lock, NULL);
	error = pthread_mutex_init(&data->sim_lock, NULL);
	// 	pthread_mutex_lock(&(data->writing_lock));	
	// 	printf("hello\n");
	// 	pthread_mutex_unlock(&(data->writing_lock));
	// printf("init writing lock\n");
	if (error != 0)
	{
		printf("ERROR lock\n");
		return(printf(ERR_03), -1);
	}
	else
		return(printf(ERR_05), -1);
		// printf(ERR_04);
}

void philo_init(t_data *data)
{

	int i = 0;

	while (i < data->philo_sum)
	{
		data->philo[i].id = i;
		data->philo[i].id_left = i;
		data->philo[i].id_right = (i + 1) % data->philo_sum;
		data->philo[i].last_feast = 0;
		data->philo[i].num_of_meals = 0;
		pthread_mutex_init(&data->philo[i].feast_lock, NULL);
		data->philo[i].data = data;
		i++;
	}
}


void 	init_all(t_data *data, int argc)
{
	if ((argc == 6 && data->args->meals_sum < 0) ||
		(data->philo_sum < 1) || (data->args->death_time < 60)
		|| (data->args->feasting_time < 60) || (data->args->sleeping_time < 60)
		|| (data->philo_sum > 200))
	{
		print_error(1);
		// return (-1);
	}	
	setup_fork_mutex(data);
	philo_init(data);
}




// Commit Messages : 	-> Added 42 header to file.
// 					-> Modified the code logic abit
// 						removed a if loop and simplified it
// 						much much more
// 					->Made it to one single loop.
// 					->removed multiple printfs in the function.
// 					-> made an error fucntion to be called in this
// 					   function.
// 					-> removed the struct from the init_philo file and 
// 					   moved it to the header file.
// 					-> added the init_utexes function here.
// 					-> Modified the code the init_mutexes function,
// 						[Removed unessesary brackets, printfs, and 
// 						shrtened the code in general.]
// 					-> Added the init_philos function.
// 					-> Updated the structs and how it is 
// 					   accsessed. Moreover the logic has changed a little
// 					   made the if loopl more shorter and totally 
// 					   removed the else part and the if loop for argc == 6.
// 					->
					