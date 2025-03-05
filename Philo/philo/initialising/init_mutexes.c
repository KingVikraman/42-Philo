//  [Analogy for the Race-Condition:]

//  🏎️ The Fast Food Drive-Thru Analogy 🍔
//  Imagine you and your friend pull up to a fast food drive-thru that has two order windows,
//  but only one kitchen preparing the food.
 
//  1)Scenario 1: No Race Condition (Synchronized Orders) ✅

//  ~You pull up first, place your order for a double cheeseburger 🍔,
//   and the cashier confirms it before moving on.
//   Your friend pulls up next and orders a chicken sandwich 🍗.
//   The kitchen receives both orders in the correct order and prepares them properly.
//   You get your cheeseburger, your friend gets their chicken sandwich. All good!


//  2)Scenario 2: Race Condition (Chaos in the Kitchen) ❌

//  ~You and your friend accidentally talk at the same time into the speaker.
//   The cashier only hears:
//   You: "Double..."
//   Friend: "...sandwich"
//   The kitchen receives an incomplete/confused order and prepares a random meal.
//   The food comes out wrong—you get a chicken cheeseburger you never ordered! 😤

// ~ init_mutexes is a function that initialises the mutex lock,
//   (which are used to prevent the race conditions.)
// ~ It loops through all the forks and initialises one mutex for each philos.
// ~ It also initialises a writing_lock mutex, which is most likely used to 
//   control the output printing (thus multiple threads dont print at the same
//   time and mess up the output).

void 	init_mutexes(t_data *data)
{
	int i; //loop counter to initialise multiple forks.
	int error; //stores return values which tells us succsess or failure.

	i = 0;
	while (i < data->total_philo_num) // a loop that runs once for each philo.
	{

	}
}
  


