void	timer(long long int time)
{
	long long int	current; // usage of microseconds.

	current = gettime();
	while (1)
	{
		if (gettime() - current >= time)
			return ;
		usleep(200);
	}
}

// This function, acts like a pause, to find the amount of time the philo sould wait
// before he continues the simulation.

// It uses long long int time due to the reason of having values in microseconds.
// Then what it does is that, the function calls gettime then assigns the retrun 
// value from gettime to current, which is in miliseconds.
// Then there is a while loop where it runs forever(the "1" measn run forever)
// what that does is that it calls gettime again to get the updated time, which 
// possibly could be a one miliseocd diffrence, then it minusus it with the current 
// int to see if its more than equal to the time(The time you put  int the terminal)
// then if the condition is true it returns and exits the loop but if its not 
// more than equal to then it would keep looping. 