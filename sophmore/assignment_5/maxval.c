#include"heading.h"

int maxval(int cap){
	
	int i = 0, best = 0;
	//this variable is to get the return for values eligible for maxval.
	int tmp = 0;
	//loop will iterate through all item in knapsack.data
	while(i < item.number_of_items){
		//this will check if weight is more than cap. If it is do not preform recursion.
		if(item.weight[i] <= cap){ 
			//Check if return of maxval has already bin saved in maxval array for 
			//current capasity and item weigth. 
			//To index the item.maxval array we use weight. 
			if(item.maxval[cap - item.weight[i]] == 0){
				//save maxval return of current weight index in maxval in array.
				item.maxval[cap - item.weight[i]] = maxval(cap - item.weight[i]);
				//save to tmp the now saved return of the current weight index plus current 
				//item value.
				tmp = item.value[i] + item.maxval[cap - item.weight[i]];
			//This will check if the current weight index already has a saved value in it. 
			}else if(item.maxval[cap - item.weight[i]] != 0){
				//save in tmp the saved maxval value for current weight index.
				tmp = item.value[i] + item.maxval[cap - item.weight[i]];
			}
			//check if the return from maxval plush current item value is better than previousely
			//calculated return.
			if(tmp > best){
				best = tmp;
			}
		}
		i++;
	}
	//return maxval.
	return(best);
}
