#ifndef __BUZZER_H__
#define __BUZZER_H__

class Buzzer {
  public:
    Buzzer(void) {};
    Buzzer(byte, bool=false);
    void tone(unsigned long),
         off(void);
  private:
    void _disable(void);
    byte _pin;
    bool _invert;
};

#endif
