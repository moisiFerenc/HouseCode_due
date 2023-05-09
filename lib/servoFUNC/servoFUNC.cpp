/******************************************************
 *  author: Ferenc Moisi
 * 
 *  date   : 2023. 05. 01.
 * 
 *  version: 0.2
 * 
 *  description:
 *  This file is responsibel for servo movments 
 *  exp: Door lock/unlock or window lock/unlock
 * 
*******************************************************/

#include <Servo.h>
#include <Arduino.h>
#include "servoFUNC.h"
#include "main.cpp"

//Door servo motor
Servo sDOOR_servo;
//Garage servo motor
Servo sGARAGE_servo;
//Solar servo motor
Servo sSOLAR_servo;
// servo pos
int pos =0;

bool bDOOR_state    = false;
bool bGARAGE_state  = false;
bool bSOLAR_state   = false;

uint8_t u_servoFUNC_GET_STATE(char index){
    switch (index)
    {
    case cDOOR_index:
        return bDOOR_state;

    case cGUARAGE_index:
        return bGARAGE_state;

    case cSOLAR_index:
        return bSOLAR_state;

    default:
        break;
    }
}

void vSERVO_SETUP(){
    //servo
    sDOOR_servo.attach(servoDOORPin, -40, 90);
    pinMode(servoDOORPin, OUTPUT);


    sGARAGE_servo.attach(servoGARAGEPin, 0,90);
    pinMode(servoGARAGEPin, OUTPUT);

    sSOLAR_servo.attach(sSOLAR_servoPIN);
    pinMode(sSOLAR_servoPIN, OUTPUT);
}


void v_servoFUNC_OPEN(char index){
    switch (index)
    {
    case cDOOR_index:
        Serial.println("1. Open Servo");
        bDOOR_state = true;
        sDOOR_servo.write(90);    
        break;
    case cGUARAGE_index:
        Serial.println("1. Open garage");
        bGARAGE_state = true;
        sGARAGE_servo.write(90);    
        break;
    case cSOLAR_index:
        Serial.println("solar panel");
        break;
    default:
        break;
    }
}

void v_servoFUNC_CLOSE(char index){

    switch (index)
    {
    case cDOOR_index:
        Serial.println("1. Close Servo");
        bDOOR_state = true;
        sDOOR_servo.write(-20);    
        break;
    case cGUARAGE_index:
        Serial.println("1. Close garage");
        bGARAGE_state = true;
        sGARAGE_servo.write(-20);    
        break;
    case cSOLAR_index:
        Serial.println("solar panel");
        break;
    default:
        break;
    }

}