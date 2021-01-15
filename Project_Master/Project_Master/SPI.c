/*
* SPI.c
*
* Created: 12/19/2020 2:29:11 PM
*  Author: karim
*/

#include "SPI.h"

void SPI_INIT(void)
{
	#if SPI_MODE == SPI_MASTER
	/*Define Directions for pins*/
	SET_BIT(SPI_PORT, MOSI);/*MOSI - Output*/
	CLR_BIT(SPI_PORT, MISO);/*MISO - Input*/
	SET_BIT(SPI_PORT, SCK); /*SCK  - Output*/
	SET_BIT(SPI_PORT, SS);  /*SS   - Output*/
	SPCR = 0x53;
	#elif SPI_MODE == SPI_SLAVE
	/*Define Directions for pins*/
	CLR_BIT(SPI_PORT, MOSI);/*MOSI - Input*/
	SET_BIT(SPI_PORT, MISO);/*MISO - Output*/
	CLR_BIT(SPI_PORT, SCK); /*SCK  - Input*/
	CLR_BIT(SPI_PORT, SS);  /*SS   - Input*/
	SPCR = 0x43;
	#endif
}
void SPI_TRANSMIT(Uint8t data)
{
	SPDR = data;
	while (GET_BIT(SPSR, SPIF) != 1);
}
Uint8t SPI_RECEIVE(void)
{
	while (GET_BIT(SPSR, SPIF) != 1);
	return SPDR;
}
void SPI_SLAVESELECT(void)
{
	CLR_BIT(PORTB, SS);
}

/*
void SPI_MASTER_INIT(void)
{
DIO_SetPin_Direction(DIO_PORTB ,DIO_PIN4 , DIO_PIN_OUTPUT);
DIO_SetPin_Direction(DIO_PORTB ,DIO_PIN5 , DIO_PIN_OUTPUT);
DIO_SetPin_Direction(DIO_PORTB ,DIO_PIN6 , DIO_PIN_INPUT);
DIO_SetPin_Direction(DIO_PORTB ,DIO_PIN7 , DIO_PIN_OUTPUT);

SPI->SPCR.SPR0 = 1;
SPI->SPCR.SPR1 = 1;
SPI->SPCR.CPHA = 0;
SPI->SPCR.CPOL = 0;
SPI->SPCR.MSTR = 1;
SPI->SPCR.DORD = 0;
SPI->SPCR.SPE  = 1;
}
void SPI_SLAVE_INIT(void)
{
DIO_SetPin_Direction(DIO_PORTB ,DIO_PIN4 , DIO_PIN_INPUT);
DIO_SetPin_Direction(DIO_PORTB ,DIO_PIN5 , DIO_PIN_INPUT);
DIO_SetPin_Direction(DIO_PORTB ,DIO_PIN6 , DIO_PIN_OUTPUT);
DIO_SetPin_Direction(DIO_PORTB ,DIO_PIN7 , DIO_PIN_INPUT);

SPI->SPCR.SPR0 = 0;
SPI->SPCR.SPR1 = 0;
SPI->SPCR.CPHA = 0;
SPI->SPCR.CPOL = 0;
SPI->SPCR.MSTR = 0;
SPI->SPCR.DORD = 0;
SPI->SPCR.SPE  = 1;
}
void SPI_MASTER_START_TRASNMIT(void)
{
DIO_SetPin_Value(DIO_PORTB ,DIO_PIN4 ,DIO_PIN_LOW);
}
void SPI_MASTER_STOP_TRASNMIT(void)
{
DIO_SetPin_Value(DIO_PORTB ,DIO_PIN4 ,DIO_PIN_HIGH);
}
Uint8t SPI_TRANSIVIER(Uint8t Data)
{
Uint8t  rec_data = 0 ;

SPI->SPDR = Data ;

while(GET_BIT(SPI->SPSR , 7)  ==  0);

rec_data = SPI->SPDR;

return rec_data ;
}
*/