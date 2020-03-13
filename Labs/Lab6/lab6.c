/*
 * Timothy Bender
 * CSCI 112 Programming in C
 * Lab 6
 * 3/12/2020
 */

#include <stdio.h>
#include <string.h>


//method declarations. 
void readFile();
void encode(char input[]);
void printInput(char input[200]);
void appendToFile(char input[200]);
int  getPos(char i);

int main(void){
	fclose(fopen("output.txt","w")); //wipe the contents of the current output file
	readFile(); //call readfile
	return(0);
}

void readFile(){
	char c[200]; //holds the input from file
	FILE *fptr;
	//catch file not found errors
	if((fptr = fopen("/public/examples/lab6/tinyTale.txt", "r")) == NULL){
		printf("Error, file not found");
		return;
	}
	while(fgets(c,200,fptr)){ //read the file in line by line, for each file append it to the file, and call encode.
		printf("%s",c);
		appendToFile(c);
		encode(c);
	}
	fclose(fptr); //close the file

}

//this method will convert the string using the key. then append it to the file. 
void encode(char input[]){
	char key[27] = "efghijklmnopqrstuvwxyzabcd";
	char output[201];
	int x = 0;
	while(input[x] != '\0'){ //iterate through the string, and check every character	       
		if(input[x] == ' ' || input[x] == '\n'){
			output[x] = input[x];   //if the character is a space or a new line then
		}				//place it into the new array without conversion
		else{	
			output[x] = key[getPos(input[x])]; //otherwise convert it.
		}
		x++;
	}

	printf("%s",output); 
	appendToFile(output); //append the encoded string to the file
	return;
}

void appendToFile(char input[]){
	FILE *fptr = fopen("output.txt","a"); //FILE pointer to our output file. 
	if(fptr == NULL){
		return;
	}
	fputs(input,fptr);  //append in the string
	fclose(fptr); 
	return;
}

//this method will return the characters number in the alphabet 
int getPos(char i){
	char alphabet[27] = "abcdefghijklmnopqrstuvwxyz"; 
	for(int x = 0; x < 27; x++){ //iterate through until you find it, then return its position
		if(i == alphabet[x]){
			return x;
		}
	}     //if its not in the alphabet return 0;
	return 0;
}










