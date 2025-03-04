#include <stdio.h>
#include <limits.h>

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

void test_atoi(char *str)
{
    int result = atoi(str);
    printf("Input: \"%s\" → Output: %d\n", str, result);
}

int main()
{
    printf("Testing atoi function:\n\n");

    // Valid numbers
    test_atoi("123");
    test_atoi("0");
    test_atoi("42");

    // Edge cases (INT_MAX and overflow)
    test_atoi("2147483647");  // Max INT (should return 2147483647)
    test_atoi("2147483648");  // Overflow (should return -1)
    test_atoi("9999999999");  // Extreme overflow

    // Leading zeros
    test_atoi("000123");  

    // Whitespace handling
    test_atoi("   42");  
    test_atoi("42   ");  
    test_atoi("   0042  ");  

    // Invalid cases
    test_atoi("-123");   // No support for negatives
    test_atoi("12a34");  // Mixed characters
    test_atoi("abc");    // Pure non-numeric
    test_atoi("");       // Empty string

    return 0;
}