#include "stdlib.h"
#include "unistd.h"
#include "stdio.h"
#include "pthread.h"


typedef struct s_philo
{
	int 	philo_sum;
	int 	feast_time;
	int 	sleep_time;
	int 	death_time;
	int		meals_sum;
} t_philo;
void	init_all(t_philo *philo, char **argv, int argc)
{
	data->philo_sum = (argv[1]);
	data->death_time = (argv[2]);
	data->feasting_time = (argv[3]);
	data->sleep_time = (argv[4]);
	if (argc == 6)
	{
		data->meals_sum = (argv[5]);
		if (data->meals_sum < 0)
			print();
	}
	else
		data->meals_sum = -1;
	if (data->philo_sum < 1)
		printf("error 404\n");
	else if (data->death_time < 60)
		printf ("error 404\n");
	else if (data->feasting_time < 60)
		printf ("error 404\n");
	else if (data->sleeping_time < 60)
		printf ("error 404\n");
	else (data->philo_sum > 200)
		printf("error 404\n");

	init_mutexes(data);
	init_philo(data);
}
