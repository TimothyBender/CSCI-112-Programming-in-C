/*
 * Timothy Bender
 * CSCI 112
 * Lab 5
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

int compareColors(char colors[10][7], char color[]);
int main(void){
	char colors[10][7] = {"black", "brown", "red", "orange","yellow",
		"green","blue","violet","gray","white"}; //store our colors as a 2d char array

	int loop = 1; //controls the master do-while loop
	printf("Enter the colors of the resistor's three bands, beginning with\nband nearest the end. Type the colors in lowercase letters\nonly, NO CAPS.\n");//only print this once
	do{
		char color[7]; //string to store our inputs
		int val1,val2,total; //used for some calculations
		double mult; //the factor by which we will by multiplying

		printf("Band 1 => ");//get first input 
		scanf("%s",color);
		val1 = 10*compareColors(colors,color); //the first input is in the 10's place so.. multiply by 10
		
		//our compareColors function returns -1 if the inputed color is not in our colors array.
		//so only continue if its >= 0
		if(val1 >= 0){
			printf("Band 2 => "); // get the second input
			scanf("%s",color);
			val2 = compareColors(colors,color);
			//again check that it exists in our array of colors
			if(val2 >= 0){
				printf("Band 3 => ");  //get third input
				scanf("%s",color);
				mult = pow(10,compareColors(colors,color));

				if(mult > 0){  
					//perform all the calculations
			 		double ohms;
					total = val1+val2; 
					ohms = total * mult;
		
					if(ohms >= 1000){ // if the ohms are above 1000 we can divide and print as kilo-ohms
						ohms /= 1000;
						printf("Resistance value: %.1lf kilo-ohms\n",ohms);
					}
					else{ // else print as normal
						printf("Resistance value: %.0lf ohms\n",ohms);
					}
						
				}
				//all these else statements will let you know if your color was invalid
				else{
					printf("Invalid color: %s\n",color);
				}
			}
			else{
				printf("Invalid color: %s\n",color);
			}
		}
		else{
			printf("Invalid color: %s\n",color);
		}
		int exit = 0;
		//another do-while to get input
		do{
			char reply = ' ';
			printf("Do you want to decode another resistor?\n => ");
			scanf(" %c",&reply);
			if(reply == 'y' || reply == 'Y'){
				exit = 1;
			}
			else if(reply == 'n' || reply == 'N'){
				exit = 1;
				loop = 0;
			}	
			else{
				printf("Bad answer, try again\n");
			}
		}
		while(exit == 0);
	}
	while(loop == 1);
	return(0);
}

int compareColors(char colors[10][7],char color[]){
	//finds the string color inside of colors and returns its position. 
	for(int i = 0; i < 10; i++){
		if(strcmp(color,colors[i]) == 0){ //compares the strings using strcmp. They must be exact matches to return i;
			return i;
		}
	}
	return -1; //returns -1 as an error
}
