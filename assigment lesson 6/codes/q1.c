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
	scanf(&s.roll);
	printf("Enter your Marks: \r\n");
	fflush(stdin); fflush(stdout);
	scanf(&s.marks);
	return s;

}

void Printstudent(struct Sstudent s){
	printf("your name:%s \n ",s.a);
	printf("your Roll:%d \n",s.roll);
	printf("your Marks:%f \n",s.marks);

}
void main(){
	struct Sstudent s;
	s=fun();
	Printstudent(s);
}



