#include <stdio.h>
#include <stdlib.h>
#include "math.h"
float result(int num){ //recieve an int but return float because maybe a real number.
	return sqrt(num);
}
int main() {
	int x=0;
	int y=0;
	printf("please enter number: \n\r");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);
	printf("output of sqrt: %f \n",result(x));
	printf("please enter number: \n\r");
	fflush(stdin); fflush(stdout);
	scanf("%d",&y);
	printf("output of sqrt: %f \n",result(y));
	return 0;
}

