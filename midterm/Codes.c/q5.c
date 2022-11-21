#include <stdio.h>
#include <stdlib.h>
int counts(int num);
int main(void) {
	int x=0;
	int y=0;
	printf("please enter number: \n");
	 fflush(stdin); fflush(stdout);
	scanf("%d",&x);
	printf("output of counting: %d \n",counts(x));
	printf("please enter number: \n");
	fflush(stdout);
	scanf("%d",&y);
	printf("output of counting %d \n",counts(y));

	return 0;
}

int counts(int num){
	int count=0;
	for(int i=0;i<17;i++){
		if((num & 1<<i)){
			count++;
		}
	}
	return count;
}