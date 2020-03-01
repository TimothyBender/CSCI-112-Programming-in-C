
#include <stdio.h>

 /*
 *Timothy Bender
 *Lab 4 CSC
 */
int get_corners(double x[], double y[]){
	int i = 0;	
	//read in our file and count the number of points;
	while(!feof(stdin)){
		scanf("%lf %lf",&x[i],&y[i]);
		i++;
	}
	return ++i;
}


void output_corners(double x[], double y[], int n, double area){
	//print the table of values of x and y
	printf(" x        y\n");
	printf(" -        -\n");
	for(int t = 0; t < n; t++){
		printf("%.2lf \t %.2lf\n",x[t],y[t]);
	}
	//print the area
	printf("area of this polygon is: %.2lf\n",area);
	
}
double polygon_area(double x[], double y[], int n){
	double area;
	//compute the area
	for(int i = 0;i < n-2; i++){
		area += (x[i+1] + x[i])*(y[i+1]-y[i]);
	}
	//half it and flip it to be positive according to the formula 
	area = area * .5;
	
	//little check to take the absolute value if the sum is negative. 
	if(area < 0.0){
		area *= -1;
	}
	return area;
}
int main(int ac, char **av){
	//declare the integer arrays we will use to hold the points, and the area double;
	double x[20],y[20],area;
	//read in the file and get the number of coords
	int num_coords = get_corners(x,y);
	//pass the points and the number of coordinates into the polygon_area function
	area = polygon_area(x,y,num_coords);
	//sent everything to be printed
	output_corners(x,y,num_coords,area);
	return(0);
}
