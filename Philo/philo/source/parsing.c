#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_PHILOS 200
#define INT_MAX 250
/*Static functions, 

what are they and what are they
and what are they usefull for? Static functions are 
like a function that you can have within a module of
other fucntions because, static means that if the value of a
certain variable is passed throught the static function
is changed wnat happens is that, the value only stays withhin
the module, and it cannot be called by other functions from 
diffrent module. Secondly, they are usefull when, one funtion within 
a module need tp check the status of the variable, or like a checker
function this could really come in handy if you wish not to have a 
whole library in your framework.



~Module is like a group of functions put into a .c file.

bool,

Bool is a boolen  data type where it can hold only two values
like True & False. Its usually used to represent conditions like 
weather or not, something is valid.
*/

static bool	ft_isdigit(char	*str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}
/* Well this a pretty simple function, it just helps you to 
checks if the string contains only digits, if digits then
it returns true. else return false.*/

int atoi(char *str)
{
	int i;
	unsigned long nb;

	nb = 0;
	i = 0;
	while (str[i] >=  '0' && str[i] <= '9')
	{
		nb = nb * 10;
		nb = nb + (str[i] - '0');
		i++;
	}
	if (nb > INT_MAX)
		return (-1);
	return ((int)nb);
}

// Well as for this, function atoi, its not the same as my libft one,
// cause in my libft i was tasked to check for white space check for 
// negative number and all that stuff, more over my atoi was not a 
// self working function, but it also called another fucntion which
// is ft_isdigit. Thus this time around i have tried making a more simpified
// and smaller atoi, function which as for now only check for positive numebers,
// INT_MAX,edge cases like zero, large overflow, contains non-numeric
// digits, non-numeric inputs, but it does not handle for whitespace.
// in exchange it only returns zero,.. 



bool	is_valid_check(int argc, char **argv)
{
	int i;
	int nb;

	i = 1;
	while (i < argc)
	{
		if (!ft_isdigit(argv[i]))
			return (printf("Not a number : %s\n", argv[i]), false);
		nb =  atoi(argv[i]);
		if (i == 1 && (nb <= 0 || nb > MAX_PHILOS))
			return (printf("Number too big or too small: %d\n", nb), false);
		if (i != 1 && nb == -1)
			return (printf("Number is a negative value: %d\n", nb), false);
		i++;
	}
	return (true);
}


// int main(int argc, char **argv)
// {
    
// 	char input[20];

// 	printf("Enter a number: ");
// 	scanf("%19s", input);

// 	// Check if at least one argument is provided
//     if (!ft_isdigit(input))
//     {
//         printf("Usage: ./program <numbers>\n");
//         return (1);
//     }

//     // Call the validation function
//     if (!is_valid_check(argc, argv))
//     {
//         printf("Invalid input. Please provide valid numbers.\n");
//         return (1);
//     }

//     printf("All inputs are valid numbers!\n");
//     return (0);
// }

// #include <stdbool.h>
// #include <stdlib.h>
// #include <stdio.h>

// #define MAX_PHILOS 200
// #define INT_MAX 250
// /*Static functions, 

// what are they and what are they
// and what are they usefull for? Static functions are 
// like a function that you can have within a module of
// other fucntions because, static means that if the value of a
// certain variable is passed throught the static function
// is changed wnat happens is that, the value only stays withhin
// the module, and it cannot be called by other functions from 
// diffrent module. Secondly, they are usefull when, one funtion within 
// a module need tp check the status of the variable, or like a checker
// function this could really come in handy if you wish not to have a 
// whole library in your framework.



// ~Module is like a group of functions put into a .c file.

// bool,

// Bool is a boolen  data type where it can hold only two values
// like True & False. Its usually used to represent conditions like 
// weather or not, something is valid.
// */

// static bool	ft_isdigit(char	*str)
// {
// 	int i;

// 	i = 0;
// 	while(str[i])
// 	{
// 		if (str[i] < '0' || str[i] > '9')
// 			return (false);
// 		i++;
// 	}
// 	return (true);
// }
// /* Well this a pretty simple function, it just helps you to 
// checks if the string contains only digits, if digits then
// it returns true. else return false.*/

// int atoi(char *str)
// {
// 	int i;
// 	unsigned long nb;

// 	nb = 0;
// 	i = 0;
// 	while (str[i] >=  '0' && str[i] <= '9')
// 	{
// 		nb = nb * 10;
// 		nb = nb + (str[i] - '0');
// 		i++;
// 	}
// 	if (nb > INT_MAX)
// 		return (-1);
// 	return ((int)nb);
// }

// // Well as for this, function atoi, its not the same as my libft one,
// // cause in my libft i was tasked to check for white space check for 
// // negative number and all that stuff, more over my atoi was not a 
// // self working function, but it also called another fucntion which
// // is ft_isdigit. Thus this time around i have tried making a more simpified
// // and smaller atoi, function which as for now only check for positive numebers,
// // INT_MAX,edge cases like zero, large overflow, contains non-numeric
// // digits, non-numeric inputs, but it does not handle for whitespace.
// // in exchange it only returns zero,.. 



// bool	is_valid_check(int argc, char **argv)
// {
// 	int i;
// 	int nb;

// 	i = 1;
// 	while (i < argc)
// 	{
// 		if (!ft_isdigit(argv[i]))
// 			return (printf("Not a number : %s\n", argv[i]), false);
// 		nb =  atoi(argv[i]);
// 		if (i == 1 && (nb <= 0 || nb > MAX_PHILOS))
// 			return (printf("Number too big or too small: %d\n", nb), false);
// 		if (i != 1 && nb == -1)
// 			return (printf("Number is a negative value: %d\n", nb), false);
// 		i++;
// 	}
// 	return (true);
// }


// int main(int argc, char **argv)
// {
    
// 	char input[20];

// 	printf("Enter a number: ");
// 	scanf("%19s", input);

// 	// Check if at least one argument is provided
//     if (!ft_isdigit(input))
//     {
//         printf("Usage: ./program <numbers>\n");
//         return (1);
//     }

//     // Call the validation function
//     if (!is_valid_check(argc, argv))
//     {
//         printf("Invalid input. Please provide valid numbers.\n");
//         return (1);
//     }

//     printf("All inputs are valid numbers!\n");
//     return (0);
// }
