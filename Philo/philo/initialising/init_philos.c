// ~init_philos is technically a function that initailizes the philospphers struct 
//  with their ID, Fork assingments, and traking variables. Each philo must have a 
//  unique ID assinged ot them.
// ~Each philo gets:
// 	-ID:their philosophers number.
// 	-Left_fork_id:Same as their ID.
// 	-right_fork_id:next philosophers for(handled with i + 1)% total_philo_num to 
// 	  wrap around.
// 	-last_ate:set to 0 initially.
// 	-num_of_meals:also 0 initially.
// 	-data: a pointer to the shared simulation data.


	
	
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct s_philo
{
	int 		id;
	int			id_left;
	int			id_right;
	long int	last_feast;
	int			num_of_meals;
} t_philo;

void philos_init(t_philo *philo, int sum_philo)
{
	int i = 0;

	while (i < sum_philo)
	{
		philo[i].id = i;
		philo[i].id_left = i;
		philo[i].id_right = (i + 1) % sum_philo;
		philo[i].last_feast = 0;
		philo[i].num_of_meals = 0;
		i++;
	}
}

// the main to test the philo_init.
int main()
{
	int num_philos = 5;  // Number of existing philo.
	t_philo *philos;

	// Memory allocated for the philo.
	philos = malloc(sizeof(t_philo) * num_philos);
	if (!philos)
	{
		printf("Memory allocation failed!\n");
		return (1);
	}

	// initialising the philosophers.
	philos_init(philos, num_philos);

	// printing the test output.
	printf("=== Philosopher Data ===\n");
	for (int i = 0; i < num_philos; i++)
	{
		printf("Philosopher %d: Left Fork: %d, Right Fork: %d, Meals: %d\n",
			   philos[i].id, philos[i].id_left, philos[i].id_right, philos[i].num_of_meals);
	}

	// Freeinf the  allocated memory.
	free(philos);

	return (0);
}
