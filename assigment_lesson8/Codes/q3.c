#include <stdio.h>
#include <stdlib.h>
int main(void) {
	char alph[27];
	char* ptr;
	int i=0;
	ptr=alph;
	printf("Enter the String: \n");
	fflush(stdin); fflush(stdout);
	gets(alph);
	printf("the arrray of alph at:%x the pointer at: %x \n",alph,ptr);
	int j=strlen(alph);
	printf("array size is equal to sentese which equal to:%d \n",j);
	ptr=ptr+(j-1);
	printf("the arrray of alph at:%x the pointer at: %x \n",alph,ptr);
	for (j;j !='\0';j--){

		printf("%c ",*ptr);
		ptr--;
	}
	return 0;
}

