#include <stdio.h>
#include <stdlib.h>

int main(void) {
	double m=29;
	double* ab;
	ab=&m;
	printf("the value of m=%0.3lf and adress of m is %x \n",m,&m);
	printf("the value of ab=%0.3lf and adress of ab is %x \n",*ab,ab);
	m=34;
	printf("the value of m=%0.3lf and adress of m is %x \n",m,&m);
	printf("the value of ab=%0.3lf and adress of ab is %x \n",*ab,ab);
	*ab=7;
	printf("the value of m=%0.3lf and adress of m is %x \n",m,&m);
	printf("the value of ab=%0.3lf and adress of ab is %x \n",*ab,ab);
	return 0;
}

