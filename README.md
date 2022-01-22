# Based on ESP32 CRSF Packet Gen
    - Generate some test CRSF packets with esp32
    - https://github.com/AlessandroAU/ESP32-CRSF-Packet-Gen
 

______________________________
M5-Stick-C / M5-Stamp-C3 ( ESP32 pico/C3 ) CRSF Remote Version
______________________________

Modified for Flowshutter and Betaflight-Blackbox logging purposes
to ARM an FC that logs Gyro and Acc data for gyroflow.xyz 

    Betaflight AETR1234 16 Channel
    AUX 1  =   ARM HIGH
    Roll/Pitch/Yaw = MID
    Thrrottle      = LOW


   M5-stick-C:

        -  LED      =   pin10
        -  Tx       =   pin33  -> UART RX on FC set to CRSF
        -  Rx       =   pin32  -> Not connected/used right now
        -  ButtonA  =   pin37
  
  M5-stamp-C3:

        -  LED      =   pin2
        -  Tx       =   pin21  -> UART RX on FC set to CRSF
        -  Rx       =   pin20  -> Not connected/used right now
        -  ButtonA  =   pin3
  

Arduino IDE + ESP32 core

  +  Neopixel
  +  Ezbutton

- https://www.arduino.cc/en/software ( 1.8.19 tested )
- https://github.com/espressif/arduino-esp32
- https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html
- https://github.com/feilipu/Arduino_FreeRTOS_Library
- https://arduinogetstarted.com/tutorials/arduino-button-library
- https://github.com/adafruit/Adafruit_NeoPixel


______________________________

Thanks to https://github.com/AlessandroAU for all the nice CRSF code
