#ifndef DS3234_H
#define DS3234_H
#include "spi1.h"
/*****************************************************************************/
/* DS3234 Variables */
/*****************************************************************************/
typedef struct{
    unsigned char seconds;
    unsigned char minutes;
    unsigned char hours;
    unsigned char day_of_week;
    unsigned char date;
    unsigned char month;
    unsigned char year;
    unsigned char init_ok:1;
    unsigned char check_clock:1;
}ds3234_data;

/*Variables con campos de bits estructurado*/
typedef struct _DS3234_control_register {
    unsigned char A1IE : 1;// Alarm 1 Interrupt Enable
    unsigned char A2IE : 1;// Alarm 2 Interrupt Enable
    unsigned char INTCN : 1;// Interrupt Control
    unsigned char RS1 : 1;// Rate Select
    unsigned char RS2 : 1;// Rate Select
    unsigned char CONV : 1;// Convert Temperature
    unsigned char BBSQW : 1;// Batterry-Backed Square-Wave Enable
    unsigned char EOSCC : 1;// Enable Oscillator
} DS3234_control_register;

typedef struct _DS3234_control_status_register {
    unsigned char A1F : 1;// Alarm 1 Flag
    unsigned char A2F : 1;// Alarm 2 Flag
    unsigned char BSY : 1;// Busy
    unsigned char EN32kHZ : 1;// Enable 32kHz Output
    unsigned char CRATE0 : 1;// Conversion Rate
    unsigned char CRATE1 : 1;// Conversion Rate
    unsigned char BB32kHZ: 1;// Battery-Backed 32kHz Output
    unsigned char OSF : 1;// Oscillator Stop Flag
} DS3234_control_status_register;

//Definit port in mc
#define SQW_OUT PORTAbits.RA2
#define DS3234_ChepSelect PORTAbits.RA1//Definir el chip select del DS3234

/*****************************************************************************/
/* DS3234 Define address register name */
/*****************************************************************************/
#define Write           0x80
#define Seconds         0x00
#define Minutes         0x01
#define Hours           0x02
#define Day             0x03
#define Date            0x04
#define Month           0x05
#define Year            0x06
#define A1seconds       0x07
#define A1minutes       0x08
#define A1hours         0x09
#define A1daydate       0x0A
#define A2minutes       0x0B
#define A2hours         0x0C
#define A2daydate       0x0D
#define Control         0x0E
#define ControlStatus   0x0F
#define Crystal         0x10
#define TempMsb         0x11
#define TempLsb         0x12
#define DisableTempC    0x13
#define SRAMaddress     0x18
#define SRAMdata        0x19

/*****************************************************************************/
/* DS3234 Function Prototyping */
/*****************************************************************************/
void DS3234_Init(void);
void DS3234_Reset(void);
void DS3234_Read(ds3234*);
void DS3234_Write(ds3234*);

#endif// End DS3234_H