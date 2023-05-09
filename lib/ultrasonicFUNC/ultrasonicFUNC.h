/******************************************************
 *  author: Ferenc Moisi
 * 
 *  date   : 2023. 04. 20.
 * 
 *  version: 0.1
 * 
 *  description:
 *  HEADER file for untrasonic sensor functions
 *  
 *  
 * 
*******************************************************/
#ifndef ULTRASONICFUNC_DOT_H    
#define ULTRASONICFUNC_DOT_H 


//ultrasonic sensor
#define trigPin             3
#define echoPin             2


uint8_t ultrasonic_sensor();
void ultrasonic_sensor_print();
void vULTRASONIC_SETUP();


#endif