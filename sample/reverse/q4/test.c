#include <stdio.h>


int sub_80483F4(int arg_0) {
	int d = 0x4EC4EC4F;

	d = d * arg_0;
	d = d >> 2;

	arg_0 = arg_0 >> 31;

	return (d-arg_0);

}




int main(int argc, char *argv[]){
	int a;

	a=sub_80483F4(26);
	printf("%d\n", a);
}
