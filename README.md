Watering 🌱
========

Software for an automatic plant watering system.

Hardware
--------
This software runs on a custom DIY board connecting a microcontroller with
various IO devices. It is intended to be used for watering a small plant.

Used components:
  - [Arduino Pro Mini](https://docs.arduino.cc/retired/boards/arduino-pro-mini)
    microcontroller (clone)
  - [5641AH](http://www.xlitx.com/datasheet/5641AH.pdf) seven segment display
  - Capacitive Soil Moisture Sensor v1.2
  - Potentiometer and button for user input
  - 5V relay
  - Small submersible 3-6V water pump

How it works
------------
The program is essentially a simple state machine with four states of
operation.

In the default state, it checks the moisture level and button state. If the
soil is more dry than a pre-defined level, the machine gets switched to a
watering state. If the button is pressed, it switches to a display state.

In the watering state, the pump is turned on for a pre-defined time and then
the state changes back to default.

In the display state, the current moisture reading is displayed and it is
checked if the button is being long-pressed. If the button is long-pressed the
state changes to level-setting. Otherwise, the state changes to default after a
short while.

The level-setting state is used to set the desired soil moisture level. The user
can set the value using the potentiometer and confirm it by pressing the button.
After the button is pressed, the state changes to default.
