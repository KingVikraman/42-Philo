void	print_error(int n)
{
	write(2, "Error: ", 7);
	if (n == 1)
		write(2, "wrong philo usage", 17);
	if (n == 2)
		write(2, "at least one argument is invalid", 32);
	if (n == 3)
		write(2, "mutex init failed", 17);
	if (n == 4)
		write(2, "pthread creation failed", 24);
	write(2, "\n", 1);
	exit(1);
}
