#include <stdio.h>
	struct Scircum{
		float radius;
		float area;
	};
struct Scircum fun(){
	struct Scircum s;
	printf("Enter your radius: \r\n");
	fflush(stdin); fflush(stdout);
	scanf("%f",&s.radius);
	s.area=(3.1415)*(s.radius)*(s.radius);
	return s;

}

void Printcircum(struct Scircum s){
	printf("Circumfrance=%.1f",s.area);


}
void main(){
	struct Scircum a;
	a=fun();
	Printcircum(a);
}



