#include <Arduino.h>
#include <Milight.h>
#include "../include/defines.h"

Milight Milight;

int buff(int);

void setup() {
    Serial.begin(115200);
    Serial.println();

    // Milight.begin("UPC9486202", "LNRYWFSH");

    // // Interval between commands
    // Milight.setCommandInterval(20);

    // // The extremeness of the brightness curve
    // Milight.setBrightnessCurve(2);
}

void loop() {
    Serial.print(buff(TOUCH_CENTER));
    Serial.print("\t");
    Serial.print(buff(TOUCH_RING1));
    Serial.print("\t");
    Serial.print(buff(TOUCH_RING2));
    Serial.print("\t");
    Serial.println(buff(TOUCH_RING3));
    // Milight.run();
}

int buff(int pin) {
  int out = (50 - touchRead(pin));
  if(out > 0) return (out + 2);
  else return 0;
}