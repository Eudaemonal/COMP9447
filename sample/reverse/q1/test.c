#include <stdio.h>


/*
 write a string arguemnt into banner.txt
*/


int readBanner(char *s){

	FILE *stream;
	stream = fopen("banner.txt", "wb");
	
	if(stream==NULL) exit(0);

	s[20] = 0;
	fputs(s, stream);

	return fclose(stream);
	
}




//========================================
int main(int argc, char *argv[]){
	char *string = "hahahaha";
	readBanner(string);

}


