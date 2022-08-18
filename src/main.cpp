#include "Arduino.h"
#include "7seg.h"
#include "pins.hpp"

int moist;

SegmentDisplay display{CATHODE, segment_pins, digit_pins[0],
                       digit_pins[1], digit_pins[2], digit_pins[3]};

void setup() {
    display.set_freq(display_freq);
    moist = analogRead(moist_sensor_pin);
}

void loop() {
    if (millis() % 500 == 0) {
        moist = (moist + analogRead(moist_sensor_pin)) / 2;
    }
    display.write_num(moist % 10000);
    display.refresh();
}
