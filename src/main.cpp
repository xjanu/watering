#include "Arduino.h"
#include "7seg.h"
#include "pins.hpp"

int moist;

SegmentDisplay display{CATHODE, PINS_SEGMENT, PINS_DIGIT[0],
                       PINS_DIGIT[1], PINS_DIGIT[2], PINS_DIGIT[3]};

void setup() {
    display.set_freq(DISPLAY_FREQ);
    moist = analogRead(PIN_MOIST);

    pinMode(PIN_PUMP, OUTPUT);
    pinMode(PIN_POT_PWR, OUTPUT);
    pinMode(PIN_BUTTON, INPUT_PULLUP);

    digitalWrite(PIN_PUMP, LOW);
    digitalWrite(PIN_POT_PWR, LOW);
}

void loop() {
    if (millis() % 500 == 0) {
        moist = (moist + analogRead(PIN_MOIST)) / 2;
    }
    display.write_num(moist % 10000);
    display.refresh();
}
