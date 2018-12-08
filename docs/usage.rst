Usage
=====

Simple input and output devices
-------------------------------

For more information about the simple peripherals, please see the
arduino-peripherals_ documentation.


Display
-------

The display constructor takes three parameters, which on this board should have
the following values.

.. list-table:: Constructor parameters.
   :header-rows: 1

   * - parameter
     - value
   * - ``clockPin``
     - 7
   * - ``dataPin``
     - 8
   * - ``latchPin``
     - 4

The display class has the following functions.

.. list-table:: Functions.
   :header-rows: 1

   * - function
     - description
   * - ``clear``
     - Clear the display.
   * - ``delay``
     - Set the refresh delay time.
   * - ``displayInt``
     - Display an integer value.
   * - ``refresh``
     - Display refresh.

Example
^^^^^^^

We typically initialise the display as follows.

.. code:: cpp

    #include <display.h>

    Display display(7, 8, 4);

To refresh the display, add the following line to the ``loop()`` body.

.. code:: cpp

    void loop(void) {
      display.refresh();
    }

The display can be set to a specific brightness and can be used to show signed
integers.

.. code:: cpp

    display.delay(20);        // Dim the display.
    display.displayInt(-123); // Show the string "-123".


.. _arduino-peripherals: https://arduino-peripherals.readthedocs.io
