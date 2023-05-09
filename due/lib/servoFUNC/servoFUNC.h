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
#ifndef SERVOFUNC_DOT_H    
#define SERVOFUNC_DOT_H 


//servo
#define servoDOORPin        7
#define servoGARAGEPin      8
#define sSOLAR_servoPIN     17

#define cDOOR_index         '1'
#define cGUARAGE_index      '2'
#define cSOLAR_index        '3'


void    v_servoFUNC_OPEN(char index);
void    v_servoFUNC_CLOSE(char index);
uint8_t u_servoFUNC_GET_STATE(char index);

void vSERVO_SETUP();

#endif