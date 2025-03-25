long long int	gettime(void)
{
	struct timeval	time; // struct to store time in seconds and milisecods.
	long long int	milisec_time; //Variable stores time in milisecods

	gettimeofday(&time,NULL);// gets the current time of the day.
	milisec_time = time.tv_sec * 1000 + time.tv_usec / 1000; // converts current time to miliseconds
	return (milisec_time); // Returns time in miliseconds.
}

// struct timeval{
// 	time_t		tv_sec; // Seconds since 1970,
// 	suseconds	tv_usec; //(Microseconds, 1,000,000, microseconds = 1 second)
// };

// time.tv_sec -> Holds for seconds.
// time.tv_sec -> Holds for miliseconds.

// gettimeofday(&time, NULL);
// ->system call retrieves the current time and stores it in time.
//   The NULL argument is usually used for time zone info.[Lowkey i think NULL might not be nessasary].

// milisec_time = time.tv_sec * 1000 + time.tv_usec / 1000;
// ->time.tv_sec * 1000 converts seconds to milliseconds.
// ->time.tv_usec / 1000 converts microseconds to milliseconds (since 1,000,000 µs = 1 sec).

// TL;DR
// 👉 This function returns the current time in milliseconds since January 1, 1970.
// 👉 It uses gettimeofday() to get seconds and microseconds, then converts it to milliseconds.
// 👉 Useful for measuring execution time, logging, and performance monitoring.