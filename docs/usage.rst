Usage
=====

Simple input and output devices
-------------------------------

.. TODO:: Refer to documentation of simple I/O devices.


Display
-------

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

.. code:: cpp

    #include <display.h>

    Display display(7, 8, 4);

.. code:: cpp

    void loop(void) {
      display.refresh();
    }

.. code:: cpp

    display.delay(20);        // Dim the display.
    display.displayInt(-123); // Show the string "-123".
