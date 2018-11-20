#ifndef __LED_H__
#define __LED_H__


class LED {
  public:
    LED(void) {};
    LED(int);
    LED(int, bool);
    void on(void),
         off(void),
         setBrightness(byte),
         pulse(int, int),
         signal(byte);
  private:
    bool _invert;
    int _pin;
};

#endif
