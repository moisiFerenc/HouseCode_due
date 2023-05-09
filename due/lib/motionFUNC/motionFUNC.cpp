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
#include "motionFUNC.h"
#include <Arduino.h>

//motion ON or OFF
bool bMotion_state  = false;

void u_motionFUNC_MOTION_DETECTION__on_off(char a){
    switch (a)
    {
    case ON:
        bMotion_state = true;
        break;
    case OFF:
        bMotion_state = false;
        break;
    
    default:
        break;
    }
}

//motion sensor
int u_motionFUNC_MOTION_DETECTION(){
    if(bMotion_state){
        if(digitalRead(motionSensorPin) == HIGH){
            //Serial.println("Motion Detected");
            //analogWrite(buzzerPin, 100);
            //delay(10000);
            //analogWrite(buzzerPin, 0);
            return 1;
        }
        else{
            //Serial.println("No Motion Detected");
            return 0;
        }
    }
    else{
        return 3;
    }
}



void vMOTIONSENSOR_SETUP(){
    pinMode(motionSensorPin, INPUT);
}