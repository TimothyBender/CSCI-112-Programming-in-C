#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Timothy Bender
 *CSCI 112
 *Test 3 Program 3
 */

void readnumbers(double numbers[]);
int main(void){
	double numbers[5];
	readnumbers(numbers);
	FILE* bfile = fopen("out.bin","wb");
	fwrite(numbers,sizeof(numbers),5,bfile);
	fclose(bfile);
}

void readnumbers(double numbers[]){

	char c[6];
	FILE *fptr;
	int counter = 0;
	double sum = 0;
	if((fptr = fopen("/public/test3/doubles.txt","r"))==NULL){
		printf("Error cannot find file");
	}
	while(fgets(c,6,fptr)){
		numbers[counter] = strtod(c,'\0');
		sum += numbers[counter];
		counter++;
	}
	printf("%.3lf\n",sum);
	fclose(fptr);

}
