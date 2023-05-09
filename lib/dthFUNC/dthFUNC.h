/******************************************************
 *  author: Ferenc Moisi
 * 
 *  date   : 2023. 05. 01.
 * 
 *  version: 0.2
 * 
 *  description:
 *  This file is the header file for DTH11
 * 
*******************************************************/
#ifndef DTHFUNC_DOT_H    
#define DTHFUNC_DOT_H

#define dht11_pin           A1
#define DHTTYPE             DHT11

float   f_dthFUNC_TEMPERATURE_VALUE();
float   f_dthFUNC_TEMPERATURE_VALUE_FARENHEIT();
void    f_dthFUNC_TEMPERATURE_VALUE_SERIAL_PRINT(float value);
float   f_dthFUNC_HUMIDITY_VALUE();
void    f_dthFUNC_HUMIDITY_VALUE_SERIAL_PRINT();

void    vSETUP_DTH();


#endif