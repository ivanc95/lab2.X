#include <xc.h>
#include "keypad.h"
#include "timer.h"

/* Initialize the rows as ODC outputs and the columns as inputs with pull-up
 * resistors. Don't forget about other considerations...
 */

#define ROW_1 LATGbits.LATG0
#define ROW_2 LATFbits.LATF1
#define ROW_3 LATDbits.LATD12
#define ROW_4 LATDbits.LATD6

#define COL_1 PORTEbits.RE7
#define COL_2 PORTEbits.RE5
#define COL_3 PORTEbits.RE3

/* Pins used for the key pad
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
    
    int pressed = 0;
    
    //Scan Row 1
    ROW_1 = 1; ROW_2 = 0; ROW_3 = 0; ROW_4 = 0;
    
    if(COL_1 == 0){
        key = '1';
        pressed++;
    }
    if(COL_2 == 0){
        key = '2';
        pressed++;
    }
    if(COL_3 == 0){
        key = '3';
        pressed++;
    }
    if(pressed > 1){
        return -1;
    }
    
    //Scan Row 2
    ROW_1 = 0; ROW_2 = 1; ROW_3 = 0; ROW_4 = 0;
    
    if(COL_1 == 0){
        key = '4';
        pressed++;
    }
    if(COL_2 == 0){
        key = '5';
        pressed++;
    }
    if(COL_3 == 0){
        key = '6';
        pressed++;
    }
    if(pressed > 1){
        return -1;
    }
    
    //Scan Row 3
    ROW_1 = 0; ROW_2 = 0; ROW_3 = 1; ROW_4 = 0;
    
    if(COL_1 == 0){
        key = '7';
        pressed++;
    }
    if(COL_2 == 0){
        key = '8';
        pressed++;
    }
    if(COL_3 == 0){
        key = '9';
        pressed++;
    }
    if(pressed > 1){
        return -1;
    }
    
    //Scan Row 4
    ROW_1 = 0; ROW_2 = 0; ROW_3 = 0; ROW_4 = 1;
    
    if(COL_1 == 0){
        key = '*';
        pressed++;
    }
    if(COL_2 == 0){
        key = '0';
        pressed++;
    }
    if(COL_3 == 0){
        key = '#';
        pressed++;
    }
    if(pressed > 1){
        return -1;
    }
    
    return key;
    
}