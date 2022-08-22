#pragma once

/**
 * @brief Get the moisture sensor reading
 */
int  read_moist();
/**
 * @brief Get the moisture sensor reading
 *
 * This overload is used for smoothing out changes
 *
 * @param current The last moisture reading
 */
int  read_moist(int current);

/**
 * @brief Get the potentiomater reading
 */
int  read_pot();

/**
 * @brief Get the button state
 * @return true if pressed
 */
bool read_button();
