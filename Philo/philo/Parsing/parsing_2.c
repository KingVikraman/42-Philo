#include "../includes/philo.h"



static bool	ft_isdigit(char	*str)
{
	int i = 0;

	if (!str[i])
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
 


int is_valid_check(t_data *data ,char **argv)
{
    int i = 0;
    int nb;
   
    data->meals_sum = 0;
	while (argv[++i])
    {
        if (!ft_isdigit(argv[i]))
            return (printf("Not a number: %s\n", argv[i]));

        nb = ft_atoi(argv[i]);

        if (i == 1 && (nb <= 0 || nb > MAX_PHILOS))
            return (printf("Invalid number of philos: %d\n", nb));
			 printf("%d\n", nb);
	        if (i != 1 && nb == -1)
            return (printf("Number is a negative value or overflowed: %d\n", nb));

        //Stores the converted values inside the struct
        if (i == 1) data->philo_sum = nb;
        if (i == 2) data->death_time = nb;
        if (i == 3) data->feasting_time = nb;
        if (i == 4) data->sleeping_time = nb;
        if (i == 5) data->meals_sum = nb; // Garbage value if optional meal cout not given
		//-----------data->args.meals_sum =nb;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_data *data;
	
	if (argc != 5 && argc != 6)
		return(printf("%s", VALIDITY_ERROR), 1);
	if (!is_valid_check(data ,argv))
		return (1);
	printf("OK\n");
}

bool is_valid_check(char **argv)
{
	int i = 0;
	int nb;

 	while (argv[++i])
	{
		if (!ft_isdigit(argv[i]))
			return (printf("Not a number: %s\n", argv[i]), false);

		//printf("input>> %s\n", argv[i]);
		nb = ft_atoi(argv[i]);
		//printf("output>> %d\n", nb);

		if (i == 1 && (nb <= 0 || nb > MAX_PHILOS))
			return (printf("Invalid number of philos: %d\n", nb), false);

		if (i != 1 && nb == -1)
			return (printf("Number is a negative value or overflowed: %d\n", nb), false);

	}
	return true;
}

// int main(int argc, char **argv)
// {
//      t_data *data;

// 	if (argc != 5 && argc != 6)
// 		return(printf("%s", VALIDITY_ERROR), 1);
// 	if (!is_valid_check(data, argv))
// 		return (1);
// 	printf("OK\n");
// }