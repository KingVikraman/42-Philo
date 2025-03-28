void	*routine(void *philosopher)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)philosopher;
	philo->last_ate = gettime();
	data = philo->data;
	if (philo->id % 2 == 0)
	{
		print_action(data, philo->id, "is thinking");
		timer(data->eating_time);
	}
	while (1)
	{
		eat(philo);
		print_action(data, philo->id, "is sleeping");
		timer(data->sleeping_time);
		print_action(data, philo->id, "is thinking");
	}
	return (NULL);
}