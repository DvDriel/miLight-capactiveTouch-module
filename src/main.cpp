#include <Arduino.h>
#include <Milight.h>

Milight Milight;

void setup() {
    Serial.begin(115200);
    Serial.println();

    Milight.begin("UPC9486202", "LNRYWFSH");

    // Interval between commands
    Milight.setCommandInterval(20);

    // The extremeness of the brightness curve
    Milight.setBrightnessCurve(2);
}

void loop() {
    // Milight.brightness(0, 0);
    // delay(1000);
    // Milight.brightness(255, 0);
    // delay(1000);
    //Milight.on(group);
    // Milight.off(1);
    // delay(1000);
    // Milight.on(1);
    // delay(1000);
    //Milight.hue(value, group);
    //Milight.white(group); 
    //Milight.saturation(value, group);

    Milight.run();
}
