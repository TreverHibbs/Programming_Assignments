#include "heading.h"

void fileprint(){
	int index=0;
	printf("\n");
	printf("item	|weight	|value	|name		\n");
	printf("--------+-------+-------+---------------\n");
	while(index != 128 && item.flag[index] != 0){
	printf("%d	|%d	|%d	|%s		\n", (index+1), item.weight[index], item.value[index], item.name[index]);
	index++;
	}
	printf("\n");
}
