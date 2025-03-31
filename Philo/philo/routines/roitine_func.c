void create_threads(t_data * data)
{
	int i;

	i = 0;
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
	data->star_time = gettime(); // Stroing the starting time of the sim.
	create_threads(data); //Calls function to create the threads for the philo.
	end_checker(data); // Function to help monitor the sim.
}