#include <stdio.h>


/*
Calcuate fibonacci numbers and put them in an array

Input:  size of fibonacci numbers
Output: Fibonacci number array pointer. or 0 if size is 0
*/


int *sub_8048632 (int arg_0){
	int *buffer;
	if(arg_0==0){
		return 0;
	}
	

	//a = &( *(arg_0) * 4);
	buffer = (*int) malloc(arg_0 * sizeof(int));

	buffer[0] = 1;
	if(arg_0==1){
		return buffer;
	}
	buffer[1] = 1;
	int i = 2;
	while(i < arg_0) {
		buffer[i] = buffer[i-1] + buffer[i-2];
		i++;
	}
	// mov ebx, [ebp + var_4]

	return buffer;
}
