#include <stdio.h>

int bcd_to_decimal(unsigned char x) {
    return x - 6 * (x >> 4);
}

int main(){
    unsigned char vBcd = 0;
    int cBCD = 0;

    vBcd = 0x5a9;
    printf("Hexadecimal: 0x%x\n",vBcd);
    
    cBCD = bcd_to_decimal(vBcd);
    printf("Decimal:%d\n",cBCD);
    
    return 0;
}