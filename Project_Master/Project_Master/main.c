/*
 * Project_Master.c
 *
 * Created: 1/10/2021 1:02:44 PM
 * Author : Asmaa Mahmoud
 */ 


#include "LCD.h"
#include "UART.h"
#include "SPI.h"

int main(void)
{
	Uint8t Data_Input = 0;

	LCD_Init();
	UART_Init();
	SPI_INIT();
	SPI_SLAVESELECT();
	LCD_Clear();
	LCD_Write_String((Uint8t*)"Hello .. ");
	_delay_ms(5000);
	LCD_Clear();
	DDRA |=0x0F;
	PORTA &=0xF0;
	
	/* Replace with your application code */
	while (1)
	{
		Data_Input = UART_Rx();

		switch (Data_Input)
		{
			case '0' :
						LCD_Clear();
						LCD_Write_Data(Data_Input);
						SPI_TRANSMIT(Data_Input);
						Data_Input = 0;
						break;
			case '1' :
						LCD_Clear();
						LCD_Write_Data(Data_Input);
						SPI_TRANSMIT(Data_Input);
						Data_Input = 0;
						break;
		 case '2':
		 			LCD_Clear();
		 			SET_BIT(PORTA,PA2);
		 			LCD_Write_Data(Data_Input);
		 			SPI_TRANSMIT(Data_Input);
		 			Data_Input = 0;		
					 break;
		case '3':
		         			LCD_Clear();
							 PORTA=0x0F;
		         			LCD_Write_Data(Data_Input);
							 SPI_TRANSMIT(Data_Input);
		         			Data_Input = 0;
							break;
							
		case '4':
		         			LCD_Clear();
							 PORTA=0x00;
		         			LCD_Write_Data(Data_Input);
							 SPI_TRANSMIT(Data_Input);
		         			_delay_ms(3000);
		         			Data_Input = 0;
		         			break;		
			
		}
	}
}