#include <stdio.h>

int readBanner(char *s){

	FILE *stream;
	stream = fopen("banner.txt", "wb");
	
	if(stream==NULL) exit(0);
	
	fputs(s, stream);

	fclose(stream);
	return;
}




//========================================
int main(int argc, char *argv[]){
	char *string = "hahahaha";
	readBanner(string);

}


