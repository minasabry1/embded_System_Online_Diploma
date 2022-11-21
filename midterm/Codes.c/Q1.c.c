#include <stdio.h>
#include <stdlib.h>
int sum(int num);
int main(void) { //decleartion.
	int x=0;
	int y=0;
	printf("please enter a number: \r\n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);
	printf("sum=: %d \r\n",sum(x));


	return 0;
}
int sum(int num){ //as in midterm mcq those steps were to sum an array
	int reminder;
	static int new=0;
	if(num!=0){
		reminder=num%10;
		new+=reminder;
		sum(num/10);
	}
	return new;
}