

#include "../includes/philo.h"

typedef struct s_args
{
    int total_philo_num;
    int death_time;
    int eating_time;
    int sleeping_time;
    int total_meals;
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
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb > MAX_INT_LIMIT)  // Handle overflow 
			return -1;
		i++;
	}
	return (int)nb;
}

bool is_valid_check(char **argv, t_args *args)
{
    int i = 0;
    int nb;

    while (argv[++i])
    {
        if (!ft_isdigit(argv[i]))
            return (printf("Not a number: %s\n", argv[i]), false);

        nb = ft_atoi(argv[i]);

        if (i == 1 && (nb <= 0 || nb > MAX_PHILOS))
            return (printf("Invalid number of philos: %d\n", nb), false);

        if (i != 1 && nb == -1)
            return (printf("Number is a negative value or overflowed: %d\n", nb), false);

        //Stores the converted values inside the struct
        if (i == 1) args->total_philo_num = nb;
        if (i == 2) args->death_time = nb;
        if (i == 3) args->eating_time = nb;
        if (i == 4) args->sleeping_time = nb;
        if (i == 5) args->total_meals = nb;
    }

    return true;
}

int main(int argc, char **argv)
{
	t_args args;

	if (argc != 5 && argc != 6)
		return (printf("Error 404: Invalid arguments!\n"), 1);
	
	if (!is_valid_check(argv, &args))
		return (1);

	printf("🧵 Philosopher Simulation Settings:\n");
	printf("Total Philosophers: %d\n", args.total_philo_num);
	printf("Time to Die: %d ms\n", args.death_time);
	printf("Time to Eat: %d ms\n", args.eating_time);
	printf("Time to Sleep: %d ms\n", args.sleeping_time);
	if (argc == 6)
		printf("Total Meals: %d\n", args.total_meals);
	else
		printf("Total Meals: Unlimited\n");

	return (0);
}
