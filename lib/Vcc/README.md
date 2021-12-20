arduino_vcc
===========

Arduino library to read VCC supply level without external components
This version also can be run on Logicgreen LG8F328P microcontroller.

<b>Warning!</b> Be aware running this program on ATmega, becase switching reference voltage to VCC will drive AREF pin with VCC. So if an external referece is connected to AREF pin it will be shorted to VCC.

Unfortunately it doesn't work on Logicgreen LGT8F328D. This because if ADMUX selecting reference voltage as VCC instead of internal reference then internal reference will be shut down.
