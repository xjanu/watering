#include "Arduino.h"
#include "moist.hpp"
#include "sense.hpp"
#include "constants.hpp"
#include "7seg.h"

extern int moist;
extern SegmentDisplay display;

int set_limit()
{
    // TODO
}

void show_moist(int time)
{
    int start_time = millis();
    display.write_num(moist);

    for (int last_refresh = 0; millis() - start_time < time;)
    {
        if (millis() - last_refresh > MOIST_REFRESH_MS) {
            moist = read_moist(moist);
            display.write_num(moist);
            last_refresh = millis();
        }
        display.refresh();
    }
}
