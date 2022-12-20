//Learn_in_depth
//Eng.Mina Sabry
//#define stack_top 0x20001000
#include <stdint.h>
extern int main(void);
extern unsigned int E_text;
extern unsigned int S_data;
extern unsigned int E_data;
extern unsigned int S_bss;
extern unsigned int E_bss;



void Reset_Handler() {
	// copy Data section from Flash to Ram
	unsigned int Data_size = (unsigned char*)&E_data - (unsigned char*)&S_data;
	unsigned char* P_Src = (unsigned char*)&E_text;
	unsigned char* P_Dst = (unsigned char*)&S_data;
	int i;

	for(i=0;i<Data_size;i++) {
		*P_Dst = *P_Src;
		P_Dst++;
		P_Src++;
	}

	// Init bss section in Ram with 0 
	unsigned int bss_size = (unsigned char*)&E_bss - (unsigned char*)&S_bss;
	P_Dst = (unsigned char*)&S_bss;

	for(i=0;i<bss_size;i++) {
		*P_Dst = (unsigned char)0;
		P_Dst++;
	}

	main();
} 

void Default_Handler() {
	Reset_Handler();
} 

void NMI_Handler() __attribute__((weak,alias("Default_Handler")));

void HardFault_Handler() __attribute__((weak,alias("Default_Handler")));

static unsigned long Stack_Top[256];

void  (* const fun_to_vectors []) () __attribute__((section(".vectors"))) = 
{
    (void (*)()) ((unsigned long)Stack_Top + sizeof(Stack_Top)),
	 &Reset_Handler,
	 &NMI_Handler,
	 &HardFault_Handler
};