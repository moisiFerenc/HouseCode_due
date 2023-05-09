/******************************************************
 *  author: Ferenc Moisi
 * 
 *  date   : 2023. 05. 01.
 * 
 *  version: 0.2
 * 
 *  description:
 *  This file is the header file for servo functionality
 * 
*******************************************************/
#ifndef RFIDFUNC_DOT_H    
#define RFIDFUNC_DOT_H 

//RFID module
#define RST_PIN   9     // Reset pin (D7)
#define SS_PIN    10    // Slave Select pin (D10)


void v_rfidFUNC_DRIVER();
void v_rfidFUNC_DOOR_FUNCTION();

void vRFID_SETUP();

#endif