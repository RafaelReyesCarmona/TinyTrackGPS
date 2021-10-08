/*
config.h - Config file for TinyTrackGPS, a simple track GPS to SD card logger.
TinyTrackGPS v0.5

Copyright © 2019-2021 Francisco Rafael Reyes Carmona.
All rights reserved.

rafael.reyes.carmona@gmail.com

  This file is part of TinyTrackGPS.

  TinyTrackGPS is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  TinyTrackGPS is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with TinyTrackGPS.  If not, see <https://www.gnu.org/licenses/>.
*/

#define NAME "TinyTrackGPS"
#define VERSION "V0.5"

#define DISPLAY_TYPE_SDD1306_128X64     // Para usar pantalla OLED 0.96" I2C 128x64 pixels
//#define DISPLAY_TYPE_HX1230_96X68       // Para usar pantalla HX1230 96x68 pixels LCD SPI(Nokia simil.)
//#define DISPLAY_TYPE_LCD_16X2           // Para usar LCD 16 x 2 carateres.
//#define DISPLAY_TYPE_LCD_16X2_I2C       // Para usar LCD 16 x 2 carateres. I2C.

#define RS 2
#define ENABLE 3
#define D0 4
#define D1 5
#define D2 6
#define D3 7

#define LCD_CLK 13
#define LCD_DIN 11
#define LCD_CS 12
#define LCD_RST 5