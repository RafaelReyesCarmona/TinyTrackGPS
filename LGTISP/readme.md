# LGTISP
LGT8Fx8P ISP download protocol implementation

## introduction
This is an implementation of LGT8Fx8P ISP download protocol. You can make arduino board as ISP for programing LGT8Fx8P.

## usage
1. Make a LGTISP:
   1. Burn LGTISP into arduino board.
   2. Short `RESET` pin and `VCC` pin of arduino board to avoid bootloader executing.
   3. The arduino board becomes a LGTISP now! Connect `SWD` and `SWC`. `RST` can be either connect or not.
      | Arduino Nano || LGT |
      |:-:|:-:|:-:|
      | D13 | -> | SWC |
      | D12 | -> | SWD |
      | D10 | -> | RST |
2. Burn bootloader into LGT8Fx8P:
   1. install Larduino.
   2. change **Board** to LGT8Fx8P.
   3. change **Programmer** to **AVR ISP**.
   4. click **Burn Bootloader**!

## advanced usage
- You can read GUID!
- You can read almost all flash after power-down! I crack it, haha
- more details : [LGTISP programmer](https://oshwhub.com/brother_yan/LGTISP)
- Explore yourself!

## author
brother_yan

## reference
[LarduinoISP](https://github.com/LGTMCU/LarduinoISP)  
[ISP4LGT8F328P](https://github.com/nicechao/ISP4LGT8F328P)

