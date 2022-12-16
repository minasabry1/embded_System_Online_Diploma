//Eng:Mina Sabry
#define RCC_Base 0x40021000
#define GPIOPA_Base 0x40010800
typedef volatile unsigned int vuint32_t; 
#define RCC_APB2ENR (*(vuint32_t *)(RCC_Base + 0x18))
#define GPIOPA_CRH  (*(vuint32_t *)(GPIOPA_Base + 0x04))
#define GPIOPA_ODR (*(vuint32_t *)(GPIOPA_Base + 0x0c))

typedef union {
	vuint32_t all_fields;
	struct {
		vuint32_t reserved:13;
		vuint32_t P_13:1;
	} Pin;
} ODR_t;

volatile ODR_t* output_ODR = (volatile ODR_t*)(GPIOPA_Base+0x0c);
volatile unsigned int Unintialized_Global;
unsigned char G_variables[] = {1,2,3};

int main(void)
{
    RCC_APB2ENR |= 1<<2;
    GPIOPA_CRH &= 0xff0ffff;
    GPIOPA_CRH |= 0x00200000;
    int i;
    while (1) {
    	output_ODR->Pin.P_13 = 1;
    	for(i=0;i<5000;i++);
    	output_ODR->Pin.P_13 = 0;
    	for(i=0;i<5000;i++);
    }
     return 0;
}