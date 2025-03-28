#include "../includes/philo.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "pthread.h"


typedef struct s_args
{
    int philo_sum;
    int death_time;
    int feasting_time;
    int sleeping_time;
    int meals_sum;
} t_args;



static bool	ft_isdigit(char	*str)
{
	int i = 0;

	if (!str[i])  // Handle empty strings
		return false;

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return false;
		i++;
	}
	return true;
}

static int ft_atoi(char *str)
{
	int i = 0;
	unsigned long nb = 0;

	while (str[i] >= '0' && str[i] <= '9')
	{           10             '2' --> 2 = 12
		nb = nb * 10 + | (str[i] - '0'); 
		if (nb > INT_MAX)  // Handle overflow 
			return -1;
		i++;
	}
	return (int)nb;

	// nb = 0 * 10 + 0 = 0
	// nb = 0 + 0 = 0
	// nb = 0 *10 + ('9' - '0')

	// char a = '9' - '0'
}
 


bool is_valid_check(char **argv, t_args *args)
{
    int i = 0;
    int nb;
   
    while (argv[++i]) // philo 5 800 200 200 [optional]
    {
        if (!ft_isdigit(argv[i]))
            return (printf("Not a number: %s\n", argv[i]), false);

        nb = ft_atoi(argv[i]);

        if (i == 1 && (nb <= 0 || nb > MAX_PHILOS))
            return (printf("Invalid number of philos: %d\n", nb), false);

        if (i != 1 && nb == -1)
            return (printf("Number is a negative value or overflowed: %d\n", nb), false);

        //Stores the converted values inside the struct
        if (i == 1) args->philo_sum = nb;
        if (i == 2) args->death_time = nb;
        if (i == 3) args->feasting_time = nb;
        if (i == 4) args->sleeping_time = nb;
        if (i == 5) args->meals_sum = nb; // Garbage value if optional meal cout not given
		//-----------data->args.meals_sum =nb;
	}

    return true;
}

int main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return(printf("%s", STR_ERR_VALID), 1);
	if (!is_valid_check(argv))
		return (1);
	printf("OK\n");
}

// bool is_valid_check(char **argv)
// {
// 	int i = 0;
// 	int nb;

//  	while (argv[++i])
// 	{
// 		if (!ft_isdigit(argv[i]))
// 			return (printf("Not a number: %s\n", argv[i]), false);

// 		//printf("input>> %s\n", argv[i]);
// 		nb = ft_atoi(argv[i]);
// 		//printf("output>> %d\n", nb);

// 		if (i == 1 && (nb <= 0 || nb > MAX_PHILOS))
// 			return (printf("Invalid number of philos: %d\n", nb), false);

// 		if (i != 1 && nb == -1)
// 			return (printf("Number is a negative value or overflowed: %d\n", nb), false);

// 	}
// 	return true;
// }

// int main(int argc, char **argv)
// {
// 	if (argc != 5 && argc != 6)
// 		return(printf("%s", STR_ERR_VALID), 1);
// 	if (!is_valid_check(argv))
// 		return (1);
// 	printf("OK\n");
// }