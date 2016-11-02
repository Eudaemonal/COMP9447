#include <stdio.h>

/*
 Remove '.' inside string arg_0 
*/



void sub_4012D0(int *arg_0) {
	int i;
	int j;
	int k;

	*var_14 = *arg_0;
	
	var_18 = *var_14[0] + 1;
	

	int i=0;
	do{
		var_19[i] = var_14[i]
		i++;
	}while(var_19[i]!= '\0')


	var_20 = *var_14[i] - var_18;

	Size = var_20;

	Memory = malloc(Size);
	memset(Memory, 0, Size);

	j = 0;			//var_8
	k = 0;			//var_10
	while(j <= Size){
		if((arg_0 [j])!= '.'){
			Memory[k] = arg_0 [j];
			k++;
		}
		j++;
	}


	int p=0;		//var_24
	int q=0;		//var_28

	//var_24[p] = Memory[k];
	//var_28[q] = arg_0[j];
	var_2C = var_28;

	do{							//copying string Memory to arg_0
		temp = Memory[p];
		arg_0[q]; = temp;
		
		p ++;
		q ++;
	}while (temp != '\0')
	
	arg_0[k] = '\0';

	free(Memory);

}




int main(int argc, char *argv[]){
	
}
