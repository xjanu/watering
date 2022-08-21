#include "Arduino.h"
#include "sense.hpp"
#include "constants.hpp"

int read_moist()
{
    return analogRead(PIN_MOIST);
}

int read_moist(int current)
{
    return (current + analogRead(PIN_MOIST)) / 2;
}

int read_pot()
{
    digitalWrite(PIN_POT_PWR, HIGH);
    int result = analogRead(PIN_POT_SENSE);
    digitalWrite(PIN_POT_PWR, LOW);
    return result;
}

bool read_button()
{
    return (digitalRead(PIN_BUTTON) == HIGH) ? false : true;
}
