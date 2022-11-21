#include <stdio.h>
#include <stdlib.h>
void reverse_string(char str[]);
int main(void) {
	char a[100];
	printf("please enter string: \r\n ");
	fflush(stdin); fflush(stdout);
	gets(a);
	reverse_string(a);
	return 0;
}

void reverse_string(char str[]){
	int i = strlen(str);
	char ove[100];
	for (i;i>=0;i--){
		if(str[i]==' '){
			for(int j=i+1;j<=strlen(str);j++){
				printf("%c",str[j]);
			}
		}
	}
	for(int k=0;k<strlen(str);k++){
		if(str[k]!=' '){
			printf("%c",str[k]);
		}
		else
			break;
	}
}