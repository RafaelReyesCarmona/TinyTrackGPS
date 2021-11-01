<img src="images/compass.png" width=48 height=48 align=right>

# TinyTrackGPS
[![Arduino ©: TinyTrackGPS](https://img.shields.io/badge/Arduino©-TinyTrackGPS-red?style=for-the-badge&logo=arduino)](README.md) [![Version: v0.9](https://img.shields.io/badge/Version-v0.9-blue?style=for-the-badge&logo=v)]()

A simple track GPS to SD card logger.

<img alt="Location example." src="images/InShot_20211017_231200992.gif" width="240">
<img alt="Location example." src="images/InShot_20211018_010318084.jpg" width="240">&nbsp;

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
  * LCD 16×2 char display module (wired or I2C), or OLED 0.96" I2C (SSD1306) (Optional)
  * Bluetooth module. (Optional)

### NO DISPLAY
Now you can use a minimal hardware to track GPS location. When no display use MicroSD module and card are mandatory. Comment all lines in 'config.h' file:
```C++
//#define DISPLAY_TYPE_SDD1306_128X64     // Para usar pantalla OLED 0.96" I2C 128x64 pixels
//#define DISPLAY_TYPE_LCD_16X2           // Para usar LCD 16 x 2 carateres.
//#define DISPLAY_TYPE_LCD_16X2_I2C       // Para usar LCD 16 x 2 carateres. I2C.
```
<img alt="Schema1." src="images/schema0.jpg" width="240">&nbsp;

### LCD 16x2

If you use LCD 16x2 char wired (6-wires), uncomment line like this in 'config.h' file:
```C++
#define DISPLAY_TYPE_LCD_16X2
```
<img alt="Schema1." src="images/schema1.jpg" width="240">&nbsp;

### LCD 16x2 I2C

If you use LCD 16x2 char I2C (4-wires), uncomment line like this in 'config.h' file:
```C++
#define DISPLAY_TYPE_LCD_16X2_I2C
```
<img alt="Schema1." src="images/InShot_20211018_000644613.jpg" width="240">&nbsp;

### OLED 0'96" 128x64 I2C

If you use OLED 0'96" 128X64 I2C (4-wires), uncomment line like this in 'config.h' file:
```C++
#define DISPLAY_TYPE_SDD1306_128X64
```
<img alt="Schema1." src="images/InShot_20211018_000545242.jpg" width="240">&nbsp;

### UST/UT Time.
_(Universal Summer Timer/Universal Standard Time)_

Now TinyTrackGPS record the info in local time. It is used Timezone library for that. Select 
the proper config at _line 74_ of `TinyTrackGPS.cpp` file. There are some info for time zone:
```C++
// Australia Eastern Time Zone (Sydney, Melbourne)
TimeChangeRule aEDT = {"AEDT", First, Sun, Oct, 2, 660};    // UTC + 11 hours
TimeChangeRule aEST = {"AEST", First, Sun, Apr, 3, 600};    // UTC + 10 hours
Timezone ausET(aEDT, aEST);

// Moscow Standard Time (MSK, does not observe DST)
TimeChangeRule msk = {"MSK", Last, Sun, Mar, 1, 180};
Timezone tzMSK(msk);

// Central European Time (Frankfurt, Paris)
TimeChangeRule CEST = {"CEST", Last, Sun, Mar, 2, 120};     // Central European Summer Time
TimeChangeRule CET = {"CET ", Last, Sun, Oct, 3, 60};       // Central European Standard Time
Timezone CE(CEST, CET);

// United Kingdom (London, Belfast)
TimeChangeRule BST = {"BST", Last, Sun, Mar, 1, 60};        // British Summer Time
TimeChangeRule GMT = {"GMT", Last, Sun, Oct, 2, 0};         // Standard Time
Timezone UK(BST, GMT);

// UTC
TimeChangeRule utcRule = {"UTC", Last, Sun, Mar, 1, 0};     // UTC
Timezone UTC(utcRule);

// US Eastern Time Zone (New York, Detroit)
TimeChangeRule usEDT = {"EDT", Second, Sun, Mar, 2, -240};  // Eastern Daylight Time = UTC - 4 hours
TimeChangeRule usEST = {"EST", First, Sun, Nov, 2, -300};   // Eastern Standard Time = UTC - 5 hours
Timezone usET(usEDT, usEST);

// US Central Time Zone (Chicago, Houston)
TimeChangeRule usCDT = {"CDT", Second, Sun, Mar, 2, -300};
TimeChangeRule usCST = {"CST", First, Sun, Nov, 2, -360};
Timezone usCT(usCDT, usCST);

// US Mountain Time Zone (Denver, Salt Lake City)
TimeChangeRule usMDT = {"MDT", Second, Sun, Mar, 2, -360};
TimeChangeRule usMST = {"MST", First, Sun, Nov, 2, -420};
Timezone usMT(usMDT, usMST);

// Arizona is US Mountain Time Zone but does not use DST
Timezone usAZ(usMST);

// US Pacific Time Zone (Las Vegas, Los Angeles)
TimeChangeRule usPDT = {"PDT", Second, Sun, Mar, 2, -420};
TimeChangeRule usPST = {"PST", First, Sun, Nov, 2, -480};
Timezone usPT(usPDT, usPST);
```

## Source

TinyTrackGPS is free software, see **License** section for more information. The code is based and get parts of the libraries above:

  * TinyGPS library, Mikal Hart (https://github.com/mikalhart/TinyGPS).
  * SdFat library, Bill Greiman (https://github.com/greiman/SdFat).
  * U8g2 library, oliver (https://github.com/olikraus/u8g2).
  * Low-Power library, Rocket Scream Electronics (https://github.com/rocketscream/Low-Power).
  * SoftwareSerial library, Arduino Standard Libraries (Arduino IDE). (only for debug)
  * LiquidCrystal library, Arduino Standard Libraries (Arduino IDE).
  * LiquidCrystal I2C library, John Rickman (https://github.com/johnrickman/LiquidCrystal_I2C).
  * UTMConversion library, Rafael Reyes (https://github.com/RafaelReyesCarmona/UTMConversion).
  * Timezone library, Jack Christensen (https://github.com/JChristensen/Timezone).
  * Time library, Paul Stoffregen (https://github.com/PaulStoffregen/Time).

## How to compile
### Config
Edit 'config.h' file before, to configure display type commenting the proper line:
```C++
// Descomentar solo uno de los displays utilizados.
//#define DISPLAY_TYPE_SDD1306_128X64     // Para usar pantalla OLED 0.96" I2C 128x64 pixels
#define DISPLAY_TYPE_LCD_16X2             // Para usar LCD 16 x 2 carateres.
//#define DISPLAY_TYPE_LCD_16X2_I2C       // Para usar LCD 16 x 2 carateres. I2C.
```
Modify Arduino pin where you connect the LCD 16x2 char:
```C++
// Definiciones para display LCD 16x2 caracteres.
#define RS 2
#define ENABLE 3
#define D0 4
#define D1 5
#define D2 6
#define D3 7
```
Modify I2C port for LCD 16x2 I2C: (connect in SCL and SDA pins)
```C++
// Define direccion I2C para LCD16x2 char.
#define I2C 0x27
```
### Coding TimeChangeRules
Normally these will be coded in pairs for a given time zone: One rule to describe when daylight (summer) time starts, and one to describe when standard time starts.

As an example, here in the Eastern US time zone, Eastern Daylight Time (EDT) starts on the 2nd Sunday in March at 02:00 local time. Eastern Standard Time (EST) starts on the 1st Sunday in November at 02:00 local time.

Define a **TimeChangeRule** as follows:

`TimeChangeRule myRule = {abbrev, week, dow, month, hour, offset};`

Where:

  * **abbrev** is a character string abbreviation for the time zone; it must be no longer than five characters.
  * **week** is the week of the month that the rule starts.
  * **dow** is the day of the week that the rule starts.
  * **hour** is the hour in local time that the rule starts (0-23).
  * **offset** is the UTC offset in minutes for the time zone being defined.

For convenience, the following symbolic names can be used:

**week:** First, Second, Third, Fourth, Last
**dow:** Sun, Mon, Tue, Wed, Thu, Fri, Sat
**month:** Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec

For the Eastern US time zone, the TimeChangeRules could be defined as follows:

```C++
TimeChangeRule usEDT = {"EDT", Second, Sun, Mar, 2, -240};  //UTC - 4 hours
TimeChangeRule usEST = {"EST", First, Sun, Nov, 2, -300};   //UTC - 5 hours
```
For Central European time zone (Frankfurt, Paris), TimeChangeRules could be as:
```C++
TimeChangeRule CEST = {"CEST", Last, Sun, Mar, 2, 120};     // Central European Summer Time
TimeChangeRule CET = {"CET ", Last, Sun, Oct, 3, 60};       // Central European Standard Time
```

For more information see Timezone info at: https://github.com/JChristensen/Timezone#readme
### Set the Time Zone

Change lines like above in `TinyTrackGPS.cpp` file, at line **74**, with appropriate definition for your time zone.

<img alt="Log File." src="images/Timezone CE - code.png" width="760">&nbsp;

If your time zone is Australia, you can use this lines:

<img alt="Log File." src="images/Timezone ausET - code.png" width="760">&nbsp;

### Platformio
Run command `pio.exe run`.
```
Processing Uno (platform: atmelavr; board: uno; framework: arduino)
-------------------------------------------------------------------------------------------------Verbose mode can be enabled via `-v, --verbose` option
CONFIGURATION: https://docs.platformio.org/page/boards/atmelavr/uno.html
PLATFORM: Atmel AVR (3.4.0) > Arduino Uno
HARDWARE: ATMEGA328P 16MHz, 2KB RAM, 31.50KB Flash
DEBUG: Current (avr-stub) On-board (avr-stub, simavr)
PACKAGES:
 - framework-arduino-avr 5.1.0
 - toolchain-atmelavr 1.70300.191015 (7.3.0)
LDF: Library Dependency Finder -> http://bit.ly/configure-pio-ldf
LDF Modes: Finder ~ chain, Compatibility ~ soft
Found 14 compatible libraries
Scanning dependencies...
Dependency Graph
|-- <LiquidCrystal> 1.0.7
|-- <TinyGPS> 0.0.0-alpha+sha.db4ef9c97a
|-- <U8g2> 2.28.8
|   |-- <SPI> 1.0
|   |-- <Wire> 1.0
|-- <SdFat> 2.1.0
|   |-- <SPI> 1.0
|-- <LiquidCrystal_I2C> 1.1.4
|   |-- <Wire> 1.0
|-- <Low-Power> 1.81.0
|-- <UTMConversion> 1.0.0
|-- <Timezone> 1.2.4
|   |-- <Time> 1.6.1
|-- <SoftwareSerial> 1.0
Building in release mode
Compiling .pio\build\Uno\src\Display.cpp.o
Compiling .pio\build\Uno\src\TinyTrackGPS.cpp.o
Linking .pio\build\Uno\firmware.elf
Checking size .pio\build\Uno\firmware.elf
Advanced Memory Usage is available via "PlatformIO Home > Project Inspect"
RAM:   [=======   ]  68.6% (used 1404 bytes from 2048 bytes)
Flash: [========= ]  85.7% (used 27634 bytes from 32256 bytes)
Building .pio\build\Uno\firmware.hex
================================== [SUCCESS] Took 3.33 seconds ==================================
Environment    Status    Duration
-------------  --------  ------------
Uno            SUCCESS   00:00:03.332
================================== 1 succeeded in 00:00:03.332 ==================================
```
For upload to Arduino use Platformio enviroment or use `platformio.exe run --target upload` command on terminal.

### Use of memory (Arduino UNO or equivalent) V0.7 vs. V0.9
#### NO DISPLAY
Compile V0.7:
```
RAM:   [=====     ]  50.3% (used 1031 bytes from 2048 bytes)
Flash: [=======   ]  70.7% (used 22798 bytes from 32256 bytes)
```
Compile V0.9:
```
RAM:   [======    ]  58.6% (used 1200 bytes from 2048 bytes)
Flash: [========  ]  76.7% (used 24748 bytes from 32256 bytes)
```
#### LCD 16x2 I2C
Compile V0.7:
```
RAM:   [=======   ]  70.2% (used 1437 bytes from 2048 bytes)
Flash: [========= ]  86.0% (used 27748 bytes from 32256 bytes)
```
Compile V0.9:
```
RAM:   [========  ]  79.6% (used 1631 bytes from 2048 bytes)
Flash: [========= ]  90.2% (used 29100 bytes from 32256 bytes)
```
#### LCD 16x2 6-WIRED
Compile V0.7:
```
RAM:   [======    ]  59.2% (used 1213 bytes from 2048 bytes)
Flash: [========  ]  81.5% (used 26296 bytes from 32256 bytes)
```
Compile V0.9:
```
RAM:   [=======   ]  68.7% (used 1407 bytes from 2048 bytes)
Flash: [========= ]  85.7% (used 27646 bytes from 32256 bytes)
```
#### OLED 0'96" 128x64 I2C
Compile V0.7:
```
RAM:   [========  ]  79.7% (used 1632 bytes from 2048 bytes)
Flash: [==========]  96.2% (used 31032 bytes from 32256 bytes)
```
Compile V0.9:
```
RAM:   [========= ]  85.2% (used 1744 bytes from 2048 bytes)
Flash: [==========]  99.8% (used 32190 bytes from 32256 bytes)
```
## Changelog
### V0.9
  * Added Timezone library for local time log.
### V0.8
  * Added UTMConversion library for conversion to UTM coordinates. It has been implemented From library UTMconversion.h (TinyTrackGPS V0.7). Now it is an independent library.

### V0.7
  * Use Low-Power library to reduce power consumption and gain greater autonomy implementing the project portably using lithium batteries.
  * No display support for minimal implementation.
  * Fixed some errors when displays on LCD 16x2.
  * Fixed error when save log on SD. Sometimes data didn't save correctly.
### V0.6
  * Fixed error GPS log file when compiling for OLED 0'96".
  * Added wait animation for OLED 0'96" 128x64.
  * Written new procedure to save data in GPS log file.
  * Less global variables, so code with less size when compile it.
### V0.5
  * Added wait animation for LCD 16x2 on "Waitting for GPS signal..." screen.
  * Added support for OLED 0'96" 128x64. 
  * GPS log file set time for create and modify.
  * Use SdFat library, Bill Greiman, for better performance.
  * Remove switch for select visual data on LCD 16x2. Now data change automatically every 8 seconds between UTM and grades coordenates.

## Working

It works getting info from NMEA module every second and save it into de log file. 


Log file Format is:
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

For conversion to UTM coordinates use UTMConversion library. (https://github.com/RafaelReyesCarmona/UTMConversion)

Example of use:

```C++
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

`Low-Power` - the library is used to reduce power consumption and gain greater autonomy implementing the project portably using lithium batteries.
Implemented in v0.4 first time and from v0.7. 

## Accuracy

NMEA 6 GPS module accuracy is similar to others GPS devices. In the picture can see it.

<img alt="GPS accuracy" src="images/InShot_20211018_001600256.jpg" width="480">&nbsp;

  * `Ref` was at _(30S 341554 4194119)_ location exactly. 
  * `TinyGPS` was located at _(30S 341556 4194126)_, 7m error. 
  * `GPS device` reported _(30S 341553 4194111)_, 8m error. 

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
