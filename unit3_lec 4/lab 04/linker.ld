/*Startyp_arm_cortexM3
ENG/Mina Sabry */
MEMORY {
	Flash(RX) : ORIGIN = 0x00000000, LENGTH = 512M
	SRAM(RWX) : ORIGIN = 0x20000000, LENGTH = 512M
}

SECTIONS {
	.text : {
		*(.vectors*)
		. = ALIGN(4) ;
		*(.text*)
		. = ALIGN(4) ;
		*(.rodata*)
		. = ALIGN(4) ;
		E_text = .;
	}> Flash 
	.data : {
		S_data = .;
		*(.data*)
		. = ALIGN(4) ; 
		E_data = .;
	}> SRAM AT> Flash
	.bss : {
		S_bss = .;
		*(.bss*)
		. = ALIGN(4) ;
		E_bss = .;
	}> SRAM
}