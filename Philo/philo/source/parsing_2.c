#include "../includes/philo.h"



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
		if (nb > INT_MAX)  // Handle overflow
			return -1;
		i++;
	}
	return (int)nb;
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

int main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return(printf("%s", STR_ERR_VALID), 1);
	if (!is_valid_check(argv))
		return (1);
	printf("OK\n");
}