#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <Arduino.h>

#define _SEGMENTS 4


class Display {
  public:
    Display(void) {};
    Display(byte, byte, byte);
    void blank(void),
         delay(byte),
         displayFloat(float),
         displayInt(int),
         refresh(void);
  private:
    byte _data[_SEGMENTS],
         _clockPin,
         _dataPin,
         _latchPin;
    unsigned long _delay,
                  _lastRefresh;
    void _setSegment(byte, byte);
};

#endif
