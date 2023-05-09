/******************************************************
 *  author: Ferenc Moisi
 * 
 *  date   : 2023. 04. 20.
 * 
 *  version: 0.1
 * 
 *  description:
 *  The ligth sensor heandle functions
 *  for internal ligth or solar panel calibration
 * 
*******************************************************/
#include <Arduino.h>
#include "photoseFUNC.h"


//return u_photoseFUNC_PHOTORESISTOR_VALUE value
int u_photoseFUNC_PHOTORESISTOR_VALUE(){

    int sensorValue = analogRead(photoPin);
    if(sensorValue <= 100){
        sensorValue = 1;
    }
    else if(sensorValue <= 200){
        sensorValue = 2;
    }
    else if(sensorValue <= 300){
        sensorValue = 3;
    }
    else if(sensorValue <= 400){
        sensorValue = 4;
    }
    else if(sensorValue <= 500){
        sensorValue = 5;
    }
    else if(sensorValue <= 600){
        sensorValue = 6;
    }
    else{
        sensorValue = 7;
    }
    return sensorValue;
}
//serial print u_photoseFUNC_PHOTORESISTOR_VALUE value
void V_photoseFUNC_PHOTORESISTOR_SERIAL_PRINT(){
    Serial.print("Photosesistor: ");
    Serial.println(u_photoseFUNC_PHOTORESISTOR_VALUE());
}

void vSETUP_PHOTOSE(){
    pinMode(SOLAR_SENSOR_1, INPUT);
    pinMode(SOLAR_SENSOR_2, INPUT);

    //photosesistor
    pinMode(photoPin, INPUT);
}