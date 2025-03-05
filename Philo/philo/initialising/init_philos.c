~init_philos is technically a function that initailizes the philospphers struct 
 with their ID, Fork assingments, and traking variables. Each philo must have a 
 unique ID assinged ot them.
~Each philo gets:
	-ID:their philosophers number.
	-Left_fork_id:Same as their ID.
	-right_fork_id:next philosophers for(handled with i + 1)% total_philo_num to 
	  wrap around).
	-last_ate:set to 0 initially.
	-num_of_meals:also 0 initially.
	-data: a pointer to the shared simulation data.

