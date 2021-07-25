/*
 * File:   ADC.c
 * Author: Gunnar
 *
 * Created on September 14, 2019, 11:34 AM
 */

#include <xc.h>
#include "PICCONFIG.h"

unsigned int readADC(char channel) {

    ADCLKbits.CS = 31; // ADCLK is FOSC/64
    ADCON0bits.ON = 1;
    ADPCH = channel;
    
    __delay_ms(5); //sampling time
    
    ADCON0bits.GO_nDONE = 1; //begin ADC
    while (ADCON0bits.GO_nDONE); //wait for conversion to complete
    
    //return ((ADRESH << 6) | (ADRESL >> 2)); //Returns 8-bit result
    return ADRESH; //return upper 8bits 
}