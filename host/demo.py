from sys import stdout
from time import sleep

from simple_rpc import Interface


interface = Interface('/dev/ttyACM0')

interface.display_delay(25)

for i in range(-100, 100):
    interface.display_int(i)
    sleep(0.01)

interface.display_int(1234)
for i in range(26)[::-1]:
    interface.display_delay(i)
    sleep(0.05)
for i in range(26):
    interface.display_delay(i)
    sleep(0.05)

interface.display_clear()

for i in range(4):
    for j in range(255):
        interface.led_brightness(i, j)
    for j in range(255)[::-1]:
        interface.led_brightness(i, j)

for i in range(3):
    stdout.write('Please press button {}... '.format(i + 1))
    stdout.flush()
    while not interface.button_pressed(i):
        pass
    stdout.write('thank you.\n')

stdout.write('\nPress button 1 to abort.\n')
while not interface.button_pressed(0):
    stdout.write('\rPotmeter value: {:04} '.format(
        interface.potmeter()))
stdout.write('\n')

stdout.write('\nPress button 2 to start buzzer test.\n')
while not interface.button_pressed(1):
    pass
for i in range(31, 5000, 50):
    interface.tone(i)
for i in range(31, 5000, 50)[::-1]:
    interface.tone(i)

interface.tone_stop()

