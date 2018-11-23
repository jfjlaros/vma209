#ifndef __LED_H__
#define __LED_H__


class LED {
  public:
    LED(void) {};
    LED(byte);
    LED(byte, bool);
    void on(void),
         off(void),
         setBrightness(byte),
         pulse(int, int),
         signal(byte);
  private:
    byte _pin;
    bool _invert;
};

#endif
