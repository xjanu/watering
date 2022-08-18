#include "Arduino.h"
#include "deps/7seg/7seg.h"

const int segment_pins[8] = {2, 5, 8, 10, 11, 3, 9, A5};
const int digit_pins[4]   = {A4, 6, 7, 4};
const int display_freq    = 300;

const int moist_sensor_pin = A0;
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
