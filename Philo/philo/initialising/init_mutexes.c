
// 	i = 0;
// 	while (i < data->total_philo_num) // a loop that runs once for each philo.
// 	{
// 		error = pthread_mutex_init(&(data->fork[i]), NULL);//the threads i am using is a library instead of a actual funtion.
// 		if (error != 0)
// 			print_error(3);
// 		i++;
// 	}
// 	error = pthread_mutex_init(&(data->writing_lock), NULL);
// 	if (error != 0)
// 		print_error(3);
// }

// Above is the original one, that feel like was correct but then when i look deeper into the
// code i realize its too complex for me to understand, thus i came up with my own one.

// void	init_single_mutex(pthread_mutex_t *mutex)
// {
// 	if(pthread_mutex_init(mutex, NULL) != 0)
// 	{
// 		print_error(3);
// 	}
// }

// void	init_mutex(t_data *data)
// {
// 	int i;

// 	i = 0;
// 	while ( i < data->total_philo_num)
// 	{
// 		init_single_mutex(&(data->fork[i]));//initialise a mutex for each fork and passes a adress of the fork mutex for the i-th philo.
// 		i++;
// 	}
// 	init_single_mutex(&(data->writing_lock));// Creates a mutex, to prevent multiple threads from printing.
// }
  

// After some carefull considerations, i felt like i shoudl make a more better code than the one above
// thus the new init_mutex was born...
#include "../includes/philo.h"

typedef struct s_data{
		int philo_sum;
		pthread_mutex_t *fork;
		pthread_mutex_t writing_lock;
} t_data;

int setup_forks_mutex(t_data *data)
{
	int fork;
	int error;

	fork = 0;
	printf(ERR_00);

	while(fork < data->philo_sum)
	{
		printf(ERR_01, fork);
		error = pthread_mutex_init(&(data->fork[fork]), NULL);
		if (error != 0)
		{
			// printf(ERR_02, fork);
			// return (-1);
			return(printf(ERR_02, fork), -1);
		}
		else
		{
			printf(ERR_03);
		}
		fork++;
	}
	printf(ERR_04);
	error = pthread_mutex_init(&(data->writing_lock), NULL);
	if (error != 0)
	{
		// printf(ERR_05, fork);
		// return (-1);
		return(printf(ERR_05, fork), -1);
	}
	else
	{
		printf(ERR_06, fork);
	}
	
	// printf(ERR_07);
	// return (0);
	return(printf(ERR_07, fork), -1);
}



int main()
{
    t_data data;

    int test_cases[] = {0, 1, 5, 50, 70, 100, 1000};
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    
    int i = 0;
    while (i < num_cases)
    {
        printf("\n=== Running Test Case: philo_sum = %d ===\n", test_cases[i]);
        data.philo_sum = test_cases[i];

        // Allocate memory for forks only if philo_sum > 0
        if (data.philo_sum > 0)
        {
            data.fork = malloc(sizeof(pthread_mutex_t) * data.philo_sum);
            if (!data.fork)
            {
                printf("Memory allocation failed for %d philosophers\n", data.philo_sum);
                return (1);
            }
        }
        else
        {
            data.fork = NULL; // No forks needed when philo_sum = 0
        }

        setup_forks_mutex(&data);

        // Free allocated memory
        if (data.fork)
            free(data.fork);

        i++; // Move to next test case
    }

    return (0);
}


Comit this -> Removed all the macros from this file because i have already 
				replaced it in the header file.
		   -> Removed the Explaination at the top of the mutex_function
		      about the race condition and placed it in the readme.txt. file/
		   -> Removed the explanation to what is mutex on the top of the funtion
		   	  and replaced it in the readme.txt file.