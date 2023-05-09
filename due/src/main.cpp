/******************************************************
 *  author: Ferenc Moisi
 * 
 *  date   : 2023. 04. 20.
 * 
 *  version: 0.1
 * 
 *  description:
 *  This is the main file of the project.
 *  It contains the main function and the global variables.
 *  It also contains the function declarations.
 *  
 *  
 * 
*******************************************************/

#include <Servo.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#include <SPI.h>
#include <Wire.h>
#include "main.h"
#include <DHT.h>
#include <string.h>  
#include <Adafruit_Sensor.h>
//#include <TFT_eSPI.h> 
#include <Arduino.h>

#include <MFRC522.h>
#include "servoFUNC.h" 
#include "ultrasonicFUNC.h"
#include "photoseFUNC.h"
#include "dthFUNC.h"
#include "rfidFUNC.h"
#include "motionFUNC.h"
#include "HMI.h"

/******************************************************
 * global variables
*******************************************************/


///RX BUFFER FROM SERIAL
int rxBuffer = 0;

// solar panel state
u_int8_t solarPanelState = 90;
u_int8_t solarSENSOR1= 0;
u_int8_t solarSENSOR2= 0;
// Air conditioner state FLAG
bool airConditionerState = false;
// light state FLAG
bool bLamp_1_state  = false;
bool bLamp_2_state  = false;
bool bLamp_3_state  = false;



bool dSOLAR_state   = false;



//led flag
bool bLED_1_state   = false;
bool bLED_2_state   = false;
bool bLED_3_state   = false;
bool bLED_4_state   = false;

//button state
bool buttonState1       = false;
bool buttonState1_old   = false;
bool buttonState2       = false;
bool buttonState2_old   = false;
bool buttonState3       = false;
bool buttonState3_old   = false;
bool buttonState4       = false;
bool buttonState4_old   = false;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;




/******************************************************
 * global variables END
*******************************************************/

/******************************************************
 * FUNCTION DECLARATIONS
*******************************************************/




//solar panel
void solar_panel(){
    //solar panel sun tracking system
    solarSENSOR1 = analogRead(SOLAR_SENSOR_1);
    solarSENSOR2 = analogRead(SOLAR_SENSOR_2);

    if(solarSENSOR1 > solarSENSOR2){
        solarPanelState = solarPanelState + 1;
        if(solarPanelState > 180){
            solarPanelState = 180;
        }
    }
    else if(solarSENSOR1 < solarSENSOR2){
        solarPanelState = solarPanelState - 1;
        if(solarPanelState < 0){
            solarPanelState = 0;
        }
    }
    else{
        solarPanelState = solarPanelState;
    }
    //sSOLAR_servo.write(solarPanelState);

    
}


//led control
void vLEDcontrol(){
int reading = digitalRead(button_1_Pin);

  // ha a gomb állapota változott
  if (reading != buttonState1_old) {
    // frissítjük a gomb állapotát
    lastDebounceTime = millis();
  }

  // ha az eltelt idő meghaladja a debounceDelay értékét
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // ha a gomb állapota változott
    if (reading != buttonState1) {
      buttonState1 = reading;
      // ha a gombot megnyomták
      if (buttonState1 == LOW) {
        // váltunk a LED állapotának
        bLED_1_state = !bLED_1_state;
        // beállítjuk a LED lábát az új állapotnak megfelelően

      }
    }
  }

  // eltároljuk az aktuális gomb állapotát
  buttonState1_old = reading;

}


/******************************************************
 * SYSTEM FUNCTIONS
*******************************************************/
void setup() {
    vSERVO_SETUP();
    vULTRASONIC_SETUP();
    vSETUP_PHOTOSE();
    vSETUP_DTH();
    vRFID_SETUP();
    vMOTIONSENSOR_SETUP();
    vHMI_SETUP();

    //dc motor
    pinMode(motorPin, OUTPUT);

    //buzzer
    pinMode(buzzerPin, OUTPUT);


    //led
    pinMode(button_1_Pin, INPUT_PULLUP);
    pinMode(button_2_Pin, INPUT_PULLUP);
    pinMode(button_3_Pin, INPUT_PULLUP);
    pinMode(button_4_Pin, INPUT_PULLUP);

    pinMode(led_1_Pin, OUTPUT);
    pinMode(led_2_Pin, OUTPUT);
    pinMode(led_3_Pin, OUTPUT);
    pinMode(led_4_Pin, OUTPUT);

    Serial.begin(9600);


}

void loop() {
   
    // **************amtomatic mode**************
    // AUTO AC
    if(f_dthFUNC_TEMPERATURE_VALUE() > 25){
        digitalWrite(motorPin, HIGH);
    }
    else if(f_dthFUNC_TEMPERATURE_VALUE() < 25 && airConditionerState){
        digitalWrite(motorPin, LOW);
    }
    // AUTO SOLAR PANEL
    solar_panel();
    // AUTO LIGHTS
    if(u_photoseFUNC_PHOTORESISTOR_VALUE() < 100){
        digitalWrite(led_1_Pin, HIGH);
    }
    else if(u_photoseFUNC_PHOTORESISTOR_VALUE() > 100 && bLamp_1_state && bLamp_2_state && bLamp_3_state){ 
        digitalWrite(led_1_Pin, LOW);
    }

    //led   
    vLEDcontrol();
    digitalWrite(led_1_Pin, bLED_1_state);

    //RIFD function call
    #ifdef DEBUG_lvl_1
    v_rfidFUNC_DRIVER();
    #endif
    v_rfidFUNC_DOOR_FUNCTION();
    // rx buffer
    rxBuffer = Serial.read();

    // switch case
    switch(rxBuffer){
        case cIPUT_door1_open:
            v_servoFUNC_OPEN(cDOOR_index);
            break;

        case cIPUT_door1_close:
           v_servoFUNC_CLOSE(cDOOR_index);
        break;

        case cIPUT_door2_open:
            v_servoFUNC_OPEN(cGUARAGE_index);
            break;

        case cIPUT_door2_close:
            v_servoFUNC_CLOSE(cGUARAGE_index);
            break;

        case cINPUT_ligth1_on:
            Serial.println("5. Turn on Light 1");
            //led_1_Pin turn on
            bLamp_1_state = true;
            digitalWrite(led_1_Pin, HIGH);  
            break;

        case cINPUT_ligth1_off:
            Serial.println("6. Turn off Light 1");
            //led_1_Pin turn off
            bLamp_1_state = false;
            digitalWrite(led_1_Pin, LOW);
            break;

        case cINPUT_ligth2_on:
            Serial.println("7. Turn on Light 2");
            //led_2_Pin turn on
            bLamp_2_state = true;
            digitalWrite(led_2_Pin, HIGH);  
            break;

        case cINPUT_ligth2_off:
            Serial.println("8. Turn off Light 2");
            //led_2_Pin turn off
            bLamp_2_state = false;
            digitalWrite(led_2_Pin, LOW);
            break;

        case cINPUT_ligth3_on:
            Serial.println("9. Turn on Light 3");
            //led_3_Pin turn on
            bLamp_3_state = true;
            digitalWrite(led_3_Pin, HIGH); 
            break;

        case cINPUT_ligth3_off:
            Serial.println("10. Turn off Light 3");
            //led_3_Pin turn off
            bLamp_3_state = false;
            digitalWrite(led_3_Pin, LOW);
            break;

        case cINPUT_AirCondition_on:
            Serial.println("13. Turn on Air Condition");
            airConditionerState = true;
            digitalWrite(motorPin, HIGH);
            break;

        case cINPUT_AirCondition_off:
            Serial.println("14. Turn off Air Condition");
            airConditionerState = false;
            digitalWrite(motorPin, LOW);
            break;
        
        case cIPUT_ultrasonicsensor_val:
            Serial.println("Ultrasonic Sensor");
            ultrasonic_sensor_print();
            break;
        case cIPUT_light_val:
            Serial.println("Photosesistor");
            V_photoseFUNC_PHOTORESISTOR_SERIAL_PRINT();
            break;
        case cIPUT_temperaturesensor_celsius_val:
            Serial.println("Temperature Sensor Celsius");
            f_dthFUNC_TEMPERATURE_VALUE_SERIAL_PRINT(f_dthFUNC_TEMPERATURE_VALUE());
            break;
        case cIPUT_temperaturesensor_fahrenheit_val:
            Serial.println("Temperature Sensor Fahrenheit");
            f_dthFUNC_TEMPERATURE_VALUE_SERIAL_PRINT(f_dthFUNC_TEMPERATURE_VALUE_FARENHEIT());
            break;
        case cIPUT_humiditiesensor_val:
            Serial.println("Humidity Sensor");
            f_dthFUNC_HUMIDITY_VALUE_SERIAL_PRINT();
            break;
        case cIPUT_buzzerA:
            Serial.println("Buzzer A");
            analogWrite(buzzerPin, 100);
            delay(1000);
            analogWrite(buzzerPin, 0);
            break;
        case cIPUT_buzzerS:
            Serial.println("Buzzer S");
            analogWrite(buzzerPin, 100);
            delay(50);
            analogWrite(buzzerPin, 0);
            delay(50);
            analogWrite(buzzerPin, 100);
            delay(50);
            analogWrite(buzzerPin, 0);
            delay(50);
            analogWrite(buzzerPin, 100);
            delay(50);
            analogWrite(buzzerPin, 0);
            delay(500);
            analogWrite(buzzerPin, 100);
            delay(50);
            analogWrite(buzzerPin, 0);
            delay(50);
            analogWrite(buzzerPin, 100);
            delay(50);
            analogWrite(buzzerPin, 0);

            break;
        case cINPUT_motionSensor_ON:
            Serial.println("Motion Sensor ON--ACTIVE");
            u_motionFUNC_MOTION_DETECTION__on_off(ON);
            break;
        case cINPUT_motionSensor_OFF:
            Serial.println("Motion Sensor OFF--INACTIVE");
            u_motionFUNC_MOTION_DETECTION__on_off(OFF);
            break;

        case cIPUT_buzzerD:
            Serial.println("Buzzer D");
            analogWrite(buzzerPin, 100);
            delay(2000);
            analogWrite(buzzerPin, 0);
            break;

        default:
            break;
        }

   
    Serial.print(ultrasonic_sensor());
    Serial.print("--");
    Serial.print(u_photoseFUNC_PHOTORESISTOR_VALUE());
    Serial.print("--");
    Serial.print((u_int8_t)f_dthFUNC_TEMPERATURE_VALUE());
    Serial.print("--");
    Serial.print((u_int8_t)f_dthFUNC_HUMIDITY_VALUE());
    Serial.print("--");
    Serial.print(11);
    Serial.print("--");
    Serial.print(bLamp_1_state);
    Serial.print("--");
    Serial.print(bLamp_2_state);
    Serial.print("--");
    Serial.print(bLamp_3_state);
    Serial.print("--");
    Serial.print(airConditionerState);
    Serial.print("--");
    Serial.print(u_servoFUNC_GET_STATE('1'));
    Serial.print("--");
    Serial.print(u_servoFUNC_GET_STATE('2'));
    Serial.print("--");
    Serial.print(u_servoFUNC_GET_STATE('3'));
    Serial.print("--");
    Serial.println(u_motionFUNC_MOTION_DETECTION());
    
   
}
// /******************************************************
//  * SYSTEM FUNCTIONS END
// *******************************************************/

