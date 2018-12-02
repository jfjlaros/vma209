#include <button.h>
#include <buzzer.h>
#include <led.h>
#include <simpleRPC.h>

#include <display.h>

#define _BUTTONS_INTERNAL_PULLUP false // Change when removing jumper J2.

Buzzer buzzer(3, true);
Display display(7, 8, 4);
Input potmeter(A0);
Button button[3] = {
  Button(A1, true, _BUTTONS_INTERNAL_PULLUP),
  Button(A2, true, _BUTTONS_INTERNAL_PULLUP),
  Button(A3, true, _BUTTONS_INTERNAL_PULLUP)};
LED led[4] = {
  LED(10, true),
  LED(11, true),
  LED(12, true),
  LED(13, true)};


void ledBrightness(byte index, byte brightness) {
  led[index].analogWrite(brightness);
}

bool buttonPressed(byte index) {
  return button[index].on();
}


void setup(void) {
  Serial.begin(9600);
}

void loop(void) {
  interface(
    pack(&buzzer, &Buzzer::tone),
      "tone: Play a tone."
      "@frequency: Frequency.",
    pack(&buzzer, &Buzzer::noTone),
      "tone_stop: Stop sound.",
    pack(&display, &Display::delay),
      "display_delay: Set the refresh delay time."
      "@delay: Delay time in milliseconds.",
    pack(&display, &Display::blank),
      "display_blank: Turn the display off.",
    pack(&display, &Display::displayInt),
      "display_int: Display an integer value."
      "@value: Value.",
    pack(&potmeter, &Input::analogRead),
      "potmeter: Read potmeter value."
      "@return: Potmeter value.",
    ledBrightness,
      "led_brightness: Set LED brightness."
      "@index: LED. @brightness: Brightness.",
    buttonPressed,
      "button_pressed: Get button status."
      "@index: Button. @return: Button status.");

  display.refresh();
}
