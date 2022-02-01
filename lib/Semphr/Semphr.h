/*
Semphr.h - Simple implementation of a semaphore for TinyTrackGPS, a simple track GPS to SD card logger.
TinyTrackGPS v0.14

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

#ifndef Semphr_h
#define Semphr_h

#include "Arduino.h"

#if defined(__arm__) || defined(ESP8266) || defined(ESP32)
#include <functional>
using fptr = std::function<void()>;
#else
typedef void (*fptr)();
#endif

class Semphr {
    public:
        Semphr(bool init = false):_state(init){}
        void operator()(fptr func){
            if (_state) {
                func();
                _state = false;
            }
        }
        void set(){_state = true;}
        void reset(){_state = false;}
        bool status(){return _state;}

    private:
        bool _state;
};

#endif