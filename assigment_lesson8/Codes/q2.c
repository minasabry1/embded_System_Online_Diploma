#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char alph[27];
	char* ptr;
	int i=0;
	ptr=alph;
	printf("%The alphaptes are: \n");
	for (i;i<26;i++){
		*ptr=i+'A';
		printf("%c ",*ptr);
		ptr++;
	}

	return 0;
}

