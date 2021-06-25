<img src="images/compass.png" width=48 height=48 align=right>

# TinyTrackGPS
[![Arduino ©: TinyTrackGPS](https://img.shields.io/badge/Arduino©-TinyTrackGPS-red?style=for-the-badge&logo=arduino)](README.md)
[![Version: v0.4](https://img.shields.io/badge/Version-v0.4-blue?style=for-the-badge&logo=v)]()

A simple track GPS to SD card logger.

<img alt="Location example." src="images/image1.jpg" width="240">&nbsp;

This program is written in C/C++ for Arduino © UNO R3 and other compatible microcontrollers based on Atmega328 and similar.

It is tested on:
* UNO R3 board (Arduino UNO compatible board based on Atmega328).
* Lgt8f328p (a replacement Arduino Pro Mini).Tested v0.1 and v0.2.

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](LICENSE)

## List of componets

This project use components list above:

  * Arduino © UNO board or equivalent AVR.
  * NMEA 6 module.
  * MicroSD module.
  * LCD 16×2 char display module.
  * Bluetooth module. (Optional)
  * Switch for select visual data on LCD.(Pin8 and GND)

<img alt="Schema1." src="images/schema1.jpg" width="240">&nbsp;

## Source

TinyTrackGPS is free software, see **License** section for more information. The code is based and get parts of the libraries above:

  * TinyGPS library, Mikal Hart (https://github.com/mikalhart/TinyGPS).
  * Ticker librry, Stefan Staub (https://github.com/sstaub/Ticker).
  * Low-Power library, rocketscream (https://github.com/rocketscream/Low-Power).
  * SD library, Arduino Standard Libraries (Arduino IDE).
  * SoftwareSerial library, Arduino Standard Libraries (Arduino IDE).
  * LiquidCrystal library, Arduino Standard Libraries (Arduino IDE).

## Working

It works getting info from NMEA module every second and save it into de log file. Format is:
```
HH:MM:SS,YY.YYYYYY,XX.XXXXXX,ALT,UTM
```
Like this:
```
12:42:47,37.990493,-4.785790,571,30S 343186 4206265
12:42:48,37.990276,-4.785741,571,30S 343190 4206240
12:42:49,37.990062,-4.785705,571,30S 343193 4206216
12:42:50,37.989860,-4.785694,571,30S 343193 4206194
...
```
Where:
  * HH - Hours from GPS UTC.
  * MM - Minutes.
  * SS - Seconds.
  * YY.YYYYYY - Degree of latitude.
  * XX.XXXXXX - Degree of longitude.
  * ALT - Altitude in meters.
  * UTM - Coordenates in UTM format(WGS84): Zone Band X Y (00A XXXXXX YYYYYYY)

<img alt="Log File." src="images/image2.png" width="480">&nbsp;

For conversion to UTM coordinates it has been implemented library UTMconversion.h

Example of use:

```
#include "UTMconversion.h"

float flat = 37.8959210;
float flon = -4.7478210;

GPS_UTM utm;

void setup() {
  char utmstr[] = "30S 123456 1234567";

  Serial.begin(9600);  

  utm.UTM(flat, flon);
  sprintf(utmstr, "%02d%c %ld %ld", utm.zone(), utm.band(), utm.X(), utm.Y());
  Serial.println(utmstr);
}

void loop() {

}
```

File is named as:

`YYYYMMDD.csv` Example: `20210216.csv`

Where:
  * YYYY - Year 4 digits format.
  * MM - Mouth.
  * DD - Day.

Low-Power the library is used to reduce power consumption and gain greater autonomy implementing the project portably using lithium batteries.

## Draw track on map

You can upload the file and get the draw on a map using [GPS Visualizer](https://www.gpsvisualizer.com/).

<img alt="GPS Visualizer1." src="images/map1.jpg" width="240">&nbsp;
<img alt="GPS Visualizer2." src="images/map2.jpg" width="240">&nbsp;
<img alt="GPS Visualizer3." src="images/gpsvisualizer2.png" width="480">&nbsp;

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

## Credits

Compass icon at the beginning is from [Flaticon.es](https://www.flaticon.es) designed by [DinosoftLabs](https://www.flaticon.es/autores/DinosoftLabs)
and licensed by [free license](images/license-37862535_compass.pdf).
