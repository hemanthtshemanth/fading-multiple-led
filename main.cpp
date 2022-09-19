#include <Arduino.h>
#define red_led 4
#define green_led 2
#define blue_led 13
#define pwm_frequency 100
#define pwm_resolution 8
#define pwm_channel_1 0
#define pwm_channel_2 2
#define pwm_channel_3 4
uint8_t dutycycle,var;

void setup()
{
  ledcSetup(pwm_channel_1, pwm_frequency, pwm_resolution);
  ledcSetup(pwm_channel_2,pwm_frequency,pwm_resolution);
  ledcSetup(pwm_channel_3,pwm_frequency,pwm_resolution);
  ledcAttachPin(red_led,pwm_channel_1);
  ledcAttachPin(green_led,pwm_channel_2);
  ledcAttachPin(blue_led,pwm_channel_3);
}


void loop()
{

  // red led fading
  for (dutycycle = 0; dutycycle <= 100;   dutycycle += 25)
  {
    var=map(dutycycle,0,100,0,255);
    ledcWrite(pwm_channel_1, var);
    delay(1000);
    
  }
  for (dutycycle = 100; dutycycle >0; dutycycle -= 25)
  {
    var=map(dutycycle,0,100,0,255);
    ledcWrite(pwm_channel_1, var);
    delay(1000);
  }
  ledcWrite(pwm_channel_1, 0);
  // green led fading
  for (dutycycle = 0; dutycycle <= 100;dutycycle += 25)
  {
    var=map(dutycycle,0,100,0,255);
    ledcWrite(pwm_channel_2, var);
    delay(1000);
    
  }
  for (dutycycle = 100; dutycycle > 0; dutycycle -= 25)
  {
    var=map(dutycycle,0,100,0,255);
    ledcWrite(pwm_channel_2, var);
    delay(1000);
  }
   ledcWrite(pwm_channel_2, 0);
  // blue led fading
  for (dutycycle = 0; dutycycle <= 100; dutycycle += 25)
  {
    var=map(dutycycle,0,100,0,255);
    ledcWrite(pwm_channel_3, var);
    delay(1000);
    
  }
  for (dutycycle = 100; dutycycle > 0; dutycycle -= 25)
  {
    var=map(dutycycle,0,100,0,255);
    ledcWrite(pwm_channel_3, var);
    delay(1000);
  }
  ledcWrite(pwm_channel_3, 0);
}