#include <stdio.h>
#include <stdlib.h>
void unique(int arr[],int n);
int main(void) {
	int array[10];
	int a=0;
	printf("please enter size of array: \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&a);
	printf("please enter elements of array: \n");
	fflush(stdin); fflush(stdout);
	for(int i=0;i<a;i++){
		scanf("%d",&array[i]);
	}
	unique(array,a);
	return 0;
}

void unique(int arr[],int n){
	int i=0,j=0,count=0;
	for ( i=0;i<n;i++){
		count=0;
		for(j=0;j<n;j++){
			if(i!=j){
				if(arr[i]==arr[j])
					count++;
			}

		}
		if (count==0)
			printf("the unique number is: %d",arr[i]);

	}
}