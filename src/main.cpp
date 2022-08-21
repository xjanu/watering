#include "Arduino.h"
#include "7seg.h"
#include "constants.hpp"
#include "sense.hpp"
#include "moist.hpp"
#include "water.hpp"

int moist;
int moist_limit;

SegmentDisplay display{CATHODE, PINS_SEGMENT, PINS_DIGIT[0],
                       PINS_DIGIT[1], PINS_DIGIT[2], PINS_DIGIT[3]};

void setup()
{
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

void loop()
{
    if (read_button()) {
        show_moist(BUTTON_LONGPRESS_MS);
        if (read_button()) {
            moist_limit = set_limit();
        } else {
            show_moist(MOIST_SHOW_MS - BUTTON_LONGPRESS_MS);
        }
    }

    moist = read_moist(moist);
    if (moist > moist_limit) {
        water();
    }

    delay(SLEEP_MS);
}
