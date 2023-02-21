///*
// * KEY_BAD.c
// *
// * Created: 2/16/2023 12:05:14 AM
// *  Author: mina sabry
// */
//#include "KEY_PAD.h"
//int Key_padRow[] = {R0, R1, R2, R3}; //rows of the keypad
//int Key_padCol[] = {C0, C1, C2, C3};//columns
//
//void Keypad_init(){
//	DataDir_KEYPAD_PORT &= ~((1 << R0) | (1 << R1) | (1 << R2) | (1 << R3));//Row>>Input
//	DataDir_KEYPAD_PORT |= ((1 << C0) | (1 << C1) | (1 << C2) | (1 << C3));//Coloumn>>Output
//	KEYPAD_PORT = 0xFF;
//}
//
//char Keypad_getkey(){
//	int i,j;
//	for (i = 0; i < 4; i++){
//		KEYPAD_PORT |= ((1<<Key_padCol[0]) | (1<<Key_padCol[1]) | (1<<Key_padCol[2]) | (1<<Key_padCol[3]));//All columns are 1
//		KEYPAD_PORT &= ~(1<<Key_padCol[i]);//Each time make one of them is 0 to check if pressed.
//		for(j = 0; j < 4; j++){//Loop at each row of the selected coloumn
//			if (!(keypadPIN & (1 << Key_padRow[j])))//Read the input from which row
//			{
//				while(!(keypadPIN & (1 << Key_padRow[j])));//Multi-Pressing.
//				switch(i){
//					case (0)://1ST COLOUMN
//					if (j == 0)
//					 return '7';
//					else if (j == 1)
//					 return '4';
//					else if (j == 2)
//					 return '1';
//					else if (j == 3)
//					 return '?';
//					break;
//					case (1)://2Nd COLOUMN
//					if (j == 0)
//					 return '8';
//					else if (j == 1)
//					 return '5';
//					else if (j == 2)
//					 return '2';
//					else if (j == 3)
//					 return '0';
//					break;
//					case (2)://3Rd COLOUMN
//					if (j == 0)
//					 return '9';
//					else if (j == 1)
//					 return '6';
//					else if (j == 2)
//					 return '3';
//					else if (j == 3)
//					 return '=';
//					break;
//					case (3)://4TH COLOUMN
//					if (j == 0)
//					 return '/';
//					else if (j == 1)
//					 return '*';
//					else if (j == 2)
//					 return '-';
//					else if (j == 3)
//					 return '+';
//					break;
//				}
//			}
//		}
//	}
//	return 'A';
//}
