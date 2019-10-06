/*
Trever Hibbs
Connor "lastname"
Steven Tomlinson
This program is meant to compute the maximum value that can be loaded into a 
knapsack with a maximum weight capacity of 1024, when given a list of no more
than 128 items with given numbers for value and weight. 
The program excepts a single command line arguement specifying the max 
weight capacity for the knapsack. Then once the program is exectuted it 
will print out the contentse of the file knapsack.data, the maximum possible
value, and how many of each item should be put in the bag. the program will
then exit.
*/

//#include"pa5.h"
#include "heading.h"
//struct item global[1024];

struct node item;

int main(int argc, char **argv){

	FILE*fptr = fopen("knapsack.data","r");
	int cap=0, getflag=0, retval=0, index=0;

	if(argc != 2){
		printf("Integer capacity of knapsack required.\n");
		return -1;
	}
	if(sscanf(argv[1], "%d", &cap)!=1){
		printf("Not a valid integer.\n");
		return -2;
	}
	if(cap > 1024){
		printf("Invalid capacity input should be between 0 and 1024.\n");
		return 0;
	}
	if(fptr == NULL){
		printf("File not found.\n");
		return -3;
	}
	printf("entering getData\n");
	getflag=getData(fptr);
	printf("leaving getData\n");
	if(getflag==0){
		printf("Error extracting data from file.\n");
		return -4;
	}

	fileprint();

	printf("maxval is %i\n", maxval(cap));

	return 0;
}


