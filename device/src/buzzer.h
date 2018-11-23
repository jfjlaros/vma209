#ifndef __BUZZER_H__
#define __BUZZER_H__


class Buzzer {
  public:
    Buzzer(void) {};
    Buzzer(byte);
    Buzzer(byte, bool);
    void tone(unsigned long),
         off(void);
  private:
    void _disable(void);
    byte _pin;
    bool _invert;
};

#endif
