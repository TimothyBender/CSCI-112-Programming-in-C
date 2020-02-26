/*
 * Timothy Bender
 * Lab 2 
 * 1/27/2020
 * CSCI 112 Programming in C
 */

#include <stdio.h>
#include <math.h>

//function declatations
void calcTotal(char teacher, double totalPurchase);
void printToFile(double totalPurchase, double discountedT, double tDisc, double salesTax, 
		double total, char teacher);
int main(void){
	
	double totalPurchase;     		 //declare local variables
	char teacher;
	
	printf("Enter the cost of your items: ");  	 //iet the total Purchase as a double
	scanf("%lf",&totalPurchase);

	printf("Are you a music teacher? (y or n): ");	//Ask whether or not they are a teacher and store as a char
	scanf(" %c",&teacher);

	calcTotal(teacher,totalPurchase);	//the function calcTotal will perform most of the calculations 

	return(0);
}

void calcTotal(char teacher, double totalPurchase){ //this method will do most of the calculations 
	double discountedT, tDisc, salesTax,total; 

	if(teacher == 'y' || teacher == 'Y'){ //if they are a teacher and the purchase is over 100, apply a 12% discount
		if(totalPurchase >= 100){
			tDisc = .12;
		}
		else{			      //a 10% discount if they are a teacher, but the total is below 100
			tDisc = .1;
		}
	}
	else{
		tDisc = 0;
	}

	discountedT = totalPurchase - (totalPurchase * tDisc);			//some calculations 
	salesTax = roundf((discountedT * .05)*100)/100;				//uses the roundf feature from math.h 
	total = discountedT + salesTax; 
	printToFile(totalPurchase,discountedT,tDisc,salesTax,total,teacher);	//finally we call a print function, and pass it all the values. 
	
}

void printToFile(double totalPurchase,double discountedT, double tDisc, 
	double salesTax, double total, char teacher){
	FILE *c = fopen("receipt.txt","w");	//Open a writable txt file 
	switch(teacher){			//Switch that allows us two different print methods for teachers and normal customers 
		case 'Y':
		case 'y':
			fprintf(c,"Total purchases\t\t\t$%.2lf\nTeacher's Discount (%.0lf%%)\t  %.2lf\n"
			"Discounted Total\t\t %.2lf"
                   	"\nSales Tax (5%%)\t\t\t  %.2lf\nTotal\t\t\t\t$%.2lf",		//a mess of formating
                   	totalPurchase,(tDisc*100),(tDisc*totalPurchase),discountedT,salesTax,total);
			break;
		default:
			fprintf(c,"Total purchases\t\t\t$%.2lf"				//another mess of formating 
                      	"\nSales Tax (5%%)\t\t\t  %.2lf\nTotal\t\t\t\t$%.2lf",
			totalPurchase,salesTax,total);
            		break;
	}
	fclose(c);  //close the file. 	
}

