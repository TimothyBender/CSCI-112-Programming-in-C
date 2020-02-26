#include <stdio.h>
#include <math.h>
#include <stdlib.h>    
#include <time.h>     //apparently this was required for the random generator

/*
 * Timothy Bender 
 * CSCI 112 Lab 3
 * Feb 13, 2020
 */



double getAverage(double,double);      //declare our function prototypes for 
double getSD(double,double,double);   //calculating the average and standardDeviation

int main(void){

	int N = 0,limit = 0,smallest,largest,sum = 0;        //declare all the variables we will need. N is the size of the array. Others are obvious
        double average = 0.0,standardDev = 0,sumSquares = 0; //declare the doubles we will need

	printf("Enter number of random integers to generate: ");   //get user input
	scanf("%d",&N);
	printf("Enter the upper limit of numbers to generate: ");
	scanf("%d",&limit);
	printf("\n");
	srand(time(NULL));
	int array[N];                   //create the array of size N

       	for(int i = 0; i < N;i++){             //loop through the array and fill it with randomly generated numbers
		int toInsert = (rand()%(limit + 1)); // generate random numbers between 0 and the users limit
		array[i] = toInsert;          
		}

	smallest = array[0];                  //give smallest and largest some starting values. 
	largest = array[0];                   //cannot use zero for smallest's default or it wont work 

	for(int x = 0; x < N;x++){            
		if(array[x] < smallest){
		smallest = array[x];
		}
		if(array[x] > largest){      //loop through the array and check if we have a new smallest
		largest = array[x];         ///or a new largest
		}
		sum += array[x];            //while we go through add up the total of the array
		sumSquares += pow((double)array[x],2.0); //also add up the squares of the array's items. We use the math libraries pow function 
	}
	average = getAverage((double)sum,(double)N);    //call getAverage and assign the result to the double average
	standardDev = getSD((double)N,(double)sumSquares,average);   //call getSD to get the standardDeviation and assign it
								     // the double standardDEv
				
	//print everything in the correct format. Double's cut to 2 decimal places. 
	printf("With %d numbers from 1 to %d, generated randomly:\n",N,limit);  
	printf("Smallest: %d, Largest: %d, Average: %.2lf, Std Deviation: %.2lf \n",smallest,largest,average,standardDev);	
	
}

double getAverage(double average, double N){
	double ans = average/N;    //Here'sour average calculator. Pretty straight forward
	return(ans);	
}

double getSD(double N,double sumSquares,double average){
	double sd = sqrt((sumSquares/N)-pow(average,2.0));   //Heres the standard deveiation calculation
	return(sd); 					     //we use the math libraries' pow and sqrt functions 
}

