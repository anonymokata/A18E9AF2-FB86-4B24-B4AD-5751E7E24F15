/* 
Roman calculator: performs addition and subtraction of roman values
Author: Vinay vittal Karagod
File dependents: main.c, calculator.h, calculator.c,calculator-test.check
Date: 08/21/2016
calculator.h: Header file where all the functions are refered
*/


#ifndef calculator_H
#define calculator_H
char * calculate(char roman_number1[50],char roman_number2[50], int option);
int romanValue(char c);
int roman_decimal(char number[]);
void predigits(char character1,char character2);
void postdigits(char character,int count);
char * decimal_roman(int total);

#endif
