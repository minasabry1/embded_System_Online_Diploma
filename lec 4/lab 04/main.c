//Eng:Mina Sabry
   
#define SYSCTL_RCG2_R *((volatile unsigned long*)(0x400FE108))
#define GPIO_PORTF_DIR_R *((volatile unsigned long*)(0x40025400))
#define GPIO_PORTF_DEN_R *((volatile unsigned long*)(0x4002551C))
#define GPIO_PORTF_DATA_R *((volatile unsigned long*)(0x400253FC))
int main(){
SYSCTL_RCG2_R =0x20;
//Delay to make sure GPIOF is UP and RUNNING
volatile unsigned long delay_count; //to not be deleted by optmiser
for (delay_count =0;delay_count <200;delay_count++);
GPIO_PORTF_DIR_R |= 1<<3; // Dir is output for pin 3 at port f
GPIO_PORTF_DEN_R |= 1<<3;
while (1){
GPIO_PORTF_DATA_R |= 1<<3;
for (delay_count =0;delay_count <200000;delay_count++);
GPIO_PORTF_DATA_R &= ~(1<<3);
for (delay_count =0;delay_count <200000;delay_count++);

}
    return 0;

}