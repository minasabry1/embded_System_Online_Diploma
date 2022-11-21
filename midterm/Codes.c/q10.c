#include <stdio.h>
#include <stdlib.h>
int max(int num);
int main() {
	int x=0;
	printf("please enter number: \r\n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);
	printf("Max num of ones re: %d \r\n",Max(x));
	printf("\nEnter number: \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);
	printf("Max num of ones are: %d \r\n",Max(x));

	return 0;
}

int Max(int num){
	int count=0, max=0;
	for (int i=0;i<6;i++){
		if(num&1<<i){
			count++;
			if(max<=count)
				max=count;
		}
		else
			count=0;
	}
	return max;
}