long long int	gettime(void)
{
	struct timeval	time;
	long long int	milisec_time;

	gettimeofday(&time, NULL);
	milisec_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (milisec_time);
}

hello