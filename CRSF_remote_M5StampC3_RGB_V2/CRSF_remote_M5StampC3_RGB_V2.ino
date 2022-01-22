// M5-Stamp-C3
// Original ESP32 CRSF Packet Gen Code by :
//
//    https://github.com/AlessandroAU/ESP32-CRSF-Packet-Gen
//
//  Modified by Nicecrash for Flowshutter and betaflight Blackbox logging purposes, GYROflow/FLOWshutter
//
//    Betaflight AETR1234 16 Channel
//    AUX 1  =   ARM HIGH
//    Roll/Pitch/Yaw = MID
//    Thrrottle      = LOW
//
//  LED      =   pin2
//  Tx       =   pin21
//  Rx       =   pin20  -  not needed for simple CRSF arm/disarm
//  ButtonA  =   pin3
//



//external libs to import in Arduino IDE :
#include "Adafruit_NeoPixel.h"            
#include "ezButton.h"   // Debounze and Button state


#include "CRSF.h"

#define PIN        2 
#define NUMPIXELS  1 

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define LOOP_STATE_STOPPED 0  //  CRSF DISARMED
#define LOOP_STATE_STARTED 1  //  CRSF ARMED

ezButton button(3);  // create ezButton object pin 3 / Button A M5-Stamp-C3
int loopState = LOOP_STATE_STOPPED; // start CRSFDisarmed

#define CRSFinterval 5000 //in ms
#define uartCRSFinverted false

CRSF crsf;

#define CRSF_CHANNEL_VALUE_MIN 172
#define CRSF_CHANNEL_VALUE_MID 992
#define CRSF_CHANNEL_VALUE_MAX 1811

hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;


void IRAM_ATTR onTimer() {
  portENTER_CRITICAL_ISR(&timerMux);
  crsf.sendRCFrameToFC();
  portEXIT_CRITICAL_ISR(&timerMux);

}

void StartTimer() {
  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, CRSFinterval, true);
  timerAlarmEnable(timer);
}

void setup() {
    crsf.Begin();
    pixels.begin(); // INITIALIZE NeoPixel
    pixels.clear(); // Set all pixels off 
    button.setDebounceTime(69);
    delay(1);

  crsf.PackedRCdataOut.ch0 = CRSF_CHANNEL_VALUE_MIN;
  crsf.PackedRCdataOut.ch1 = CRSF_CHANNEL_VALUE_MIN;
  crsf.PackedRCdataOut.ch2 = CRSF_CHANNEL_VALUE_MIN;
  crsf.PackedRCdataOut.ch3 = CRSF_CHANNEL_VALUE_MIN;
  crsf.PackedRCdataOut.ch4 = CRSF_CHANNEL_VALUE_MIN;
  crsf.sendRCFrameToFC();

  StartTimer();
}

void loop() {
  button.loop();
  if (button.isPressed()) {
    if (loopState == LOOP_STATE_STOPPED)
      loopState = LOOP_STATE_STARTED;
    else // if(loopState == LOOP_STATE_STARTED)
      loopState = LOOP_STATE_STOPPED;
  }

  if (loopState == LOOP_STATE_STARTED) {
       crsf.PackedRCdataOut.ch4 = CRSF_CHANNEL_VALUE_MAX; //  Channel 4 sending AUX 1 HIGH signal
           pixels.setPixelColor(0, pixels.Color(255, 0, 0));
           pixels.setBrightness(60); 
           pixels.show();            
     } else {
      
        crsf.PackedRCdataOut.ch4 = CRSF_CHANNEL_VALUE_MIN;//  Channel 4 sending AUX 1 LOW signal
           pixels.setPixelColor(0, pixels.Color(0, 255, 0));
           pixels.setBrightness(5); 
//           delay();
           pixels.show(); 
          }

//  Betaflight AETR1234 
//  CRSF_CHANNEL_VALUE_MIN
//  CRSF_CHANNEL_VALUE_MID
//  CRSF_CHANNEL_VALUE_MAX

  crsf.PackedRCdataOut.ch0 = CRSF_CHANNEL_VALUE_MID;      //  CH 0 ROLL
  crsf.PackedRCdataOut.ch1 = CRSF_CHANNEL_VALUE_MID;      //  CH 1 PITCH
  crsf.PackedRCdataOut.ch2 = CRSF_CHANNEL_VALUE_MIN;      //  CH 2 THROTTLE
  crsf.PackedRCdataOut.ch3 = CRSF_CHANNEL_VALUE_MID;      //  CH 3 YAW
  crsf.PackedRCdataOut.ch5 = CRSF_CHANNEL_VALUE_MIN;      //  CH 5 AUX 2
  crsf.PackedRCdataOut.ch6 = CRSF_CHANNEL_VALUE_MAX;      //  CH 6 AUX 3
  crsf.PackedRCdataOut.ch7 = CRSF_CHANNEL_VALUE_MIN;      //  CH 7 AUX 4
  crsf.PackedRCdataOut.ch8 = CRSF_CHANNEL_VALUE_MAX;      //  CH 8 AUX 5

}
