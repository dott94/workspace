#include "my.h"

/*
 * Precondition: The string containing a number in string format
 * Postcondition: The integer version of the string is returned

 */
int my_atoi(char* string)
{
	int neg;
	int i;
	if(string != NULL)
	{
        while(*string == ' ')
        {
            string++;
        }
		neg = 1;
		i = 0;
        for( ; *string && *string != ' ' && (*string == '+' || *string == '-' || (*string <= '9' && *string >= '0')); string++)
		{
			if(*string == '-')
			{
				neg *= -1;
			}
            else if(*string <= '9' && *string >= '0')
			{
				i = (i * 10) + (*string - '0');
			}
		}
		return i * neg;
	}
	return 0;
}