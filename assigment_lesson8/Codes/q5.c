#include <stdio.h>
#include <stdlib.h>
struct Sinf{
	char E_name[20];
	int age;
	int E_id;
};

int main() {

	struct Sinf inf1={"mina",25,01};
	struct Sinf inf2={"kiro",25,02};
	struct Sinf inf3={"mark",28,03};
	struct Sinf inf4={"Abanoub",25,04};
	struct Sinf (*ptr_arr[4])={&inf1,&inf2,&inf3,&inf4};
	int i=0;

	for(i;i<4;i++){

		printf("\n%s \n", ptr_arr[i]->E_name);
		printf("%d \n", ptr_arr[i]->age);
		printf("%d \n", ptr_arr[i]->E_id);
		printf("----------------");
	}
	return 0;
}

