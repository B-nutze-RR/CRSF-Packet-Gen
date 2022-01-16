# ESP32 CRSF Packet Gen
 Generate some test CRSF packets with esp3
 https://github.com/AlessandroAU/ESP32-CRSF-Packet-Gen



M5-Stick-C CRSF Remote Version

Modified for Flowshutter and Betaflight Blackbox logging purposes
to ARM an FC that just logs Gyro and Acc data for IMAGE stabilization in GYROflow.

    Betaflight AETR1234 16 Channel
    AUX 1  =   ARM HIGH
    Roll/Pitch/Yaw = MID
    Thrrottle      = LOW

  LED      =   pin10
  Tx       =   pin33  -> UART RX on FC set to CRSF
  Rx       =   pin32  -> Not connected/needed
  ButtonA  =   pin37

Arduino IDE + ESP32 
https://github.com/espressif/arduino-esp32
https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html ( stable works )

Thanks to https://github.com/AlessandroAU for all the nice CRSF code
