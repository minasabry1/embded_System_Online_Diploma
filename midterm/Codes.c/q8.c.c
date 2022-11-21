#include <stdio.h>
#include <stdlib.h>
void reverse(int arr[], int n);

int main(void) {
	int arr[10];
	int x=0;
	printf("please enter size of array: \r\n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);
	printf("Enter elements of array: \r\n");
	fflush(stdin); fflush(stdout);
	for(int i=0;i<x;i++){
		scanf("%d",&arr[i]);
	}
	printf("The reverse array are :\n");
	reverse(arr,x);

	return 0;
}

void reverse(int arr[], int n){
	for(int i=n-1;i>=0;i--){
		printf("%d ",arr[i]);
	}
}