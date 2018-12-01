#include <Arduino.h>

#include "buzzer.h"


Buzzer::Buzzer(byte pin, bool invert) {
  _pin = pin;
  _invert = invert;

  pinMode(_pin, OUTPUT);
  _disable();
}

void Buzzer::_disable(void) {
  digitalWrite(_pin, LOW ^ _invert);
}

void Buzzer::tone(unsigned long frequency) {
  ::tone(_pin, frequency);
}

void Buzzer::off(void) {
  ::noTone(_pin);
  _disable();
}
