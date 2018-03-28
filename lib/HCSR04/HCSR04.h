#ifndef _HSCR04_H_
#define _HSCR04_H_

#include <Arduino.h>
#define SPEED_OF_SOUND 343


class HCSR04{
public:
  HCSR04(int trig, int echo, long maxPulseMicros);
  HCSR04(int trig, int echo);
  float getDistance();
private:
  long getTimeMicros();
  int _trig, _echo;
  long _maxPulseMicros = 10000;
};



#endif
