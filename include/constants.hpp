#pragma once

#include <Arduino.h>

// Pins
const int PINS_SEGMENT[8] = {2, 5, 8, 10, 11, 3, 9, A5};
const int PINS_DIGIT[4]   = {A4, 6, 7, 4};

/* TODO: Check pins */
const int PIN_MOIST     = A0;
const int PIN_PUMP      = 13;
const int PIN_POT_SENSE = A1;
const int PIN_POT_PWR   = A2;
const int PIN_BUTTON    = A3;

// Delays
const int DISPLAY_FREQ = 300;

const int SLEEP_MS = 20;
const int BUTTON_LONGPRESS_MS = 300;
const int MOIST_SHOW_MS = 3000;
const int MOIST_REFRESH_MS = 500;
const int LIMIT_REFRESH_MS = 50;

const int WATER_ON_MS      = 5000;
const int WATER_MIN_OFF_MS = 30 * 60000;

// Initialization
const int MOIST_LIMIT_INIT = 500;

static_assert(MOIST_SHOW_MS > BUTTON_LONGPRESS_MS);
