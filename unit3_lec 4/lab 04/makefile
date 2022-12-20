#@copyright :Mina
CC			 =arm-none-eabi-
CFLAGS 		 =-mcpu=cortex-m4 -mthumb -gdwarf-2 -g
INCS		 =-I .
LIBS		 =
SRC			 =$(wildcard *.c)
OBJ			 =$(SRC:.c=.o)
ASM    		 =$(wildcard *.s)
ASMOBJ 		 =$(ASM:.s=.o)
LINKER 		 =$(wildcard *.ld)
Project_Name =unit3_lab4_cortex_m4


ALL : $(Project_Name).bin
	@echo "---build is done:)---"


%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) -c $< -o $@
	@echo "---build c-> o files is done:)---"

$(Project_Name).elf : $(OBJ) $(ASMOBJ)
	$(CC)ld.exe -T $(LINKER) $(OBJ) $(ASMOBJ) $(LIBS) -Map=Map_File.map -o $@ -Map=Map_file.map
	cp $(Project_Name).elf $(Project_Name).axf
	@echo "---build linker is done:)---"

$(Project_Name).bin : $(Project_Name).elf
	$(CC)objcopy.exe -O binary $< $@
	@echo "---build binary is done:)---"

clean_all:
	rm *.o *elf *.bin *.map
	@echo "Everything is Cleaned..."

clean:
	rm *.elf *.bin *.map