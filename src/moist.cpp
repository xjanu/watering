#include "Arduino.h"
#include "moist.hpp"
#include "sense.hpp"
#include "constants.hpp"
#include "7seg.h"

extern int moist;
extern SegmentDisplay display;

int set_limit()
{
    int new_limit = MOIST_LIMIT_INIT;

    while (read_button());

    for (int last_refresh = 0; !read_button();)
    {
        if (millis() - last_refresh > LIMIT_REFRESH_MS) {
            new_limit = read_pot();
            display.write_num(new_limit);
            last_refresh = millis();
        }
        display.refresh();
    }

    return new_limit;
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
