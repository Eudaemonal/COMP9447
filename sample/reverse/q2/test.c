#include <stdio.h>


/*
Processing the input string and gain authandaction
*/



char *globalStr="";


void gainAuth3(	int *b, int c){

	if(vmAuthLevel!=2){
		exit(1);
	}
	b = b << cl;

	b = b - 0x20;		//sub ebx, 20h
	b[0] = d;
	d = d << cl;

	b[0] =b[0]^0xDEADBEEF;

	d = d << cl;

	d = d << cl;
	b[1] = cx;
	d = d << cl;	
	
	b[1] =b[1] ^0xDEADBEEF;

	d = d << cl;
	d = d << cl;

	b[2] = 0;
	d = d << cl;
	
	if(strcmp(globalStr, b)!=0){	//string not same
		exit(1);
	}
	printAuthLevel(vmAuthLevel);


}




int main(int argc, char *argv[]){


}
