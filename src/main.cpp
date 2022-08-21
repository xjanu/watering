#include "Arduino.h"
#include "7seg.h"
#include "constants.hpp"
#include "sense.hpp"

int moist;

SegmentDisplay display{CATHODE, PINS_SEGMENT, PINS_DIGIT[0],
                       PINS_DIGIT[1], PINS_DIGIT[2], PINS_DIGIT[3]};

void setup() {
    display.set_freq(DISPLAY_FREQ);
    moist = read_moist();

    pinMode(PIN_MOIST,      INPUT);
    pinMode(PIN_PUMP,       OUTPUT);
    pinMode(PIN_POT_SENSE,  INPUT);
    pinMode(PIN_POT_PWR,    OUTPUT);
    pinMode(PIN_BUTTON,     INPUT_PULLUP);

    digitalWrite(PIN_PUMP,     LOW);
    digitalWrite(PIN_POT_PWR,  LOW);
}

void loop() {
    if (millis() % 500 == 0) {
        moist = (moist + read_moist()) / 2;
    }
    display.write_num(moist % 10000);
    display.refresh();
}
