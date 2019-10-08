/*
	heading file for pa5 programs.
	contains initializing statement
	for structure
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char name[128][32];
	int value[128];
	int weight[128];
	int flag[128];
	int maxval[1024];
	int number_of_items;
};

extern struct node item;

int getData(FILE*);
void fileprint();
int maxval(int);
