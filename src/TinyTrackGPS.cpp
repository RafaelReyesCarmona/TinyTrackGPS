/*
TinyTrackGPS.cpp - A simple track GPS to SD card logger.
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

/*
     Programa de localizacion por gps que graba las posiciones en
     un fichero de texto cada segundo, de forma diaria.

     Conectar módulo SD con pin CS (naranja) en pin 10 arduino.

     Conectar módulo NMEA-6M (gps) pines 8,9 (9 - pin rx negro)

     Conectar LCD 16x2 pines 2,3,4,5,6,7 (2-amarillo , 3-azul,
     4-rojo, 5-azul oscuro, 6-verde, 7-blanco)
*/

// Include libraries.
#include <Arduino.h>
#include "config.h"
#include "Display.h"
#include <Ticker.h>
#include <SoftwareSerial.h>
#include <TinyGPS.h>
#include <Fat16.h>
#include <Fat16util.h> // use functions to print strings from flash memory
//#include <SD.h>
#include <LowPower.h>
#include "UTMconversion.h"

//File GPSFile;
char GPSLogFile[] = "YYYYMMDD.csv"; // Formato de nombre de fichero. YYYY-Año, MM-Mes, DD-Día.
const uint8_t CHIP_SELECT = SS;  // SD card chip select pin. (10)
SdCard card;
Fat16 file;

boolean SDReady;
float flat, flon;
unsigned long age;

/* Código de demostración uso de librería TinyGPS.
   Requiere uso de librería SoftwareSerial, se presupone que disponemos
   de un dispositivo GPS serie de 9600-bauds conectado en pines 9(rx) y 8(tx).
*/
TinyGPS gps;
GPS_UTM utm;
#define PIN_SELECT 8
boolean pin = LOW;
SoftwareSerial gps_serial(9, 8);
int year_actual;
byte month_actual, day_actual;
byte hour_prev, minute_prev, second_prev;

Display LCD(LCD_16X2);
void GPSData();
Ticker GPSRefresh(GPSData, 1000);


void setup(void) {
  boolean config = 0;
  Serial.begin(9600);
  gps_serial.begin(9600);

  pinMode(10, OUTPUT);

  //Serial.print(F("Initializing SD card..."));

//  SDReady = SD.begin(10);
  SDReady = card.begin(CHIP_SELECT) & Fat16::init(&card);
  file.writeError = false;

  //(SDReady) ? Serial.println(F("Done.")) : Serial.println(F("FAILED!"));

  /* Declaramos pin para selector visor coordenadas */
  pinMode(PIN_SELECT,INPUT_PULLUP);

  /* Iniciaización del display LCD u OLED */
  LCD.start();
  LCD.clr();
  LCD.splash();
  
  //Serial.print(F("Waiting for GPS signal..."));
  LCD.clr();
  LCD.print("Waiting for","GPS signal...");

unsigned int time = 0;

  do {
    LCD.wait_anin(time++);

    while (gps_serial.available())
    {
      if (gps.encode(gps_serial.read())) // Comprueba que ha recibido una sentencia del GPS.
        {
          int year;
          byte month, day, hour, minute, second, hundredths;
          unsigned long age;

          gps.crack_datetime(&year, &month, &day, &hour, &minute, &second, &hundredths, &age);
          if (sprintf(GPSLogFile, "%04d%02d%02d.csv", year, month, day) > 0) {
            config = true;
            //Serial.println(F("Done."));
            }
          year_actual = year;
          month_actual = month;
          day_actual = day;
          hour_prev = hour;
          minute_prev = minute;
          second_prev = second;

          // Si no existe el fichero lo crea y añade las cabeceras.
          if (SDReady && !file.open(GPSLogFile,O_READ)) {
//            if (GPSFile = SD.open(GPSLogFile, FILE_WRITE)) {
            if (file.open(GPSLogFile, O_CREAT | O_APPEND | O_WRITE)) {
              //Serial.print(F("New GPSLogFile, adding heads..."));
              file.println("Time,latitude,longitude,alt,utm");
              //Serial.println(F("Done."));
              file.close();
            } else { 
               //Serial.println(F("** Error creating GPSLogFile. **"));
            }
          }
        }
    }
  }while(!config);

//  if (SDReady) {
//    Serial.print(F("Filename: "));
//    Serial.println(GPSLogFile);
//  }
//  Serial.println(F("Configuration ended."));
  LCD.clr();
  //lcd.clear();
  GPSRefresh.start();
}

void loop(void) {
//  boolean gps_ok = false;

//  do {
  while (gps_serial.available())
    gps.encode(gps_serial.read()); //{
//        gps_ok = true;
//    }
//  }while(!gps_ok);

  GPSRefresh.update();
}

void GPSData() {
  int year;
  byte month, day, hour, minute, second, hundredths;
  unsigned long age;
  int elevation;
  float f_elevation;
  char timestr[]= "00:00:00";
  char utmstr[] = "30S 123456 1234567";
  long timeidle = millis();

  gps.f_get_position(&flat, &flon, &age);
  f_elevation = gps.f_altitude();
  elevation = abs((int)f_elevation);
  utm.UTM(flat, flon);
  sprintf(utmstr, "%02d%c %ld %ld", utm.zone(), utm.band(), utm.X(), utm.Y());
  if (pin != digitalRead(PIN_SELECT)) {
    LCD.clr();
    pin = digitalRead(PIN_SELECT);
    }

  if (pin == LOW) {
    LCD.print_utm(utm.zone(),utm.band(),utm.X(),utm.Y(),gps.satellites(),elevation,SDReady);
    }
  else {
    LCD.print_grades(flat, flon);
    };

  gps.crack_datetime(&year, &month, &day, &hour, &minute, &second, &hundredths, &age);
  if (age != TinyGPS::GPS_INVALID_AGE){
    sprintf(timestr, "%02d:%02d:%02d,", hour, minute, second);
    //Serial.print(timestr);
  }

  if (year != year_actual || month != month_actual || day != day_actual) {
    sprintf(GPSLogFile, "%04d%02d%02d.csv", year, month, day);
    year_actual = year;
    month_actual = month;
    day_actual = day;

    // Si no existe el fichero lo crea y añade las cabeceras.
    if (SDReady && !file.open(GPSLogFile,O_READ)) {
//    if (SDReady && !SD.exists(GPSLogFile)) {
      if (file.open(GPSLogFile, O_CREAT | O_APPEND | O_WRITE)) {
        //Serial.print(F("New GPSLogFile, adding heads..."));
        file.println("Time,latitude,longitude,alt,utm");
        //Serial.println(F("Done."));
        file.close();
        }
        else {
        //Serial.println(F("** Error creating GPSLogFile. **"));
        }
    }
  }
  if (!((hour_prev == hour) && (minute_prev == minute) && (second_prev == second))) {
  if (SDReady && file.open(GPSLogFile, O_CREAT | O_APPEND | O_WRITE)) {
    //Serial.print(F("Open GPSLogFile to write..."));
    file.print(timestr);
    file.print(flat,6);
    file.print(",");
    file.print(flon,6);
    file.print(",");
    file.print(elevation);
    file.print(",");
    file.println(utmstr);
    file.close();
    //Serial.println(F("Done."));
    hour_prev = hour;
    minute_prev = minute;
    second_prev = second;
//  } else if (!GPSFile){
    //Serial.println(F("** Error opening GPSLogFile. **"));
  }
} //else Serial.println(F("** GPS signal lost. **"));
timeidle -= millis();
timeidle += 1000L;
//Serial.println(timeidle);
if (timeidle > 500L)
  LowPower.idle(SLEEP_500MS, ADC_OFF, TIMER2_ON, TIMER1_ON, TIMER0_ON, SPI_ON, USART0_ON, TWI_OFF);
else if(timeidle > 250L)
  LowPower.idle(SLEEP_250MS, ADC_OFF, TIMER2_ON, TIMER1_ON, TIMER0_ON, SPI_ON, USART0_ON, TWI_OFF);
else if(timeidle > 120L)
  LowPower.idle(SLEEP_120MS, ADC_OFF, TIMER2_ON, TIMER1_ON, TIMER0_ON, SPI_ON, USART0_ON, TWI_OFF);
else if(timeidle > 60L)
  LowPower.idle(SLEEP_60MS, ADC_OFF, TIMER2_ON, TIMER1_ON, TIMER0_ON, SPI_ON, USART0_ON, TWI_OFF);
}
