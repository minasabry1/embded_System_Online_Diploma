#include<stdio.h>
int check_prime(int num);
int main(){
	int start,end, result,i;
	printf("Enter two numbers: \r\n");
	fflush(stdin); fflush(stdout);
	scanf("%d %d",&start, &end);
	printf("The start of the interval is: %d and the end is: %d \r\n",start,end);
	for(i=start;i<end;++i){
		result=check_prime (i);
		if(result==1)
			printf("%d \r\n",i);
	}

	return 0;

}

int check_prime(int num)
{
	int j,result=1;
	for (j=2; j<=num/2;++j){
		if (num%j==0) {
			result=0;
			break;
		}
	}
	return result;

}