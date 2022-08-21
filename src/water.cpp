#include "Arduino.h"
#include "water.hpp"
#include "constants.hpp"

int last_watered = 0;

void water()
{
    if (millis() - last_watered > WATER_MIN_OFF_MS) {
        digitalWrite(PIN_PUMP, HIGH);
        delay(WATER_ON_MS);
        digitalWrite(PIN_PUMP, LOW);
        last_watered = millis();
    }
}
