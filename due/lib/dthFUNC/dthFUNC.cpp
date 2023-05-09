/******************************************************
 *  author: Ferenc Moisi
 * 
 *  date   : 2023. 04. 20.
 * 
 *  version: 0.1
 * 
 *  description:
 *  The temperature and humidity sensor
 * 
*******************************************************/
#include "dthFUNC.h"
#include <DHT.h>
#include <Arduino.h>

// dth11
DHT dht(dht11_pin, DHTTYPE);




//return temperature sensor value in celsius
float f_dthFUNC_TEMPERATURE_VALUE(){
    //read dht11 sensor
    float t = dht.readTemperature();
    
    return t;
}
//return temperature sensor value in fahrenheit
float f_dthFUNC_TEMPERATURE_VALUE_FARENHEIT(){
    float temperatureC = f_dthFUNC_TEMPERATURE_VALUE();
    float temperatureF = (temperatureC * 9 / 5) + 32;

    return temperatureF;
}
//serial print temperature sensor value 
void f_dthFUNC_TEMPERATURE_VALUE_SERIAL_PRINT(float value){
    Serial.print("Temperature: ");
    Serial.println(value);
}

// return humidity sensor value
float f_dthFUNC_HUMIDITY_VALUE(){
    float h = dht.readHumidity();
    return h;
}
//serial print humidity sensor value
void f_dthFUNC_HUMIDITY_VALUE_SERIAL_PRINT(){
    Serial.print("Humidity: ");
    Serial.println(f_dthFUNC_HUMIDITY_VALUE());
}

void vSETUP_DTH(){
    pinMode(dht11_pin, INPUT);
    dht.begin();
}