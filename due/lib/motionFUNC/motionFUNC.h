/******************************************************
 *  author: Ferenc Moisi
 * 
 *  date   : 2023. 05. 01.
 * 
 *  version: 0.2
 * 
 *  description:
 *  This file is the header file for motion sensor alert
 * 
*******************************************************/
#ifndef MOTIONFUNC_DOT_H    
#define MOTIONFUNC_DOT_H 

#define motionSensorPin     A5

#define ON  '1'
#define OFF '0'


void u_motionFUNC_MOTION_DETECTION__on_off(char a);
int u_motionFUNC_MOTION_DETECTION();

void vMOTIONSENSOR_SETUP();



#endif