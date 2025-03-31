#ifndef PHILO_H
# define PHILO_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_PHILOS 200
#define MAX_INT_LIMIT 250
#define	VALIDITY_ERROR	"Invalid number of arguments! Usage: ./philo number_of_philos time_to_die time_to_eat time_to_sleep [must_eat]"
#define STR_ERR_NUMBERS	 "Arguments must be positive numbers!"
#define STD_ERR_LIMITS	 "One or more arguments are out of range!"
#define	STD_ERR_START	"All arguments are valid! Starting the simulation..."
#define ERR_00 "FAILURE:Fork also cannot initialise, HAIYA!!!.\n"
#define ERR_01 "The forks ahh is connected ahh successfullyy!!.\n"
#define ERR_02 "Initialising the writing lock ahh!\n "
#define ERR_03 "FAILURE: Writing lock also cannot initialise. GG!!!\n."
#define ERR_04 "The writing locks ahh is connected ahh successfully!!\n"
#define ERR_05 "All mutexes are initialised smoothly!\n"


typedef struct s_args{
	long long int	start_time;
	int 			death_time;
	int 			feasting_time;
	int 			sleeping_time;
	int 			meals_sum;
} t_args;

typedef struct s_philo
{
	int 		id;
	int			id_left;
	int			id_right;
	long int	last_feast;
	int			num_of_meals;
	pthread_t	thread;
	struct s_data *data;
} t_philo;

typedef struct s_data{
	int philo_sum;
	pthread_mutex_t *fork;
	pthread_mutex_t writing_lock;
	t_args *args;
	t_philo *philo;
} t_data;


void	timer(long long int time);
void	print_error(int n);
void print_success(int n);
long long int	gettime(void);
void philo_init(t_data *data);
void	eat(t_philo *philo);
void	start_sim(t_data *data);
void create_threads(t_data * data);
int		setup_fork_mutex(t_data *data);
void	end_checker(t_data *data);
void	*routine(void *philosopher);
void 	init_all(t_data *data, int argc);
void	print_action(t_data *data, int id, char *str);
int is_valid_check(t_data *data ,char **argv);
// Example of a struct:

// struct def_types {
// 	char name[50];
// 	int age;
// 	float gpa;
// };
#endif




// int hello(int *x)
// {
// 	*x = 10;
// }
// int main()
// {
// 	int x;
// 	hello(&x);
// 	printf("%d\n", x);
// }

