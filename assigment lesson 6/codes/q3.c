#include <stdio.h>
	struct Scomplex{
		float real;
		float imag;
	};
struct Scomplex fun(char a){
	struct Scomplex s;
	printf("Enter your %c real: \r\n",a);
	fflush(stdin); fflush(stdout);
	scanf("%f",&s.real);
	printf("Enter your %c imaganiray: \r\n",a);
	fflush(stdin); fflush(stdout);
	scanf("%f",&s.imag);
	return s;

}
struct Scomplex sum(struct Scomplex a,struct Scomplex b){
	struct Scomplex c;
	c.real=a.real+b.real;
	c.imag=a.imag+b.imag;
	return c;
}

void Printcomplex(struct Scomplex s){
	printf("Sum=%.1f+%.1fi",s.real,s.imag);


}
void main(){
	struct Scomplex a,b,c;
	a=fun('1');
	b=fun('2');
	c=sum(a,b);
	Printcomplex(c);
}



