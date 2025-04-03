/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:34:58 by rvikrama          #+#    #+#             */
/*   Updated: 2025/04/04 00:22:10 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


void	print_action(t_data *data, int id, char *str)
{
	pthread_mutex_lock(&(data->writing_lock));
	pthread_mutex_lock(&(data->sim_lock));
	if (data->sim_running)
	{
		printf("%lld ", gettime() - data->args->start_time);
		printf("%d ", id + 1);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&(data->sim_lock));
	pthread_mutex_unlock(&(data->writing_lock));

}

void	eat(t_philo *philo)
{
	t_data *data;
	data = philo->data;
	
	if (data->philo_sum == 1)
	{
		pthread_mutex_lock(&(data->fork[philo->id_left]));
		print_action(data, philo->id, "has taken a fork");
		pthread_mutex_unlock(&(data->fork[philo->id_left]));
		timer(data->args->death_time + 10);
		return;
	}
	
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&(data->fork[philo->id_right]));
		pthread_mutex_lock(&(data->fork[philo->id_left]));
	}
	else
	{
		pthread_mutex_lock(&(data->fork[philo->id_left]));
		pthread_mutex_lock(&(data->fork[philo->id_right]));
	}

	print_action(data, philo->id, "has taken a fork");
	print_action(data, philo->id, "has taken a fork");

	print_action(data, philo->id, "is eating");	
	
	pthread_mutex_lock(&philo->feast_lock);
	philo->last_feast = gettime();
	philo->num_of_meals++;
	pthread_mutex_unlock(&philo->feast_lock);
	timer(data->args->feasting_time);
	
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&(data->fork[philo->id_left]));
		pthread_mutex_unlock(&(data->fork[philo->id_right]));
	}
	else
	{
		pthread_mutex_unlock(&(data->fork[philo->id_right]));
		pthread_mutex_unlock(&(data->fork[philo->id_left]));
	}
}

bool check_stop(t_data *data)
{
	bool status;

	pthread_mutex_lock(&data->sim_lock);
	status = data->sim_running;
	pthread_mutex_unlock(&data->sim_lock);

	return (status);
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
	if (philo->id % 2 != 0) // 0 % 2 = 0
	{
		print_action(data, philo->id, "is thinking");
		timer(data->args->feasting_time / 2);
	}
	while (check_stop(data))
	{
		eat(philo);
		print_action(data, philo->id, "is sleeping");
		timer(data->args->sleeping_time);
		print_action(data, philo->id, "is thinking");
	}
	return (NULL);
}


// void	end_checker(t_data *data)
// {
// 	int	i;
// 	int all_ate;

// 	while (1)
// 	{
// 		i = 0;
// 		while (i < data->philo_sum)
// 		{
// 			if (gettime() - data->philo[i].last_feast > data->args->death_time)
// 			{
// 				print_action(data, i, "died");
// 				exit(0);
// 			}
// 			i++;
// 		}
		
// 		if (data->args->meals_sum!= -1)
// 		{
// 			all_ate = 1;
// 			i = 0;
// 			while(i < data->philo_sum)
// 			{
// 				if (data->philo[i].num_of_meals < data->args->meals_sum)
// 				{
// 					all_ate = 0;
// 					break;
// 				}
// 				i++;
// 			}
// 			if (all_ate)
// 				return;
// 		}
// 		usleep(1000);
// 	}
// }

void end_checker(t_data *data)
{
    int         i;
    bool         all_ate;
    long long   now;

    while (1)
    {
        i = -1;
    	now = gettime();
        while (++i < data->philo_sum)
        {
            pthread_mutex_lock(&data->philo[i].feast_lock);
            if ((int)(now - data->philo[i].last_feast) > data->args->death_time)
            {
                print_action(data, i, "died");
                
				pthread_mutex_lock(&data->sim_lock);
				data->sim_running = false;

				pthread_mutex_unlock(&data->sim_lock);
				pthread_mutex_unlock(&data->philo[i].feast_lock);
				
				return ;
            }
            pthread_mutex_unlock(&data->philo[i].feast_lock);
        }

        if (data->args->meals_sum > 0)
        {
            all_ate = true;
            i = -1;
            while (++i < data->philo_sum && all_ate)
            {
                pthread_mutex_lock(&data->philo[i].feast_lock);
                all_ate = (data->philo[i].num_of_meals >= data->args->meals_sum);
                pthread_mutex_unlock(&data->philo[i].feast_lock);
            }
            if (all_ate)
            {
                print_action(data, -1, "All philosophers are full");

                pthread_mutex_lock(&data->sim_lock);
				data->sim_running = false;
				pthread_mutex_unlock(&data->sim_lock);
                
				return;
            }
        }
        usleep(500);
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

	data->sim_running = true; 
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


