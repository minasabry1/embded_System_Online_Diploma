/*
 * LCD.c
 *
 * Created: 2/15/2023 7:59:51 PM
 *  Author: Mina Sabry
 */ 

#include <LCD.h>

GPIO_PIN_CONFIG_T PinCfg;



void LCD_clear_screen (){//clears the LCD screen.

	LCD_Send_A_Command(LCD_CLEAR_SCREEN);
}
void LCD_lcd_kick (void){//sends a pulse to the EN pin of the LCD to initiate a data transfer.
	//Enable read at Falling(H>>L)
	MCAL_GPIO_WritePin(LCD_Control, Enable_Switch, GPIO_PIN_SET) ;
	my_wait(50);
	MCAL_GPIO_WritePin(LCD_Control, Enable_Switch, GPIO_PIN_RESET) ;

}
void LCD_GOTO_XY(unsigned char line, unsigned char position){// positions the cursor at the specified line and position on the LCD screen.
	if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			LCD_Send_A_Command(LCD_BEGIN_AT_FIRST_RAW+position);
		}
	}
	if (line == 2)
	{
		if (position < 16 && position >= 0)
		{
			LCD_Send_A_Command(LCD_BEGIN_AT_SECOND_RAW+position);
		}
	}
}



void LCD_check_lcd_isbusy(void){//checks whether the LCD is busy processing a command or data transfer.
	// initializes the LCD display with the required settings.

	//Pin /A0>>A7 is INPUT
	PinCfg.GPIO_PinNumber=GPIO_PIN_0;
	PinCfg.GPIO_PinMode=GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_Control, &PinCfg);

	PinCfg.GPIO_PinNumber=GPIO_PIN_1;
	PinCfg.GPIO_PinMode=GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_Control, &PinCfg);

	PinCfg.GPIO_PinNumber=GPIO_PIN_2;
	PinCfg.GPIO_PinMode=GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_Control, &PinCfg);

	PinCfg.GPIO_PinNumber=GPIO_PIN_3;
	PinCfg.GPIO_PinMode=GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_Control, &PinCfg);

	PinCfg.GPIO_PinNumber=GPIO_PIN_4;
	PinCfg.GPIO_PinMode=GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_Control, &PinCfg);

	PinCfg.GPIO_PinNumber=GPIO_PIN_5;
	PinCfg.GPIO_PinMode=GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_Control, &PinCfg);

	PinCfg.GPIO_PinNumber=GPIO_PIN_6;
	PinCfg.GPIO_PinMode=GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_Control, &PinCfg);

	PinCfg.GPIO_PinNumber=GPIO_PIN_7;
	PinCfg.GPIO_PinMode=GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_Control, &PinCfg);




	MCAL_GPIO_WritePin(LCD_Control, RW_SWITCH, GPIO_PIN_SET); //RW ON
	MCAL_GPIO_WritePin(LCD_Control, RS_SWITCH, GPIO_PIN_RESET); //RS OFF
	LCD_lcd_kick(); //Enable
	//LCD_Control_Direction |= (0xFF<<DATA_shift);; //DDRA>>Output Mode
	MCAL_GPIO_WritePin(LCD_Control, RW_SWITCH, GPIO_PIN_RESET) ;//Rest
}

void LCD_init(void){//initializes the LCD display with the required settings.
	my_wait(20);
	//LCD_check_lcd_isbusy();

	//LCD_Control_Direction |= (1<<Enable_Switch | 1<<RW_SWITCH | 1<<RS_SWITCH);//DDRB>>OUTPUT (Enable,RS,RW)
	//LCD_Control &= ~(1<<Enable_Switch | 1<<RS_SWITCH | 1<<RW_SWITCH);//PortB

	//Enable_Switch ..RW_SWITCH..RS_SWITCH.. are Output mode, max speed 10 MHz.
	PinCfg.GPIO_PinNumber=RS_SWITCH;
	PinCfg.GPIO_PinMode=GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed=GPIO_SPEED_10M;
	MCAL_GPIO_INIT(LCD_Control, &PinCfg);

	PinCfg.GPIO_PinNumber=RW_SWITCH;
	PinCfg.GPIO_PinMode=GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed=GPIO_SPEED_10M;
	MCAL_GPIO_INIT(LCD_Control, &PinCfg);

	PinCfg.GPIO_PinNumber=Enable_Switch;
	PinCfg.GPIO_PinMode=GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed=GPIO_SPEED_10M;
	MCAL_GPIO_INIT(LCD_Control, &PinCfg);
	////////////////////////////////////////////////////////////////////////

	my_wait(15);

	//Pin /A0>>A7 is OUTPUT
	//01: Output mode, max speed 10 MHz.
	PinCfg.GPIO_PinNumber=GPIO_PIN_0;
	PinCfg.GPIO_PinMode=GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed=GPIO_SPEED_10M;
	MCAL_GPIO_INIT(LCD_Control, &PinCfg);

	PinCfg.GPIO_PinNumber=GPIO_PIN_1;
	PinCfg.GPIO_PinMode=GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed=GPIO_SPEED_10M;
	MCAL_GPIO_INIT(LCD_Control, &PinCfg);

	PinCfg.GPIO_PinNumber=GPIO_PIN_2;
	PinCfg.GPIO_PinMode=GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed=GPIO_SPEED_10M;
	MCAL_GPIO_INIT(LCD_Control, &PinCfg);

	PinCfg.GPIO_PinNumber=GPIO_PIN_3;
	PinCfg.GPIO_PinMode=GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed=GPIO_SPEED_10M;
	MCAL_GPIO_INIT(LCD_Control, &PinCfg);

	PinCfg.GPIO_PinNumber=GPIO_PIN_4;
	PinCfg.GPIO_PinMode=GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed=GPIO_SPEED_10M;
	MCAL_GPIO_INIT(LCD_Control, &PinCfg);

	PinCfg.GPIO_PinNumber=GPIO_PIN_5;
	PinCfg.GPIO_PinMode=GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed=GPIO_SPEED_10M;
	MCAL_GPIO_INIT(LCD_Control, &PinCfg);

	PinCfg.GPIO_PinNumber=GPIO_PIN_6;
	PinCfg.GPIO_PinMode=GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed=GPIO_SPEED_10M;
	MCAL_GPIO_INIT(LCD_Control, &PinCfg);

	PinCfg.GPIO_PinNumber=GPIO_PIN_7;
	PinCfg.GPIO_PinMode=GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed=GPIO_SPEED_10M;
	MCAL_GPIO_INIT(LCD_Control, &PinCfg);
	LCD_clear_screen();

	//#ifdef Eight_Bit_Mode

		LCD_Send_A_Command(LCD_FUNCTION_8BIT_2LINES);
	//#endif // Eight_Bit_Mode

	//#ifdef Four_Bit_Mode
	//	LCD_Send_A_Command(0x02);
	//	LCD_Send_A_Command(LCD_FUNCTION_4BIT_2LINES);
	//#endif // Eight_Bit_Mode

		LCD_Send_A_Command(LCD_ENTRY_MODE);
		LCD_Send_A_Command(LCD_BEGIN_AT_FIRST_RAW);
		LCD_Send_A_Command(LCD_DISP_ON_CURSOR_BLINK);


}


void LCD_Send_A_Command(unsigned char command){//sends a command to the LCD display.
	//send commands already intialized at datasheet and there are steps for doing it.
	//#ifdef Eight_Bit_Mode
	//LCD_check_lcd_isbusy();
	//LCD_Control=command;
	MCAL_GPIO_WritePort(LCD_Control, command);
	//LCD_Control &=~((1 << RS_SWITCH) | (1<<RW_SWITCH)) ;//PortB
	MCAL_GPIO_WritePin(LCD_Control, RS_SWITCH, GPIO_PIN_RESET) ;
	MCAL_GPIO_WritePin(LCD_Control, RW_SWITCH, GPIO_PIN_RESET) ;
	my_wait(1);
	LCD_lcd_kick();
	//#endif // Eight_Bit_Mode
	//#ifdef Four_Bit_Mode
	//	LCD_check_lcd_isbusy();
	//	LCD_Control = (LCD_Control & 0x0F) | (command & 0xF0);
	//	LCD_Control &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
	//	LCD_lcd_kick ();
	//	my_wait(100);
	//	LCD_Control = (LCD_Control & 0x0F) | (command << 4);
	//	LCD_Control &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
	//	LCD_lcd_kick();
	//#endif
}
void LCD_Send_A_Character(unsigned char character){//writes a character to the LCD display.
	//#ifdef Eight_Bit_Mode
	//LCD_check_lcd_isbusy();
	MCAL_GPIO_WritePort(LCD_Control, character);
	MCAL_GPIO_WritePin(LCD_Control, RS_SWITCH, GPIO_PIN_SET) ;
	MCAL_GPIO_WritePin(LCD_Control, RW_SWITCH, GPIO_PIN_RESET) ;

	my_wait(1);
	LCD_lcd_kick();
	//#endif // Eight_Bit_Mode

	//#ifdef Four_Bit_Mode
	//	LCD_check_lcd_isbusy();
	//	LCD_Control = (LCD_Control & 0x0F) | (character & 0xF0);
	//	LCD_Control |= 1<<RS_SWITCH; //turn RS ON for Data mode.
	//	LCD_Control &= ~(1<<RW_SWITCH);//turn RW off so you can write.
	//	LCD_lcd_kick ();
	//	LCD_Control = (LCD_Control & 0x0F) | (character << 4);
	//	LCD_Control |= 1<<RS_SWITCH; //turn RS ON for Data mode.
	//	LCD_Control &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
	//	LCD_lcd_kick();
	//#endif
	//}


}

