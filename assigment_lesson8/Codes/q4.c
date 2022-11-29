#include <stdio.h>
#include <stdlib.h>
int main(void) {
	 int elments[15];
	 int* ptr;
	int num;
	int i=0;
	ptr=elments;
	printf("Enter the size of array max(15): \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);
	for(i;i<num;i++){
	printf("enter element of %d=:",i+1);
	fflush(stdin); fflush(stdout);
	scanf("%d",&elments[i]);
	}
	ptr=ptr+(num-1);

	for (num;num !=0;num--){

		printf("element of%d=:%d \n",num,*ptr);
		ptr--;
	}
	return 0;
}

