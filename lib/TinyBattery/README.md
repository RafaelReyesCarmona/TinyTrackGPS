<img src="img/battery.png" width=48 height=48 align="right">

# TinyBattery

Ligth Library for Arduino Environment to Battery management.

## Installation ##

### Arduino IDE ###

For a tutorial on how to install new libraries for use with the Arduino
development environment please refer to the following website:
http://www.arduino.cc/en/Reference/Libraries

--- or ---

1. Download the ZIP file from the page [releases](https://github.com/RafaelReyesCarmona/TinyBattery/releases) to your machine.
<p align=center>
<img src="img/Download_latest.png" alt="Download latest version of library" width=600>
</p>

2. In the Arduino IDE, choose Sketch/Include Library/Add Zip Library.
<p align=center>
<img src="img/Add_library.png" alt="Add library Arduino IDE" width=600>
</p>

3. Navigate to the ZIP file, and click Open.

### PlatformIO ###

How to use the library in PlatformIO see [documentation](https://docs.platformio.org/en/latest/librarymanager/index.html) of Library Manager.

The only one simple step is to define dependencies in “platformio.ini” (Project Configuration File). For example,

```
[env:pro16MHzatmega328]
platform = atmelavr
board = pro16MHzatmega328
framework = arduino
lib_deps = rafaelreyescarmona/TinyBattery

[env:LGT8F328]
board = LGT8F328P
board_build.f_cpu = 32000000
platform = lgt8f
framework = arduino
lib_deps = rafaelreyescarmona/TinyBattery@^0.1
```

For Manual installation in PlatformIO Core:

1. Run a terminal and type for search the library: 
```
pio lib search TinyBattery
```
<p align=center>
<img src="img/PlatformIO_3.png" alt="PlatformIO Search command" width=600>
</p>

2. Type for install:
```
pio lib install ______
```

--- or ---

1. Search "TinyBattery" in search box of _Libraries_ of panel.
<p align=center>
<img src="img/PlatformIO_1.png" alt="PlatformIO Search screen" width=600>
</p>

2. Click _Add to project_ button. Library will be included in the project and "platformio.ini" updated.
<p align=center>
<img src="img/PlatformIO_2.png" alt="PlatformIO Add library" width=600>
</p>

## How to use the library ##

In Arduino IDE, Choose Sketch/Include Library/Scroll and select "TinyBattery".
<p align=center>
<img src="img/Using_library_1.png" alt="Using TinyBattery library in Arduino IDE" width=600>
</p>

There are a two examples files with the library. In the Arduino IDE, choose File/Examples/TinyBattery, and you can see "TinyBattery".

<p align=center>
<img src="img/Arduino_examples.png" alt="Examples files" width=600>
</p>

--- or ---

Example of use:

```C++
#include <Arduino.h>
#include <TinyBattery.h>

TinyBattery Battery(/* PIN */           A0,
                    /* VccREF */        5.035,
                    /* RESISTOR_VDD */  21000,
                    /* RESISTOR_GND */  47000,
                    /* MIN_VOLT */      16.00,
                    /* MAX_VOLT */      25.90);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(56700);
}

void loop() {
  // put your main code here, to run repeatedly:
  float Bat = Battery.GetVoltage();
  byte Bat_Level = Battery.GetChargeLevel();
  Serial.print("Battery: ");
  Serial.print(Bat);
  Serial.print(" V. Battery Level: ");
  Serial.print(Bat_Level);
  Serial.println(" %.");
  delay(250);
}
```

## License ##

This file is part of TinyBattery Library.

TinyBattery Library is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

TinyBattery Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with TinyBattery Library.  If not, see <https://www.gnu.org/licenses/>.

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](LICENSE)

## Authors ##

Copyright © 2021 Francisco Rafael Reyes Carmona.
Contact me: rafael.reyes.carmona@gmail.com

## Credits ##

Battery icon at the beginning is from [Flaticon.es](https://www.flaticon.es) designed by [FreePik](https://www.flaticon.com/authors/freepik)
and licensed by [free license](img/license.pdf).