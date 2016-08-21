# include "calculator.h"
# include <check.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>

int inputs(char roman_number1[50],char roman_number2[50], int option)
{
	
	
	int first_number, second_number; // to store roman values
	int sum = 0, sub = 0;// initilizing the addition and subtraction value
	first_number = roman_decimal(roman_number1); // calling roman_decimal function to convert first roman number to decimal
	second_number = roman_decimal(roman_number2); // calling roman_decimal function to convert second roman number to decimal
	
	switch(option)
	        {
	        case 1:
	        	sum =  first_number+ second_number;
	        	if(sum > 3999)
	        	{
	        	 	printf("Number exceeds the maximum limit");
	        	 	exit(0);
	        	}
	        	else
				return sum;
	        	   	break;
	        case 2:
			if(first_number >= second_number)
	        		sub = first_number - second_number;
			else
				sub = second_number - first_number;

	        	if(sub > 3999)
	        	  {
	        	  	 printf("Number exceeds the maximum limit");
	        	   	 exit(0);
	        	  }
			else				
                                return sub; 
                                break;

	        default :
	        	printf("Invalid input \n");

	        }

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

int roman_decimal(char number[])
{
	int index_value = 0;
	int decnum = 0; // value to store the dicimal value 

	while(number[index_value] == 'I' || number[index_value] == 'V' || number[index_value] == 'X' || number[index_value] == 'L'|| number[index_value] == 'C' || number[index_value] == 'D' || number[index_value] == 'M')
		{

		if(romanValue(number[index_value]) < 0) // condition to check the invalid numbers
			{
				printf("%d",romanValue(number[index_value]));
				printf("Invalid roman digit : %c",number[index_value]);
				exit(0);
			}
		
		if((strlen(number) - index_value) > 2)
			{
				if(romanValue(number[index_value]) < romanValue(number[index_value+2])){
				printf("Invalid roman number");
				exit(0);
			}
		}

		
		if(romanValue(number[index_value]) >= romanValue(number[index_value+1])) // reading each roman from the string
			decnum = decnum + romanValue(number[index_value]);
			else{
			decnum = decnum + (romanValue(number[index_value+1]) - romanValue(number[index_value]));
			index_value++;
			}
	index_value++;

}
return decnum;
}


