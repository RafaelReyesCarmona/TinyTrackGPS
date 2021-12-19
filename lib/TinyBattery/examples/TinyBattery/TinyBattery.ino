/*
TinyBattery.ino - Ligth Library for Arduino Environment to Battery management.
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
