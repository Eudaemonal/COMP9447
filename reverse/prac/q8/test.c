#include <stdio.h>




void sub_401120(int Size){
	int var_4;

	*Dst = malloc(Size);

	memset(Dst, 0, Size);
	
	Dst[5] = 1;
	Dst[6] = 2;

	var_4 = 0;
	while(var_4 <Size){
		printf("arr is %x", Dst[var_4]);
		var_4++;
	}
 	return;
}
