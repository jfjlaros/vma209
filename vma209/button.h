#ifndef __BUTTON_H__
#define __BUTTON_H__

class Button {
  public:
    Button(void) {};
    Button(byte, bool=false, bool=false);
    bool isPressed(void),
         wasPressed(void);
  private:
    byte _pin;
    bool _invert;
};

#endif
