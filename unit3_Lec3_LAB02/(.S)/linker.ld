/*Startyp_arm_cortexM3
ENG/Mina Sabry */
MEMORY
{
	flash(RX) : ORIGIN = 0x08000000, LENGTH = 128K
	sram(RWX) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{	
	.text : {
		*(.vectors*)
		. = ALIGN(4) ;
		*(.text*)
		. = ALIGN(4) ;
		*(.rodata*)
		. = ALIGN(4) ;
		_E_text = . ;
	}>flash

	.data : {
	_S_Data = . ;
	*(.data*)
	. = ALIGN(4) ;
	_E_Data = . ;	
	}>sram AT> flash
	
	.bss : {
	_S_Bss = . ;
	*(.bss*)
	. = ALIGN(4) ;
	_E_Bss = . ;
	. = ALIGN(4) ;
	. = . +1000 ;
	_stack_top = . ;
	}>sram
}