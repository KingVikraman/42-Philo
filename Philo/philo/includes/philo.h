#ifndef PHILO_H
# define PHILO_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

#define	STD_ERR_VALID	"Invalid number of arguments! Usage: ./philo number_of_philos time_to_die time_to_eat time_to_sleep [must_eat]"
#define STD_ERR_NUMBERS	 "Arguments must be positive numbers!"
#define STD_ERR_LIMITS	 "One or more arguments are out of range!"
#define	STD_ERR_START	"All arguments are valid! Starting the simulation..."



// Example of a struct:

// struct def_types {
// 	char name[50];
// 	int age;
// 	float gpa;
// };
#endif

/* okay, let me state the task that philosophers project demands.
So what its about is that, there are five philosophers and one so called
pool of data and what we are tasked to do is that to create a program
to ensure that all the philosophers can eat for the pool of data
in sync  with their forks and without coming to a situation where one philo starves to death.
. Each philo requres two forks to eat.So what are the possible edge casses that we could face,
 One, we call it the deadlock, okay what does a deadlock do, deadlock is when  there is one fork
assigned to each philo, in this case lets say there is 3 philos in a table
with one pool of data, now each philo has been assigned to their concurrent forks
once that is done, and when the process starts each philo will be taking the 
first fork assigned to them, for example:philo one will be assinged fork one, 
thus now all the three philo takes one fork each that are assinged to them, 
but the claus here is that each philo needs at least two forks ot eat, but each
philo only got one now. So now each philo is wating for thier second fork.
Thus this is called a deadlock where no philos can eat not do anything. 

Thus what is the cause of this problem, well if my understading is rigth, in the mid of a 
flight going to india, haha. the cause of this could be becasuse of the usage of mutex
why use the mutex is due to te race condition that i will metion it later, thats actually 
the secodn problem, but anyways the mutex works in a very particular way where, it prevents
two philos from accsessing one fork at the same time, thus the mutex works like a key where
when one philo is holding the fork another cannot take it from them nor snatch.

OKay that is the first case,lets now look at the second case, The second case is called 
the Race condition, 









Lone Philo routine*/