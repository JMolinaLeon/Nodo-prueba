#ifndef SPI2_H

/*----------------------------------------------------------------------------
 HEADER FILES
 -----------------------------------------------------------------------------*/
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/*----------------------------------------------------------------------------
 PROGRAM CONSTANTS
 ----------------------------------------------------------------------------*/
#define	SPI2_H
#define SS1_SetDigitalOutput()  _TRISB0 = 0
#define SD_SS2_Toggle()         _LATB0 ^= 1 
#define SD_SS2_SetLow()         _LATB0 = 0
#define SD_SS2_SetHigh()        _LATB0 = 1

/*Elegir velocidad en la transmisión*/
#define FAST 1//Frecuencia reloj 5Mhz
#define SLOW 0//Frecuencia reloj 312.5kHz


/*----------------------------------------------------------------------------
 FUCTION PROTOTYPES
 -----------------------------------------------------------------------------*/


/**
 * @param Velocidad: FAST= 5Mhz or SLOW=312.5kHz 
 */
void SD_SPI2_Init(unsigned char);

/**
 * @param  Dato a enviar
 * @return Dato recibido
 */
uint8_t SPI2_Exchange_Byte(uint8_t data);

/**
 * 
 * @param Dato a enviar
 * @return Dato recibido
 */
uint8_t SPI2_Write(uint8_t data);


#endif
/*END*/
