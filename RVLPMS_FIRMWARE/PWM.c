/*
 * File:   PWM.c
 * Author: Gunnar
 *
 * Created on September 13, 2019, 10:42 PM
 */

#include <xc.h>
#include "PPS.h"

void PWM_INIT() {
    
    PPS_unlock();
  //  RC2PPS = 0x0B; //PWM3
    RC3PPS = 0x0C; //PWM6
    RC4PPS = 0x0D; //PWM7
    PPS_lock();

    PWM6CON = 0;
    PWM6DCH = 0;
    PWM6DCL = 0b00111111;
    PWM6CON = 0b10000000;
    TRISCbits.TRISC3 = 0;
    PWM6CON = 0b11110000;

    PWM7CON = 0;
    PWM7DCH = 0;
    PWM7DCL = 0b00111111;
    PWM7CON = 0b10000000;
    TRISCbits.TRISC4 = 0;
    PWM7CON = 0b11110000;        
    
    //TIMER2 setup
    T2CLKCON = 0b00000011;  //CLK is HFINTOSC     
    TMR2ON = 1;             //TMR2 ON
    T2CKPS0 = 0;            //prescaler=16
    T2CKPS1 = 0;
    T2CKPS2 = 1;
        
    T2OUTPS0 = 1;           //postscaler=16
    T2OUTPS1 = 1;
    T2OUTPS2 = 1;
    T2OUTPS3 = 1;
        
    TMR2 = 0;               //set to 0
    PR2 = 255;              //stop value
    TMR2IF = 0;             //set flag to 0    
    
}

void PWM_power_down() {
    //shutdown pwm
    PWM6DCH = 0;
    PWM7DCH = 0;            
    PWM6CONbits.EN = 0;
    PWM7CONbits.EN = 0;
    
//    RC2 = 1;
    RC3 = 1;
    RC4 = 1;      
    
    PPS_unlock();
  //  RC2PPS = 0x00; //GPIO
    RC3PPS = 0x00; //GPIO
    RC4PPS = 0x00; //GPIO
    PPS_lock();
      
}