# TinyTrackGPS
[![Arduino ©: TinyTrackGPS](https://img.shields.io/badge/Arduino©-TinyTrackGPS-red?style=for-the-badge&logo=arduino)](README.md)

A simple track GPS to SD card logger. 

<img alt="Location example." src="images/image1.jpg" width="240">&nbsp;

This program is written in C for Arduino © UNO R3 and other compatible microcontrollers based on Atmega328 and similar. 

It is tested on:
* UNO R3 board (Arduino UNO compatible board based on Atmega328). 
* Lgt8f328p (a replacement Arduino Pro Mini). 

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](LICENSE)

## List of componets

This project use components list above:

  * Arduino © UNO board or equivalent AVR. 
  * NMEA 6 module. 
  * MicroSD module. 
  * LCD 16×2 char display module. 
  * Bluetooth module. (Optional) 

## Source

TinyTrackGPS is free software, see **License** section for more information. The code is based and get parts of the libraries above:

  * TinyGPS library, Mikal Hart (https://github.com/mikalhart/TinyGPS).
  * SD library, Arduino Standard Libraries (Arduino IDE).
  * SoftwareSerial library, Arduino Standard Libraries (Arduino IDE).
  * LiquidCrystal library, Arduino Standard Libraries (Arduino IDE).

## Working

It works getting info from NMEA module every second and save it into de log file. Format is:

`HH:MM:SS,XX.XXXXXX,YY.YYYYYY`

Where:
  * HH - Hours from GPS UTC.
  * MM - Minutes
  * SS - Seconds
  * XX.XXXXXX - Degree of latitude.
  * YY.YYYYYY - Degree of longitude.

<img alt="Log File." src="images/image2.png" width="240">&nbsp;

## Draw track on map

You can upload the file and get the draw on a map using [GPS Visualizer](https://www.gpsvisualizer.com/). 

<img alt="GPS Visualizer1." src="images/map1.jpg" width="240">&nbsp;
<img alt="GPS Visualizer2." src="images/map2.jpg" width="240">&nbsp;

Or using apps like AlpineQuest. 

<img alt="AlpineQuest." src="images/map3.jpg" width="240">&nbsp;

## License

This file is part of TinyTrackGPS.

TinyTrackGPS is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

TinyTrackGPS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with TinyTrackGPS.  If not, see <https://www.gnu.org/licenses/>.

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](LICENSE)

## Authors

Copyright © 2019-2021 Francisco Rafael Reyes Carmona. 
Contact me: rafael.reyes.carmona@gmail.com 
