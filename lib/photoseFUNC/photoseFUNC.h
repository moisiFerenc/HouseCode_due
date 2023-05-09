/******************************************************
 *  author: Ferenc Moisi
 * 
 *  date   : 2023. 05. 01.
 * 
 *  version: 0.2
 * 
 *  description:
 *  This file is the header file for photoresistor sensor
 * 
*******************************************************/
#ifndef PHOTOSEFUNC_DOT_H    
#define PHOTOSEFUNC_DOT_H

//photosesistor
#define photoPin            A0
//solar panel
#define SOLAR_SENSOR_1      A6
#define SOLAR_SENSOR_2      A7


int  u_photoseFUNC_PHOTORESISTOR_VALUE();
void V_photoseFUNC_PHOTORESISTOR_SERIAL_PRINT();

void vSETUP_PHOTOSE();

#endif