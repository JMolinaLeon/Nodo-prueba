#include "ds3234.h"
/*****************************************************************************/
/* DS3234 Functions */
/*****************************************************************************/

/* Configure the DS3234 */
void DS3234_Init(void){ 
    DS3234_control_register config;
    *((unsigned char *) & config) = 0;
    config.A1IE = 0;// Alarm 1 Interrupt Disable
    config.A2IE = 0;// Alarm 2 Interrupt Disable
    config.INTCN = 0;//Square wave enable
    config.RS1 = 0;// RS1 y RS2 frecuency squiare wave 00->1Hz
    config.RS2 = 0;// RS1 y RS2 frecuency squiare wave 00->1Hz

    DS3234_ChepSelect = 0;// Habilitamos dispositivo SPI1 
    SPI1_Exchange_Byte(Write | Control);
    SPI1_Exchange_Byte(config);
    DS3234_ChepSelect = 1;// Deshabilitamos dispositivo SPI1

}

void DS3234_Read(ds3234_data *p){
    DS3234_ChepSelect = 0;
    /* Para leer solo necesitamos mandar el mapa de direcciones
        como indica el datasheet */
    p->seconds = SPI1_Exchange_Byte(Seconds);
    p->minutes = SPI1_Exchange_Byte(Minutes);
    p->hours = SPI1_Exchange_Byte(Hours);
    p->day_of_week = SPI1_Exchange_Byte(Day);
    p->date = SPI1_Exchange_Byte(Date);
    p->month = SPI1_Exchange_Byte(Month)
    p->year = SPI1_Exchange_Byte(Year)

    DS3234_ChepSelect = 1;
}//End Read

void DS3234_Write(ds3234_data *p){
    DS3234_ChepSelect = 0;
    /* Para Escribir agregamos 0x80 al mapa de direcciones del datasheet */
    SPI1_Exchange_Byte(Write | Seconds);
    SPI1_Exchange_Byte(p->seconds);
    SPI1_Exchange_Byte(Write | Minutes);
    SPI1_Exchange_Byte(p->minutes)
    SPI1_Exchange_Byte(Write | Hours);
    SPI1_Exchange_Byte(p->hours);
    SPI1_Exchange_Byte(Write | Day);
    SPI1_Exchange_Byte(p->day_of_week);
    SPI1_Exchange_Byte(Write | Date);
    SPI1_Exchange_Byte(p->date)
    SPI1_Exchange_Byte(Write | Month)
    SPI1_Exchange_Byte(p->month);
    SPI1_Exchange_Byte(Write | Year)
    SPI1_Exchange_Byte(p->year);
    DS3234_ChepSelect = 1;
}// End Write

DS3234_control_status_register DS3234_Status(void){
    DS3234_control_status_register status;
    *((unsigned char *) & status) = 0;
    DS3234_ChepSelect = 0;
    status = SPI1_Exchange_Byte(ControlStatus);
    DS3234_ChepSelect = 1;
}