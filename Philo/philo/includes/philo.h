#ifndef PHILO_H
# define PHILO_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>


#define	STD_ERR_VALID	"Invalid number of arguments! Usage: ./philo number_of_philos time_to_die time_to_eat time_to_sleep [must_eat]"
#define STD_ERR_NUMBERS	 "Arguments must be positive numbers!"
#define STD_ERR_LIMITS	 "One or more arguments are out of range!"
#define	STD_ERR_START	"All arguments are valid! Starting the simulation..."
#define ERR_00 "Starting mutex initialisation\n"
#define ERR_01 "Initialising the mutex for the fork %d.\n"
#define ERR_02 "FAILURE:Fork also cannot initialise, HAIYA!!!.\n"
#define ERR_03 "The forks ahh is connected ahh successfullyy!!.\n"
#define ERR_04 "Initialising the writing lock ahh!\n "
#define ERR_05 "FAILURE: Writing lock also cannot initialise. GG!!!\n."
#define ERR_06 "The writing locks ahh is connected ahh successfully!!\n"
#define ERR_07 "All mutexes are initialised smoothly!\n"


typedef struct s_data{
	int philo_sum;
	pthread_mutex_t *fork;
	pthread_mutex_t writing_lock;
	t_args *args;
	t_philo *philo;
} t_data;

typedef struct s_args{
	// int 	philo_sum;
	int 	death_time;
	int 	feasting_time;
	int 	sleeping_time;
	int 	meals_sum;
} t_args;

typedef struct s_philo
{
	int 		id;
	int			id_left;
	int			id_right;
	long int	last_feast;
	int			num_of_meals;
} t_philo;


void	init_all(t_data *data, char **argv, int argc);
// Example of a struct:

// struct def_types {
// 	char name[50];
// 	int age;
// 	float gpa;
// };
#endif




int hello(int *x)
{
	*x = 10;
}
int main()
{
	int x;
	hello(&x);
	printf("%d\n", x);
}

