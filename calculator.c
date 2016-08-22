/* 
Roman calculator: performs addition and subtraction of roman values
Author: Vinay vittal Karagod
File dependents: main.c, calculator.h, calculator.c,calculator-test.check
Date: 08/21/2016
calculator.c: function file which receives values from calculator-test.check. 
	      This will returns the output of the program
*/
# include "calculator.h"
# include <check.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>

int roman_index = 0; // index to hold the position of the roman digits 
char roman_num[50]; // to hold the digits of the roman digits

// Function to recieve the inputs
char * calculate(char roman_number1[50],char roman_number2[50], int option)
{

	int first_number, second_number; // to store roman values
	int sum = 0, sub = 0;// initilizing the addition and subtraction value
	first_number = roman_decimal(roman_number1); // calling roman_decimal function to convert first roman number to decimal
	second_number = roman_decimal(roman_number2); // calling roman_decimal function to convert second roman number to decimal
	char * answer; // to store the final result

//switch case for addition or subtractio operation	
		switch(option)
	        {
	        case 1:
	        	sum =  first_number+ second_number;
	        	if(sum > 3999)
	        	{
	        	 	printf("Number exceeds the maximum limit \n");
	        	 	exit(0);
	        	}
	        	else
				answer = decimal_roman(sum);
	        	   	break;
	        case 2:
			if(first_number >= second_number)
	        		sub = first_number - second_number;
			else
				sub = second_number - first_number;

	        	if(sub > 3999)
	        	  {
	        	  	 printf("Number exceeds the maximum limit \n");
	        	   	 exit(0);
	        	  }
			else				
                                answer = decimal_roman(sub); 
                                break;

	        default :
	        	printf("Invalid input \n");

	        }

return answer;
}


// to convert each roman number to decimal number
int romanValue(char r_Character)
{
	int value=0;
		switch(r_Character){
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

// function receives the roman string to convert into decimal number
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

void predigits(char character1,char character2)// storing the predigits for example: 40 has to be stored as XL 
{
	roman_num[roman_index++] = character1;
	roman_num[roman_index++] = character2;

}

void postdigits(char character,int count)
{
	    int loop;
	    for(loop=0;loop<count;loop++)
	    roman_num[roman_index++] = character;
}


//Function to convert back the decimal number to roman number
char * decimal_roman(int total)
{
		while(total !=0)
		{

	         	if(total >= 1000){ // converstion for 1000
	             	postdigits('M',total/1000);
	             	total = total - (total/1000) * 1000;
	         	}
	         	else if(total >=500){ // conversion for 500
	             	if(total < (500 + 4 * 100)){
	                 	postdigits('D',total/500);
	                 	total = total - (total/500) * 500;
	             		}
	             	else{
	                 	predigits('C','M');
	                 	total = total - (1000-100);
	             		}
	         	}
	         	else if(total >=100){ // conversion for 100
	             	if(total < (100 + 3 * 100)){
	                	postdigits('C',total/100);
	               		total = total - (total/100) * 100;
	             		}
	             	else{
	                 	predigits('L','D');
	                 	total = total - (500-100);
	             	    }
	         	}
	         	else if(total >=50){ // conversion for 50
	             		if(total < (50 + 4 * 10)){
	                 	postdigits('L',total/50);
	                 	total = total - (total/50) * 50;
	             	}
	             	else{
	                 	predigits('X','C');
	                 	total = total - (100-10);
	             	    }
	                }
	         	else if(total >=10){ //conversion for 10
	             		if(total < (10 + 3 * 10)){
	                 	postdigits('X',total/10);
	                 	total = total - (total/10) * 10;
	             		}
	             	else{
	                 	predigits('X','L');
	                 	total = total - (50-10);
	             		}
	         	     }
	         	else if(total >=5){ //conversion for 5
	             		if(total < (5 + 4 * 1)){
	                 	postdigits('V',total/5);
	                 	total = total - (total/5) * 5;
	             	     }
	             	else{
	                 	predigits('I','X');
	                 	total = total - (10-1);
	             	    }
	         	}
	         	else if(total >=1){ // conversion for 1
	             		if(total < 4)
				{
	                        postdigits('I',total/1);
	                 	total = total - (total/1) * 1;
	             		}
	             	else{
	                 	predigits('I','V');
	                 	total = total - (5-1);
	             	    }
	         	}
	    	}	
	
	roman_num[roman_index++] = '\0';
        roman_index = 0; // resetting the index
        return roman_num;
}
