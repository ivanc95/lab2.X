#include <xc.h>
#include "keypad.h"
#include "timer.h"

/* Initialize the rows as ODC outputs and the columns as inputs with pull-up
 * resistors. Don't forget about other considerations...
 */

/* The pins used for the key pad
 * COL_1      RE7
 * COL_2      RE5
 * COL_2      RE3
 * ROW_1      RG0
 * ROW_2      RF1
 * ROW_3      RD12
 * ROW_4      RD6
 */
void initKeypad(void){
    
    //Initialize Column Tristates
    TRISEbits.TRISE7 = 1;
    TRISEbits.TRISE5 = 1;
    TRISEbits.TRISE3 = 1;
    
    //Initialize Column Pull-Ups
    CNPUEbits.CNPUE7 = 1;
    CNPUEbits.CNPUE5 = 1;
    CNPUEbits.CNPUE3 = 1;
    
    //Turn on CN for port E
    CNCONEbits.ON = 1;
    
    //Enable CN Interrupt for each pin
    CNENEbits.CNIEE7 = 1;
    CNENEbits.CNIEE5 = 1;
    CNENEbits.CNIEE3 = 1;
    
    IFS1bits.CNEIF = 0;
    IEC1bits.CNEIE = 1;
    IPC8bits.CNIP = 7;
    
    //Initialize Row Tristates
    TRISGbits.TRISG0 = 0;
    TRISFbits.TRISF1 = 0;
    TRISDbits.TRISD12 = 0;
    TRISDbits.TRISD6 = 0;
    
    //Initialize ODC for row pins
    ODCGbits.ODCG0 = 1;
    ODCFbits.ODCF1 = 1;
    ODCDbits.ODCD12 = 1;
    ODCDbits.ODCD6 = 1;
}

/* This function will be called AFTER you have determined that someone pressed
 * SOME key. This function is to figure out WHICH key has been pressed.
 * This function should return -1 if more than one key is pressed or if
 * no key is pressed at all. Otherwise, it should return the ASCII character of
 * the key that is pressed. The ascii character c programmatically is just 'c'
 */
char scanKeypad(void){
    char key = -1;
    
    return key;
    
    
}