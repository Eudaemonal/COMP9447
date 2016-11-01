#include <stdio.h>

char *globalStr="";


void gainAuth3(){
	if(vmAuthLevel!=2){
		exit(1);
	}
	
	
	if(strcmp(globalStr, s2)!=0){	//string not same
		exit(1);
	}
	printAuthLevel(vmAuthLevel);


}




int main(int argc, char *argv[]){


}
