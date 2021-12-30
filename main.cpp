#include "Arduino.h"
#include "deps/7seg/7seg.h"

const int segment_pins[8] = {6, 4, A0, 12, 11, 5, A1, 13};
const int digit_pins[4]   = {10, 7, 8, 9};
const int display_freq    = 300;

const int moist_sensor_pin = A3;
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
