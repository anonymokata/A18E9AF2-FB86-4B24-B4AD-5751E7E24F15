# include "calculator.h"
# include <check.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>

void inputs(char roman_number1[50])
{
	int first_number;
	
	first_number = romanValue(roman_number1); // calling roman_decimal function to convert first roman number to decimal
	return 0;
}

int romanValue(char c)
{
	int value=0;
		switch(c){
		case 'I': value = 1; 
		 	  break;
		case 'V': value = 5; 
			  break;
		case 'X': value = 10; 
			  break;
		case 'L': value = 50; 
			  break;
		case 'C': value = 100; 
			  break;
		case 'D': value = 500; 
			  break;
		case 'M': value = 1000; 
			  break;	
		case '\0': value = 0; 
			  break;
		default: value = -1;
		}

		return value;
}


