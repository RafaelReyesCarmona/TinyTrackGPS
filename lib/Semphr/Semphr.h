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

    private:
        bool _state;
};

#endif