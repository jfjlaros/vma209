#include <Arduino.h>

#include "button.h"


/**
 * Constructor.
 *
 * @arg {byte} pin - Input pin.
 * @arg {bool} invert - Invert reading.
 * @arg {bool} pullUp - Enable internal pull up resistor.
 */
Button::Button(byte pin, bool invert, bool pullUp) {
  _pin = pin;
  _invert = invert;

  if (pullUp) {
    pinMode(_pin, INPUT_PULLUP);
  }
  else {
    pinMode(_pin, INPUT);
 }
}

/**
 * Read current button state.
 *
 * @return {bool} - Button state.
 */
bool Button::isPressed(void) {
  return (bool)digitalRead(_pin) ^ _invert;
}

bool Button::wasPressed(void) {
  return false;
}
