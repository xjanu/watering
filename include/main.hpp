#pragma once

#include "constants.hpp"
#include "7seg.h"

int moist;
int moist_limit;

SegmentDisplay display{CATHODE, PINS_SEGMENT, PINS_DIGIT[0],
                       PINS_DIGIT[1], PINS_DIGIT[2], PINS_DIGIT[3]};
