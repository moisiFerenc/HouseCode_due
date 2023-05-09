#include "rfidFUNC.h"
#include <MFRC522.h>
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include "servoFUNC.h"

byte prevUID[4] = {0x33,0xB0,0xB4,0xB6};

MFRC522 rfid(SS_PIN, RST_PIN);
// UID read --- RFID handle
void v_rfidFUNC_DRIVER(){
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    return;

  Serial.print(F("UID: "));
  for (uint8_t i = 0; i < 4; i++) {
    Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(rfid.uid.uidByte[i], HEX);
  }
  Serial.println();
  #ifdef DEBUG  
    for (uint8_t i = 0; i< 10; i++){
        Serial.print(rfid.uid.uidByte[i]);
    }
    Serial.println();
  #endif
  rfid.PICC_HaltA(); // Stop reading

}
bool compareUIDs(byte uid1[], byte uid2[], uint8_t size) {
  for (uint8_t i = 0; i < size; i++) {
    if (uid1[i] != uid2[i]) {
      return false;
    }
  }
  return true;
}
void v_rfidFUNC_DOOR_FUNCTION(){
  if (rfid.PICC_IsNewCardPresent()) {
    if (rfid.PICC_ReadCardSerial()) {
      if (compareUIDs(rfid.uid.uidByte, prevUID, rfid.uid.size)) {
        if(u_servoFUNC_GET_STATE(cDOOR_index)){
            v_servoFUNC_OPEN(cDOOR_index);
        }else{
            v_servoFUNC_CLOSE(cDOOR_index);
        }
      } 
    
      rfid.PICC_HaltA();
      rfid.PCD_StopCrypto1();
    }
  }
}


void vRFID_SETUP(){
    SPI.begin();
    rfid.PCD_Init();
}