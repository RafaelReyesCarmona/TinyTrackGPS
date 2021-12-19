/*
TinyBattery.cpp - Ligth Library for Arduino Environment to Battery management.
v0.1

Copyright © 2021 Francisco Rafael Reyes Carmona.
All rights reserved.

rafael.reyes.carmona@gmail.com


  This file is part of TinyBattery Library.

  TinyBattery Library is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  TinyBattery Library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with TinyBattery Library.  If not, see <https://www.gnu.org/licenses/>.

*/

/**
 * Ligth Library for Arduino Enveroment to Battery management.
 */

#include "TinyBattery.h"

TinyBattery::TinyBattery(){
  _PIN = VCC;
  _MIN_V = BAT_MIN;
  _MAX_V = BAT_MAX;
}

TinyBattery::TinyBattery(PinType PIN,
                         float VREF,
                         long RESISTOR_VDD,
                         long RESISTOR_GND,
                         float MIN_VOLT,
                         float MAX_VOLT) {
  _PIN = PIN;
  _VREF = VREF;
  _MIN_V = MIN_VOLT;
  _MAX_V = MAX_VOLT;

  // Calculate conversion factor (maximum output voltage of the voltage divider)
  _FACTOR = RESISTOR_VDD + RESISTOR_GND;
  _FACTOR /= RESISTOR_GND;

  pinMode(_PIN, INPUT);
}


TinyBattery::TinyBattery(PinType PIN,
                         float VREF,
                         float MIN_VOLT,
                         float MAX_VOLT,
                         float FACTOR) {
  _PIN = PIN;
  _VREF = VREF;
  _MIN_V = MIN_VOLT;
  _MAX_V = MAX_VOLT;
  _FACTOR = FACTOR;

  pinMode(_PIN, INPUT);
}

float TinyBattery::GetVoltage() {
  if(_PIN == 0xff)
    return ((float)readVcc() / 1000.0);
  else
    return ((((float)analogRead(_PIN) * _VREF) / _ADC_MAX) * _FACTOR);
}

byte TinyBattery::GetChargeLevel(byte numsamples)
{
    if (_MAX_V - _MIN_V == 0.0) {
      return 0;
    }

    float Current_Level = GetVoltage();

    for (byte i = numsamples; i--; ) {
      Current_Level = (_alphaEMA_LOW * GetVoltage()) + ((1.0 - _alphaEMA_LOW) * Current_Level);
    }

    Current_Level -= _MIN_V;
    Current_Level *= 100;
    Current_Level /= (_MAX_V - _MIN_V);
    if (Current_Level > 100.0){
      Current_Level = 100;
    }
    return (byte)Current_Level;
    //percent = map(constrain(v,BAT_MIN,BAT_MAX),BAT_MIN,BAT_MAX,0,100);
}


void TinyBattery::setEMA(float EMA){
  _alphaEMA_LOW = EMA;
}


void TinyBattery::setADC(int ADC_MAX){
  _ADC_MAX = ADC_MAX;
}

void TinyBattery::analogRef(uint8_t mode){
analogReference(mode);
switch (mode) {
  #if defined(__LGT8F__)
  case INTERNAL1V024:
    _VREF = 1.024;
    break;
  case INTERNAL2V048:
    _VREF = 2.048;
    break;
  case INTERNAL4V096:
    _VREF = 4.096;
    break;
  #endif
  case DEFAULT:
    break;
  }
}

long TinyBattery::readVcc() 
{
  long result;
  // Read 1.1V reference against AVcc
  ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  delay(2); // Wait for Vref to settle
  ADCSRA |= _BV(ADSC); // Convert
  while (bit_is_set(ADCSRA,ADSC));
  result = ADCL;
  result |= ADCH<<8;
  result = 1125300L / result; // Back-calculate AVcc in mV
  return result;
}