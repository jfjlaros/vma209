#include "display.h"

#define _BLANK 0xff // Empty.
#define _DOT 0x7f   // Decimal point.
#define _MINUS 0xbf // Minus sign.

unsigned char _digit[] = { // Digits 0-9.
  0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};


/**
 * Constructor.
 *
 * @arg {byte} clockPin - Clock pin.
 * @arg {byte} dataPin - Data pin.
 * @arg {byte} latchPin - Latch pin.
 */
Display::Display(byte clockPin, byte dataPin, byte latchPin) {
  _clockPin = clockPin;
  _dataPin = dataPin;
  _latchPin = latchPin;

  _delay = 0;
  _last_time = 0;

  pinMode(_clockPin, OUTPUT);
  pinMode(_dataPin, OUTPUT);
  pinMode(_latchPin, OUTPUT);

  blank();
}

/**
 * Send {data} to a segment.
 *
 * @arg {byte} segment - Segment number.
 * @arg {byte} data - Data to be sent do {segment}.
 */
void Display::_setSegment(byte segment, byte data) {
  digitalWrite(_latchPin, LOW);
  shiftOut(_dataPin, _clockPin, MSBFIRST, data);
  shiftOut(_dataPin, _clockPin, MSBFIRST, 0xf0 | (1 << segment));
  digitalWrite(_latchPin, HIGH);
}

/**
 * Blank the display.
 */
void Display::blank(void) {
  int i;

  for (i = 0; i < _SEGMENTS; i++) {
    _data[i] = _BLANK;
  }
}

/**
 * Set the refresh delay time.
 *
 * @arg {byte} delay - Delay time in milliseconds.
 */
void Display::delay(byte delay) {
  _delay = delay;
}

/**
 * Display a floating point value.
 *
 * @arg {float} value - Value to be displayed.
 *
 * TODO: Implement properly.
 */
void Display::displayFloat(float value) {
  displayInt((int)(value * 100));
  _data[1] = _data[1] & _DOT;
}

/**
 * Display an integer value.
 *
 * @arg {int} value - Value to be displayed.
 */
void Display::displayInt(int value) {
  int value_ = value,
      i;

  blank();
  if (value == 0) {
    _data[_SEGMENTS - 1] = _digit[0];
  }
  if (value < 0) {
    _data[0] = _MINUS;
    value_ = -value;
  }
  for (i = _SEGMENTS - 1; i >= 0 && value_; i--) {
    _data[i] = _digit[value_ % 10];
    value_ = value_ / 10;
  }
}

/**
 * Display refresh.
 */
void Display::refresh(void) {
  byte i;

  if (millis() - _last_time < _delay) {
    return;
  }

  for (i = 0; i < _SEGMENTS; i++) {
    _setSegment(i, _data[i]);
  }
  _setSegment(0x00, _BLANK); // TODO: Check the 0x00 effect.

  _last_time = millis();
}
