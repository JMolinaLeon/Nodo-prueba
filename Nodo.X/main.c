#include "main.h"

unsigned char bufferE[512];
unsigned char bufferR[512];
unsigned char banderInt1;
unsigned char banderaSPI1;
unsigned int banderCont;
unsigned long sector;

unsigned char mutex;

typedef struct _data_to_send {
    uint32_t add;
    uint32_t sub;
    uint32_t mult;
    uint32_t div;
} data_to_sent;
data_to_sent to_send;

typedef struct _data_to_received {
    uint32_t op1;
    uint32_t op2;
} data_received;
data_received received;

/*----------------------------------------------------------------------------
 FUNCTION PROTOTYPES
 -----------------------------------------------------------------------------*/

/*============================================================================
 FUNCTION MAIN
 =============================================================================*/
int main(void) {
    /* Variables Locales*/
    unsigned char rx_addr[5] = {0x78, 0x78, 0x78, 0x78, 0x78};
    unsigned char tx_addr[5] = {0x78, 0x78, 0x78, 0x78, 0x78};

    unsigned int  j;

    banderInt1 = 1;
    banderCont = 0;
    banderaSPI1 = 0;
    sdF.detected = 0;
    sdF.init_ok = 0;
    sdF.saving = 0;
    sector = 2051;
    mutex = 0;

    SYSTEM_Initialize();

    /* Incializamos la variable de la memoria a 0*/
    for (j = 0; j < 512; j++) {
        bufferE[j] = 0;
    }

    //Configuramos  RF24L01
    RF24L01_setup(tx_addr, rx_addr, 12);

    /*Encendemos el ADXL255*/
    //ADXL355_Write_Byte(POWER_CTL, MEASURING);
    //__delay_ms(250);
    
    for (j = 0; j < 10; j++) {
        LED_rojo_toggle();
        __delay_ms(100);
    }

    uint8_t buffer[5]; //USO DE LA LECTURA DE REGISTROS Y PAYLOAD
    ReadregisterNum(RF24L01_reg_TX_ADDR,5,buffer); // LEER BYTES DEL REGISTRO ADRESS
    if (buffer[0] == tx_addr[0]&& buffer[1] == tx_addr[1]&& buffer[2] == tx_addr[2] 
       && buffer[3] == tx_addr[3] && buffer[4] == tx_addr[4] ){
        for (j = 0; j < 10; j++) {
            LED_rojo_toggle();
            __delay_ms(500);
        }
        
      LED_rojo_setHigh();
    } 
    else{ 
        LED_rojo_setLow();
    }
    //LED_verde_setLow();

    while (1) {

        
    }

    return 0;
}



