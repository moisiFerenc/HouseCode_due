/******************************************************
 *  author: Ferenc Moisi
 * 
 *  date   : 2023. 04. 20.
 * 
 *  version: 0.1
 * 
 *  description:
 *  The ultrasonic sensor heandle functions
 *  This sensor is responible for door state tracking , and can trigger an emergency
 *  
 * 
*******************************************************/
#include <Arduino.h>
#include "ultrasonicFUNC.h"



//return ultrasonic sensor value
uint8_t ultrasonic_sensor(){
    long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;

    if(distance <= 30){
        distance = 1;
    }
    else if(distance <= 60){
        distance = 2;
    }
    else if(distance <= 90){
        distance = 3;
    }
    else if(distance <= 120){
        distance = 4;
    }
    else if(distance <= 150){
        distance = 5;
    }
    else if(distance <= 180){
        distance = 6;
    }
    else{
        distance = 7;
    }



    return distance;
}

//serial print ultrasonic sensor value
void ultrasonic_sensor_print(){
    Serial.print("Distance: ");
    Serial.println(ultrasonic_sensor());
}

void vULTRASONIC_SETUP(){
    //ultrasonic sensor 
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}