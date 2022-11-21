#include <stdio.h>
	struct Sstudent{
		char a[20];
		int roll;
		float marks;
	};
struct Sstudent fun(){
	struct Sstudent s;
	printf("Enter your name: \r\n");
	fflush(stdin); fflush(stdout);
	scanf("%s",s.a) ;
	printf("Enter your Roll: \r\n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&s.roll);
	printf("Enter your Marks: \r\n");
	fflush(stdin); fflush(stdout);
	scanf("%f",&s.marks);
	return s;

}

void Printstudent(struct Sstudent s){
	printf("your name:%s \n ",s.a);
	printf("your Roll:%d \n",s.roll);
	printf("your Marks:%.2f \n",s.marks);

}
void main(){
	struct Sstudent s[10];
	int i;
	for(i=0;i<10;i++){
	s[i]=fun();
	}
	for(i=0;i<10;i++){
		Printstudent(s[i]);
		}

}



