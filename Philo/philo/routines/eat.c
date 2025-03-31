void	eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&(data->fork[philo->left_fork_id]));
	print_action(data, philo->id, "has taken a fork");
	pthread_mutex_lock(&(data->fork[philo->right_fork_id]));
	print_action(data, philo->id, "has taken a fork");
	philo->last_ate = gettime();
	print_action(data, philo->id, "is eating");
	philo->num_of_meals++;
	timer(data->eating_time);
	pthread_mutex_unlock(&(data->fork[philo->left_fork_id]));
	pthread_mutex_unlock(&(data->fork[philo->right_fork_id]));
}

Code Explaination:
	-> This code is responsible for handling the philos eating routine.
	   in this simulation...


Step By step explaination.
	->	Starts with struct, t_data *data. Obtains information from that struct.
	->  Allows access to the dats inside the philo struct.
	->	Next picking up the left fork, [pthread_mutex_lock]
		is a library function to be called,that locks the fork and preventing 
		other philos from taking the left fork at the same time.
	-> 	Print out the left fork, with the systax" Has taken a fork".
	->	Picking up the right fork, similar to the left one, but this time its the
		rigth, using[pthread_mutex_lock], we lock the rigth fork, to ensure that a 
		a philo would have two forks when they eat.
	->	Prints out the systax in the CLI" Has taken another fork".
	->	Updates the last time eaten.
	-> 	Increment the meal count.
	->	thus takes a pause to allow eating itme 
	