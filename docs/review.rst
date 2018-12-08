Review
======

In this document, we review the Velleman VMA209_ "Multi-function shield
expansion board for Arduino". We cover both the hardware, the provided software
and the available documentation.

Documentation
-------------

The manual_ does not provide much information about the board, its components
or how to use it. It mainly consists of code examples that are also present in
the examples_ archive. The examples are instructive, but do not cover all the
functionality of the board. Basic things like driving the LED display are
covered, but more advanced topics like dimming are not touched upon. The
schema_ is probably the most useful document, as it lists all components and
their wiring.

It would have been nice if a library was provided by the manufacturer. Instead,
we put all our findings together for others to use.


Display
-------

The 4-digit 7-segment display is controlled by two MC74HC595AD shift registers,
one controlling the digit selection and one controlling the segment selection.
Using shift registers instead of a dedicated LED driver IC like the MAX7221
puts the burden of refreshing and dimming the display on the microcontroller.

When the board powers up, some random data is displayed at full brightness
because the shift registers are not in a well defined state after startup. This
effect stops once the software refresh procedure starts.

Refreshing
^^^^^^^^^^

As mentioned above, display refreshing must be done by the microcontroller. We
tried to do this at first with the hardware timer library MsTimer2_. This does
work quite well from a performance point of view, but since timer 2 interferes
with LED D4, we chose not to use this method.

Eventually, we decided to implement a software timer which needs be polled
continuously from the ``loop()`` body. This timer returns immediately if a
refresh is not needed, so other functions can still be performed in the mean
time.

During each refresh cycle, each digit is turned on and off as fast as possible.

Dimming
^^^^^^^

The shift registers have an *output enable* pin. It would have been nice if
these pins were wired to a PWM capable pin of the Arduino as this would enable
us to set the brightness of the display independently from the refresh rate.
Unfortunately these pins are wired to ground.

We therefore dim the display by lowering the refresh rate. After the refresh
cycle, the next refresh time is stored and all subsequent refresh calls will
return immediately until the refresh time is reached.

This approach has several drawbacks:

- At maximum brightness, all CPU time is spent on refreshing. So an other
  function that is executed in the mean time will likely influence the
  brightness of the display.
- If the brightness is set too low, the display will start flickering.


LEDs
----

Apart from the fact that the wiring is a bit awkward, the LEDs are working just
fine. To enable an LED, the output pin should be LOW, to disable an LED, it
should be high. This is opposite to what one might expect.

We used the ``invert`` parameter for LEDs in our library to make this a bit
easier for the end user.

At startup, one of the LEDs (number 13) is lit at full brightness, this is
because the Arduino itself has an LED attached to pin 13 which is off during
the initialisation cycle. Because of the inverted behaviour of the LEDs on the
shield, this LED is on by default.


Buzzer
------

The buzzer is driven by a PNP transistor, presumably to use the maximum
capacity of the buzzer (it is rather loud). Using a PNP transistor means that a
high voltage must be applied to turn off the buzzer, however, the standard
``tone()`` and ``noTone()`` functions assume that a buzzer can be turned off by
applying a low voltage. Using these functions will therefore result in a loud
noise when the buzzer should be silent. An NPN transistor would have been
better in this case.

We work around this issue by using the ``invert`` parameter, like we did for
the LEDs.

Advanced features
^^^^^^^^^^^^^^^^^

There are quite some ingenious ways of doing volume control and even generating
polyphonic sounds using buzzers. This however requires wiring the buzzer to
either two pins, as is the case for ToneAC_ or to use a dedicated pin, as is
the case for the `Arduino volume control library`_.

Unfortunately, none of these features are available in this setting.


Potmeter
--------

Works fine, no comments.


Buttons
-------

Work fine, but like most of the other components are wired a bit awkward. They
read LOW if the button is pressed, HIGH otherwise. This is also mitigated by
the use of the ``invert`` parameter.

Jumper J2 controls the pull up resistors for the buttons. If this jumper is
removed, the ``pullUp`` parameter can be used to use the internal pull up
resistors of the Arduino instead.


Conclusions
-----------

After quite some tinkering, this shield is quite usable for a wide range of
projects. We hope that the library that resulted from our endeavours will spare
other purchasers of this board some time.

Some obvious candidates for improving the hardware:

- Wiring the shift register OE pins to a PWM pin.
- Connecting the buzzer to pin 5 or 6 for volume control.


.. _MsTimer2: https://github.com/PaulStoffregen/MsTimer2
.. _ToneAC: http://playground.arduino.cc/Code/ToneAC
.. _VMA209: https://www.vellemanusa.com/products/view/?id=529565
.. _examples: https://www.velleman.eu/downloads/29/vma209_examples.zip
.. _manual: https://www.velleman.eu/downloads/29/vma209_a4v01.pdf
.. _schema: https://www.velleman.eu/downloads/29/infosheets/vma209_scheme.pdf
.. _Arduino volume control library: https://hackaday.io/project/11957-10-bit-component-less-volume-control-for-arduino
