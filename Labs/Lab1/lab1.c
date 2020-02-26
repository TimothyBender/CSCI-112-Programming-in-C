#include <stdio.h>

/*Timothy Bender
 * Lab 1 
 * CSCI 112 - Programming in C
 * 1/17/2020
*/

int main(void){
	double hours,minutes,temperature;
       	/*Declare variables. Doubles were decided to be easiest*/

	printf("Enter time since power failure in hours and minutes: ");
       	/*Get the hours and minutes*/
	scanf("%lf %lf",&hours,&minutes);

	hours = hours + (minutes / 60); /*Determine the elapsed time*/
	 

	temperature = (4*(hours*hours))/(hours + 2) - 20; /*Perform the calculation*/

	printf("Temperature after power failure for %.2f hours is %.2fC\n",hours,temperature);
       	/*Print result, the double will be cut off at 2 decimal places*/
	return(0);
}
