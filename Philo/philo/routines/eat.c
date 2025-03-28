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