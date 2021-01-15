/*
 * Project_Slave.c
 *
 * Created: 1/10/2021 4:04:32 PM
 * Author : Asmaa Mahmoud
 */ 

#include "LCD.h"
#include "SPI.h"

int main(void)
{
	Uint8t Data_REc = 0;
	//LED0_Init();
	//LED1_Init();
	LCD_Init();
	SPI_INIT();
	LCD_Clear();
	LCD_Write_String((Uint8t*)"Waiting for Data!!");
	DDRA |=0x0F;
	PORTA &=0xF0;
	/* Replace with your application code */
	while (1)
	{
		Data_REc = SPI_RECEIVE();
		
		switch (Data_REc)
		{

			case '0' :
			LCD_Clear();
			CLR_BIT(PORTA,PA1);CLR_BIT(PORTA,PA2);SET_BIT(PORTA,PA0);
			LCD_Write_String((Uint8t*)"LED_0 IS ON");
			Data_REc = 0;
			break;
			
			case '1':
			LCD_Clear();
			CLR_BIT(PORTA,PA0);CLR_BIT(PORTA,PA2);SET_BIT(PORTA,PA1);
			LCD_Write_String((Uint8t*)"LED_1 IS ON");
			Data_REc = 0;
			break;
			
			case '2':
			LCD_Clear();
			CLR_BIT(PORTA,PA1);CLR_BIT(PORTA,PA0);SET_BIT(PORTA,PA2);
			LCD_Write_String((Uint8t*)"LED_2 IS ON");
			Data_REc = 0;
			break;
			
			case '3':
			LCD_Clear();
			PORTA=0x0F;
			LCD_Write_String((Uint8t*)"ALL LEDS ON");
			Data_REc = 0;
			break;
			case '4':
			
			LCD_Clear();
			PORTA=0x00;
			LCD_Write_String((Uint8t*)"ALL LEDS OFF");
			_delay_ms(3000);
			Data_REc = 0;
			break;
			
		}
	}
}