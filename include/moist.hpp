#pragma once

/**
 * @brief Set the dryness limit
 *
 * Let the user set the moist level using a potentiometer.
 *
 * @return the new value for moist_limit
 */
int set_limit();

/**
 * @brief Show the current moisture reading
 * @param time How long to keep showing the reading
 */
void show_moist(int time);
