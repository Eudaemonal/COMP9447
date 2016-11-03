#include <stdio.h>


//Bubble sort

void bubble_sort(int *array, int size){
	int i;
	int j;
	i=0;
	
	while(i != size){

		for(j=1; j<size; j++){
			if(array[j] >= arg[j-1]){
				i++;
			}
			else{		//swap esi, ebx
				temp = array[j-1];
				array[j-1] = array[j];
				array[j] = temp;
			}
		}
		i++;
	}

}
