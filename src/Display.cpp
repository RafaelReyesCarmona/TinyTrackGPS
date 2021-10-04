/*
Display.cpp - A simple track GPS to SD card logger. Display module.
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

#include "Display.h"

Display::Display(Display_Type t):_screen(t){
    if (_screen == SDD1306_128X64){
        _width = 128;
        _height = 64;
        _offset = 0;
    } else if (_screen == HX1230_96X68){
        _width = 96;
        _height = 68;
        _offset = 32;
    } else if (_screen == LCD_16X2 || _screen == LCD_16X2_I2C){
        _width = 16;
        _height = 2;
        _offset = 0;
    }
}

void Display::start(){
    if (_screen == LCD_16X2){
        #if defined(DISPLAY_TYPE_LCD_16X2)
        // DEFINICION DE CARACTERES PERSONALIZADOS
        byte alt[8] = {
            0b00000100,
            0b00001110,
            0b00011111,
            0b00000100,
            0b00000100,
            0b00000100,
            0b00000100,
            0b00000100,
        };

        byte ant[8] = {
            0b00001110,
            0b00010001,
            0b00010101,
            0b00010001,
            0b00000100,
            0b00000100,
            0b00001110,
            0b00000000,
        };

        byte sd[8] = {
            0b00001110,
            0b00010001,
            0b00011111,
            0b00000000,
            0b00000000,
            0b00010111,
            0b00010101,
            0b00011101,
        };

        byte hourglass_0[8] = {
            0b00011111,
            0b00001110,
            0b00001110,
            0b00000100,
            0b00000100,
            0b00001010,
            0b00001010,
            0b00011111,
        };

        byte hourglass_1[8] = {
            0b00011111,
            0b00001010,
            0b00001110,
            0b00000100,
            0b00000100,
            0b00001010,
            0b00001010,
            0b00011111,
        };

        byte hourglass_2[8] = {
            0b00011111,
            0b00001010,
            0b00001110,
            0b00000100,
            0b00000100,
            0b00001010,
            0b00001110,
            0b00011111,
        };

        byte hourglass_3[8] = {
            0b00011111,
            0b00001010,
            0b00001010,
            0b00000100,
            0b00000100,
            0b00001010,
            0b00001110,
            0b00011111,
        };

        byte hourglass_4[8] = {
            0b00011111,
            0b00001010,
            0b00001010,
            0b00000100,
            0b00000100,
            0b00001110,
            0b00001110,
            0b00011111,
        };
        #endif
        #if defined(DISPLAY_TYPE_LCD_16X2)
        lcd = new LiquidCrystal(RS, ENABLE, D0, D1, D2, D3);
        #endif

        #if defined(DISPLAY_TYPE_LCD_16X2)
        lcd->begin(_width, _height);

        lcd->createChar(0, hourglass_0);
        lcd->createChar(1, hourglass_1);
        lcd->createChar(2, hourglass_2);
        lcd->createChar(3, hourglass_3);
        lcd->createChar(4, hourglass_4);
        lcd->createChar(5, alt);
        lcd->createChar(6, ant);
        lcd->createChar(7, sd);
        #endif
    }

    if (_screen == HX1230_96X68) {
        #if defined(DISPLAY_TYPE_HX1230_96X68)
        u8g2_HX1230 = new U8G2_HX1230_96X68_1_3W_SW_SPI(U8G2_R0, /* clock=*/ LCD_CLK, /* data=*/ LCD_DIN, /* cs=*/ LCD_CS, /* reset=*/ LCD_RST);
        #endif
    }

    if (_screen == SDD1306_128X64) {
        #if defined(DISPLAY_TYPE_SDD1306_128X64)
        u8g2_SSD1306 = new U8G2_SSD1306_128X64_NONAME_1_SW_I2C(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);
        u8g2_SSD1306->setFont(u8g2_font_helvR10_tf);
        u8g2_SSD1306->setFontRefHeightExtendedText();
        u8g2_SSD1306->setDrawColor(1);
        u8g2_SSD1306->setFontPosTop();
        #endif
    }
}

void Display::clr(){
    if (_screen == LCD_16X2 || _screen == LCD_16X2_I2C) {
        #if defined(DISPLAY_TYPE_LCD_16X2)||(DISPLAY_TYPE_LCD_16X2_I2C)
        lcd->clear();
        #endif
    }
}

void Display::print(int vertical, int horizontal, const char text[]){
    if (_screen == LCD_16X2 || _screen == LCD_16X2_I2C) {
        #if defined(DISPLAY_TYPE_LCD_16X2)||(DISPLAY_TYPE_LCD_16X2_I2C)
        lcd->setCursor(vertical, horizontal);
        lcd->print(text);
        #endif
    }
}

void Display::print(int line, const char text[]){
    if (_screen == LCD_16X2 || _screen == LCD_16X2_I2C) {
        byte pos = _width -(strlen(text));
        pos = (pos >> 1);
        this->print((int)pos, line, text);
    }
}

void Display::print(const char text[]){
    if (_screen == LCD_16X2 || _screen == LCD_16X2_I2C) {
    #if defined(DISPLAY_TYPE_LCD_16X2)||(DISPLAY_TYPE_LCD_16X2_I2C)
    lcd->print(text);
    #endif
    }
}

void Display::print(const char text1[], const char text2[]){
    if (_screen == LCD_16X2 || _screen == LCD_16X2_I2C) {
        this->print(0, text1);
        this->print(1, text2);
    }
    else if (_screen == SDD1306_128X64) {
         #if defined(DISPLAY_TYPE_SDD1306_128X64)
        u8g2_SSD1306->firstPage();  
        do { 
            u8g2_SSD1306->setCursor(20,0);
            u8g2_SSD1306->println(text1);
            u8g2_SSD1306->print(text2);
        } while( u8g2_SSD1306->nextPage() );
        #endif
    }
}

void Display::print(const char text1[], const char text2[], const char text3[]){

}

void Display::print(const char text1[], const char text2[], const char text3[], const char text4[]){

}

void Display::wait_anin(int t){
    if (_screen == LCD_16X2 || _screen == LCD_16X2_I2C) {
        #if defined(DISPLAY_TYPE_LCD_16X2)||(DISPLAY_TYPE_LCD_16X2_I2C)
        lcd->setCursor(15,1);
        lcd->write((byte)t%5);
        #endif
    }
    delay(500);
}

void Display::print_PChar(byte c) {
    if (_screen == LCD_16X2 || _screen == LCD_16X2_I2C) {
    #if defined(DISPLAY_TYPE_LCD_16X2)||(DISPLAY_TYPE_LCD_16X2_I2C)
    lcd->write(c);
    #endif
    }
}

void Display::print_utm(int zone, char band, long X, long Y,unsigned short sat ,int elevation,boolean SDReady){
    if (_screen == LCD_16X2 || _screen == LCD_16X2_I2C) {
        #if defined(DISPLAY_TYPE_LCD_16X2)||(DISPLAY_TYPE_LCD_16X2_I2C)
        char line[12];
        sprintf(line, "%02d%c %ld ", zone, band, X);
        this->print(0,0,line);
        this->print_PChar((byte)6);
        sprintf(line, "%02d ", sat);
        this->print(12,0,line);
        SDReady ? this->print_PChar((byte)7) : this->print("-");

        // New line
        sprintf(line, "%ld ", Y);
        this->print(1,1,line);
        this->print_PChar((byte)5);
        sprintf(line, "%dm", elevation);
        if (elevation < 10) this->print(14,1,line);
        else if (elevation < 100) this->print(13,1,line);
        else if (elevation < 1000) this->print(12,1,line);
        else this->print(11,1,line);
        #endif
    }
}

void Display::print_grades(float latitude, float longitude){
    if (_screen == LCD_16X2 || _screen == LCD_16X2_I2C) {
        #if defined(DISPLAY_TYPE_LCD_16X2)||(DISPLAY_TYPE_LCD_16X2_I2C)
        char line[14];
        strcpy(line, "LAT=");
        dtostrf(latitude, 2, 6, &line[strlen(line)]);
        this->print(0, line);
        strcpy(line, "LON=");
        dtostrf(longitude, 2, 6, &line[strlen(line)]);
        this->print(1, line);
        #endif
    }
}

void Display::splash(int time_delay){
    if (_screen == LCD_16X2 || _screen == LCD_16X2_I2C) this->print(NAME, VERSION);

    delay(time_delay);
}