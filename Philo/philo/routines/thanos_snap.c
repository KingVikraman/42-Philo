void	end_checker(t_data *data)
{
	int	i;

	i = 0;
	usleep(50);
	while (1)
	{
		while (i < data->total_philo_num)
		{
			if (gettime() - data->philo[i].last_ate > data->death_time)
			{
				print_action(data, i, "died");
				exit(0);
			}
			i++;
		}
		i = 0;
		if (data->total_meals != -1)
		{
			while (data->philo[i].num_of_meals >= data->total_meals)
				i++;
			if (i == data->total_philo_num)
				exit(0);
		}
	}
}