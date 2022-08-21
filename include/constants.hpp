#pragma once

#include "Arduino.h"

// 7seg display
const int PINS_SEGMENT[8] = {2, 5, 8, 10, 11, 3, 9, A5};
const int PINS_DIGIT[4]   = {A4, 6, 7, 4};
const int DISPLAY_FREQ    = 300;

// Other pins
/* TODO: Check pins */
const int PIN_MOIST     = A0;
const int PIN_PUMP      = 13;
const int PIN_POT_SENSE = A1;
const int PIN_POT_PWR   = A2;
const int PIN_BUTTON    = A3;
