/*
config.h - Config file for TinyTrackGPS, a simple track GPS to SD card logger.
TinyTrackGPS v0.12

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

// Definimos nombre aplicación y versión.
#define NAME "TinyTrackGPS"
#define NAME_M "TINYTRACKGPS"
#define VERSION "V0.12.15"

// Descomentar solo uno de los displays utilizados. Comentar todas las líneas para uso NO DISPLAY.
//#define DISPLAY_TYPE_SDD1306_128X64 // Para usar pantalla OLED 0.96" I2C 128x64 pixels
#define DISPLAY_TYPE_SDD1306_128X64_lcdgfx // Para usar pantalla OLED 0.96" I2C 128x64 pixels (lcdgfx library)
//#define DISPLAY_TYPE_LCD_16X2           // Para usar LCD 16 x 2 carateres.
//#define DISPLAY_TYPE_LCD_16X2_I2C       // Para usar LCD 16 x 2 carateres. I2C.

// Definiciones para display LCD 16x2 caracteres.
#define LCD_RS 2
#define LCD_ENABLE 3
#define LCD_D0 4
#define LCD_D1 5
#define LCD_D2 6
#define LCD_D3 7

// Define direccion I2C para LCD16x2 char.
#define I2C 0x27
