

//  [Analogy for the Race-Condition:]

//  🏎️ The Fast Food Drive-Thru Analogy 🍔
//  Imagine you and your friend pull up to a fast food drive-thru that has two order windows,
//  but only one kitchen preparing the food.
 
//  1)Scenario 1: No Race Condition (Synchronized Orders) ✅

//  ~You pull up first, place your order for a double cheeseburger 🍔,
//   and the cashier confirms it before moving on.
//   Your friend pulls up next and orders a chicken sandwich 🍗.
//   The kitchen receives both orders in the correct order and prepares them properly.
//   You get your cheeseburger, your friend gets their chicken sandwich. All good!


//  2)Scenario 2: Race Condition (Chaos in the Kitchen) ❌

//  ~You and your friend accidentally talk at the same time into the speaker.
//   The cashier only hears:
//   You: "Double..."
//   Friend: "...sandwich"
//   The kitchen receives an incomplete/confused order and prepares a random meal.
//   The food comes out wrong—you get a chicken cheeseburger you never ordered! 😤

// ~ init_mutexes is a function that initialises the mutex lock,
//   (which are used to prevent the race conditions.)
// ~ It loops through all the forks and initialises one mutex for each philos.
// ~ It also initialises a writing_lock mutex, which is most likely used to 
//   control the output printing (thus multiple threads dont print at the same
//   time and mess up the output).

// void 	init_mutexes(t_data *data)
// {
// 	int i; //loop counter to initialise multiple forks.
// 	int error; //stores return values which tells us succsess or failure.

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
  


// What is a mutex??

// Final Analogy:Mutex = A lock on a bathroom door....

// ~ Imagine multiple people(threads in this case) wants to use a shared bathroom(fork).
// ~ We put a lock on the door(mutex) so only one person can acsess the bathroom at a time.
// ~ If we forget to add a lock, then multiple people can try and acsess the bathroom
// 	at the same time, which may cause chaos(race condition).
// ~ The writing lock ensures that only one person can write on the board(print on the screen)
// 	at a time.


// After some carefull considerations, i felt like i shoudl make a more better code than the one above
// thus the new init_mutex was born...
#include "../includes/philo.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define ERR_00 "Starting mutex initialisation"
#define ERR_01 "Initialising the mutex for the fork %d."
#define ERR_02 "FAILURE:Fork also cannot initialise, HAIYA!!!."
#define ERR_03
#define ERR_04
#define ERR_05

typedef struct s_data{
		int sum_philo;
		pthread_mutex_t *fork;
		pthread_mutex_t writing_lock;
} t_data;

int setup_forks_mutex(t_data *data)
{
	int fork;
	int error;

	fork = 0;
	printf("Starting mutex initialisation\n");

	while(fork < data->sum_philo)
	{
		printf("Initialising the mutex for the fork %d. \n", fork);
		error = pthread_mutex_init(&(data->fork[fork]), NULL);
		if (error != 0)
		{
			printf("FAILURE:Fork also cannot initialise, HAIYA!!!.\n", fork);
			return (-1);
		}
		else
		{
			printf("The forks ahh is connected ahh successfullyy!!\n");
		}
		fork++;
	}
	printf(" Initialising the writing lock ahh! \n");
	error = pthread_mutex_init(&(data->writing_lock), NULL);
	if (error != 0)
	{
		printf("FAILURE: Writing lock also cannot initialise. GG!!!.\n", fork);
		return (-1);
	}
	else
	{
		printf("The writing locks ahh is connected ahh successfully!!\n", fork);
	}
	
	printf("All mutexes are initialised smoothly!\n");
	return (0);
}



int main()
{
    t_data data;

    int test_cases[] = {0, 1, 5, 50, 70, 100, 1000};
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    
    int i = 0;
    while (i < num_cases)
    {
        printf("\n=== Running Test Case: sum_philo = %d ===\n", test_cases[i]);
        data.sum_philo = test_cases[i];

        // Allocate memory for forks only if sum_philo > 0
        if (data.sum_philo > 0)
        {
            data.fork = malloc(sizeof(pthread_mutex_t) * data.sum_philo);
            if (!data.fork)
            {
                printf("Memory allocation failed for %d philosophers\n", data.sum_philo);
                return (1);
            }
        }
        else
        {
            data.fork = NULL; // No forks needed when sum_philo = 0
        }

        setup_forks_mutex(&data);

        // Free allocated memory
        if (data.fork)
            free(data.fork);

        i++; // Move to next test case
    }

    return (0);
}