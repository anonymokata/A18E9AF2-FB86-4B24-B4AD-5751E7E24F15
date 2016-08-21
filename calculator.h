#ifndef calculator_H
#define calculator_H
char * calculate(char roman_number1[50],char roman_number2[50], int option);
int romanValue(char c);
int roman_decimal(char number[]);
void predigits(char character1,char character2);
void postdigits(char character,int count);
char * decimal_roman(int total);

#endif
