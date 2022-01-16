# Based on ESP32 CRSF Packet Gen
  -Generate some test CRSF packets with esp3
  -https://github.com/AlessandroAU/ESP32-CRSF-Packet-Gen
 
Thanks to https://github.com/AlessandroAU for all the nice CRSF code


______________________________
M5-Stick-C ( ESP32) CRSF Remote Version
______________________________
Modified for Flowshutter and Betaflight Blackbox logging purposes
to ARM an FC that just logs Gyro and Acc data for IMAGE stabilization in GYROflow.

    Betaflight AETR1234 16 Channel
    AUX 1  =   ARM HIGH
    Roll/Pitch/Yaw = MID
    Thrrottle      = LOW

   -LED      =   pin10
   -Tx       =   pin33  -> UART RX on FC set to CRSF
   -Rx       =   pin32  -> Not connected/needed
   -ButtonA  =   pin37
  
  
Arduino IDE + ESP32 core

- https://www.arduino.cc/en/software ( 1.8.19 tested )
- https://github.com/espressif/arduino-esp32
- https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html 


______________________________

RP2040 CRSF Remote Version ( WIP )
______________________________

   -LED      =   pin_
   -Tx       =   pin_  -> UART RX on FC set to CRSF
   -Rx       =   pin_  -> Not connected/needed
   -ButtonA  =   pin_
  
  
  Arduino IDE + RP2040 core
  - https://www.arduino.cc/en/software ( 1.8.19 tested )
  - https://github.com/earlephilhower/arduino-pico
  - https://arduino-pico.readthedocs.io/en/latest/


( work in progress )
