#include <stdio.h>
	struct Sdistance{
		int feet;
		float inch;
	};
struct Sdistance fun(char a){
	struct Sdistance s;
	printf("Enter your %c Feet: \r\n",a);
	fflush(stdin); fflush(stdout);
	scanf("%d",&s.feet);
	printf("Enter your %c Inch: \r\n",a);
	fflush(stdin); fflush(stdout);
	scanf("%f",&s.inch);
	return s;

}
struct Sdistance sum(struct Sdistance a,struct Sdistance b){
	struct Sdistance c;
	c.feet=a.feet+b.feet;
	c.inch=a.inch+b.inch;

	if (c.inch>12.0)
	{
	c.inch=c.inch-12.0;
	++c.feet;
	}
	return c;
}

void Printstudent(struct Sdistance s){
	printf("\nSum of distances=%d\'-%f\'",s.feet,s.inch);


}
void main(){
	struct Sdistance a,b,c;
	a=fun('1');
	b=fun('2');
	c=sum(a,b);
	Printstudent(c);
}



