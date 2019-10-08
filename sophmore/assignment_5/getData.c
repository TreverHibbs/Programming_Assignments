#include "heading.h"

/*
	getData function source code. This code first assumes that
	file pointer successfully opened a file named "knapsack.data"
	First check determines if the file is empty, returns zero
	if true. Else, goes through each entry until end of file.
	Parsing the string utilizes sscanf; however, correct conversion
	of integers appears to fail for reasons unknown.
*/

int getData(FILE*fp){ // do we need to get a file pointer or can we
			// call it in here? ex:
			// FILE*fp = fopen("knapsack.data", "r");
	char string[128], item_name[32], *p;
	int value=0, weight=0, i=0, line=0;
	if (fp == NULL) return 0;
		printf("initial pointer is not null\n");
	while(NULL != fgets(string, 128, fp)){
		if(sscanf(string, "%d %d %s", &weight, &value, item_name) != 3) return 0;
		item.weight[line]=weight;
		item.value[line]=value;
		strcpy(item.name[line], item_name);
		/*
		while(p != NULL){
			printf("i loop %d\n", i);
			if(i==0) sscanf(p, "%d", &a[line]->weight);
			printf("i==0");
			if(i==1) sscanf(p, "%d", &a[line]->value);
			printf("i==1");
			if(i==2) strcpy(a[line]->name, p);
			printf("i==2");
			i++;
		} 
		*/
		// printf("leaving i loop\n");
		
		item.flag[line]=1;	// flag used to track valid
		item.number_of_items++;
		
		//item.maxval[line]=0;	// entries in global structure
		line++;
	}
	fclose(fp);
	//reset line for next loop.
	printf("Finished reading valid data\n");
	while(line != 128){ // for all other lines not filled in,
			// register flag and maxval as zero.
		item.flag[line]=0;
		//a[line].maxval=0;
		line++;
	}
	return 1;
}
