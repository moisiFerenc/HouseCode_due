/******************************************************
 *  author: Ferenc Moisi
 * 
 *  date   : 2023. 04. 20.
 * 
 *  version: 0.1
 * 
 *  description:
 *  This is the main header file of the project.
 *  It contains the global variables and the pin definitions.
 *  
*******************************************************/



/******************************************************
 * DEBUGGER DEFINITIONS
*******************************************************/
//#define DEBUG 0
//#define DEBUG_lvl_1 1
//#define DEBUG_lvl_2 2
/******************************************************
 * DEBUGGER DEFINITIONS
*******************************************************/


/******************************************************
 * PIN DEFINITIONS
*******************************************************/




//dc motor
#define motorPin            4

//buzzer
#define buzzerPin           13
#define buzzerLEDpin        0000
//ledstrip1
#define PIN_NEO_PIXEL       11   // Arduino pin that connects to NeoPixel
#define NUM_PIXELS          4   // The number of LEDs (pixels) on NeoPixel
//led 
#define led_1_Pin           44
#define led_2_Pin           46
#define led_3_Pin           48
#define led_4_Pin           50
//button
#define button_1_Pin        47
#define button_2_Pin        49
#define button_3_Pin        50
#define button_4_Pin        52





/******************************************************
 * PIN DEFINITIONS END
*******************************************************/

/******************************************************
 * SWITCH DEFINITIONS
*******************************************************/

// message handler
#define cIPUT_door1_open                        (char)'1'
#define cIPUT_door1_close                       (char)'2'


#define cIPUT_door2_open                        (char)'3'
#define cIPUT_door2_close                       (char)'4'

#define cINPUT_ligth1_on                        (char)'5'
#define cINPUT_ligth1_off                       (char)'6'

#define cINPUT_ligth2_on                        (char)'7'
#define cINPUT_ligth2_off                       (char)'8'

#define cINPUT_ligth3_on                        (char)'9'
#define cINPUT_ligth3_off                       (char)'0'


#define cINPUT_AirCondition_on                  (char)'c'
#define cINPUT_AirCondition_off                 (char)'d'

#define cINPUT_SolarPanel_on                    (char)'a'
#define cINPUT_SolarPanel_off                   (char)'b'

#define cIPUT_buzzerA                           (char)'j'
#define cIPUT_buzzerS                           (char)'i'
#define cIPUT_buzzerD                           (char)'k'

#define cINPUT_motionSensor_ON                  (char)'l'
#define cINPUT_motionSensor_OFF                 (char)'m'
// system message
#define cIPUT_ultrasonicsensor_val              (char)'e'
#define cIPUT_temperaturesensor_celsius_val     (char)'f'
#define cIPUT_temperaturesensor_fahrenheit_val  (char)'x'
#define cIPUT_humiditiesensor_val               (char)'g'
#define cIPUT_light_val                         (char)'h'

/******************************************************
 * SWITCH DEFINITIONS END
*******************************************************/

/******************************************************
 * STATE MACHINE DEFINITIONS
*******************************************************/

// #define cINPUT_automatic_mode                   (char)'m'
// #define cINPUT_manual_mode                      (char)'n'
// #define cINPUT_diagnostic_mode                  (char)'o'
#define INT     (int)1
#define STRING  (char)2
/******************************************************
 * STATE MACHINE DEFINITIONS END
*******************************************************/