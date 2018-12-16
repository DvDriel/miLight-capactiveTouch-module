#include <Arduino.h>
#include <Milight.h>
#include "../include/defines.h"

Milight Milight;

uint16_t sensorValues[SENSORS];
char sensorPins[SENSORS] = {TOUCH_CENTER, TOUCH_RING1, TOUCH_RING2, TOUCH_RING3};
uint8_t brightness;

uint16_t buff(char);
void getSensorValues();
void printSensorValues();
void checkSensorInput();

void setup() {
    Serial.begin(115200);
    Serial.println();

    Milight.begin("UPC9486202", "LNRYWFSH");

    // // Interval between commands
    Milight.setCommandInterval(20);

    // // The extremeness of the brightness curve
    Milight.setBrightnessCurve(2);
}

void loop() {
    getSensorValues();
    printSensorValues();
    checkSensorInput();
    Milight.run();
}

uint16_t buff(char pin) {
  uint16_t out = (50 - touchRead(pin));
  if(out > 0) return (out + 2);
  else return 0;
}

void getSensorValues() {
    for(int i=0; i<SENSORS; i++) {
        sensorValues[i] = buff(sensorPins[i]);
    }
}

void printSensorValues() {
    Serial.print(buff(TOUCH_CENTER));
    Serial.print("\t");
    Serial.print(buff(TOUCH_RING1));
    Serial.print("\t");
    Serial.print(buff(TOUCH_RING2));
    Serial.print("\t");
    Serial.println(buff(TOUCH_RING3));
//     Serial.print(sensorValues[0]);
//     Serial.print("\t");
//     Serial.print(sensorValues[1]);
//     Serial.print("\t");
//     Serial.print(sensorValues[2]);
//     Serial.print("\t");
//     Serial.println(sensorValues[3]);
}

void checkSensorInput() {
    if(sensorValues[0] >= THRESHHOLD && sensorValues[0] < 100) {
        Milight.brightness(brightness, 1);
        if(brightness > 0) {
            brightness = 0;
        } else {
            brightness = 255;
        }
    }
}