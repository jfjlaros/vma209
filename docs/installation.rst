Installation
============

In this section we cover retrieval of the latest release or development version
of the code and subsequent installation for an Arduino device.

Prerequisites
-------------

This project depends on the arduino-peripherals_ library:

- peripherals_ installation instructions.

The demo needs both the device library as well as the host library of
simpleRPC_:

- `simpleRPC device`_ installation instructions.
- `simpleRPC host`_ installation instructions.


Download
--------

Latest release
^^^^^^^^^^^^^^

Navigate to the `latest release`_ and either download the ``.zip`` or the
``.tar.gz`` file.

Unpack the downloaded archive.


From source
^^^^^^^^^^^

The source is hosted on GitHub_, to install the latest development version, use
the following commands.

::

    git clone https://github.com/jfjlaros/vma209.git
    cd vma209
    git submodule init
    git submodule update


Installation
------------

Arduino IDE
^^^^^^^^^^^

In the Arduino IDE, a library can be added to the list of standard libraries by
clicking through the following menu options.

- Sketch
- Import Library
- Add Library

To add the library, navigate to the downloaded folder and select the subfolder
named ``display``.

- Click OK.

Now the library can be added to any new project by clicking through the
following menu options.

- Sketch
- Import Library
- display


Ino
^^^

Ino_ is an easy way of working with Arduino hardware from the command line.
Adding libraries is also easy, simply place the library in the ``lib``
subdirectory.


::

    cd lib
    git clone https://github.com/jfjlaros/vma209.git


.. _arduino-peripherals: https://arduino-peripherals.readthedocs.io
.. _peripherals: https://arduino-peripherals.readthedocs.io/en/latest/installation.html
.. _simpleRPC: https://simplerpc.readthedocs.io
.. _simpleRPC device: https://simplerpc.readthedocs.io/en/latest/install_device.html
.. _simpleRPC host: https://simplerpc.readthedocs.io/en/latest/install_host.html
.. _latest release: https://github.com/jfjlaros/vma209/releases/latest
.. _GitHub: https://github.com/jfjlaros/vma209.git
.. _Ino: http://inotool.org
