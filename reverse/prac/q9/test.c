#include <stdio.h>



/*
Finding " and change it to \"
*/


void sub_401190(char *arg_0){
	int i;

	dx = arg_0->offset1;

	c = c->offset0;

	/*
	int i=0;
	do{
		i++
	}while(arg_0[i]!=0)		//get the length of arg_0
	i = i- 1
	*/
	
	s = len(arg_0);

	i = 0;
	if(s==0) return 0;
	a = 0;

	if(s ){
		do{
			if(arg_0[i]==0x22){
				i++;
			}
			a++;
		}while(a < s)
	}
	
	*ptr = malloc(i+s+1);


	if(ptr==NULL) return 0;
	i = 0;
	if(s == 0){
		ptr[i] = 0;
	}
	else{
		do{
		
			if(arg_0[i] == 0x22){
				ptr[j] = 0x5C;
				j++;
			}
			ptr[j] = arg_0[i];
			i++;
			j++;

		}while(i < s);
	}

}

//===================================================


char *escapeDoubleQuotes(char *str) {


  char *endPtr = str;
  char *startPtr = str+1;
  char ch;
  int  i;


  do {
    ch = *endPtr;
    endPtr++;
  } while (ch!= '\0')


  int maxIndex = (int)endPtr - (int)startPtr;
  int numQuotes = 0;
  if (maxIndex == 0) { return NULL; }


  for (i = 0; i < maxIndex; i++) {
    if (str[i] == '"') { numQuotes++; }
  }


  int newStrLength = maxIndex + numQuotes + 1;
  char *newString = malloc(newStrLength);
  if (newString == NULL) { return NULL; }


  char *strPtr = newString;
  for (i = 0; i < maxIndex; i++) {
    ch = str[i];


    if (ch == '"') {
      *strPtr = '\\';
      strPrt++;
    }


    *strPtr = ch;
    strPtr++;
  }


  newString[i] = '\0';
  return newString;
}












